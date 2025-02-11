/***************************************************************************
***
***     Copyright (C) 2022-2023 IntelliCAD Technology Consortium. All Rights Reserved.
***
***     Use of the information contained herein, in part or in whole,
***     in/as source code and/or in/as object code, in any way by anyone
***     other than authorized employees of The IntelliCAD Technology Consortium,
***     or by anyone to whom The IntelliCAD Technology Consortium  has not
***     granted use is illegal.
***
***     Description: AcArray template class declaration
***
*****************************************************************************/

// Other headers depend on this macro
#ifndef AC_ACARRAY_H
#define AC_ACARRAY_H
#pragma once

#include "PAL/api/c11_Annex_K.h"
#include "adesk.h"
#include <memory>
#include <cstdlib>
#include <algorithm>
#include <type_traits>

#include "icarx/IcArxAssert.h"
#define AC_ARRAY_ASSERT ICARX_ASSERT

#define ACARRAY_GROWTH_THRESHOLD 0x10000

template<class T>
void AcArrayValidateParams(bool bSameBuffer, T* pDest, size_t nBufLen, const T* pSource,
						   size_t nCount);

#include "icarx/IcArxPackPush.h"
#pragma push_macro("new")
#pragma push_macro("delete")
#undef new
#undef delete

template<class T>
class AcArrayMemCopyReallocator
{
public:
	static void copyItems(T* pDest, size_t nBufLen, const T* pSource, size_t nCount)
	{
		AcArrayValidateParams<T>(false, pDest, nBufLen, pSource, nCount);
		if (nCount > 0)
			memcpy_s(pDest, nBufLen * sizeof(T), pSource, nCount * sizeof(T));
	}
	static void moveItems(T* pDest, size_t nBufLen, T* pSource, size_t nCount, bool bSameBuffer)
	{
		AcArrayValidateParams<T>(bSameBuffer, pDest, nBufLen, pSource, nCount);
		if (nCount > 0)
		{
			if (bSameBuffer)
				memmove_s(pDest, nBufLen * sizeof(T), pSource, nCount * sizeof(T));
			else
				memcpy_s(pDest, nBufLen * sizeof(T), pSource, nCount * sizeof(T));
		}
	}
};

template<class T>
class AcArrayObjectCopyReallocator
{
public:
	static void copyItems(T* pDest, size_t nBufLen, const T* pSource, size_t nCount)
	{
		AcArrayValidateParams<T>(false, pDest, nBufLen, pSource, nCount);
		while (nCount--)
		{
			*pDest = *pSource;
			pDest++;
			pSource++;
		}
	}
	static void moveItems(T* pDest, size_t nBufLen, T* pSource, size_t nCount, bool bSameBuffer)
	{
		AcArrayValidateParams<T>(bSameBuffer, pDest, nBufLen, pSource, nCount);
		while (nCount--)
		{
			*pDest = std::move(*pSource);
			pDest++;
			pSource++;
		}
	}
};

template<typename T, bool>
struct AcArrayItemCopierSelector;

template<typename T>
struct AcArrayItemCopierSelector<T, false>
{
	typedef AcArrayObjectCopyReallocator<T> allocator;
};

template<typename T>
struct AcArrayItemCopierSelector<T, true>
{
	typedef AcArrayMemCopyReallocator<T> allocator;
};

template<typename T,
		 typename R = typename AcArrayItemCopierSelector<T, std::is_trivial<T>::value>::allocator>
class AcArray
{
public:
	typedef T Type;
	typedef R Allocator;

	enum
	{
		eUsesMemCopy = std::is_same<R, AcArrayMemCopyReallocator<T>>::value
	};

protected:
	T* mpArray{nullptr};
	int mPhysicalLen{0};
	int mLogicalLen{0};
	int mGrowLen{0};

protected:
	void copyOtherIntoThis(const AcArray<T, R>& otherArray);
	void insertSpace(int nIndex);
	bool isValid(int i) const { return 0 <= i && i < mLogicalLen; }
	void moveOtherIntoThis(AcArray<T, R>& otherArray);

public:
	AcArray(int initPhysicalLength = 0, int initGrowLength = 8);
	AcArray(AcArray<T, R>&& src) noexcept : mGrowLen(src.mGrowLen) { this->moveOtherIntoThis(src); }
	AcArray(const AcArray<T, R>& src) : mGrowLen(src.mGrowLen) { this->copyOtherIntoThis(src); }
	~AcArray()
	{
		if (mPhysicalLen > 0)
			this->setPhysicalLength(0);
	}
	AcArray<T, R>& operator=(AcArray<T, R>&& src) noexcept
	{
		if (this != &src)
		{
			this->setPhysicalLength(0);
			this->moveOtherIntoThis(src);
		}
		return *this;
	}
	AcArray<T, R>& operator=(const AcArray<T, R>& src)
	{
		if (this != &src)
			this->copyOtherIntoThis(src);
		return *this;
	}
	bool operator==(const AcArray<T, R>&) const;
	bool operator!=(const AcArray<T, R>& cpr) const { return !operator==(cpr); }
	const T& operator[](int i) const { return at(i); }
	T& operator[](int i) { return at(i); }

	int append(T&& value) { return this->appendMove(value); }
	int append(const T& value)
	{
		insertAt(mLogicalLen, value);
		return mLogicalLen - 1;
	}
	AcArray<T, R>& append(const AcArray<T, R>& array);
	int appendMove(T& value)
	{
		this->insertAtMove(mLogicalLen, value);
		return this->mLogicalLen - 1;
	}
	AcArray<T, R>& appendMove(AcArray<T, R>& array);
	const T* asArrayPtr() const { return mpArray; }
	T* asArrayPtr() { return mpArray; }
	const T& at(int i) const
	{
		ICARX_ASSERT(this->isValid(i));
		return mpArray[i];
	}
	T& at(int i)
	{
		ICARX_ASSERT(this->isValid(i));
		return mpArray[i];
	}
	const T* begin() const { return mpArray; }
	T* begin() { return mpArray; }
	bool contains(const T& value, int start = 0) const
	{
		return this->findFrom(value, start) != -1;
	}
	const T* end() const { return mpArray + mLogicalLen; }
	T* end() { return mpArray + mLogicalLen; }
	int find(const T& value) const { return this->findFrom(value, 0); }
	bool find(const T& value, int& foundAt, int start = 0) const;
	int findFrom(const T& value, int start) const;
	const T& first() const { return at(0); }
	T& first() { return at(0); }
	int growLength() const { return mGrowLen; }
	AcArray<T, R>& insertAt(int index, T&& value) { return this->insertAtMove(index, value); }
	AcArray<T, R>& insertAt(int index, const T& value);
	AcArray<T, R>& insertAtMove(int index, T& value);
	bool isEmpty() const { return mLogicalLen == 0; }
	const T& last() const { return at(mLogicalLen - 1); }
	T& last() { return at(mLogicalLen - 1); }
	int length() const { return mLogicalLen; }
	int logicalLength() const { return mLogicalLen; }
	constexpr static int maxLength() { return 0x7fffffff / sizeof(T); }
	int physicalLength() const { return mPhysicalLen; }
	bool remove(const T& value, int start = 0);
	AcArray<T, R>& removeAll()
	{
		this->setLogicalLength(0);
		return *this;
	}
	AcArray<T, R>& removeAt(int index);
	AcArray<T, R>& removeFirst() { return removeAt(0); }
	AcArray<T, R>& removeLast();
	AcArray<T, R>& removeSubArray(int startIndex, int endIndex);
	AcArray<T, R>& reverse();
	AcArray<T, R>& setAll(const T& value)
	{
		for (int i = 0; i < mLogicalLen; i++)
			mpArray[i] = value;
		return *this;
	}
	AcArray<T, R>& setAt(int i, const T& value)
	{
		ICARX_ASSERT(this->isValid(i));
		mpArray[i] = value;
		return *this;
	}
	AcArray<T, R>& setGrowLength(int glen)
	{
		ICARX_ASSERT(glen > 0);
		mGrowLen = glen;
		return *this;
	}
	AcArray<T, R>& setLogicalLength(int);
	AcArray<T, R>& setPhysicalLength(int);
	AcArray<T, R>& swap(int i1, int i2);
};

template<class T, class R>
inline AcArray<T, R>::AcArray(int physicalLength, int growLength) : mGrowLen(growLength)
{
	static_assert(std::is_trivial<T>::value || !std::is_pod<T>::value,
				  "is_pod but not is_trivial?");
	ICARX_ASSERT(mGrowLen > 0);
	ICARX_ASSERT(physicalLength >= 0);
	ICARX_ASSERT(physicalLength <= maxLength());
	if (physicalLength > 0)
		this->setPhysicalLength(physicalLength);
}

template<class T, class R>
bool AcArray<T, R>::operator==(const AcArray<T, R>& cpr) const
{
	if (mLogicalLen == cpr.mLogicalLen)
	{
		for (int i = 0; i < mLogicalLen; i++)
			if (mpArray[i] != cpr.mpArray[i])
				return false;
		return true;
	}
	return false;
}

template<class T, class R>
AcArray<T, R>& AcArray<T, R>::append(const AcArray<T, R>& otherArray)
{
	const int nOrigLogLen = this->mLogicalLen;
	const int nOrigOtherLogLen = otherArray.mLogicalLen;
	this->setLogicalLength(nOrigLogLen + nOrigOtherLogLen);

	R::copyItems(mpArray + nOrigLogLen, mLogicalLen - nOrigLogLen, otherArray.mpArray,
				 nOrigOtherLogLen);

	return *this;
}

template<class T, class R>
AcArray<T, R>& AcArray<T, R>::appendMove(AcArray<T, R>& otherArray)
{
	ICARX_ASSERT(this != &otherArray);
	if (this != &otherArray)
	{
		if (this->mLogicalLen == 0)
		{
			this->setPhysicalLength(0);
			this->moveOtherIntoThis(otherArray);
		}
		else
		{
			const int nOrigLogLen = this->mLogicalLen;
			this->setLogicalLength(nOrigLogLen + otherArray.mLogicalLen);

			R::moveItems(mpArray + nOrigLogLen, mLogicalLen - nOrigLogLen, otherArray.mpArray,
						 otherArray.mLogicalLen, false);
		}
	}
	return *this;
}

template<class T, class R>
inline void AcArray<T, R>::copyOtherIntoThis(const AcArray<T, R>& otherArray)
{
	ICARX_ASSERT(this != &otherArray);
	this->setLogicalLength(otherArray.mLogicalLen);
	R::copyItems(mpArray, mPhysicalLen, otherArray.mpArray, mLogicalLen);
}

template<class T, class R>
bool AcArray<T, R>::find(const T& value, int& index, int start) const
{
	const int nFoundAt = this->findFrom(value, start);
	if (nFoundAt == -1)
		return false;
	index = nFoundAt;
	return true;
}

template<class T, class R>
int AcArray<T, R>::findFrom(const T& value, int start) const
{
	ICARX_ASSERT(start >= 0);
	if (start < 0)
		return -1;
	for (int i = start; i < this->mLogicalLen; i++)
	{
		if (mpArray[i] == value)
			return i;
	}
	return -1;
}

template<class T, class R>
AcArray<T, R>& AcArray<T, R>::insertAt(int index, const T& value)
{
	ICARX_ASSERT(index >= 0);
	ICARX_ASSERT(index <= mLogicalLen);
	ICARX_ASSERT(mLogicalLen <= mPhysicalLen);
	if (index < 0 || index > mLogicalLen)
		return *this;
	if (index == mLogicalLen && mLogicalLen < mPhysicalLen)
	{
		mpArray[index] = value;
		mLogicalLen++;
	}
	else
	{
		T tmp(value);
		this->insertSpace(index);
		mpArray[index] = std::move(tmp);
	}
	return *this;
}

template<class T, class R>
AcArray<T, R>& AcArray<T, R>::insertAtMove(int index, T& value)
{
	ICARX_ASSERT(index >= 0);
	ICARX_ASSERT(index <= mLogicalLen);
	ICARX_ASSERT(mLogicalLen <= mPhysicalLen);
	if (index < 0 || index > mLogicalLen)
		return *this;
	if (index == mLogicalLen && mLogicalLen < mPhysicalLen)
	{
		mpArray[index] = std::move(value);
		mLogicalLen++;
	}
	else
	{
		T tmp(std::move(value));
		this->insertSpace(index);
		mpArray[index] = std::move(tmp);
	}
	return *this;
}

template<class T, class R>
void AcArray<T, R>::insertSpace(int nIndex)
{
	this->setLogicalLength(mLogicalLen + 1);

	if (nIndex < mLogicalLen - 1)
	{
		ICARX_ASSERT(mLogicalLen >= 0);
		T* p = mpArray + mLogicalLen - 1;
		T* const pSpace = mpArray + nIndex;
		ICARX_ASSERT(p >= pSpace);
		do {
			*p = std::move(*(p - 1));
		} while (--p != pSpace);
	}
}

template<class T, class R>
inline void AcArray<T, R>::moveOtherIntoThis(AcArray<T, R>& otherArray)
{
	ICARX_ASSERT(this != &otherArray);
	ICARX_ASSERT(this->mpArray == nullptr);
	this->mpArray = otherArray.mpArray;
	this->mLogicalLen = otherArray.mLogicalLen;
	this->mPhysicalLen = otherArray.mPhysicalLen;
	otherArray.mpArray = nullptr;
	otherArray.mLogicalLen = 0;
	otherArray.mPhysicalLen = 0;
	otherArray.mGrowLen = 8;
}

template<class T, class R>
bool AcArray<T, R>::remove(const T& value, int start)
{
	const int i = this->findFrom(value, start);
	if (i == -1)
		return false;
	this->removeAt(i);
	return true;
}

template<class T, class R>
AcArray<T, R>& AcArray<T, R>::removeAt(int index)
{
	ICARX_ASSERT(isValid(index));
	ICARX_ASSERT(mLogicalLen <= mPhysicalLen);
	ICARX_ASSERT(!isEmpty());
	if (isEmpty() || !isValid(index))
		return *this;

	if (index < mLogicalLen - 1)
	{
		R::moveItems(mpArray + index, mPhysicalLen - index, mpArray + index + 1,
					 mLogicalLen - 1 - index, true);
	}
	mLogicalLen--;
	return *this;
}

template<class T, class R>
inline AcArray<T, R>& AcArray<T, R>::removeLast()
{
	ICARX_ASSERT(!isEmpty());
	if (!isEmpty())
		mLogicalLen--;
	return *this;
}

template<class T, class R>
AcArray<T, R>& AcArray<T, R>::removeSubArray(int startIndex, int endIndex)
{
	ICARX_ASSERT(isValid(startIndex));
	ICARX_ASSERT(startIndex <= endIndex);

	if (endIndex >= mLogicalLen - 1)
	{
		mLogicalLen = startIndex;
		return *this;
	}

	const int kNumToRemove = endIndex + 1 - startIndex;
	const int kNumToShift = mLogicalLen - 1 - endIndex;
	ICARX_ASSERT(kNumToShift >= 1);
	R::moveItems(mpArray + startIndex, mPhysicalLen - startIndex, mpArray + endIndex + 1,
				 kNumToShift, true);
	mLogicalLen -= kNumToRemove;
	return *this;
}

template<class T, class R>
AcArray<T, R>& AcArray<T, R>::reverse()
{
	for (int i = 0; i < mLogicalLen / 2; i++)
	{
		T tmp = std::move(mpArray[i]);
		mpArray[i] = std::move(mpArray[mLogicalLen - 1 - i]);
		mpArray[mLogicalLen - 1 - i] = std::move(tmp);
	}
	return *this;
}

template<class T, class R>
AcArray<T, R>& AcArray<T, R>::setLogicalLength(int n)
{
	ICARX_ASSERT(n >= 0);
	if (n < 0)
		n = 0;
	ICARX_ASSERT(n <= maxLength());
	if (n > mPhysicalLen)
	{
		const int growth = (mPhysicalLen * sizeof(T)) < ACARRAY_GROWTH_THRESHOLD
								   ? mPhysicalLen
								   : ACARRAY_GROWTH_THRESHOLD / sizeof(T);

		int minSize = mPhysicalLen + std::max<int>(growth, mGrowLen);
		if (n > minSize)
			minSize = n;
		setPhysicalLength(minSize);
	}
	mLogicalLen = n;
	ICARX_ASSERT(mLogicalLen <= mPhysicalLen);
	return *this;
}

template<class T, class R>
AcArray<T, R>& AcArray<T, R>::setPhysicalLength(int n)
{
	ICARX_ASSERT(mPhysicalLen >= mLogicalLen);
	ICARX_ASSERT((mPhysicalLen == 0) == (mpArray == nullptr));
	ICARX_ASSERT(n >= 0);
	ICARX_ASSERT(n <= maxLength());
	if (n == mPhysicalLen || n < 0)
		return *this;

	T* pOldArray = mpArray;
	const size_t nOldLen = mPhysicalLen;

	mPhysicalLen = n;
	mpArray = nullptr;

	if (mPhysicalLen < mLogicalLen)
		mLogicalLen = mPhysicalLen;

	if (mPhysicalLen != 0)
	{
		mpArray = static_cast<T*>(::operator new(sizeof(T) * mPhysicalLen));
		ICARX_ASSERT(mpArray != nullptr);
		if (mpArray == nullptr)
		{
			mPhysicalLen = 0;
			mLogicalLen = 0;
		}
		else
		{
			T* pNewBuf = mpArray;
			for (int i = 0; i < mPhysicalLen; i++, pNewBuf++) ::new (pNewBuf) T;

			R::moveItems(mpArray, mPhysicalLen, pOldArray, mLogicalLen, false);
		}
	}

	for (size_t i = 0; i < nOldLen; i++) (pOldArray + i)->~T();

	::operator delete(static_cast<void*>(pOldArray));

	return *this;
}

template<class T, class R>
AcArray<T, R>& AcArray<T, R>::swap(int i1, int i2)
{
	ICARX_ASSERT(isValid(i1));
	ICARX_ASSERT(isValid(i2));

	if (i1 == i2)
		return *this;

	T tmp = std::move(mpArray[i1]);
	mpArray[i1] = std::move(mpArray[i2]);
	mpArray[i2] = std::move(tmp);
	return *this;
}

#include "acarrayhelper.h"

#pragma pop_macro("new")
#pragma pop_macro("delete")
#include "icarx/IcArxPackPop.h"

template<class T>
void AcArrayValidateParams(bool bSameBuffer, T* pDest, size_t nBufLen, const T* pSource,
						   size_t nCount)
{
	(void)(pDest);
	(void)(nBufLen);
	(void)(pSource);
	(void)(nCount);
	ICARX_ASSERT(nCount >= 0);
	ICARX_ASSERT(nCount <= nBufLen);
	ICARX_ASSERT(nCount <= AcArray<T>::maxLength());
	if (bSameBuffer)
	{
		ICARX_ASSERT(pSource > pDest);
	}
	else
	{
		ICARX_ASSERT(pSource >= pDest + nBufLen || (pDest >= pSource + nCount));
	}
}

#endif

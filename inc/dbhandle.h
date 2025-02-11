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
***     Description: Declaration of AcDbHandle class
***
*****************************************************************************/
#pragma once

#include "adesk.h"
#include <stddef.h>
#include "AcDbCore2dDefs.h"

#include "icarx/IcArxPackPush.h"

class AcDbHandle
{
	friend class AcDbHandleTable;
	friend class HandleDataBase;

private:
#pragma warning(push)
#pragma warning(disable : 4201)
	union
	{
		struct
		{
			uint32_t mLow;
			uint32_t mHigh;
		};

		uint64_t mWord64 = 0;
	} mHandle;
#pragma warning(pop)

private:
	uint64_t get64BitVal() const { return mHandle.mWord64; }
	void set64BitVal(uint64_t val) { mHandle.mWord64 = val; }

public:
	enum
	{
		kMaxValueBytes = 8
	};

	enum
	{
		kStrSiz = 17
	};

public:
	AcDbHandle() = default;
	AcDbHandle(int lo, int hi);
	AcDbHandle(const ACHAR*);
	AcDbHandle(uint64_t);
	AcDbHandle& operator=(const AcDbHandle&);
	AcDbHandle& operator=(const ACHAR*);
	AcDbHandle& operator=(uint64_t);
	AcDbHandle& operator++();
	AcDbHandle operator++(int);
	AcDbHandle operator+(IcArx::Integers::ULongPtr) const;
	AcDbHandle operator+(const AcDbHandle&) const;
	AcDbHandle& operator+=(const AcDbHandle&);
	AcDbHandle operator-(const AcDbHandle&) const;
	AcDbHandle& operator-=(const AcDbHandle&);
	bool operator<(const AcDbHandle&) const;
	bool operator<=(const AcDbHandle&) const;
	bool operator>(const AcDbHandle&) const;
	bool operator>=(const AcDbHandle&) const;
	bool operator==(const AcDbHandle&) const;
	bool operator!=(const AcDbHandle&) const;
	operator uint64_t() const;

	int byte(uint32_t i) const;
	int compare(const AcDbHandle&) const;
	void copyFromOldType(const uint8_t hand[8]);
	void copyToOldType(uint8_t hand[8]) const;
	void decrement();
	ACDBCORE2D_PORT bool getIntoAsciiBuffer(ACHAR* pBuf, size_t nBufLen) const;
	template<size_t nBufLen>
	inline bool getIntoAsciiBuffer(wchar_t (&buf)[nBufLen]) const
	{
		return this->getIntoAsciiBuffer(buf, nBufLen);
	}
	void getValueBytes(uint8_t*, uint8_t*) const;
	uint32_t high() const;
	void increment();
	bool isNull() const;
	bool isOne() const;
	uint32_t low() const;
	void print() const;
	bool restZeros(int i) const;
	void setHigh(uint32_t high);
	void setLow(uint32_t low);
	void setNull();
	void setValueBytes(uint8_t, const uint8_t*);
	AcDbHandle slowOperatorPlus(const AcDbHandle&) const;
};

#include "icarx/IcArxPackPop.h"

inline AcDbHandle::AcDbHandle(int lo, int hi)
{
	mHandle.mLow = lo;
	mHandle.mHigh = hi;
}

inline AcDbHandle::AcDbHandle(uint64_t val)
{
	this->set64BitVal(val);
}

inline AcDbHandle& AcDbHandle::operator=(const AcDbHandle& handle)
{
	this->set64BitVal(handle.get64BitVal());
	return *this;
}

inline AcDbHandle& AcDbHandle::operator=(uint64_t val)
{
	this->set64BitVal(val);
	return *this;
}

inline AcDbHandle& AcDbHandle::operator++()
{
	this->set64BitVal(get64BitVal() + 1);
	return *this;
}

inline AcDbHandle AcDbHandle::operator++(int)
{
	AcDbHandle tempHandle = *this;
	++(*this);
	return tempHandle;
}

inline AcDbHandle AcDbHandle::operator+(IcArx::Integers::ULongPtr val) const
{
	AcDbHandle tHandle(*this);
	tHandle.set64BitVal(tHandle.get64BitVal() + val);
	return tHandle;
}

inline AcDbHandle AcDbHandle::operator+(const AcDbHandle& handle) const
{
	AcDbHandle tHandle(*this);
	tHandle.set64BitVal(tHandle.get64BitVal() + handle.get64BitVal());
	return tHandle;
}

inline bool AcDbHandle::operator<(const AcDbHandle& handle) const
{
	return this->get64BitVal() < handle.get64BitVal();
}

inline bool AcDbHandle::operator>(const AcDbHandle& handle) const
{
	return this->get64BitVal() > handle.get64BitVal();
}

inline bool AcDbHandle::operator==(const AcDbHandle& handle) const
{
	return this->get64BitVal() == handle.get64BitVal();
}

inline bool AcDbHandle::operator!=(const AcDbHandle& handle) const
{
	return this->get64BitVal() != handle.get64BitVal();
}

inline AcDbHandle::operator uint64_t() const
{
	return get64BitVal();
}

inline int AcDbHandle::byte(uint32_t i) const
{
	if (i >= kMaxValueBytes)
		return 0;
	return *((unsigned char*)&(mHandle.mLow) + i);
}

inline int AcDbHandle::compare(const AcDbHandle& handle) const
{
	if (this->get64BitVal() > handle.get64BitVal())
		return -1;
	else if (this->get64BitVal() == handle.get64BitVal())
		return 0;
	else
		return 1;
}

inline void AcDbHandle::decrement()
{
	this->set64BitVal(get64BitVal() - 1);
}

inline uint32_t AcDbHandle::high() const
{
	return mHandle.mHigh;
}

inline void AcDbHandle::increment()
{
	this->set64BitVal(get64BitVal() + 1);
}

inline bool AcDbHandle::isNull() const
{
	return this->get64BitVal() == 0;
}

inline bool AcDbHandle::isOne() const
{
	return this->get64BitVal() == 1;
}

inline uint32_t AcDbHandle::low() const
{
	return mHandle.mLow;
}

inline bool AcDbHandle::restZeros(int i) const
{
	if (i < 0 || i >= kMaxValueBytes)
		return false;
	if (i < 4)
	{
		const uint32_t mask = ~0U << (i << 3);
		return !(mHandle.mHigh | (mHandle.mLow & mask));
	}
	else
	{
		const uint32_t mask = ~0U << ((i - 4) << 3);
		return !(mHandle.mHigh & mask);
	}
}

inline void AcDbHandle::setHigh(uint32_t high)
{
	mHandle.mHigh = high;
	return;
}

inline void AcDbHandle::setLow(uint32_t low)
{
	mHandle.mLow = low;
	return;
}

inline void AcDbHandle::setNull()
{
	mHandle.mHigh = mHandle.mLow = 0;
}

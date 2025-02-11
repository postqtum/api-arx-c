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
***     Description: Declaration of AcOutputBufMgr class
***
*****************************************************************************/
#pragma once

#include "IcArxAssert.h"

#include "IcArxPackPush.h"

class AcOutputBufMgr
{
private:
	void* mpBuffer;
	unsigned mnBufSize;
	unsigned mnByteCount;
	unsigned mnBytesRequested;

public:
	AcOutputBufMgr();
	~AcOutputBufMgr();

	bool attachBuffer(void* pBuffer, unsigned nBufSize);
	unsigned byteCount() const;
	bool detachBuffer();
	bool hasBuffer() const;
	void* pointer() const;
	void* requestBytes(unsigned nBytesNeeded);
	bool reset();
	unsigned takeBytes(unsigned nBytesUsed);
};

#include "IcArxPackPop.h"

inline AcOutputBufMgr::AcOutputBufMgr()
		: mpBuffer(nullptr), mnBufSize(0), mnByteCount(0), mnBytesRequested(0)
{
}

inline AcOutputBufMgr::~AcOutputBufMgr()
{
	ICARX_ASSERT(this->mnByteCount == 0);
	ICARX_ASSERT(this->mnBytesRequested == 0);
}

inline bool AcOutputBufMgr::attachBuffer(void* pBuffer, unsigned nBufSize)
{
	ICARX_ASSERT(pBuffer);
	ICARX_ASSERT(nBufSize > 2);
	ICARX_ASSERT(nBufSize < 0x10000000);
	ICARX_ASSERT(!this->mpBuffer);
	ICARX_ASSERT(this->mnBufSize == 0);
	ICARX_ASSERT(this->mnByteCount == 0);
	ICARX_ASSERT(this->mnBytesRequested == 0);
	if (this->mpBuffer || !pBuffer)
		return false;
	this->mpBuffer = pBuffer;
	this->mnBufSize = nBufSize;
	return true;
}

inline unsigned AcOutputBufMgr::byteCount() const
{
	return this->mnByteCount;
}

inline bool AcOutputBufMgr::detachBuffer()
{
	ICARX_ASSERT(this->mpBuffer);
	ICARX_ASSERT(this->mnBufSize != 0);
	ICARX_ASSERT(this->mnByteCount == 0);
	ICARX_ASSERT(this->mnBytesRequested == 0);
	if (!this->mpBuffer || this->mnByteCount != 0 || this->mnBytesRequested != 0)
		return false;
	this->mpBuffer = nullptr;
	this->mnBufSize = 0;
	return true;
}

inline bool AcOutputBufMgr::hasBuffer() const
{
	return this->mpBuffer != nullptr;
}

inline void* AcOutputBufMgr::pointer() const
{
	return this->mpBuffer;
}

inline void* AcOutputBufMgr::requestBytes(unsigned nBytesNeeded)
{
	ICARX_ASSERT(this->hasBuffer());
	ICARX_ASSERT(this->mnBytesRequested == 0);
	if (!this->hasBuffer() || this->mnBytesRequested != 0)
		return nullptr;
	ICARX_ASSERT(this->mnBufSize >= 2);
	ICARX_ASSERT(this->mnByteCount <= this->mnBufSize);
	ICARX_ASSERT(nBytesNeeded >= 1);
	ICARX_ASSERT(nBytesNeeded < this->mnBufSize);
	if (nBytesNeeded < 1 || nBytesNeeded >= this->mnBufSize)
		return nullptr;
	if (this->mnByteCount + nBytesNeeded > this->mnBufSize)
		return nullptr;
	this->mnBytesRequested = nBytesNeeded;

	return reinterpret_cast<char*>(this->mpBuffer) + this->mnByteCount;
}

inline bool AcOutputBufMgr::reset()
{
	ICARX_ASSERT(this->hasBuffer());
	ICARX_ASSERT(this->mnBytesRequested == 0);
	if (!this->hasBuffer() || this->mnBytesRequested != 0)
		return false;
	this->mnByteCount = 0;
	return true;
}

inline unsigned AcOutputBufMgr::takeBytes(unsigned nBytesUsed)
{
	ICARX_ASSERT(this->hasBuffer());
	ICARX_ASSERT(this->mnBytesRequested != 0);
	ICARX_ASSERT(this->mnBytesRequested >= nBytesUsed);
	if (!this->hasBuffer() || this->mnBytesRequested < nBytesUsed)
		return 0;
	this->mnBytesRequested = 0;
	this->mnByteCount += nBytesUsed;
	ICARX_ASSERT(this->mnByteCount <= this->mnBufSize);
	return this->mnBufSize - this->mnByteCount;
}

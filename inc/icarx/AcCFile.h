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
***     Description: Declaration of AcCFile class
***
*****************************************************************************/
#pragma once

#include "AcCFileFunctions.h"
#include "AcOutputBufMgr.h"

#include "IcArxPackPush.h"

class AcCFile : public CFile
{
private:
	AdCharFormatter mChFmtr;
	AcOutputBufMgr mOutputBufMgr;

public:
	AcCFile();
	AcCFile(HANDLE hFile);
	AcCFile(LPCTSTR lpszFileName, UINT nOpenFlags);
	~AcCFile() = default;

	UINT Read(void* lpBuf, UINT nCount) override;
	virtual UINT Read(LPTSTR lpBuf, UINT nCount);
	void Write(const void* lpBuf, UINT nCount) override;
	virtual void Write(LPCTSTR pString, UINT nCount);
	virtual void Write(LPCTSTR pString);
	bool attachBuffer(void* pBuffer, unsigned nBufSize);
	bool detachBuffer();
	bool flushBytes();
	unsigned getCharFormat() const { return this->mChFmtr.getFormat(); }
	bool getExpandLF() const { return this->mChFmtr.getExpandLF(); }
	bool getUseCIF() const { return this->mChFmtr.getUseCIF(); }
	bool hasBuffer() const;
	bool readBOM();
	unsigned setCharFormat(unsigned nFmt) { return this->mChFmtr.setFormat(nFmt); }
	bool setExpandLF(bool bExpandLF) { return this->mChFmtr.setExpandLF(bExpandLF); }
	bool setUseCIF(bool bUseCIF) { return this->mChFmtr.setUseCIF(bUseCIF); }
	bool writeBOM();
};

#include "IcArxPackPop.h"

inline AcCFile::AcCFile() : mChFmtr(AdCharFormatter::kAnsi, false, false)
{
	this->mChFmtr.setExpandLF(false);
}

inline AcCFile::AcCFile(HANDLE hFile) : CFile(hFile), mChFmtr(AdCharFormatter::kAnsi, false, false)
{
}

inline AcCFile::AcCFile(LPCTSTR lpszFileName, UINT nOpenFlags)
		: CFile(lpszFileName, nOpenFlags), mChFmtr(AdCharFormatter::kAnsi, false, false)
{
}

inline UINT AcCFile::Read(void* lpBuf, UINT nCount)
{
	return this->CFile::Read(lpBuf, nCount);
}

inline UINT AcCFile::Read(LPTSTR lpBuf, UINT nCount)
{
	UINT nDestIndex = 0;
	for (;;)
	{
		ICARX_ASSERT(nDestIndex <= nCount);
		if (nDestIndex == nCount)
			break;
		wchar_t wch = 0;
		bool bReadOk = false;
		switch (this->mChFmtr.getFormat())
		{
			case AdCharFormatter::kAnsi:
				bReadOk = ::acReadAnsiCharFromCFile(this, wch, &(this->mChFmtr));
				break;
			case AdCharFormatter::kUtf8:
				bReadOk = ::acReadUtf8CharFromCFile(this, wch, &(this->mChFmtr));
				break;
			case AdCharFormatter::kUtf16LE:
			case AdCharFormatter::kUtf16BE:
				bReadOk = ::acReadUtf16CharFromCFile(this, wch, &(this->mChFmtr));
				break;
		}

		if (!bReadOk)
			break;
		lpBuf[nDestIndex] = wch;
		nDestIndex++;
	}
	return nDestIndex;
}

inline void AcCFile::Write(const void* lpBuf, UINT nCount)
{
	this->CFile::Write(lpBuf, nCount);
}

inline void AcCFile::Write(LPCTSTR lpBuf, UINT nCount)
{
	ICARX_ASSERT(nCount < 0x1000000);
	const bool bHasBuffer = this->hasBuffer();
	for (unsigned i = 0; i < nCount; i++)
	{
		if (!bHasBuffer)
			::acWriteWCharToCFile(lpBuf[i], this, this->mChFmtr);
		else
		{
			const int kReservedSize = 8;
			void* pOutBuf = this->mOutputBufMgr.requestBytes(kReservedSize);
			const int nBytes = this->mChFmtr.wcharToBytes(
					lpBuf[i], reinterpret_cast<char*>(pOutBuf), kReservedSize);
			ICARX_ASSERT(nBytes >= 1);
			ICARX_ASSERT(nBytes <= kReservedSize);
			const unsigned nBytesLeft = this->mOutputBufMgr.takeBytes(nBytes);
			if (nBytesLeft <= kReservedSize)
				this->flushBytes();
		}
	}
}

inline void AcCFile::Write(LPCTSTR lpBuf)
{
	this->Write(lpBuf, AdCharFormatter::wcsLength(lpBuf));
}

inline bool AcCFile::attachBuffer(void* pBuffer, unsigned nBufSize)
{
	return this->mOutputBufMgr.attachBuffer(pBuffer, nBufSize);
}

inline bool AcCFile::detachBuffer()
{
	return this->mOutputBufMgr.detachBuffer();
}

inline bool AcCFile::flushBytes()
{
	ICARX_ASSERT(this->hasBuffer());
	if (!this->hasBuffer())
		return false;
	const unsigned nBytes = this->mOutputBufMgr.byteCount();
	if (nBytes != 0)
	{
		const void* pBuf = this->mOutputBufMgr.pointer();
		this->Write(pBuf, nBytes);
	}
	this->mOutputBufMgr.reset();
	return true;
}

inline bool AcCFile::hasBuffer() const
{
	return this->mOutputBufMgr.hasBuffer();
}

inline bool AcCFile::readBOM()
{
	const ULONGLONG dwPosition = this->GetPosition();
	ICARX_ASSERT(dwPosition == 0);
	if (dwPosition != 0)
		return false;

	unsigned short nVal;
	if (this->Read(&nVal, 2) == 2)
	{
		if (nVal == 0xfeff)
		{
			this->setCharFormat(AdCharFormatter::kUtf16LE);
			return true;
		}
		if (nVal == 0xfffe)
		{
			this->setCharFormat(AdCharFormatter::kUtf16BE);
			return true;
		}
		if (nVal == 0xbbef)
		{
			unsigned char nByte3;
			if (this->Read(&nByte3, 1) == 1)
			{
				if (nByte3 == 0xbf)
				{
					this->setCharFormat(AdCharFormatter::kUtf8);
					return true;
				}
			}
		}
		else if (nVal == 0 || nVal == 0xfeff)
		{
			unsigned nVal2;
			if (this->Read(&nVal2, 2) == 2)
			{
				if (nVal == 0 && nVal2 == 0xfffe)
				{
					this->setCharFormat(AdCharFormatter::kUtf32BE);
					return true;
				}
				else if (nVal == 0xfeff && nVal2 == 0)
				{
					this->setCharFormat(AdCharFormatter::kUtf32LE);
					return true;
				}
			}
		}
	}

	this->SeekToBegin();
	return false;
}

inline bool AcCFile::writeBOM()
{
	ICARX_ASSERT((this->m_hFile) != CFile::hFileNull);
	if ((this->m_hFile) == CFile::hFileNull)
		return false;

	const ULONGLONG dwPosition = this->GetPosition();
	ICARX_ASSERT(dwPosition == 0);
	if (dwPosition != 0)
		return false;

	unsigned nBom = 0;
	const int cbBomSize = AdCharFormatter::getBOM(nBom, this->getCharFormat());
	if (cbBomSize == 0)
		return false;

	this->Write(&nBom, cbBomSize);
	return true;
}

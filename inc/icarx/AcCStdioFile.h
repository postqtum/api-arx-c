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
***     Description: Declaration of AcCStdioFile class
***
*****************************************************************************/
#pragma once

#include "AcCFileFunctions.h"
#include "AcOutputBufMgr.h"

#include "IcArxPackPush.h"

class AcCStdioFile : public CStdioFile
{
private:
	AdCharFormatter mChFmtr;
	AcOutputBufMgr mOutputBufMgr;

public:
	AcCStdioFile();
	AcCStdioFile(FILE* pOpenStream);
	AcCStdioFile(LPCTSTR lpszFileName, UINT nOpenFlags);
	~AcCStdioFile() = default;

	LPTSTR ReadString(LPTSTR lpsz, UINT nMax) override;
	BOOL ReadString(CString& rString) override;
	void WriteString(LPCTSTR lpsz) override;
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

inline AcCStdioFile::AcCStdioFile() : mChFmtr(AdCharFormatter::kAnsi, true, false)
{
}

inline AcCStdioFile::AcCStdioFile(FILE* pOpenStream)
		: CStdioFile(pOpenStream), mChFmtr(AdCharFormatter::kAnsi, true, false)
{
}

inline AcCStdioFile::AcCStdioFile(LPCTSTR lpszFileName, UINT nOpenFlags)
		: CStdioFile(lpszFileName, nOpenFlags), mChFmtr(AdCharFormatter::kAnsi, true, false)
{
}

inline LPTSTR AcCStdioFile::ReadString(LPTSTR lpsz, UINT nMax)
{
	ICARX_ASSERT(lpsz);
	ICARX_ASSERT(nMax >= 1);
	if (nMax < 1)
		return nullptr;

	bool bGotAnyData = false;
	UINT nDestIndex = 0;
	for (;;)
	{
		ICARX_ASSERT(nDestIndex < nMax - 1);
		if (nDestIndex >= nMax - 1)
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
		lpsz[nDestIndex] = wch;
		nDestIndex++;
		bGotAnyData = true;
		if (wch == L'\n' || nDestIndex >= nMax - 1)
			break;
	}
	ICARX_ASSERT(nDestIndex < nMax);
	lpsz[nDestIndex] = 0;
	return bGotAnyData ? lpsz : nullptr;
}

inline BOOL AcCStdioFile::ReadString(CString& rString)
{
	rString.Empty();

	bool bGotAnyData = false;
	for (;;)
	{
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
		bGotAnyData = true;
		if (wch == L'\n')
			break;
		rString.AppendChar(wch);
	}
	return bGotAnyData;
}

inline void AcCStdioFile::WriteString(LPCTSTR lpsz)
{
	const bool bHasBuffer = this->hasBuffer();
	for (;;)
	{
		const wchar_t wch = *lpsz;
		if (wch == L'\0')
			break;
		if (!bHasBuffer)
			::acWriteWCharToCFile(wch, this, this->mChFmtr);
		else
		{
			const int kReservedSize = 8;
			void* pOutBuf = this->mOutputBufMgr.requestBytes(kReservedSize);
			const int nBytes = this->mChFmtr.wcharToBytes(wch, reinterpret_cast<char*>(pOutBuf),
														  kReservedSize);
			ICARX_ASSERT(nBytes >= 1);
			ICARX_ASSERT(nBytes <= kReservedSize);
			const unsigned nBytesLeft = this->mOutputBufMgr.takeBytes(nBytes);
			if (nBytesLeft <= kReservedSize)
				this->flushBytes();
		}
		lpsz++;
	}
}

inline bool AcCStdioFile::attachBuffer(void* pBuffer, unsigned nBufSize)
{
	return this->mOutputBufMgr.attachBuffer(pBuffer, nBufSize);
}

inline bool AcCStdioFile::detachBuffer()
{
	return this->mOutputBufMgr.detachBuffer();
}

inline bool AcCStdioFile::flushBytes()
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

inline bool AcCStdioFile::hasBuffer() const
{
	return this->mOutputBufMgr.hasBuffer();
}

inline bool AcCStdioFile::readBOM()
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

inline bool AcCStdioFile::writeBOM()
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

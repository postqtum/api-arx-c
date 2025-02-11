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
***     Description:
***
*****************************************************************************/
#pragma once

#include "PAL/api/def.h"
#include "stdio.h"
#include "AdCharFmt.h"
#include "casuppress.h"
#include <cstdarg>
#include "acbasedefs.h"

#pragma warning(push)
#pragma warning(disable : 4996)

#include "icarx/IcArxAssert.h"
#define AcFILE_Assert ICARX_ASSERT

#include "icarx/IcArxPackPush.h"

class AcFILE
{
private:
	FILE* mpFILE;
	AdCharFormatter mChFmtr;

private:
	int fputsWorker(const wchar_t* pSrc, int nOptions);
	bool parseAnsiOrCIF(wchar_t& wch);
	bool parseUtf16(wchar_t& wch);
	bool parseUtf8(wchar_t& wch);

public:
	AcFILE() : mpFILE(nullptr), mChFmtr(AdCharFormatter::kAnsi, false, false) {}
	AcFILE(FILE* pFILE) : mpFILE(pFILE), mChFmtr(AdCharFormatter::kAnsi, false, false) {}
	~AcFILE() { ICARX_ASSERT(!this->mpFILE); }

	void attach(FILE* pFILE);
	FILE* detach();
	unsigned getCharFormat() const { return this->mChFmtr.getFormat(); }
	bool getExpandLF() const { return this->mChFmtr.getExpandLF(); }
	bool getUseCIF() const { return this->mChFmtr.getUseCIF(); }
	int fclose();
	ACBASE_PORT int fgetc();
	wchar_t* fgets(wchar_t* pBuf, int nChars);
	ACBASE_PORT FILE* fopen(const wchar_t* pName, const wchar_t* pMode);
	ACBASE_PORT int fprintf(const wchar_t* pFmtStr, ...);
	int fputc(wchar_t c);
	int fputs(const wchar_t* pStr);
	int fscanf(const wchar_t* pFmtStr, ...);
	ACBASE_PORT FILE* fsopen(const wchar_t* pName, const wchar_t* pMode, int shflag);
	bool isOpen() const { return this->mpFILE != nullptr; }
	FILE* pFILE() const { return this->mpFILE; }
	bool readBOM();
	unsigned setCharFormat(unsigned nFmt) { return this->mChFmtr.setFormat(nFmt); }
	bool setExpandLF(bool bExpandLF) { return this->mChFmtr.setExpandLF(bExpandLF); }
	bool setUseCIF(bool bUseCIF) { return this->mChFmtr.setUseCIF(bUseCIF); }
	int ungetc(wchar_t c);
	ACBASE_PORT int vfprintf(const wchar_t* pFmtStr, va_list va);
	bool writeBOM();
};

#include "icarx/IcArxPackPop.h"

inline void AcFILE::attach(FILE* pFILE)
{
	ICARX_ASSERT(!this->mpFILE);
	this->mpFILE = pFILE;
}

inline FILE* AcFILE::detach()
{
	FILE* pRet = this->mpFILE;
	this->mpFILE = nullptr;
	return pRet;
}

inline int AcFILE::fclose()
{
	int nRet = 0;
	if (this->mpFILE)
	{
		nRet = ::fclose(this->mpFILE);
		this->mpFILE = nullptr;
	}
	return nRet;
}

inline wchar_t* AcFILE::fgets(wchar_t* pBuf, int nChars)
{
	ICARX_ASSERT(this->mpFILE);
	ICARX_ASSERT(nChars > 1);

	wchar_t* pSavePtr = pBuf;
	for (;;)
	{
		if (nChars <= 1)
			break;
		const int ch = this->fgetc();
		if (ch == EOF)
			break;
		ICARX_ASSERT((ch & ~0xffff) == 0);
		ICARX_ASSERT((wchar_t)ch == ch);
		*pSavePtr = (wchar_t)ch;
		pSavePtr++;
		if (ch == '\n')
			break;
		nChars--;
	}
	*pSavePtr = 0;

	if (pSavePtr == pBuf)
		return nullptr;

	return pBuf;
}

inline int AcFILE::fputc(wchar_t c)
{
	ICARX_ASSERT(this->mpFILE);

	char chBuf[8];
	const unsigned nBytes = this->mChFmtr.wcharToBytes(c, chBuf, sizeof(chBuf));
	ICARX_ASSERT(nBytes >= 1);
	ICARX_ASSERT(nBytes <= 8);
	const unsigned nNumWrote = (unsigned)fwrite(chBuf, 1, nBytes, this->mpFILE);
	if (nNumWrote == nBytes)
		return c;
	else
		return -1;
}

inline int AcFILE::fputs(const wchar_t* pStr)
{
	ICARX_ASSERT(this->mpFILE);
	return fputsWorker(pStr, 0);
}

inline int AcFILE::fputsWorker(const wchar_t* pSrc, int nOptions)
{
	ICARX_ASSERT(this->mpFILE);
	ICARX_ASSERT(pSrc);

	int nNumInput = 0;
	for (;;)
	{
		const wchar_t wch = *pSrc;
		if (wch == 0)
			break;
		char chBuf[8];
		const unsigned nBytes = this->mChFmtr.wcharToBytes(wch, chBuf, sizeof(chBuf));
		ICARX_ASSERT(nBytes >= 1);
		ICARX_ASSERT(nBytes <= 8);
		const unsigned nNumWrote = (unsigned)fwrite(chBuf, 1, nBytes, this->mpFILE);
		if (nNumWrote != nBytes)
			return -1;
		nNumInput++;
		pSrc++;
	}

	if (nOptions == 0)
		return 0;
	else if (nOptions == 1)
		return nNumInput;
	else
	{
		ICARX_ASSERT(false);
	}

	return -1;
}

inline int AcFILE::fscanf(const wchar_t* pFmtStr, ...)
{
	ICARX_ASSERT(this->mpFILE);

	pFmtStr = nullptr;

	ICARX_ASSERT(false);
	return -1;
}

inline bool AcFILE::parseUtf16(wchar_t& wch)
{
	wchar_t wchLocal = 0;
	int nBytesRead = (int)::fread(&wchLocal, 1, 2, this->mpFILE);
	if (nBytesRead <= 0)
		return false;

	const unsigned nFormat = this->mChFmtr.getFormat();
	if (nFormat == AdCharFormatter::kUtf16BE)
		wchLocal = (wchLocal >> 8) | (wchLocal << 8);

	wch = wchLocal;
	if (wchLocal == L'\r' && mChFmtr.getExpandLF())
	{
		wchar_t wchNewLine = L'\n';
		nBytesRead = (int)::fread(&wchNewLine, 1, 2, this->mpFILE);
		if (nBytesRead <= 0)
			return true;

		if (nFormat == AdCharFormatter::kUtf16BE)
			wchNewLine = (wchNewLine >> 8) | (wchNewLine << 8);
		if (wchNewLine != L'\n')
		{
			::fseek(this->mpFILE, -2L, SEEK_CUR);
			return true;
		}
		wch = L'\n';
	}

	return true;
}

inline bool AcFILE::readBOM()
{
	ICARX_ASSERT(this->mpFILE);
	const long lFilePos = ::ftell(this->mpFILE);
	ICARX_ASSERT(lFilePos == 0L);
	if (lFilePos != 0L)
		return false;

	unsigned short nVal;
	if (::fread(&nVal, 1, 2, this->mpFILE) == 2)
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
			if (::fread(&nByte3, 1, 1, this->mpFILE) == 1)
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
			if (::fread(&nVal2, 1, 2, this->mpFILE) == 2)
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

	::rewind(this->mpFILE);
	return false;
}

inline int AcFILE::ungetc(wchar_t c)
{
	ICARX_ASSERT(this->mpFILE);

	char chBuf[8];
	const unsigned nBytes = this->mChFmtr.wcharToBytes(c, chBuf, sizeof(chBuf));
	ICARX_ASSERT(nBytes >= 1);
	ICARX_ASSERT(nBytes <= 8);
	if (nBytes == 1 && ::ungetc(chBuf[0], this->mpFILE) == chBuf[0])
		return c;
	else
		return -1;
}

inline bool AcFILE::writeBOM()
{
	ICARX_ASSERT(this->mpFILE);
	if (!this->mpFILE)
		return false;

	const long lFilePos = ::ftell(this->mpFILE);
	ICARX_ASSERT(lFilePos == 0L);
	if (lFilePos != 0L)
		return false;

	unsigned nBom = 0;
	const int cbBomSize = AdCharFormatter::getBOM(nBom, this->getCharFormat());
	if (cbBomSize == 0)
		return false;

	const int cbWritten = (int)::fwrite(&nBom, 1, cbBomSize, this->mpFILE);

	ICARX_ASSERT(cbWritten == cbBomSize);
	if (cbWritten != cbBomSize)
	{
		::rewind(this->mpFILE);
		return false;
	}

	return true;
}

#pragma warning(pop)

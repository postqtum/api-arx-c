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

#include "IcArxAssert.h"
#include "../AdCharFmt.h"

inline void acByteSwap(wchar_t& wch)
{
	const wchar_t lobits = (wch >> 8) & 0x00ff;
	const wchar_t hibits = (wch << 8) & 0xff00;
	wch = lobits | hibits;
}

inline bool acReadCIFFromCFile(CFile* pCFile, wchar_t& wch)
{
	const ULONGLONG nCurPos = pCFile->GetPosition();
	char chbuf[9];
	chbuf[0] = '\\';
	const unsigned nCharRead = pCFile->Read(chbuf + 1, 1);
	ICARX_ASSERT(nCharRead <= 1);
	if (nCharRead == 1)
	{
		if (chbuf[1] == 'U' || chbuf[1] == 'u')
		{
			const unsigned nMoreCharsRead = pCFile->Read(chbuf + 2, 5);
			ICARX_ASSERT(nMoreCharsRead <= 5);
			chbuf[2 + nMoreCharsRead] = 0;
			if (AdCharFormatter::isCIFString(chbuf))
				if (AdCharFormatter::parseCIF(chbuf, wch))
					return true;
		}
		else if (chbuf[1] == 'M' || chbuf[1] == 'm')
		{
			const unsigned nMoreCharsRead = pCFile->Read(chbuf + 2, 6);
			ICARX_ASSERT(nMoreCharsRead <= 6);
			chbuf[2 + nMoreCharsRead] = 0;
			if (AdCharFormatter::isCIFString(chbuf))
				if (AdCharFormatter::parseCIF(chbuf, wch))
					return true;
		}
	}
	pCFile->Seek(nCurPos, SEEK_SET);
	return false;
}

inline bool acReadAnsiCharFromCFile(CFile* pCFile, wchar_t& wch, AdCharFormatter* pChFmtr)
{
	char chbuf[2];
	const bool bUseCIF = pChFmtr->getUseCIF();
	const int nCharsRead = pCFile->Read(chbuf, 1);
	if (nCharsRead <= 0)
		return false;
	ICARX_ASSERT(nCharsRead == 1);

	if (chbuf[0] >= 0 && static_cast<unsigned char>(chbuf[0]) <= 0x7f)
	{
		wch = chbuf[0];
		if (chbuf[0] == '\r' && pChFmtr->getExpandLF())
		{
			unsigned char newLine = 0;
			const int nBytesRead = pCFile->Read(&newLine, 1);
			if (nBytesRead < 1)
				return true;
			if (newLine != '\n')
			{
				pCFile->Seek(-1L, CFile::current);
				return true;
			}
			wch = L'\n';
		}
		if (chbuf[0] == '\\' && bUseCIF && acReadCIFFromCFile(pCFile, wch))
			return true;
		return true;
	}
	bool bDoubleByte = false;
	if (::IsDBCSLeadByte(chbuf[0]))
	{
		const int nTrailingCharsRead = pCFile->Read(chbuf + 1, 1);
		ICARX_ASSERT(nTrailingCharsRead == 1);
		if (nTrailingCharsRead != 1)
		{
			return false;
		}
		bDoubleByte = true;
	}
	const int nConverted = ::MultiByteToWideChar(CP_ACP, 0, chbuf, bDoubleByte ? 2 : 1, &wch, 1);
	ICARX_ASSERT(nConverted == 1);
	if (nConverted != 1) {}
	return true;
}

inline bool acReadUtf8CharFromCFile(CFile* pCFile, wchar_t& wch, AdCharFormatter* pChFmtr)
{
	char chbuf[4];
	wch = 0;


	unsigned nCharsRead = pCFile->Read(chbuf, 1);
	if (nCharsRead <= 0)
		return false;
	ICARX_ASSERT(nCharsRead == 1);

	unsigned nByteCount = 1;
	unsigned char firstByte = (unsigned char)chbuf[0];

	if (!(firstByte & 0x80))
	{
		wch = (wchar_t)firstByte;
		if (firstByte == '\r' && pChFmtr->getExpandLF())
		{
			unsigned char newLine = 0;
			const int nBytesRead = pCFile->Read(&newLine, 1);
			if (nBytesRead < 1)
				return true;
			if (newLine != '\n')
			{
				pCFile->Seek(-1L, CFile::current);
				return true;
			}
			wch = L'\n';
		}
		return true;
	}

	if ((firstByte & 0xF0) == 0xF0)
		nByteCount = 4;
	else if ((firstByte & 0xE0) == 0xE0)
		nByteCount = 3;
	else if ((firstByte & 0xC0) == 0xC0)
		nByteCount = 2;

	if (nByteCount > 1)
	{
		nCharsRead = pCFile->Read(&chbuf[1], nByteCount - 1);
		ICARX_ASSERT(nCharsRead >= 1);
		ICARX_ASSERT(nCharsRead == (nByteCount - 1));
	}

	const int nConverted = ::MultiByteToWideChar(CP_UTF8, 0, chbuf, nByteCount, &wch, 1);

	ICARX_ASSERT(nConverted == 1);
	if (nConverted != 1) {}
	return true;
}

inline bool acReadUtf16CharFromCFile(CFile* pCFile, wchar_t& wch, AdCharFormatter* pChFmtr)
{
	ICARX_ASSERT(pChFmtr);
	const int nCharsRead = pCFile->Read(&wch, 2);
	if (nCharsRead < 2)
	{
		wch = 0;
		return false;
	}

	ICARX_ASSERT(nCharsRead == 2);
	const unsigned nFileFormat = pChFmtr->getFormat();

	if (nFileFormat == AdCharFormatter::kUtf16BE)
		acByteSwap(wch);

	if (wch == L'\r' && pChFmtr->getExpandLF())
	{
		wchar_t wchNewLine = 0;
		const int nBytesRead = pCFile->Read(&wchNewLine, 2);
		if (nBytesRead < 2)
			return true;
		if (nFileFormat == AdCharFormatter::kUtf16BE)
			acByteSwap(wchNewLine);
		if (wchNewLine != '\n')
		{
			pCFile->Seek(-2L, CFile::current);
			return true;
		}
		wch = '\n';
		return true;
	}

	return true;
}

inline void acWriteWCharToCFile(wchar_t wch, CFile* pFile, const AdCharFormatter& charFmt)
{
	char chBuf[8];
	const int nBytes = charFmt.wcharToBytes(wch, chBuf, sizeof(chBuf));
	ICARX_ASSERT(nBytes >= 1);
	ICARX_ASSERT(nBytes <= 8);
	pFile->Write(chBuf, nBytes);
}

inline unsigned acCheckCFileCharFormat(CFile* pCFile)
{
	ICARX_ASSERT(pCFile);
	ICARX_ASSERT((pCFile->m_hFile) != (CFile::hFileNull));

	const int nLength = (int)pCFile->GetLength();
	if (nLength <= 3)
		return AdCharFormatter::kAnsi;

	const ULONGLONG ullPrevPos = pCFile->GetPosition();
	pCFile->Seek(0L, SEEK_SET);

	DWORD dwMagicCode = 0;

	pCFile->Read(&dwMagicCode, 4);

	pCFile->Seek(ullPrevPos, SEEK_SET);

	const unsigned nCharFmt = AdCharFormatter::lookupBOM(dwMagicCode);
	return (nCharFmt == AdCharFormatter::kUnknown) ? AdCharFormatter::kAnsi : nCharFmt;
}

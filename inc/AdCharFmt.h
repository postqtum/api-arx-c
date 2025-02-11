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

#include "adesk.h"
#include "casuppress.h"

#pragma warning(push, 4)

#include "icarx/IcArxAssert.h"
#define AdCharFmt_Assert ICARX_ASSERT

#include "acbasedefs.h"
#include "PAL/api/codepgid.h"
#include <stddef.h>

class AdCharFormatter
{
public:
	enum
	{
		kUnknown = 0,
		kAnsi,
		kUtf8,
		kUtf16LE,
		kUtf16BE,
		kUtf32LE,
		kUtf32BE
	};
	AdCharFormatter(unsigned nFormat, bool bUseCIF, bool bExpandLF)
			: mnFormat(nFormat), mbUseCIF(bUseCIF), mbExpandLF(bExpandLF)
	{
		ICARX_ASSERT(this->mbUseCIF == false || this->mnFormat == kAnsi);
	}

	AdCharFormatter() : mnFormat(kAnsi), mbUseCIF(false), mbExpandLF(true) {}

	static unsigned lookupBOM(unsigned nBom)
	{
		if ((nBom & 0x00ffffff) == 0xbfbbef)
			return kUtf8;
		if ((nBom & 0x0000ffff) == 0xfeff)
			return kUtf16LE;
		if ((nBom & 0x0000ffff) == 0xfffe)
			return kUtf16BE;
		if (nBom == 0x0000feff)
			return kUtf32LE;
		if (nBom == 0xfffe0000)
			return kUtf32BE;
		return kUnknown;
	}

	static int getBOM(unsigned& nBom, unsigned nFmt)
	{
		if (nFmt == kUtf8)
		{
			nBom = 0xbfbbef;
			return 3;
		}
		else if (nFmt == kUtf16LE)
		{
			nBom = 0xfeff;
			return 2;
		}
		else if (nFmt == kUtf16BE)
		{
			nBom = 0xfffe;
			return 2;
		}
		else if (nFmt == kUtf32LE)
		{
			nBom = 0x0000feff;
			return 4;
		}
		else if (nFmt == kUtf32BE)
		{
			nBom = 0xfffe0000;
			return 4;
		}
		else
		{
			ICARX_ASSERT(nFmt == kUnknown || nFmt == kAnsi);
			return 0;
		}
	}

	template<class ChType>
	static void putCIF(wchar_t wch, ChType* pDest)
	{
		pDest[0] = '\\';
		pDest[1] = 'U';
		pDest[2] = '+';
		for (int i = 0; i < 4; i++)
		{
			const ChType n = (ChType)(wch & 0xf);
			pDest[6 - i] = (n <= 9) ? ('0' + n) : ('A' - 10 + n);
			wch >>= 4;
		}
	}

	bool getUseCIF() const { return this->mbUseCIF; }
	bool getExpandLF() const { return this->mbExpandLF; }
	unsigned getFormat() const { return this->mnFormat; }

	bool setUseCIF(bool bUseCIF)
	{
		const bool bOldUseCIF = this->mbUseCIF;
		this->mbUseCIF = bUseCIF;
		return bOldUseCIF;
	}
	bool setExpandLF(bool bExpandLF)
	{
		const bool bOldExpandLF = this->mbExpandLF;
		this->mbExpandLF = bExpandLF;
		return bOldExpandLF;
	}
	unsigned setFormat(unsigned nFormat)
	{
		const unsigned nOldFormat = this->mnFormat;
		this->mnFormat = nFormat;
		return nOldFormat;
	}

	static unsigned wcsLength(const wchar_t* pStr)
	{
		unsigned nLen = 0;
		while (*pStr != L'\0')
		{
			nLen++;
			pStr++;
		}
		return nLen;
	}

	static ACBASE_PORT unsigned wcharToAnsiOrUtf8(wchar_t wch, char* pDestBuf,
												  unsigned nDestBufSize, bool bToAnsi, bool bUseCIF,
												  bool bExpandLF);

	static ACBASE_PORT unsigned wcharToUtf16(wchar_t wch, char* pDestBuf, unsigned nDestBufSize,
											 bool bLittleEndian, bool bExpandLF);

	unsigned wcharToBytes(wchar_t wch, char* pDestBuf, unsigned nDestBufSize) const
	{
		if (this->mnFormat == kAnsi || this->mnFormat == kUtf8)
			return wcharToAnsiOrUtf8(wch, pDestBuf, nDestBufSize, this->mnFormat == kAnsi,
									 this->mbUseCIF, this->mbExpandLF);
		else if (this->mnFormat == kUtf16LE || this->mnFormat == kUtf16BE)
		{
			ICARX_ASSERT(!this->mbUseCIF);
			return wcharToUtf16(wch, pDestBuf, nDestBufSize, this->mnFormat == kUtf16LE,
								this->mbExpandLF);
		}
		else
		{
			ICARX_ASSERT(!this->mbUseCIF);
			ICARX_ASSERT(nDestBufSize >= 4);
			ICARX_ASSERT(this->mnFormat == kUtf32LE || this->mnFormat == kUtf32BE);
			ICARX_ASSERT(this->mnFormat != kUtf32LE);
			ICARX_ASSERT(this->mnFormat != kUtf32BE);
			return 0;
		}
	}

	template<class ChType>
	static bool isHex(ChType ch)
	{
		return (ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'F') || (ch >= 'a' && ch <= 'f');
	}

	template<class ChType>
	static bool isHex(ChType ch, unsigned& uVal)
	{
		if (ch >= '0' && ch <= '9')
		{
			uVal = ch - '0';
			ICARX_ASSERT(uVal <= 9);
			return true;
		}
		if (ch >= 'A' && ch <= 'F')
		{
			uVal = ch - 'A' + 10;
			ICARX_ASSERT(uVal >= 10);
			ICARX_ASSERT(uVal <= 15);
			return true;
		}
		if (ch >= 'a' && ch <= 'f')
		{
			uVal = ch - 'a' + 10;
			ICARX_ASSERT(uVal >= 10);
			ICARX_ASSERT(uVal <= 15);
			return true;
		}
		return false;
	}

	template<class ChType>
	static bool isCIFString(const ChType* pSrcBuf)
	{
		ICARX_ASSERT(pSrcBuf);

		if (pSrcBuf[0] == '\\' && (pSrcBuf[1] == 'U' || pSrcBuf[1] == 'u') && pSrcBuf[2] == '+' &&
			isHex<ChType>(pSrcBuf[3]) && isHex<ChType>(pSrcBuf[4]) && isHex<ChType>(pSrcBuf[5]) &&
			isHex<ChType>(pSrcBuf[6]))
			return true;

		return false;
	}

	template<class ChType>
	static bool isCIFString(const ChType* pSrcBuf, unsigned nSrcBufSize)
	{
		ICARX_ASSERT(pSrcBuf);
		ICARX_ASSERT(nSrcBufSize > 0);
		if (nSrcBufSize < 7)
			return false;
		return isCIFString<ChType>(pSrcBuf);
	}

	template<class ChType>
	static bool parseCIF(const ChType* pSrcBuf, wchar_t& wch)
	{
		ICARX_ASSERT(pSrcBuf);
		if (!pSrcBuf)
			return false;

		if (pSrcBuf[0] != '\\' || (pSrcBuf[1] != 'U' && pSrcBuf[1] != 'u') || pSrcBuf[2] != '+')
			return false;

		unsigned uVal;
		if (!isHex<ChType>(pSrcBuf[3], uVal))
			return false;
		wch = (wchar_t)(uVal << 12);
		if (!isHex<ChType>(pSrcBuf[4], uVal))
			return false;
		wch |= (wchar_t)(uVal << 8);
		if (!isHex<ChType>(pSrcBuf[5], uVal))
			return false;
		wch |= (wchar_t)(uVal << 4);
		if (!isHex<ChType>(pSrcBuf[6], uVal))
			return false;
		wch |= (wchar_t)uVal;

		return true;
	}

	template<class ChType>
	static bool isMIFString(const ChType* pSrcBuf)
	{
		ICARX_ASSERT(pSrcBuf);

		if (pSrcBuf[0] == '\\' && (pSrcBuf[1] == 'M' || pSrcBuf[1] == 'm') && pSrcBuf[2] == '+' &&
			pSrcBuf[3] >= '1' && pSrcBuf[3] <= '5' && isHex<ChType>(pSrcBuf[4]) &&
			isHex<ChType>(pSrcBuf[5]) && isHex<ChType>(pSrcBuf[6]) && isHex<ChType>(pSrcBuf[7]))
			return true;

		return false;
	}

	template<class ChType>
	static bool isMIFString(const ChType* pSrcBuf, unsigned nSrcBufSize)
	{
		ICARX_ASSERT(pSrcBuf);
		ICARX_ASSERT(nSrcBufSize > 0);
		if (nSrcBufSize < 8)
			return false;
		return isMIFString<ChType>(pSrcBuf);
	}

	static unsigned winCodePageFromMIFIndex(unsigned nIdx)
	{
		return nIdx == 1   ? 932
			   : nIdx == 2 ? 950
			   : nIdx == 3 ? 949
			   : nIdx == 4 ? 1361
			   : nIdx == 5 ? 936
						   : 0;
	}

	static code_page_id codePageIdFromMIFIndex(uint8_t nIdx)
	{
		return nIdx == 1   ? code_page_id::CODE_PAGE_DOS932
			   : nIdx == 2 ? code_page_id::CODE_PAGE_BIG5
			   : nIdx == 3 ? code_page_id::CODE_PAGE_KSC5601
			   : nIdx == 4 ? code_page_id::CODE_PAGE_JOHAB
			   : nIdx == 5 ? code_page_id::CODE_PAGE_GB2312
						   : code_page_id::CODE_PAGE_CURRENT;
	}

	static unsigned char MIFIndexFromWinCodePage(unsigned nCodePage)
	{
		return nCodePage == 932	   ? 1
			   : nCodePage == 950  ? 2
			   : nCodePage == 949  ? 3
			   : nCodePage == 1361 ? 4
			   : nCodePage == 936  ? 5
								   : 0;
	}

	static uint8_t MIFIndexFromCodePageId(code_page_id codePageId)
	{
		switch (codePageId)
		{
			case code_page_id::CODE_PAGE_DOS932:
			case code_page_id::CODE_PAGE_ANSI_932: return 1;
			case code_page_id::CODE_PAGE_BIG5:
			case code_page_id::CODE_PAGE_ANSI_950: return 2;
			case code_page_id::CODE_PAGE_KSC5601:
			case code_page_id::CODE_PAGE_ANSI_949: return 3;
			case code_page_id::CODE_PAGE_JOHAB:
			case code_page_id::CODE_PAGE_ANSI_1361: return 4;
			case code_page_id::CODE_PAGE_GB2312:
			case code_page_id::CODE_PAGE_ANSI_936: return 5;
			default: return 0;
		}
	}


	template<class ChType>
	static bool putMIF(wchar_t wch, ChType* pMbOut, unsigned nWinCodePage)
	{
		const unsigned char nMIFIndex = MIFIndexFromWinCodePage(nWinCodePage);
		if (nMIFIndex == 0)
			return false;
		ICARX_ASSERT(nMIFIndex >= 1);
		ICARX_ASSERT(nMIFIndex <= 5);
		char mbBuf[2];
		const int nMbChars = isNativeToCodePage(wch, nWinCodePage, mbBuf, 2);
		if (nMbChars == 0)
			return false;
		if (nMbChars == 1)
		{
			mbBuf[1] = mbBuf[0];
			mbBuf[0] = 0;
		}
		ICARX_ASSERT(nMbChars <= 2);
		pMbOut[0] = '\\';
		pMbOut[1] = 'M';
		pMbOut[2] = '+';
		pMbOut[3] = '0' + nMIFIndex;
		unsigned nNibs[4];
		nNibs[0] = mbBuf[0] >> 4;
		nNibs[1] = mbBuf[0];
		nNibs[2] = mbBuf[1] >> 4;
		nNibs[3] = mbBuf[1];
		for (int i = 0; i < 4; i++)
		{
			const ChType n = (ChType)(nNibs[i] & 0xf);
			pMbOut[4 + i] = (n <= 9) ? ('0' + n) : ('A' - 10 + n);
		}
		return true;
	}

	template<class ChType>
	static bool putMIF(wchar_t wch, ChType* pMbOut, code_page_id codePageId)
	{
		const auto nMIFIndex = MIFIndexFromCodePageId(codePageId);
		if (nMIFIndex == 0)
			return false;
		ICARX_ASSERT(nMIFIndex >= 1);
		ICARX_ASSERT(nMIFIndex <= 5);
		char mbBuf[2];
		const int nMbChars = isNativeToCodePageId(wch, codePageId, mbBuf, 2);
		if (nMbChars == 0)
			return false;
		if (nMbChars == 1)
		{
			mbBuf[1] = mbBuf[0];
			mbBuf[0] = 0;
		}
		ICARX_ASSERT(nMbChars <= 2);
		pMbOut[0] = '\\';
		pMbOut[1] = 'M';
		pMbOut[2] = '+';
		pMbOut[3] = '0' + nMIFIndex;
		unsigned nNibs[4];
		nNibs[0] = mbBuf[0] >> 4;
		nNibs[1] = mbBuf[0];
		nNibs[2] = mbBuf[1] >> 4;
		nNibs[3] = mbBuf[1];
		for (int i = 0; i < 4; i++)
		{
			const ChType n = (ChType)(nNibs[i] & 0xf);
			pMbOut[4 + i] = (n <= 9) ? ('0' + n) : ('A' - 10 + n);
		}
		return true;
	}

	template<class ChType>
	static unsigned getMIFCodePage(ChType ch)
	{
		return ch == '1'   ? 932
			   : ch == '2' ? 950
			   : ch == '3' ? 949
			   : ch == '4' ? 1361
			   : ch == '5' ? 936
						   : 0;
	}

	template<class ChType>
	static code_page_id getMIFCodePageId(ChType ch)
	{
		return ch == '1'   ? code_page_id::CODE_PAGE_DOS932
			   : ch == '2' ? code_page_id::CODE_PAGE_BIG5
			   : ch == '3' ? code_page_id::CODE_PAGE_KSC5601
			   : ch == '4' ? code_page_id::CODE_PAGE_JOHAB
			   : ch == '5' ? code_page_id::CODE_PAGE_GB2312
						   : code_page_id::CODE_PAGE_UNDEFINED;
	}

	template<class ChType>
	static bool parseMIF(const ChType* pSrcBuf, wchar_t& wch)
	{
		ICARX_ASSERT(pSrcBuf);
		if (!pSrcBuf)
			return false;

		if (pSrcBuf[0] != '\\' || (pSrcBuf[1] != 'M' && pSrcBuf[1] != 'm') || pSrcBuf[2] != '+')
			return false;

		const auto codePageId = getMIFCodePageId<ChType>(pSrcBuf[3]);
		if (code_page_id::CODE_PAGE_UNDEFINED == codePageId)
			return false;

		char mbBuf[2];
		unsigned uVal;
		if (!isHex<ChType>(pSrcBuf[4], uVal))
			return false;
		mbBuf[0] = (char)(uVal << 4);
		if (!isHex<ChType>(pSrcBuf[5], uVal))
			return false;
		mbBuf[0] |= (char)uVal;

		if (!isHex<ChType>(pSrcBuf[6], uVal))
			return false;
		mbBuf[1] = (char)(uVal << 4);
		if (!isHex<ChType>(pSrcBuf[7], uVal))
			return false;
		mbBuf[1] |= (char)(uVal);

		if (mbBuf[0] == 0)
		{
			mbBuf[0] = mbBuf[1];
			mbBuf[1] = 0;
		}

		extern bool convertMBStringToOneWideChar(code_page_id codePageId, char* mbBuf, int mbLen,
												 wchar_t& wch);
		return convertMBStringToOneWideChar(codePageId, mbBuf, mbBuf[1] == 0 ? 1 : 2, wch);
	}

	static ACBASE_PORT int isNativeToCodePage(wchar_t wch, unsigned nCodePage, char* pChNative,
											  int bufferLen);

	static ACBASE_PORT int isNativeToCodePageId(wchar_t wch, code_page_id codePageId,
												char* pChNative, int bufferLen);

	static ACBASE_PORT int wcharNonNativeToCIF(const wchar_t* szSrc, wchar_t* szDst,
											   size_t cchDstSize, bool b2byteCharToCIF = false);


	static int wcharFromCIFMIF(const wchar_t* szSrc, wchar_t* szDst, int cchDstSize)
	{
		ICARX_ASSERT(szSrc);
		ICARX_ASSERT(!szDst || cchDstSize > 0);
		ICARX_ASSERT(szDst || cchDstSize <= 0);
		if (!szSrc)
			return 0;
		if (szDst && cchDstSize <= 0)
			return 0;
		if (!szDst && cchDstSize > 0)
			return 0;

		int cchWritten = 0;
		const wchar_t* lpReadPtr = szSrc;
		wchar_t* lpWritePtr = szDst;
		wchar_t* lpWriteEnd = szDst + cchDstSize;

		if (!szDst && cchDstSize < 0)
		{
			lpWritePtr = const_cast<wchar_t*>(szSrc);
			lpWriteEnd = nullptr;
		}

		for (;;)
		{
			if (lpWritePtr && lpWriteEnd && lpWritePtr >= lpWriteEnd)
				break;

			const wchar_t wch = *lpReadPtr;
			wchar_t wchOut;
			if (parseCIF<wchar_t>(lpReadPtr, wchOut))
				lpReadPtr += 7;
			else if (parseMIF<wchar_t>(lpReadPtr, wchOut))
				lpReadPtr += 8;
			else
			{
				wchOut = wch;
				lpReadPtr++;
			}

			if (lpWritePtr)
				*lpWritePtr++ = wchOut;

			cchWritten++;
			if (wch == 0)
				break;
		}

		return cchWritten;
	}

	static int wcharNonNativeToRTF(code_page_id codePageId, const wchar_t* szSrc, int cchSrcLen,
								   char* szDst, int* pcbDstSize)
	{
		ICARX_ASSERT(szSrc);
		ICARX_ASSERT(pcbDstSize);
		ICARX_ASSERT(cchSrcLen >= -1);
		ICARX_ASSERT(cchSrcLen < 0x1000000);
		if (!szSrc || !pcbDstSize)
			return 0;
		if (cchSrcLen < -1)
			return 0;
		ICARX_ASSERT(!szDst || *pcbDstSize > 0);
		if (szDst && *pcbDstSize <= 0)
			return 0;

		int cbWritten = 0;
		int cchProcessed = 0;
		for (;;)
		{
			if (cchSrcLen >= 0)
			{
				ICARX_ASSERT(cchProcessed <= cchSrcLen);
				if (cchProcessed >= cchSrcLen)
					break;
			}
			char szAnsiBuf[2];
			const wchar_t wch = szSrc[cchProcessed];
			if (wch == L'\0')
			{
				if (cchSrcLen < 0)
					break;
			}
			const int cbAnsiSize = isNativeToCodePageId(wch, codePageId, szAnsiBuf, 2);

			ICARX_ASSERT(cbAnsiSize >= 0);
			ICARX_ASSERT(cbAnsiSize <= 2);
			if (cbAnsiSize > 0)
			{
				if (szDst)
				{
					if (cbWritten + cbAnsiSize >= *pcbDstSize)
						break;
					szDst[cbWritten] = szAnsiBuf[0];
					if (cbAnsiSize > 1)
						szDst[cbWritten + 1] = szAnsiBuf[1];
				}
				cbWritten += cbAnsiSize;
			}
			else
			{
				unsigned short nValue = wch;
				ICARX_ASSERT(nValue >= 128);
				int nDigits = 3;
				if (nValue < 1000)
					nDigits += 3;
				else if (nValue < 10000)
					nDigits += 4;
				else
					nDigits += 5;

				if (szDst)
				{
					if (cbWritten + nDigits >= *pcbDstSize)
						break;
					szDst[cbWritten + 0] = '\\';
					szDst[cbWritten + 1] = 'u';
					int i = cbWritten + nDigits - 1;
					szDst[i] = '?';
					do {
						ICARX_ASSERT(i > cbWritten + 1);
						i--;
						szDst[i] = (char)((nValue % 10) + '0');
						nValue /= 10;
					} while (nValue != 0);
					ICARX_ASSERT(i == cbWritten + 2);
				}
				cbWritten += nDigits;
			}
			cchProcessed++;
		}

		*pcbDstSize = cbWritten;
		if (cchSrcLen < 0)
		{
			if (szDst)
				szDst[cbWritten] = 0;
			*pcbDstSize = cbWritten + 1;
		}
		return cchProcessed;
	}

private:
	unsigned mnFormat;
	bool mbUseCIF;
	bool mbExpandLF;
};

#pragma warning(pop)

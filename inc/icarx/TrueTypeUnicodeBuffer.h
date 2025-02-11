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
***     Description: Declaration of TrueTypeUnicodeBuffer class
***
*****************************************************************************/
#pragma once

#include "../PAL/api/charset.h"
#include "../adesk.h"

#include <cwchar>

#include "IcArxAssert.h"

#include "IcArxPackPush.h"

class TrueTypeUnicodeBuffer
{
private:
	static const int m_kBufferLen = 256;

	bool m_bValid;
	wchar_t* m_pBuffer;
	int m_iLen;
	bool m_bDynamicBuffer;
	wchar_t m_sBuffer[m_kBufferLen];

public:
	TrueTypeUnicodeBuffer(const wchar_t* text, int length, bool raw, Charset charset)
			: m_bValid(true), m_bDynamicBuffer(false)
	{
		(void)(charset);
		if (length < -1)
		{
			m_iLen = -length - 1;
			m_pBuffer = (wchar_t*)text;
			return;
		}
		if (length != -1)
			m_iLen = length;
		else
		{
			const size_t nLen = ::wcslen(text);
			ICARX_ASSERT(nLen < 0x7FFFFFFE);
			ICARX_ASSERT(nLen == (int)nLen);
			m_iLen = (int)nLen;
		}
		if (!raw)
		{
			size_t nSize;
			if (m_iLen + 1 > m_kBufferLen)
			{
				m_bDynamicBuffer = true;
				m_pBuffer = new wchar_t[m_iLen + 1];
				nSize = m_iLen + 1;
				if (!m_pBuffer)
				{
					m_bValid = false;
					return;
				}
			}
			else
			{
				m_pBuffer = m_sBuffer;
				nSize = m_kBufferLen;
			}
			wcsncpy_s(m_pBuffer, nSize, text, m_iLen);
			m_pBuffer[m_iLen] = 0;
		}
		else
		{
			m_pBuffer = const_cast<wchar_t*>(text);
		}
	}
	~TrueTypeUnicodeBuffer()
	{
		if (m_bDynamicBuffer)
			delete[] m_pBuffer;
	}

	wchar_t* buf() const { return m_pBuffer; }
	int len() const { return m_iLen; }
	bool valid() const { return m_bValid; }
};

#include "IcArxPackPop.h"

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
***     Description: Declaration of AcTrayItemAnimationControl class
***
*****************************************************************************/
#pragma once

using AcTrayItemAnimationCallbackFunc = void (*)(void*, int);
using AcTrayItemAnimationCallbackData = void*;

#include "IcArxPackPush.h"

class AcTrayItemAnimationControl
{
public:
	enum
	{
		ANIMATION_ERROR_NO_CREATE,
		ANIMATION_ERROR_NO_ICONS,
		ANIMATION_KILLED,
		ANIMATION_FINISHED,
	};

private:
	HBITMAP m_hBitmap;
	HGLOBAL m_hGifGlobal;
	DWORD m_dwGifSize;
	CString m_strGIFFile;
	int m_nDurationInSeconds;
	HICON m_hNewIcon;
	AcTrayItemAnimationCallbackFunc m_pCallbackFunc;
	AcTrayItemAnimationCallbackData m_pCallbackData;

private:
	void InitDefault()
	{
		m_pCallbackFunc = 0;
		m_pCallbackData = 0;
		m_nDurationInSeconds = 5;
		m_hNewIcon = 0;
	}

public:
	AcTrayItemAnimationControl();
	AcTrayItemAnimationControl(const CString& strGIFFile);
	AcTrayItemAnimationControl(HBITMAP hBitmap);
	~AcTrayItemAnimationControl();

	HBITMAP GetBitmap() const { return m_hBitmap; };
	AcTrayItemAnimationCallbackData GetCallbackData() const
	{
		return m_pCallbackData;
	}
	AcTrayItemAnimationCallbackFunc GetCallbackFunc() const
	{
		return m_pCallbackFunc;
	}
	int GetDuration() const { return m_nDurationInSeconds; }
	const CString& GetGIFFile() const { return m_strGIFFile; };
	void GetGIFResourceData(HGLOBAL& hGlobal, DWORD& dwSize) const
	{
		hGlobal = m_hGifGlobal;
		dwSize = m_dwGifSize;
	};
	HICON GetNewIcon() const { return m_hNewIcon; };
	void SetBitmap(HBITMAP hBitmap) { m_hBitmap = hBitmap; }
	void SetCallback(AcTrayItemAnimationCallbackFunc pCallbackFunc,
								   AcTrayItemAnimationCallbackData pCallbackData)
	{
		m_pCallbackFunc = pCallbackFunc;
		m_pCallbackData = pCallbackData;
	}
	void SetDuration(int nDurationInSeconds)
	{
		m_nDurationInSeconds = nDurationInSeconds;
	}
	void SetGIFFile(const CString& strGIFFile) { m_strGIFFile = strGIFFile; }
	void SetGIFResourceData(HGLOBAL hGlobal, DWORD dwSize)
	{
		m_hGifGlobal = hGlobal;
		m_dwGifSize = dwSize;
	};
	void SetNewIcon(HICON hNewIcon) { m_hNewIcon = hNewIcon; }
};

#include "IcArxPackPop.h"

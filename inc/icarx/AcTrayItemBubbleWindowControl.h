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
***     Description: Declaration of AcTrayItemBubbleWindowControl class
***
*****************************************************************************/
#pragma once

#include "../AdAChar.h"

#ifndef ACAD_PORT
#	define ACAD_PORT
#endif

using AcTrayItemBubbleWindowCallbackFunc = void (*)(void*, int);
using AcTrayItemBubbleWindowCallbackData = void*;

#include "IcArxPackPush.h"

class AcTrayItemBubbleWindowControl
{
public:
	enum
	{
		BUBBLE_WINDOW_ICON_NONE,
		BUBBLE_WINDOW_ICON_INFORMATION,
		BUBBLE_WINDOW_ICON_CRITICAL,
		BUBBLE_WINDOW_ICON_WARNING,
	};

	enum
	{
		BUBBLE_WINDOW_ERROR_NO_CREATE,
		BUBBLE_WINDOW_ERROR_NO_ICONS,
		BUBBLE_WINDOW_ERROR_NO_NOTIFICATIONS,
		BUBBLE_WINDOW_CLOSE,
		BUBBLE_WINDOW_TIME_OUT,
		BUBBLE_WINDOW_HYPERLINK_CLICK,
		BUBBLE_WINDOW_HYPERLINK_CLICK_CHECKED,
		BUBBLE_WINDOW_DOCUMENT_DEACTIVATED
	};

private:
	int m_nIconType;
	CString m_strTitle;
	CString m_strText;
	CString m_strHyperText;
	CString m_strHyperLink;
	CString m_strText2;
	CString m_strCheckboxText;
	bool m_bIsChecked;
	AcTrayItemBubbleWindowCallbackFunc m_pCallbackFunc;
	AcTrayItemBubbleWindowCallbackData m_pCallbackData;

private:
	void InitDefault()
	{
		m_pCallbackFunc = 0;
		m_pCallbackData = 0;
		m_nIconType = BUBBLE_WINDOW_ICON_INFORMATION;
	}

public:
	AcTrayItemBubbleWindowControl();
	ACAD_PORT AcTrayItemBubbleWindowControl(const CString& strTitle, const CString& strText,
											const CString& strHyperText = ACRX_T(""),
											const CString& strHyperLink = ACRX_T(""),
											const CString& strText2 = ACRX_T(""),
											const CString& strCheckboxText = ACRX_T(""),
											bool bIsChecked = false);
	~AcTrayItemBubbleWindowControl();

	AcTrayItemBubbleWindowCallbackData GetCallbackData() const { return m_pCallbackData; }
	AcTrayItemBubbleWindowCallbackFunc GetCallbackFunc() const { return m_pCallbackFunc; }
	const CString& GetCheckboxText() const { return m_strCheckboxText; }
	const CString& GetHyperLink() const { return m_strHyperLink; }
	const CString& GetHyperText() const { return m_strHyperText; }
	int GetIconType() const { return m_nIconType; };
	const bool GetIsChecked() const { return m_bIsChecked; }
	const CString& GetText() const { return m_strText; }
	const CString& GetText2() const { return m_strText2; }
	const CString& GetTitle() const { return m_strTitle; }
	void SetCallback(AcTrayItemBubbleWindowCallbackFunc pCallbackFunc,
					 AcTrayItemBubbleWindowCallbackData pCallbackData = 0)
	{
		m_pCallbackFunc = pCallbackFunc;
		m_pCallbackData = pCallbackData;
	}
	void SetCheckboxText(const CString& strText) { m_strCheckboxText = strText; }
	void SetHyperLink(const CString& strHyperLink) { m_strHyperLink = strHyperLink; }
	void SetHyperText(const CString& strHyperText) { m_strHyperText = strHyperText; }
	void SetIconType(int nIconType) { m_nIconType = nIconType; }
	void SetIsChecked(bool bNewVal) { m_bIsChecked = bNewVal; }
	void SetText(const CString& strText) { m_strText = strText; }
	void SetText2(const CString& strText2) { m_strText2 = strText2; }
	void SetTitle(const CString& strTitle) { m_strTitle = strTitle; }
};

#include "IcArxPackPop.h"

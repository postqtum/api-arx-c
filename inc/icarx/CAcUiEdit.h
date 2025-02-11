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
***     Description: Declaration of CAcUiEdit class
***
*****************************************************************************/
#pragma once

#include "../acui_port.h"
#include "CAdUiEdit.h"

enum ACUI_ERROR_CODE
{
	kAcUiError_None,
	kAcUiError_Blank,
	kAcUiError_Symbol,
	kAcUiError_Numeric,
	kAcUiError_Angle,
	kAcUiError_Zero,
	kAcUiError_Negative,
	kAcUiError_Range
};

#include "IcArxPackPush.h"

class ACUI_PORT CAcUiEdit : public CAdUiEdit
{
	DECLARE_DYNAMIC(CAcUiEdit)

public:
	CAcUiEdit();
	~CAcUiEdit();

private:
	BOOL m_bWantsFocus;
	BOOL m_bWasValid;

protected:
	ADUI_REPLY DoAdUiMessage(ADUI_NOTIFY notifyCode, UINT controlId, LPARAM lParam) override;

public:
	void SetStyleMask(DWORD mask) override;

private:
	void DisplayError(UINT);

public:
	BOOL m_bChanged;
	double m_dMinValue;
	double m_dMaxValue;
	CString m_csMsg;
	BOOL m_bTouch;

	void Convert();
	BOOL ConvertData(CString& x);
	BOOL HasChanged();
	void SetDirty();
	void SetRange(double vMin, double vMax);
	BOOL Validate();
	ACUI_ERROR_CODE ValidateData(CString& x);

protected:
	afx_msg BOOL OnChange();
	afx_msg void OnErrSpace();
	afx_msg void OnKillFocus(CWnd* pNewWnd);

	DECLARE_MESSAGE_MAP()
};

#include "IcArxPackPop.h"

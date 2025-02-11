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
***     Description: Declaration of CAcFdUiFormatDialog class
***
*****************************************************************************/
#pragma once

#include "adui.h"
#include "AcFdUi.h"
#include "AcValue.h"

class AcTcUiSystemInternals;
class CAcFdUiFormatList;

#define ACFDUI_UM_FORMAT_CHANGED (WM_APP + 100)
#define ACFDUI_UM_BEGIN_FORMATEX_DIALOG (WM_APP + 101)
#define ACFDUI_UM_END_FORMATEX_DIALOG (WM_APP + 102)

#define ACFDUI_FDSTYLE_SIMPLE (0x1 << 1)
#define ACFDUI_FDSTYLE_FILENAME (0x1 << 2)
#define ACFDUI_FDSTYLE_DOUBLE (0x1 << 3)
#define ACFDUI_FDSTYLE_DOUBLE_POINT (0x1 << 4)
#define ACFDUI_FDSTYLE_ALL (0x1 << 5)

class ACFDUI_PORT CAcFdUiFormatDialog : public CAdUiDialog
{
	DECLARE_DYNAMIC(CAcFdUiFormatDialog)
protected:
	void* mpImpObj = nullptr;

private:
	friend class AcFdUiSystemInternals;

protected:
	void DoDataExchange(CDataExchange* pDX);

	afx_msg void OnBnClickedAppendSymbol();
	afx_msg void OnBnClickedFilenameOnly();
	afx_msg void OnBnClickedFormatEx();
	afx_msg void OnBnClickedIncludeExtension();
	afx_msg void OnBnClickedPathAndFilename();
	afx_msg void OnBnClickedPathOnly();
	afx_msg void OnBnClickedPointX();
	afx_msg void OnBnClickedPointY();
	afx_msg void OnBnClickedPointZ();
	afx_msg void OnCbnEditChangeListSeparator();
	afx_msg void OnCbnSelChangeCurrencySymbol();
	afx_msg void OnCbnSelChangeDecimalSeparator();
	afx_msg void OnCbnSelChangeListSeparator();
	afx_msg void OnCbnSelChangePrecision();
	afx_msg void OnDestroy();
	afx_msg void OnEnChangePreview();
	afx_msg void OnLbnSelChangeFormatList();
	afx_msg void OnLbnSelChangeNegativeNumberList();

	DECLARE_MESSAGE_MAP()

public:
	CAcFdUiFormatDialog(CWnd* pParent, BOOL bNew);
	~CAcFdUiFormatDialog();
	virtual BOOL Create(CWnd* pParent);
	int GetCurrentFormat(CString& sDisplayName, CString& sFormatString, CString& sVersion) const;
	CAcFdUiFormatList* GetFormatList();
	CString GetFormatType() const;
	BOOL SetCurrentFormat(LPCTSTR pszDisplayName, LPCTSTR pszFormatString);
	BOOL SetDialogStyle(int nStyle);
	BOOL SetFormatPreviewLabel(LPCTSTR pszText);
	BOOL SetFormatPreviewReadOnly(BOOL bReadOnly = 1);
	BOOL SetFormatPreviewText(LPCTSTR pszPreviewText, const AcValue& fieldValue);
	BOOL SetFormatType(LPCTSTR pszFormatType);
};

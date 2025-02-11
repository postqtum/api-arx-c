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

#include "AdUi.h"
#include "AcFdUi.h"

class AcTcUiSystemInternals;
class CAcFdUiFieldDialog;
class CAcFdUiFieldDialogHook;
class CAcFdUiImpFieldDialog;
class AcDbField;

class ACFDUI_PORT CAcFdUiFieldOptionDialog : public CAdUiDialog
{
	friend CAcFdUiFieldDialog;
	friend CAcFdUiImpFieldDialog;

	DECLARE_DYNAMIC(CAcFdUiFieldOptionDialog)

protected:
	void* mpImpObj;

private:
	friend class AcFdUiSystemInternals;

protected:
	void DoDataExchange(CDataExchange* pDX);
	void OnCancel();
	virtual BOOL OnFieldSelected(UINT uNewFieldId);
	virtual BOOL OnKillActive();
	void OnOK();
	virtual BOOL OnSetActive();

	afx_msg LRESULT OnBeginFormatExDialog(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnEndFormatExDialog(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnFormatChanged(WPARAM wParam, LPARAM lParam);

	DECLARE_MESSAGE_MAP()


public:
	CAcFdUiFieldOptionDialog(CAcFdUiFieldDialogHook* pDialogHook, CAcFdUiFieldDialog* pFieldDlg,
							 UINT nIDTemplate, HINSTANCE hDialogResource = nullptr);
	~CAcFdUiFieldOptionDialog() throw();
	virtual BOOL Create(CWnd* pParent);
	virtual BOOL Create(LPCTSTR lpszTemplateName, CWnd* pParent = nullptr);
	virtual BOOL Create(UINT nIDTemplate, CWnd* pParent = nullptr);
	CAcFdUiFieldDialog* GetFieldDialog() const;
	CAcFdUiFieldDialogHook* GetFieldDialogHook() const;
};

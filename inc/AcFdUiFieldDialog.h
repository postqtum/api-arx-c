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
***     Description: Declaration of CAcFdUiFieldDialog class
***
*****************************************************************************/
#pragma once

#include "adui.h"
#include "AcFdUi.h"
#include "acui.h"

class AcFdUiSystemInternals;
class CAcFdUiFieldOptionDialog;
class CAcFdUiImpFieldDialog;

#define ACFDUI_FD_CREATE_FIELD 1
#define ACFDUI_FD_EDIT_FIELD 2

class ACFDUI_PORT CAcFdUiFieldDialog : public CAcUiDialog
{
	friend CAcFdUiImpFieldDialog;

	DECLARE_DYNAMIC(CAcFdUiFieldDialog)

protected:
	void* mpImpObj = nullptr;

private:
	friend class AcFdUiSystemInternals;

protected:
	void DoDataExchange(CDataExchange* pDX);
	DECLARE_MESSAGE_MAP()

	void OnOK();
	void OnCancel();
	BOOL OnInitDialog();

	afx_msg LRESULT OnBeginFormatExDialog(WPARAM wParam, LPARAM lParam);
	afx_msg void OnCbnSelChangeCategoryList();
	afx_msg void OnDialogHelp();
	afx_msg void OnEnChangeFieldCode();
	afx_msg LRESULT OnEndFormatExDialog(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnFormatChanged(WPARAM wParam, LPARAM lParam);
	afx_msg void OnLbnSelChangeFieldNameList();

public:
	CAcFdUiFieldDialog(CWnd* pParent = nullptr);
	~CAcFdUiFieldDialog();
	void BeginEditorCommand();
	void CancelEditorCommand();
	void CompleteEditorCommand(BOOL restoreDialogs = 1);
	INT_PTR DoModal(AcDbField * &pField, BOOL bEdit, AcDbDatabase * pDb);
	BOOL GetCurrentField(UINT * pFieldId, UINT * pCatId) const;
	CString GetFieldCode() const;
	CEdit* GetFieldCodeEditCtrl();
	AcDbField* GetFieldToEdit() const;
	CAcFdUiFieldOptionDialog* GetOptionDialog() const;
	BOOL IsFieldCodeDirty();
	BOOL SelectField(UINT uFieldId, UINT uCatId);
	BOOL SetFieldCode(LPCTSTR pszExpr);
	BOOL SetFieldCodeReadOnly(BOOL bReadOnly = 1);
};

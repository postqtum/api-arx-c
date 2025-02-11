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
***     Description: Declaration of CAcFdUiFieldDialogHook class
***
*****************************************************************************/
#pragma once

#include "AcFdUi.h"
#include "DbField.h"
#include <afxtempl.h>

class AcTcUiSystemInternals;
class CAcFdUiFieldDialog;
class CAcFdUiFieldOptionDialog;
class CAcFdUiImpFieldDialog;
class CAcFdUiFieldDialogHook;

typedef CTypedPtrArray<CPtrArray, CAcFdUiFieldDialogHook*> AcFdUiFieldDialogHookArray;

class ACFDUI_PORT CAcFdUiFieldDialogHook : public CObject
{
protected:
	void* mpImpObj = nullptr;

private:
	friend class AcFdUiSystemInternals;

public:
	CAcFdUiFieldDialogHook();
	~CAcFdUiFieldDialogHook() noexcept;
	virtual BOOL BeginFieldDialog(CAcFdUiFieldDialog* pFieldDlg, AcDbDatabase* pDb, int nContext);
	virtual BOOL CreateField(UINT uFieldId, AcDbField*& pField);
	virtual BOOL CreateInstance(CAcFdUiFieldDialogHook*& pHook);
	virtual BOOL EndFieldDialog(int nRet);
	virtual BOOL GetCategoryNames(UINT uMinUnusedCatId, CStringArray& catNames, CUIntArray& catIds);
	AcDbDatabase* GetDatabase() const;
	virtual int GetEvaluatorIds(CStringArray& evalIds);
	virtual BOOL GetFieldNames(UINT uCatId, UINT uMinUnusedFieldId, CStringArray& fieldNames,
							   CUIntArray& fieldIds, BOOL& bSort);
	virtual BOOL GetOptionDialog(UINT uFieldId, CAcFdUiFieldOptionDialog*& pOptionDlg);
	virtual CString GetPreview(LPCTSTR pszFormatType, LPCTSTR pszFormat);
	virtual BOOL OnFieldSelected(UINT uFieldId);
	virtual BOOL SetFieldToEdit(AcDbField* pField);
	virtual BOOL UpdateFieldCode();
};

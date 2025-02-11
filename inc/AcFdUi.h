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
***     Description: AcFdUi common declarations
***
*****************************************************************************/
#pragma once

#ifdef ACFD_API
#	define ACFDUI_PORT __declspec(dllexport)
#else
#	define ACFDUI_PORT
#endif

#include <afxwin.h>

class CAcFdUiFieldManager;
class AcDbField;
class AcDbDatabase;

#define ACFDUI_CATEGORY_ID_ALL -1

#define ACFDUI_CATID_USER_FIRST 1000

#define ACFDUI_FIELDID_USER_FIRST 50000

ACFDUI_PORT CAcFdUiFieldManager* AcFdUiGetFieldManager(void);
ACFDUI_PORT int AcFdUiInvokeFieldDialog(AcDbField*& pNewField, BOOL bEdit, AcDbDatabase* pDb,
										CWnd* pParent = nullptr);

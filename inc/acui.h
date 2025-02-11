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

#include "acui_port.h"

ACUI_PORT void InitAcUiDLL();

ACUI_PORT HINSTANCE AcUiAppResourceInstance();
ACUI_PORT HINSTANCE AcUiAppBrandingResourceInstance();

ACUI_PORT LPCTSTR AcUiContextHelpFileName();

#ifndef kDialogOptionUseTipsForContextHelp
#	define kDialogOptionUseTipsForContextHelp 2
#endif

inline unsigned int AcUiEnableToolTips()
{
	return kDialogOptionUseTipsForContextHelp;
}

ACUI_PORT bool AcUiFindContextHelpFullPath(LPCTSTR fileName, CString& fullPath);
ACUI_PORT bool AcUiIsInputPending();
ACUI_PORT CWnd* AcUiMainWindow();
ACUI_PORT void AcUiRootKey(CString& rootKey);


typedef CAdUiRegistryAccess CAcUiRegistryAccess;
typedef CAdUiRegistryDeleteAccess CAcUiRegistryDeleteAccess;
typedef CAdUiRegistryWriteAccess CAcUiRegistryWriteAccess;


#include "acuiButton.h"
#include "acuiDialogWorksheet.h"
#include "acuiDialog.h"
#include "acuiTabCtrl.h"

typedef CAcUiTabChildDialog CAcUiTabExtension;

#include "aced.h"

#include "acuiDock.h"
#include "acuiEdit.h"
#include "acuiHeaderCtrl.h"
#include "acuiListBox.h"
#include "acuiListCtrl.h"
#include "acuiComboBox.h"
#include "acuiPathname.h"
#include "acuiNavDialog.h"

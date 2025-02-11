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
***     Description: Common definitions for AdUi
***
*****************************************************************************/
#pragma once

#include <afxwin.h>

#include "adui_port.h"

class ADUI_PORT CAdUiThemeManager;


void ADUI_PORT InitAdUiDLL();

int ADUI_PORT AdUiAlertDialog(LPCTSTR captionText, LPCTSTR msg0Text, LPCTSTR button0Text,
							  LPCTSTR button1Text, UINT defButton = 0);

int ADUI_PORT AdUiDataValidationLevel();

BOOL ADUI_PORT AdUiFindContextHelpFullPath(LPCTSTR fileName, CString& fullPath);

void ADUI_PORT AdUiSubstituteShellFont(CWnd& dlg, CFont& font);
CAdUiThemeManager ADUI_PORT* AdUiGetThemeManager();

HWND ADUI_PORT AdUiGetSafeParentHwnd();
ADUI_PORT CWnd* AdUiGetSafeParentWnd();

bool ADUI_PORT AdUiSetDockBarMinWidth(int width);


class ADUI_PORT CAdUiBaseDialog;
class ADUI_PORT CAdUiComboBox;
class ADUI_PORT CAdUiDialog;
class ADUI_PORT CAdUiDialogBar;
class ADUI_PORT CAdUiFileDialog;
class ADUI_PORT CAdUiTab;
class ADUI_PORT CAdUiTabChildDialog;
class ADUI_PORT CAdUiTabExtensionManager;
class ADUI_PORT CAdUiTabMainDialog;
class ADUI_PORT CAdUiDialogWorksheet;
class ADUI_PORT CAdUiDropTarget;
class ADUI_PORT CAdUiTheme;
class ADUI_PORT CAdUiPalette;
class ADUI_PORT CAdUiPaletteSet;
class ADUI_PORT CAdUiThemeMgrReactor;
class ADUI_PORT CAduiLabelEdit;


#define MOVEX 0x00001
#define MOVEY 0x00002
#define MOVEXY 0x00003
#define ELASTICX 0x00010
#define ELASTICY 0x00020
#define ELASTICXY 0x00030

#pragma pack(push, 8)
typedef struct _dlgControlTag
{
	DWORD id;
	DWORD flags;
	DWORD pct;
} DLGCTLINFO, *PDLGCTLINFO;
#pragma pack(pop)


namespace AdUi
{

enum AdUiIconMode
{
	kSmall = 0,
	kLarge
};

enum AdUiImage
{
	kImageSmall = 1,
	kImageLarge = 2,

	kImageEnable = 4,
	kImageDisable = 8,
};

};	// namespace AdUi

#include <winreg.h>

#include <afxole.h>

#include "aduiRegistryAccess.h"

#include "aduiMessage.h"
#include "aduiDropTarget.h"
#include "aduiTabExtension.h"
#include "aduiTextTip.h"

#include "aduiButton.h"
#include "aduiTabCtrl.h"
#include "aduiRichEditCtrl.h"

#include "aduiBaseDialog.h"
#include "aduiDialog.h"
#include "aduiDialogBar.h"
#include "aduiFileDialog.h"
#include "aduiTabChildDialog.h"
#include "aduiTabMainDialog.h"

#include "aduiEdit.h"
#include "aduiHeaderCtrl.h"
#include "aduiListBox.h"
#include "aduiListCtrl.h"
#include "aduiComboBox.h"

#include "aduiDock.h"

#include "aduiPathname.h"
#include "aduiPalette.h"
#include "aduiPaletteSet.h"

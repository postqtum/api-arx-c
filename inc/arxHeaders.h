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

#include "dbxHeaders.h"

//-----------------------------------------------------------------------------
#include "icarx/IcArxPackPush.h"
#pragma warning(disable : 4312 4275)

//-----------------------------------------------------------------------------
//#pragma comment (lib ,"acad.lib")
//#pragma comment (lib ,"accore.lib")
#ifdef _AFXEXT
//#pragma comment (lib ,"acui24.lib")
//#pragma comment (lib ,"adui24.lib")
//#pragma comment (lib ,"aNav.lib")
//#pragma comment (lib ,"AcTc.lib")
//#pragma comment (lib ,"AcTcUi.lib")
//#pragma comment (lib ,"AcFdUi.lib")
#endif	// #ifdef _AFXEXT
//#pragma comment (lib ,"AcFdEval.lib")
#ifdef _RENDER_SUPPORT_
//#pragma comment (lib, "avlib.lib")
#endif	// _RENDER_SUPPORT_
#ifdef _ASE_SUPPORT_
#	ifndef AC_FULL_DEBUG
//#pragma comment (lib ,"aseapi24.lib")
//#pragma comment (lib ,"asiapi24.lib")
#	else
//#pragma comment (lib ,"aseapi24d.lib")
//#pragma comment (lib ,"asiapi24d.lib")
#	endif
//#pragma comment (lib ,"userdata.lib")
#endif	// _ASE_SUPPORT_

#include "accmd.h"
#include "aced.h"
#include "acdocman.h"
#include "actrans.h"
#include "acedsel.h"
#include "acedxref.h"
#include "lngtrans.h"
#include "dbltrans.h"
#include "AcApLMgr.h"
#include "acedinet.h"
#include "acedinpt.h"
#include "AcDblClkEdit.h"
#include "AcGradThumbEng.h"
//#include "subselect.h"

#include "dbjig.h"
#include "dbmatch.h"
#include "dbInterferencePE.h"
#include "dbosnap.h"

#include "clipdata.h"

#ifdef _AFXEXT
#	include "gs.h"
#endif	// _AFXEXT
#include "AcGsManager.h"

#include "AcPl.h"
#include "AcPlDSDData.h"
#include "AcPlDSDEntry.h"
#include "AcPlHostAppServices.h"
#include "AcPlObject.h"
#include "AcPlPlotConfig.h"
#include "AcPlPlotConfigMgr.h"
#include "AcPlPlotEngine.h"
#include "AcPlPlotErrorHandler.h"
#include "AcPlPlotErrorHandlerLock.h"
#include "AcPlPlotFactory.h"
#include "AcPlPlotInfo.h"
#include "AcPlPlotInfoValidator.h"
#include "AcPlPlotLogger.h"
#include "AcPlPlotLoggingErrorHandler.h"
#include "AcPlPlotProgress.h"
#include "acplplotreactor.h"
#include "acplplotreactormgr.h"

#include "acpublishreactors.h"
#include "acpublishuireactors.h"

#include "acdmmapi.h"
#include "acdmmeplotproperties.h"
#include "acdmmeplotproperty.h"
#include "acdmmutils.h"

#ifdef _AFXEXT

#	pragma warning(disable : 4275)
#	include "adui.h"
#	include "AcExtensionModule.h"
#	include "aduiBaseDialog.h"
#	include "aduiButton.h"
#	include "aduiComboBox.h"
#	include "aduiDialog.h"
#	include "aduiDialogBar.h"
#	include "aduiDialogWorksheet.h"
#	include "aduiDock.h"
#	include "aduiDropTarget.h"
#	include "aduiEdit.h"
#	include "aduiFileDialog.h"
#	include "aduiHeaderCtrl.h"
#	include "aduiListBox.h"
#	include "aduiListCtrl.h"
#	include "aduiMessage.h"
#	include "aduiPalette.h"
#	include "aduiPaletteSet.h"
#	include "aduiPathname.h"
#	include "aduiRegistryAccess.h"
#	include "aduiTabChildDialog.h"
#	include "aduiTabCtrl.h"
#	include "aduiTabExtension.h"
#	include "aduiTabMainDialog.h"
#	include "aduiTextTip.h"
#	include "aduiTheme.h"
#	include "aduiThemeManager.h"
#	include "aduiCoupledGroupCtrl.h"
#	include "aduiGroupCtrl.h"
#	include "aduipathenums.h"

#	include "acui.h"
#	include "rxmfcapi.h"
#	include "AcStatusBar.h"
#	include "acuiButton.h"
#	include "acuiComboBox.h"
#	include "acuiDialog.h"
#	include "acuiDialogWorksheet.h"
#	include "acuidock.h"
#	include "acuiEdit.h"
#	include "acuiHeaderCtrl.h"
#	include "acuiListBox.h"
#	include "acuiListCtrl.h"
#	include "acuiNavDialog.h"
#	include "acuiPathname.h"
#	include "acuiTabCtrl.h"

#	include "aNav.h"
#	include "aNavArray.h"
#	include "aNavData.h"
#	include "aNavDataArray.h"
#	include "aNavDialog.h"
#	include "aNavFilter.h"
#	include "aNavFilterArray.h"
#	include "aNavListCtrl.h"

#	include "AcTc.h"
#	include "AcTcUiManager.h"
#	include "AcTcUI.h"
#	include "AcTcUiCatalogView.h"
#	include "AcTcUiCatalogViewItem.h"
#	include "AcTcUiPaletteView.h"
#	include "AcTcUiToolPalette.h"
#	include "AcTcUiToolPaletteSet.h"
#	include "AcTcUiToolPaletteGroup.h"
#	include "AcTcUiScheme.h"
#	include "AcTc_i.h"
#	include "dcdispid.h"

#	include "AcFdUi.h"
#	include "AcFdUiFieldDialog.h"
#	include "AcFdUiFieldDialogHook.h"
#	include "AcFdUiFieldFormatDialog.h"
#	include "AcFdUiFieldFormatList.h"
#	include "AcFdUiFieldManager.h"
#	include "AcFdUiFieldOptionDialog.h"
#	include "AcFdUtil.h"

#endif	// _AFXEXT

#include "adsdlg.h"
#include "adsrxdef.h"
#include "adslib.h"

#include "acssgetfilter.h"
#include "acutasrt.h"
#include "arxEntryPoint.h"
#include "AcApDMgr.h"
#include "acprofile.h"

#ifdef __ATLCOM_H__
#	include "dynpropmgr.h"
#endif	// __ATLCOM_H__

#ifdef _INC_LEAGACY_HEADERS_
#	include "ol_errno.h"
#endif	// _INC_LEAGACY_HEADERS_

#ifdef _ASE_SUPPORT_
#	include "asisys.h"
#	include "asiappl.h"
#	include "csptypes.h"
#	include "avoidtry.h"
#	include "asiucode.h"
#	include "asiconst.h"
#	include "asisdata.h"
#	include "asiclass.h"
#	include "aseconst.h"
#	include "aseclass.h"
#endif	// _ASE_SUPPORT_

#ifdef _RENDER_SUPPORT_
#	include "averror.h"
#	include "avlib.h"
#endif	// _RENDER_SUPPORT_

#include "icarx/IcArxPackPop.h"

/***************************************************************************
***
***     Copyright (C) 2023 IntelliCAD Technology Consortium. All Rights Reserved.
***
***     Use of the information contained herein, in part or in whole,
***     in/as source code and/or in/as object code, in any way by anyone
***     other than authorized employees of The IntelliCAD Technology Consortium,
***     or by anyone to whom The IntelliCAD Technology Consortium  has not
***     granted use is illegal.
***
***     Description: Example of CAcUiMRUComboBox usage
***
*****************************************************************************/
#include "stdafx.h"

#include <inc/arxEntryPoint.h>
#include <inc/aduiFileDialog.h>
#include <inc/rxmfcapi.h>

#include "CAcUiMRUComboBoxDialogTest.h"
#include "CAdUiImageDialogTest.h"
#include "MyCAdUiDockControlBarTest.h"

static std::unique_ptr<MyCAdUiDockControlBar> g_dockBar;
static std::unique_ptr<CFrameWnd> g_pMainFrame;

class ComboBoxApp : public AcRxArxApp
{
public:
	ComboBoxApp() = default;

	static void IcadSampleTestComboBoxApp()
	{
		CAcUiMRUComboBoxDialogTest dlg;
		dlg.DoModal();

		CAdUiImageDialogTest dlg1;
		dlg1.DoModal();

		CAdUiFileDialog dlg2(FALSE, L"txt");
		dlg2.DoModal();

		g_pMainFrame = std::make_unique<CFrameWnd>();
		g_pMainFrame->Create(
		        AfxRegisterWndClass(CS_DBLCLKS | CS_VREDRAW | CS_HREDRAW, NULL, NULL, NULL),
		        L"TestWindow");
		g_pMainFrame->EnableDocking(CBRS_ALIGN_ANY);
		g_pMainFrame->ShowWindow(SW_SHOW);

		g_dockBar = std::make_unique<MyCAdUiDockControlBar>();
		g_dockBar->Create(g_pMainFrame.get(), L"MyDockBar", 0, WS_CHILD | WS_VISIBLE | CBRS_BOTTOM,
		        CRect(0, 0, 500, 500));
		g_dockBar->EnableDocking(CBRS_ALIGN_ANY);
		g_dockBar->SetWindowText(_T("MyDockBar"));
		g_dockBar->ShowWindow(SW_SHOW);
	}

private:
	void RegisterServerComponents(void) override {}
};

IMPLEMENT_ARX_ENTRYPOINT(ComboBoxApp)
ACED_ARXCOMMAND_ENTRY_AUTO(ComboBoxApp, IcadSample, TestComboBoxApp, TestComboBoxApp, ACRX_CMD_TRANSPARENT, NULL)

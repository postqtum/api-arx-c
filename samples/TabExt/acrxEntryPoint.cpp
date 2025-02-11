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
***     Description: Entry point
***
*****************************************************************************/
#include "StdAfx.h"

#include <filesystem>

#include <inc/rxmfcapi.h>

#include "resource.h"

#include "MyTabChildDialog.h"

static const std::filesystem::path getMyModulePath()
{
	static const std::filesystem::path result = []() {
		std::filesystem::path result;
			DWORD size{};
			std::unique_ptr<wchar_t[]> buffer;
			do {
				size += MAX_PATH;
				buffer = std::make_unique<wchar_t[]>(size);
			} while (GetModuleFileName(TabExtDLL.ModuleResourceInstance(), buffer.get(), size) == size);
			if (buffer)
			{
				result = buffer.get();
			}
		return result;
	}();
	return result;
}

class CTabExtApp : public AcRxArxApp
{

public:
	CTabExtApp()
	    : AcRxArxApp()
	{
	}

	virtual AcRx::AppRetCode On_kInitAppMsg(void* pkt)
	{
		auto retCode = AcRxArxApp::On_kInitAppMsg(pkt);

		auto moduleName = getMyModulePath().filename();

		// Let the host application know this ARX may want to extend some dialogs
		acedRegisterExtendedTab(moduleName.c_str(), ACRX_T("CustomizeDialog"));
		acedRegisterExtendedTab(moduleName.c_str(), ACRX_T("DrawingSettingsDialog"));
		acedRegisterExtendedTab(moduleName.c_str(), ACRX_T("OptionsDialog"));

		return (retCode);
	}

	virtual AcRx::AppRetCode On_kUnloadAppMsg(void* pkt)
	{

		auto retCode = AcRxArxApp::On_kUnloadAppMsg(pkt);

		return (retCode);
	}

	AcRx::AppRetCode On_kInitDialogMsg(void* pkt) override
	{
		auto mgr = static_cast<CAdUiTabExtensionManager*>(pkt);
		auto dialogName = mgr->GetDialogName();
		mgr->AddTab(TabExtDLL.ModuleResourceInstance(), IDD_OPTIONS_DIALOG, ACRX_T("Icad Options Tab"),
		        new MyTabChildDialog());
		return AcRx::kRetOK;
	}

	virtual void RegisterServerComponents() {}
};

IMPLEMENT_ARX_ENTRYPOINT(CTabExtApp)

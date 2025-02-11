#include "stdafx.h"

#include <inc/aduiRegistryAccess.h>
#include <inc/AcExtensionModule.h>
#include <inc/acui.h>
#include <afxdllx.h>

AC_IMPLEMENT_EXTENSION_MODULE(IcArxUiTesringDLL)
//- Now you can use the CAcModuleResourceOverride class in
//- your application to switch to the correct resource instance.
//- Please see the ObjectARX Documentation for more details

//-----------------------------------------------------------------------------
//- DLL Entry Point
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	//- Remove this if you use lpReserved
	UNREFERENCED_PARAMETER(lpReserved);

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		_hdllInstance = hInstance;
		IcArxUiTesringDLL.AttachInstance(hInstance);
		InitAcUiDLL();
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		IcArxUiTesringDLL.DetachInstance();
	}
	return (TRUE);
}

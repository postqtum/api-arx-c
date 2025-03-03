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
***     Description: Pre-compiled header file declaration unit
***
*****************************************************************************/
#pragma once

#define DIALOGCONTROLS_MODULE

#ifndef _ALLOW_RTCc_IN_STL
#define _ALLOW_RTCc_IN_STL
#endif

#pragma pack(push, 8)
#pragma warning(disable : 4786 4996)
    //#pragma warning(disable: 4098)

    //-----------------------------------------------------------------------------
#define STRICT

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN //- Exclude rarely-used stuff from Windows headers
#endif

//- Modify the following defines if you have to target a platform prior to the ones specified below.
//- Refer to MSDN for the latest info on corresponding values for different platforms.
#ifndef WINVER        //- Allow use of features specific to Windows 95 and Windows NT 4 or later.
#define WINVER 0x0601 //- Change this to the appropriate value to target Windows 98 and Windows 2000 or later.
#endif
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0601
#endif

        //- ObjectARX and OMF headers needs this
#include <map>

    //-----------------------------------------------------------------------------
#include <afxwin.h> //- MFC core and standard components
#include <afxext.h> //- MFC extensions
#include <afxcmn.h> //- MFC support for Windows Common Controls

                //-----------------------------------------------------------------------------
    //- Include ObjectDBX/ObjectARX headers
    //- Uncomment one of the following lines to bring a given library in your project.
    //#define _BREP_SUPPORT_					//- Support for the BRep API
    //#define _HLR_SUPPORT_						//- Support for the Hidden Line Removal API
    //#define _AMODELER_SUPPORT_				//- Support for the AModeler API
        //#define _ASE_SUPPORT_							//- Support for the ASI/ASE API
    //#define _RENDER_SUPPORT_					//- Support for the AutoCAD Render API
        //#define _ARX_CUSTOM_DRAG_N_DROP_	//- Support for the ObjectARX Drag'n Drop API
    //#define _INC_LEAGACY_HEADERS_			//- Include legacy headers in this project
#include <inc/aduiRegistryAccess.h>
#include <inc/acui.h>
#include <inc/adui_port.h>
#include <inc/aduiMessage.h>
#include <inc/dbid.h>
#include <inc/dbmain.h>
#include <inc/acuiEdit.h>
#include <inc/dbxEntryPoint.h>
#include <inc/adui.h>

//-----------------------------------------------------------------------------

#pragma pack(pop)

#include "resource.h"

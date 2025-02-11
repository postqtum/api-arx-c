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

#include "adesk.h"

#ifndef AC_DO_NO_IMPORT
#	pragma warning(push)
#	pragma warning(disable : 4279)
#	pragma warning(disable : 4192)
#	import "msxml6.dll" named_guids rename_namespace("MSXML") rename("offset", "MSXMLoffset")
#	pragma warning(pop)
#else  // AC_DO_NO_IMPORT
#	include "msxml6.tlh"
#endif
__declspec(selectany) extern const GUID CLSID_DOMDocumentAcad = MSXML::CLSID_DOMDocument60;

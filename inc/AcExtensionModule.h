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
***     Description: Extension module common includes
***
*****************************************************************************/
#pragma once

#include "icarx/CAcExtensionModule.h"
#include "icarx/CAcModuleResourceOverride.h"

#define AC_DECLARE_EXTENSION_MODULE(exm) extern CAcExtensionModule exm;

#define AC_IMPLEMENT_EXTENSION_MODULE(exm) \
	CAcExtensionModule exm;                \
	CAcExtensionModule& CAcModuleResourceOverride::m_extensionModule = exm;

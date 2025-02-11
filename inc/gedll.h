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
***     Description: DLL linking declspecs
***
*****************************************************************************/
#pragma once

#include "adesk.h"

#pragma warning(disable : 4251)
#pragma warning(disable : 4273)
#pragma warning(disable : 4275)

#ifdef ICARXGE_EXPORTS
#	define GE_DLLEXPIMPORT __declspec(dllexport)
#	define GE_DLLDATAEXIMP __declspec(dllexport)
#else
#	define GE_DLLEXPIMPORT __declspec(dllimport)
#	define GE_DLLDATAEXIMP __declspec(dllimport)
#endif


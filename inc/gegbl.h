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
***     Description: Declaration of AcGeContext struct
***
*****************************************************************************/
#pragma once

#include <cstdlib>
#include "gedll.h"
#include "adesk.h"
#include "getol.h"
#include "gegblge.h"

class AcGeVector3d;

#include "icarx/IcArxPackPush.h"

struct AcGeContext
{
	GE_DLLDATAEXIMP static AcGeTol gTol;
	GE_DLLDATAEXIMP static void (*gErrorFunc)();
	GE_DLLDATAEXIMP static void (*gOrthoVector)(const AcGeVector3d&, AcGeVector3d&);
	GE_DLLDATAEXIMP static void* (*gAllocMem)(size_t);
	GE_DLLDATAEXIMP static void (*gFreeMem)(void*);
#ifndef NDEBUG
	GE_DLLDATAEXIMP static void (*gAssertFunc)(const ACHAR*, const ACHAR*, int, const ACHAR*);
#endif
};

#include "icarx/IcArxPackPop.h"

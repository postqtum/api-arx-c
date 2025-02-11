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

#include "icarx/AcDbBreakData.h"
#include "icarx/AcDbBreakPointRef.h"

#include "dbmain.h"

Acad::ErrorStatus acdbGetBreakSubentIndex(AcDbEntity* pEnt, const AcGePoint3d& pickPt,
										  const AcGeVector3d& viewDir, int& subentIndex,
										  AcGePoint3d& ptOnEnt,
										  const AcGeTol& tol = AcGeContext::gTol);

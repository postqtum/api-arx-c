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
***     Description: Declaration of AcGePosition3d class
***
*****************************************************************************/
#pragma once

#include "adesk.h"
#include "gepent3d.h"
#include "gepnt3d.h"

#include "icarx/IcArxPackPush.h"

class AcGePosition3d : public AcGePointEnt3d
{
public:
	GE_DLLEXPIMPORT AcGePosition3d();
	GE_DLLEXPIMPORT AcGePosition3d(const AcGePoint3d& pnt);
	GE_DLLEXPIMPORT AcGePosition3d(double x, double y, double z);
	GE_DLLEXPIMPORT AcGePosition3d(const AcGePosition3d&);
	~AcGePosition3d() = default;
	GE_DLLEXPIMPORT AcGePosition3d& operator=(const AcGePosition3d&);

	GE_DLLEXPIMPORT AcGePosition3d& set(const AcGePoint3d&);
	GE_DLLEXPIMPORT AcGePosition3d& set(double x, double y, double z);
};

#include "icarx/IcArxPackPop.h"

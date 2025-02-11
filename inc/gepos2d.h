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
***     Description: Declaration of AcGePosition2d class
***
*****************************************************************************/
#pragma once

#include "adesk.h"
#include "gepent2d.h"

#include "icarx/IcArxPackPush.h"

class AcGePosition2d : public AcGePointEnt2d
{
public:
	GE_DLLEXPIMPORT AcGePosition2d();
	GE_DLLEXPIMPORT AcGePosition2d(const AcGePoint2d& pnt);
	GE_DLLEXPIMPORT AcGePosition2d(double x, double y);
	GE_DLLEXPIMPORT AcGePosition2d(const AcGePosition2d&);
	~AcGePosition2d() = default;
	GE_DLLEXPIMPORT AcGePosition2d& operator=(const AcGePosition2d&);

	GE_DLLEXPIMPORT AcGePosition2d& set(const AcGePoint2d&);
	GE_DLLEXPIMPORT AcGePosition2d& set(double x, double y);
};

#include "icarx/IcArxPackPop.h"

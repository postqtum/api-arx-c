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
***     Description: Declaration of AcGeLine2d class
***
*****************************************************************************/
#pragma once

#include "gelent2d.h"

#include "icarx/IcArxPackPush.h"

class AcGeLine2d : public AcGeLinearEnt2d
{
public:
	GE_DLLDATAEXIMP static const AcGeLine2d kXAxis;
	GE_DLLDATAEXIMP static const AcGeLine2d kYAxis;

public:
	GE_DLLEXPIMPORT AcGeLine2d();
	GE_DLLEXPIMPORT AcGeLine2d(const AcGePoint2d& pnt, const AcGeVector2d& vec);
	GE_DLLEXPIMPORT AcGeLine2d(const AcGePoint2d& pnt1, const AcGePoint2d& pnt2);
	GE_DLLEXPIMPORT AcGeLine2d(const AcGeLine2d&);
	~AcGeLine2d() = default;
	GE_DLLEXPIMPORT AcGeLine2d& operator=(const AcGeLine2d&);

	GE_DLLEXPIMPORT AcGeLine2d& set(const AcGePoint2d& pnt, const AcGeVector2d& vec);
	GE_DLLEXPIMPORT AcGeLine2d& set(const AcGePoint2d& pnt1, const AcGePoint2d& pnt2);
};

#include "icarx/IcArxPackPop.h"

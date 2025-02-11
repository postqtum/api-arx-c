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
***     Description: Declaration of AcGeLine3d class
***
*****************************************************************************/
#pragma once

#include "gelent3d.h"

#include "icarx/IcArxPackPush.h"

class AcGeLine2d;

class AcGeLine3d : public AcGeLinearEnt3d
{
public:
	GE_DLLDATAEXIMP static const AcGeLine3d kXAxis;
	GE_DLLDATAEXIMP static const AcGeLine3d kYAxis;
	GE_DLLDATAEXIMP static const AcGeLine3d kZAxis;

public:
	GE_DLLEXPIMPORT AcGeLine3d();
	GE_DLLEXPIMPORT AcGeLine3d(const AcGePoint3d& pnt, const AcGeVector3d& vec);
	GE_DLLEXPIMPORT AcGeLine3d(const AcGePoint3d& pnt1, const AcGePoint3d& pnt2);
	GE_DLLEXPIMPORT AcGeLine3d(const AcGeLine3d&);
	~AcGeLine3d() = default;
	GE_DLLEXPIMPORT AcGeLine3d& operator=(const AcGeLine3d&);

	GE_DLLEXPIMPORT AcGeLine3d& set(const AcGePoint3d& pnt, const AcGeVector3d& vec);
	GE_DLLEXPIMPORT AcGeLine3d& set(const AcGePoint3d& pnt1, const AcGePoint3d& pnt2);
};

#include "icarx/IcArxPackPop.h"

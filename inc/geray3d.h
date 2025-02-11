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
***     Description: Declaration of AcGeRay3d class
***
*****************************************************************************/
#pragma once

#include "gelent3d.h"

class AcGeRay2d;

#include "icarx/IcArxPackPush.h"

class AcGeRay3d : public AcGeLinearEnt3d
{
public:
	GE_DLLEXPIMPORT AcGeRay3d();
	GE_DLLEXPIMPORT AcGeRay3d(const AcGePoint3d& pnt, const AcGeVector3d& vec);
	GE_DLLEXPIMPORT AcGeRay3d(const AcGePoint3d& pnt1, const AcGePoint3d& pnt2);
	GE_DLLEXPIMPORT AcGeRay3d(const AcGeRay3d&);
	~AcGeRay3d() = default;
	GE_DLLEXPIMPORT AcGeRay3d& operator=(const AcGeRay3d&);

	GE_DLLEXPIMPORT AcGeRay3d& set(const AcGePoint3d& pnt, const AcGeVector3d& vec);
	GE_DLLEXPIMPORT AcGeRay3d& set(const AcGePoint3d& pnt1, const AcGePoint3d& pnt2);
};

#include "icarx/IcArxPackPop.h"

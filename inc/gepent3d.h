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
***     Description: Declaration of AcGePointEnt3d class
***
*****************************************************************************/
#pragma once

#include "adesk.h"
#include "geent3d.h"

#include "icarx/IcArxPackPush.h"

class AcGePointEnt3d : public AcGeEntity3d
{
protected:
	GE_DLLEXPIMPORT AcGePointEnt3d();
	GE_DLLEXPIMPORT AcGePointEnt3d(const AcGePointEnt3d&);

public:
	~AcGePointEnt3d() = default;
	GE_DLLEXPIMPORT AcGePointEnt3d& operator=(const AcGePointEnt3d&);
	GE_DLLEXPIMPORT operator AcGePoint3d() const;

	GE_DLLEXPIMPORT AcGePoint3d point3d() const;
};

#include "icarx/IcArxPackPop.h"

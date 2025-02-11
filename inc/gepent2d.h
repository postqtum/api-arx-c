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
***     Description: Declaration of AcGePointEnt2d class
***
*****************************************************************************/
#pragma once

#include "adesk.h"
#include "geent2d.h"
#include "gepnt2d.h"

#include "icarx/IcArxPackPush.h"

class AcGePointEnt2d : public AcGeEntity2d
{
protected:
	GE_DLLEXPIMPORT AcGePointEnt2d();
	GE_DLLEXPIMPORT AcGePointEnt2d(const AcGePointEnt2d&);

public:
	~AcGePointEnt2d() = default;
	GE_DLLEXPIMPORT AcGePointEnt2d& operator=(const AcGePointEnt2d&);
	GE_DLLEXPIMPORT operator AcGePoint2d() const;

	GE_DLLEXPIMPORT AcGePoint2d point2d() const;
};

#include "icarx/IcArxPackPop.h"

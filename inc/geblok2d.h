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
***     Description: Declaration of AcGeBoundBlock2d class
***
*****************************************************************************/
#pragma once

#include "geent2d.h"

class AcGePoint2d;
class AcGeVector2d;

#include "icarx/IcArxPackPush.h"

class AcGeBoundBlock2d : public AcGeEntity2d
{
public:
	GE_DLLEXPIMPORT AcGeBoundBlock2d();
	GE_DLLEXPIMPORT AcGeBoundBlock2d(const AcGePoint2d& point1, const AcGePoint2d& point2);
	GE_DLLEXPIMPORT AcGeBoundBlock2d(const AcGePoint2d& base, const AcGeVector2d& dir1,
									 const AcGeVector2d& dir2);
	GE_DLLEXPIMPORT AcGeBoundBlock2d(const AcGeBoundBlock2d&);
	~AcGeBoundBlock2d() = default;
	GE_DLLEXPIMPORT AcGeBoundBlock2d& operator=(const AcGeBoundBlock2d&);

	GE_DLLEXPIMPORT bool contains(const AcGePoint2d& point) const;
	GE_DLLEXPIMPORT AcGeBoundBlock2d& extend(const AcGePoint2d& point);
	GE_DLLEXPIMPORT void get(AcGePoint2d& base, AcGeVector2d& dir1, AcGeVector2d& dir2) const;
	GE_DLLEXPIMPORT void getMinMaxPoints(AcGePoint2d& point1, AcGePoint2d& point2) const;
	GE_DLLEXPIMPORT bool isBox() const;
	GE_DLLEXPIMPORT bool isDisjoint(const AcGeBoundBlock2d& block) const;
	GE_DLLEXPIMPORT AcGeBoundBlock2d& set(const AcGePoint2d& point1, const AcGePoint2d& point2);
	GE_DLLEXPIMPORT AcGeBoundBlock2d& set(const AcGePoint2d& base, const AcGeVector2d& dir1,
										  const AcGeVector2d& dir2);
	GE_DLLEXPIMPORT AcGeBoundBlock2d& setToBox(bool);
	GE_DLLEXPIMPORT AcGeBoundBlock2d& swell(double distance);
};

#include "icarx/IcArxPackPop.h"

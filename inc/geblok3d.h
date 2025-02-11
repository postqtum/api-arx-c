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
***     Description: Declaration of AcGeBoundBlock3d class
***
*****************************************************************************/
#pragma once

#include "geent3d.h"

class AcGePoint3d;
class AcGeVector3d;

#include "icarx/IcArxPackPush.h"

class AcGeBoundBlock3d : public AcGeEntity3d
{
public:
	GE_DLLEXPIMPORT AcGeBoundBlock3d();
	GE_DLLEXPIMPORT AcGeBoundBlock3d(const AcGePoint3d& base, const AcGeVector3d& dir1,
									 const AcGeVector3d& dir2, const AcGeVector3d& dir3);
	GE_DLLEXPIMPORT AcGeBoundBlock3d(const AcGeBoundBlock3d&);
	~AcGeBoundBlock3d() = default;
	GE_DLLEXPIMPORT AcGeBoundBlock3d& operator=(const AcGeBoundBlock3d&);

	GE_DLLEXPIMPORT bool contains(const AcGePoint3d& point) const;
	GE_DLLEXPIMPORT AcGeBoundBlock3d& extend(const AcGePoint3d& point);
	GE_DLLEXPIMPORT void get(AcGePoint3d& base, AcGeVector3d& dir1, AcGeVector3d& dir2,
							 AcGeVector3d& dir3) const;
	GE_DLLEXPIMPORT void getMinMaxPoints(AcGePoint3d& point1, AcGePoint3d& point2) const;
	GE_DLLEXPIMPORT bool isBox() const;
	GE_DLLEXPIMPORT bool isDisjoint(const AcGeBoundBlock3d& block) const;
	GE_DLLEXPIMPORT AcGeBoundBlock3d& set(const AcGePoint3d& point1, const AcGePoint3d& point2);
	GE_DLLEXPIMPORT AcGeBoundBlock3d& set(const AcGePoint3d& base, const AcGeVector3d& dir1,
										  const AcGeVector3d& dir2, const AcGeVector3d& dir3);
	GE_DLLEXPIMPORT AcGeBoundBlock3d& setToBox(bool);
	GE_DLLEXPIMPORT AcGeBoundBlock3d& swell(double distance);
};

#include "icarx/IcArxPackPop.h"

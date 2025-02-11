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
***     Description: Declaration of AcGeEntity2d class
***
*****************************************************************************/
#pragma once

#include "gegbl.h"
#include "gepnt2d.h"
#include "geintrvl.h"
#include "gegblnew.h"

class AcGeImpEntity3d;

#include "icarx/IcArxPackPush.h"

class AcGeEntity2d
{
	friend class AcGeEntity3d;
	friend class AcGeImpEntity3d;

protected:
	AcGeImpEntity3d* mpImpEnt;
	int mDelEnt;

protected:
	GE_DLLEXPIMPORT AcGeEntity2d();
	GE_DLLEXPIMPORT AcGeEntity2d(const AcGeEntity2d&);
	GE_DLLEXPIMPORT AcGeEntity2d(AcGeImpEntity3d&, int);
	GE_DLLEXPIMPORT AcGeEntity2d(AcGeImpEntity3d*);

	GE_DLLEXPIMPORT AcGeEntity2d* newEntity2d(AcGeImpEntity3d*) const;

public:
	GE_DLLEXPIMPORT ~AcGeEntity2d();
	GE_DLLEXPIMPORT AcGeEntity2d& operator=(const AcGeEntity2d&);
	GE_DLLEXPIMPORT bool operator==(const AcGeEntity2d&) const;
	GE_DLLEXPIMPORT bool operator!=(const AcGeEntity2d&) const;

	GE_DLLEXPIMPORT AcGeEntity2d* copy() const;
	GE_DLLEXPIMPORT bool isEqualTo(const AcGeEntity2d& entity,
								   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isKindOf(AcGe::EntityId entType) const;
	GE_DLLEXPIMPORT bool isOn(const AcGePoint2d& pnt, const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT AcGeEntity2d& mirror(const AcGeLine2d& line);
	GE_DLLEXPIMPORT AcGeEntity2d& rotateBy(double angle,
										   const AcGePoint2d& wrtPoint = AcGePoint2d::kOrigin);
	GE_DLLEXPIMPORT AcGeEntity2d& scaleBy(double scaleFactor,
										  const AcGePoint2d& wrtPoint = AcGePoint2d::kOrigin);
	GE_DLLEXPIMPORT AcGeEntity2d& transformBy(const AcGeMatrix2d& xfm);
	GE_DLLEXPIMPORT AcGeEntity2d& translateBy(const AcGeVector2d& translateVec);
	GE_DLLEXPIMPORT AcGe::EntityId type() const;
};

#include "icarx/IcArxPackPop.h"

inline AcGeEntity2d* AcGeEntity2d::newEntity2d(AcGeImpEntity3d* impEnt) const
{
	return GENEWLOC(AcGeEntity2d, this)(impEnt);
}

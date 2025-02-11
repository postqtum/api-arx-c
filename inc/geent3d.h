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
***     Description: Declaration of AcGeEntity3d class
***
*****************************************************************************/
#pragma once

#include "gegbl.h"
#include "gepnt3d.h"
#include "geent2d.h"
#include "geintrvl.h"
#include "gegblnew.h"

class AcGeImpEntity3d;

#include "icarx/IcArxPackPush.h"

class AcGeEntity3d
{
	friend class AcGeImpEntity3d;

protected:
	AcGeImpEntity3d* mpImpEnt;
	int mDelEnt;

protected:
	GE_DLLEXPIMPORT AcGeEntity3d();
	GE_DLLEXPIMPORT AcGeEntity3d(const AcGeEntity3d&);
	GE_DLLEXPIMPORT AcGeEntity3d(AcGeImpEntity3d&, int);
	GE_DLLEXPIMPORT AcGeEntity3d(AcGeImpEntity3d*);

	GE_DLLEXPIMPORT AcGeEntity2d* newEntity2d(AcGeImpEntity3d*) const;
	GE_DLLEXPIMPORT AcGeEntity2d* newEntity2d(AcGeImpEntity3d&, int) const;
	GE_DLLEXPIMPORT AcGeEntity3d* newEntity3d(AcGeImpEntity3d*) const;
	GE_DLLEXPIMPORT AcGeEntity3d* newEntity3d(AcGeImpEntity3d&, int) const;

public:
	GE_DLLEXPIMPORT ~AcGeEntity3d();
	GE_DLLEXPIMPORT AcGeEntity3d& operator=(const AcGeEntity3d&);
	GE_DLLEXPIMPORT bool operator==(const AcGeEntity3d&) const;
	GE_DLLEXPIMPORT bool operator!=(const AcGeEntity3d&) const;

	GE_DLLEXPIMPORT AcGeEntity3d* copy() const;
	GE_DLLEXPIMPORT bool isEqualTo(const AcGeEntity3d& ent,
								   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isKindOf(AcGe::EntityId entType) const;
	GE_DLLEXPIMPORT bool isOn(const AcGePoint3d& pnt, const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT AcGeEntity3d& mirror(const AcGePlane& plane);
	GE_DLLEXPIMPORT AcGeEntity3d& rotateBy(double angle, const AcGeVector3d& vec,
										   const AcGePoint3d& wrtPoint = AcGePoint3d::kOrigin);
	GE_DLLEXPIMPORT AcGeEntity3d& scaleBy(double scaleFactor,
										  const AcGePoint3d& wrtPoint = AcGePoint3d::kOrigin);
	GE_DLLEXPIMPORT AcGeEntity3d& transformBy(const AcGeMatrix3d& xfm);
	GE_DLLEXPIMPORT AcGeEntity3d& translateBy(const AcGeVector3d& translateVec);
	GE_DLLEXPIMPORT AcGe::EntityId type() const;
};

#include "icarx/IcArxPackPop.h"

inline AcGeEntity2d* AcGeEntity3d::newEntity2d(AcGeImpEntity3d* impEnt) const
{
	return GENEWLOC(AcGeEntity2d, this)(impEnt);
}

inline AcGeEntity2d* AcGeEntity3d::newEntity2d(AcGeImpEntity3d& impEnt, int dummy) const
{
	return GENEWLOC(AcGeEntity2d, this)(impEnt, dummy);
}

inline AcGeEntity3d* AcGeEntity3d::newEntity3d(AcGeImpEntity3d* impEnt) const
{
	return GENEWLOC(AcGeEntity3d, this)(impEnt);
}

inline AcGeEntity3d* AcGeEntity3d::newEntity3d(AcGeImpEntity3d& impEnt, int dummy) const
{
	return GENEWLOC(AcGeEntity3d, this)(impEnt, dummy);
}

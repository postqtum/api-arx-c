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
***     Description: Declaration of AcGePointOnSurface class
***
*****************************************************************************/
#pragma once

#include "gepent3d.h"

class AcGeSurface;

#include "icarx/IcArxPackPush.h"

class AcGePointOnSurface : public AcGePointEnt3d
{
public:
	GE_DLLEXPIMPORT AcGePointOnSurface();
	GE_DLLEXPIMPORT AcGePointOnSurface(const AcGeSurface& surf);
	GE_DLLEXPIMPORT AcGePointOnSurface(const AcGeSurface& surf, const AcGePoint2d& param);
	GE_DLLEXPIMPORT AcGePointOnSurface(const AcGePointOnSurface&);
	~AcGePointOnSurface() = default;
	GE_DLLEXPIMPORT AcGePointOnSurface& operator=(const AcGePointOnSurface&);

	GE_DLLEXPIMPORT AcGeVector2d inverseTangentVector(const AcGeVector3d& vec) const;
	GE_DLLEXPIMPORT AcGeVector2d inverseTangentVector(const AcGeVector3d& vec,
													  const AcGePoint2d& param);
	GE_DLLEXPIMPORT AcGeVector2d inverseTangentVector(const AcGeVector3d& vec,
													  const AcGeSurface& surf,
													  const AcGePoint2d& param);
	GE_DLLEXPIMPORT AcGeVector3d mixedPartial() const;
	GE_DLLEXPIMPORT AcGeVector3d mixedPartial(const AcGePoint2d& param);
	GE_DLLEXPIMPORT AcGeVector3d mixedPartial(const AcGeSurface& surf, const AcGePoint2d& param);
	GE_DLLEXPIMPORT AcGeVector3d normal() const;
	GE_DLLEXPIMPORT AcGeVector3d normal(const AcGePoint2d& param);
	GE_DLLEXPIMPORT AcGeVector3d normal(const AcGeSurface& surf, const AcGePoint2d& param);
	GE_DLLEXPIMPORT AcGePoint2d parameter() const;
	GE_DLLEXPIMPORT AcGePoint3d point() const;
	GE_DLLEXPIMPORT AcGePoint3d point(const AcGePoint2d& param);
	GE_DLLEXPIMPORT AcGePoint3d point(const AcGeSurface& surf, const AcGePoint2d& param);
	GE_DLLEXPIMPORT AcGePointOnSurface& setParameter(const AcGePoint2d& param);
	GE_DLLEXPIMPORT AcGePointOnSurface& setSurface(const AcGeSurface& surf);
	GE_DLLEXPIMPORT const AcGeSurface* surface() const;
	GE_DLLEXPIMPORT AcGeVector3d tangentVector(const AcGeVector2d& vec) const;
	GE_DLLEXPIMPORT AcGeVector3d tangentVector(const AcGeVector2d& vec, const AcGePoint2d& param);
	GE_DLLEXPIMPORT AcGeVector3d tangentVector(const AcGeVector2d& vec, const AcGeSurface& vecSurf,
											   const AcGePoint2d& param);
	GE_DLLEXPIMPORT AcGeVector3d uDeriv(int order) const;
	GE_DLLEXPIMPORT AcGeVector3d uDeriv(int order, const AcGePoint2d& param);
	GE_DLLEXPIMPORT AcGeVector3d uDeriv(int order, const AcGeSurface& surf,
										const AcGePoint2d& param);
	GE_DLLEXPIMPORT AcGeVector3d vDeriv(int order) const;
	GE_DLLEXPIMPORT AcGeVector3d vDeriv(int order, const AcGePoint2d& param);
	GE_DLLEXPIMPORT AcGeVector3d vDeriv(int order, const AcGeSurface& surf,
										const AcGePoint2d& param);
};

#include "icarx/IcArxPackPop.h"

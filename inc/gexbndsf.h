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
***     Description: Declaration of AcGeExternalBoundedSurface class
***
*****************************************************************************/
#pragma once

#include "gegbl.h"
#include "gesurf.h"

class AcGeExternalSurface;
class AcGeCurveBoundary;

#include "icarx/IcArxPackPush.h"

class GE_DLLEXPIMPORT AcGeExternalBoundedSurface : public AcGeSurface
{
public:
	AcGeExternalBoundedSurface();
	AcGeExternalBoundedSurface(void* surfaceDef, AcGe::ExternalEntityKind surfaceKind,
							   bool makeCopy = true);
	AcGeExternalBoundedSurface(const AcGeExternalBoundedSurface&);
	AcGeExternalBoundedSurface& operator=(const AcGeExternalBoundedSurface&);

	AcGe::ExternalEntityKind externalSurfaceKind() const;
	void getBaseSurface(AcGeSurface*& surfaceDef) const;
	void getBaseSurface(AcGeExternalSurface& unboundedSurfaceDef) const;
	void getContours(int& numContours, AcGeCurveBoundary*& curveBoundaries) const;
	void getExternalSurface(void*& surfaceDef) const;
	bool isCone() const;
	bool isCylinder() const;
	bool isDefined() const;
	bool isExternalSurface() const;
	bool isNurbs() const;
	bool isOwnerOfSurface() const;
	bool isPlane() const;
	bool isSphere() const;
	bool isTorus() const;
	int numContours() const;
	AcGeExternalBoundedSurface& set(void* surfaceDef, AcGe::ExternalEntityKind surfaceKind,
									bool makeCopy = true);
	AcGeExternalBoundedSurface& setToOwnSurface();
};

#include "icarx/IcArxPackPop.h"

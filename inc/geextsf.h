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
***     Description: Declaration of AcGeExternalSurface class
***
*****************************************************************************/
#pragma once

#include "gegbl.h"
#include "gesurf.h"

class AcGePlane;
class AcGeCylinder;
class AcGeCone;
class AcGeSphere;
class AcGeTorus;
class AcGeNurbSurface;
class surface;

#include "icarx/IcArxPackPush.h"

class GE_DLLEXPIMPORT AcGeExternalSurface : public AcGeSurface
{
public:
	AcGeExternalSurface();
	AcGeExternalSurface(void* surfaceDef, AcGe::ExternalEntityKind surfaceKind,
						bool makeCopy = true);
	AcGeExternalSurface(const AcGeExternalSurface&);
	AcGeExternalSurface& operator=(const AcGeExternalSurface&);

	AcGe::ExternalEntityKind externalSurfaceKind() const;
	void getExternalSurface(void*& surfaceDef) const;
	bool isCone() const;
	bool isCylinder() const;
	bool isDefined() const;
	bool isNativeSurface(AcGeSurface*& nativeSurface) const;
	bool isNurbSurface() const;
	bool isOwnerOfSurface() const;
	bool isPlane() const;
	bool isSphere() const;
	bool isTorus() const;
	AcGeExternalSurface& set(void* surfaceDef, AcGe::ExternalEntityKind surfaceKind,
							 bool makeCopy = true);
	AcGeExternalSurface& setToOwnSurface();
};

#include "icarx/IcArxPackPop.h"

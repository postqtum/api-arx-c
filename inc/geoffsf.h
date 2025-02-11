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
***     Description: Declaration of AcGeOffsetSurface class
***
*****************************************************************************/
#pragma once

#include "gegbl.h"
#include "gepnt3d.h"
#include "gesurf.h"

class AcGePlane;
class AcGeBoundedPlane;
class AcGeCylinder;
class AcGeCone;
class AcGeSphere;
class AcGeTorus;

#include "icarx/IcArxPackPush.h"

class GE_DLLEXPIMPORT AcGeOffsetSurface : public AcGeSurface
{
public:
	AcGeOffsetSurface();
	AcGeOffsetSurface(AcGeSurface* baseSurface, double offsetDist,
					  bool makeCopy = true);
	AcGeOffsetSurface(const AcGeOffsetSurface&);
	AcGeOffsetSurface& operator=(const AcGeOffsetSurface&);

	void getConstructionSurface(AcGeSurface*& base) const;
	bool getSurface(AcGeSurface*&) const;
	bool isBoundedPlane() const;
	bool isCone() const;
	bool isCylinder() const;
	bool isPlane() const;
	bool isSphere() const;
	bool isTorus() const;
	double offsetDist() const;
	AcGeOffsetSurface& set(AcGeSurface*, double offsetDist, bool makeCopy = true);
};

#include "icarx/IcArxPackPop.h"

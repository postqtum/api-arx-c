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
***     Description: Declaration of AcGeCurveBoundary class
***
*****************************************************************************/
#pragma once

#include "gegbl.h"

class AcGeCurve2d;
class AcGeEntity3d;
class AcGePosition3d;
class AcGeImpCurveBoundary;

#include "icarx/IcArxPackPush.h"

class GE_DLLEXPIMPORT AcGeCurveBoundary
{
	friend class AcGeImpCurveBoundary;

private:
	AcGeImpCurveBoundary* mpImpBnd;

public:
	AcGeCurveBoundary();
	AcGeCurveBoundary(int numberOfCurves, const AcGeEntity3d* const* crv3d,
					  const AcGeCurve2d* const* crv2d, bool* orientation3d,
					  bool* orientation2d, bool makeCopy = true);
	AcGeCurveBoundary(const AcGeCurveBoundary&);
	~AcGeCurveBoundary();
	AcGeCurveBoundary& operator=(const AcGeCurveBoundary&);

	void getContour(int& n, AcGeEntity3d*** crv3d, AcGeCurve2d*** paramGeometry,
					bool** orientation3d, bool** orientation2d) const;
	bool isDegenerate() const;
	bool isDegenerate(AcGePosition3d& degenPoint, AcGeCurve2d** paramCurve) const;
	bool isOwnerOfCurves() const;
	int numElements() const;
	AcGeCurveBoundary& set(int numElements, const AcGeEntity3d* const* crv3d,
						   const AcGeCurve2d* const* crv2d, bool* orientation3d,
						   bool* orientation2d, bool makeCopy = true);
	AcGeCurveBoundary& setToOwnCurves();
};

#include "icarx/IcArxPackPop.h"

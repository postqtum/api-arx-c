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
***     Description: Declaration of AcGeNurbSurface class
***
*****************************************************************************/
#pragma once

#include "gegbl.h"
#include "gesurf.h"
#include "gept3dar.h"
#include "gedblar.h"

class AcGeKnotVector;

#include "icarx/IcArxPackPush.h"

class GE_DLLEXPIMPORT AcGeNurbSurface : public AcGeSurface
{
public:
	AcGeNurbSurface();
	AcGeNurbSurface(int degreeU, int degreeV, int propsInU, int propsInV, int numControlPointsInU,
					int numControlPointsInV, const AcGePoint3d controlPoints[],
					const double weights[], const AcGeKnotVector& uKnots,
					const AcGeKnotVector& vKnots, const AcGeTol& tol = AcGeContext::gTol);
	AcGeNurbSurface(const AcGeNurbSurface&);
	AcGeNurbSurface& operator=(const AcGeNurbSurface&);

	int degreeInU() const;
	int degreeInV() const;
	void getControlPoints(AcGePoint3dArray& points) const;
	void getDefinition(int& degreeU, int& degreeV, int& propsInU, int& propsInV,
					   int& numControlPointsInU, int& numControlPointsInV,
					   AcGePoint3dArray& controlPoints, AcGeDoubleArray& weights,
					   AcGeKnotVector& uKnots, AcGeKnotVector& vKnots) const;
	void getUKnots(AcGeKnotVector& uKnots) const;
	void getVKnots(AcGeKnotVector& vKnots) const;
	bool getWeights(AcGeDoubleArray& weights) const;
	bool isPeriodicInU(double&) const;
	bool isPeriodicInV(double&) const;
	bool isRationalInU() const;
	bool isRationalInV() const;
	int numControlPointsInU() const;
	int numControlPointsInV() const;
	int numKnotsInU() const;
	int numKnotsInV() const;
	AcGeNurbSurface& set(int degreeU, int degreeV, int propsInU, int propsInV,
						 int numControlPointsInU, int numControlPointsInV,
						 const AcGePoint3d controlPoints[], const double weights[],
						 const AcGeKnotVector& uKnots, const AcGeKnotVector& vKnots,
						 const AcGeTol& tol = AcGeContext::gTol);
	int singularityInU() const;
	int singularityInV() const;
};

#include "icarx/IcArxPackPop.h"

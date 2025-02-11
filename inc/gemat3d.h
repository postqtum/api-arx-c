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
***     Description: Declaration of AcGeMatrix3d class
***
*****************************************************************************/
#pragma once

#include "gegbl.h"
#include "gemat2d.h"
#include "gepnt3d.h"

class AcGeLine3d;
class AcGeVector3d;
class AcGePlane;
class AcGeTol;

#include "icarx/IcArxPackPush.h"

class AcGeMatrix3d
{
public:
	double entry[4][4];

	GE_DLLDATAEXIMP static const AcGeMatrix3d kIdentity;

public:
	GE_DLLEXPIMPORT AcGeMatrix3d();
	GE_DLLEXPIMPORT AcGeMatrix3d(const AcGeMatrix3d& src);
	~AcGeMatrix3d() = default;
	AcGeMatrix3d& operator=(const AcGeMatrix3d&) = default;
	GE_DLLEXPIMPORT bool operator==(const AcGeMatrix3d&) const;
	GE_DLLEXPIMPORT bool operator!=(const AcGeMatrix3d&) const;
	GE_DLLEXPIMPORT AcGeMatrix3d operator*(const AcGeMatrix3d&) const;
	GE_DLLEXPIMPORT AcGeMatrix3d& operator*=(const AcGeMatrix3d&);
	GE_DLLEXPIMPORT double& operator()(unsigned int, unsigned int);
	GE_DLLEXPIMPORT double operator()(unsigned int, unsigned int) const;

	GE_DLLEXPIMPORT static AcGeMatrix3d alignCoordSys(
			const AcGePoint3d& fromOrigin, const AcGeVector3d& fromXAxis,
			const AcGeVector3d& fromYAxis, const AcGeVector3d& fromZAxis,
			const AcGePoint3d& toOrigin, const AcGeVector3d& toXAxis, const AcGeVector3d& toYAxis,
			const AcGeVector3d& toZAxis);
	GE_DLLEXPIMPORT AcGeMatrix2d convertToLocal(AcGeVector3d& normal, double& elev) const;
	GE_DLLEXPIMPORT double det() const;
	GE_DLLEXPIMPORT void getCoordSystem(AcGePoint3d& origin, AcGeVector3d& xAxis,
										AcGeVector3d& yAxis, AcGeVector3d& zAxis) const;
	GE_DLLEXPIMPORT AcGeMatrix3d inverse() const;
	GE_DLLEXPIMPORT AcGeMatrix3d inverse(const AcGeTol& tol) const;
	GE_DLLEXPIMPORT bool inverse(AcGeMatrix3d& inv, double tol) const;
	GE_DLLEXPIMPORT AcGeMatrix3d& invert();
	GE_DLLEXPIMPORT bool isEqualTo(const AcGeMatrix3d& mat,
								   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isScaledOrtho(const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isSingular(const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isUniScaledOrtho(const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT static AcGeMatrix3d mirroring(const AcGePlane& pln);
	GE_DLLEXPIMPORT static AcGeMatrix3d mirroring(const AcGePoint3d& pnt);
	GE_DLLEXPIMPORT static AcGeMatrix3d mirroring(const AcGeLine3d& line);
	GE_DLLEXPIMPORT double norm() const;
	GE_DLLEXPIMPORT static AcGeMatrix3d planeToWorld(const AcGeVector3d& normal);
	GE_DLLEXPIMPORT static AcGeMatrix3d planeToWorld(const AcGePlane&);
	GE_DLLEXPIMPORT AcGeMatrix3d& postMultBy(const AcGeMatrix3d& rightSide);
	GE_DLLEXPIMPORT AcGeMatrix3d& preMultBy(const AcGeMatrix3d& leftSide);
	GE_DLLEXPIMPORT static AcGeMatrix3d projection(const AcGePlane& projectionPlane,
												   const AcGeVector3d& projectDir);
	GE_DLLEXPIMPORT static AcGeMatrix3d rotation(double angle, const AcGeVector3d& axis,
												 const AcGePoint3d& center = AcGePoint3d::kOrigin);
	GE_DLLEXPIMPORT double scale() const;
	GE_DLLEXPIMPORT static AcGeMatrix3d scaling(double scaleAll,
												const AcGePoint3d& center = AcGePoint3d::kOrigin);
	GE_DLLEXPIMPORT AcGeMatrix3d& setCoordSystem(const AcGePoint3d& origin,
												 const AcGeVector3d& xAxis,
												 const AcGeVector3d& yAxis,
												 const AcGeVector3d& zAxis);
	GE_DLLEXPIMPORT AcGeMatrix3d& setToAlignCoordSys(
			const AcGePoint3d& fromOrigin, const AcGeVector3d& fromXAxis,
			const AcGeVector3d& fromYAxis, const AcGeVector3d& fromZAxis,
			const AcGePoint3d& toOrigin, const AcGeVector3d& toXAxis, const AcGeVector3d& toYAxis,
			const AcGeVector3d& toZAxis);
	GE_DLLEXPIMPORT AcGeMatrix3d& setToIdentity();
	GE_DLLEXPIMPORT AcGeMatrix3d& setToMirroring(const AcGePlane& pln);
	GE_DLLEXPIMPORT AcGeMatrix3d& setToMirroring(const AcGePoint3d& pnt);
	GE_DLLEXPIMPORT AcGeMatrix3d& setToMirroring(const AcGeLine3d& line);
	GE_DLLEXPIMPORT AcGeMatrix3d& setToPlaneToWorld(const AcGeVector3d& normal);
	GE_DLLEXPIMPORT AcGeMatrix3d& setToPlaneToWorld(const AcGePlane& plane);
	GE_DLLEXPIMPORT AcGeMatrix3d& setToProduct(const AcGeMatrix3d& mat1, const AcGeMatrix3d& mat2);
	GE_DLLEXPIMPORT AcGeMatrix3d& setToProjection(const AcGePlane& projectionPlane,
												  const AcGeVector3d& projectDir);
	GE_DLLEXPIMPORT AcGeMatrix3d& setToRotation(double angle, const AcGeVector3d& axis,
												const AcGePoint3d& center = AcGePoint3d::kOrigin);
	GE_DLLEXPIMPORT AcGeMatrix3d& setToScaling(double scaleAll,
											   const AcGePoint3d& center = AcGePoint3d::kOrigin);
	GE_DLLEXPIMPORT AcGeMatrix3d& setToTranslation(const AcGeVector3d& vec);
	GE_DLLEXPIMPORT AcGeMatrix3d& setToWorldToPlane(const AcGeVector3d& normal);
	GE_DLLEXPIMPORT AcGeMatrix3d& setToWorldToPlane(const AcGePlane& plane);
	GE_DLLEXPIMPORT AcGeMatrix3d& setTranslation(const AcGeVector3d& vec);
	GE_DLLEXPIMPORT AcGeVector3d translation() const;
	GE_DLLEXPIMPORT static AcGeMatrix3d translation(const AcGeVector3d& vec);
	GE_DLLEXPIMPORT AcGeMatrix3d transpose() const;
	GE_DLLEXPIMPORT AcGeMatrix3d& transposeIt();
	GE_DLLEXPIMPORT static AcGeMatrix3d worldToPlane(const AcGeVector3d& normal);
	GE_DLLEXPIMPORT static AcGeMatrix3d worldToPlane(const AcGePlane&);
};

#include "icarx/IcArxPackPop.h"

inline bool AcGeMatrix3d::operator==(const AcGeMatrix3d& otherMatrix) const
{
	return this->isEqualTo(otherMatrix);
}

inline bool AcGeMatrix3d::operator!=(const AcGeMatrix3d& otherMatrix) const
{
	return !this->isEqualTo(otherMatrix);
}

inline double AcGeMatrix3d::operator()(unsigned int row, unsigned int column) const
{
	return entry[row][column];
}

inline double& AcGeMatrix3d::operator()(unsigned int row, unsigned int column)
{
	return entry[row][column];
}

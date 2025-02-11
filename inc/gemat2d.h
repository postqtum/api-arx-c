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
***     Description: Declaration of AcGeMatrix2d class
***
*****************************************************************************/
#pragma once

#include "gegbl.h"
#include "gepnt2d.h"

class AcGeVector2d;
class AcGeLine2d;
class AcGeTol;

#include "icarx/IcArxPackPush.h"

class AcGeMatrix2d
{
public:
	double entry[3][3];

	GE_DLLDATAEXIMP static const AcGeMatrix2d kIdentity;

public:
	GE_DLLEXPIMPORT AcGeMatrix2d();
	GE_DLLEXPIMPORT AcGeMatrix2d(const AcGeMatrix2d&);
	~AcGeMatrix2d() = default;
	AcGeMatrix2d& operator=(const AcGeMatrix2d&) = default;
	GE_DLLEXPIMPORT bool operator==(const AcGeMatrix2d&) const;
	GE_DLLEXPIMPORT bool operator!=(const AcGeMatrix2d&) const;
	GE_DLLEXPIMPORT AcGeMatrix2d operator*(const AcGeMatrix2d&) const;
	GE_DLLEXPIMPORT AcGeMatrix2d& operator*=(const AcGeMatrix2d&);
	GE_DLLEXPIMPORT double& operator()(unsigned int, unsigned int);
	GE_DLLEXPIMPORT double operator()(unsigned int, unsigned int) const;

	GE_DLLEXPIMPORT static AcGeMatrix2d alignCoordSys(
			const AcGePoint2d& fromOrigin, const AcGeVector2d& fromE0, const AcGeVector2d& fromE1,
			const AcGePoint2d& toOrigin, const AcGeVector2d& toE0, const AcGeVector2d& toE1);
	GE_DLLEXPIMPORT double det() const;
	GE_DLLEXPIMPORT void getCoordSystem(AcGePoint2d& origin, AcGeVector2d& e0,
										AcGeVector2d& e1) const;
	GE_DLLEXPIMPORT AcGeMatrix2d inverse() const;
	GE_DLLEXPIMPORT AcGeMatrix2d& invert();
	GE_DLLEXPIMPORT bool isConformal(double& scale, double& angle, bool& isMirror,
									 AcGeVector2d& reflex) const;
	GE_DLLEXPIMPORT bool isEqualTo(const AcGeMatrix2d& mat,
								   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isScaledOrtho(const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isSingular(const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isUniScaledOrtho(const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT static AcGeMatrix2d mirroring(const AcGePoint2d& pnt);
	GE_DLLEXPIMPORT static AcGeMatrix2d mirroring(const AcGeLine2d& line);
	GE_DLLEXPIMPORT AcGeMatrix2d& postMultBy(const AcGeMatrix2d& rightSide);
	GE_DLLEXPIMPORT AcGeMatrix2d& preMultBy(const AcGeMatrix2d& leftSide);
	GE_DLLEXPIMPORT static AcGeMatrix2d rotation(double angle,
												 const AcGePoint2d& center = AcGePoint2d::kOrigin);
	GE_DLLEXPIMPORT double scale();
	GE_DLLEXPIMPORT static AcGeMatrix2d scaling(double scaleAll,
												const AcGePoint2d& center = AcGePoint2d::kOrigin);
	GE_DLLEXPIMPORT AcGeMatrix2d& setCoordSystem(const AcGePoint2d& origin, const AcGeVector2d& e0,
												 const AcGeVector2d& e1);
	GE_DLLEXPIMPORT AcGeMatrix2d& setToAlignCoordSys(
			const AcGePoint2d& fromOrigin, const AcGeVector2d& fromE0, const AcGeVector2d& fromE1,
			const AcGePoint2d& toOrigin, const AcGeVector2d& toE0, const AcGeVector2d& toE1);
	GE_DLLEXPIMPORT AcGeMatrix2d& setToIdentity();
	GE_DLLEXPIMPORT AcGeMatrix2d& setToMirroring(const AcGePoint2d& pnt);
	GE_DLLEXPIMPORT AcGeMatrix2d& setToMirroring(const AcGeLine2d& line);
	GE_DLLEXPIMPORT AcGeMatrix2d& setToProduct(const AcGeMatrix2d& mat1, const AcGeMatrix2d& mat2);
	GE_DLLEXPIMPORT AcGeMatrix2d& setToRotation(double angle,
												const AcGePoint2d& center = AcGePoint2d::kOrigin);
	GE_DLLEXPIMPORT AcGeMatrix2d& setToScaling(double scaleAll,
											   const AcGePoint2d& center = AcGePoint2d::kOrigin);
	GE_DLLEXPIMPORT AcGeMatrix2d& setToTranslation(const AcGeVector2d& vec);
	GE_DLLEXPIMPORT AcGeMatrix2d& setTranslation(const AcGeVector2d& vec);
	GE_DLLEXPIMPORT static AcGeMatrix2d translation(const AcGeVector2d& vec);
	GE_DLLEXPIMPORT AcGeVector2d translation() const;
	GE_DLLEXPIMPORT AcGeMatrix2d transpose() const;
	GE_DLLEXPIMPORT AcGeMatrix2d& transposeIt();
};

#include "icarx/IcArxPackPop.h"

inline bool AcGeMatrix2d::operator==(const AcGeMatrix2d& otherMatrix) const
{
	return this->isEqualTo(otherMatrix);
}

inline bool AcGeMatrix2d::operator!=(const AcGeMatrix2d& otherMatrix) const
{
	return !this->isEqualTo(otherMatrix);
}

inline double AcGeMatrix2d::operator()(unsigned int row, unsigned int column) const
{
	return entry[row][column];
}

inline double& AcGeMatrix2d::operator()(unsigned int row, unsigned int column)
{
	return entry[row][column];
}

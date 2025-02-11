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
***     Description: Declaration of AcGeScale3d class
***
*****************************************************************************/
#pragma once

#include "adesk.h"
#include "gegbl.h"

class AcGeMatrix3d;

#include "icarx/IcArxPackPush.h"

class AcGeScale3d
{
public:
	double sx;
	double sy;
	double sz;

	GE_DLLDATAEXIMP static const AcGeScale3d kIdentity;

public:
	GE_DLLEXPIMPORT AcGeScale3d();
	GE_DLLEXPIMPORT AcGeScale3d(double factor);
	GE_DLLEXPIMPORT AcGeScale3d(double xFact, double yFact, double zFact);
	GE_DLLEXPIMPORT AcGeScale3d(const AcGeScale3d&);
	~AcGeScale3d() = default;
	AcGeScale3d& operator=(const AcGeScale3d&) = default;
	GE_DLLEXPIMPORT bool operator==(const AcGeScale3d&) const;
	GE_DLLEXPIMPORT bool operator!=(const AcGeScale3d&) const;
	GE_DLLEXPIMPORT AcGeScale3d operator*(const AcGeScale3d&) const;
	GE_DLLEXPIMPORT AcGeScale3d operator*(double) const;
	GE_DLLEXPIMPORT friend AcGeScale3d operator*(double, const AcGeScale3d&);
	GE_DLLEXPIMPORT AcGeScale3d& operator*=(const AcGeScale3d&);
	GE_DLLEXPIMPORT AcGeScale3d& operator*=(double);
	GE_DLLEXPIMPORT double operator[](unsigned int) const;
	GE_DLLEXPIMPORT double& operator[](unsigned int);
	GE_DLLEXPIMPORT operator AcGeMatrix3d() const;

	GE_DLLEXPIMPORT AcGeScale3d& extractScale(const AcGeMatrix3d& mat);
	GE_DLLEXPIMPORT void getMatrix(AcGeMatrix3d& mat) const;
	GE_DLLEXPIMPORT AcGeScale3d inverse() const;
	GE_DLLEXPIMPORT AcGeScale3d& invert();
	GE_DLLEXPIMPORT bool isEqualTo(const AcGeScale3d& scaleVec,
								   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isProportional(const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT AcGeScale3d& postMultBy(const AcGeScale3d& rightSide);
	GE_DLLEXPIMPORT AcGeScale3d& preMultBy(const AcGeScale3d& leftSide);
	GE_DLLEXPIMPORT AcGeScale3d& removeScale(AcGeMatrix3d& mat);
	GE_DLLEXPIMPORT AcGeScale3d& set(double sc0, double sc1, double sc2);
	GE_DLLEXPIMPORT AcGeScale3d& setToProduct(const AcGeScale3d& sclVec1,
											  const AcGeScale3d& sclVec2);
	GE_DLLEXPIMPORT AcGeScale3d& setToProduct(const AcGeScale3d& sclVec, double s);
};

#include "icarx/IcArxPackPop.h"

inline bool AcGeScale3d::operator==(const AcGeScale3d& s) const
{
	return this->isEqualTo(s);
}

inline bool AcGeScale3d::operator!=(const AcGeScale3d& s) const
{
	return !(this->isEqualTo(s));
}

inline double AcGeScale3d::operator[](unsigned int i) const
{
	return *(&sx + i);
}

inline double& AcGeScale3d::operator[](unsigned int i)
{
	return *(&sx + i);
}

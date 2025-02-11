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
***     Description: Declaration of AcGeScale2d class
***
*****************************************************************************/
#pragma once

#include "adesk.h"
#include "gegbl.h"

class AcGeMatrix2d;
class AcGeScale3d;

#include "icarx/IcArxPackPush.h"

class AcGeScale2d
{
public:
	double sx;
	double sy;

	GE_DLLDATAEXIMP static const AcGeScale2d kIdentity;

public:
	GE_DLLEXPIMPORT AcGeScale2d();
	GE_DLLEXPIMPORT AcGeScale2d(double factor);
	GE_DLLEXPIMPORT AcGeScale2d(double xFactor, double yFactor);
	GE_DLLEXPIMPORT AcGeScale2d(const AcGeScale2d&);
	~AcGeScale2d() = default;
	AcGeScale2d& operator=(const AcGeScale2d&) = default;
	GE_DLLEXPIMPORT bool operator==(const AcGeScale2d&) const;
	GE_DLLEXPIMPORT bool operator!=(const AcGeScale2d&) const;
	GE_DLLEXPIMPORT AcGeScale2d operator*(const AcGeScale2d&) const;
	GE_DLLEXPIMPORT AcGeScale2d operator*(double) const;
	GE_DLLEXPIMPORT friend AcGeScale2d operator*(double, const AcGeScale2d&);
	GE_DLLEXPIMPORT AcGeScale2d& operator*=(const AcGeScale2d&);
	GE_DLLEXPIMPORT AcGeScale2d& operator*=(double);
	GE_DLLEXPIMPORT double operator[](unsigned int) const;
	GE_DLLEXPIMPORT double& operator[](unsigned int);
	GE_DLLEXPIMPORT operator AcGeMatrix2d() const;
	GE_DLLEXPIMPORT operator AcGeScale3d() const;

	GE_DLLEXPIMPORT AcGeScale2d& extractScale(const AcGeMatrix2d& mat);
	GE_DLLEXPIMPORT void getMatrix(AcGeMatrix2d& mat) const;
	GE_DLLEXPIMPORT AcGeScale2d inverse() const;
	GE_DLLEXPIMPORT AcGeScale2d& invert();
	GE_DLLEXPIMPORT bool isEqualTo(const AcGeScale2d& scaleVec,
								   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isProportional(const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT AcGeScale2d& postMultBy(const AcGeScale2d& rightSide);
	GE_DLLEXPIMPORT AcGeScale2d& preMultBy(const AcGeScale2d& leftSide);
	GE_DLLEXPIMPORT AcGeScale2d& removeScale(AcGeMatrix2d& mat);
	GE_DLLEXPIMPORT AcGeScale2d& set(double sc0, double sc1);
	GE_DLLEXPIMPORT AcGeScale2d& setToProduct(const AcGeScale2d& sclVec1,
											  const AcGeScale2d& sclVec2);
	GE_DLLEXPIMPORT AcGeScale2d& setToProduct(const AcGeScale2d& sclVec, double s);
};

#include "icarx/IcArxPackPop.h"

inline bool AcGeScale2d::operator==(const AcGeScale2d& s) const
{
	return this->isEqualTo(s);
}

inline bool AcGeScale2d::operator!=(const AcGeScale2d& s) const
{
	return !this->isEqualTo(s);
}

inline double AcGeScale2d::operator[](unsigned int i) const
{
	return *(&sx + i);
}

inline double& AcGeScale2d::operator[](unsigned int i)
{
	return *(&sx + i);
}

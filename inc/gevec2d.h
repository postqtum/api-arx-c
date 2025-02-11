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
***     Description: Declaration of AcGeVector2d class
***
*****************************************************************************/
#pragma once

#include "adesk.h"
#include "gegbl.h"
#include "gegblabb.h"

class AcGeMatrix2d;

#include "icarx/IcArxPackPush.h"

class AcGeVector2d
{
public:
	double x = 0.0;
	double y = 0.0;

	GE_DLLDATAEXIMP static const AcGeVector2d kIdentity;
	GE_DLLDATAEXIMP static const AcGeVector2d kXAxis;
	GE_DLLDATAEXIMP static const AcGeVector2d kYAxis;

public:
	GE_DLLEXPIMPORT AcGeVector2d();
	GE_DLLEXPIMPORT AcGeVector2d(double x, double y);
	GE_DLLEXPIMPORT AcGeVector2d(const AcGeVector2d&);
	~AcGeVector2d() = default;
	AcGeVector2d& operator=(const AcGeVector2d&) = default;
	GE_DLLEXPIMPORT bool operator==(const AcGeVector2d&) const;
	GE_DLLEXPIMPORT bool operator!=(const AcGeVector2d&) const;
	GE_DLLEXPIMPORT AcGeVector2d operator+(const AcGeVector2d&) const;
	GE_DLLEXPIMPORT AcGeVector2d& operator+=(const AcGeVector2d&);
	GE_DLLEXPIMPORT AcGeVector2d operator-() const;
	GE_DLLEXPIMPORT AcGeVector2d operator-(const AcGeVector2d&) const;
	GE_DLLEXPIMPORT AcGeVector2d& operator-=(const AcGeVector2d&);
	GE_DLLEXPIMPORT AcGeVector2d operator*(double) const;
	GE_DLLEXPIMPORT friend AcGeVector2d operator*(const AcGeMatrix2d&, const AcGeVector2d&);
	GE_DLLEXPIMPORT friend AcGeVector2d operator*(double, const AcGeVector2d&);
	GE_DLLEXPIMPORT AcGeVector2d& operator*=(double);
	GE_DLLEXPIMPORT AcGeVector2d operator/(double) const;
	GE_DLLEXPIMPORT AcGeVector2d& operator/=(double);
	GE_DLLEXPIMPORT double operator[](unsigned int) const;
	GE_DLLEXPIMPORT double& operator[](unsigned int);
	GE_DLLEXPIMPORT operator AcGeMatrix2d() const;

	GE_DLLEXPIMPORT double angle() const;
	GE_DLLEXPIMPORT double angleTo(const AcGeVector2d& vec) const;
	GE_DLLEXPIMPORT double dotProduct(const AcGeVector2d& vec) const;
	GE_DLLEXPIMPORT bool isCodirectionalTo(const AcGeVector2d& vec, const AcGeTol& tol,
										   AcGeError& flag) const;
	GE_DLLEXPIMPORT bool isCodirectionalTo(const AcGeVector2d& vec,
										   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isEqualTo(const AcGeVector2d& vec,
								   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isParallelTo(const AcGeVector2d& vec,
									  const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isParallelTo(const AcGeVector2d& vec, const AcGeTol& tol,
									  AcGeError& flag) const;
	GE_DLLEXPIMPORT bool isPerpendicularTo(const AcGeVector2d& vec,
										   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isPerpendicularTo(const AcGeVector2d& vec, const AcGeTol& tol,
										   AcGeError& flag) const;
	GE_DLLEXPIMPORT bool isUnitLength(const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isZeroLength(const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT double length() const;
	GE_DLLEXPIMPORT double lengthSqrd() const;
	GE_DLLEXPIMPORT AcGeVector2d& mirror(const AcGeVector2d& line);
	GE_DLLEXPIMPORT AcGeVector2d& negate();
	GE_DLLEXPIMPORT AcGeVector2d normal(const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT AcGeVector2d& normalize(const AcGeTol& tol = AcGeContext::gTol);
	GE_DLLEXPIMPORT AcGeVector2d& normalize(const AcGeTol& tol, AcGeError& flag);
	GE_DLLEXPIMPORT AcGeVector2d perpVector() const;
	GE_DLLEXPIMPORT AcGeVector2d& rotateBy(double angle);
	GE_DLLEXPIMPORT AcGeVector2d& set(double x, double y);
	GE_DLLEXPIMPORT AcGeVector2d& setToProduct(const AcGeMatrix2d& mat, const AcGeVector2d& vec);
	GE_DLLEXPIMPORT AcGeVector2d& setToProduct(const AcGeVector2d& vec, double scl);
	GE_DLLEXPIMPORT AcGeVector2d& setToSum(const AcGeVector2d& vec1, const AcGeVector2d& vec2);
	GE_DLLEXPIMPORT AcGeVector2d& transformBy(const AcGeMatrix2d& leftSide);
};

#include "icarx/IcArxPackPop.h"

inline AcGeVector2d::AcGeVector2d()
{
}

inline AcGeVector2d::AcGeVector2d(double xx, double yy) : x(xx), y(yy)
{
}

inline AcGeVector2d::AcGeVector2d(const AcGeVector2d& src) : x(src.x), y(src.y)
{
}

inline bool AcGeVector2d::operator==(const AcGeVector2d& v) const
{
	return this->isEqualTo(v);
}

inline bool AcGeVector2d::operator!=(const AcGeVector2d& v) const
{
	return !this->isEqualTo(v);
}

inline AcGeVector2d AcGeVector2d::operator+(const AcGeVector2d& v) const
{
	return AcGeVector2d(x + v.x, y + v.y);
}

inline AcGeVector2d& AcGeVector2d::operator+=(const AcGeVector2d& v)
{
	x += v.x;
	y += v.y;
	return *this;
}

inline AcGeVector2d AcGeVector2d::operator-() const
{
	return AcGeVector2d(-x, -y);
}

inline AcGeVector2d AcGeVector2d::operator-(const AcGeVector2d& v) const
{
	return AcGeVector2d(x - v.x, y - v.y);
}

inline AcGeVector2d& AcGeVector2d::operator-=(const AcGeVector2d& v)
{
	x -= v.x;
	y -= v.y;
	return *this;
}

inline AcGeVector2d AcGeVector2d::operator*(double s) const
{
	return AcGeVector2d(x * s, y * s);
}

inline AcGeVector2d& AcGeVector2d::operator*=(double s)
{
	x *= s;
	y *= s;
	return *this;
}

inline AcGeVector2d AcGeVector2d::operator/(double val) const
{
	return AcGeVector2d(x / val, y / val);
}

inline AcGeVector2d& AcGeVector2d::operator/=(double val)
{
	x /= val;
	y /= val;
	return *this;
}

inline double AcGeVector2d::operator[](unsigned int i) const
{
	return *(&x + i);
}

inline double& AcGeVector2d::operator[](unsigned int i)
{
	return *(&x + i);
}

inline double AcGeVector2d::dotProduct(const AcGeVector2d& v) const
{
	return x * v.x + y * v.y;
}

inline double AcGeVector2d::lengthSqrd() const
{
	return x * x + y * y;
}

inline AcGeVector2d& AcGeVector2d::negate()
{
	x = -x;
	y = -y;
	return *this;
}

inline AcGeVector2d AcGeVector2d::perpVector() const
{
	return AcGeVector2d(-y, x);
}

inline AcGeVector2d& AcGeVector2d::set(double xx, double yy)
{
	x = xx;
	y = yy;
	return *this;
}

inline AcGeVector2d& AcGeVector2d::setToProduct(const AcGeVector2d& v, double s)
{
	x = s * v.x;
	y = s * v.y;
	return *this;
}

inline AcGeVector2d& AcGeVector2d::setToSum(const AcGeVector2d& v1, const AcGeVector2d& v2)
{
	x = v1.x + v2.x;
	y = v1.y + v2.y;
	return *this;
}

#define ADSK_ACGEVECTOR2D_DEFINED
#include "acarrayhelper.h"

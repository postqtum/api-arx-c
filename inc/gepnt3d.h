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
***     Description: Declaration of AcGePoint3d class
***
*****************************************************************************/
#pragma once

#include "gevec3d.h"

class AcGeMatrix3d;
class AcGeLinearEnt3d;
class AcGePlane;
class AcGePlanarEnt;
class AcGeVector3d;
class AcGePoint2d;

#include "icarx/IcArxPackPush.h"

class AcGePoint3d
{
public:
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;

	GE_DLLDATAEXIMP static const AcGePoint3d kOrigin;

public:
	GE_DLLEXPIMPORT AcGePoint3d();
	GE_DLLEXPIMPORT AcGePoint3d(double x, double y, double z);
	GE_DLLEXPIMPORT AcGePoint3d(const AcGePlanarEnt& pln, const AcGePoint2d& pnt2d);
	GE_DLLEXPIMPORT AcGePoint3d(const AcGePoint3d&);
	~AcGePoint3d() = default;
	AcGePoint3d& operator=(const AcGePoint3d&) = default;
	GE_DLLEXPIMPORT bool operator==(const AcGePoint3d&) const;
	GE_DLLEXPIMPORT bool operator!=(const AcGePoint3d&) const;
	GE_DLLEXPIMPORT AcGePoint3d operator+(const AcGeVector3d&) const;
	GE_DLLEXPIMPORT AcGePoint3d& operator+=(const AcGeVector3d&);
	GE_DLLEXPIMPORT AcGeVector3d operator-(const AcGePoint3d&) const;
	GE_DLLEXPIMPORT AcGePoint3d operator-(const AcGeVector3d&) const;
	GE_DLLEXPIMPORT AcGePoint3d& operator-=(const AcGeVector3d&);
	GE_DLLEXPIMPORT AcGePoint3d operator*(double) const;
	GE_DLLEXPIMPORT friend AcGePoint3d operator*(const AcGeMatrix3d&, const AcGePoint3d&);
	GE_DLLEXPIMPORT friend AcGePoint3d operator*(double, const AcGePoint3d&);
	GE_DLLEXPIMPORT AcGePoint3d& operator*=(double);
	GE_DLLEXPIMPORT AcGePoint3d operator/(double) const;
	GE_DLLEXPIMPORT AcGePoint3d& operator/=(double);
	GE_DLLEXPIMPORT double operator[](unsigned int) const;
	GE_DLLEXPIMPORT double& operator[](unsigned int);

	GE_DLLEXPIMPORT AcGeVector3d asVector() const;
	GE_DLLEXPIMPORT AcGePoint2d convert2d(const AcGePlanarEnt& pln) const;
	GE_DLLEXPIMPORT double distanceTo(const AcGePoint3d& pnt) const;
	GE_DLLEXPIMPORT bool isEqualTo(const AcGePoint3d& pnt,
								   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT AcGePoint3d& mirror(const AcGePlane& pln);
	GE_DLLEXPIMPORT AcGePoint3d orthoProject(const AcGePlane& pln) const;
	GE_DLLEXPIMPORT AcGePoint3d project(const AcGePlane& pln, const AcGeVector3d& vec) const;
	GE_DLLEXPIMPORT AcGePoint3d& rotateBy(double angle, const AcGeVector3d& vec,
										  const AcGePoint3d& wrtPoint = AcGePoint3d::kOrigin);
	GE_DLLEXPIMPORT AcGePoint3d& scaleBy(double scaleFactor,
										 const AcGePoint3d& wrtPoint = AcGePoint3d::kOrigin);
	GE_DLLEXPIMPORT AcGePoint3d& set(double x, double y, double z);
	GE_DLLEXPIMPORT AcGePoint3d& set(const AcGePlanarEnt& pln, const AcGePoint2d& pnt);
	GE_DLLEXPIMPORT AcGePoint3d& setToProduct(const AcGeMatrix3d& mat, const AcGePoint3d& pnt);
	GE_DLLEXPIMPORT AcGePoint3d& setToSum(const AcGePoint3d& pnt, const AcGeVector3d& vec);
	GE_DLLEXPIMPORT AcGePoint3d& transformBy(const AcGeMatrix3d& leftSide);
};

#include "icarx/IcArxPackPop.h"

inline AcGePoint3d::AcGePoint3d()
{
}

inline AcGePoint3d::AcGePoint3d(double xx, double yy, double zz) : x(xx), y(yy), z(zz)
{
}

inline AcGePoint3d::AcGePoint3d(const AcGePoint3d& src) : x(src.x), y(src.y), z(src.z)
{
}

inline bool AcGePoint3d::operator==(const AcGePoint3d& p) const
{
	return this->isEqualTo(p);
}

inline bool AcGePoint3d::operator!=(const AcGePoint3d& p) const
{
	return !this->isEqualTo(p);
}

inline AcGePoint3d AcGePoint3d::operator+(const AcGeVector3d& v) const
{
	return AcGePoint3d(x + v.x, y + v.y, z + v.z);
}

inline AcGePoint3d& AcGePoint3d::operator+=(const AcGeVector3d& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

inline AcGePoint3d AcGePoint3d::operator-(const AcGeVector3d& v) const
{
	return AcGePoint3d(x - v.x, y - v.y, z - v.z);
}

inline AcGeVector3d AcGePoint3d::operator-(const AcGePoint3d& p) const
{
	return AcGeVector3d(x - p.x, y - p.y, z - p.z);
}

inline AcGePoint3d& AcGePoint3d::operator-=(const AcGeVector3d& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

inline AcGePoint3d AcGePoint3d::operator*(double val) const
{
	return AcGePoint3d(x * val, y * val, z * val);
}

inline AcGePoint3d operator*(double val, const AcGePoint3d& p)
{
	return AcGePoint3d(p.x * val, p.y * val, p.z * val);
}

inline AcGePoint3d& AcGePoint3d::operator*=(double val)
{
	x *= val;
	y *= val;
	z *= val;
	return *this;
}

inline AcGePoint3d AcGePoint3d::operator/(double val) const
{
	return AcGePoint3d(x / val, y / val, z / val);
}

inline AcGePoint3d& AcGePoint3d::operator/=(double val)
{
	x /= val;
	y /= val;
	z /= val;
	return *this;
}

inline double AcGePoint3d::operator[](unsigned int i) const
{
	return *(&x + i);
}

inline double& AcGePoint3d::operator[](unsigned int i)
{
	return *(&x + i);
}

inline AcGeVector3d AcGePoint3d::asVector() const
{
	return AcGeVector3d(x, y, z);
}

inline AcGePoint3d& AcGePoint3d::set(double xx, double yy, double zz)
{
	x = xx;
	y = yy;
	z = zz;
	return *this;
}

#define ADSK_ACGEPOINT3D_DEFINED
#include "acarrayhelper.h"

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
***     Description: Declaration of AcGeKnotVector class
***
*****************************************************************************/
#pragma once

#include "gegbl.h"
#include "gedblar.h"

#include "icarx/IcArxAssert.h"

class AcGeInterval;

#include "icarx/IcArxPackPush.h"

class AcGeKnotVector
{
protected:
	AcGeDoubleArray mData;
	double mTolerance;

public:
	GE_DLLDATAEXIMP static double globalKnotTolerance;

protected:
	bool isValid(int) const;

public:
	GE_DLLEXPIMPORT AcGeKnotVector(double eps = globalKnotTolerance);
	GE_DLLEXPIMPORT AcGeKnotVector(int size, int growSize, double eps = globalKnotTolerance);
	GE_DLLEXPIMPORT AcGeKnotVector(int size, const double[], double eps = globalKnotTolerance);
	GE_DLLEXPIMPORT AcGeKnotVector(int plusMult, const AcGeKnotVector& src);
	GE_DLLEXPIMPORT AcGeKnotVector(const AcGeDoubleArray& src, double eps = globalKnotTolerance);
	GE_DLLEXPIMPORT AcGeKnotVector(const AcGeKnotVector&);
	GE_DLLEXPIMPORT ~AcGeKnotVector();
	GE_DLLEXPIMPORT AcGeKnotVector& operator=(const AcGeKnotVector&);
	GE_DLLEXPIMPORT AcGeKnotVector& operator=(const AcGeDoubleArray&);
	GE_DLLEXPIMPORT double& operator[](int);
	GE_DLLEXPIMPORT const double operator[](int) const;

	GE_DLLEXPIMPORT AcGeKnotVector& append(AcGeKnotVector& tail, double knotRatio = 0.);
	GE_DLLEXPIMPORT int append(double val);
	GE_DLLEXPIMPORT const double* asArrayPtr() const;
	GE_DLLEXPIMPORT double* asArrayPtr();
	GE_DLLEXPIMPORT bool contains(double param) const;
	GE_DLLEXPIMPORT double endParam() const;
	GE_DLLEXPIMPORT void getDistinctKnots(AcGeDoubleArray& knots) const;
	GE_DLLEXPIMPORT int getInterval(int ord, double par, AcGeInterval& interval) const;
	GE_DLLEXPIMPORT int growLength() const;
	GE_DLLEXPIMPORT AcGeKnotVector& insert(double u);
	GE_DLLEXPIMPORT AcGeKnotVector& insertAt(int indx, double u, int multiplicity = 1);
	GE_DLLEXPIMPORT bool isEmpty() const;
	GE_DLLEXPIMPORT bool isEqualTo(const AcGeKnotVector& other) const;
	GE_DLLEXPIMPORT bool isOn(double knot) const;
	GE_DLLEXPIMPORT int length() const;
	GE_DLLEXPIMPORT int logicalLength() const;
	GE_DLLEXPIMPORT int multiplicityAt(int i) const;
	GE_DLLEXPIMPORT int multiplicityAt(double param) const;
	GE_DLLEXPIMPORT int numIntervals() const;
	GE_DLLEXPIMPORT int physicalLength() const;
	GE_DLLEXPIMPORT AcGeKnotVector& removeAt(int);
	GE_DLLEXPIMPORT AcGeKnotVector& removeSubVector(int startIndex, int endIndex);
	GE_DLLEXPIMPORT AcGeKnotVector& reverse();
	GE_DLLEXPIMPORT AcGeKnotVector& set(int size, const double[], double eps = globalKnotTolerance);
	GE_DLLEXPIMPORT AcGeKnotVector& setGrowLength(int);
	GE_DLLEXPIMPORT AcGeKnotVector& setLogicalLength(int);
	GE_DLLEXPIMPORT AcGeKnotVector& setPhysicalLength(int);
	GE_DLLEXPIMPORT AcGeKnotVector& setRange(double lower, double upper);
	GE_DLLEXPIMPORT AcGeKnotVector& setTolerance(double tol);
	GE_DLLEXPIMPORT int split(double par, AcGeKnotVector* pKnot1, int multLast,
							  AcGeKnotVector* pKnot2, int multFirst) const;
	GE_DLLEXPIMPORT double startParam() const;
	GE_DLLEXPIMPORT double tolerance() const;
};

#include "icarx/IcArxPackPop.h"

inline double& AcGeKnotVector::operator[](int i)
{
	ICARX_ASSERT(isValid(i));
	return mData[i];
}

inline const double AcGeKnotVector::operator[](int i) const
{
	ICARX_ASSERT(isValid(i));
	return mData[i];
}

inline const double* AcGeKnotVector::asArrayPtr() const
{
	return mData.asArrayPtr();
}

inline double* AcGeKnotVector::asArrayPtr()
{
	return mData.asArrayPtr();
}

inline bool AcGeKnotVector::isValid(int i) const
{
	return 0 <= i && i < mData.logicalLength();
}

inline AcGeKnotVector& AcGeKnotVector::setTolerance(double eps)
{
	mTolerance = eps;
	return *this;
}

inline double AcGeKnotVector::tolerance() const
{
	return mTolerance;
}

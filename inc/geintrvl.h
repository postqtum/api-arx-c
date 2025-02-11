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
***     Description: Declaration of AcGeInterval class
***
*****************************************************************************/
#pragma once

#include "gegbl.h"

#include "icarx/IcArxPackPush.h"

class AcGeInterval
{
	friend class AcGeImpInterval;

protected:
	class AcGeImpInterval* mpImpInt;

private:
	int mDelInt;

protected:
	GE_DLLEXPIMPORT AcGeInterval(AcGeImpInterval&, int);

public:
	GE_DLLEXPIMPORT AcGeInterval(double tol = 1.e-12);
	GE_DLLEXPIMPORT AcGeInterval(double lower, double upper, double tol = 1.e-12);
	GE_DLLEXPIMPORT AcGeInterval(bool boundedBelow, double bound, double tol = 1.e-12);
	GE_DLLEXPIMPORT AcGeInterval(const AcGeInterval&);
	GE_DLLEXPIMPORT ~AcGeInterval();
	GE_DLLEXPIMPORT AcGeInterval& operator=(const AcGeInterval&);
	GE_DLLEXPIMPORT bool operator==(const AcGeInterval&) const;
	GE_DLLEXPIMPORT bool operator!=(const AcGeInterval&) const;
	GE_DLLEXPIMPORT bool operator<(double) const;
	GE_DLLEXPIMPORT bool operator<(const AcGeInterval&) const;
	GE_DLLEXPIMPORT friend bool operator<(double, const AcGeInterval&);
	GE_DLLEXPIMPORT bool operator<=(double) const;
	GE_DLLEXPIMPORT bool operator<=(const AcGeInterval&) const;
	GE_DLLEXPIMPORT friend bool operator<=(double, const AcGeInterval&);
	GE_DLLEXPIMPORT bool operator>(double) const;
	GE_DLLEXPIMPORT bool operator>(const AcGeInterval&) const;
	GE_DLLEXPIMPORT friend bool operator>(double, const AcGeInterval&);
	GE_DLLEXPIMPORT bool operator>=(double) const;
	GE_DLLEXPIMPORT bool operator>=(const AcGeInterval&) const;
	GE_DLLEXPIMPORT friend bool operator>=(double, const AcGeInterval&);

	GE_DLLEXPIMPORT bool contains(const AcGeInterval& otherInterval) const;
	GE_DLLEXPIMPORT bool contains(double val) const;
	GE_DLLEXPIMPORT double element() const;
	GE_DLLEXPIMPORT void getBounds(double& lower, double& upper) const;
	GE_DLLEXPIMPORT void getMerge(const AcGeInterval& otherInterval, AcGeInterval& result) const;
	GE_DLLEXPIMPORT bool intersectWith(const AcGeInterval& otherInterval,
									   AcGeInterval& result) const;
	GE_DLLEXPIMPORT bool isBounded() const;
	GE_DLLEXPIMPORT bool isBoundedAbove() const;
	GE_DLLEXPIMPORT bool isBoundedBelow() const;
	GE_DLLEXPIMPORT bool isContinuousAtUpper(const AcGeInterval& otherInterval) const;
	GE_DLLEXPIMPORT bool isDisjoint(const AcGeInterval& otherInterval) const;
	GE_DLLEXPIMPORT bool isEqualAtLower(const AcGeInterval& otherInterval) const;
	GE_DLLEXPIMPORT bool isEqualAtLower(double value) const;
	GE_DLLEXPIMPORT bool isEqualAtUpper(const AcGeInterval& otherInterval) const;
	GE_DLLEXPIMPORT bool isEqualAtUpper(double value) const;
	GE_DLLEXPIMPORT bool isOverlapAtUpper(const AcGeInterval& otherInterval,
										  AcGeInterval& overlap) const;
	GE_DLLEXPIMPORT bool isPeriodicallyOn(double period, double& val);
	GE_DLLEXPIMPORT bool isSingleton() const;
	GE_DLLEXPIMPORT bool isUnBounded() const;
	GE_DLLEXPIMPORT double length() const;
	GE_DLLEXPIMPORT double lowerBound() const;
	GE_DLLEXPIMPORT AcGeInterval& set(double lower, double upper);
	GE_DLLEXPIMPORT AcGeInterval& set(bool boundedBelow, double bound);
	GE_DLLEXPIMPORT AcGeInterval& set();
	GE_DLLEXPIMPORT AcGeInterval& setLower(double lower);
	GE_DLLEXPIMPORT AcGeInterval& setTolerance(double tol);
	GE_DLLEXPIMPORT AcGeInterval& setUpper(double upper);
	GE_DLLEXPIMPORT int subtract(const AcGeInterval& otherInterval, AcGeInterval& lInterval,
								 AcGeInterval& rInterval) const;
	GE_DLLEXPIMPORT double tolerance() const;
	GE_DLLEXPIMPORT double upperBound() const;
};

#include "icarx/IcArxPackPop.h"

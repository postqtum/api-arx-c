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
***     Description: Declaration of AcGeTol class
***
*****************************************************************************/
#pragma once

#include <cstdlib>
#include "gedll.h"
#include "gedblar.h"

#include "icarx/IcArxPackPush.h"

class AcGeTol
{
	friend class AcGeTolA;

private:
	double mTolArr[5];
	int mAbs;

public:
	GE_DLLEXPIMPORT AcGeTol();

	GE_DLLEXPIMPORT double equalPoint() const;
	GE_DLLEXPIMPORT double equalVector() const;

	GE_DLLEXPIMPORT void setEqualPoint(double val);
	GE_DLLEXPIMPORT void setEqualVector(double val);

};

#include "icarx/IcArxPackPop.h"

inline void AcGeTol::setEqualVector(double val)
{
	mTolArr[1] = val;
}

inline double AcGeTol::equalVector() const
{
	return mTolArr[1];
}

inline void AcGeTol::setEqualPoint(double val)
{
	mTolArr[0] = val;
}

inline double AcGeTol::equalPoint() const
{
	return mTolArr[0];
}

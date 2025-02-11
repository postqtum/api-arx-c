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
***     Description: Declaration of AcGsDCPoint class
***
*****************************************************************************/
#pragma once

#define SCALAR_MIN (-2147483647 - 1)
#define SCALAR_MAX 2147483647

#include "IcArxPackPush.h"

class AcGsDCPoint
{
public:
	enum MaxFlag
	{
		Maximum
	};
	enum MinFlag
	{
		Minimum
	};

public:
	long x;
	long y;

public:
	AcGsDCPoint() = default;
	AcGsDCPoint(long xin, long yin) : x(xin), y(yin) {}
	AcGsDCPoint(MaxFlag)
	{
		x = SCALAR_MAX;
		y = SCALAR_MAX;
	}
	AcGsDCPoint(MinFlag)
	{
		x = SCALAR_MIN;
		y = SCALAR_MIN;
	}
	void operator=(const AcGsDCPoint& r)
	{
		x = r.x;
		y = r.y;
	}
	void operator=(MaxFlag)
	{
		x = SCALAR_MAX;
		y = SCALAR_MAX;
	}
	void operator=(MinFlag)
	{
		x = SCALAR_MIN;
		y = SCALAR_MIN;
	}
	bool operator==(const AcGsDCPoint& r) const { return x == r.x && y == r.y; }
	bool operator!=(const AcGsDCPoint& r) const { return x != r.x || y != r.y; }
};

#include "IcArxPackPop.h"

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
***     Description: Declaration of AcGiColorRGBA class
***
*****************************************************************************/
#pragma once

#include "IcArxPackPush.h"

class AcGiColorRGBA
{
public:
	double red = 0.0;
	double green = 0.0;
	double blue = 0.0;
	double alpha = 1.0;

public:
	AcGiColorRGBA() = default;
	AcGiColorRGBA(double r, double g, double b, double a) : red(r), green(g), blue(b), alpha(a) {}
};

#include "IcArxPackPop.h"

inline AcGiColorRGBA operator*(const AcGiColorRGBA& c1, const AcGiColorRGBA& c2)
{
	return AcGiColorRGBA(c1.red * c2.red, c1.green * c2.green, c1.blue * c2.blue,
						 c1.alpha * c2.alpha);
}

inline AcGiColorRGBA operator*(const AcGiColorRGBA& c, double s)
{
	return AcGiColorRGBA(s * c.red, s * c.green, s * c.blue, s * c.alpha);
}

inline AcGiColorRGBA operator*(double s, const AcGiColorRGBA& c)
{
	return c * s;
}

inline AcGiColorRGBA operator+(const AcGiColorRGBA& c1, const AcGiColorRGBA& c2)
{
	return AcGiColorRGBA(c1.red + c2.red, c1.green + c2.green, c1.blue + c2.blue,
						 c1.alpha + c2.alpha);
}

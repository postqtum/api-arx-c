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
***     Description: Declaration of AcGiColorRGB class
***
*****************************************************************************/
#pragma once

#include "IcArxPackPush.h"

class AcGiColorRGB
{
public:
	double red = 0.0;
	double green = 0.0;
	double blue = 0.0;

public:
	AcGiColorRGB() = default;
	AcGiColorRGB(double r, double g, double b) : red(r), green(g), blue(b) {}
};

#include "IcArxPackPop.h"

inline AcGiColorRGB operator*(const AcGiColorRGB& c1, const AcGiColorRGB& c2)
{
	return AcGiColorRGB(c1.red * c2.red, c1.green * c2.green, c1.blue * c2.blue);
}

inline AcGiColorRGB operator*(const AcGiColorRGB& c, double s)
{
	return AcGiColorRGB(s * c.red, s * c.green, s * c.blue);
}

inline AcGiColorRGB operator*(double s, const AcGiColorRGB& c)
{
	return c * s;
}

inline AcGiColorRGB operator+(const AcGiColorRGB& c1, const AcGiColorRGB& c2)
{
	return AcGiColorRGB(c1.red + c2.red, c1.green + c2.green, c1.blue + c2.blue);
}

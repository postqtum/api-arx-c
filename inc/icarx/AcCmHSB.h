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
***     Description: Declaration of AcCmHSB class
***
*****************************************************************************/
#pragma once

#include <cstdint>

#include "../AcDbCore2dDefs.h"
#include "../acadstrc.h"

#include "IcArxPackPush.h"

class AcCmHSB
{
private:
	uint32_t mHSB = 0;

public:
	ACDBCORE2D_PORT AcCmHSB() = default;
	ACDBCORE2D_PORT AcCmHSB(uint16_t hue, uint8_t saturation, uint8_t brightness);
	ACDBCORE2D_PORT AcCmHSB(const AcCmHSB&) = default;
	ACDBCORE2D_PORT virtual ~AcCmHSB() = default;
	ACDBCORE2D_PORT AcCmHSB& operator=(const AcCmHSB&) = default;
	ACDBCORE2D_PORT bool operator==(const AcCmHSB&) const;
	ACDBCORE2D_PORT bool operator!=(const AcCmHSB&) const;

	ACDBCORE2D_PORT virtual uint8_t brightness() const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus hsbToRGB(uint8_t* r, uint8_t* g, uint8_t* b);
	ACDBCORE2D_PORT virtual uint16_t hue() const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus rgbToHSB(uint8_t r, uint8_t g, uint8_t b);
	ACDBCORE2D_PORT virtual uint8_t saturation() const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setBrightness(uint8_t brightness);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setBrightness(double brightness);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setHSB(uint32_t value);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setHSB(uint16_t hue, uint8_t saturation,
													 uint8_t brightness);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setHSB(double hue, double saturation,
													 double brightness);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setHue(uint16_t hue);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setHue(double hue);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setSaturation(uint8_t saturation);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setSaturation(double saturation);
	ACDBCORE2D_PORT virtual uint32_t value() const;
};

#include "IcArxPackPop.h"

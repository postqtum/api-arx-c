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
***     Description: Declaration of AcCmColorBase class
***
*****************************************************************************/
#pragma once

#include "../adesk.h"
#include "AcCmEntityColor.h"

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcCmColorBase
{
public:
	virtual ~AcCmColorBase() = default;

	virtual uint8_t blue() const = 0;
	virtual const ACHAR* bookName(void) const = 0;
	virtual uint32_t color() const = 0;
	virtual uint16_t colorIndex() const = 0;
	virtual AcCmEntityColor::ColorMethod colorMethod() const = 0;
	virtual const ACHAR* colorName(void) const = 0;
	virtual const ACHAR* colorNameForDisplay(void) = 0;
	virtual IcArx::Integers::ColorRef getCOLORREF() const = 0;
	virtual IcArx::Integers::RGBQuad getRGB() const = 0;
	virtual uint32_t getRGBM() const = 0;
	virtual uint8_t green() const = 0;
	virtual bool hasBookName(void) const = 0;
	virtual bool hasColorName(void) const = 0;
	virtual bool isByACI() const = 0;
	virtual bool isByBlock() const = 0;
	virtual bool isByColor() const = 0;
	virtual bool isByLayer() const = 0;
	virtual bool isByPen() const = 0;
	virtual bool isForeground() const = 0;
	virtual uint16_t penIndex() const = 0;
	virtual uint8_t red() const = 0;
	virtual Acad::ErrorStatus setBlue(uint8_t blue) = 0;
	virtual void setByBlock() = 0;
	virtual void setByLayer() = 0;
	virtual Acad::ErrorStatus setCOLORREF(IcArx::Integers::ColorRef cref) = 0;
	virtual Acad::ErrorStatus setColor(uint32_t color) = 0;
	virtual Acad::ErrorStatus setColorIndex(uint16_t colorIndex) = 0;
	virtual Acad::ErrorStatus setColorMethod(AcCmEntityColor::ColorMethod eColorMethod) = 0;
	virtual void setForeground() = 0;
	virtual Acad::ErrorStatus setGreen(uint8_t green) = 0;
	virtual void setLayerOff() = 0;
	virtual Acad::ErrorStatus setNames(const ACHAR* colorName, const ACHAR* bookName = nullptr) = 0;
	virtual void setNone() = 0;
	virtual Acad::ErrorStatus setPenIndex(uint16_t penIndex) = 0;
	virtual Acad::ErrorStatus setRGB(uint8_t red, uint8_t green, uint8_t blue) = 0;
	virtual Acad::ErrorStatus setRGB(IcArx::Integers::RGBQuad rgbquad) = 0;
	virtual Acad::ErrorStatus setRGBM(uint32_t rgbmValue) = 0;
	virtual Acad::ErrorStatus setRed(uint8_t red) = 0;
};

#include "IcArxPackPop.h"

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
***     Description: Declaration of AcCmEntityColor class
***
*****************************************************************************/
#pragma once

#include "../acadstrc.h"
#include "../AcDbCore2dDefs.h"

#include "IcArxIntegers.h"
#include <vector>

#include "IcArxPackPush.h"

class AcCmEntityColor
{
public:
	enum ACIcolorMethod
	{
		kACIbyBlock = 0,
		kACIforeground = 7,
		kACIbyLayer = 256,
		kACIclear = 0,
		kACIstandard = 7,
		kACImaximum = 255,
		kACInone = 257,
		kACIminimum = -255,
		kACIfrozenLayer = -32700
	};

	enum Color
	{
		kRed,
		kGreen,
		kBlue
	};

	enum ColorMethod
	{
		kByLayer = 0xC0,
		kByBlock,
		kByColor,
		kByACI,
		kByPen,
		kForeground,
		kLayerOff,
		kLayerFrozen,
		kNone
	};

private:
	union
	{
		uint32_t whole;
		int16_t indirect;
		struct
		{
			uint8_t blue, green, red, colorMethod;
		} mdata;
		int32_t mnIndirect32;
	} mRGBM;

public:
	ACDBCORE2D_PORT AcCmEntityColor();
	ACDBCORE2D_PORT AcCmEntityColor(const AcCmEntityColor& color);
	ACDBCORE2D_PORT AcCmEntityColor(ColorMethod eColorMethod);
	ACDBCORE2D_PORT AcCmEntityColor(uint8_t red, uint8_t green, uint8_t blue);
	ACDBCORE2D_PORT ~AcCmEntityColor() = default;
	ACDBCORE2D_PORT AcCmEntityColor& operator=(const AcCmEntityColor& color);
	ACDBCORE2D_PORT bool operator==(const AcCmEntityColor& color) const;
	ACDBCORE2D_PORT bool operator!=(const AcCmEntityColor& color) const;

	static AcCmEntityColor ByBlock()
	{
		AcCmEntityColor ec;
		ec.setByBlock();
		return ec;
	}
	static AcCmEntityColor ByLayer()
	{
		AcCmEntityColor ec;
		ec.setByLayer();
		return ec;
	}
	static AcCmEntityColor Foreground()
	{
		AcCmEntityColor ec;
		ec.setForeground();
		return ec;
	}
	static AcCmEntityColor None()
	{
		AcCmEntityColor ec;
		ec.setNone();
		return ec;
	}
	static AcCmEntityColor black() { return AcCmEntityColor(0, 0, 0); }
	ACDBCORE2D_PORT uint8_t blue() const;
	ACDBCORE2D_PORT bool canResolveRGB() const;
	ACDBCORE2D_PORT uint32_t color() const;
	ACDBCORE2D_PORT int16_t colorIndex() const;
	ACDBCORE2D_PORT ColorMethod colorMethod() const;
	ACDBCORE2D_PORT AcCmEntityColor forceRGB(IcArx::Integers::ColorRef background_rgb = 0) const;
	ACDBCORE2D_PORT IcArx::Integers::ColorRef getCOLORREF() const;
	ACDBCORE2D_PORT IcArx::Integers::RGBQuad getRGB() const;
	ACDBCORE2D_PORT uint32_t getRGBM() const;
	ACDBCORE2D_PORT uint8_t green() const;
	ACDBCORE2D_PORT bool isByACI() const;
	ACDBCORE2D_PORT bool isByBlock() const;
	ACDBCORE2D_PORT bool isByColor() const;
	ACDBCORE2D_PORT bool isByLayer() const;
	ACDBCORE2D_PORT bool isByPen() const;
	ACDBCORE2D_PORT bool isForeground() const;
	ACDBCORE2D_PORT bool isLayerFrozen() const;
	ACDBCORE2D_PORT bool isLayerFrozenOrOff() const;
	ACDBCORE2D_PORT bool isLayerOff() const;
	ACDBCORE2D_PORT bool isNone() const;
	ACDBCORE2D_PORT int32_t layerIndex() const;
	ACDBCORE2D_PORT static uint8_t lookUpACI(uint8_t red, uint8_t green, uint8_t blue);
	ACDBCORE2D_PORT static uint32_t lookUpRGB(uint8_t colorIndex);
	ACDBCORE2D_PORT AcCmEntityColor makeRGB(IcArx::Integers::ColorRef background_rgb = 0) const;
	ACDBCORE2D_PORT AcCmEntityColor makeTrueColor() const;
	ACDBCORE2D_PORT uint16_t penIndex() const;
	ACDBCORE2D_PORT uint8_t red() const;
	ACDBCORE2D_PORT Acad::ErrorStatus setBlue(uint8_t blue);
	void setByBlock()
	{
		mRGBM.whole = 0;
		mRGBM.mdata.colorMethod = kByBlock;
	}
	void setByLayer()
	{
		mRGBM.whole = 0;
		mRGBM.mdata.colorMethod = kByLayer;
	}
	ACDBCORE2D_PORT Acad::ErrorStatus setCOLORREF(IcArx::Integers::ColorRef cref);
	ACDBCORE2D_PORT Acad::ErrorStatus setColor(uint32_t color);
	ACDBCORE2D_PORT Acad::ErrorStatus setColorIndex(int16_t colorIndex);
	ACDBCORE2D_PORT Acad::ErrorStatus setColorMethod(ColorMethod eColorMethod);
	void setForeground()
	{
		mRGBM.whole = 0;
		mRGBM.mdata.colorMethod = kForeground;
	}
	ACDBCORE2D_PORT Acad::ErrorStatus setGreen(uint8_t green);
	ACDBCORE2D_PORT Acad::ErrorStatus setLayerIndex(int32_t layerIndex);
	ACDBCORE2D_PORT void setLayerOff();
	void setNone()
	{
		mRGBM.whole = 0;
		mRGBM.mdata.colorMethod = kNone;
	}
	ACDBCORE2D_PORT Acad::ErrorStatus setPenIndex(uint16_t penIndex);
	ACDBCORE2D_PORT Acad::ErrorStatus setRGB(uint8_t red, uint8_t green, uint8_t blue);
	ACDBCORE2D_PORT Acad::ErrorStatus setRGB(IcArx::Integers::RGBQuad rgbquad);
	ACDBCORE2D_PORT Acad::ErrorStatus setRGBM(uint32_t rgbmValue);
	ACDBCORE2D_PORT Acad::ErrorStatus setRed(uint8_t red);
	ACDBCORE2D_PORT Acad::ErrorStatus setTrueColor();
	ACDBCORE2D_PORT Acad::ErrorStatus setTrueColorMethod();
	ACDBCORE2D_PORT uint32_t trueColor() const;
	ACDBCORE2D_PORT uint8_t trueColorMethod() const;
	static AcCmEntityColor white() { return AcCmEntityColor(255, 255, 255); }
};

#include "IcArxPackPop.h"

class AcDbObjectId;

ACDBCORE2D_PORT AcCmEntityColor
accmResolveEffectiveColorToRGB(const AcCmEntityColor& effectiveColor, AcDbObjectId entLayerId);

ACDBCORE2D_PORT AcCmEntityColor accmAttenuateRGB(const AcCmEntityColor& in);

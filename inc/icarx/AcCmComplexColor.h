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
***     Description: Declaration of AcCmComplexColor class
***
*****************************************************************************/
#pragma once

#include "acut_str_util.h"
#include "AcCmEntityColor.h"
#include "../AcString.h"
#include "../AcDbCore2dDefs.h"

#include "AcDbXObject.h"

#include "IcArxPackPush.h"

class AcCmComplexColor : public AcDbXObject
{
private:
	uint16_t refCount = 0;
	AcCmEntityColor mColor;

public:
	ACRX_DECLARE_MEMBERS(AcCmComplexColor);

	Acad::ErrorStatus audit(AcDbAuditInfo* pAuditInfo) override;
	virtual uint8_t blue() const;
	ACDBCORE2D_PORT virtual uint32_t color() const;
	virtual uint16_t colorIndex() const;
	virtual AcCmEntityColor::ColorMethod colorMethod() const;
	Acad::ErrorStatus copyFrom(const AcRxObject*) override;
	virtual void decReference();
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	virtual Acad::ErrorStatus getDescription(AcString& desc) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getDescription(ACHAR*& desc) const final;
	virtual Acad::ErrorStatus getExplanation(AcString& expl) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getExplanation(ACHAR*& expl) const final;
	uint32_t getRGB() const;
	uint32_t getRGBM() const;
	virtual uint8_t green() const;
	virtual AcCmComplexColor* incReference();
	virtual bool isByACI() const;
	virtual bool isByBlock() const;
	virtual bool isByColor() const;
	virtual bool isByLayer() const;
	virtual bool isByPen() const;
	virtual bool isForeground() const;
	virtual uint16_t penIndex() const;
	virtual uint8_t red() const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setBlue(uint8_t blue);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setColor(uint32_t color);
	virtual Acad::ErrorStatus setColorIndex(uint16_t colorIndex);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setColorMethod(
			AcCmEntityColor::ColorMethod eColorMethod);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setGreen(uint8_t green);
	virtual Acad::ErrorStatus setPenIndex(uint16_t penIndex);
	virtual Acad::ErrorStatus setRGB(uint8_t red, uint8_t green, uint8_t blue);
	Acad::ErrorStatus setRGB(uint32_t rgbValue);
	Acad::ErrorStatus setRGBM(uint32_t rgbmValue);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setRed(uint8_t red);
};

#include "IcArxPackPop.h"

inline Acad::ErrorStatus AcCmComplexColor::getDescription(ACHAR*& desc) const
{
	return ::acutGetAcStringConvertToAChar(this, &AcCmComplexColor::getDescription, desc);
}

inline Acad::ErrorStatus AcCmComplexColor::getExplanation(ACHAR*& expl) const
{
	return ::acutGetAcStringConvertToAChar(this, &AcCmComplexColor::getExplanation, expl);
}

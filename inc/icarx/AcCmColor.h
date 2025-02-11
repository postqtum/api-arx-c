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
***     Description: Declaration of AcCmColor class
***
*****************************************************************************/
#pragma once

#include "../dbcolor.h"
#include "../AcString.h"
#include "acut_str_util.h"
#include "AcDbEnumMode.h"

class AcDbDwgFiler;
class AcDbDxfFiler;
class AcDbAuditInfo;
class AcCmColorImp;

#include "IcArxPackPush.h"

class AcCmColor : public AcCmColorBase
{
	friend class AcCmColorImp;

public:
	static const uint16_t MaxColorIndex;

private:
	AcCmColorImp* m_Imp;

public:
	ACDBCORE2D_PORT AcCmColor();
	ACDBCORE2D_PORT AcCmColor(const AcCmColor&);
	ACDBCORE2D_PORT AcCmColor(const AcCmEntityColor&);
	ACDBCORE2D_PORT AcCmColor(const AcCmColorBase&);
	ACDBCORE2D_PORT ~AcCmColor();
	ACDBCORE2D_PORT AcCmColor& operator=(const AcCmColor&);
	ACDBCORE2D_PORT AcCmColor& operator=(const AcCmColorBase&);
	ACDBCORE2D_PORT AcCmColor& operator=(const AcCmEntityColor&);
	ACDBCORE2D_PORT bool operator==(const AcCmColor&) const;
	ACDBCORE2D_PORT bool operator==(const AcCmColorBase&) const;
	ACDBCORE2D_PORT bool operator!=(const AcCmColor&) const;
	ACDBCORE2D_PORT bool operator!=(const AcCmColorBase&) const;

	Acad::ErrorStatus audit(AcDbAuditInfo* pAuditInfo);
	ACDBCORE2D_PORT uint8_t blue() const override;
	const ACHAR* bookName() const override;
	ACDBCORE2D_PORT uint32_t color() const override;
	uint16_t colorIndex() const override;
	ACDBCORE2D_PORT AcCmEntityColor::ColorMethod colorMethod() const override;
	const ACHAR* colorName() const override;
	const ACHAR* colorNameForDisplay() override;
	int dictionaryKeyLength() const;
	Acad::ErrorStatus dwgIn(AcDbDwgFiler* pInputFiler);
	Acad::ErrorStatus dwgInAsTrueColor(AcDbDwgFiler* pInputFiler);
	Acad::ErrorStatus dwgOut(AcDbDwgFiler* pOutputFiler) const;
	Acad::ErrorStatus dwgOutAsTrueColor(AcDbDwgFiler* pOutputFiler) const;
	Acad::ErrorStatus dxfIn(AcDbDxfFiler* pFiler, int groupCodeOffset = 0);
	Acad::ErrorStatus dxfOut(AcDbDxfFiler* pFiler, int groupCodeOffset = 0) const;
	AcCmEntityColor entityColor() const;
	ACDBCORE2D_PORT IcArx::Integers::ColorRef getCOLORREF() const override;
	ACDBCORE2D_PORT Acad::ErrorStatus getDescription(AcString& desc) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getDescription(ACHAR*& desc) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getDictionaryKey(AcString& sKey) const;
	Acad::ErrorStatus getDictionaryKey(ACHAR* pKey, size_t nLen) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getExplanation(AcString& expl) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getExplanation(ACHAR*& expl) const;
	ACDBCORE2D_PORT IcArx::Integers::RGBQuad getRGB() const override;
	ACDBCORE2D_PORT uint32_t getRGBM() const override;
	ACDBCORE2D_PORT uint8_t green() const override;
	bool hasBookName() const override;
	bool hasColorName() const override;
	bool isByACI() const override;
	bool isByBlock() const override;
	bool isByColor() const override;
	bool isByLayer() const override;
	bool isByPen() const override;
	bool isForeground() const override;
	bool isNone() const;
	uint16_t penIndex() const override;
	ACDBCORE2D_PORT uint8_t red() const override;
	Acad::ErrorStatus serializeIn(const void* pBuff, int* pBuflen);
	Acad::ErrorStatus serializeOut(void* pBuff, int* pBuflen,
								   AcDb::AcDbDwgVersion ver = AcDb::kDHL_CURRENT) const;
	ACDBCORE2D_PORT Acad::ErrorStatus setBlue(uint8_t blue) override;
	ACDBCORE2D_PORT void setByBlock() override;
	ACDBCORE2D_PORT void setByLayer() override;
	ACDBCORE2D_PORT Acad::ErrorStatus setCOLORREF(IcArx::Integers::ColorRef cref) override;
	ACDBCORE2D_PORT Acad::ErrorStatus setColor(uint32_t color) override;
	ACDBCORE2D_PORT Acad::ErrorStatus setColorIndex(uint16_t colorIndex) override;
	ACDBCORE2D_PORT Acad::ErrorStatus setColorMethod(AcCmEntityColor::ColorMethod eColorMethod) override;
	ACDBCORE2D_PORT void setForeground() override;
	ACDBCORE2D_PORT Acad::ErrorStatus setGreen(uint8_t green) override;
	ACDBCORE2D_PORT void setLayerOff() override;
	Acad::ErrorStatus setNames(const ACHAR* colorName, const ACHAR* bookName = nullptr) override;
	Acad::ErrorStatus setNamesFromDictionaryKey(const ACHAR* pKey);
	ACDBCORE2D_PORT void setNone() override;
	Acad::ErrorStatus setPenIndex(uint16_t penIndex) override;
	Acad::ErrorStatus setRGB(uint8_t red, uint8_t green, uint8_t blue) override;
	ACDBCORE2D_PORT Acad::ErrorStatus setRGB(IcArx::Integers::RGBQuad rgbquad) override;
	ACDBCORE2D_PORT Acad::ErrorStatus setRGBM(uint32_t rgbmValue) override;
	ACDBCORE2D_PORT Acad::ErrorStatus setRed(uint8_t red) override;
};

#include "IcArxPackPop.h"

inline Acad::ErrorStatus AcCmColor::getDescription(ACHAR*& desc) const
{
	return ::acutGetAcStringConvertToAChar(this, &AcCmColor::getDescription, desc);
}

inline Acad::ErrorStatus AcCmColor::getExplanation(ACHAR*& expl) const
{
	return ::acutGetAcStringConvertToAChar(this, &AcCmColor::getExplanation, expl);
}

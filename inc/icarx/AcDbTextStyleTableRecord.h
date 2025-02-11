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
***     Description: Declaration of AcDbTextStyleTableRecord class
***
*****************************************************************************/
#pragma once

#include "acut_str_util.h"
#include "AcDbSymbolTableRecord.h"

#include "../PAL/api/charset.h"
#include "../PAL/api/FontPitchAndFamily.h"

class AcDbTextStyleTable;

#include "IcArxPackPush.h"

class AcDbTextStyleTableRecord : public AcDbSymbolTableRecord
{
public:
	using TableType = AcDbTextStyleTable;

protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbTextStyleTableRecord);

	AcDbTextStyleTableRecord();
	~AcDbTextStyleTableRecord();

	ACDBCORE2D_PORT Acad::ErrorStatus bigFontFileName(AcString& sFileName) const;
	Acad::ErrorStatus bigFontFileName(ACHAR*& fileName) const;
	Acad::ErrorStatus bigFontFileName(const ACHAR*& fileName) const;
	AcGiDrawable* drawable() override;
	ACDBCORE2D_PORT Acad::ErrorStatus fileName(AcString& sFileName) const;
	Acad::ErrorStatus fileName(ACHAR*& fileName) const;
	Acad::ErrorStatus fileName(const ACHAR*& fileName) const;
	uint8_t flagBits() const;
	ACDBCORE2D_PORT Acad::ErrorStatus font(
			AcString& sTypeface, bool& bold, bool& italic, Charset& charset,
			Autodesk::AutoCAD::PAL::FontUtils::FontPitch& pitch,
			Autodesk::AutoCAD::PAL::FontUtils::FontFamily& family) const;
	Acad::ErrorStatus font(ACHAR*& pTypeface, bool& bold, bool& italic, Charset& charset,
						   Autodesk::AutoCAD::PAL::FontUtils::FontPitch& pitch,
						   Autodesk::AutoCAD::PAL::FontUtils::FontFamily& family) const;
	bool isShapeFile() const;
	bool isVertical() const;
	double obliquingAngle() const;
	double priorSize() const;
	Acad::ErrorStatus setBigFontFileName(const ACHAR* fileName);
	Acad::ErrorStatus setFileName(const ACHAR* fileName);
	void setFlagBits(uint8_t flagBits);
	ACDBCORE2D_PORT Acad::ErrorStatus setFont(const ACHAR* pTypeface, bool bold, bool italic,
											  Charset charset,
											  Autodesk::AutoCAD::PAL::FontUtils::FontPitch pitch,
											  Autodesk::AutoCAD::PAL::FontUtils::FontFamily family,
											  bool bAllowMissingFont = false);
	void setIsShapeFile(bool shape);
	void setIsVertical(bool vertical);
	Acad::ErrorStatus setObliquingAngle(double obliquingAngle);
	Acad::ErrorStatus setPriorSize(double priorSize);
	Acad::ErrorStatus setTextSize(double size);
	Acad::ErrorStatus setXScale(double xScale);
	double textSize() const;
	double xScale() const;
};

#include "IcArxPackPop.h"

inline Acad::ErrorStatus AcDbTextStyleTableRecord::bigFontFileName(ACHAR*& fileName) const
{
	return ::acutGetAcStringConvertToAChar(this, &AcDbTextStyleTableRecord::bigFontFileName,
										   fileName);
}
inline Acad::ErrorStatus AcDbTextStyleTableRecord::fileName(ACHAR*& fileName) const
{
	return ::acutGetAcStringConvertToAChar(this, &AcDbTextStyleTableRecord::fileName, fileName);
}
inline Acad::ErrorStatus AcDbTextStyleTableRecord::font(
		ACHAR*& pTypeface, bool& bold, bool& italic, Charset& charset,
		Autodesk::AutoCAD::PAL::FontUtils::FontPitch& pitch,
		Autodesk::AutoCAD::PAL::FontUtils::FontFamily& family) const
{
	pTypeface = nullptr;
	AcString sTypeface;
	const Acad::ErrorStatus es = this->font(sTypeface, bold, italic, charset, pitch, family);
	if (es == Acad::eOk)
		::acutNewString(sTypeface.kwszPtr(), pTypeface);
	return es;
}

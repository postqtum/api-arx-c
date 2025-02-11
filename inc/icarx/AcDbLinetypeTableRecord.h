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
***     Description: Declaration of AcDbLinetypeTableRecord class
***
*****************************************************************************/
#pragma once

#include "acut_str_util.h"
#include "AcDbSymbolTableRecord.h"
#include "../gevec2d.h"

class AcDbLinetypeTable;

#include "IcArxPackPush.h"

class AcDbLinetypeTableRecord : public AcDbSymbolTableRecord
{
public:
	using TableType = AcDbLinetypeTable;

protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbLinetypeTableRecord);

	AcDbLinetypeTableRecord();
	~AcDbLinetypeTableRecord();

	Acad::ErrorStatus asciiDescription(ACHAR*& pString) const { return comments(pString); }
	Acad::ErrorStatus asciiDescription(const ACHAR*& pString) const { return comments(pString); }
	Acad::ErrorStatus comments(ACHAR*& pString) const;
	Acad::ErrorStatus comments(const ACHAR*& pString) const;
	ACDBCORE2D_PORT Acad::ErrorStatus comments(AcString& sComments) const;
	double dashLengthAt(int index) const;
	AcGiDrawable* drawable() override;
	bool isScaledToFit() const;
	int numDashes() const;
	double patternLength() const;
	Acad::ErrorStatus setAsciiDescription(const ACHAR* pString) { return setComments(pString); }
	Acad::ErrorStatus setComments(const ACHAR* pString);
	ACDBCORE2D_PORT Acad::ErrorStatus setDashLengthAt(int index, double value);
	void setIsScaledToFit(bool scaledToFit);
	ACDBCORE2D_PORT Acad::ErrorStatus setNumDashes(int count);
	ACDBCORE2D_PORT Acad::ErrorStatus setPatternLength(double patternLength);
	ACDBCORE2D_PORT Acad::ErrorStatus setShapeIsUcsOrientedAt(int index, bool isUcsOriented);
	ACDBCORE2D_PORT Acad::ErrorStatus setShapeIsUprightAt(int index, bool isUpright);
	ACDBCORE2D_PORT Acad::ErrorStatus setShapeNumberAt(int index, int shapeNumber);
	ACDBCORE2D_PORT Acad::ErrorStatus setShapeOffsetAt(int index, const AcGeVector2d& offset);
	ACDBCORE2D_PORT Acad::ErrorStatus setShapeRotationAt(int index, double rotation);
	ACDBCORE2D_PORT Acad::ErrorStatus setShapeScaleAt(int index, double scale);
	ACDBCORE2D_PORT Acad::ErrorStatus setShapeStyleAt(int index, AcDbObjectId id);
	Acad::ErrorStatus setTextAt(int index, const ACHAR* text);
	bool shapeIsUcsOrientedAt(int index) const;
	bool shapeIsUprightAt(int index) const;
	int shapeNumberAt(int index) const;
	AcGeVector2d shapeOffsetAt(int index) const;
	double shapeRotationAt(int index) const;
	double shapeScaleAt(int index) const;
	AcDbObjectId shapeStyleAt(int index) const;
	ACDBCORE2D_PORT Acad::ErrorStatus textAt(int index, AcString& sText) const;
	Acad::ErrorStatus textAt(int index, ACHAR*& text) const;
	Acad::ErrorStatus textAt(int index, const ACHAR*& text) const;
};

#include "IcArxPackPop.h"

inline Acad::ErrorStatus AcDbLinetypeTableRecord::comments(ACHAR*& pComments) const
{
	return ::acutGetAcStringConvertToAChar(this, &AcDbLinetypeTableRecord::comments, pComments);
}
inline Acad::ErrorStatus AcDbLinetypeTableRecord::textAt(int nIndex, ACHAR*& pText) const
{
	AcString sText;
	return ::acutAcStringToAChar(sText, pText, this->textAt(nIndex, sText));
}

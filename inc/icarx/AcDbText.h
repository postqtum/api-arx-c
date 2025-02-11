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
***     Description: Declaration of AcDbText class
***
*****************************************************************************/
#pragma once

#include "AcDbEntity.h"
#include "AcDbEnumGeom.h"
#include "../gepnt3d.h"

#include "IcArxPackPush.h"

class AcDbText : public AcDbEntity
{
public:
	enum AcTextAlignment
	{
		kTextAlignmentLeft = 0,
		kTextAlignmentCenter = (kTextAlignmentLeft + 1),
		kTextAlignmentRight = (kTextAlignmentCenter + 1),
		kTextAlignmentAligned = (kTextAlignmentRight + 1),
		kTextAlignmentMiddle = (kTextAlignmentAligned + 1),
		kTextAlignmentFit = (kTextAlignmentMiddle + 1),
		kTextAlignmentTopLeft = (kTextAlignmentFit + 1),
		kTextAlignmentTopCenter = (kTextAlignmentTopLeft + 1),
		kTextAlignmentTopRight = (kTextAlignmentTopCenter + 1),
		kTextAlignmentMiddleLeft = (kTextAlignmentTopRight + 1),
		kTextAlignmentMiddleCenter = (kTextAlignmentMiddleLeft + 1),
		kTextAlignmentMiddleRight = (kTextAlignmentMiddleCenter + 1),
		kTextAlignmentBottomLeft = (kTextAlignmentMiddleRight + 1),
		kTextAlignmentBottomCenter = (kTextAlignmentBottomLeft + 1),
		kTextAlignmentBottomRight = (kTextAlignmentBottomCenter + 1)
	};

protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbText);

	AcDbText();
	AcDbText(const AcGePoint3d& position, const ACHAR* text,
			 AcDbObjectId style = AcDbObjectId::kNull, double height = 0, double rotation = 0);
	~AcDbText();

	virtual Acad::ErrorStatus adjustAlignment(const AcDbDatabase* pDb = nullptr);
	AcGePoint3d alignmentPoint() const;
	Acad::ErrorStatus convertFieldToText();
	int correctSpelling();
	ACDBCORE2D_PORT void getBoundingPoints(AcGePoint3dArray& arr) const;
	Acad::ErrorStatus getPlane(AcGePlane&, AcDb::Planarity&) const override;
	double height() const;
	ACDBCORE2D_PORT bool hitTest(const AcGePoint3d& ptHit) const;
	AcDb::TextHorzMode horizontalMode() const;
	bool isDefaultAlignment() const;
	bool isMirroredInX() const;
	bool isMirroredInY() const;
	bool isPlanar() const override { return true; }
	ACDBCORE2D_PORT AcTextAlignment justification() const;
	Acad::ErrorStatus mirrorInX(bool);
	Acad::ErrorStatus mirrorInY(bool);
	AcGeVector3d normal() const;
	double oblique() const;
	AcGePoint3d position() const;
	Acad::ErrorStatus removeField(AcDbObjectId fieldId) override;
	Acad::ErrorStatus removeField(const ACHAR* pszPropName, AcDbObjectId& returnId) override;
	Acad::ErrorStatus removeField(const ACHAR* pszPropName) override;
	double rotation() const;
	Acad::ErrorStatus setAlignmentPoint(const AcGePoint3d&);
	Acad::ErrorStatus setField(const ACHAR* pszPropName, AcDbField* pField,
							   AcDbObjectId& fieldId) override;
	Acad::ErrorStatus setHeight(double);
	Acad::ErrorStatus setHorizontalMode(AcDb::TextHorzMode);
	ACDBCORE2D_PORT Acad::ErrorStatus setJustification(AcTextAlignment);
	Acad::ErrorStatus setNormal(const AcGeVector3d&);
	Acad::ErrorStatus setOblique(double);
	Acad::ErrorStatus setPosition(const AcGePoint3d&);
	Acad::ErrorStatus setRotation(double);
	Acad::ErrorStatus setTextString(const ACHAR*);
	Acad::ErrorStatus setTextStyle(AcDbObjectId);
	Acad::ErrorStatus setThickness(double);
	Acad::ErrorStatus setVerticalMode(AcDb::TextVertMode);
	Acad::ErrorStatus setWidthFactor(double);
	ACDBCORE2D_PORT Acad::ErrorStatus textString(AcString& sText) const;
	ACHAR* textString() const;
	const ACHAR* textStringConst() const;
	AcDbObjectId textStyle() const;
	double thickness() const;
	AcDb::TextVertMode verticalMode() const;
	double widthFactor() const;
};

#include "IcArxPackPop.h"

inline ACHAR* AcDbText::textString() const
{
	return ::acutGetAcStringConvertToAChar(this, &AcDbText::textString);
}

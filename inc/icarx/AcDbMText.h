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
***     Description: Declaration of AcDbMText class
***
*****************************************************************************/
#pragma once

#include "../dbmain.h"

#include "AcDbMTextFragment.h"

typedef int (*AcDbMTextEnum)(AcDbMTextFragment*, void*);

#include "IcArxPackPush.h"

class AcDbMText : public AcDbEntity
{
public:
	enum AttachmentPoint
	{
		kTopLeft = 1,
		kTopCenter = 2,
		kTopRight = 3,
		kMiddleLeft = 4,
		kMiddleCenter = 5,
		kMiddleRight = 6,
		kBottomLeft = 7,
		kBottomCenter = 8,
		kBottomRight = 9,
		kBaseLeft = 10,
		kBaseCenter = 11,
		kBaseRight = 12,
		kBaseAlign = 13,
		kBottomAlign = 14,
		kMiddleAlign = 15,
		kTopAlign = 16,
		kBaseFit = 17,
		kBottomFit = 18,
		kMiddleFit = 19,
		kTopFit = 20,
		kBaseMid = 21,
		kBottomMid = 22,
		kMiddleMid = 23,
		kTopMid = 24,
	};

	enum ColumnType
	{
		kNoColumns,
		kStaticColumns,
		kDynamicColumns,
	};

	enum FlowDirection
	{
		kLtoR = 1,
		kRtoL = 2,
		kTtoB = 3,
		kBtoT = 4,
		kByStyle = 5
	};

protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbMText);

	AcDbMText();
	~AcDbMText();

	double actualHeight(AcGiWorldDraw* ctxt = nullptr) const;
	double actualWidth() const;
	static const ACHAR* const alignChange();
	double ascent() const;
	AttachmentPoint attachment() const;
	bool backgroundFillOn() const;
	static const ACHAR* const blockBegin();
	static const ACHAR* const blockEnd();
	static const ACHAR* const colorChange();
	ACDBCORE2D_PORT Acad::ErrorStatus contents(AcString& sContents) const;
	ACHAR* contents() const;
	ACDBCORE2D_PORT Acad::ErrorStatus contentsRTF(AcString& sContentsRTF) const;
	ACHAR* contentsRTF() const;
	Acad::ErrorStatus convertFieldToText();
	int correctSpelling();
	double descent() const;
	AcGeVector3d direction() const;
	void explodeFragments(AcDbMTextEnum, void*, AcGiWorldDraw* ctxt = nullptr) const;
	FlowDirection flowDirection() const;
	static const ACHAR* const fontChange();
	Acad::ErrorStatus getBackgroundFillColor(AcCmColor& color) const;
	Acad::ErrorStatus getBackgroundScaleFactor(double& scale) const;
	Acad::ErrorStatus getBackgroundTransparency(AcCmTransparency& transp) const;
	void getBoundingPoints(AcGePoint3dArray&) const;
	ACDBCORE2D_PORT void getBoundingPointsByLine(AcArray<AcGePoint3dArray>&) const;
	Acad::ErrorStatus getColumnAutoHeight(bool&) const;
	Acad::ErrorStatus getColumnCount(int&) const;
	Acad::ErrorStatus getColumnFlowReversed(bool&) const;
	Acad::ErrorStatus getColumnGutterWidth(double&) const;
	Acad::ErrorStatus getColumnHeight(int, double&) const;
	Acad::ErrorStatus getColumnType(ColumnType&) const;
	Acad::ErrorStatus getColumnWidth(double&) const;
	void getEcs(AcGeMatrix3d& retVal) const override;
	ACDBCORE2D_PORT Acad::ErrorStatus getPlane(AcGePlane& plane,
											   AcDb::Planarity& type) const override;
	double height() const;
	static const ACHAR* const heightChange();
	ACDBCORE2D_PORT bool hitTest(const AcGePoint3d& ptHit) const;
	bool isPlanar() const override { return true; }
	static const ACHAR* const lineBreak();
	double lineSpacingFactor() const;
	AcDb::LineSpacingStyle lineSpacingStyle() const;
	AcGePoint3d location() const;
	static const ACHAR* const nonBreakSpace();
	AcGeVector3d normal() const;
	static const ACHAR* const obliqueChange();
	static const ACHAR* const overlineOff();
	static const ACHAR* const overlineOn();
	static const ACHAR* const paragraphBreak();
	Acad::ErrorStatus removeField(AcDbObjectId fieldId) override;
	Acad::ErrorStatus removeField(const ACHAR* pszPropName, AcDbObjectId& returnId) override;
	Acad::ErrorStatus removeField(const ACHAR* pszPropName) override;
	double rotation() const;
	Acad::ErrorStatus setAttachment(AttachmentPoint);
	Acad::ErrorStatus setAttachmentMovingLocation(AttachmentPoint);
	Acad::ErrorStatus setBackgroundFill(bool enable);
	Acad::ErrorStatus setBackgroundFillColor(const AcCmColor& color);
	Acad::ErrorStatus setBackgroundScaleFactor(const double scale);
	Acad::ErrorStatus setBackgroundTransparency(const AcCmTransparency& transp);
	Acad::ErrorStatus setColumnAutoHeight(bool);
	Acad::ErrorStatus setColumnCount(int);
	Acad::ErrorStatus setColumnFlowReversed(bool);
	Acad::ErrorStatus setColumnGutterWidth(double);
	Acad::ErrorStatus setColumnHeight(int, double);
	Acad::ErrorStatus setColumnType(ColumnType);
	Acad::ErrorStatus setColumnWidth(double);
	int setContents(const ACHAR*);
	int setContentsRTF(const ACHAR* RTFString);
	Acad::ErrorStatus setDirection(const AcGeVector3d&);
	Acad::ErrorStatus setDynamicColumns(double width, double gutter, bool auto_height);
	Acad::ErrorStatus setField(const ACHAR* pszPropName, AcDbField* pField,
							   AcDbObjectId& fieldId) override;
	Acad::ErrorStatus setFlowDirection(FlowDirection);
	Acad::ErrorStatus setHeight(double);
	Acad::ErrorStatus setLineSpacingFactor(double dFactor);
	Acad::ErrorStatus setLineSpacingStyle(AcDb::LineSpacingStyle eStyle);
	Acad::ErrorStatus setLocation(const AcGePoint3d&);
	Acad::ErrorStatus setNormal(const AcGeVector3d&);
	Acad::ErrorStatus setRotation(double);
	ACDBCORE2D_PORT Acad::ErrorStatus setShowBorders(bool enable);
	Acad::ErrorStatus setStaticColumns(double width, double gutter, int count);
	Acad::ErrorStatus setTextHeight(double);
	Acad::ErrorStatus setTextStyle(AcDbObjectId);
	Acad::ErrorStatus setUseBackgroundColor(bool enable);
	Acad::ErrorStatus setUseWordBreak(bool bEnable);
	Acad::ErrorStatus setWidth(double);
	ACDBCORE2D_PORT bool showBorders() const;
	static const ACHAR* const stackStart();
	static const ACHAR* const strikethroughOff();
	static const ACHAR* const strikethroughOn();
	ACDBCORE2D_PORT Acad::ErrorStatus text(AcString& sText) const;
	ACHAR* text() const;
	double textHeight() const;
	AcDbObjectId textStyle() const;
	static const ACHAR* const trackChange();
	static const ACHAR* const underlineOff();
	static const ACHAR* const underlineOn();
	bool useBackgroundColorOn() const;
	bool useWordBreak() const;
	double width() const;
	static const ACHAR* const widthChange();
};

#include "IcArxPackPop.h"

inline ACHAR* AcDbMText::contents() const
{
	return ::acutGetAcStringConvertToAChar(this, &AcDbMText::contents);
}

inline ACHAR* AcDbMText::contentsRTF() const
{
	return ::acutGetAcStringConvertToAChar(this, &AcDbMText::contentsRTF);
}

inline ACHAR* AcDbMText::text() const
{
	return ::acutGetAcStringConvertToAChar(this, &AcDbMText::text);
}

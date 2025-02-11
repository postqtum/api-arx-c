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
***     Description: Declaration of AcDbSectionViewStyle class
***
*****************************************************************************/
#pragma once

#include "dbModelDocViewStyle.h"

#include "icarx/IcArxPackPush.h"

class AcDbSectionViewStyle : public AcDbModelDocViewStyle
{
public:
	enum IdentifierPosition
	{
		kEndCuttingPlane = 0,
		kAboveDirectionArrowLine = 1,
		kAboveDirectionArrowSymbol = 2,
		kStartDirectionArrow = 3,
		kEndDirectionArrow = 4,
	};

	enum ArrowDirection
	{
		kTowardsCuttingPlane = 0,
		kAwayFromCuttingPlane = 1,
	};

protected:
	ACDBCORE2D_PORT Acad::ErrorStatus subDeepClone(AcDbObject* pOwner, AcDbObject*& pClonedObject,
												   AcDbIdMapping& idMap,
												   bool isPrimary = true) const override;
	ACDBCORE2D_PORT Acad::ErrorStatus subWblockClone(
			AcRxObject* pOwner, AcDbObject*& pClonedObject, AcDbIdMapping& idMap,
			bool isPrimary = true) const override;

public:
	ACDBCORE2D_PORT AcDbSectionViewStyle();
	ACDBCORE2D_PORT ~AcDbSectionViewStyle();

	ACDB_DECLARE_MEMBERS_EXPIMP(AcDbSectionViewStyle, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT AcDbObjectId arrowEndSymbolId() const;
	ACDBCORE2D_PORT AcDbSectionViewStyle::ArrowDirection arrowPosition() const;
	ACDBCORE2D_PORT AcDbObjectId arrowStartSymbolId() const;
	ACDBCORE2D_PORT AcCmColor arrowSymbolColor() const;
	ACDBCORE2D_PORT double arrowSymbolExtensionLength() const;
	ACDBCORE2D_PORT double arrowSymbolSize() const;
	ACDBCORE2D_PORT AcCmColor bendLineColor() const;
	ACDBCORE2D_PORT double bendLineLength() const;
	ACDBCORE2D_PORT AcDbObjectId bendLineTypeId() const;
	ACDBCORE2D_PORT AcDb::LineWeight bendLineWeight() const;
	ACDBCORE2D_PORT double endLineLength() const;
	ACDBCORE2D_PORT double endLineOvershoot() const;
	ACDBCORE2D_PORT Acad::ErrorStatus getViewLabelPattern(AcString& pattern,
														  AcDbField* pField = nullptr) const;
	ACDBCORE2D_PORT const AcArray<double>& hatchAngles() const;
	ACDBCORE2D_PORT AcCmColor hatchBackgroundColor() const;
	ACDBCORE2D_PORT AcCmColor hatchColor() const;
	ACDBCORE2D_PORT const ACHAR* hatchPattern() const;
	ACDBCORE2D_PORT double hatchScale() const;
	ACDBCORE2D_PORT AcCmTransparency hatchTransparency() const;
	ACDBCORE2D_PORT AcCmColor identifierColor() const;
	ACDBCORE2D_PORT const ACHAR* identifierExcludeCharacters() const;
	ACDBCORE2D_PORT double identifierHeight() const;
	ACDBCORE2D_PORT AcDbObjectId identifierStyleId() const;
	ACDBCORE2D_PORT bool isContinuousLabeling() const;
	ACDBCORE2D_PORT AcCmColor planeLineColor() const;
	ACDBCORE2D_PORT AcDbObjectId planeLineTypeId() const;
	ACDBCORE2D_PORT AcDb::LineWeight planeLineWeight() const;
	ACDBCORE2D_PORT Acad::ErrorStatus setArrowEndSymbolId(const AcDbObjectId& arrowSymbolId);
	ACDBCORE2D_PORT Acad::ErrorStatus setArrowPosition(AcDbSectionViewStyle::ArrowDirection type);
	ACDBCORE2D_PORT Acad::ErrorStatus setArrowStartSymbolId(const AcDbObjectId& arrowSymbolId);
	ACDBCORE2D_PORT Acad::ErrorStatus setArrowSymbolColor(const AcCmColor& color);
	ACDBCORE2D_PORT Acad::ErrorStatus setArrowSymbolExtensionLength(double length);
	ACDBCORE2D_PORT Acad::ErrorStatus setArrowSymbolSize(double size);
	ACDBCORE2D_PORT Acad::ErrorStatus setBendLineColor(const AcCmColor& color);
	ACDBCORE2D_PORT Acad::ErrorStatus setBendLineLength(double length);
	ACDBCORE2D_PORT Acad::ErrorStatus setBendLineTypeId(const AcDbObjectId& objId);
	ACDBCORE2D_PORT Acad::ErrorStatus setBendLineWeight(AcDb::LineWeight lineweight);
	ACDBCORE2D_PORT Acad::ErrorStatus setContinuousLabeling(bool bValue);
	ACDBCORE2D_PORT Acad::ErrorStatus setEndLineLength(double length);
	ACDBCORE2D_PORT Acad::ErrorStatus setEndLineOvershoot(double length);
	ACDBCORE2D_PORT Acad::ErrorStatus setHatchAngles(const AcArray<double>& angleArray);
	ACDBCORE2D_PORT Acad::ErrorStatus setHatchBackgroundColor(const AcCmColor& color);
	ACDBCORE2D_PORT Acad::ErrorStatus setHatchColor(const AcCmColor& color);
	ACDBCORE2D_PORT Acad::ErrorStatus setHatchPattern(const ACHAR* pattern);
	ACDBCORE2D_PORT Acad::ErrorStatus setHatchScale(double scale);
	ACDBCORE2D_PORT Acad::ErrorStatus setHatchTransparency(const AcCmTransparency& transparency);
	ACDBCORE2D_PORT Acad::ErrorStatus setIdentifierColor(const AcCmColor& color);
	ACDBCORE2D_PORT Acad::ErrorStatus setIdentifierExcludeCharacters(const ACHAR* str);
	ACDBCORE2D_PORT Acad::ErrorStatus setIdentifierHeight(double height);
	ACDBCORE2D_PORT Acad::ErrorStatus setIdentifierStyleId(const AcDbObjectId& objId);
	ACDBCORE2D_PORT Acad::ErrorStatus setPlaneLineColor(const AcCmColor& color);
	ACDBCORE2D_PORT Acad::ErrorStatus setPlaneLineTypeId(const AcDbObjectId& objId);
	ACDBCORE2D_PORT Acad::ErrorStatus setPlaneLineWeight(AcDb::LineWeight lineweight);
	ACDBCORE2D_PORT Acad::ErrorStatus setShowAllBendIndentifiers(bool bValue);
	ACDBCORE2D_PORT Acad::ErrorStatus setShowAllPlaneLines(bool bValue);
	ACDBCORE2D_PORT Acad::ErrorStatus setShowArrowheads(bool bValue);
	ACDBCORE2D_PORT Acad::ErrorStatus setShowEndAndBendLines(bool bValue);
	ACDBCORE2D_PORT Acad::ErrorStatus setShowHatching(bool bValue);
	ACDBCORE2D_PORT Acad::ErrorStatus setShowViewLabel(bool bValue);
	ACDBCORE2D_PORT Acad::ErrorStatus setViewIdentifierOffset(double offset);
	ACDBCORE2D_PORT Acad::ErrorStatus setViewIdentifierPosition(
			AcDbSectionViewStyle::IdentifierPosition type);
	ACDBCORE2D_PORT Acad::ErrorStatus setViewLabelAlignment(
			AcDbModelDocViewStyle::TextAlignment alignment);
	ACDBCORE2D_PORT Acad::ErrorStatus setViewLabelAttachment(
			AcDbModelDocViewStyle::AttachmentPoint attachment);
	ACDBCORE2D_PORT Acad::ErrorStatus setViewLabelOffset(double offset);
	ACDBCORE2D_PORT Acad::ErrorStatus setViewLabelPattern(const ACHAR* pattern,
														  const AcDbField* pField = nullptr);
	ACDBCORE2D_PORT Acad::ErrorStatus setViewLabelTextColor(const AcCmColor& color);
	ACDBCORE2D_PORT Acad::ErrorStatus setViewLabelTextHeight(double height);
	ACDBCORE2D_PORT Acad::ErrorStatus setViewLabelTextStyleId(const AcDbObjectId& objId);
	ACDBCORE2D_PORT bool showAllBendIndentifiers() const;
	ACDBCORE2D_PORT bool showAllPlaneLines() const;
	ACDBCORE2D_PORT bool showArrowheads() const;
	ACDBCORE2D_PORT bool showEndAndBendLines() const;
	ACDBCORE2D_PORT bool showHatching() const;
	ACDBCORE2D_PORT bool showViewLabel() const;
	ACDBCORE2D_PORT static bool validateIdentifierExcludeCharacters(const ACHAR* str);
	ACDBCORE2D_PORT double viewIdentifierOffset() const;
	ACDBCORE2D_PORT AcDbSectionViewStyle::IdentifierPosition viewIdentifierPosition() const;
	ACDBCORE2D_PORT AcDbModelDocViewStyle::TextAlignment viewLabelAlignment() const;
	ACDBCORE2D_PORT AcDbModelDocViewStyle::AttachmentPoint viewLabelAttachment() const;
	ACDBCORE2D_PORT double viewLabelOffset() const;
	ACDBCORE2D_PORT const ACHAR* viewLabelPattern() const;
	ACDBCORE2D_PORT AcCmColor viewLabelTextColor() const;
	ACDBCORE2D_PORT double viewLabelTextHeight() const;
	ACDBCORE2D_PORT AcDbObjectId viewLabelTextStyleId() const;
};

#include "icarx/IcArxPackPop.h"

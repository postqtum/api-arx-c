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
***     Description: Declaration of AcDbDetailViewStyle class
***
*****************************************************************************/
#pragma once

#include "dbModelDocViewStyle.h"

#include "icarx/IcArxPackPush.h"

class AcDbDetailViewStyle : public AcDbModelDocViewStyle
{
public:
	enum IdentifierPlacement
	{
		kOutsideBoundary = 0,
		kOutsideBoundaryWithLeader,
		kOnBoundary,
		kOnBoundaryWithLeader,
	};

	enum ModelEdge
	{
		kSmooth = 0,
		kSmoothWithBorder,
		kSmoothWithConnectionLine,
		kJagged,
	};

protected:
	ACDBCORE2D_PORT Acad::ErrorStatus subDeepClone(AcDbObject* pOwner, AcDbObject*& pClonedObject,
												   AcDbIdMapping& idMap,
												   bool isPrimary = true) const override;
	ACDBCORE2D_PORT Acad::ErrorStatus subWblockClone(AcRxObject* pOwner, AcDbObject*& pClonedObject,
													 AcDbIdMapping& idMap,
													 bool isPrimary = true) const override;

public:
	ACDBCORE2D_PORT AcDbDetailViewStyle();
	ACDBCORE2D_PORT ~AcDbDetailViewStyle();

	ACDB_DECLARE_MEMBERS_EXPIMP(AcDbDetailViewStyle, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT AcCmColor arrowSymbolColor() const;
	ACDBCORE2D_PORT AcDbObjectId arrowSymbolId() const;
	ACDBCORE2D_PORT double arrowSymbolSize() const;
	ACDBCORE2D_PORT AcCmColor borderLineColor() const;
	ACDBCORE2D_PORT AcDbObjectId borderLineTypeId() const;
	ACDBCORE2D_PORT AcDb::LineWeight borderLineWeight() const;
	ACDBCORE2D_PORT AcCmColor boundaryLineColor() const;
	ACDBCORE2D_PORT AcDbObjectId boundaryLineTypeId() const;
	ACDBCORE2D_PORT AcDb::LineWeight boundaryLineWeight() const;
	ACDBCORE2D_PORT AcCmColor connectionLineColor() const;
	ACDBCORE2D_PORT AcDbObjectId connectionLineTypeId() const;
	ACDBCORE2D_PORT AcDb::LineWeight connectionLineWeight() const;
	ACDBCORE2D_PORT Acad::ErrorStatus getViewLabelPattern(AcString& pattern,
														  AcDbField* pField = nullptr) const;
	ACDBCORE2D_PORT AcCmColor identifierColor() const;
	ACDBCORE2D_PORT double identifierHeight() const;
	ACDBCORE2D_PORT double identifierOffset() const;
	ACDBCORE2D_PORT AcDbDetailViewStyle::IdentifierPlacement identifierPlacement() const;
	ACDBCORE2D_PORT AcDbObjectId identifierStyleId() const;
	ACDBCORE2D_PORT AcDbDetailViewStyle::ModelEdge modelEdge() const;
	ACDBCORE2D_PORT Acad::ErrorStatus setArrowSymbolColor(const AcCmColor& color);
	ACDBCORE2D_PORT Acad::ErrorStatus setArrowSymbolId(const AcDbObjectId& arrowSymbolId);
	ACDBCORE2D_PORT Acad::ErrorStatus setArrowSymbolSize(double size);
	ACDBCORE2D_PORT Acad::ErrorStatus setBorderLineColor(const AcCmColor& color);
	ACDBCORE2D_PORT Acad::ErrorStatus setBorderLineTypeId(const AcDbObjectId& objId);
	ACDBCORE2D_PORT Acad::ErrorStatus setBorderLineWeight(AcDb::LineWeight lineweight);
	ACDBCORE2D_PORT Acad::ErrorStatus setBoundaryLineColor(const AcCmColor& color);
	ACDBCORE2D_PORT Acad::ErrorStatus setBoundaryLineTypeId(const AcDbObjectId& objId);
	ACDBCORE2D_PORT Acad::ErrorStatus setBoundaryLineWeight(AcDb::LineWeight lineweight);
	ACDBCORE2D_PORT Acad::ErrorStatus setConnectionLineColor(const AcCmColor& color);
	ACDBCORE2D_PORT Acad::ErrorStatus setConnectionLineTypeId(const AcDbObjectId& objId);
	ACDBCORE2D_PORT Acad::ErrorStatus setConnectionLineWeight(AcDb::LineWeight lineweight);
	ACDBCORE2D_PORT Acad::ErrorStatus setIdentifierColor(const AcCmColor& color);
	ACDBCORE2D_PORT Acad::ErrorStatus setIdentifierHeight(double height);
	ACDBCORE2D_PORT Acad::ErrorStatus setIdentifierOffset(double offset);
	ACDBCORE2D_PORT Acad::ErrorStatus setIdentifierPlacement(
			AcDbDetailViewStyle::IdentifierPlacement placement);
	ACDBCORE2D_PORT Acad::ErrorStatus setIdentifierStyleId(const AcDbObjectId& objId);
	ACDBCORE2D_PORT Acad::ErrorStatus setModelEdge(AcDbDetailViewStyle::ModelEdge placement);
	ACDBCORE2D_PORT Acad::ErrorStatus setShowArrows(bool bValue);
	ACDBCORE2D_PORT Acad::ErrorStatus setShowViewLabel(bool bValue);
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
	ACDBCORE2D_PORT bool showArrows() const;
	ACDBCORE2D_PORT bool showViewLabel() const;
	ACDBCORE2D_PORT AcDbModelDocViewStyle::TextAlignment viewLabelAlignment() const;
	ACDBCORE2D_PORT AcDbModelDocViewStyle::AttachmentPoint viewLabelAttachment() const;
	ACDBCORE2D_PORT double viewLabelOffset() const;
	ACDBCORE2D_PORT const ACHAR* viewLabelPattern() const;
	ACDBCORE2D_PORT AcCmColor viewLabelTextColor() const;
	ACDBCORE2D_PORT double viewLabelTextHeight() const;
	ACDBCORE2D_PORT AcDbObjectId viewLabelTextStyleId() const;
};

#include "icarx/IcArxPackPop.h"

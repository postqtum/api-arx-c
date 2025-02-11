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
***     Description:  Declaration of AcDbDetailSymbol class
***
*****************************************************************************/
#pragma once

#include "dbViewSymbol.h"
#include "dbDetailViewStyle.h"

#ifndef ACSYNERGY_PORT
#	define ACSYNERGY_PORT
#endif

#include "icarx/IcArxPackPush.h"

class ACSYNERGY_PORT AcDbDetailSymbol : public AcDbViewSymbol
{
public:
	enum BoundaryType
	{
		kCircularBoundary,
		kRectangularBoundary,
		kCustomBoundary
	};

	enum OverriddenProperty
	{
		kModelEdge = 0x00000001,
		kIdentifierPosition = 0x00000001 << 1,
	};

public:
	ACRX_DECLARE_MEMBERS(AcDbDetailSymbol);

	AcDbDetailSymbol();

	const AcGeVector2d& boundarySize() const;
	BoundaryType boundaryType() const;
	double detailViewScale() const;
	const AcGeVector3d& direction() const;
	bool displayIdentifier() const;
	const AcGePoint3d identifierPosition() const;
	Acad::ErrorStatus initializeIdentifierPositionAt(const AcGePoint3d& pt);
	bool isOverriddenProperty(AcDbDetailSymbol::OverriddenProperty property) const;
	Acad::ErrorStatus modelEdgeBorderExtents(AcDbExtents& modelEdgeExtent) const;
	const AcGeVector3d& modelEdgeDirection() const;
	const AcGePoint3d& modelEdgeOrigin() const;
	AcDbDetailViewStyle::ModelEdge modelEdgeType() const;
	AcGePoint3d origin() const;
	double owningViewScale() const;
	Acad::ErrorStatus resetIdentifierPosition();
	Acad::ErrorStatus setBoundarySize(const AcGeVector2d& size);
	Acad::ErrorStatus setBoundaryType(BoundaryType bndType);
	Acad::ErrorStatus setDetailViewScale(double viewScale);
	Acad::ErrorStatus setDisplayIdentifier(const bool displayIdentifier);
	Acad::ErrorStatus setIdentifierPosition(const AcGePoint3d& pt);
	Acad::ErrorStatus setModelEdgeDirection(const AcGeVector3d& dir);
	Acad::ErrorStatus setModelEdgeOrigin(const AcGePoint3d& pt);
	Acad::ErrorStatus setModelEdgeType(AcDbDetailViewStyle::ModelEdge modelEdgeType);
	Acad::ErrorStatus setOrigin(const AcGePoint3d& pt);
	Acad::ErrorStatus setOwningViewScale(double viewScale);
	Acad::ErrorStatus setPickPoints(const AcGePoint3dArray& pickPoints);
};

#include "icarx/IcArxPackPop.h"

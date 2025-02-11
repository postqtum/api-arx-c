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
***     Description: Declaration of AcDbUnderlayItem struct
***
*****************************************************************************/
#pragma once

#include "AcUnderlayLayer.h"
#include "AcDbUnderlayDrawContext.h"
#include "AcDbUnderlayDefinition.h"

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcDbUnderlayItem
{
public:
	virtual ~AcDbUnderlayItem() = 0;

	virtual Acad::ErrorStatus draw(AcGiWorldDraw* pWorldDraw, AcGiViewportDraw* pViewportDraw,
								   const AcDbUnderlayDrawContext& context) const = 0;
	virtual Acad::ErrorStatus getExtents(AcGePoint2d& min, AcGePoint2d& max) const = 0;
	virtual AcString getName() const = 0;
	virtual Acad::ErrorStatus getOsnapPoints(
			const AcGeMatrix3d& modelToWorld, AcDb::OsnapMode osnapMode,
			IcArx::Integers::GsMarker gsSelectionMark, const AcGePoint3d& pickPoint,
			const AcGePoint3d& lastPoint, const AcGeMatrix3d& viewXform,
			AcGePoint3dArray& snapPoints, AcDbIntArray& geomIds) const = 0;
	virtual AcDbEntity* getSubEntityAtGsMarker(const AcGeMatrix3d& modelToWorld,
											   IcArx::Integers::GsMarker gsSelectionMark) const = 0;
	virtual Acad::ErrorStatus getThumbnail(BITMAPINFO*& thumbnail) const = 0;
	virtual Acad::ErrorStatus getUnderlayLayer(int, AcUnderlayLayer&) const
	{
		return Acad::eNotImplemented;
	}
	virtual AcDb::UnitsValue getUnits() const = 0;
	virtual Acad::ErrorStatus intersectWith(const AcGeMatrix3d& modelToWorld,
											const AcDbEntity* pEnt, AcDb::Intersect intType,
											const AcGePlane* projPlane, AcGePoint3dArray& points,
											IcArx::Integers::GsMarker thisGsMarker,
											IcArx::Integers::GsMarker otherGsMarker) const = 0;
	virtual AcGeMatrix3d modelTransform() const = 0;
	virtual uint32_t underlayLayerCount() const { return 0; }
	virtual bool usingPartialContent() const = 0;
	int version() const;
};

#include "IcArxPackPop.h"

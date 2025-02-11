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
***     Description:
***
*****************************************************************************/
#pragma once

#include "icarx/AcDbEntity.h"

#ifndef ACSYNERGY_PORT
#	define ACSYNERGY_PORT
#endif

class AcDbImpViewBorder;

#include "icarx/IcArxPackPush.h"

class ACSYNERGY_PORT AcDbViewBorder : public AcDbEntity
{
	friend class AcDbAssocViewRepActionBody;
	friend class AcDbImpViewBorder;
	friend class AcDbImpViewSymbol;

public:
	enum SourceType
	{
		kSourceNotDefined = 0,
		kInventorSource = 1,
		kFusionSource = 2,
		kModelSpaceSource = 3
	};

	enum ViewStyleType
	{
		kFromBase = 0,
		kWireframeVisibleEdges = 1,
		kWireframeHiddenEdges = 2,
		kShadedVisibleEdges = 3,
		kShadedHiddenEdges = 4
	};

public:
	ACRX_DECLARE_MEMBERS(AcDbViewBorder);

	AcDbViewBorder();
	~AcDbViewBorder();

	Acad::ErrorStatus audit(AcDbAuditInfo* pAuditInfo) override;
	AcGePoint2d centerPoint(bool exludeSketchEnts = true) const;
	AcGePoint3d centerPoint3d(bool exludeSketchEnts = true) const;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	Acad::ErrorStatus getSize(AcGePoint3d& minPt, AcGePoint3d& maxPt) const;
	Acad::ErrorStatus getSubentColor(const AcDbSubentId& subentId, AcCmColor& color) const;
	Acad::ErrorStatus getSubentLayerId(const AcDbSubentId& subentId, AcDbObjectId& layerId) const;
	Acad::ErrorStatus getSubentLineWeight(const AcDbSubentId& subentId,
										  AcDb::LineWeight& lineweight) const;
	Acad::ErrorStatus getSubentLinetypeId(const AcDbSubentId& subentId,
										  AcDbObjectId& linetypeId) const;
	Acad::ErrorStatus getSubentLinetypeScale(const AcDbSubentId& subentId,
											 double& linetypeScale) const;
	ACHAR* getSubentPlotStyleName(const AcDbSubentId& subentId) const;
	Acad::ErrorStatus getSubentVisibility(const AcDbSubentId& subentId,
										  AcDb::Visibility& visVal) const;
	double height() const;
	bool hitTest(const AcGePoint3d& inputPt) const;
	AcGePoint3d insertionPoint() const;
	AcString inventorFileReference() const;
	bool isFirstAngleProjection() const;
	Acad::ErrorStatus recalculateBorder();
	double rotationAngle() const;
	void saveAs(AcGiWorldDraw* mode, AcDb::SaveType st) override;
	double scale() const;
	void setDisableUnHighlight(bool bIsDisable);
	Acad::ErrorStatus setLayer(const ACHAR* newVal, bool doSubents = true,
							   bool allowHiddenLayer = false) override;
	Acad::ErrorStatus setLayer(AcDbObjectId newVal, bool doSubents = true,
							   bool allowHiddenLayer = false) override;
	void setScale(double newScale);
	Acad::ErrorStatus setSize(const AcGePoint3d& minPt, const AcGePoint3d& maxPt);
	Acad::ErrorStatus setSubentColor(const AcDbSubentId& subentId, const AcCmColor& color);
	Acad::ErrorStatus setSubentLayer(const AcDbSubentId& subentId, AcDbObjectId newVal);
	Acad::ErrorStatus setSubentLineWeight(const AcDbSubentId& subentId, AcDb::LineWeight newVal);
	Acad::ErrorStatus setSubentLinetype(const AcDbSubentId& subentId, AcDbObjectId newVal);
	Acad::ErrorStatus setSubentLinetypeScale(const AcDbSubentId& subentId, double newVal);
	Acad::ErrorStatus setSubentPlotStyleName(const AcDbSubentId& subentId, const ACHAR* newName);
	Acad::ErrorStatus setSubentVisibility(const AcDbSubentId& subentId, AcDb::Visibility newVal);
	void setTransientEnts(const AcArray<AcDbEntity*>& traientEnts);
	Acad::ErrorStatus setViewportId(const AcDbObjectId& viewportId);
	uint32_t shadedDPI() const;
	AcDbViewBorder::SourceType sourceType() const;
	Acad::ErrorStatus subDeepClone(AcDbObject* pOwnerObject, AcDbObject*& pClonedObject,
								   AcDbIdMapping& idMap, bool isPrimary = true) const override;
	Acad::ErrorStatus subErase(bool erasing) override;
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
	Acad::ErrorStatus subGetGeomExtents(AcDbExtents& extents) const override;
	Acad::ErrorStatus subGetGripPoints(AcDbGripDataPtrArray& grips, const double curViewUnitSize,
									   const int gripSize, const AcGeVector3d& curViewDir,
									   const int bitflags) const override;
	Acad::ErrorStatus subGetGripPoints(AcGePoint3dArray& gripPoints, AcDbIntArray& osnapModes,
									   AcDbIntArray& geomIds) const override;
	Acad::ErrorStatus subGetGsMarkersAtSubentPath(
			const AcDbFullSubentPath& subPath,
			AcArray<IcArx::Integers::GsMarker>& gsMarkers) const override;
	Acad::ErrorStatus subGetOsnapPoints(AcDb::OsnapMode osnapMode,
										IcArx::Integers::GsMarker gsSelectionMark,
										const AcGePoint3d& pickPoint, const AcGePoint3d& lastPoint,
										const AcGeMatrix3d& viewXform, AcGePoint3dArray& snapPoints,
										AcDbIntArray& geomIds) const override;
	Acad::ErrorStatus subGetOsnapPoints(AcDb::OsnapMode osnapMode,
										IcArx::Integers::GsMarker gsSelectionMark,
										const AcGePoint3d& pickPoint, const AcGePoint3d& lastPoint,
										const AcGeMatrix3d& viewXform, AcGePoint3dArray& snapPoints,
										AcDbIntArray& geomIds,
										const AcGeMatrix3d& insertionMat) const override;
	Acad::ErrorStatus subGetStretchPoints(AcGePoint3dArray& stretchPoints) const override;
	Acad::ErrorStatus subGetSubentClassId(const AcDbFullSubentPath& path,
										  CLSID* clsId) const override;
	Acad::ErrorStatus subGetSubentPathsAtGsMarker(
			AcDb::SubentType type, IcArx::Integers::GsMarker gsMark, const AcGePoint3d& pickPoint,
			const AcGeMatrix3d& viewXform, int& numPaths, AcDbFullSubentPath*& subentPaths,
			int numInserts = 0, AcDbObjectId* entAndInsertStack = nullptr) const override;
	void subGripStatus(const AcDb::GripStat status) override;
	Acad::ErrorStatus subHighlight(const AcDbFullSubentPath& subId = kNullSubent,
								   const bool highlightAll = false) const override;
	Acad::ErrorStatus subIntersectWith(const AcDbEntity* pEnt, AcDb::Intersect intType,
									   const AcGePlane& projPlane, AcGePoint3dArray& points,
									   IcArx::Integers::GsMarker thisGsMarker = 0,
									   IcArx::Integers::GsMarker otherGsMarker = 0) const override;

	Acad::ErrorStatus subIntersectWith(const AcDbEntity* pEnt, AcDb::Intersect intType,
									   AcGePoint3dArray& points,
									   IcArx::Integers::GsMarker thisGsMarker = 0,
									   IcArx::Integers::GsMarker otherGsMarker = 0) const override;
	void subList() const override;
	Acad::ErrorStatus subMoveGripPointsAt(const AcDbVoidPtrArray& gripAppData,
										  const AcGeVector3d& offset, const int bitflags) override;
	Acad::ErrorStatus subMoveGripPointsAt(const AcDbIntArray& indices,
										  const AcGeVector3d& offset) override;
	Acad::ErrorStatus subMoveStretchPointsAt(const AcDbIntArray& indices,
											 const AcGeVector3d& offset) override;
	Acad::ErrorStatus subTransformBy(const AcGeMatrix3d& xform) override;
	Acad::ErrorStatus subUnhighlight(const AcDbFullSubentPath& subId = kNullSubent,
									 const bool highlightAll = false) const override;
	Acad::ErrorStatus subWblockClone(AcRxObject* pOwnerObject, AcDbObject*& pClonedObject,
									 AcDbIdMapping& idMap, bool isPrimary = true) const override;
	bool subWorldDraw(AcGiWorldDraw* pWd) override;
	Acad::ErrorStatus subentIdToNestedEnts(const AcDbSubentId& subentId,
										   AcDbFullSubentPathArray& nestedEnts) const;
	AcDbViewBorder::ViewStyleType viewStyleType() const;
	AcDbObjectId viewportId() const;
	double width() const;
};

#include "icarx/IcArxPackPop.h"

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
***     Description: Declaration of AcDbEntity class
***
*****************************************************************************/
#pragma once

#include "../AcString.h"
#include "../acgidefs.h"
#include "../dbintar.h"
#include "../gept3dar.h"

#include "acut_str_util.h"
#include "AcDbObject.h"
#include "AcCmColor.h"
#include "AcDbFullSubentPathArray.h"

class AcGePlane;
class AcGePoint3d;
class AcGeVector3d;
class AcGiMapper;

class AcDbGripData;
using AcDbGripDataPtrArray = AcArray<AcDbGripData*, AcArrayMemCopyReallocator<AcDbGripData*>>;

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcDbEntity : public AcDbObject
{
	friend class AcDbPropertiesOverrule;
	friend class AcDbOsnapOverrule;
	friend class AcDbTransformOverrule;
	friend class AcDbGripOverrule;
	friend class AcDbSubentityOverrule;
	friend class AcDbHighlightOverrule;
	friend class AcDbHighlightStateOverrule;
	friend class AcDbVisibilityOverrule;
	friend class AcDbGeometryOverrule;
	friend class AcDbGripEntityOverrule;

public:
	enum VisualStyleType
	{
		kFullVisualStyle,
		kFaceVisualStyle,
		kEdgeVisualStyle
	};

protected:
	AcDbEntity();
	AcDbEntity(const AcDbEntity&) = delete;
	AcDbEntity& operator=(const AcDbEntity&) = delete;

	ACDBCORE2D_PORT virtual Acad::ErrorStatus subAddSubentPaths(
			const AcDbFullSubentPathArray& newPaths);
	ACDBCORE2D_PORT virtual bool subCloneMeForDragging();
	ACDBCORE2D_PORT virtual Acad::ErrorStatus subDeleteSubentPaths(
			const AcDbFullSubentPathArray& paths);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus subExplode(AcDbVoidPtrArray& entitySet) const;
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus subGetCompoundObjectTransform(
			AcGeMatrix3d& xMat) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus subGetGeomExtents(AcDbExtents& extents) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus subGetGripEntityUCS(const void* pGripAppData,
																  AcGeVector3d& normalVec,
																  AcGePoint3d& origin,
																  AcGeVector3d& xAxis) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus subGetGripPoints(AcGePoint3dArray& gripPoints,
															   AcDbIntArray& osnapModes,
															   AcDbIntArray& geomIds) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus subGetGripPoints(AcDbGripDataPtrArray& grips,
															   const double curViewUnitSize,
															   const int gripSize,
															   const AcGeVector3d& curViewDir,
															   const int bitflags) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus subGetGripPointsAtSubentPath(
			const AcDbFullSubentPath& path, AcDbGripDataPtrArray& grips,
			const double curViewUnitSize, const int gripSize, const AcGeVector3d& curViewDir,
			const int bitflags) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus subGetGsMarkersAtSubentPath(
			const AcDbFullSubentPath& subPath, AcArray<IcArx::Integers::GsMarker>& gsMarkers) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus subGetOsnapPoints(
			AcDb::OsnapMode osnapMode, IcArx::Integers::GsMarker gsSelectionMark,
			const AcGePoint3d& pickPoint, const AcGePoint3d& lastPoint,
			const AcGeMatrix3d& viewXform, AcGePoint3dArray& snapPoints,
			AcDbIntArray& geomIds) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus subGetOsnapPoints(
			AcDb::OsnapMode osnapMode, IcArx::Integers::GsMarker gsSelectionMark,
			const AcGePoint3d& pickPoint, const AcGePoint3d& lastPoint,
			const AcGeMatrix3d& viewXform, AcGePoint3dArray& snapPoints, AcDbIntArray& geomIds,
			const AcGeMatrix3d& insertionMat) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus subGetStretchPoints(
			AcGePoint3dArray& stretchPoints) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus subGetSubentClassId(const AcDbFullSubentPath& path,
																  CLSID* clsId) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus subGetSubentPathGeomExtents(
			const AcDbFullSubentPath& path, AcDbExtents& extents) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus subGetSubentPathsAtGsMarker(
			AcDb::SubentType type, IcArx::Integers::GsMarker gsMark, const AcGePoint3d& pickPoint,
			const AcGeMatrix3d& viewXform, int& numPaths, AcDbFullSubentPath*& subentPaths,
			int numInserts = 0, AcDbObjectId* entAndInsertStack = nullptr) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus subGetTransformedCopy(const AcGeMatrix3d& xform,
																	AcDbEntity*& pEnt) const;
	ACDBCORE2D_PORT virtual void subGripStatus(const AcDb::GripStat status);
	ACDBCORE2D_PORT virtual bool subHideMeForDragging() const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus subHighlight(
			const AcDbFullSubentPath& subId = kNullSubent, const bool highlightAll = false) const;
	ACDBCORE2D_PORT virtual AcGiHighlightStyle subHighlightState(const AcDbFullSubentPath& subId);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus subIntersectWith(
			const AcDbEntity* pEnt, AcDb::Intersect intType, AcGePoint3dArray& points,
			IcArx::Integers::GsMarker thisGsMarker = 0,
			IcArx::Integers::GsMarker otherGsMarker = 0) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus subIntersectWith(
			const AcDbEntity* pEnt, AcDb::Intersect intType, const AcGePlane& projPlane,
			AcGePoint3dArray& points, IcArx::Integers::GsMarker thisGsMarker = 0,
			IcArx::Integers::GsMarker otherGsMarker = 0) const;
	ACDBCORE2D_PORT virtual bool subIsContentSnappable() const;
	ACDBCORE2D_PORT virtual void subList() const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus subMoveGripPointsAt(const AcDbIntArray& indices,
																  const AcGeVector3d& offset);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus subMoveGripPointsAt(
			const AcDbVoidPtrArray& gripAppData, const AcGeVector3d& offset, const int bitflags);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus subMoveGripPointsAtSubentPaths(
			const AcDbFullSubentPathArray& paths, const AcDbVoidPtrArray& gripAppData,
			const AcGeVector3d& offset, const int bitflags);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus subMoveStretchPointsAt(const AcDbIntArray& indices,
																	 const AcGeVector3d& offset);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus subPopHighlight(const AcDbFullSubentPath& subId);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus subPushHighlight(const AcDbFullSubentPath& subId,
															   AcGiHighlightStyle highlightStyle);
	ACDBCORE2D_PORT virtual uint32_t subSetAttributes(AcGiDrawableTraits* pTraits) override;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus subSetVisibility(AcDb::Visibility newVal,
															   bool doSubents = true);
	ACDBCORE2D_PORT virtual void subSubentGripStatus(const AcDb::GripStat status,
													 const AcDbFullSubentPath& subentity);
	ACDBCORE2D_PORT virtual AcDbEntity* subSubentPtr(const AcDbFullSubentPath& id) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus subTransformBy(const AcGeMatrix3d& xform);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus subTransformSubentPathsBy(
			const AcDbFullSubentPathArray& paths, const AcGeMatrix3d& xform);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus subUnhighlight(
			const AcDbFullSubentPath& subId = kNullSubent, const bool highlightAll = false) const;
	ACDBCORE2D_PORT virtual void subViewportDraw(AcGiViewportDraw* pVd) override;
	ACDBCORE2D_PORT virtual AcDb::Visibility subVisibility() const;
	ACDBCORE2D_PORT virtual bool subWorldDraw(AcGiWorldDraw* pWd) override;

public:
	ACDBCORE2D_DECLARE_MEMBERS(AcDbEntity);

	~AcDbEntity() = default;

	ACDBCORE2D_PORT virtual Acad::ErrorStatus addSubentPaths(
			const AcDbFullSubentPathArray& newPaths) final;
	ACDBCORE2D_PORT Acad::ErrorStatus applyPartialUndo(AcDbDwgFiler* undoFiler,
													   AcRxClass* classObj) override;
	ACDBCORE2D_PORT Acad::ErrorStatus audit(AcDbAuditInfo* pAuditInfo) override;
	AcDbObjectId blockId() const;
	Acad::ErrorStatus boundingBoxIntersectWith(const AcDbEntity* pEnt, AcDb::Intersect intType,
											   AcGePoint3dArray& points,
											   IcArx::Integers::GsMarker thisGsMarker,
											   IcArx::Integers::GsMarker otherGsMarker) const;

	Acad::ErrorStatus boundingBoxIntersectWith(const AcDbEntity* pEnt, AcDb::Intersect intType,
											   const AcGePlane& projPlane, AcGePoint3dArray& points,
											   IcArx::Integers::GsMarker thisGsMarker,
											   IcArx::Integers::GsMarker otherGsMarker) const;
	ACDBCORE2D_PORT bool bounds(AcDbExtents& bounds) const override;
	ACDBCORE2D_PORT virtual bool castShadows() const;
	ACDBCORE2D_PORT virtual bool cloneMeForDragging() final;
	ACDBCORE2D_PORT virtual AcDb::CollisionType collisionType() const;
	AcCmColor color() const;
	uint16_t colorIndex() const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus deleteSubentPaths(
			const AcDbFullSubentPathArray& paths) final;
	virtual void dragStatus(const AcDb::DragStat status);
	Acad::ErrorStatus draw();
	ACDBCORE2D_PORT AcGiDrawable* drawable() override;
	ACDBCORE2D_PORT Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	ACDBCORE2D_PORT Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	ACDBCORE2D_PORT Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	ACDBCORE2D_PORT Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	AcCmEntityColor entityColor() const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus explode(AcDbVoidPtrArray& entitySet) const final;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getCompoundObjectTransform(
			AcGeMatrix3d& xMat) const final;
	ACDBCORE2D_PORT virtual void getEcs(AcGeMatrix3d& retVal) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getGeomExtents(AcDbExtents& extents) const final;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getGripEntityUCS(const void* pGripAppData,
															   AcGeVector3d& normalVec,
															   AcGePoint3d& origin,
															   AcGeVector3d& xAxis) const final;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getGripPoints(AcGePoint3dArray& gripPoints,
															AcDbIntArray& osnapModes,
															AcDbIntArray& geomIds) const final;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getGripPoints(AcDbGripDataPtrArray& grips,
															const double curViewUnitSize,
															const int gripSize,
															const AcGeVector3d& curViewDir,
															const int bitflags) const final;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getGripPointsAtSubentPath(
			const AcDbFullSubentPath& path, AcDbGripDataPtrArray& grips,
			const double curViewUnitSize, const int gripSize, const AcGeVector3d& curViewDir,
			const int bitflags) const final;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getGsMarkersAtSubentPath(
			const AcDbFullSubentPath& subPath,
			AcArray<IcArx::Integers::GsMarker>& gsMarkers) const final;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getMaterialMapper(AcGiMapper& mapper) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getOsnapPoints(
			AcDb::OsnapMode osnapMode, IcArx::Integers::GsMarker gsSelectionMark,
			const AcGePoint3d& pickPoint, const AcGePoint3d& lastPoint,
			const AcGeMatrix3d& viewXform, AcGePoint3dArray& snapPoints,
			AcDbIntArray& geomIds) const final;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getOsnapPoints(
			AcDb::OsnapMode osnapMode, IcArx::Integers::GsMarker gsSelectionMark,
			const AcGePoint3d& pickPoint, const AcGePoint3d& lastPoint,
			const AcGeMatrix3d& viewXform, AcGePoint3dArray& snapPoints, AcDbIntArray& geomIds,
			const AcGeMatrix3d& insertionMat) const final;
	virtual Acad::ErrorStatus getPlane(AcGePlane&, AcDb::Planarity&) const
	{
		return Acad::eNotApplicable;
	}
	AcDb::PlotStyleNameType getPlotStyleNameId(AcDbObjectId& id) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getStretchPoints(
			AcGePoint3dArray& stretchPoints) const final;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getSubentClassId(const AcDbFullSubentPath& path,
															   CLSID* clsId) const final;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getSubentPathGeomExtents(
			const AcDbFullSubentPath& path, AcDbExtents& extents) const final;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getSubentPathsAtGsMarker(
			AcDb::SubentType type, IcArx::Integers::GsMarker gsMark, const AcGePoint3d& pickPoint,
			const AcGeMatrix3d& viewXform, int& numPaths, AcDbFullSubentPath*& subentPaths,
			int numInserts = 0, AcDbObjectId* entAndInsertStack = nullptr) const final;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getTransformedCopy(const AcGeMatrix3d& xform,
																 AcDbEntity*& pEnt) const final;
	ACDBCORE2D_PORT virtual void gripStatus(const AcDb::GripStat status) final;
	ACDBCORE2D_PORT virtual bool hideMeForDragging() const final;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus highlight(
			const AcDbFullSubentPath& subId = kNullSubent,
			const bool highlightAll = false) const final;
	AcGiHighlightStyle highlightState(const AcDbFullSubentPath& subId);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus intersectWith(
			const AcDbEntity* pEnt, AcDb::Intersect intType, AcGePoint3dArray& points,
			IcArx::Integers::GsMarker thisGsMarker = 0,
			IcArx::Integers::GsMarker otherGsMarker = 0) const final;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus intersectWith(
			const AcDbEntity* pEnt, AcDb::Intersect intType, const AcGePlane& projPlane,
			AcGePoint3dArray& points, IcArx::Integers::GsMarker thisGsMarker = 0,
			IcArx::Integers::GsMarker otherGsMarker = 0) const final;
	ACDBCORE2D_PORT virtual bool isContentSnappable() const final;
	virtual bool isPlanar() const { return false; }
	ACDBCORE2D_PORT Acad::ErrorStatus layer(AcString& sName) const;
	ACHAR* layer() const;
	AcDbObjectId layerId() const;
	AcDb::LineWeight lineWeight() const;
	ACDBCORE2D_PORT Acad::ErrorStatus linetype(AcString& sName) const;
	ACHAR* linetype() const;
	AcDbObjectId linetypeId() const;
	double linetypeScale() const;
	ACDBCORE2D_PORT virtual void list() const final;
	ACDBCORE2D_PORT Acad::ErrorStatus material(AcString& sName) const;
	ACHAR* material() const;
	AcDbObjectId materialId() const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus moveGripPointsAt(const AcDbIntArray& indices,
															   const AcGeVector3d& offset) final;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus moveGripPointsAt(const AcDbVoidPtrArray& gripAppData,
															   const AcGeVector3d& offset,
															   const int bitflags) final;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus moveGripPointsAtSubentPaths(
			const AcDbFullSubentPathArray& paths, const AcDbVoidPtrArray& gripAppData,
			const AcGeVector3d& offset, const int bitflags) final;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus moveStretchPointsAt(const AcDbIntArray& indices,
																  const AcGeVector3d& offset) final;
	ACDBCORE2D_PORT Acad::ErrorStatus plotStyleName(AcString& sName) const;
	ACHAR* plotStyleName() const;
	Acad::ErrorStatus popHighlight(const AcDbFullSubentPath& subId);
	Acad::ErrorStatus pushHighlight(const AcDbFullSubentPath& subId,
									AcGiHighlightStyle highlightStyle);
	ACDBCORE2D_PORT virtual bool receiveShadows() const;
	void recordGraphicsModified(bool setModified = true);
	ACDBCORE2D_PORT virtual void saveAs(AcGiWorldDraw* mode, AcDb::SaveType st);
	ACDBCORE2D_PORT virtual void setCastShadows(bool newVal);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setColor(const AcCmColor& color, bool doSubents,
													   AcDbDatabase* pDb);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setColor(const AcCmColor& color,
													   bool doSubents = true) final;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setColorIndex(uint16_t color, bool doSubents = true);
	void setDatabaseDefaults();
	void setDatabaseDefaults(AcDbDatabase* pDb);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setLayer(const ACHAR* newVal, bool doSubents = true,
													   bool allowHiddenLayer = false);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setLayer(AcDbObjectId newVal, bool doSubents = true,
													   bool allowHiddenLayer = false);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setLineWeight(AcDb::LineWeight newVal,
															bool doSubents = true);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setLinetype(const ACHAR* newVal,
														  bool doSubents = true);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setLinetype(AcDbObjectId newVal,
														  bool doSubents = true);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setLinetypeScale(double newval,
															   bool doSubents = true);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setMaterial(const ACHAR* newVal,
														  bool doSubents = true);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setMaterial(AcDbObjectId newVal,
														  bool doSubents = true);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setMaterialMapper(const AcGiMapper& mapper,
																bool doSubents = true);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setPlotStyleName(const ACHAR* newName,
															   bool doSubents = true);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setPlotStyleName(
			AcDb::PlotStyleNameType, AcDbObjectId newId = AcDbObjectId::kNull,
			bool doSubents = true);
	Acad::ErrorStatus setPropertiesFrom(const AcDbEntity* pEntity, bool doSubents = true);
	ACDBCORE2D_PORT virtual void setReceiveShadows(bool newVal);
	virtual Acad::ErrorStatus setTransparency(const AcCmTransparency& trans, bool doSubents = true);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setVisibility(AcDb::Visibility newVal,
															bool doSubents = true) final;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setVisualStyle(
			AcDbObjectId visualStyleId, VisualStyleType vsType = kFullVisualStyle,
			bool doSubents = true);
	ACDBCORE2D_PORT virtual void subSetDatabaseDefaults(AcDbDatabase* pDb);
	ACDBCORE2D_PORT virtual void subentGripStatus(const AcDb::GripStat status,
												  const AcDbFullSubentPath& subentity) final;
	ACDBCORE2D_PORT virtual AcDbEntity* subentPtr(const AcDbFullSubentPath& id) const final;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus transformBy(const AcGeMatrix3d& xform) final;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus transformSubentPathsBy(
			const AcDbFullSubentPathArray& paths, const AcGeMatrix3d& xform) final;
	AcCmTransparency transparency() const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus unhighlight(
			const AcDbFullSubentPath& subId = kNullSubent,
			const bool highlightAll = false) const final;
	AcDb::Visibility visibility() const;
	AcDbObjectId visualStyleId(VisualStyleType vsType = kFullVisualStyle) const;
};

#include "IcArxPackPop.h"

inline ACHAR* AcDbEntity::layer() const
{
	AcString sName;
	return ::acutAcStringToAChar(sName, this->layer(sName));
}

inline ACHAR* AcDbEntity::linetype() const
{
	AcString sName;
	return ::acutAcStringToAChar(sName, this->linetype(sName));
}

inline ACHAR* AcDbEntity::material() const
{
	AcString sName;
	return ::acutAcStringToAChar(sName, this->material(sName));
}

inline ACHAR* AcDbEntity::plotStyleName() const
{
	AcString sName;
	return ::acutAcStringToAChar(sName, this->plotStyleName(sName));
}

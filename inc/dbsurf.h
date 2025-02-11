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
***     Description: Declaration of AcDbSweptSurface class
***
*****************************************************************************/
#pragma once

#include "dbmain.h"
#include "dbsubeid.h"
#include "gepnt3d.h"
#include "gevec3d.h"
#include "dbRevolveOptions.h"
#include "dbSweepOptions.h"
#include "dbLoftOptions.h"
#include "AcDbAssocGlobal.h"
#include "AcDbCompoundObjectId.h"

class AcDb3dSolid;
class AcDbLoftProfile;
class AcDbBlendOptions;
class AcDbNurbSurface;
class AcDb3dProfile;
class AcDbRevolvedSurface;
class AcDbExtrudedSurface;
class AcDbSweptSurface;
class AcDbPathRef;

using AcDbNurbSurfaceArray = AcArray<AcDbNurbSurface*>;

#include "icarx/IcArxPackPush.h"

class AcDbSurface : public AcDbEntity
{
public:
	enum EdgeExtensionType
	{
		kExtendEdge = 0x000,
		kStretchEdge = 0x001,
	};

	enum WireframeType
	{
		kIsolines = 0,
		kIsoparms = 1
	};

protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	GEOMENT_DECLARE_MEMBERS(AcDbSurface);

	AcDbSurface();
	~AcDbSurface();

	virtual void* ASMBodyCopy(bool bDeepCopy = false) const;
	virtual Acad::ErrorStatus booleanIntersect(const AcDbSurface* pSurface2,
											   AcArray<AcDbEntity*>& intersectionEntities);
	virtual Acad::ErrorStatus booleanIntersect(const AcDb3dSolid* pSolid,
											   AcArray<AcDbEntity*>& intersectionEntities);
	virtual Acad::ErrorStatus booleanSubtract(const AcDbSurface* pSurface2,
											  AcDbSurface*& pNewSurface);
	virtual Acad::ErrorStatus booleanSubtract(const AcDb3dSolid* pSolid, AcDbSurface*& pNewSurface);
	virtual Acad::ErrorStatus booleanUnion(const AcDbSurface* pSurface2, AcDbSurface*& pNewSurface);
	virtual Acad::ErrorStatus chamferEdges(const AcArray<AcDbSubentId*>& edgeSubentIds,
										   const AcDbSubentId& baseFaceSubentId, double baseDist,
										   double otherDist);
	ACDB_PORT Acad::ErrorStatus chamferEdges(const AcArray<AcDbSubentId*>& edgeSubentIds,
											 const AcDbSubentId& baseFaceSubentId, double baseDist,
											 double otherDist, bool bAssociativeEnabled);
	virtual void commitWritableASMBody();
	Acad::ErrorStatus ACDB_PORT convertToNurbSurface(AcDbNurbSurfaceArray& nsArray);
	virtual Acad::ErrorStatus convertToRegion(AcArray<AcDbEntity*>& regions);
	ACDB_PORT static Acad::ErrorStatus createBlendSurface(AcDbLoftProfile* startProfile,
														  AcDbLoftProfile* endProfile,
														  AcDbBlendOptions* blendOptions,
														  AcDbSurface*& blendSurface);
	ACDB_PORT static Acad::ErrorStatus createBlendSurface(AcDbLoftProfile* startProfile,
														  AcDbLoftProfile* endProfile,
														  AcDbBlendOptions* blendOptions,
														  bool bAssociativeEnabled,
														  AcDbObjectId& blendSurfaceId);
	ACDB_PORT static Acad::ErrorStatus createExtendSurface(AcDbObjectId sourceSurface,
														   const AcArray<AcDbSubentId>& edges,
														   double extDist,
														   EdgeExtensionType extOption,
														   bool bAssociativeEnabled,
														   AcDbObjectId& newExtendSurfaceId);
	ACDB_PORT static Acad::ErrorStatus createExtrudedSurface(
			AcDb3dProfile* pSweep, const AcGeVector3d& directionVec, AcDbSweepOptions& sweepOptions,
			AcDbExtrudedSurface*& newExtrudedSurface);
	ACDB_PORT static Acad::ErrorStatus createExtrudedSurface(AcDb3dProfile* pSweep,
															 const AcGeVector3d& directionVec,
															 AcDbSweepOptions& sweepOptions,
															 bool bAssociativeEnabled,
															 AcDbObjectId& newExtrudedSurfaceId);
	ACDB_PORT static Acad::ErrorStatus createFilletSurface(
			const AcDbObjectId& surfId1, const AcGePoint3d& pickPt1, const AcDbObjectId& surfId2,
			const AcGePoint3d& pickPt2, double radius, AcDb::FilletTrimMode trimMode,
			const AcGeVector3d& projDir, AcDbSurface*& filletSurface);
	ACDB_PORT static Acad::ErrorStatus createFilletSurface(
			const AcDbObjectId& surfId1, const AcGePoint3d& pickPt1, const AcDbObjectId& surfId2,
			const AcGePoint3d& pickPt2, double radius, AcDb::FilletTrimMode trimMode,
			const AcGeVector3d& projDir, bool bAssociativeEnabled, AcDbObjectId& filletSurfaceId);
	static Acad::ErrorStatus createFrom(const AcDbEntity* pFromEntity, AcDbSurface*& pNewSurface);
	virtual Acad::ErrorStatus createInterferenceObjects(AcArray<AcDbEntity*>& interferenceObjects,
														AcDbEntity* pEntity,
														unsigned int flags) const;
	ACDB_PORT static Acad::ErrorStatus createLoftedSurface(
			const AcArray<AcDbLoftProfile*>& crossSections, const AcArray<AcDbLoftProfile*>& guides,
			AcDbLoftProfile* pPath, AcDbLoftOptions& loftOptions, AcDbSurface*& newSurface);
	ACDB_PORT static Acad::ErrorStatus createLoftedSurface(
			const AcArray<AcDbLoftProfile*>& crossSections, const AcArray<AcDbLoftProfile*>& guides,
			AcDbLoftProfile* pPath, AcDbLoftOptions& loftOptions, bool bAssociativeEnabled,
			AcDbObjectId& newSurfaceId);
	ACDB_PORT static Acad::ErrorStatus createNetworkSurface(
			const AcArray<AcDb3dProfile*>& uProfiles, const AcArray<AcDb3dProfile*>& vProfiles,
			AcDbSurface*& newSurface);
	ACDB_PORT static Acad::ErrorStatus createNetworkSurface(
			const AcArray<AcDb3dProfile*>& uProfiles, const AcArray<AcDb3dProfile*>& vProfiles,
			bool bAssociativeEnabled, AcDbObjectId& newSurfaceId);
	ACDB_PORT static Acad::ErrorStatus createOffsetSurface(AcDbEntity* pInputSurface,
														   double offsetDistance,
														   AcDbEntity*& offsetSurface);
	ACDB_PORT static Acad::ErrorStatus createOffsetSurface(AcDbEntity* pInputSurface,
														   double offsetDistance,
														   bool bAssociativeEnabled,
														   AcDbObjectId& offsetSurfaceId);
	ACDB_PORT static Acad::ErrorStatus createPatchSurface(const AcDbPathRef& pathRef,
														  const AcDbObjectIdArray& constraintIds,
														  int continuity, double bulge,
														  AcDbSurface*& newSurface);
	ACDB_PORT static Acad::ErrorStatus createPatchSurface(const AcDbPathRef& pathRef,
														  const AcDbObjectIdArray& constraintIds,
														  int continuity, double bulge,
														  bool bAssociativeEnabled,
														  AcDbObjectId& newSurfaceId);
	ACDB_PORT static Acad::ErrorStatus createRevolvedSurface(
			AcDb3dProfile* pRev, const AcGePoint3d& axisPnt, const AcGeVector3d& axisDir,
			double revAngle, double startAngle, AcDbRevolveOptions& revolveOptions,
			AcDbRevolvedSurface*& newRevolvedSurface);
	ACDB_PORT static Acad::ErrorStatus createRevolvedSurface(
			AcDb3dProfile* pRev, const AcGePoint3d& axisPnt, const AcGeVector3d& axisDir,
			double revAngle, double startAngle, AcDbRevolveOptions& revolveOptions,
			bool bAssociativeEnabled, AcDbObjectId& newSurfaceId);
	ACDB_PORT static Acad::ErrorStatus createRevolvedSurface(
			AcDb3dProfile* pRev, AcDb3dProfile* pAxis, bool flipAxisDirection, double revAngle,
			double startAngle, AcDbRevolveOptions& revolveOptions,
			AcDbRevolvedSurface*& newRevolvedSurface);
	ACDB_PORT static Acad::ErrorStatus createRevolvedSurface(
			AcDb3dProfile* pRev, AcDb3dProfile* pAxis, bool flipAxisDirection, double revAngle,
			double startAngle, AcDbRevolveOptions& revolveOptions, bool bAssociativeEnabled,
			AcDbObjectId& newRevolvedSurfaceId);
	virtual Acad::ErrorStatus createSectionObjects(const AcGePlane& sectionPlane,
												   AcArray<AcDbEntity*>& sectionObjects) const;
	ACDB_PORT static Acad::ErrorStatus createSweptSurface(AcDb3dProfile* pSweep,
														  AcDb3dProfile* pPath,
														  AcDbSweepOptions& sweepOptions,
														  AcDbSweptSurface*& newSweptSurface);
	ACDB_PORT static Acad::ErrorStatus createSweptSurface(AcDb3dProfile* pSweep,
														  AcDb3dProfile* pPath,
														  AcDbSweepOptions& sweepOptions,
														  bool bAssociativeEnabled,
														  AcDbObjectId& newSurfaceId);
	AcDbObjectId ACDB_PORT creationActionBodyId() const;
	ACDB_PORT void dragStatus(const AcDb::DragStat) override;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* filer) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* filer) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* filer) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* filer) const override;
	ACDB_PORT Acad::ErrorStatus extendEdges(AcDbFullSubentPathArray& edges, double extDist,
											EdgeExtensionType extOption, bool bAssociativeEnabled);
	virtual Acad::ErrorStatus filletEdges(const AcArray<AcDbSubentId*>& edgeSubentIds,
										  const AcGeDoubleArray& radius,
										  const AcGeDoubleArray& startSetback,
										  const AcGeDoubleArray& endSetback);
	ACDB_PORT Acad::ErrorStatus filletEdges(const AcArray<AcDbSubentId*>& edgeSubentIds,
											double radius, bool bAssociativeEnabled);
	virtual Acad::ErrorStatus getArea(double& area) const;
	virtual void const* getLockedASMBody();
	virtual void* getLockedWritableASMBody();
	ACDB_PORT Acad::ErrorStatus getPerimeter(double& perimeter) const;
	Acad::ErrorStatus getPlane(AcGePlane& plane, AcDb::Planarity& planarity) const override;
	virtual Acad::ErrorStatus getSubentColor(const AcDbSubentId& subentId, AcCmColor& color) const;
	virtual Acad::ErrorStatus getSubentMaterial(const AcDbSubentId& subentId,
												AcDbObjectId& matId) const;
	virtual Acad::ErrorStatus getSubentMaterialMapper(const AcDbSubentId& subentId,
													  AcGiMapper& mapper) const;
	ACDB_PORT WireframeType getWireframeType() const;
	virtual Acad::ErrorStatus imprintEntity(const AcDbEntity* pEntity);
	virtual AcDbSubentId internalSubentId(void* ent) const;
	virtual void* internalSubentPtr(const AcDbSubentId& id) const;
	Acad::ErrorStatus ACDB_PORT
	modificationActionBodyIds(AcDbObjectIdArray& modificationActionBodyIds) const;
	Acad::ErrorStatus projectOnToSurface(const AcDbEntity* pEntityToProject,
										 const AcGeVector3d& projectionDirection,
										 AcArray<AcDbEntity*>& projectedEntities) const;
	Acad::ErrorStatus ACDB_PORT rayTest(const AcGePoint3d& rayBasePoint, const AcGeVector3d& rayDir,
										double rayRadius, AcArray<AcDbSubentId>& subEntIds,
										AcGeDoubleArray& parameters) const;
	virtual Acad::ErrorStatus setASMBody(const void* modelerBody);
	virtual Acad::ErrorStatus setSubentColor(const AcDbSubentId& subentId, const AcCmColor& color);
	virtual Acad::ErrorStatus setSubentMaterial(const AcDbSubentId& subentId,
												const AcDbObjectId& matId);
	virtual Acad::ErrorStatus setSubentMaterialMapper(const AcDbSubentId& subentId,
													  const AcGiMapper& mapper);
	virtual Acad::ErrorStatus setUIsolineDensity(uint16_t numIsolines);
	virtual Acad::ErrorStatus setVIsolineDensity(uint16_t numIsolines);
	ACDB_PORT Acad::ErrorStatus setWireframeType(WireframeType type);
	virtual Acad::ErrorStatus sliceByPlane(const AcGePlane& slicePlane,
										   AcDbSurface*& pNegHalfSurface,
										   AcDbSurface*& pNewSurface);
	virtual Acad::ErrorStatus sliceBySurface(const AcDbSurface* pSlicingSurface,
											 AcDbSurface*& pNegHalfSurface,
											 AcDbSurface*& pNewSurface);
	virtual Acad::ErrorStatus thicken(double thickness, bool bBothSides,
									  AcDb3dSolid*& pSolid) const;
	ACDB_PORT static Acad::ErrorStatus trimSurface(const AcDbObjectId& blankSurfaceId,
												   const AcDbObjectIdArray& toolIds,
												   const AcDbObjectIdArray& toolCurveIds,
												   const AcArray<AcGeVector3d> projVectors,
												   const AcGePoint3d& pickPoint,
												   const AcGeVector3d& viewVector, bool bAutoExtend,
												   bool bAssociativeEnabled);
	virtual uint16_t uIsolineDensity() const;
	virtual void unlockASMBody();
	ACDB_PORT virtual bool usesGraphicsCache();
	virtual uint16_t vIsolineDensity() const;
};

#include "icarx/IcArxPackPop.h"

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

#include "dbmain.h"
#include "dbsubeid.h"
#include "gepnt3d.h"
#include "gevec3d.h"
#include "acarray.h"
#include "db3dProfile.h"
#include "geintarr.h"

class AcDbSurface;
class AcDbRegion;
class AcDbCurve;

#include "icarx/IcArxPackPush.h"

class AcDb3dSolid : public AcDbEntity
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDb3dSolid);

	AcDb3dSolid();
	~AcDb3dSolid();

	virtual void* ASMBodyCopy(bool bDeepCopy = false) const;
	virtual Acad::ErrorStatus booleanOper(AcDb::BoolOperType operation, AcDb3dSolid* solid);
	virtual Acad::ErrorStatus chamferEdges(const AcArray<AcDbSubentId*>& edgeSubentIds,
										   const AcDbSubentId& baseFaceSubentId, double baseDist,
										   double otherDist);
	virtual Acad::ErrorStatus checkInterference(const AcDb3dSolid* otherSolid, bool createNewSolid,
												bool& solidsInterfere,
												AcDb3dSolid*& commonVolumeSolid) const;
	virtual Acad::ErrorStatus cleanBody();
	virtual void commitWritableASMBody();
	virtual Acad::ErrorStatus convertToBrepAtSubentPaths(const AcDbFullSubentPathArray& paths);
	virtual Acad::ErrorStatus copyEdge(const AcDbSubentId& subentId, AcDbEntity*& newEntity);
	virtual Acad::ErrorStatus copyFace(const AcDbSubentId& subentId, AcDbEntity*& newEntity);
	virtual Acad::ErrorStatus createBox(double xLen, double yLen, double zLen);
	virtual Acad::ErrorStatus createExtrudedSolid(AcDbEntity* pSweepEnt,
												  const AcGeVector3d& directionVec,
												  AcDbSweepOptions& sweepOptions);
	virtual Acad::ErrorStatus createExtrudedSolid(AcDbEntity* pSweepEnt,
												  const AcDbSubentId& faceSubentId,
												  const AcGeVector3d& directionVec,
												  AcDbSweepOptions& sweepOptions);
	virtual Acad::ErrorStatus createExtrudedSolid(AcDbEntity* pSweepEnt,
												  const AcDbSubentId& faceSubentId, double height,
												  AcDbSweepOptions& sweepOptions);
	virtual Acad::ErrorStatus createFrom(const AcDbEntity* pFromEntity);
	virtual Acad::ErrorStatus createFrustum(double height, double xRadius, double yRadius,
											double topXRadius);
	virtual Acad::ErrorStatus createLoftedSolid(AcArray<AcDbEntity*>& crossSectionCurves,
												AcArray<AcDbEntity*>& guideCurves,
												AcDbEntity* pPathCurve,
												AcDbLoftOptions& loftOptions);
	ACDB_PORT Acad::ErrorStatus createLoftedSolid(const AcArray<AcDbLoftProfile*>& crossSections,
												  const AcArray<AcDbLoftProfile*>& guides,
												  AcDbLoftProfile* pPath,
												  AcDbLoftOptions& loftOptions);
	virtual Acad::ErrorStatus createPyramid(double height, int sides, double radius,
											double topRadius = 0.0);
	virtual Acad::ErrorStatus createRevolvedSolid(AcDbEntity* pRevEnt, const AcGePoint3d& axisPnt,
												  const AcGeVector3d& axisDir, double revAngle,
												  double startAngle,
												  AcDbRevolveOptions& revolveOptions);
	virtual Acad::ErrorStatus createRevolvedSolid(AcDbEntity* pRevEnt,
												  const AcDbSubentId& faceSubentId,
												  const AcGePoint3d& axisPnt,
												  const AcGeVector3d& axisDir, double revAngle,
												  double startAngle,
												  AcDbRevolveOptions& revolveOptions);
	Acad::ErrorStatus createSculptedSolid(const AcArray<AcDbEntity*>& limitingBodies,
										  const AcGeIntArray& limitingFlags);
	virtual Acad::ErrorStatus createSphere(double radius);
	virtual Acad::ErrorStatus createSweptSolid(AcDbEntity* pSweepEnt, AcDbEntity* pPathEnt,
											   AcDbSweepOptions& sweepOptions);
	virtual Acad::ErrorStatus createSweptSolid(AcDbEntity* pSweepEnt,
											   const AcDbSubentId& faceSubentId,
											   AcDbEntity* pPathEnt,
											   AcDbSweepOptions& sweepOptions);
	virtual Acad::ErrorStatus createTorus(double majorRadius, double minorRadius);
	virtual Acad::ErrorStatus createWedge(double xLen, double yLen, double zLen);
	ACDB_PORT void dragStatus(const AcDb::DragStat) override;
	virtual Acad::ErrorStatus extrude(const AcDbRegion* region, double height,
									  double taperAngle = 0.0);
	virtual Acad::ErrorStatus extrudeAlongPath(const AcDbRegion* region, const AcDbCurve* path,
											   double taperAngle = 0.0);
	virtual Acad::ErrorStatus extrudeFaces(const AcArray<AcDbSubentId*>& faceSubentIds,
										   double height, double taper);
	virtual Acad::ErrorStatus extrudeFacesAlongPath(const AcArray<AcDbSubentId*>& faceSubentIds,
													const AcDbCurve* path);
	virtual Acad::ErrorStatus filletEdges(const AcArray<AcDbSubentId*>& edgeSubentIds,
										  const AcGeDoubleArray& radius,
										  const AcGeDoubleArray& startSetback,
										  const AcGeDoubleArray& endSetback);
	virtual Acad::ErrorStatus getArea(double& area) const;
	virtual void const* getLockedASMBody();
	virtual void* getLockedWritableASMBody();
	virtual Acad::ErrorStatus getMassProp(double& volume, AcGePoint3d& centroid,
										  double momInertia[3], double prodInertia[3],
										  double prinMoments[3], AcGeVector3d prinAxes[3],
										  double radiiGyration[3], AcDbExtents& extents) const;
	virtual Acad::ErrorStatus getSection(const AcGePlane& plane, AcDbRegion*& sectionRegion) const;
	virtual Acad::ErrorStatus getSlice(const AcGePlane& plane, bool getNegHalfToo,
									   AcDb3dSolid*& negHalfSolid);
	virtual Acad::ErrorStatus getSlice(AcDbSurface* pSurface, bool bGetNegHalfToo,
									   AcDb3dSolid*& pNegHalfSolid);
	virtual Acad::ErrorStatus getSubentColor(const AcDbSubentId& subentId, AcCmColor& color) const;
	virtual Acad::ErrorStatus getSubentMaterial(const AcDbSubentId& subentId,
												AcDbObjectId& matId) const;
	virtual Acad::ErrorStatus getSubentMaterialMapper(const AcDbSubentId& subentId,
													  AcGiMapper& mapper) const;
	virtual Acad::ErrorStatus imprintEntity(const AcDbEntity* pEntity);
	virtual AcDbSubentId internalSubentId(void* ent) const;
	virtual void* internalSubentPtr(const AcDbSubentId& id) const;
	virtual bool isNull() const;
	virtual uint32_t numChanges() const;
	virtual Acad::ErrorStatus offsetBody(double offsetDistance);
	ACDB_PORT virtual Acad::ErrorStatus offsetFaces(const AcArray<AcDbSubentId*>& faceSubentIds,
													double offsetDistance);
	Acad::ErrorStatus projectOnToSolid(const AcDbEntity* pEntityToProject,
									   const AcGeVector3d& projectionDirection,
									   AcArray<AcDbEntity*>& projectedEntities) const;
	virtual bool recordHistory() const;
	virtual Acad::ErrorStatus removeFaces(const AcArray<AcDbSubentId*>& faceSubentIds);
	virtual Acad::ErrorStatus revolve(const AcDbRegion* region, const AcGePoint3d& axisPoint,
									  const AcGeVector3d& axisDir, double angleOfRevolution);
	virtual Acad::ErrorStatus separateBody(AcArray<AcDb3dSolid*>& newSolids);
	virtual Acad::ErrorStatus setASMBody(const void* modelerBody);
	virtual Acad::ErrorStatus setRecordHistory(bool bRecord);
	virtual Acad::ErrorStatus setShowHistory(bool bShow);
	virtual Acad::ErrorStatus setSubentColor(const AcDbSubentId& subentId, const AcCmColor& color);
	virtual Acad::ErrorStatus setSubentMaterial(const AcDbSubentId& subentId, AcDbObjectId matId);
	virtual Acad::ErrorStatus setSubentMaterialMapper(const AcDbSubentId& subentId,
													  const AcGiMapper& mapper);
	virtual Acad::ErrorStatus shellBody(const AcArray<AcDbSubentId*>& faceSubentIds,
										double offsetDistance);
	virtual bool showHistory() const;
	ACDB_PORT virtual Acad::ErrorStatus stlOut(
			const ACHAR* fileName, bool asciiFormat,
			double maxSurfaceDeviation = 0.0 /*use default*/) const;
	virtual Acad::ErrorStatus taperFaces(const AcArray<AcDbSubentId*>& faceSubentIds,
										 const AcGePoint3d& basePoint,
										 const AcGeVector3d& draftVector, double draftAngle);
	virtual Acad::ErrorStatus transformFaces(const AcArray<AcDbSubentId*>& faceSubentIds,
											 const AcGeMatrix3d& matrix);
	virtual void unlockASMBody();
	ACDB_PORT virtual bool usesGraphicsCache();

};

#include "icarx/IcArxPackPop.h"

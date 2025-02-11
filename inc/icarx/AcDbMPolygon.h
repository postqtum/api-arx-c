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
***     Description: Declaration of AcDbMPolygon class
***
*****************************************************************************/
#pragma once

#include "../dbhatch.h"

#include "AcMPolygonPort.h"

class AcDbMPolygonNode;
class AcDbCircle;
class AcDbPolyline;
class AcDb2dPolyline;
class AcDbMPolygonCrossingArray;
class AcDbImpMPolygon;

const double AcDbMPolygonCrossingFuzz = 1E-6;

#include "IcArxPackPush.h"

class AcDbMPolygon : public AcDbEntity
{
public:
	enum loopDir
	{
		kExterior = 0,
		kInterior,
		kAnnotation
	};

public:
	ACMPOLYGON_PORT AcDbMPolygon();
	ACMPOLYGON_PORT ~AcDbMPolygon();

	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbMPolygon, ACMPOLYGON_PORT);

	ACMPOLYGON_PORT virtual Acad::ErrorStatus appendLoopFromBoundary(
			const AcDbCircle* pCircle, bool excludeCrossing = true,
			double tol = AcDbMPolygonCrossingFuzz);
	ACMPOLYGON_PORT virtual Acad::ErrorStatus appendLoopFromBoundary(
			const AcDbPolyline* pPoly, bool excludeCrossing = true,
			double tol = AcDbMPolygonCrossingFuzz);
	ACMPOLYGON_PORT virtual Acad::ErrorStatus appendLoopFromBoundary(
			const AcDb2dPolyline* pPoly, bool excludeCrossing = true,
			double tol = AcDbMPolygonCrossingFuzz);
	ACMPOLYGON_PORT virtual Acad::ErrorStatus appendMPolygonLoop(
			const AcGePoint2dArray& vertices, const AcGeDoubleArray& bulges,
			bool excludeCrossing = true, double tol = AcDbMPolygonCrossingFuzz);
	ACMPOLYGON_PORT Acad::ErrorStatus audit(AcDbAuditInfo*) override;
	ACMPOLYGON_PORT virtual Acad::ErrorStatus balanceDisplay();
	ACMPOLYGON_PORT virtual Acad::ErrorStatus balanceTree();
	ACMPOLYGON_PORT virtual Acad::ErrorStatus createLoops(
			const AcArray<AcGePoint2dArray, AcArrayObjectCopyReallocator<AcGePoint2dArray> >&
					vertices,
			const AcArray<AcGeDoubleArray, AcArrayObjectCopyReallocator<AcGeDoubleArray> >& bulges,
			AcDbIntArray& rejectedObjs, bool excludeCrossing = true,
			double tol = AcDbMPolygonCrossingFuzz);
	ACMPOLYGON_PORT virtual Acad::ErrorStatus createLoopsFromBoundaries(
			const AcDbObjectIdArray& ids, AcDbIntArray& rejectedObjs, bool excludeCrossing = true,
			double tol = AcDbMPolygonCrossingFuzz);
	ACMPOLYGON_PORT Acad::ErrorStatus decomposeForSave(AcDb::AcDbDwgVersion ver,
													   AcDbObject*& replaceObj,
													   AcDbObjectId& replaceId,
													   bool& exchangeXData) override;
	ACMPOLYGON_PORT virtual void deleteMPolygonTree(AcDbMPolygonNode* loopNode) const;
	ACMPOLYGON_PORT Acad::ErrorStatus dwgInFields(AcDbDwgFiler* filer) override;
	ACMPOLYGON_PORT Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* filer) const override;
	ACMPOLYGON_PORT Acad::ErrorStatus dxfInFields(AcDbDxfFiler* filer) override;
	ACMPOLYGON_PORT Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* filer) const override;
	ACMPOLYGON_PORT virtual double elevation() const;
	ACMPOLYGON_PORT virtual Acad::ErrorStatus evaluateHatch(bool bUnderestimateNumLines = false);
	ACMPOLYGON_PORT virtual double getArea() const;
	ACMPOLYGON_PORT virtual void getChildLoops(int curLoop,
											   AcGeIntArray& selectedLoopIndexes) const;
	ACMPOLYGON_PORT virtual int getClosestLoopTo(const AcGePoint3d& worldPt) const;
	ACMPOLYGON_PORT virtual Acad::ErrorStatus getLoopAtGsMarker(int gsMark, int& loop) const;
	ACMPOLYGON_PORT virtual Acad::ErrorStatus getLoopDirection(int lindex,
															   AcDbMPolygon::loopDir& dir) const;
	ACMPOLYGON_PORT virtual Acad::ErrorStatus getMPolygonLoopAt(int loopIndex,
																AcGePoint2dArray& vertices,
																AcGeDoubleArray& bulges) const;
	ACMPOLYGON_PORT virtual Acad::ErrorStatus getMPolygonTree(AcDbMPolygonNode*& loopNode) const;
	ACMPOLYGON_PORT virtual AcGeVector2d getOffsetVector() const;
	ACMPOLYGON_PORT virtual int getParentLoop(int curLoop) const;
	ACMPOLYGON_PORT virtual Acad::ErrorStatus getPatternDefinitionAt(int index, double& angle,
																	 double& baseX, double& baseY,
																	 double& offsetX,
																	 double& offsetY,
																	 AcGeDoubleArray& dashes) const;
	ACMPOLYGON_PORT virtual double getPerimeter() const;
	ACMPOLYGON_PORT virtual AcDbHatch* hatch();
	ACMPOLYGON_PORT virtual bool includesTouchingLoops(double tol = AcDbMPolygonCrossingFuzz) const;
	ACMPOLYGON_PORT virtual Acad::ErrorStatus insertMPolygonLoopAt(
			int loopIndex, const AcGePoint2dArray& vertices, const AcGeDoubleArray& bulges,
			bool excludeCrossing = true, double tol = AcDbMPolygonCrossingFuzz);
	ACMPOLYGON_PORT virtual bool isBalanced() const;
	ACMPOLYGON_PORT virtual int isPointInsideMPolygon(const AcGePoint3d& worldPt,
													  AcGeIntArray& loopsArray,
													  double tol = AcDbMPolygonCrossingFuzz) const;
	ACMPOLYGON_PORT virtual bool isPointOnLoopBoundary(const AcGePoint3d& worldPt, int loop,
													   double tol = AcDbMPolygonCrossingFuzz) const;
	ACMPOLYGON_PORT virtual Acad::ErrorStatus loopCrossesItself(
			bool& crosses, bool findAll, AcDbMPolygonCrossingArray& crossingsArray,
			const AcGePoint2dArray& vertexPts, const AcGeDoubleArray& vertexBulges,
			double tol = AcDbMPolygonCrossingFuzz) const;
	ACMPOLYGON_PORT virtual bool loopCrossesItself(const AcGePoint2dArray& vertexPts,
												   const AcGeDoubleArray& vertexBulges,
												   double tol = AcDbMPolygonCrossingFuzz) const;
	ACMPOLYGON_PORT virtual Acad::ErrorStatus loopCrossesMPolygon(
			bool& crosses, bool findAll, AcDbMPolygonCrossingArray& crossingsArray,
			const AcGePoint2dArray& testVertexPts, const AcGeDoubleArray& testVertexBulges,
			double tol = AcDbMPolygonCrossingFuzz) const;
	ACMPOLYGON_PORT virtual AcGeVector3d normal() const;
	ACMPOLYGON_PORT virtual int numMPolygonLoops() const;
	ACMPOLYGON_PORT virtual int numPatternDefinitions() const;
	ACMPOLYGON_PORT virtual double patternAngle() const;
	ACMPOLYGON_PORT virtual AcCmColor patternColor() const;
	ACMPOLYGON_PORT virtual bool patternDouble() const;
	ACMPOLYGON_PORT virtual const TCHAR* patternName() const;
	ACMPOLYGON_PORT virtual double patternScale() const;
	ACMPOLYGON_PORT virtual double patternSpace() const;
	ACMPOLYGON_PORT virtual AcDbHatch::HatchPatternType patternType() const;
	ACMPOLYGON_PORT virtual Acad::ErrorStatus removeMPolygonLoopAt(int loopIndex);
	ACMPOLYGON_PORT void saveAs(AcGiWorldDraw* mode, AcDb::SaveType st) override;
	ACMPOLYGON_PORT virtual bool selfCrosses(const AcGePoint2dArray& vertexPts,
											 const AcGeDoubleArray& vertexBulges,
											 double tol = AcDbMPolygonCrossingFuzz) const;
	ACMPOLYGON_PORT virtual Acad::ErrorStatus setElevation(double elevation);
	ACMPOLYGON_PORT Acad::ErrorStatus setGradient(AcDbHatch::GradientPatternType gradType,
												  const TCHAR* gradName);
	ACMPOLYGON_PORT Acad::ErrorStatus setGradientAngle(double angle);
	ACMPOLYGON_PORT Acad::ErrorStatus setGradientColors(unsigned int count, AcCmColor* colors,
														float* values);
	ACMPOLYGON_PORT Acad::ErrorStatus setGradientOneColorMode(bool oneColorMode);
	ACMPOLYGON_PORT Acad::ErrorStatus setGradientShift(float shiftValue);
	ACMPOLYGON_PORT virtual Acad::ErrorStatus setLoopDirection(int lindex,
															   AcDbMPolygon::loopDir dir);
	ACMPOLYGON_PORT virtual Acad::ErrorStatus setNormal(const AcGeVector3d& normal);
	ACMPOLYGON_PORT virtual Acad::ErrorStatus setPattern(AcDbHatch::HatchPatternType patType,
														 const TCHAR* patName);
	ACMPOLYGON_PORT virtual Acad::ErrorStatus setPatternAngle(double angle);
	ACMPOLYGON_PORT virtual Acad::ErrorStatus setPatternColor(const AcCmColor& pc);
	ACMPOLYGON_PORT virtual Acad::ErrorStatus setPatternDouble(bool isDouble);
	ACMPOLYGON_PORT virtual Acad::ErrorStatus setPatternScale(double scale);
	ACMPOLYGON_PORT virtual Acad::ErrorStatus setPatternSpace(double space);
	ACMPOLYGON_PORT Acad::ErrorStatus subExplode(AcDbVoidPtrArray& entitySet) const override;
	ACMPOLYGON_PORT Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
	ACMPOLYGON_PORT Acad::ErrorStatus subGetGeomExtents(AcDbExtents& extents) const override;
	ACMPOLYGON_PORT Acad::ErrorStatus subGetGripPoints(AcGePoint3dArray& gripPoints,
													   AcDbIntArray& osnapModes,
													   AcDbIntArray& geomIds) const override;
	ACMPOLYGON_PORT Acad::ErrorStatus subGetGsMarkersAtSubentPath(
			const AcDbFullSubentPath& subPath,
			AcArray<IcArx::Integers::GsMarker>& gsMarkers) const override;
	ACMPOLYGON_PORT Acad::ErrorStatus subGetOsnapPoints(AcDb::OsnapMode osnapMode,
														IcArx::Integers::GsMarker gsSelectionMark,
														const AcGePoint3d& pickPoint,
														const AcGePoint3d& lastPoint,
														const AcGeMatrix3d& viewXform,
														AcGePoint3dArray& snapPoints,
														AcDbIntArray& geomIds) const override;
	ACMPOLYGON_PORT Acad::ErrorStatus subGetStretchPoints(
			AcGePoint3dArray& stretchPoints) const override;
	ACMPOLYGON_PORT Acad::ErrorStatus subGetSubentPathsAtGsMarker(
			AcDb::SubentType type, IcArx::Integers::GsMarker gsMark, const AcGePoint3d& pickPoint,
			const AcGeMatrix3d& viewXform, int& numPaths, AcDbFullSubentPath*& subentPaths,
			int numInserts = 0, AcDbObjectId* entAndInsertStack = nullptr) const override;
	ACMPOLYGON_PORT Acad::ErrorStatus subIntersectWith(
			const AcDbEntity* ent, AcDb::Intersect intType, AcGePoint3dArray& points,
			IcArx::Integers::GsMarker thisGsMarker = 0,
			IcArx::Integers::GsMarker otherGsMarker = 0) const override;
	ACMPOLYGON_PORT Acad::ErrorStatus subIntersectWith(
			const AcDbEntity* ent, AcDb::Intersect intType, const AcGePlane& projPlane,
			AcGePoint3dArray& points, IcArx::Integers::GsMarker thisGsMarker = 0,
			IcArx::Integers::GsMarker otherGsMarker = 0) const override;
	ACMPOLYGON_PORT void subList() const override;
	ACMPOLYGON_PORT Acad::ErrorStatus subMoveGripPointsAt(const AcDbIntArray& indices,
														  const AcGeVector3d& offset) override;
	ACMPOLYGON_PORT Acad::ErrorStatus subMoveStretchPointsAt(const AcDbIntArray& indices,
															 const AcGeVector3d& offset) override;
	ACMPOLYGON_PORT AcDbEntity* subSubentPtr(const AcDbFullSubentPath& id) const override;
	ACMPOLYGON_PORT Acad::ErrorStatus subTransformBy(const AcGeMatrix3d& xform) override;
	ACMPOLYGON_PORT bool subWorldDraw(AcGiWorldDraw* mode) override;
};

#include "IcArxPackPop.h"

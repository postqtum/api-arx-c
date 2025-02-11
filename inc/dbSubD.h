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
***     Description: Declaration of AcDbSubDMesh class
***
*****************************************************************************/
#pragma once

#include "dbsol3d.h"
#include "dbmain.h"
#include "gevc3dar.h"

class AcDbSurface;
class AcGiFaceData;
class AcGiMapper;

#include "icarx/IcArxPackPush.h"

class AcDbSubDMesh : public AcDbEntity
{
	ACDB_DECLARE_MEMBERS_EXPIMP(AcDbSubDMesh, ACDB_PORT);

public:
	ACDB_PORT AcDbSubDMesh();
	ACDB_PORT ~AcDbSubDMesh();

	ACDB_PORT bool bounds(AcDbExtents& retBounds) const override;
	ACDB_PORT Acad::ErrorStatus cap(const AcDbFullSubentPathArray& edgePaths);
	ACDB_PORT Acad::ErrorStatus collapse(const AcDbSubentId& subent);
	ACDB_PORT Acad::ErrorStatus computeRayIntersection(const AcGePoint3d& rayStart,
													   const AcGeVector3d& rayDir,
													   AcArray<AcDbSubentId>& retSubents,
													   AcArray<double>& retIntersectDist,
													   AcGePoint3dArray& retIntersectPoint) const;
	ACDB_PORT Acad::ErrorStatus computeSurfaceArea(double& retSurfArea) const;
	ACDB_PORT Acad::ErrorStatus computeVolume(double& retVolume) const;
	ACDB_PORT Acad::ErrorStatus convertToSolid(bool bConvertAsSmooth, bool optimize,
											   AcDb3dSolid*& pSolid) const;
	ACDB_PORT Acad::ErrorStatus convertToSurface(bool bConvertAsSmooth, const AcDbSubentId& id,
												 AcDbSurface*& pSurface) const;
	ACDB_PORT Acad::ErrorStatus convertToSurface(bool bConvertAsSmooth, bool optimize,
												 AcDbSurface*& pSurface) const;
	ACDB_PORT void dragStatus(const AcDb::DragStat status) override;
	ACDB_PORT Acad::ErrorStatus extrudeConnectedFaces(const AcDbFullSubentPathArray& subentPaths,
													  double length, const AcGeVector3d& dir,
													  double taper);
	ACDB_PORT Acad::ErrorStatus extrudeConnectedFaces(const AcDbFullSubentPathArray& subentPaths,
													  const AcGePoint3dArray& alongPath,
													  double taper);
	ACDB_PORT Acad::ErrorStatus extrudeFaces(const AcDbFullSubentPathArray& subentPaths,
											 double length, const AcGeVector3d& dir, double taper);
	ACDB_PORT Acad::ErrorStatus extrudeFaces(const AcDbFullSubentPathArray& subentPaths,
											 const AcGePoint3dArray& alongPath, double taper);
	ACDB_PORT Acad::ErrorStatus getAdjacentSubentPath(const AcDbFullSubentPath& path,
													  AcDb::SubentType type,
													  AcDbFullSubentPathArray& subentPaths) const;
	ACDB_PORT Acad::ErrorStatus getCrease(const AcDbFullSubentPathArray& subentPaths,
										  AcArray<double>& result) const;
	ACDB_PORT Acad::ErrorStatus getCrease(const AcDbSubentId& id, double& result) const;
	ACDB_PORT Acad::ErrorStatus getEdgeArray(AcArray<int32_t>& edgeArray) const;
	ACDB_PORT Acad::ErrorStatus getFaceArray(AcArray<int32_t>& faceArray) const;
	ACDB_PORT Acad::ErrorStatus getFacePlane(const AcDbSubentId& id, AcGePlane& facePlane) const;
	ACDB_PORT Acad::ErrorStatus getNormalArray(AcGeVector3dArray& normalArray) const;
	ACDB_PORT Acad::ErrorStatus getSubDividedFaceArray(AcArray<int32_t>& faceArray) const;
	ACDB_PORT Acad::ErrorStatus getSubDividedNormalArray(AcGeVector3dArray& normalArray) const;
	ACDB_PORT Acad::ErrorStatus getSubDividedVertexAt(int32_t nIndex, AcGePoint3d& vertex) const;
	ACDB_PORT Acad::ErrorStatus getSubDividedVertexAt(const AcDbSubentId& id,
													  AcGePoint3d& vertex) const;
	ACDB_PORT Acad::ErrorStatus getSubDividedVertices(AcGePoint3dArray& vertexArray) const;
	ACDB_PORT Acad::ErrorStatus getSubentColor(const AcDbSubentId& id, AcCmColor& color) const;
	ACDB_PORT Acad::ErrorStatus getSubentMaterial(const AcDbSubentId& id,
												  AcDbObjectId& material) const;
	ACDB_PORT Acad::ErrorStatus getSubentMaterialMapper(const AcDbSubentId& id,
														AcGiMapper& mapper) const;
	ACDB_PORT Acad::ErrorStatus getSubentPath(int32_t nIndex, AcDb::SubentType type,
											  AcDbFullSubentPathArray& subentPaths) const;
	ACDB_PORT Acad::ErrorStatus getVertexAt(int32_t nIndex, AcGePoint3d& vertex) const;
	ACDB_PORT Acad::ErrorStatus getVertexAt(const AcDbSubentId& id, AcGePoint3d& vertex) const;
	ACDB_PORT Acad::ErrorStatus getVertexColorArray(AcArray<AcCmEntityColor>& arr);
	ACDB_PORT Acad::ErrorStatus getVertexNormalArray(AcGeVector3dArray& arr);
	ACDB_PORT Acad::ErrorStatus getVertexTextureArray(AcGePoint3dArray& arr);
	ACDB_PORT Acad::ErrorStatus getVertices(AcGePoint3dArray& vertexArray) const;
	ACDB_PORT Acad::ErrorStatus isWatertight(bool& result) const;
	ACDB_PORT Acad::ErrorStatus mergeFaces(const AcDbFullSubentPathArray& subentPaths);
	ACDB_PORT Acad::ErrorStatus numOfEdges(int32_t& result) const;
	ACDB_PORT Acad::ErrorStatus numOfFaces(int32_t& result) const;
	ACDB_PORT Acad::ErrorStatus numOfSubDividedFaces(int32_t& result) const;
	ACDB_PORT Acad::ErrorStatus numOfSubDividedFacesAt(const AcDbFullSubentPathArray& subentPaths,
													   int32_t& result) const;
	ACDB_PORT Acad::ErrorStatus numOfSubDividedVertices(int32_t& result) const;
	ACDB_PORT Acad::ErrorStatus numOfVertices(int32_t& result) const;
	ACDB_PORT Acad::ErrorStatus setBox(double xLen, double yLen, double zLen, int divX, int divY,
									   int divZ, int subDLevel);
	ACDB_PORT Acad::ErrorStatus setBox(const AcGeMatrix3d& xForm, int divX, int divY, int divZ,
									   int subDLevel);
	ACDB_PORT Acad::ErrorStatus setCone(double majorRadius, double minorRadius, double height,
										int divAxis, int divHeight, int divCap, double radiusRatio,
										int subDLevel);
	ACDB_PORT Acad::ErrorStatus setCone(const AcGeMatrix3d& xForm, int divAxis, int divHeight,
										int divCap, double radiusRatio, int subDLevel);
	ACDB_PORT Acad::ErrorStatus setCrease(double creaseVal);
	ACDB_PORT Acad::ErrorStatus setCrease(const AcDbFullSubentPathArray& subentPaths,
										  double creaseVal);
	ACDB_PORT Acad::ErrorStatus setCylinder(double majorRadius, double minorRadius, double height,
											int divAxis, int divHeight, int divCap, int subDLevel);
	ACDB_PORT Acad::ErrorStatus setCylinder(const AcGeMatrix3d& xForm, int divAxis, int divHeight,
											int divCap, int subDLevel);
	ACDB_PORT Acad::ErrorStatus setPyramid(double radius, double height, int divLength,
										   int divHeight, int divCap, int nSides,
										   double radiusRatio, int subDLevel);
	ACDB_PORT Acad::ErrorStatus setPyramid(const AcGeMatrix3d& xForm, int divLength, int divHeight,
										   int divCap, int nSides, double radiusRatio,
										   int subDLevel);
	ACDB_PORT Acad::ErrorStatus setSphere(double radius, int divAxis, int divHeight, int subDLevel);
	ACDB_PORT Acad::ErrorStatus setSphere(const AcGeMatrix3d& xForm, int divAxis, int divHeight,
										  int subDLevel);
	ACDB_PORT Acad::ErrorStatus setSubDMesh(const AcGePoint3dArray& vertexArray,
											const AcArray<int32_t>& faceArray, int subDLevel);
	ACDB_PORT Acad::ErrorStatus setSubentColor(const AcDbSubentId& id, const AcCmColor& color);
	ACDB_PORT Acad::ErrorStatus setSubentMaterial(const AcDbSubentId& id,
												  const AcDbObjectId& material);
	ACDB_PORT Acad::ErrorStatus setSubentMaterialMapper(const AcDbSubentId& id,
														const AcGiMapper& mapper);
	ACDB_PORT Acad::ErrorStatus setTorus(double majorRadius, int divSection, int divSweepPath,
										 double sectionRadiusRatio, double sectionRotate,
										 int subDLevel);
	ACDB_PORT Acad::ErrorStatus setTorus(const AcGeMatrix3d& xForm, int divSection,
										 int divSweepPath, double sectionRadiusRatio,
										 double sectionRotate, int subDLevel);
	ACDB_PORT Acad::ErrorStatus setVertexAt(int32_t nIndex, const AcGePoint3d& vertex);
	ACDB_PORT Acad::ErrorStatus setVertexAt(const AcDbSubentId& id, const AcGePoint3d& vertex);
	ACDB_PORT Acad::ErrorStatus setVertexColorArray(AcArray<AcCmEntityColor>& arr);
	ACDB_PORT Acad::ErrorStatus setVertexNormalArray(AcGeVector3dArray& arr);
	ACDB_PORT Acad::ErrorStatus setVertexTextureArray(AcGePoint3dArray& arr);
	ACDB_PORT Acad::ErrorStatus setWedge(double xLen, double yLen, double zLen, int divLength,
										 int divWidth, int divHeight, int divSlope, int divCap,
										 int subDLevel);
	ACDB_PORT Acad::ErrorStatus setWedge(const AcGeMatrix3d& xForm, int divLength, int divWidth,
										 int divHeight, int divSlope, int divCap, int subDLevel);
	ACDB_PORT Acad::ErrorStatus spin(const AcDbSubentId& subent);
	ACDB_PORT Acad::ErrorStatus splitFace(const AcDbSubentId& subentFaceId,
										  const AcDbSubentId& subent0, const AcGePoint3d& point0,
										  const AcDbSubentId& subent1, const AcGePoint3d& point1);
	ACDB_PORT Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
	ACDB_PORT Acad::ErrorStatus subdDivideDown();
	ACDB_PORT Acad::ErrorStatus subdDivideUp();
	ACDB_PORT Acad::ErrorStatus subdLevel(int32_t& result) const;
	ACDB_PORT Acad::ErrorStatus subdRefine();
	ACDB_PORT Acad::ErrorStatus subdRefine(const AcDbFullSubentPathArray& subentPaths);
};

struct MeshFaceterSettings
{
	double faceterDevSurface;
	double faceterDevNormal;
	double faceterGridRatio;
	double faceterMaxEdgeLength;
	uint16_t faceterMaxGrid;
	uint16_t faceterMinUGrid;
	uint16_t faceterMinVGrid;
	int16_t faceterMeshType;
};

#include "icarx/IcArxPackPop.h"

typedef struct MeshFaceterSettings AcDbFaceterSettings;

ACDB_PORT Acad::ErrorStatus acdbGetObjectMesh(AcDbObject* pObj, const AcDbFaceterSettings* faceter,
											  AcGePoint3dArray& vertexArray,
											  AcArray<int32_t>& faceArray,
											  AcGiFaceData*& faceData);

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
***     Description: Declaration of AcDbGeoMap class
***
*****************************************************************************/
#pragma once

#include <new>

#include "imgent.h"
#include "AcDbGeoTypes.h"

#ifdef ACGEOLOCATIONOBJ_API
#	define ACGEOLOCATIONOBJ_PORT __declspec(dllexport)
#else
#	define ACGEOLOCATIONOBJ_PORT
#endif

#include "icarx/IcArxPackPush.h"
#pragma warning(disable : 4275)

class ACGEOLOCATIONOBJ_PORT AcDbGeoMap : public AcDbRasterImage
{
	friend class AcDbGeoMapSystemInternals;

private:
	void operator delete[](void*){};
	void* operator new[](size_t) { throw std::bad_alloc(); };
	void* operator new[](size_t, const char*, int) { throw std::bad_alloc(); };

protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
	Acad::ErrorStatus subGetGeomExtents(AcDbExtents& extents) const override;
	void subList() const override;
	uint32_t subSetAttributes(AcGiDrawableTraits* pTraits) override;
	void subViewportDraw(AcGiViewportDraw* pViewportDraw) override;
	bool subWorldDraw(AcGiWorldDraw* pWorldDraw) override;

public:
	ACRX_DECLARE_MEMBERS(AcDbGeoMap);

	AcDbGeoMap();
	AcDbGeoMap(AcGeoMapType mapType, AcGeoMapResolution resolution, unsigned int levelOfDetail);
	AcDbGeoMap(AcDbObjectId viewportId, bool isViewportSpecific);
	~AcDbGeoMap();

	unsigned int LOD() const;
	Acad::ErrorStatus applyPartialUndo(AcDbDwgFiler* undoFiler, AcRxClass* classObj) override;
	AcGePoint3d bottomLeftPt() const;
	int8_t brightness() const override;
	const AcGePoint2dArray& clipBoundary() const override;
	int8_t contrast() const override;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	int8_t fade() const override;
	bool freeScanLines(AcGiSentScanLines* pSSL) const override;
	Acad::ErrorStatus getImageVertices(AcGePoint3dArray& verts) const;
	void getOrientation(AcGePoint3d& origin, AcGeVector3d& u, AcGeVector3d& v) const override;
	AcGiSentScanLines* getScanLines(const AcGiRequestScanLines& req) const override;
	Acad::ErrorStatus getVertices(AcGePoint3dArray& verts) const override;
	double height() const;
	AcGePoint3d imageBottomLeftPt() const;
	AcDbObjectId imageDefId() const override;
	double imageHeight() const;
	AcGeVector2d imageSize(bool bGetCachedValue = false) const override;
	double imageWidth() const;
	bool isOutOfDate() const;
	AcGeoMapType mapType() const;
	AcGeoMapResolution resolution() const;
	Acad::ErrorStatus setBrightness(int8_t value) override;
	Acad::ErrorStatus setContrast(int8_t value) override;
	Acad::ErrorStatus setFade(int8_t value) override;
	Acad::ErrorStatus setMapType(AcGeoMapType mapType);
	Acad::ErrorStatus setResolution(AcGeoMapResolution resolution);
	Acad::ErrorStatus subErase(bool erasing) override;
	Acad::ErrorStatus subGetGripPoints(AcDbGripDataPtrArray& grips, const double curViewUnitSize,
									   const int gripSize, const AcGeVector3d& curViewDir,
									   const int bitflags) const override;
	Acad::ErrorStatus subGetGripPoints(AcGePoint3dArray& gripPoints, AcDbIntArray& osnapModes,
									   AcDbIntArray& geomIds) const override;
	Acad::ErrorStatus subGetOsnapPoints(AcDb::OsnapMode osnapMode,
										IcArx::Integers::GsMarker gsSelectionMark,
										const AcGePoint3d& pickPoint, const AcGePoint3d& lastPoint,
										const AcGeMatrix3d& viewXform, AcGePoint3dArray& snapPoints,
										AcDbIntArray& geomIds) const override;
	Acad::ErrorStatus subIntersectWith(const AcDbEntity* ent, AcDb::Intersect intType,
									   AcGePoint3dArray& points,
									   IcArx::Integers::GsMarker thisGsMarker = 0,
									   IcArx::Integers::GsMarker otherGsMarker = 0) const override;
	Acad::ErrorStatus subIntersectWith(const AcDbEntity* ent, AcDb::Intersect intType,
									   const AcGePlane& projPlane, AcGePoint3dArray& points,
									   IcArx::Integers::GsMarker thisGsMarker = 0,
									   IcArx::Integers::GsMarker otherGsMarker = 0) const override;
	Acad::ErrorStatus subMoveGripPointsAt(const AcDbIntArray& indices,
										  const AcGeVector3d& offset) override;
	Acad::ErrorStatus subMoveGripPointsAt(const AcDbVoidPtrArray& gripAppData,
										  const AcGeVector3d& offset, const int bitflags) override;
	Acad::ErrorStatus subTransformBy(const AcGeMatrix3d& xform) override;
	bool updateMapImage(bool bReset = false);
	double width() const;
};

#include "icarx/IcArxPackPop.h"

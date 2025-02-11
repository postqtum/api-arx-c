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

#include "dbents.h"
#include "dbimage.h"
#include "acgi.h"
#include "gept3dar.h"
#include "gebndpln.h"
#include "geplin2d.h"
#include "dbproxy.h"

#include "icarx/AcDbRasterImageDef.h"
#include "icarx/IsmDllAccess.h"

const double kEpsilon = 1.0e-7;

const int kAllEntityProxyFlags =
		AcDbProxyEntity::kEraseAllowed | AcDbProxyEntity::kTransformAllowed |
		AcDbProxyEntity::kColorChangeAllowed | AcDbProxyEntity::kLayerChangeAllowed |
		AcDbProxyEntity::kLinetypeChangeAllowed | AcDbProxyEntity::kMaterialChangeAllowed |
		AcDbProxyEntity::kLinetypeScaleChangeAllowed | AcDbProxyEntity::kVisibilityChangeAllowed;

class RasterImageImp;

#include "icarx/IcArxPackPush.h"
#pragma warning(disable : 4275)

class ISMDLLACCESS AcDbRasterImage : public AcDbImage
{
	friend class AcDbImpRasterImage;

public:
	enum ClipBoundaryType
	{
		kInvalid,
		kRect,
		kPoly
	};

	enum ImageDisplayOpt
	{
		kShow = 1,
		kShowUnAligned = 2,
		kClip = 4,
		kTransparent = 8
	};

private:
	RasterImageImp* mpImp = nullptr;
	static ClassVersion mVersion;

private:
	void operator delete[](void*) {}
	void* operator new[](size_t) noexcept { return nullptr; }
	void* operator new[](size_t, const char*, int) noexcept { return nullptr; }

protected:
	AcDbRasterImage(AcDbSystemInternals* pSys);

public:
	ACRX_DECLARE_MEMBERS(AcDbRasterImage);

	AcDbRasterImage();
	~AcDbRasterImage();

	virtual int8_t brightness() const;
	bool castShadows() const override;
	static ClassVersion classVersion() { return mVersion; }
	virtual const AcGePoint2dArray& clipBoundary() const;
	virtual ClipBoundaryType clipBoundaryType() const;
	virtual int8_t contrast() const;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* filer) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* filer) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* filer) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* filer) const override;
	virtual int8_t fade() const;
	bool freeScanLines(AcGiSentScanLines* pSSL) const override;
	virtual void getOrientation(AcGePoint3d& origin, AcGeVector3d& u, AcGeVector3d& v) const;
	virtual Acad::ErrorStatus getPixelToModelTransform(AcGeMatrix3d&) const;
	AcGiSentScanLines* getScanLines(const AcGiRequestScanLines& req) const override;
	virtual Acad::ErrorStatus getVertices(AcGePoint3dArray& verts) const;
	double height() const;
	virtual AcDbObjectId imageDefId() const;
	double imageHeight() const;
	virtual AcGeVector2d imageSize(bool bGetCachedValue = false) const;
	double imageWidth() const;
	virtual bool isClipInverted() const;
	bool isClipped() const;
	bool isImageShown() const;
	bool isImageTransparent() const;
	virtual bool isSetDisplayOpt(ImageDisplayOpt option) const;
	bool isShownClipped() const;
	AcGePoint3d position() const;
	RasterImageImp* ptrImp() const { return mpImp; }
	virtual AcDbObjectId reactorId() const;
	bool receiveShadows() const override;
	double rotation() const;
	void saveAs(AcGiWorldDraw* mode, AcDb::SaveType st) override;
	virtual AcGeVector2d scale() const;
	virtual Acad::ErrorStatus setBrightness(int8_t value);
	void setCastShadows(bool newVal) override;
	virtual Acad::ErrorStatus setClipBoundary(ClipBoundaryType type, const AcGePoint2dArray&);
	Acad::ErrorStatus setClipBoundaryToWholeImage()
	{
		AcGeVector2d size(0, 0);
		return setClipBoundaryToWholeImage(size);
	}
	virtual Acad::ErrorStatus setClipBoundaryToWholeImage(AcGeVector2d& size);
	virtual void setClipInverted(bool newVal);
	virtual Acad::ErrorStatus setContrast(int8_t value);
	virtual void setDisplayOpt(ImageDisplayOpt option, bool bValue);
	virtual Acad::ErrorStatus setFade(int8_t value);
	Acad::ErrorStatus setHeight(double);
	virtual Acad::ErrorStatus setImageDefId(AcDbObjectId imageId);
	void setImageTransparency(bool value);
	virtual bool setOrientation(const AcGePoint3d& origin, const AcGeVector3d& uCorner,
								const AcGeVector3d& vOnPlane);
	RasterImageImp* setPtrImp(RasterImageImp* pImp);
	virtual void setReactorId(AcDbObjectId reactorId);
	void setReceiveShadows(bool newVal) override;
	Acad::ErrorStatus setRotation(double rotation);
	void setShowClipped(bool value);
	void setShowImage(bool value);
	Acad::ErrorStatus setWidth(double);
	Acad::ErrorStatus subSwapIdWith(AcDbObjectId otherId, bool swapXdata = false,
									bool swapExtDict = false) override;
	double width() const;

protected:
	void baseList() const;
	Acad::ErrorStatus subExplode(AcDbVoidPtrArray& entitySet) const override;
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
	Acad::ErrorStatus subGetStretchPoints(AcGePoint3dArray& stretchPoints) const override;
	Acad::ErrorStatus subGetSubentPathsAtGsMarker(
			AcDb::SubentType type, IcArx::Integers::GsMarker gsMark, const AcGePoint3d& pickPoint,
			const AcGeMatrix3d& viewXform, int& numPaths, AcDbFullSubentPath*& subentPaths,
			int numInserts = 0, AcDbObjectId* entAndInsertStack = 0) const override;
	Acad::ErrorStatus subGetTransformedCopy(const AcGeMatrix3d& xform,
											AcDbEntity*& ent) const override;
	void subGripStatus(const AcDb::GripStat status) override;
	Acad::ErrorStatus subIntersectWith(const AcDbEntity* ent, AcDb::Intersect intType,
									   AcGePoint3dArray& points,
									   IcArx::Integers::GsMarker thisGsMarker = 0,
									   IcArx::Integers::GsMarker otherGsMarker = 0) const override;
	Acad::ErrorStatus subIntersectWith(const AcDbEntity* ent, AcDb::Intersect intType,
									   const AcGePlane& projPlane, AcGePoint3dArray& points,
									   IcArx::Integers::GsMarker thisGsMarker = 0,
									   IcArx::Integers::GsMarker otherGsMarker = 0) const override;
	void subList() const override;
	Acad::ErrorStatus subMoveGripPointsAt(const AcDbVoidPtrArray& gripAppData,
										  const AcGeVector3d& offset, const int bitflags) override;
	Acad::ErrorStatus subMoveGripPointsAt(const AcDbIntArray& indices,
										  const AcGeVector3d& offset) override;
	Acad::ErrorStatus subMoveStretchPointsAt(const AcDbIntArray& indices,
											 const AcGeVector3d& offset) override;
	AcDbEntity* subSubentPtr(const AcDbFullSubentPath& id) const override;
	Acad::ErrorStatus subTransformBy(const AcGeMatrix3d& xform) override;
	void subViewportDraw(AcGiViewportDraw* mode) override;
	bool subWorldDraw(AcGiWorldDraw* mode) override;
};

inline RasterImageImp* AcDbRasterImage::setPtrImp(RasterImageImp* pImp)
{
	RasterImageImp* oldImp = mpImp;
	mpImp = pImp;
	return oldImp;
}

inline void modelToPixel(const AcGeMatrix3d& modToPix, const AcGePoint3d& modPt, AcGePoint2d& pixPt)
{
	AcGePoint3d modelPt = modPt;
	modelPt.transformBy(modToPix);
	pixPt.set(modelPt.x, modelPt.y);
}

inline void modelToPixel(const AcGeVector3d& viewDir, const AcGeMatrix3d& modToPix,
						 const AcGePlane& plane, const AcGePoint3d& modPt, AcGePoint2d& pixPt)
{
	AcGePoint3d ptOnPlane = modPt.project(plane, viewDir);
	ptOnPlane.transformBy(modToPix);
	pixPt.set(ptOnPlane.x, ptOnPlane.y);
}

inline void pixelToModel(const AcGeMatrix3d& pixToMod, const AcGePoint2d& pixPt, AcGePoint3d& modPt)
{
	modPt.set(pixPt.x, pixPt.y, 0);
	modPt.transformBy(pixToMod);
}

#pragma warning(default : 4275)

#include "icarx/IcArxPackPop.h"

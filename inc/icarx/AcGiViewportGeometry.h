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
***     Description: Declaration of AcGiViewportGeometry and OwnerDraw3d classes
***
*****************************************************************************/
#pragma once

#include "AcGiGeometry.h"

class AcDbRasterImage;
class AcDbObjectId;
class OwnerDraw;

#include "IcArxPackPush.h"

class OwnerDraw3d
{
public:
	virtual ~OwnerDraw3d() = default;
};

class AcGiViewportGeometry : public AcGiGeometry
{
public:
	enum ImageSource
	{
		kFromDwg,
		kFromOleObject,
		kFromRender
	};

	ACRX_DECLARE_MEMBERS(AcGiViewportGeometry);

	virtual bool ownerDraw3d(AcGePoint3d& /*minBounds*/, AcGePoint3d& /*maxBounds*/,
							 OwnerDraw3d* /*pOwnerDraw*/
	) const
	{
		return false;
	};
	virtual bool ownerDrawDc(int32_t vpnumber, int32_t left, int32_t top, int32_t right,
							 int32_t bottom, const OwnerDraw* pOwnerDraw) const = 0;
	virtual bool polygonDc(const uint32_t nbPoints, const AcGePoint3d* pPoints) const = 0;
	virtual bool polygonEye(const uint32_t nbPoints, const AcGePoint3d* pPoints) const = 0;
	virtual bool polylineDc(const uint32_t nbPoints, const AcGePoint3d* pPoints) const = 0;
	virtual bool polylineEye(const uint32_t nbPoints, const AcGePoint3d* pPoints) const = 0;
	virtual bool rasterImageDc(const AcGePoint3d& origin, const AcGeVector3d& u,
							   const AcGeVector3d& v, const AcGeMatrix2d& pixelToDc,
							   AcDbObjectId entityId, AcGiImageOrg imageOrg, uint32_t imageWidth,
							   uint32_t imageHeight, int16_t imageColorDepth, bool transparency,
							   ImageSource source, const AcGeVector3d& unrotatedU,
							   const AcGiImageOrg origionalImageOrg,
							   const AcGeMatrix2d& unrotatedPixelToDc,
							   const uint32_t unrotatedImageWidth,
							   const uint32_t unrotatedImageHeight) const = 0;
	virtual bool rasterImageDcUsingRawPointer(
			const AcGePoint3d& origin, const AcGeVector3d& u, const AcGeVector3d& v,
			const AcGeMatrix2d& pixelToDc, AcDbRasterImage* pRasterImage, AcGiImageOrg imageOrg,
			uint32_t imageWidth, uint32_t imageHeight, int16_t imageColorDepth, bool transparency,
			ImageSource source, const AcGeVector3d& unrotatedU,
			const AcGiImageOrg origionalImageOrg, const AcGeMatrix2d& unrotatedPixelToDc,
			const uint32_t unrotatedImageWidth, const uint32_t unrotatedImageHeight) const
	{
		return false;
	};
};

#include "IcArxPackPop.h"

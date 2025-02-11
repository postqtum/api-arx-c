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
***     Description: Declaration of AcGiGeometry class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../rxboiler.h"
#include "../acgidefs.h"
#include "../acarray.h"
#include "../gepnt3d.h"
#include "../gemat3d.h"
#include "../AcGiLineAttributes.h"

class AcGeVector3d;
class AcGePoint2d;
class AcGiPolyline;
class AcCmEntityColor;
class AcCmTransparency;
class AcGiEdgeData;
class AcGiFaceData;
class AcGiVertexData;
class AcGiTextStyle;
class AcDbPolyline;
class AcGiDrawable;
class AcGiImageBGRA32;
struct AcGiClipBoundary;
class AcGiGdiDrawObject;
class AcGeCurve2d;

enum AcGiOrientationTransformBehavior
{
	kAcGiWorldOrientation,
	kAcGiScreenOrientation,
	kAcGiZAxisOrientation
};

enum AcGiPositionTransformBehavior
{
	kAcGiWorldPosition,
	kAcGiViewportPosition,
	kAcGiScreenPosition,
	kAcGiScreenLocalOriginPosition,
	kAcGiWorldWithScreenOffsetPosition
};

enum AcGiScaleTransformBehavior
{
	kAcGiWorldScale,
	kAcGiViewportScale,
	kAcGiScreenScale,
	kAcGiViewportLocalOriginScale,
	kAcGiScreenLocalOriginScale
};

#include "IcArxPackPush.h"

class AcGiGeometry : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcGiGeometry);

	enum TransparencyMode
	{
		kTransparencyOff,
		kTransparency1Bit,
		kTransparency8Bit,
	};

	virtual bool circle(const AcGePoint3d& center, const double radius,
						const AcGeVector3d& normal) const = 0;
	virtual bool circle(const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&) const = 0;
	virtual bool circularArc(const AcGePoint3d& center, const double radius,
							 const AcGeVector3d& normal, const AcGeVector3d& startVector,
							 const double sweepAngle,
							 const AcGiArcType arcType = kAcGiArcSimple) const = 0;
	virtual bool circularArc(const AcGePoint3d& start, const AcGePoint3d& point,
							 const AcGePoint3d& end,
							 const AcGiArcType arcType = kAcGiArcSimple) const = 0;
	virtual bool draw(AcGiDrawable*) const = 0;
	virtual bool edge(const AcArray<AcGeCurve2d*>& edges) const = 0;
	virtual bool ellipticalArc(const AcGePoint3d& center, const AcGeVector3d& normal,
							   double majorAxisLength, double minorAxisLength,
							   double startDegreeInRads, double endDegreeInRads,
							   double tiltDegreeInRads,
							   AcGiArcType arcType = kAcGiArcSimple) const = 0;
	virtual void getModelToWorldTransform(AcGeMatrix3d&) const = 0;
	virtual void getWorldToModelTransform(AcGeMatrix3d&) const = 0;
	virtual bool image(const AcGiImageBGRA32& imageSource, const AcGePoint3d& position,
					   const AcGeVector3d& u,  // orientation and magnitude of width
					   const AcGeVector3d& v,  // orientation and magnitude of height
					   TransparencyMode transparencyMode = kTransparency8Bit) const = 0;
	virtual bool mesh(const uint32_t rows, const uint32_t columns, const AcGePoint3d* pVertexList,
					  const AcGiEdgeData* pEdgeData = nullptr,
					  const AcGiFaceData* pFaceData = nullptr,
					  const AcGiVertexData* pVertexData = nullptr,
					  const bool bAutoGenerateNormals = true) const = 0;
	virtual bool ownerDraw(AcGiGdiDrawObject* /*pObject*/, const AcGePoint3d& /*position*/,
						   const AcGeVector3d& /*u*/, const AcGeVector3d& /*v*/
	) const
	{
		return true;
	};
	virtual bool pline(const AcDbPolyline& lwBuf, uint32_t fromIndex = 0,
					   uint32_t numSegs = 0) const = 0;
	virtual bool polyPolygon(const uint32_t numPolygonIndices, const uint32_t* numPolygonPositions,
							 const AcGePoint3d* polygonPositions, const uint32_t* numPolygonPoints,
							 const AcGePoint3d* polygonPoints,
							 const AcCmEntityColor* outlineColors = nullptr,
							 const AcGiLineType* outlineTypes = nullptr,
							 const AcCmEntityColor* fillColors = nullptr,
							 const AcCmTransparency* fillOpacities = nullptr) const = 0;
	virtual bool polyPolyline(uint32_t nbPolylines, const AcGiPolyline* pPolylines) const = 0;
	virtual bool polypoint(const uint32_t nbPoints, const AcGePoint3d* pVertexList,
						   const AcGeVector3d* pNormal = nullptr,
						   const IcArx::Integers::LongPtr* pSubEntMarkers = nullptr) const
	{
		AcGePoint3d pline[2];
		bool retval = false;
		for (uint32_t i = 0; i < nbPoints; i++)
		{
			pline[1] = pline[0] = pVertexList[i];
			retval = polyline(2, pline, pNormal ? &pNormal[i] : nullptr,
							  pSubEntMarkers ? pSubEntMarkers[i] : -1);
			if (retval)
				return retval;
		}
		return retval;
	};
	virtual bool polygon(const uint32_t nbPoints, const AcGePoint3d* pVertexList) const = 0;
	virtual bool polyline(const AcGiPolyline& polylineObj) const = 0;
	virtual bool polyline(const uint32_t nbPoints, const AcGePoint3d* pVertexList,
						  const AcGeVector3d* pNormal = nullptr,
						  IcArx::Integers::LongPtr lBaseSubEntMarker = -1) const = 0;
	virtual void popClipBoundary() = 0;
	virtual bool popModelTransform() = 0;
	virtual bool pushClipBoundary(AcGiClipBoundary* pBoundary) = 0;
	virtual bool pushModelTransform(const AcGeMatrix3d& xMat) = 0;
	virtual bool pushModelTransform(const AcGeVector3d& vNormal) = 0;
	virtual AcGeMatrix3d pushOrientationTransform(AcGiOrientationTransformBehavior behavior) = 0;
	virtual AcGeMatrix3d pushPositionTransform(AcGiPositionTransformBehavior behavior,
											   const AcGePoint2d& offset) = 0;
	virtual AcGeMatrix3d pushPositionTransform(AcGiPositionTransformBehavior behavior,
											   const AcGePoint3d& offset) = 0;
	virtual AcGeMatrix3d pushScaleTransform(AcGiScaleTransformBehavior behavior,
											const AcGePoint2d& extents) = 0;
	virtual AcGeMatrix3d pushScaleTransform(AcGiScaleTransformBehavior behavior,
											const AcGePoint3d& extents) = 0;
	virtual bool ray(const AcGePoint3d&, const AcGePoint3d&) const = 0;
	virtual bool rowOfDots(int count, const AcGePoint3d& start, const AcGeVector3d& step) const = 0;
	virtual bool shell(const uint32_t nbVertex, const AcGePoint3d* pVertexList,
					   const uint32_t faceListSize, const int32_t* pFaceList,
					   const AcGiEdgeData* pEdgeData = nullptr,
					   const AcGiFaceData* pFaceData = nullptr,
					   const AcGiVertexData* pVertexData = nullptr,
					   const struct resbuf* pResBuf = nullptr,
					   const bool bAutoGenerateNormals = true) const = 0;
	virtual bool text(const AcGePoint3d& position, const AcGeVector3d& normal,
					  const AcGeVector3d& direction, const ACHAR* pMsg, const int32_t length,
					  const bool raw, const AcGiTextStyle& pTextStyle) const = 0;
	virtual bool text(const AcGePoint3d& position, const AcGeVector3d& normal,
					  const AcGeVector3d& direction, const double height, const double width,
					  const double oblique, const ACHAR* pMsg) const = 0;
	virtual bool worldLine(const AcGePoint3d pnts[2])
	{
		AcGePoint3d polyPnts[2];
		AcGeMatrix3d mat;
		getWorldToModelTransform(mat);
		polyPnts[0] = mat * pnts[0];
		polyPnts[1] = mat * pnts[1];
		return polyline(2, polyPnts);
	};
	virtual bool xline(const AcGePoint3d&, const AcGePoint3d&) const = 0;
};

#include "IcArxPackPop.h"

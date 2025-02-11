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
***     Description: Declaration of AcGsModel class
***
*****************************************************************************/
#pragma once

#include "../drawable.h"
#include "../gept3dar.h"

#ifndef DRAWBRIDGE_API
#define DRAWBRIDGE_API
#endif

class AcGeMatrix3d;
class AcGePoint3d;
class AcGiVisualStyle;
class AcGsGraphicsKernel;

#include "IcArxPackPush.h"

class AcGsModel
{
public:
	enum InvalidationHint
	{
		kInvalidateNone,
		kInvalidateIsolines,
		kInvalidateViewportCache,
		kInvalidateAll,
		kInvalidateAllStatic,
		kInvalidateFacets,
		kInvalidateFills,
		kInvalidateLinetypes,
		kInvalidateMaterials,
		kInvalidateLayers,
		kInvalidateXrefs,
		kInvalidateRasterImages,
		kInvalidateAttributes,
		kInvalidateUnderlayFrame,
		kInvalidateLtScale,
		kInvalidateTransform,
		kInvalidateTransparencies,
		kInvalidateDrawableByView
	};

	enum OrderActionType
	{
		kMoveBelow,
		kMoveAbove,
		kSwapOrder,
	};

	enum RenderType
	{
		kMain,
		kSprite,
		kDirect,
		kHighlight,
		kHighlightSelection,
		kDirectTopmost,
		kContrast,
		kCount
	};

public:
	virtual DRAWBRIDGE_API ~AcGsModel();

	virtual bool addSceneGraphRoot(AcGiDrawable* pRoot) = 0;
	virtual AcDbObjectId background() const = 0;
	virtual bool bounds(const AcGiDrawable& drawable, AcGePoint3d& minPt, AcGePoint3d& maxPt) = 0;
	virtual void enableLinetypes(bool bEnable) = 0;
	virtual bool eraseSceneGraphRoot(AcGiDrawable* pRoot) = 0;
	virtual AcGsGraphicsKernel& graphicsKernel() = 0;
	virtual void invalidate(InvalidationHint hint) = 0;
	virtual bool isLightingPhotometric() const = 0;
	virtual bool isSectioningEnabled() const = 0;
	virtual bool lightsInBlocksEnabled() const = 0;
	virtual bool linetypesEnabled() const = 0;
	virtual void onAdded(AcGiDrawable* pAdded, AcGiDrawable* pParent) = 0;
	virtual void onAdded(AcGiDrawable* pAdded, IcArx::Integers::IntDbId parentID) = 0;
	virtual void onErased(AcGiDrawable* pErased, AcGiDrawable* pParent) = 0;
	virtual void onErased(AcGiDrawable* pErased, IcArx::Integers::IntDbId parentID) = 0;
	virtual void onModified(AcGiDrawable* pModified, AcGiDrawable* pParent) = 0;
	virtual void onModified(AcGiDrawable* pModified, IcArx::Integers::IntDbId parentID) = 0;
	virtual void onModified(AcGiDrawable* pModified, AcGiDrawable* pParent,
							InvalidationHint hint) = 0;
	virtual void onModified(AcGiDrawable* pModified, IcArx::Integers::IntDbId parentID,
							InvalidationHint hint) = 0;
	virtual void onPaletteModified() = 0;
	virtual RenderType renderType() = 0;
	virtual bool selectable() const = 0;
	virtual void setBackground(const AcDbObjectId backgroundId) = 0;
	virtual void setDrawOrder(AcGiDrawable* pDrawable, AcGiDrawable* pRelativeDrawable,
							  AcGiDrawable* pParent, OrderActionType action) = 0;
	virtual void setEnableSectioning(bool enable) = 0;
	virtual void setExtents(const AcGePoint3d&, const AcGePoint3d&) = 0;
	virtual void setLightingPhotometric(bool bPhotometric) = 0;
	virtual void setLightsInBlocksEnabled(bool bEnabled) = 0;
	virtual bool setSectioning(const AcGePoint3dArray& pts, const AcGeVector3d& upVector) = 0;
	virtual bool setSectioning(const AcGePoint3dArray& pts, const AcGeVector3d& upVector,
							   double top, double bottom) = 0;
	virtual void setSectioningVisualStyle(const AcDbObjectId visualStyleId) = 0;
	virtual void setSelectable(bool bEnable) = 0;
	virtual void setShadowPlaneLocation(double planeLocationZ) = 0;
	virtual void setTransform(const AcGeMatrix3d&) = 0;
	virtual void setUnitScale(double metersPerUnit) = 0;
	virtual void setViewClippingOverride(bool bOverride) = 0;
	virtual void setVisualStyle(const AcDbObjectId visualStyleId) = 0;
	virtual void setVisualStyle(const AcGiVisualStyle& visualStyle) = 0;
	virtual double shadowPlaneLocation() const = 0;
	virtual AcGeMatrix3d transform() const = 0;
	virtual double unitScale() const = 0;
	virtual AcDbObjectId visualStyle() const = 0;
	virtual bool visualStyle(AcGiVisualStyle& visualStyle) const = 0;
};

#include "IcArxPackPop.h"

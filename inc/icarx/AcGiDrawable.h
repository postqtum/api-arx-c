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
***     Description: Declaration of AcGiDrawable class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../dbid.h"

class AcDbExtents;
class AcGiDrawStream;
class AcGiDrawableTraits;
class AcGiWorldDraw;
class AcGiViewportDraw;
class AcGiDrawableAccessory;

#include "IcArxPackPush.h"
#pragma warning(disable : 4481)
#pragma warning(disable : 4100)

class ADESK_NO_VTABLE AcGiDrawable : public AcRxObject
{
public:
	enum DrawableType
	{
		kGeometry = 0,
		kDistantLight,
		kPointLight,
		kSpotLight,
		kAmbientLight,
		kSolidBackground,
		kGradientBackground,
		kImageBackground,
		kGroundPlaneBackground,
		kViewport,
		kWebLight,
		kSkyBackground,
		kImageBasedLightingBackground
	};

	enum SetAttributesFlags
	{
		kDrawableNone = 0,
		kDrawableIsAnEntity = 1,
		kDrawableUsesNesting = 2,
		kDrawableIsCompoundObject = 4,
		kDrawableViewIndependentViewportDraw = 8,
		kDrawableIsInvisible = 16,
		kDrawableHasAttributes = 32,
		kDrawableRegenTypeDependentGeometry = 64,
		kDrawableIsDimension = (kDrawableIsAnEntity + kDrawableIsCompoundObject + 128),
		kDrawableRegenDraw = 256,
		kDrawableStandardDisplaySingleLOD = 512,
		kDrawableShadedDisplaySingleLOD = 1024,
		kDrawableViewDependentViewportDraw = 2048,
		kDrawableBlockDependentViewportDraw = 4096,
		kDrawableIsExternalReference = 8192,
		kDrawableNotPlottable = 16384,
		kDrawableNotAllowLCS = 32768,
		kDrawableMergeControlOff = 65536,
		kThreadedWorldDrawViewportDraw = 131072
	};

protected:
	virtual uint32_t subSetAttributes(AcGiDrawableTraits* traits) = 0;
	virtual void subViewportDraw(AcGiViewportDraw* vd) = 0;
	virtual uint32_t subViewportDrawLogicalFlags(AcGiViewportDraw* /*vd*/) { return 0; }
	virtual bool subWorldDraw(AcGiWorldDraw* wd) = 0;

public:
	ACRX_DECLARE_MEMBERS(AcGiDrawable);

	ACDBCORE2D_PORT AcGiDrawable() = default;
	ACDBCORE2D_PORT ~AcGiDrawable() = default;

	virtual bool RolloverHit(IcArx::Integers::ULongPtr /*nSubentId*/,
							 IcArx::Integers::ULongPtr /*nMouseFlags*/, bool /*bReset*/)
	{
		return false;
	}
	virtual bool bounds(AcDbExtents& /*bounds*/) const { return false; }
	ACDBCORE2D_PORT virtual AcGiDrawStream* drawStream() const;
	virtual DrawableType drawableType() const { return kGeometry; }
	virtual AcDbObjectId id() const = 0;
	virtual bool isPersistent() const = 0;
	ACDBCORE2D_PORT virtual uint32_t setAttributes(AcGiDrawableTraits* traits) final;
	ACDBCORE2D_PORT virtual void setDrawStream(AcGiDrawStream* pStream);
	ACDBCORE2D_PORT virtual void viewportDraw(AcGiViewportDraw* vd) final;
	ACDBCORE2D_PORT virtual uint32_t viewportDrawLogicalFlags(AcGiViewportDraw* vd) final;
	ACDBCORE2D_PORT virtual bool worldDraw(AcGiWorldDraw* wd) final;
};

#include "IcArxPackPop.h"

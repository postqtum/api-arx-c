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
***     Description: Declaration of AcGsDevice class
***
*****************************************************************************/
#pragma once

#include "AcGsModel.h"
#include "AcGsEnum.h"

class AcGsGraphicsKernel;
class AcGsDCRect;
class AcGsView;
struct AcGsColor;
class AcGsDCPoint;
class AcGsRenderInterrupter;
class AcGsRenderProgressMonitor;

namespace Atil
{
class Image;
};

#include "IcArxPackPush.h"

class AcGsDevice
{
public:
	enum RendererType
	{
		kDefault,
		kSoftware,
		kSoftwareNewViewsOnly,
		kFullRender,
		kSelectionRender,
		kFbxExportRender
	};

	enum EnableIRResult
	{
		kSuccess,
		kOutOfMemory
	};

public:
	virtual ~AcGsDevice() = default;

	virtual bool add(AcGsView* view) = 0;
	virtual EnableIRResult beginInteractiveRender(AcGsRenderProgressMonitor* pProgressMonitor) = 0;
	virtual Atil::Image* createSnapshot(const AcGsDCPoint& offset, const AcGsDCRect& imageDim,
										GS::ImageDataFormat format,
										GS::ImageOrientation orientation) = 0;
	virtual void endInteractiveRender() = 0;
	virtual bool erase(AcGsView* view) = 0;
	virtual void eraseAll() = 0;
	virtual AcGsColor getBackgroundColor() = 0;
	virtual RendererType getDeviceRenderer() = 0;
	virtual int getMaxDeviceHeight() = 0;
	virtual int getMaxDeviceWidth() = 0;
	virtual AcGsRenderInterrupter* getRenderInterrupter() const = 0;
	virtual void getSnapShot(Atil::Image* pOutput, AcGsDCPoint const& offset) = 0;
	virtual AcGsGraphicsKernel& graphicsKernel() = 0;
	virtual void invalidate() = 0;
	virtual void invalidate(const AcGsDCRect& rect) = 0;
	virtual void invalidate(AcGsModel::RenderType pane) = 0;
	virtual void invalidate(const AcGsDCRect& rect, AcGsModel::RenderType pane) = 0;
	virtual bool isRendering() const = 0;
	virtual bool isValid() const = 0;
	virtual void onDisplayChange(int nBitsPerPixel, int nXRes, int nYRes) = 0;
	virtual void onRealizeBackgroundPalette() = 0;
	virtual void onRealizeForegroundPalette() = 0;
	virtual void onSize(int width, int height) = 0;
	virtual void pauseInteractiveRender() = 0;
	virtual void postRenderProgressCheckingReqeust() = 0;
	virtual void resumeInteractiveRender() = 0;
	virtual bool setBackgroundColor(AcGsColor color) = 0;
	virtual void setDesiredFrameRate(float frameRate) = 0;
	virtual void setDeviceRenderer(RendererType type) = 0;
	virtual void setDisplayUpdateSuppressed(bool bSuppressed) = 0;
	virtual void setFontKerningDisplay(bool bDisplay) = 0;
	virtual void setLogicalPalette(const AcGsColor* palette, int nCount) = 0;
	virtual void setPhysicalPalette(const AcGsColor* palette, int nCount) = 0;
	virtual void setRenderInterrupter(AcGsRenderInterrupter* pInterrupter) = 0;
	virtual void update(AcGsDCRect* pUpdatedRect = nullptr) = 0;
	virtual void update(AcGsDCRect* pUpdatedRect, GS::SyncBehavior sync) = 0;
};

#include "IcArxPackPop.h"

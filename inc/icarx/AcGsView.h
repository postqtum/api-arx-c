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
***     Description: Declaration of AcGsView class
***
*****************************************************************************/
#pragma once

#include "AcGsDCRect.h"
#include "AcGsColor.h"
#include "AcGsEnum.h"
#include "../acgi.h"

class AcGsGraphicsKernel;
class AcGePoint2d;
class AcGePoint3d;
class AcGeVector3d;
class AcGeMatrix3d;
class AcGsRenderProgressMonitor;
class AcGsDevice;
class AcGiVisualStyle;
class AcGsModel;
struct AcGsClientViewInfo;

#include "IcArxPackPush.h"

// If you inherit from both classes AcGsView and AcRxObject, use code like this
//class UserClass : public AcGsView
//#ifndef INTELLICAD_ADESK_H_HEADER
// , public AcRxObject
//#endif

class AcGsView : public AcRxObject
{
public:
	enum DefaultLightingType
	{
		kOneLight,
		kTwoLights,
		kBackLight
	};

	enum EnableIRResult
	{
		kSuccess,
		kOutOfMemory
	};

	enum ModelCloneOption
	{
		kCloneNoModels,
		kCloneMainPersistentModel,
		kCloneAllModels
	};

	enum Projection
	{
		kParallel,
		kPerspective
	};

	enum SelectionMode
	{
		kWindow,
		kCrossing,
		kFence,
		kWPoly,
		kCPoly,
	};

public:
	ACRX_DECLARE_MEMBERS(AcGsView);

	virtual ~AcGsView() = default;

	virtual bool add(AcGiDrawable* drawable, AcGsModel* model) = 0;
	virtual double backClip() const = 0;
	virtual AcDbObjectId background() const = 0;
	virtual void beginFastInteractivity() = 0;
	virtual EnableIRResult beginInteractiveRender(AcGsRenderProgressMonitor* pProgressMonitor) = 0;
	virtual void beginInteractivity(double fFrameRateInHz) = 0;
	virtual void clearFrozenLayers() = 0;
	virtual AcGsView* clone(bool bCloneViewParameters = true, bool bCloneGeometry = false) = 0;
	virtual AcGsView* clone(bool bCloneViewParameters, ModelCloneOption cloneOption) = 0;
	virtual Atil::Image* createSnapshot(const AcGsDCPoint& offset, const AcGsDCRect& imageDim,
										GS::ImageDataFormat format,
										GS::ImageOrientation orientation,
										bool bOnlyCaptureRenderedImage = false) = 0;
	virtual void dolly(const AcGeVector3d& vector) = 0;
	virtual void dolly(double x, double y, double z) = 0;
	virtual void enableDefaultLighting(bool bEnable, DefaultLightingType type = kTwoLights) = 0;
	virtual void enableStereo(bool bEnable) = 0;
	virtual bool endFastInteractivity() = 0;
	virtual void endInteractiveRender() = 0;
	virtual void endInteractivity() = 0;
	virtual bool erase(AcGiDrawable* drawable) = 0;
	virtual void eraseAll() = 0;
	virtual bool exceededBounds() = 0;
	virtual bool extentsInView(const AcGePoint3d& minPoint, const AcGePoint3d& maxPoint) = 0;
	virtual double fieldHeight() const = 0;
	virtual double fieldWidth() const = 0;
	virtual void flush() = 0;
	virtual void freezeLayer(IcArx::Integers::IntDbId layerID) = 0;
	virtual double frontClip() const = 0;
	virtual const AcGsClientViewInfo& getClientViewInfo() const = 0;
	virtual AcGsDevice* getDevice() const = 0;
	virtual AcGsModel* getModel(AcGiDrawable*) const = 0;
	virtual void getModelList(AcArray<AcGsModel*>&) const = 0;
	virtual void getNumPixelsInUnitSquare(const AcGePoint3d& givenWorldpt, AcGePoint2d& pixelArea,
										  bool includePerspective = true) const = 0;
	virtual void getSnapShot(Atil::Image* pOutput, AcGsDCPoint const& offset) = 0;
	virtual void getStereoParameters(double& magnitude, double& parallax) const = 0;
	virtual void getViewport(AcGePoint2d& lowerLeft, AcGePoint2d& upperRight) const = 0;
	virtual void getViewport(AcGsDCRect& screen_rect) const = 0;
	virtual void getViewportBorderProperties(AcGsColor& color, int& weight) const = 0;
	virtual AcGsGraphicsKernel& graphicsKernel() = 0;
	virtual void hide() = 0;
	virtual void invalidate() = 0;
	virtual void invalidate(const AcGsDCRect& rect) = 0;
	virtual void invalidateCachedViewportGeometry() = 0;
	virtual void invalidateCachedViewportGeometry(AcGiDrawable* pDrawable) = 0;
	virtual bool isBackClipped() const = 0;
	virtual bool isFastInteractivity() = 0;
	virtual bool isFrontClipped() const = 0;
	virtual bool isInteractive() const = 0;
	virtual bool isPerspective() const = 0;
	virtual bool isPointInViewport(const int32_t x, const int32_t y) = 0;
	virtual bool isRendering() const = 0;
	virtual bool isStereoEnabled() const = 0;
	virtual bool isValid() const = 0;
	virtual bool isViewportBorderVisible() const = 0;
	virtual bool isVisible() = 0;
	virtual int maximumUpgrade() = 0;
	virtual int minimumDegrade() = 0;
	virtual AcGeMatrix3d objectToDeviceMatrix() const = 0;
	virtual void orbit(double x, double y) = 0;
	virtual void pan(double x, double y) = 0;
	virtual bool pointInView(const AcGePoint3d& pnt) = 0;
	virtual AcGePoint3d position() const = 0;
	virtual AcGeMatrix3d projectionMatrix() const = 0;
	virtual void removeViewportClipRegion() = 0;
	virtual bool renderToImage(Atil::Image* pOutput, AcGiDrawable* pSettings,
							   AcGsRenderProgressMonitor* pProgressMonitor,
							   const AcGsDCRect& rectScreen, bool bReuseScene = false) = 0;
	virtual void roll(double angle) = 0;
	virtual AcGeMatrix3d screenMatrix() const = 0;
	virtual void setBackClip(double distance) = 0;
	virtual void setBackground(const AcDbObjectId backgroundId) = 0;
	virtual void setEnableBackClip(bool enable) = 0;
	virtual void setEnableFrontClip(bool enable) = 0;
	virtual void setFrontClip(double distance) = 0;
	virtual void setMaximumUpgrade(int step) = 0;
	virtual void setMinimumDegrade(int step) = 0;
	virtual void setStereoParameters(double magnitude, double parallax) = 0;
	virtual void setView(const AcGePoint3d& position, const AcGePoint3d& target,
						 const AcGeVector3d& upVector, double fieldWidth, double fieldHeight,
						 Projection projection = kParallel) = 0;
	virtual void setViewport(const AcGePoint2d& lowerLeft, const AcGePoint2d& upperRight) = 0;
	virtual void setViewport(const AcGsDCRect& screen_rect) = 0;
	virtual void setViewportBorderProperties(AcGsColor const& color, int weight) = 0;
	virtual void setViewportBorderVisibility(bool bVisible) = 0;
	virtual void setViewportClipRegion(int contours, int const* counts,
									   AcGsDCPoint const* points) = 0;
	virtual void setVisualStyle(const AcDbObjectId visualStyleId) = 0;
	virtual void setVisualStyle(const AcGiVisualStyle& visualStyle) = 0;
	virtual void show() = 0;
	virtual AcGePoint3d target() const = 0;
	virtual void thawLayer(IcArx::Integers::IntDbId layerID) = 0;
	virtual AcGeVector3d upVector() const = 0;
	virtual void update() = 0;
	virtual void update(GS::SyncBehavior sync) = 0;
	virtual AcGeMatrix3d viewingMatrix() const = 0;
	virtual AcDbObjectId visualStyle() const = 0;
	virtual bool visualStyle(AcGiVisualStyle& visualStyle) const = 0;
	virtual AcGeMatrix3d worldToDeviceMatrix() const = 0;
	virtual void zoom(double factor) = 0;
	virtual void zoomExtents(const AcGePoint3d& minPoint, const AcGePoint3d& maxPoint) = 0;
	virtual void zoomWindow(const AcGePoint2d& lowerLeft, const AcGePoint2d& upperRight) = 0;
};

#include "IcArxPackPop.h"

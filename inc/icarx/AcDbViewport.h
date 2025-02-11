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
***     Description: Declaration of AcDbViewport class
***
*****************************************************************************/
#pragma once

#include "AcDbEntity.h"
#include "AcGiViewportTraits.h"
#include "../acdbxref.h"

#include "IcArxPackPush.h"

typedef struct tagBITMAPINFO BITMAPINFO;

class AcDbViewport : public AcDbEntity
{
public:
	enum ShadePlotType
	{
		kAsDisplayed = 0,
		kWireframe = 1,
		kHidden = 2,
		kRendered = 3,
		kVisualStyle = 4,
		kRenderPreset = 5
	};

	enum StandardScaleType
	{
		kScaleToFit,
		kCustomScale,
		k1_1,
		k1_2,
		k1_4,
		k1_5,
		k1_8,
		k1_10,
		k1_16,
		k1_20,
		k1_30,
		k1_40,
		k1_50,
		k1_100,
		k2_1,
		k4_1,
		k8_1,
		k10_1,
		k100_1,
		k1_128in_1ft,
		k1_64in_1ft,
		k1_32in_1ft,
		k1_16in_1ft,
		k3_32in_1ft,
		k1_8in_1ft,
		k3_16in_1ft,
		k1_4in_1ft,
		k3_8in_1ft,
		k1_2in_1ft,
		k3_4in_1ft,
		k1in_1ft,
		k1and1_2in_1ft,
		k3in_1ft,
		k6in_1ft,
		k1ft_1ft
	};

protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	AcDbViewport();
	~AcDbViewport();

	ACDB_DECLARE_MEMBERS(AcDbViewport);

	AcCmColor ambientLightColor() const;
	AcDbAnnotationScale* annotationScale() const;
	double backClipDistance() const;
	AcDbObjectId background() const;
	double brightness() const;
	AcGePoint3d centerPoint() const;
	uint16_t circleSides() const;
	double contrast() const;
	void copied(const AcDbObject* pDbObj, const AcDbObject* pNewObj) override;
	double customScale() const;
	AcGiViewportTraits::DefaultLightingType defaultLightingType() const;
	Acad::ErrorStatus effectivePlotStyleSheet(const ACHAR*&);
	double elevation() const;
	void erased(const AcDbObject*, bool) override;
	Acad::ErrorStatus freezeLayersInViewport(const AcDbObjectIdArray&);
	double frontClipDistance() const;
	Acad::ErrorStatus getFrozenLayerList(AcDbObjectIdArray& ids) const;
	Acad::ErrorStatus getLabelBlock(AcDbObjectId& objId) const;
	Acad::ErrorStatus getModelView(AcDbXrefObjectId& xrefObjId) const;
	Acad::ErrorStatus getPreviewImage(Atil::Image*& pPreviewImage) const;
	Acad::ErrorStatus getSheetView(AcDbObjectId& objId) const;
	Acad::ErrorStatus getThumbnail(BITMAPINFO*& thumbnail) const;
	Acad::ErrorStatus getUcs(AcGePoint3d& origin, AcGeVector3d& xAxis, AcGeVector3d& yAxis) const;
	AcGeVector2d gridIncrement() const;
	uint16_t gridMajor() const;
	double height() const;
	bool hiddenLinesRemoved() const;
	bool isBackClipOn() const;
	bool isDefaultLightingOn() const;
	bool isFastZoomOn() const { return true; }
	bool isFrontClipAtEyeOn() const;
	bool isFrontClipOn() const;
	bool isGridAdaptive() const;
	bool isGridBoundToLimits() const;
	bool isGridFollow() const;
	bool isGridOn() const;
	bool isGridSubdivisionRestricted() const;
	bool isLayerFrozenInViewport(const AcDbObjectId& layerId) const;
	bool isLocked() const;
	bool isNonRectClipOn() const;
	bool isOn() const;
	bool isPerspectiveOn() const;
	bool isSnapIsometric() const;
	bool isSnapOn() const;
	bool isTransparent() const;
	bool isUcsFollowModeOn() const;
	bool isUcsIconAtOrigin() const;
	bool isUcsIconVisible() const;
	bool isUcsOrthographic(AcDb::OrthographicView& view) const;
	bool isUcsSavedWithViewport() const;
	bool isViewOrthographic(AcDb::OrthographicView& view) const;
	double lensLength() const;
	void modified(const AcDbObject*) override;
	AcDbObjectId nonRectClipEntityId() const;
	int16_t number() const;
	bool plotAsRaster() const;
	ACDBCORE2D_PORT Acad::ErrorStatus plotStyleSheet(AcString& sName) const;
	Acad::ErrorStatus plotStyleSheet(ACHAR*&) const;
	Acad::ErrorStatus plotStyleSheet(const ACHAR*&) const;
	bool plotWireframe() const;
	AcDbObjectId previousBackground(
			AcGiDrawable::DrawableType type = AcGiDrawable::kGeometry) const;
	bool previousBackgroundForcedSwitch(void) const;
	Acad::ErrorStatus removeHiddenLines();
	ACDBCORE2D_PORT Acad::ErrorStatus removeHiddenLines(bool);
	Acad::ErrorStatus removeLabelBlock(void);
	Acad::ErrorStatus removeModelView(void);
	Acad::ErrorStatus removeSheetView(void);
	Acad::ErrorStatus setAmbientLightColor(const AcCmColor& clr);
	Acad::ErrorStatus setAnnotationScale(const AcDbAnnotationScale* pScaleObj);
	Acad::ErrorStatus setBackClipDistance(double newVal);
	Acad::ErrorStatus setBackClipOff();
	Acad::ErrorStatus setBackClipOn();
	ACDBCORE2D_PORT Acad::ErrorStatus setBackClipOn(bool bOn);
	Acad::ErrorStatus setBackground(AcDbObjectId backgroundId);
	Acad::ErrorStatus setBrightness(double);
	Acad::ErrorStatus setCenterPoint(const AcGePoint3d&);
	Acad::ErrorStatus setCircleSides(uint16_t);
	Acad::ErrorStatus setContrast(double);
	Acad::ErrorStatus setCustomScale(double);
	Acad::ErrorStatus setDefaultLightingOn(bool on);
	Acad::ErrorStatus setDefaultLightingType(AcGiViewportTraits::DefaultLightingType typ);
	Acad::ErrorStatus setElevation(double elev);
	Acad::ErrorStatus setFastZoomOff() { return Acad::eOk; }
	Acad::ErrorStatus setFastZoomOn() { return Acad::eOk; }
	ACDBCORE2D_PORT Acad::ErrorStatus setFastZoomOn(bool);
	Acad::ErrorStatus setFrontClipAtEyeOff();
	Acad::ErrorStatus setFrontClipAtEyeOn();
	ACDBCORE2D_PORT Acad::ErrorStatus setFrontClipAtEyeOn(bool bOn);
	Acad::ErrorStatus setFrontClipDistance(double newVal);
	Acad::ErrorStatus setFrontClipOff();
	Acad::ErrorStatus setFrontClipOn();
	ACDBCORE2D_PORT Acad::ErrorStatus setFrontClipOn(bool bOn);
	Acad::ErrorStatus setGridAdaptive(bool bNewVal);
	Acad::ErrorStatus setGridBoundToLimits(bool bNewVal);
	Acad::ErrorStatus setGridFollow(bool bNewVal);
	Acad::ErrorStatus setGridIncrement(const AcGeVector2d&);
	Acad::ErrorStatus setGridMajor(uint16_t);
	Acad::ErrorStatus setGridOff();
	Acad::ErrorStatus setGridOn();
	ACDBCORE2D_PORT Acad::ErrorStatus setGridOn(bool);
	Acad::ErrorStatus setGridSubdivisionRestricted(bool bNewVal);
	Acad::ErrorStatus setHeight(double);
	ACDBCORE2D_PORT Acad::ErrorStatus setIsOn(bool bOn);
	Acad::ErrorStatus setLabelBlock(AcDbObjectId objId);
	Acad::ErrorStatus setLensLength(double);
	Acad::ErrorStatus setLocked();
	ACDBCORE2D_PORT Acad::ErrorStatus setLocked(bool);
	Acad::ErrorStatus setModelView(const AcDbXrefObjectId& xrefObjId);
	Acad::ErrorStatus setNonRectClipEntityId(AcDbObjectId);
	Acad::ErrorStatus setNonRectClipOff();
	Acad::ErrorStatus setNonRectClipOn();
	ACDBCORE2D_PORT Acad::ErrorStatus setNonRectClipOn(bool bOn);
	Acad::ErrorStatus setOff();
	Acad::ErrorStatus setOn();
	Acad::ErrorStatus setOpaque();
	Acad::ErrorStatus setPerspectiveOff();
	Acad::ErrorStatus setPerspectiveOn();
	ACDBCORE2D_PORT Acad::ErrorStatus setPerspectiveOn(bool bOn);
	Acad::ErrorStatus setPlotStyleSheet(const ACHAR*);
	Acad::ErrorStatus setPreviewImage(const Atil::Image* pPreviewImage);
	Acad::ErrorStatus setPreviousBackground(
			AcDbObjectId backgroundId, AcGiDrawable::DrawableType type = AcGiDrawable::kGeometry);
	Acad::ErrorStatus setPreviousBackground(AcDbObjectId backgroundId,
											AcGiDrawable::DrawableType type, bool bForcedSwitch);
	Acad::ErrorStatus setShadePlot(const ShadePlotType);
	Acad::ErrorStatus setShadePlot(const ShadePlotType type, const AcDbObjectId shadePlotId);
	Acad::ErrorStatus setSheetView(AcDbObjectId objId);
	Acad::ErrorStatus setSnapAngle(double);
	Acad::ErrorStatus setSnapBasePoint(const AcGePoint2d&);
	Acad::ErrorStatus setSnapIncrement(const AcGeVector2d&);
	Acad::ErrorStatus setSnapIsoPair(uint16_t);
	Acad::ErrorStatus setSnapIsometric();
	ACDBCORE2D_PORT Acad::ErrorStatus setSnapIsometric(bool);
	Acad::ErrorStatus setSnapOff();
	Acad::ErrorStatus setSnapOn();
	ACDBCORE2D_PORT Acad::ErrorStatus setSnapOn(bool);
	Acad::ErrorStatus setSnapStandard();
	Acad::ErrorStatus setStandardScale(const StandardScaleType);
	Acad::ErrorStatus setSun(AcDbObjectId& retId, AcDbObject* pSun);
	Acad::ErrorStatus setSun(AcDbObjectId& retId, AcDbObject* pSun, bool eraseOldSun);
	Acad::ErrorStatus setThumbnail(const BITMAPINFO* thumbnail);
	Acad::ErrorStatus setToneOperatorParameters(const AcGiToneOperatorParameters& params);
	Acad::ErrorStatus setTransparent();
	ACDBCORE2D_PORT Acad::ErrorStatus setTransparent(bool);
	Acad::ErrorStatus setTwistAngle(double);
	Acad::ErrorStatus setUcs(const AcGePoint3d& origin, const AcGeVector3d& xAxis,
							 const AcGeVector3d& yAxis);
	Acad::ErrorStatus setUcs(AcDb::OrthographicView view);
	Acad::ErrorStatus setUcs(const AcDbObjectId& ucsId);
	Acad::ErrorStatus setUcsFollowModeOff();
	Acad::ErrorStatus setUcsFollowModeOn();
	ACDBCORE2D_PORT Acad::ErrorStatus setUcsFollowModeOn(bool bOn);
	Acad::ErrorStatus setUcsIconAtCorner();
	Acad::ErrorStatus setUcsIconAtOrigin();
	ACDBCORE2D_PORT Acad::ErrorStatus setUcsIconAtOrigin(bool);
	Acad::ErrorStatus setUcsIconInvisible();
	Acad::ErrorStatus setUcsIconVisible();
	ACDBCORE2D_PORT Acad::ErrorStatus setUcsIconVisible(bool);
	void setUcsPerViewport(bool ucsvp);
	Acad::ErrorStatus setUcsToWorld();
	Acad::ErrorStatus setUnlocked();
	Acad::ErrorStatus setViewCenter(const AcGePoint2d& pt);
	Acad::ErrorStatus setViewDirection(const AcGeVector3d&);
	Acad::ErrorStatus setViewDirection(AcDb::OrthographicView view);
	Acad::ErrorStatus setViewHeight(double ht);
	Acad::ErrorStatus setViewTarget(const AcGePoint3d&);
	Acad::ErrorStatus setVisualStyle(const AcDbObjectId oidVisualStyle);
	Acad::ErrorStatus setWidth(double);
	ShadePlotType shadePlot() const;
	AcDbObjectId shadePlotId() const;
	Acad::ErrorStatus showHiddenLines();
	double snapAngle() const;
	AcGePoint2d snapBasePoint() const;
	AcGeVector2d snapIncrement() const;
	uint16_t snapIsoPair() const;
	StandardScaleType standardScale() const;
	void subObjModified(const AcDbObject* pDbObj, const AcDbObject* pSubObj) override;
	AcDbObjectId sunId() const;
	Acad::ErrorStatus syncModelView(void);
	Acad::ErrorStatus thawAllLayersInViewport();
	Acad::ErrorStatus thawLayersInViewport(const AcDbObjectIdArray&);
	Acad::ErrorStatus toneOperatorParameters(AcGiToneOperatorParameters& params) const;
	double twistAngle() const;
	AcDbObjectId ucsName() const;
	Acad::ErrorStatus updateDisplay() const;
	AcGePoint2d viewCenter() const;
	AcGeVector3d viewDirection() const;
	double viewHeight() const;
	AcGePoint3d viewTarget() const;
	AcDbObjectId visualStyle() const;
	double width() const;
};

#include "IcArxPackPop.h"

inline Acad::ErrorStatus AcDbViewport::plotStyleSheet(ACHAR*& pName) const
{
	return ::acutGetAcStringConvertToAChar(this, &AcDbViewport::plotStyleSheet, pName);
}

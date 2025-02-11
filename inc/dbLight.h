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
***     Description: Declaration of AcDbLight class
***
*****************************************************************************/
#pragma once

#include "dbmain.h"
#include "dbents.h"

#pragma warning(disable : 4275 4251)

#ifdef SCENEOE
#	define LIGHTDLLIMPEXP __declspec(dllexport)
#else
#	define LIGHTDLLIMPEXP
#endif

#include "AcGiLightTraits.h"

class AcDbImpLight;

#include "icarx/IcArxPackPush.h"

class LIGHTDLLIMPEXP AcDbLight : public AcDbEntity
{
	friend class AcDbImpLight;

public:
	enum GlyphDisplayType
	{
		kGlyphDisplayAuto = 0,
		kGlyphDisplayOn,
		kGlyphDisplayOff
	};

	enum LampColorPreset
	{
		kD65White = 0,
		kFluorescent,
		kCoolWhite,
		kWhiteFluorescent,
		kDaylightFluorescent,
		kIncandescent,
		kXenon,
		kHalogen,
		kQuartz,
		kMetalHalide,
		kMercury,
		kPhosphorMercury,
		kHighPressureSodium,
		kLowPressureSodium,
		kCustom
	};

	enum LampColorType
	{
		kKelvin = 0,
		kPreset
	};

	enum PhysicalIntensityMethod
	{
		kPeakIntensity = 0,
		kFlux,
		kIlluminance
	};

private:
	static uint32_t kCurrentVersionNumber;

private:
	AcDbImpLight* mpAcDbImpLight;
	bool mSelected;

private:
	Acad::ErrorStatus baseDeepClone(AcDbObject* pOwner, AcDbObject*& pClonedObject,
									AcDbIdMapping& idMap, bool isPrimary) const;
	Acad::ErrorStatus baseHighlight(const AcDbFullSubentPath& subId, const bool highlightAll) const;
	uint32_t baseSetAttributes(AcGiDrawableTraits* pTraits);
	Acad::ErrorStatus baseUnhighlight(const AcDbFullSubentPath& subId,
									  const bool highlightAll) const;
	Acad::ErrorStatus baseWblockClone(AcRxObject* pOwnerObject, AcDbObject*& pClonedObject,
									  AcDbIdMapping& idMap, bool isPrimary) const;

protected:
	Acad::ErrorStatus subDeepClone(AcDbObject* pOwner, AcDbObject*& pClonedObject,
								   AcDbIdMapping& idMap, bool isPrimary = true) const override;
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
	Acad::ErrorStatus subGetGeomExtents(AcDbExtents& extents) const override;
	Acad::ErrorStatus subGetGripPoints(AcDbGripDataPtrArray& grips, const double curViewUnitSize,
									   const int gripSize, const AcGeVector3d& curViewDir,
									   const int bitflags) const override;
	Acad::ErrorStatus subGetOsnapPoints(AcDb::OsnapMode osnapMode,
										IcArx::Integers::GsMarker gsSelectionMark,
										const AcGePoint3d& pickPoint, const AcGePoint3d& lastPoint,
										const AcGeMatrix3d& viewXform, AcGePoint3dArray& snapPoints,
										AcDbIntArray& geomIds) const override;

	Acad::ErrorStatus subGetOsnapPoints(AcDb::OsnapMode osnapMode,
										IcArx::Integers::GsMarker gsSelectionMark,
										const AcGePoint3d& pickPoint, const AcGePoint3d& lastPoint,
										const AcGeMatrix3d& viewXform, AcGePoint3dArray& snapPoints,
										AcDbIntArray& geomIds,
										const AcGeMatrix3d& insertionMat) const override;
	Acad::ErrorStatus subGetTransformedCopy(const AcGeMatrix3d& xform,
											AcDbEntity*& pEnt) const override;
	Acad::ErrorStatus subHighlight(const AcDbFullSubentPath& subId,
								   const bool highlightAll) const override;
	void subList() const override;
	Acad::ErrorStatus subMoveGripPointsAt(const AcDbVoidPtrArray& gripAppData,
										  const AcGeVector3d& offset, const int bitflags) override;
	uint32_t subSetAttributes(AcGiDrawableTraits* pTraits) override;
	Acad::ErrorStatus subTransformBy(const AcGeMatrix3d& xform) override;
	Acad::ErrorStatus subUnhighlight(const AcDbFullSubentPath& subId,
									 const bool highlightAll) const override;
	void subViewportDraw(AcGiViewportDraw* mode) override;
	Acad::ErrorStatus subWblockClone(AcRxObject* pOwnerObject, AcDbObject*& pClonedObject,
									 AcDbIdMapping& idMap,
									 bool isPrimary /* = true */) const override;
	bool subWorldDraw(AcGiWorldDraw* mode) override;

public:
	ACRX_DECLARE_MEMBERS(AcDbLight);

	AcDbLight();
	~AcDbLight();

	bool castShadows() const override;
	Acad::ErrorStatus copyFrom(const AcRxObject* other) override;
	Acad::ErrorStatus decomposeForSave(AcDb::AcDbDwgVersion ver, AcDbObject*& replaceObj,
									   AcDbObjectId& replaceId, bool& exchangeXData) override;
	AcGiDrawable::DrawableType drawableType() const override;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	virtual double falloffAngle() const;
	GlyphDisplayType glyphDisplay() const;
	bool hasTarget() const;
	virtual double hotspotAngle() const;
	double illuminanceDistance() const;
	virtual double intensity() const;
	virtual bool isOn() const;
	virtual bool isPlottable() const;
	AcDbLight::LampColorPreset lampColorPreset() const;
	Acad::ErrorStatus lampColorRGB(AcGiColorRGB& rgbColor) const;
	double lampColorTemp() const;
	AcDbLight::LampColorType lampColorType() const;
	virtual const AcGiLightAttenuation& lightAttenuation() const;
	virtual const AcCmColor& lightColor() const;
	virtual const AcGeVector3d& lightDirection() const;
	virtual AcGiDrawable::DrawableType lightType() const;
	virtual const AcString& name() const;
	double physicalIntensity() const;
	AcDbLight::PhysicalIntensityMethod physicalIntensityMethod() const;
	virtual const AcGePoint3d& position() const;
	bool receiveShadows() const override;
	Acad::ErrorStatus resultingColor(AcCmColor& rgbColor) const;
	void setCastShadows(bool newVal) override;
	Acad::ErrorStatus setGlyphDisplay(GlyphDisplayType type);
	Acad::ErrorStatus setHasTarget(bool hasTarget);
	virtual Acad::ErrorStatus setHotspotAndFalloff(double hotspot, double falloff);
	Acad::ErrorStatus setIlluminanceDistance(double distance);
	virtual Acad::ErrorStatus setIntensity(double intensity);
	virtual Acad::ErrorStatus setIsPlottable(bool plot);
	Acad::ErrorStatus setLampColorPreset(AcDbLight::LampColorPreset colorPreset);
	Acad::ErrorStatus setLampColorRGB(AcGiColorRGB rgbColor);
	Acad::ErrorStatus setLampColorTemp(double colorTemp);
	Acad::ErrorStatus setLampColorType(AcDbLight::LampColorType colorType);
	virtual void setLightAttenuation(const AcGiLightAttenuation& params);
	virtual Acad::ErrorStatus setLightColor(const AcCmColor& color);
	virtual Acad::ErrorStatus setLightDirection(const AcGeVector3d& lightvec);
	virtual Acad::ErrorStatus setLightType(AcGiDrawable::DrawableType type);
	virtual Acad::ErrorStatus setName(const AcString& name);
	virtual Acad::ErrorStatus setOn(bool value);
	Acad::ErrorStatus setPhysicalIntensity(double physicalIntensity);
	Acad::ErrorStatus setPhysicalIntensityMethod(AcDbLight::PhysicalIntensityMethod method);
	virtual Acad::ErrorStatus setPosition(const AcGePoint3d& pos);
	void setReceiveShadows(bool newVal) override;
	Acad::ErrorStatus setShadowParameters(const AcGiShadowParameters& params);
	virtual Acad::ErrorStatus setTargetLocation(const AcGePoint3d& newVal);
	Acad::ErrorStatus setWebFile(const ACHAR* webFile);
	Acad::ErrorStatus setWebRotation(AcGeVector3d rotation);
	Acad::ErrorStatus shadowParameters(AcGiShadowParameters& params) const;
	Acad::ErrorStatus subClose() override;
	virtual const AcGePoint3d& targetLocation() const;
	Acad::ErrorStatus webFile(AcString& webFile) const;
	Acad::ErrorStatus webRotation(AcGeVector3d& rotation) const;
};

#include "icarx/IcArxPackPop.h"

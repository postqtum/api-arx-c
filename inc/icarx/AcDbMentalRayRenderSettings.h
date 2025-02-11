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
***     Description: Declaration of AcDbMentalRayRenderSettings class
***
*****************************************************************************/
#pragma once

#include "AcGiMentalRayRenderSettingsTraits.h"
#include "SceneDllImpExp.h"
#include "AcDbRenderSettings.h"

class AcDbImpMentalRayRenderSettings;

#include "IcArxPackPush.h"

class SCENEDLLIMPEXP AcDbMentalRayRenderSettings : public AcDbRenderSettings
{
	friend class AcDbImpMentalRayRenderSettings;

public:
	enum ShadowSamplingMultiplier
	{
		kSamplingMultiplierZero = 0,
		kSamplingMultiplierOneEighth,
		kSamplingMultiplierOneFourth,
		kSamplingMultiplierOneHalf,
		kSamplingMultiplierOne,
		kSamplingMultiplierTwo
	};

private:
	AcDbImpMentalRayRenderSettings* mpImpMentalRay;

private:
	uint32_t baseSetAttributes(AcGiDrawableTraits* pTraits);

protected:
	uint32_t subSetAttributes(AcGiDrawableTraits* pTraits) override;

public:
	ACRX_DECLARE_MEMBERS(AcDbMentalRayRenderSettings);

	AcDbMentalRayRenderSettings();
	~AcDbMentalRayRenderSettings();
	virtual bool operator==(const AcDbMentalRayRenderSettings& settings);

	void SamplingFilter(AcGiMrFilter& eFilter, double& fWidth, double& fHeight) const;
	Acad::ErrorStatus copyFrom(const AcRxObject* other) override;
	AcGiMrDiagnosticBSPMode diagnosticBSPMode() const;
	void diagnosticGridMode(AcGiMrDiagnosticGridMode& eDiagnosticGridMode, float& fSize) const;
	AcGiMrDiagnosticMode diagnosticMode() const;
	AcGiMrDiagnosticPhotonMode diagnosticPhotonMode() const;
	bool diagnosticSamplesMode() const;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	float energyMultiplier() const;
	bool exportMIEnabled() const;
	AcString exportMIFileName() const;
	AcGiMrExportMIMode exportMIMode() const;
	int fgRayCount() const;
	void fgSampleRadius(double& fMin, double& fMax) const;
	void fgSampleRadiusState(bool& bMin, bool& bMax, bool& bPixels) const;
	bool finalGatheringEnabled() const;
	AcGiMrFinalGatheringMode finalGatheringMode() const;
	int giPhotonsPerLight() const;
	int giSampleCount() const;
	double giSampleRadius() const;
	bool giSampleRadiusEnabled() const;
	bool globalIlluminationEnabled() const;
	double lightLuminanceScale() const;
	int memoryLimit() const;
	void photonTraceDepth(int& iReflection, int& iRefraction, int& iSum) const;
	void rayTraceDepth(int& iReflection, int& iRefraction, int& iSum) const;
	bool rayTracingEnabled() const;
	void sampling(int& iMin, int& iMax) const;
	void samplingContrastColor(float& r, float& g, float& b, float& a) const;
	void setDiagnosticBSPMode(AcGiMrDiagnosticBSPMode eDiagnosticBSPMode);
	Acad::ErrorStatus setDiagnosticGridMode(AcGiMrDiagnosticGridMode eDiagnosticGridMode,
											float fSize);
	void setDiagnosticMode(AcGiMrDiagnosticMode eDiagnosticMode);
	void setDiagnosticPhotonMode(AcGiMrDiagnosticPhotonMode eDiagnosticPhotonMode);
	void setDiagnosticSamplesMode(bool bDiagnosticSamplesMode);
	Acad::ErrorStatus setEnergyMultiplier(float fScale);
	void setExportMIEnabled(bool bEnabled);
	Acad::ErrorStatus setExportMIFileName(const AcString& strFileName);
	Acad::ErrorStatus setExportMIMode(AcGiMrExportMIMode eExportMIMode);
	void setFGRadiusState(bool bMin, bool bMax, bool bPixels);
	Acad::ErrorStatus setFGRayCount(int iNum);
	Acad::ErrorStatus setFGSampleRadius(double fMin, double fMax);
	void setFinalGatheringEnabled(bool bEnabled);
	Acad::ErrorStatus setFinalGatheringMode(AcGiMrFinalGatheringMode mode);
	Acad::ErrorStatus setGIPhotonsPerLight(int iNum);
	Acad::ErrorStatus setGISampleCount(int iNum);
	Acad::ErrorStatus setGISampleRadius(double fRadius);
	void setGISampleRadiusEnabled(bool bEnabled);
	void setGlobalIlluminationEnabled(bool bEnabled);
	Acad::ErrorStatus setLightLuminanceScale(double fLuminance);
	Acad::ErrorStatus setMemoryLimit(int iMemoryLimit);
	Acad::ErrorStatus setPhotonTraceDepth(int iReflection, int iRefraction, int iSum);
	Acad::ErrorStatus setRayTraceDepth(int iReflection, int iRefraction, int iSum);
	void setRayTracingEnabled(bool bEnabled);
	Acad::ErrorStatus setSampling(int iMin, int iMax);
	Acad::ErrorStatus setSamplingContrastColor(float r, float g, float b, float a);
	Acad::ErrorStatus setSamplingFilter(AcGiMrFilter eFilter, double fWidth, double fHeight);
	void setShadowMapsEnabled(bool bEnabled);
	void setShadowMode(AcGiMrShadowMode eShadowMode);
	Acad::ErrorStatus setShadowSamplingMultiplier(
			AcDbMentalRayRenderSettings::ShadowSamplingMultiplier multiplier);
	void setTileOrder(AcGiMrTileOrder eTileOrder);
	Acad::ErrorStatus setTileSize(int iTileSize);
	bool shadowMapsEnabled() const;
	AcGiMrShadowMode shadowMode() const;
	AcDbMentalRayRenderSettings::ShadowSamplingMultiplier shadowSamplingMultiplier() const;
	AcGiMrTileOrder tileOrder() const;
	int tileSize() const;
};

#include "IcArxPackPop.h"

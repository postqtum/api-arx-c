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
***     Description: Declaration of AcGiMentalRayRenderSettingsTraits class
***
*****************************************************************************/
#pragma once

#include "AcGiRenderSettingsTraits.h"

enum AcGiMrDiagnosticBSPMode
{
	krDepth = 0,
	krSize
};

enum AcGiMrDiagnosticGridMode
{
	krObject = 0,
	krWorld,
	krCamera
};

enum AcGiMrDiagnosticMode
{
	krOff = 0,
	krGrid,
	krPhoton,
	krSamples,
	krBSP
};

enum AcGiMrDiagnosticPhotonMode
{
	krDensity = 0,
	krIrradiance
};

enum AcGiMrExportMIMode
{
	krExportMIOff = 0,
	krExportMIWithRender,
	krExportMIOnly
};

enum AcGiMrExposureType
{
	krAutomatic = 0,
	krLogarithmic
};

enum AcGiMrFilter
{
	krBox = 0,
	krTriangle,
	krGauss,
	krMitchell,
	krLanczos
};

enum AcGiMrFinalGatheringMode
{
	krFinalGatherOff = 0,
	krFinalGatherOn,
	krFinalGatherAuto
};

enum AcGiMrShadowMode
{
	krSimple = 0,
	krSorted,
	krSegments
};

enum AcGiMrTileOrder
{
	krHilbert = 0,
	krSpiral,
	krLeftToRight,
	krRightToLeft,
	krTopToBottom,
	krBottomToTop
};

#include "IcArxPackPush.h"

class AcGiMentalRayRenderSettingsTraits : public AcGiRenderSettingsTraits
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcGiMentalRayRenderSettingsTraits, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT virtual void SamplingFilter(AcGiMrFilter& filter, double& width,
												double& height) const = 0;
	ACDBCORE2D_PORT virtual AcGiMrDiagnosticBSPMode diagnosticBSPMode() const = 0;
	ACDBCORE2D_PORT virtual void diagnosticGridMode(AcGiMrDiagnosticGridMode& mode,
													float& fSize) const = 0;
	ACDBCORE2D_PORT virtual AcGiMrDiagnosticMode diagnosticMode() const = 0;
	ACDBCORE2D_PORT virtual AcGiMrDiagnosticPhotonMode diagnosticPhotonMode() const = 0;
	ACDBCORE2D_PORT virtual float energyMultiplier() const = 0;
	ACDBCORE2D_PORT virtual bool exportMIEnabled() const = 0;
	ACDBCORE2D_PORT virtual const ACHAR* exportMIFileName() const = 0;
	ACDBCORE2D_PORT virtual AcGiMrExportMIMode exportMIMode() const = 0;
	ACDBCORE2D_PORT virtual AcGiMrExposureType exposureType() const = 0;
	ACDBCORE2D_PORT virtual int fgRayCount() const = 0;
	ACDBCORE2D_PORT virtual void fgSampleRadius(double& min, double& max) const = 0;
	ACDBCORE2D_PORT virtual void fgSampleRadiusState(bool& bMin, bool& bMax, bool& bPixels) = 0;
	ACDBCORE2D_PORT virtual bool finalGatheringEnabled() const = 0;
	ACDBCORE2D_PORT virtual AcGiMrFinalGatheringMode finalGatheringMode() const = 0;
	ACDBCORE2D_PORT virtual int giPhotonsPerLight() const = 0;
	ACDBCORE2D_PORT virtual int giSampleCount() const = 0;
	ACDBCORE2D_PORT virtual double giSampleRadius() const = 0;
	ACDBCORE2D_PORT virtual bool giSampleRadiusEnabled() const = 0;
	ACDBCORE2D_PORT virtual bool globalIlluminationEnabled() const = 0;
	ACDBCORE2D_PORT virtual double lightLuminanceScale() const = 0;
	ACDBCORE2D_PORT virtual int memoryLimit() const = 0;
	ACDBCORE2D_PORT virtual void photonTraceDepth(int& reflection, int& refraction,
												  int& sum) const = 0;
	ACDBCORE2D_PORT virtual const void* progressMonitor() const = 0;
	ACDBCORE2D_PORT virtual void rayTraceDepth(int& reflection, int& refraction,
											   int& sum) const = 0;
	ACDBCORE2D_PORT virtual bool rayTraceEnabled() const = 0;
	ACDBCORE2D_PORT virtual void sampling(int& min, int& max) const = 0;
	ACDBCORE2D_PORT virtual void samplingContrastColor(float& r, float& g, float& b,
													   float& a) const = 0;
	ACDBCORE2D_PORT virtual void setDiagnosticBSPMode(AcGiMrDiagnosticBSPMode mode) = 0;
	ACDBCORE2D_PORT virtual void setDiagnosticGridMode(AcGiMrDiagnosticGridMode mode,
													   float fSize) = 0;
	ACDBCORE2D_PORT virtual void setDiagnosticMode(AcGiMrDiagnosticMode mode) = 0;
	ACDBCORE2D_PORT virtual void setDiagnosticPhotonMode(AcGiMrDiagnosticPhotonMode mode) = 0;
	ACDBCORE2D_PORT virtual void setEnergyMultiplier(float fScale) = 0;
	ACDBCORE2D_PORT virtual void setExportMIEnabled(bool enabled) = 0;
	ACDBCORE2D_PORT virtual void setExportMIFileName(const ACHAR* miName) = 0;
	ACDBCORE2D_PORT virtual void setExportMIMode(AcGiMrExportMIMode mode) = 0;
	ACDBCORE2D_PORT virtual void setExposureType(AcGiMrExposureType type) = 0;
	ACDBCORE2D_PORT virtual void setFGRadiusState(bool bMin, bool bMax, bool bPixels) = 0;
	ACDBCORE2D_PORT virtual void setFGRayCount(int num) = 0;
	ACDBCORE2D_PORT virtual void setFGSampleRadius(double min, double max) = 0;
	ACDBCORE2D_PORT virtual void setFinalGatheringEnabled(bool enabled) = 0;
	ACDBCORE2D_PORT virtual void setFinalGatheringMode(AcGiMrFinalGatheringMode mode) = 0;
	ACDBCORE2D_PORT virtual void setGIPhotonsPerLight(int num) = 0;
	ACDBCORE2D_PORT virtual void setGISampleCount(int num) = 0;
	ACDBCORE2D_PORT virtual void setGISampleRadius(double radius) = 0;
	ACDBCORE2D_PORT virtual void setGISampleRadiusEnabled(bool enabled) = 0;
	ACDBCORE2D_PORT virtual void setGlobalIlluminationEnabled(bool enabled) = 0;
	ACDBCORE2D_PORT virtual void setLightLuminanceScale(double luminance) = 0;
	ACDBCORE2D_PORT virtual void setMemoryLimit(int limit) = 0;
	ACDBCORE2D_PORT virtual void setPhotonTraceDepth(int reflection, int refraction, int sum) = 0;
	ACDBCORE2D_PORT virtual void setProgressMonitor(void* pMonitor) = 0;
	ACDBCORE2D_PORT virtual void setRayTraceDepth(int reflection, int refraction, int sum) = 0;
	ACDBCORE2D_PORT virtual void setRayTraceEnabled(bool enabled) = 0;
	ACDBCORE2D_PORT virtual void setSampling(int min, int max) = 0;
	ACDBCORE2D_PORT virtual void setSamplingContrastColor(float r, float g, float b, float a) = 0;
	ACDBCORE2D_PORT virtual void setSamplingFilter(AcGiMrFilter filter, double width,
												   double height) = 0;
	ACDBCORE2D_PORT virtual void setShadowMapEnabled(bool enabled) = 0;
	ACDBCORE2D_PORT virtual void setShadowMode(AcGiMrShadowMode mode) = 0;
	ACDBCORE2D_PORT virtual void setShadowSamplingMultiplier(double multiplier) = 0;
	ACDBCORE2D_PORT virtual void setTileOrder(AcGiMrTileOrder order) = 0;
	ACDBCORE2D_PORT virtual void setTileSize(int size) = 0;
	ACDBCORE2D_PORT virtual bool shadowMapEnabled() const = 0;
	ACDBCORE2D_PORT virtual AcGiMrShadowMode shadowMode() const = 0;
	ACDBCORE2D_PORT virtual double shadowSamplingMultiplier() const = 0;
	ACDBCORE2D_PORT virtual AcGiMrTileOrder tileOrder() const = 0;
	ACDBCORE2D_PORT virtual int tileSize() const = 0;
};

#include "IcArxPackPop.h"

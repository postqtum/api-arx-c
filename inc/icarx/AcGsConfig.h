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
***     Description: Declaration of AcGsConfig, AcGsConfigReactor classes
***
*****************************************************************************/
#pragma once

#include "../AdAChar.h"
#include "../AcString.h"
#include "../acarray.h"
#include "AcGsEnum.h"

#include "IcArxPackPush.h"

class AcGsConfigReactor
{
public:
	AcGsConfigReactor() = default;
	virtual ~AcGsConfigReactor() = default;

	virtual void configWasModified() {}
	virtual void deviceSwitchHasEnded() {}
	virtual void deviceSwitchToBegin() {}
	virtual void hardwareAccelerationWasModified(bool /*newValue*/) {}
};

class AcGsConfig
{
public:
	struct CertificationData
	{
		AcString sCardName;
		AcString sDriverVersion;
		AcString sProductDriverURL;
		AcString sTuningDate;
		AcString sDeviceFailed;
		int nHardwareFeatureLevel;
		int nSoftwareFeatureLevel;
		int nCertificationStatus;
		int nHardwareID;
	};

	enum DegradationChannel
	{
		kViewportDraw,
		kLineAntialias,
		kLighting,
		kTransparencyQuality,
		kShadowsFull,
		kTransparency,
		kDiscardBackfaces,
		kShadowsGround,
		kEdgeStyles,
		kFacetEdges,
		kFastSilhouette,
		kTextures,
		kMaterials,
		kLightingQuality,
		kBackgrounds,
		kIntersectEdges,
		kFaceted,
		kWireframe,
		kDegradationChannels
	};

	enum EffectListType
	{
		kEL_Current,
		kEL_RegistryHardware,
		kEL_RegistrySoftware,
		kEL_File,
		kEL_HardwareBasic,
		kEL_HardwareMedium,
		kEL_HardwareAdvanced
	};

	struct EffectStatus
	{
		const AcUniqueString* pUniqueString;
		AcString effectName;
		int bEnabled;
		int bRecommended;
		int bAvailable;
		int nFeatureLevel;
	};

	enum FeatureModeType
	{
		kFM_Start = -3,
		kFM_Legacy = kFM_Start,
		kFM_ClassicDx9,
		kFM_ClassicDx11,
		kFM_Software,
		kFM_Basic,
		kFM_Medium,
		kFM_Advanced,
		kFM_Unknown = 0xffff,
	};

	enum Handedness
	{
		kLeft,
		kRight
	};

	enum Quality
	{
		kLowQuality,
		kMediumQuality,
		kHighQuality
	};

	enum SpyglassType
	{
		kNone = 0,
		kSoftware,
		kHardware
	};

protected:
	AcGsConfig() = default;

public:
	virtual ~AcGsConfig() = default;

	virtual bool adaptiveDegradation() const = 0;
	virtual void addReactor(AcGsConfigReactor*) = 0;
	virtual bool canDegradeChannel(DegradationChannel) const = 0;
	virtual bool canEnableMetal() const = 0;
	virtual bool configure() = 0;
	virtual void currentDisplayDriver(ACHAR* pszPath, int nPathStrLen, ACHAR* pszDriver,
									  int nDriverStrLen, bool& bAccelerated) const = 0;
	virtual int curveTessellationTol() const = 0;
	virtual void defaultHardwareAcceleratedDriver(ACHAR* pszPath, int nPathStrLen, ACHAR* pszDriver,
												  int nDriverStrLen) const = 0;
	virtual int degradationChainPosition(DegradationChannel) const = 0;
	virtual DegradationChannel degradationChannelAt(int position) const = 0;
	virtual bool discardBackFaces() const = 0;
	virtual void driverName(ACHAR* pszPath, int nStrLen) const = 0;
	virtual void driverPath(ACHAR* pszPath, int nStrLen) const = 0;
	virtual int driverRevision() const = 0;
	virtual int driverVersion() const = 0;
	virtual bool dynamicTessellation() const = 0;
	virtual int frameRate() const = 0;
	virtual bool generateVertexNormals() const = 0;
	virtual CertificationData getCertificationData() = 0;
	virtual AcArray<EffectStatus>* getEffectList(EffectListType type) = 0;
	virtual int getFeatureAvailableVal(const AcUniqueString*) const = 0;
	virtual FeatureModeType getFeatureMode() const = 0;
	virtual int getFeatureModeAvailable() const = 0;
	virtual int getFeatureRecommendedVal(const AcUniqueString*) const = 0;
	virtual int getFeatureVal(const AcUniqueString*) const = 0;
	virtual AcString getVirtualDeviceName() = 0;
	virtual Handedness handedness() const = 0;
	virtual void hardwareAcceleratedDriver(ACHAR* pszPath, int nPathStrLen, ACHAR* pszDriver,
										   int nDriverStrLen) const = 0;
	virtual void hardwareAcceleratedDrivers(ACHAR* pszPath, int nPathStrLen, ACHAR** pszDrivers,
											int nDrivers, int nDriverStrLen) = 0;
	virtual bool isAADisabledInInteractive() const = 0;
	virtual bool isFeatureAvailable(const AcUniqueString*) const = 0;
	virtual bool isFeatureEnabled(const AcUniqueString*) const = 0;
	virtual bool isFeatureRecommended(const AcUniqueString*) const = 0;
	virtual bool isHardwareAccelerationAvailable() const = 0;
	virtual bool isHardwareAccelerationEnabled() const = 0;
	virtual bool isHardwareAccelerationRecommended() const = 0;
	virtual bool isInConfiguring() = 0;
	virtual bool isLODEnabledInRetainModeWhileInteractive() const = 0;
	virtual bool isNoHardwareOverrideEnabled() const = 0;
	virtual int maxLODs() const = 0;
	virtual int numHardwareAcceleratedDrivers() = 0;
	virtual bool redrawOnWindowExpose() const = 0;
	virtual void removeReactor(AcGsConfigReactor*) = 0;
	virtual void restore() = 0;
	virtual void saveToRegistry() = 0;
	virtual void setAdaptiveDegradation(bool bAdaptiveDegradation) = 0;
	virtual void setCanDegradeChannel(DegradationChannel, bool bDegrade) = 0;
	virtual GS::ErrorStatus setCurveTessellationTol(int curveTessellationTol) = 0;
	virtual void setDiscardBackFaces(bool bDiscardBackFaces) = 0;
	virtual void setDriverPath(const ACHAR* pszPath) = 0;
	virtual void setDynamicTessellation(bool bDynamicTessellation) = 0;
	virtual void setFeatureEnabled(const AcUniqueString*, bool bEnable = true) = 0;
	virtual void setFeatureMode(const FeatureModeType) = 0;
	virtual void setFeatureVal(const AcUniqueString*, int iVal = 0) = 0;
	virtual GS::ErrorStatus setFrameRate(int nFramesPerSecond) = 0;
	virtual void setGenerateVertexNormals(bool bEnable) = 0;
	virtual void setHandedness(Handedness) = 0;
	virtual void setHardwareAcceleratedDriver(const ACHAR* pszPath, const ACHAR* pszDriver) = 0;
	virtual void setHardwareAcceleration(bool bEnable) = 0;
	virtual GS::ErrorStatus setMaxLODs(int nLevels) = 0;
	virtual void setRedrawOnWindowExpose(bool bRedrawWindowExpose) = 0;
	virtual GS::ErrorStatus setSurfaceTessellationTol(int surfaceTessellationTol) = 0;
	virtual void setTransparency(Quality quality) = 0;
	virtual void shiftDegradationChainPosition(DegradationChannel, bool bShiftDown) = 0;
	virtual bool showConfigDialog(const wchar_t* strInput = nullptr) const = 0;
	virtual SpyglassType spyglassType() const = 0;
	virtual int surfaceTessellationTol() const = 0;
	virtual Quality transparency() const = 0;
};

#include "IcArxPackPop.h"

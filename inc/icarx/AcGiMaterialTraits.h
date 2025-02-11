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
***     Description: Declaration of AcGiMaterialTraits class
***
*****************************************************************************/
#pragma once

#include "AcGiNonEntityTraits.h"

class AcGiMaterialColor;
class AcGiMaterialMap;

#include "IcArxPackPush.h"

class AcGiMaterialTraits : public AcGiNonEntityTraits
{
public:
	ACRX_DECLARE_MEMBERS(AcGiMaterialTraits);

	enum ChannelFlags
	{
		kNone = 0x00000,
		kUseDiffuse = 0x00001,
		kUseSpecular = 0x00002,
		kUseReflection = 0x00004,
		kUseOpacity = 0x00008,
		kUseBump = 0x00010,
		kUseRefraction = 0x00020,
		kUseNormalMap = 0x00040,
		kUseAll = (kUseDiffuse | kUseSpecular | kUseReflection | kUseOpacity | kUseBump |
				   kUseRefraction | kUseNormalMap),
	};

	enum GlobalIlluminationMode
	{
		kGlobalIlluminationNone,
		kGlobalIlluminationCast,
		kGlobalIlluminationReceive,
		kGlobalIlluminationCastAndReceive
	};

	enum FinalGatherMode
	{
		kFinalGatherNone,
		kFinalGatherCast,
		kFinalGatherReceive,
		kFinalGatherCastAndReceive
	};

	enum IlluminationModel
	{
		kBlinnShader = 0,
		kMetalShader,
	};

	enum LuminanceMode
	{
		kSelfIllumination = 0,
		kLuminance,
	};

	enum Mode
	{
		kRealistic = 0,
		kAdvanced,
	};

	enum NormalMapMethod
	{
		kTangentSpace
	};

	virtual void ambient(AcGiMaterialColor& color) const = 0;
	virtual void bump(AcGiMaterialMap& map) const = 0;
	virtual ChannelFlags channelFlags() const = 0;
	virtual double colorBleedScale() const = 0;
	virtual void diffuse(AcGiMaterialColor& color, AcGiMaterialMap& map) const = 0;
	virtual FinalGatherMode finalGather() const = 0;
	virtual GlobalIlluminationMode globalIllumination() const = 0;
	virtual IlluminationModel illuminationModel() const = 0;
	virtual double indirectBumpScale() const = 0;
	virtual double luminance() const = 0;
	virtual LuminanceMode luminanceMode() const = 0;
	virtual Mode mode() const = 0;
	virtual void normalMap(AcGiMaterialMap& map, NormalMapMethod& method,
						   double& strength) const = 0;
	virtual void opacity(double& dPercentage, AcGiMaterialMap& map) const = 0;
	virtual double reflectanceScale() const = 0;
	virtual void reflection(AcGiMaterialMap& map) const = 0;
	virtual double reflectivity() const = 0;
	virtual void refraction(double& dIndex, AcGiMaterialMap& map) const = 0;
	virtual double selfIllumination() const = 0;
	virtual void setAmbient(const AcGiMaterialColor& color) = 0;
	virtual void setBump(const AcGiMaterialMap& map) = 0;
	virtual void setChannelFlags(ChannelFlags flags) = 0;
	virtual void setColorBleedScale(double value) = 0;
	virtual void setDiffuse(const AcGiMaterialColor& color, const AcGiMaterialMap& map) = 0;
	virtual void setFinalGather(FinalGatherMode mode) = 0;
	virtual void setGlobalIllumination(GlobalIlluminationMode mode) = 0;
	virtual void setIlluminationModel(IlluminationModel model) = 0;
	virtual void setIndirectBumpScale(double value) = 0;
	virtual void setLuminance(double value) = 0;
	virtual void setLuminanceMode(LuminanceMode value) = 0;
	virtual void setMode(Mode value) = 0;
	virtual void setNormalMap(const AcGiMaterialMap& map, NormalMapMethod method,
							  double strength) = 0;
	virtual void setOpacity(double dPercentage, const AcGiMaterialMap& map) = 0;
	virtual void setReflectanceScale(double value) = 0;
	virtual void setReflection(const AcGiMaterialMap& map) = 0;
	virtual void setReflectivity(double value) = 0;
	virtual void setRefraction(double dIndex, const AcGiMaterialMap& map) = 0;
	virtual void setSelfIllumination(double value) = 0;
	virtual void setSpecular(const AcGiMaterialColor& color, const AcGiMaterialMap& map,
							 double dGloss) = 0;
	virtual void setTranslucence(double value) = 0;
	virtual void setTransmittanceScale(double value) = 0;
	virtual void setTwoSided(bool value) = 0;
	virtual void specular(AcGiMaterialColor& color, AcGiMaterialMap& map, double& dGloss) const = 0;
	virtual double translucence() const = 0;
	virtual double transmittanceScale() const = 0;
	virtual bool twoSided() const = 0;
};

#include "IcArxPackPop.h"

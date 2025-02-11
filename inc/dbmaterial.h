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
***     Description: Common includes for database support
***
*****************************************************************************/
#pragma once

#include "dbmain.h"
#include "acgimaterial.h"

#include "icarx/IcArxPackPush.h"

class AcDbMaterial : public AcDbObject
{
public:
	enum MaterialFlags
	{
		kNone = 0,
		kIsLegacy = 0x1,
		kIsModifiedIsValid = 0x2,
		kIsModified = 0x4,
		kIsModifiedAndValid = 0x6
	};

protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbMaterial);

	AcDbMaterial();
	~AcDbMaterial();

	virtual void ambient(AcGiMaterialColor& color) const;
	virtual void bump(AcGiMaterialMap& map) const;
	virtual AcGiMaterialTraits::ChannelFlags channelFlags() const;
	void clearAdskMaterialCache();
	double colorBleedScale() const;
	virtual const ACHAR* description(void) const;
	virtual void diffuse(AcGiMaterialColor& color, AcGiMaterialMap& map) const;
	AcGiDrawable* drawable(void) override;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	AcGiMaterialTraits::FinalGatherMode finalGather() const;
	void* getAdskMaterialData();
	Acad::ErrorStatus getAdskMaterialFlags(MaterialFlags& flags) const;
	AcGiMaterialTraits::GlobalIlluminationMode globalIllumination() const;
	virtual AcGiMaterialTraits::IlluminationModel illuminationModel() const;
	double indirectBumpScale() const;
	bool isAnonymous() const;
	bool isRenamable() const;
	double luminance() const;
	AcGiMaterialTraits::LuminanceMode luminanceMode() const;
	virtual AcGiMaterialTraits::Mode mode() const;
	virtual const ACHAR* name(void) const;
	Acad::ErrorStatus normalMap(AcGiMaterialMap& map, AcGiMaterialTraits::NormalMapMethod& method,
								double& strength) const;
	virtual void opacity(double& dPercentage, AcGiMaterialMap& map) const;
	double reflectanceScale() const;
	virtual void reflection(AcGiMaterialMap& map) const;
	virtual double reflectivity() const;
	virtual void refraction(double& dIndex, AcGiMaterialMap& map) const;
	virtual double selfIllumination() const;
	Acad::ErrorStatus setAdskMaterialData(const void* pMatObj, bool bCacheIt = false);
	Acad::ErrorStatus setAdskMaterialFlags(MaterialFlags flags);
	virtual void setAmbient(const AcGiMaterialColor& color);
	Acad::ErrorStatus setAnonymous(bool isAnonymous);
	virtual void setBump(const AcGiMaterialMap& map);
	virtual Acad::ErrorStatus setChannelFlags(AcGiMaterialTraits::ChannelFlags value);
	Acad::ErrorStatus setColorBleedScale(double value);
	virtual Acad::ErrorStatus setDescription(const ACHAR* pDescription);
	virtual void setDiffuse(const AcGiMaterialColor& color, const AcGiMaterialMap& map);
	void setFinalGather(AcGiMaterialTraits::FinalGatherMode mode);
	void setGlobalIllumination(AcGiMaterialTraits::GlobalIlluminationMode mode);
	virtual Acad::ErrorStatus setIlluminationModel(AcGiMaterialTraits::IlluminationModel model);
	Acad::ErrorStatus setIndirectBumpScale(double value);
	Acad::ErrorStatus setLuminance(double value);
	Acad::ErrorStatus setLuminanceMode(AcGiMaterialTraits::LuminanceMode value);
	virtual Acad::ErrorStatus setMode(AcGiMaterialTraits::Mode value);
	virtual Acad::ErrorStatus setName(const ACHAR* pName);
	Acad::ErrorStatus setNormalMap(const AcGiMaterialMap& map,
								   AcGiMaterialTraits::NormalMapMethod method, double strength);
	virtual void setOpacity(double dPercentage, const AcGiMaterialMap& map);
	Acad::ErrorStatus setReflectanceScale(double value);
	virtual void setReflection(const AcGiMaterialMap& map);
	virtual Acad::ErrorStatus setReflectivity(double value);
	virtual void setRefraction(double dIndex, const AcGiMaterialMap& map);
	virtual Acad::ErrorStatus setSelfIllumination(double value);
	Acad::ErrorStatus setShininess(double value);
	virtual void setSpecular(const AcGiMaterialColor& color, const AcGiMaterialMap& map,
							 double dGloss);
	virtual Acad::ErrorStatus setTranslucence(double value);
	Acad::ErrorStatus setTransmittanceScale(double value);
	Acad::ErrorStatus setTwoSided(bool value);
	double shininess() const;
	virtual void specular(AcGiMaterialColor& color, AcGiMaterialMap& map, double& dGloss) const;
	virtual double translucence() const;
	double transmittanceScale() const;
	bool twoSided() const;
};

#include "icarx/IcArxPackPop.h"

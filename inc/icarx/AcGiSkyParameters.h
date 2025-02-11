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
***     Description: Declaration of AcGiSkyParameters class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../rxboiler.h"
#include "AcCmColor.h"

class AcGeVector3d;
class AcGiImpSkyParameters;

#include "IcArxPackPush.h"

class AcGiSkyParameters : public AcRxObject
{
	friend class AcGiImpSkyParameters;

private:
	AcGiImpSkyParameters* m_Imp;

protected:
	virtual bool aerialPerspectiveImp() const;
	virtual double diskIntensityImp() const;
	virtual double diskScaleImp() const;
	virtual double glowIntensityImp() const;
	virtual AcCmColor groundColorImp() const;
	virtual double hazeImp() const;
	virtual double horizonBlurImp() const;
	virtual double horizonHeightImp() const;
	virtual bool illuminationImp() const;
	virtual double intensityFactorImp() const;
	virtual AcCmColor nightColorImp() const;
	virtual double redBlueShiftImp() const;
	virtual double saturationImp() const;
	virtual void setAerialPerspectiveImp(bool apply);
	virtual bool setDiskIntensityImp(double intensity);
	virtual bool setDiskScaleImp(double scale);
	virtual bool setGlowIntensityImp(double intensity);
	virtual void setGroundColorImp(const AcCmColor& color);
	virtual bool setHazeImp(double haze);
	virtual bool setHorizonBlurImp(double blur);
	virtual bool setHorizonHeightImp(double height);
	virtual void setIlluminationImp(bool enable);
	virtual bool setIntensityFactorImp(double intensity);
	virtual void setNightColorImp(const AcCmColor& color);
	virtual bool setRedBlueShiftImp(double redBlueShift);
	virtual bool setSaturationImp(double saturation);
	virtual bool setSolarDiskSamplesImp(uint16_t samples);
	virtual bool setSunDirectionImp(const AcGeVector3d& sundir);
	virtual bool setVisibilityDistanceImp(double distance);
	virtual uint16_t solarDiskSamplesImp() const;
	virtual const AcGeVector3d& sunDirectionImp() const;
	virtual double visibilityDistanceImp() const;

public:
	ACRX_DECLARE_MEMBERS(AcGiSkyParameters);

	AcGiSkyParameters();
	AcGiSkyParameters(const AcGiSkyParameters&);
	~AcGiSkyParameters();
	AcGiSkyParameters& operator=(const AcGiSkyParameters&);
	bool operator==(const AcGiSkyParameters&) const;

	bool aerialPerspective() const { return aerialPerspectiveImp(); }
	double diskIntensity() const { return diskIntensityImp(); }
	double diskScale() const { return diskScaleImp(); }
	double glowIntensity() const { return glowIntensityImp(); }
	AcCmColor groundColor() const { return groundColorImp(); }
	double haze() const { return hazeImp(); }
	bool illumination() const { return illuminationImp(); }
	double horizonBlur() const { return horizonBlurImp(); }
	double horizonHeight() const { return horizonHeightImp(); }
	double intensityFactor() const { return intensityFactorImp(); }
	AcCmColor nightColor() const { return nightColorImp(); }
	double redBlueShift() const { return redBlueShiftImp(); }
	double saturation() const { return saturationImp(); }
	void setAerialPerspective(bool apply) { setAerialPerspectiveImp(apply); }
	bool setDiskIntensity(double intensity) { return setDiskIntensityImp(intensity); }
	bool setDiskScale(double scale) { return setDiskScaleImp(scale); }
	bool setGlowIntensity(double intensity) { return setGlowIntensityImp(intensity); }
	void setGroundColor(const AcCmColor& color) { return setGroundColorImp(color); }
	bool setHaze(double haze) { return setHazeImp(haze); }
	bool setHorizonBlur(double blur) { return setHorizonBlurImp(blur); }
	bool setHorizonHeight(double height) { return setHorizonHeightImp(height); }
	void setIllumination(bool enable) { return setIlluminationImp(enable); }
	bool setIntensityFactor(double intensity) { return setIntensityFactorImp(intensity); }
	void setNightColor(const AcCmColor& color) { setNightColorImp(color); }
	bool setRedBlueShift(double redBlueShift) { return setRedBlueShiftImp(redBlueShift); }
	bool setSaturation(double saturation) { return setSaturationImp(saturation); }
	bool setSolarDiskSamples(uint16_t samples) { return setSolarDiskSamplesImp(samples); }
	bool setSunDirection(const AcGeVector3d& sundir) { return setSunDirectionImp(sundir); }
	bool setVisibilityDistance(double distance) { return setVisibilityDistanceImp(distance); }
	uint16_t solarDiskSamples() const { return solarDiskSamplesImp(); }
	const AcGeVector3d& sunDirection() const { return sunDirectionImp(); }
	double visibilityDistance() const { return visibilityDistanceImp(); }
};

#include "IcArxPackPop.h"

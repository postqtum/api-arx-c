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
***     Description: Declaration of AcDbSun class
***
*****************************************************************************/
#pragma once

#include "dbmain.h"

#pragma warning(disable : 4275 4251)

#ifdef SCENEOE
#	define DLLIMPEXP __declspec(dllexport)
#else
#	define DLLIMPEXP
#endif

#include "AcGiLightTraits.h"
#include "rxboiler.h"
#include "dbLight.h"

class AcDbImpSun;

#include "icarx/IcArxPackPush.h"

class LIGHTDLLIMPEXP AcDbSun : public AcDbObject
{
private:
	static uint32_t kCurrentVersionNumber;

protected:
	uint32_t subSetAttributes(AcGiDrawableTraits* pTraits) override;

public:
	ACRX_DECLARE_MEMBERS(AcDbSun);

	AcDbSun();
	~AcDbSun();

	virtual double altitude() const;
	virtual double azimuth() const;
	virtual const AcDbDate& dateTime() const;
	Acad::ErrorStatus decomposeForSave(AcDb::AcDbDwgVersion ver, AcDbObject*& replaceObj,
									   AcDbObjectId& replaceId, bool& exchangeXData) override;
	AcGiDrawable* drawable() override;
	DrawableType drawableType() const override { return AcGiDrawable::kDistantLight; }
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	virtual double intensity() const;
	virtual bool isDayLightSavingsOn() const;
	virtual bool isOn() const;
	virtual Acad::ErrorStatus setAltitude(double altitude);
	virtual Acad::ErrorStatus setAzimuth(double azimuth);
	virtual Acad::ErrorStatus setDateTime(const AcDbDate& datetime);
	virtual Acad::ErrorStatus setDayLightSavingsOn(bool value);
	virtual Acad::ErrorStatus setIntensity(double intensity);
	virtual Acad::ErrorStatus setOn(bool value);
	virtual void setShadowParameters(const AcGiShadowParameters& params);
	Acad::ErrorStatus setSkyParameters(const AcGiSkyParameters& params);
	virtual Acad::ErrorStatus setSunColor(const AcCmColor& color);
	virtual void setSunDirection(const AcGeVector3d& sundir);
	virtual const AcGiShadowParameters& shadowParameters() const;
	Acad::ErrorStatus skyParameters(AcGiSkyParameters& params) const;
	virtual const AcCmColor& sunColor() const;
	virtual const AcGiColorRGB& sunColorPhotometric(const double multiplier);
	virtual const AcGeVector3d& sunDirection() const;
};

#include "icarx/IcArxPackPop.h"

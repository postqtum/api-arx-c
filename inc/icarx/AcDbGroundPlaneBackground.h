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
***     Description: Declaration of AcDbGroundPlaneBackground class
***
*****************************************************************************/
#pragma once

#include "AcDbBackground.h"

class AcCmEntityColor;

#include "IcArxPackPush.h"
#pragma warning(disable : 4275 4251)

class SCENEDLLIMPEXP AcDbGroundPlaneBackground : public AcDbBackground
{
	friend class AcDbImpGroundPlaneBackground;

protected:
	uint32_t subSetAttributes(AcGiDrawableTraits* pTraits) override;

public:
	ACRX_DECLARE_MEMBERS(AcDbGroundPlaneBackground);

	AcDbGroundPlaneBackground();
	~AcDbGroundPlaneBackground();

	AcCmEntityColor colorGroundPlaneFar() const;
	AcCmEntityColor colorGroundPlaneNear() const;
	AcCmEntityColor colorSkyHorizon() const;
	AcCmEntityColor colorSkyZenith() const;
	AcCmEntityColor colorUndergroundAzimuth() const;
	AcCmEntityColor colorUndergroundHorizon() const;
	Acad::ErrorStatus copyFrom(const AcRxObject* other) override;
	AcGiDrawable::DrawableType drawableType() const override;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	void setColorGroundPlaneFar(const AcCmEntityColor& color);
	void setColorGroundPlaneNear(const AcCmEntityColor& color);
	void setColorSkyHorizon(const AcCmEntityColor& color);
	void setColorSkyZenith(const AcCmEntityColor& color);
	void setColorUndergroundAzimuth(const AcCmEntityColor& color);
	void setColorUndergroundHorizon(const AcCmEntityColor& color);
};

#include "IcArxPackPop.h"

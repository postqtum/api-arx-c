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
***     Description: Declaration of AcDbRapidRTRenderSettings class
***
*****************************************************************************/
#pragma once

#include "AcGiRapidRTRenderSettingsTraits.h"
#include "SceneDllImpExp.h"
#include "AcDbRenderSettings.h"

#include "IcArxPackPush.h"

class SCENEDLLIMPEXP AcDbRapidRTRenderSettings : public AcDbRenderSettings
{
public:
	enum RenderTarget
	{
		krLevel = 0,
		krTime = 1,
		krInfinite = 2
	};

protected:
	uint32_t subSetAttributes(AcGiDrawableTraits* pTraits) override;

public:
	ACRX_DECLARE_MEMBERS(AcDbRapidRTRenderSettings);

	AcDbRapidRTRenderSettings();
	~AcDbRapidRTRenderSettings();
	virtual bool operator==(const AcDbRapidRTRenderSettings& settings);

	Acad::ErrorStatus copyFrom(const AcRxObject* other) override;
	Acad::ErrorStatus decomposeForSave(AcDb::AcDbDwgVersion ver, AcDbObject*& replaceObj,
									   AcDbObjectId& replaceId, bool& exchangeXData) override;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	float filterHeight() const;
	AcGiFilterType filterType() const;
	float filterWidth() const;
	AcGiLightingMode lightingModel() const;
	int renderLevel() const;
	RenderTarget renderTarget() const;
	int renderTime() const;
	Acad::ErrorStatus setFilterHeight(float height);
	Acad::ErrorStatus setFilterType(AcGiFilterType type);
	Acad::ErrorStatus setFilterWidth(float width);
	Acad::ErrorStatus setLightingModel(AcGiLightingMode model);
	Acad::ErrorStatus setRenderLevel(int level);
	Acad::ErrorStatus setRenderTarget(RenderTarget target);
	Acad::ErrorStatus setRenderTime(int time);
};

#include "IcArxPackPop.h"

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
***     Description: Declaration of AcDbRenderSettings class
***
*****************************************************************************/
#pragma once

#include "../AcString.h"

#include "SceneDllImpExp.h"
#include "AcDbObject.h"

class AcDbImpRenderSettings;

#include "IcArxPackPush.h"

class SCENEDLLIMPEXP AcDbRenderSettings : public AcDbObject
{
protected:
	uint32_t subSetAttributes(AcGiDrawableTraits* pTraits) override;

public:
	ACRX_DECLARE_MEMBERS(AcDbRenderSettings);

	AcDbRenderSettings();
	AcDbRenderSettings(AcDbImpRenderSettings*);
	~AcDbRenderSettings();
	virtual bool operator==(const AcDbRenderSettings& settings);

	bool backFacesEnabled() const;
	Acad::ErrorStatus copyFrom(const AcRxObject* other) override;
	AcString description() const;
	bool diagnosticBackgroundEnabled() const;
	int displayIndex() const;
	AcGiDrawable* drawable() override;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	bool isPredefined() const;
	bool materialsEnabled() const;
	AcString name() const;
	AcString previewImageFileName() const;
	void setBackFacesEnabled(bool bEnabled);
	void setDescription(const AcString& strDes);
	void setDiagnosticBackgroundEnabled(bool bEnabled);
	void setDisplayIndex(int idx);
	Acad::ErrorStatus setIsPredefined(bool bPredefined);
	void setMaterialsEnabled(bool bEnabled);
	Acad::ErrorStatus setName(const AcString& strName);
	Acad::ErrorStatus setPreviewImageFileName(const AcString& strFileName);
	void setShadowsEnabled(bool bEnabled);
	void setTextureSampling(bool bSampling);
	bool shadowsEnabled() const;
	bool textureSampling() const;
};

#include "IcArxPackPop.h"

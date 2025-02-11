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
***     Description: Declaration of AcDbRenderEnvironment class
***
*****************************************************************************/
#pragma once

#include "../AcString.h"

#include "AcCmEntityColor.h"
#include "SceneDllImpExp.h"
#include "AcDbObject.h"

class AcDbImpRenderEnvironment;

#include "IcArxPackPush.h"

class SCENEDLLIMPEXP AcDbRenderEnvironment : public AcDbObject
{
protected:
	uint32_t subSetAttributes(AcGiDrawableTraits* pTraits) override;

public:
	ACRX_DECLARE_MEMBERS(AcDbRenderEnvironment);

	AcDbRenderEnvironment();
	~AcDbRenderEnvironment();
	virtual bool operator==(const AcDbRenderEnvironment& environment);

	void distances(double& dNear, double& dFar) const;
	AcGiDrawable* drawable() override;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	bool environmentImageEnabled() const;
	AcString environmentImageFileName() const;
	bool fogBackgroundEnabled() const;
	AcCmEntityColor fogColor() const;
	void fogDensity(double& dNear, double& dFar) const;
	bool fogEnabled() const;
	Acad::ErrorStatus setDistances(double dNear, double dFar);
	void setEnvironmentImageEnabled(bool bEnabled);
	Acad::ErrorStatus setEnvironmentImageFileName(const AcString& strFileName);
	void setFogBackgroundEnabled(bool bEnable);
	void setFogColor(const AcCmEntityColor& color);
	Acad::ErrorStatus setFogDensity(double dNear, double dFar);
	void setFogEnabled(bool bEnable);
};

#include "IcArxPackPop.h"

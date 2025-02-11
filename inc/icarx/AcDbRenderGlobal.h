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
***     Description: Declaration of AcDbRenderGlobal class
***
*****************************************************************************/
#pragma once

#include "../AcString.h"

#include "AcGiMentalRayRenderSettingsTraits.h"
#include "SceneDllImpExp.h"
#include "AcDbObject.h"

#include "IcArxPackPush.h"

class SCENEDLLIMPEXP AcDbRenderGlobal : public AcDbObject
{
public:
	enum Destination
	{
		krWindow = 0,
		krViewport
	};

	enum Procedure
	{
		krView = 0,
		krCrop,
		krSelected
	};

public:
	ACRX_DECLARE_MEMBERS(AcDbRenderGlobal);

	AcDbRenderGlobal();
	~AcDbRenderGlobal();
	bool operator==(const AcDbRenderGlobal& global);

	Acad::ErrorStatus copyFrom(const AcRxObject* other) override;
	Destination destination();
	AcString dimensionName() const;
	void dimensions(int& w, int& h) const;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	AcGiMrExposureType exposureType() const;
	bool highInfoLevel() const;
	bool predefinedPresetsFirst() const;
	Procedure procedure();
	void procedureAndDestination(Procedure& eProcedure, Destination& eDestination) const;
	bool saveEnabled() const;
	AcString saveFileName() const;
	Acad::ErrorStatus setDestination(Destination eDestination);
	Acad::ErrorStatus setDimensions(int w, int h);
	Acad::ErrorStatus setExposureType(AcGiMrExposureType type);
	void setHighInfoLevel(bool bHighInfoLevel);
	void setPredefinedPresetsFirst(bool bPredefinedPresetsFirst);
	Acad::ErrorStatus setProcedure(Procedure eProcedure);
	void setProcedureAndDestination(Procedure eProcedure, Destination eDestination);
	void setSaveEnabled(bool bEnabled);
	Acad::ErrorStatus setSaveFileName(const AcString& strFileName);
};

#include "IcArxPackPop.h"

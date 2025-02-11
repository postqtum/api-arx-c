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
***     Description: Declaration of AcDbPointCloudColorRamp class
***
*****************************************************************************/
#pragma once

#include "../acdbport.h"
#include "../acadstrc.h"
#include "../AcString.h"

#include "AcCmEntityColor.h"

class AcDbDwgFiler;
class AcDbDxfFiler;
class PointCloudColorRampImp;

#include "IcArxPackPush.h"

class ACDB_PORT AcDbPointCloudColorRamp
{
	friend class PointCloudColorMapImp;

private:
	PointCloudColorRampImp* pImpl;

private:
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler);
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler);
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const;

public:
	AcDbPointCloudColorRamp();
	~AcDbPointCloudColorRamp();

	AcDbPointCloudColorRamp(const AcDbPointCloudColorRamp&) = delete;
	AcDbPointCloudColorRamp& operator=(const AcDbPointCloudColorRamp&) = delete;

	AcCmEntityColor color(int c) const;
	const AcString name() const;
	int32_t numColors() const;
	void setColor(int c, AcCmEntityColor color);
	void setFrom(const AcDbPointCloudColorRamp* source);
	Acad::ErrorStatus setName(const AcString& name);
	Acad::ErrorStatus setNumColors(int32_t count);
	void setVisibility(int c, bool visibility);
	bool visibility(int c) const;
};

#include "IcArxPackPop.h"

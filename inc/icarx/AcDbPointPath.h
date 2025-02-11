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
***     Description: Declaration of AcDbPointPath class
***
*****************************************************************************/
#pragma once

#include "../gepnt3d.h"
#include "AcDbNamedPath.h"

#include "IcArxPackPush.h"
#pragma warning(disable : 4275 4251)

class SCENEDLLIMPEXP AcDbPointPath : public AcDbNamedPath
{
	friend class AcDbPointPath;

protected:
	uint32_t subSetAttributes(AcGiDrawableTraits* pTraits) override;

public:
	ACRX_DECLARE_MEMBERS(AcDbPointPath);

	AcDbPointPath();
	~AcDbPointPath();

	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	Acad::ErrorStatus getGeometry(AcGeCurve3d*& pCurveGeometry) const override;
	Acad::ErrorStatus setGeometry(const AcGePoint3d& pt);
};

#include "IcArxPackPop.h"

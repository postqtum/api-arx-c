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
***     Description: Declaration of AcDbPointCloudDefReactorEx class
***
*****************************************************************************/
#pragma once

#include "AcDbObject.h"

class PointCloudDefReactorExImp;

#include "IcArxPackPush.h"

class ACDB_PORT AcDbPointCloudDefReactorEx : public AcDbObject
{
private:
	static int m_version;
	static bool m_bIsEnabled;
	PointCloudDefReactorExImp* m_pImp = nullptr;

public:
	ACRX_DECLARE_MEMBERS(AcDbPointCloudDefReactorEx);

public:
	AcDbPointCloudDefReactorEx();
	~AcDbPointCloudDefReactorEx();

	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	void erased(const AcDbObject* dbObj, bool pErasing = true) override;
	void modified(const AcDbObject* dbObj) override;
	static int classVersion();
	static bool isEnabled();
	static void setEnable(bool bEnable);
};

#include "IcArxPackPop.h"

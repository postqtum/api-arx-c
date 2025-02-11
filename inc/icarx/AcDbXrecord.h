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
***     Description: Declaration of AcDbXrecord class
***
*****************************************************************************/
#pragma once

#include "../dbmain.h"

#define ACDB_XRECORD_CLASS ACRX_T(/*MSG0*/ "AcDbXrecord")

#include "IcArxPackPush.h"

class AcDbXrecord : public AcDbObject
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbXrecord);

	AcDbXrecord();
	~AcDbXrecord();

	ACDBCORE2D_PORT Acad::ErrorStatus appendRbChain(const resbuf& pRb);
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* filer) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* filer) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* filer) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* filer) const override;
	bool isXlateReferences() const;
	AcDb::DuplicateRecordCloning mergeStyle() const override;
	Acad::ErrorStatus rbChain(resbuf** ppRb, AcDbDatabase* auxDb = nullptr) const;
	Acad::ErrorStatus setFromRbChain(const resbuf& pRb, AcDbDatabase* auxDb = nullptr);
	virtual void setMergeStyle(AcDb::DuplicateRecordCloning style);
	void setXlateReferences(bool translate);
	Acad::ErrorStatus subClose() override;
};

#include "IcArxPackPop.h"

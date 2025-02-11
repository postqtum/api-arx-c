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
***     Description: Declaration of AcDbOleFrame class
***
*****************************************************************************/
#pragma once

#include "../dbframe.h"

#include "IcArxPackPush.h"

class AcDbOleFrame : public AcDbFrame
{
public:
	ACDB_DECLARE_MEMBERS(AcDbOleFrame);

	AcDbOleFrame();
	~AcDbOleFrame();

	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* filer) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* filer) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* filer) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* filer) const override;
	virtual void* getOleObject() const;
	virtual void setOleObject(const void* pItem);
};

#include "IcArxPackPop.h"

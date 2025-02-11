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
***     Description: Declaration of AcDbXObject class
***
*****************************************************************************/
#pragma once

#include "../adesk.h"
#include "../rxobject.h"

class AcDbAuditInfo;
class AcDbDwgFiler;
class AcDbDxfFiler;

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcDbXObject : public AcRxObject
{
protected:
	AcDbXObject();

public:
	ACRX_DECLARE_MEMBERS(AcDbXObject);

	virtual Acad::ErrorStatus audit(AcDbAuditInfo* pAuditInfo);
	Acad::ErrorStatus dwgIn(AcDbDwgFiler* pFiler);
	virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler);
	Acad::ErrorStatus dwgOut(AcDbDwgFiler* pFiler) const;
	virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const;
	Acad::ErrorStatus dxfIn(AcDbDxfFiler* pFiler);
	virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler);
	Acad::ErrorStatus dxfOut(AcDbDxfFiler* pFiler) const;
	virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const;
};

#include "IcArxPackPop.h"

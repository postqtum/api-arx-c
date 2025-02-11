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
***     Description: Declaration of AcDbObjectContextCollection class
***
*****************************************************************************/
#pragma once

#include "../dbmain.h"
#include "../dbObjContext.h"

class AcDbObjectContextCollectionIterator;

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcDbObjectContextCollection : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcDbObjectContextCollection);

	virtual Acad::ErrorStatus addContext(const AcDbObjectContext* pContext) = 0;
	virtual AcDbObjectContext* currentContext(const AcDbObject* pRequestingObject) const = 0;
	virtual AcDbObjectContext* getContext(const AcString& contextName) const = 0;
	virtual bool hasContext(const AcString& contextName) const = 0;
	virtual Acad::ErrorStatus lockContext(const AcDbObjectContext* pContext) = 0;
	virtual bool locked() const = 0;
	virtual AcString name() const = 0;
	virtual AcDbObjectContextCollectionIterator* newIterator() const = 0;
	virtual Acad::ErrorStatus removeContext(const AcString& contextName) = 0;
	virtual Acad::ErrorStatus setCurrentContext(const AcDbObjectContext* pContext) = 0;
	virtual Acad::ErrorStatus unlockContext() = 0;
};

#include "IcArxPackPop.h"

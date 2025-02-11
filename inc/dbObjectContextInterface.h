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
***     Description: Declaration of AcDbObjectContextInterface class
***
*****************************************************************************/
#pragma once

#include "acdb.h"
#include "dbmain.h"

class AcDbObjectContext;

const ACDBCORE2D_PORT AcString& acdbAnnotationScaleCollectionName();

#include "icarx/IcArxPackPush.h"

class AcDbObjectContextInterface : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcDbObjectContextInterface);

	virtual Acad::ErrorStatus addContext(AcDbObject* pObject,
										 const AcDbObjectContext& context) const = 0;
	virtual bool hasContext(const AcDbObject* pObject, const AcDbObjectContext& context) const = 0;
	virtual Acad::ErrorStatus removeContext(AcDbObject* pObject,
											const AcDbObjectContext& context) const = 0;
	virtual bool supportsCollection(const AcDbObject* pObject,
									const AcString& collectionName) const = 0;
};

#include "icarx/IcArxPackPop.h"

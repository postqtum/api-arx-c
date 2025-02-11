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
***     Description:
***
*****************************************************************************/
#pragma once

#include "icarx/AcDbSymbolUtilities.h"

#include "dbsymtb.h"

namespace AcDbSymUtil = AcDbSymbolUtilities;

ACDBCORE2D_PORT Acad::ErrorStatus getTableStyleNameFromDbById(const AcDbObjectId& objId,
															  AcString& sName);

inline Acad::ErrorStatus getTableStyleNameFromDbById(const AcDbObjectId& objId, ACHAR*& pName)
{
	AcString sName;
	return ::acutAcStringToAChar(sName, pName, ::getTableStyleNameFromDbById(objId, sName));
}

using AcDbSymUtilServices = AcDbSymbolUtilities::Services;

inline const AcDbSymUtilServices* acdbSymUtil()
{
	return AcDbSymbolUtilities::servicesPtr();
}

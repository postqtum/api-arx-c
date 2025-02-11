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

#include "icarx/AcDbGeoData.h"
#include "icarx/AcDbGeoDataReactor.h"

ACDBCORE2D_PORT Acad::ErrorStatus acdbGetGeoDataObjId(AcDbDatabase* pDb, AcDbObjectId& objId);
ACDBCORE2D_PORT Acad::ErrorStatus acdbGetGeoDataTransform(AcDbDatabase* pDbSource,
														  AcDbDatabase* pDbTarget,
														  AcGePoint3d& insertionPt,
														  double& rotation, double& scale);
ACDBCORE2D_PORT Acad::ErrorStatus acdbRegisterGeoDataReactor(AcDbGeoDataReactor* reactor);
ACDBCORE2D_PORT void acdbRemoveGeoDataReactor(AcDbGeoDataReactor* reactor);

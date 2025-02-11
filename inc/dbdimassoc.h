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

#include "icarx/AcDbAnnoAlertDisabler.h"
#include "icarx/AcDbDimAssoc.h"

ACDBCORE2D_PORT bool acdbDisableAssociativityAlertIcon(AcDbEntity* pEnt, bool disable);
ACDBCORE2D_PORT Acad::ErrorStatus acdbGetAssocAnnotationActionBody(const AcDbObjectId& idDim,
																   AcDbObjectId& idActionBody);
ACDBCORE2D_PORT bool acdbGetAssociativityOverride(AcDbEntity* pEnt, int& nValue);
Acad::ErrorStatus acdbGetDimAssocId(AcDbObjectId dimId, AcDbObjectId& dimAssocId);
Acad::ErrorStatus acdbGetDimAssocIds(AcDbObjectId entId, AcDbObjectIdArray& dimAssocIds);
ACDBCORE2D_PORT Acad::ErrorStatus acdbGetNonAssocAnnotations(AcDbDatabase* pDb, bool isPaperSpace,
															 AcDbObjectId& blockId,
															 AcDbObjectIdArray& annoIds,
															 bool ignoreOffOrFrozenLayers = false);
ACDBCORE2D_PORT bool acdbIsAnnoMonitorOn();
ACDBCORE2D_PORT bool acdbIsAssociativeAnnotation(AcDbObject* pObj, bool* pIsPartialAssoc = nullptr);
ACDBCORE2D_PORT bool acdbIsAssociativityAlertIconDisabled(AcDbEntity* pEnt);
ACDBCORE2D_PORT bool acdbIsEntityInBlockOrXref(const AcDbEntity* pEnt);
bool acdbIsTransSpatial(const AcDbFullSubentPath& idPath);
Acad::ErrorStatus acdbPostDimAssoc(AcDbObjectId dimId, AcDbDimAssoc* pDimAssoc,
								   AcDbObjectId& dimAssocId, bool isActive = true);
ACDBCORE2D_PORT bool acdbSetAssociativityOverride(AcDbEntity* pEnt, int nValue);
Acad::ErrorStatus acdbUpdateAllDimensions(AcDbDatabase* pDb);
Acad::ErrorStatus acdbUpdateDimension(AcDbObjectId dimId);

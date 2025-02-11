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

#include "icarx/AcViewFrustum.h"
#include "icarx/AcPcPoint.h"
#include "icarx/IAcPcDataBuffer.h"
#include "icarx/IAcPcPointProcessor.h"

#include "rxobject.h"
#include "AcString.h"

class IPointCloudFilter;
class AcDbObjectId;
class AcGePoint3d;
class AcDbDatabase;
class AcDbEntity;
class AcDbExtents;

ACDB_PORT Acad::ErrorStatus acdbAttachPointCloudEntity(
		AcDbObjectId& newPointCloudId, const AcString& indexFile, const AcString& sourceFile,
		AcGePoint3d& location, double scale = 1.0, double rotation = 0.0, AcDbDatabase* pDb = nullptr);
ACDB_PORT Acad::ErrorStatus acdbAttachPointCloudExEntity(AcDbObjectId& newPointCloudExId,
														 const AcString& pointCloudFile,
														 AcGePoint3d& location, double scale = 1.0,
														 double rotation = 0.0,
														 AcDbDatabase* pDb = nullptr);
ACDB_PORT Acad::ErrorStatus acdbCreatePointCloudEntity(AcDbEntity*& newPointCloud,
													   const AcString& indexFile,
													   const AcString& sourceFile,
													   AcGePoint3d& location, double scale = 1.0,
													   double rotation = 0.0);
ACDB_PORT Acad::ErrorStatus acdbModifyPointCloudDataView(AcDbEntity* pEnt,
														 IAcPcPointFilter* pFilter);
ACDB_PORT Acad::ErrorStatus acdbProcessPointCloudData(AcDbEntity* pEnt, const AcDbExtents& ext,
													  int levelOfDetail,
													  IAcPcPointProcessor* pCallback);
ACDB_PORT Acad::ErrorStatus acdbProcessPointCloudData(AcDbEntity* pEnt,
													  const AcViewFrustum& frustum,
													  int levelOfDetail,
													  IAcPcPointProcessor* pCallback);
ACDB_PORT Acad::ErrorStatus acdbResetPointCloudDataView(AcDbEntity* pEnt);
ACDB_PORT Acad::ErrorStatus acdbSetPointCloudFilter(AcDbEntity* pEnt, IPointCloudFilter* pFilter);

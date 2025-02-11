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
***     Description: Declaration of AcPointCloudExtractor class
***
*****************************************************************************/
#pragma once

#include "../acdbport.h"
#include "../dbidar.h"
#include "../acadstrc.h"

class AcDbPointCloudEx;
class AcGeVector3d;
class AcGePoint3d;
class ExtractOption;
class AcPointCloudExtractResult;
class IPointCloudExtracProgressCallback;
class AcDbObjectId;
class AcString;
class AcCmColor;

#include "IcArxPackPush.h"

class ACDB_PORT AcPointCloudExtractor
{
public:
	static AcDbObjectIdArray appendLineProfile(const AcPointCloudExtractResult& profile,
											   AcDbObjectId spaceId, AcString layer,
											   AcCmColor color);
	static AcDbObjectIdArray appendPolylineProfile(const AcPointCloudExtractResult& profile,
												   AcDbObjectId spaceId, AcString layer,
												   AcCmColor color, double polylineWidth);
	static Acad::ErrorStatus extract(AcDbPointCloudEx* pointCloud,
									 const AcGeVector3d& planeZDirection,
									 const AcGeVector3d& planeXDirection, AcGePoint3d pointPlane,
									 const ExtractOption& extractOption,
									 AcPointCloudExtractResult& outlineResult,
									 IPointCloudExtracProgressCallback* progress = 0);
};

#include "IcArxPackPop.h"

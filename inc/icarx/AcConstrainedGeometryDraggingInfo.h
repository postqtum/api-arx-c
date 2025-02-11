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
***     Description: Declaration of AcConstrainedGeometryDraggingInfo struct
***
*****************************************************************************/
#pragma once

#include "AcDbAssocTransInfo.h"
#include "AcDbFullSubentPathArray.h"

class AcString;
class AcConstrainedGeometry;

#include "IcArxPackPush.h"

struct AcConstrainedGeometryDraggingInfo : public AcDbAssocTransInfo
{
	AcDbFullSubentPathArray maGeomFullSubentPaths;
	AcArray<AcConstrainedGeometry*> maDraggingGeometries;

	ACDBCORE2D_PORT static const AcString& getKey();
};

#include "IcArxPackPop.h"

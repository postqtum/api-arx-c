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
***     Description: Declaration of AcEdInputPoint class
***
*****************************************************************************/
#pragma once

#include "../acadapidef.h"
#include "../acarray.h"
#include "../dbidar.h"
#include "AcDbObjectId.h"
#include "AcDbEnumOsnap.h"

class AcEdImpInputPointManager;
class AcDbCustomOsnapMode;
class AcApDocument;
class AcGiViewportDraw;
class AcGePoint3d;
class AcGeCurve3d;

#include "IcArxPackPush.h"

class AcEdInputPoint
{
	friend class AcEdImpInputPointManager;

private:
	AcEdImpInputPointManager* m_pImpMgr = nullptr;

private:
	AcEdInputPoint(AcEdImpInputPointManager* pImpMgr);
	AcEdInputPoint& operator=(const AcEdInputPoint&);

public:
	ACAD_PORT const AcArray<AcGeCurve3d*>& alignmentPaths() const;
	ACAD_PORT const AcGePoint3d& cartesianSnappedPoint() const;
	ACAD_PORT const AcGePoint3d& computedPoint() const;
	ACAD_PORT const AcArray<AcDbCustomOsnapMode*>& customOsnapModes() const;
	ACAD_PORT const AcArray<AcDbCustomOsnapMode*>& customOsnapOverrides() const;
	ACAD_PORT AcApDocument* document() const;
	ACAD_PORT AcGiViewportDraw* drawContext() const;
	ACAD_PORT const AcGePoint3d& grippedPoint() const;
	ACAD_PORT const AcArray<IcArx::Integers::GsMarker>& gsSelectionMark() const;
	ACAD_PORT int history() const;
	ACAD_PORT const AcArray<AcDbObjectId>& keyPointEntities() const;
	ACAD_PORT const AcArray<IcArx::Integers::GsMarker>& keyPointGsSelectionMark() const;
	ACAD_PORT const AcGePoint3d& lastPoint() const;
	ACAD_PORT const AcArray<AcDbObjectIdArray, AcArrayObjectCopyReallocator<AcDbObjectIdArray> >&
	nestedKeyPointEntities() const;
	ACAD_PORT const AcArray<AcDbObjectIdArray, AcArrayObjectCopyReallocator<AcDbObjectIdArray> >&
	nestedPickedEntities() const;
	ACAD_PORT const AcDb::OsnapMask osnapMask() const;
	ACAD_PORT const AcDb::OsnapMask osnapOverrides() const;
	ACAD_PORT const AcGePoint3d& osnappedPoint() const;
	ACAD_PORT const AcArray<AcDbObjectId>& pickedEntities() const;
	ACAD_PORT bool pointComputed() const;
	ACAD_PORT const AcGePoint3d& rawPoint() const;
	ACAD_PORT const ACHAR* tooltipString() const;
};

#include "IcArxPackPop.h"

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
***     Description: Declaration of AcEdInputPointMonitor class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../acadapidef.h"
#include "../acarray.h"
#include "../dbidar.h"
#include "AcEdDSPoint.h"
#include "AcDbObjectId.h"
#include "AcDbEnumOsnap.h"

class AcGePoint3d;
class AcGiViewportDraw;
class AcApDocument;
class AcDbCustomOsnapMode;
class AcGeCurve3d;
class AcEdInputPoint;
class AcEdInputPointMonitorResult;

#include "IcArxPackPush.h"

class AcEdInputPointMonitor : public AcRxObject
{
private:
	AcEdDSPoint m_lastPoint{0, 0};

public:
	ACRX_DECLARE_MEMBERS(AcEdInputPointMonitor);

	ACAD_PORT virtual ~AcEdInputPointMonitor();

	virtual bool excludeFromOsnapCalculation(const AcArray<AcDbObjectId>& /*nestedEntity*/,
											 IcArx::Integers::GsMarker /*gsSelectionMark*/)
	{
		return false;
	}
	virtual Acad::ErrorStatus monitorInputPoint(const AcEdInputPoint& /*input*/,
												AcEdInputPointMonitorResult& /*output*/)
	{
		return Acad::eOk;
	}
	virtual Acad::ErrorStatus monitorInputPoint(
			bool&, ACHAR*&, AcGiViewportDraw*, AcApDocument*, bool, int, const AcGePoint3d&,
			const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&,
			AcDb::OsnapMask, const AcArray<AcDbCustomOsnapMode*>&, AcDb::OsnapMask,
			const AcArray<AcDbCustomOsnapMode*>&, const AcArray<AcDbObjectId>&,
			const AcArray<AcDbObjectIdArray, AcArrayObjectCopyReallocator<AcDbObjectIdArray> >&,
			const AcArray<IcArx::Integers::GsMarker>&, const AcArray<AcDbObjectId>&,
			const AcArray<AcDbObjectIdArray, AcArrayObjectCopyReallocator<AcDbObjectIdArray> >&,
			const AcArray<IcArx::Integers::GsMarker>&, const AcArray<AcGeCurve3d*>&,
			const AcGePoint3d&, const ACHAR*)
	{
		return Acad::eOk;
	}
	virtual bool mouseHasMoved();
};

#include "IcArxPackPop.h"

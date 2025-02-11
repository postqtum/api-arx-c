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
***     Description: Declaration of AcEdInputPointFilter class
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
class AcEdInputPointFilterResult;

#include "IcArxPackPush.h"

class AcEdInputPointFilter : public AcRxObject
{
private:
	AcEdDSPoint m_lastPoint{0, 0};

public:
	ACRX_DECLARE_MEMBERS(AcEdInputPointFilter);

	ACAD_PORT virtual ~AcEdInputPointFilter();

	virtual bool mouseHasMoved();
	virtual Acad::ErrorStatus processInputPoint(const AcEdInputPoint& /*input*/,
												AcEdInputPointFilterResult& /*output*/)
	{
		return Acad::eOk;
	}
	virtual Acad::ErrorStatus processInputPoint(
			bool&, AcGePoint3d&, bool&, bool&, ACHAR*&, bool&, AcGiViewportDraw*, AcApDocument*,
			bool, int, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&,
			const AcGePoint3d&, const AcGePoint3d&, AcDb::OsnapMask,
			const AcArray<AcDbCustomOsnapMode*>&, AcDb::OsnapMask,
			const AcArray<AcDbCustomOsnapMode*>&, const AcArray<AcDbObjectId>&,
			const AcArray<AcDbObjectIdArray, AcArrayObjectCopyReallocator<AcDbObjectIdArray>>&,
			const AcArray<IcArx::Integers::GsMarker>&, const AcArray<AcDbObjectId>&,
			const AcArray<AcDbObjectIdArray, AcArrayObjectCopyReallocator<AcDbObjectIdArray>>&,
			const AcArray<IcArx::Integers::GsMarker>&, const AcArray<AcGeCurve3d*>&,
			const AcGePoint3d&, const ACHAR*)
	{
		return Acad::eOk;
	}
	virtual AcEdInputPointFilter* revokeInputFilter(AcEdInputPointFilter* /*revokedFilter*/)
	{
		return this;
	}
};

#include "IcArxPackPop.h"

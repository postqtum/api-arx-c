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

#include "dbfilter.h"
#include "gepnt2d.h"
#include "gevec2d.h"
#include "gept2dar.h"

#define ACDB_INFINITE_XCLIP_DEPTH (1.0e+300)

class AcDbExtents;
class AcDbBlockReference;

#include "icarx/IcArxPackPush.h"

class AcDbSpatialFilter : public AcDbFilter
{
public:
	ACDB_DECLARE_MEMBERS(AcDbSpatialFilter);

	AcDbSpatialFilter();
	ACDBCORE2D_PORT AcDbSpatialFilter(const AcGePoint2dArray& pts, const AcGeVector3d& normal, double elevation,
					  double frontClip, double backClip, bool enabled);
	~AcDbSpatialFilter();

	bool clipVolumeIntersectsExtents(const AcDbExtents& ext) const;
	AcGeMatrix3d& getClipSpaceToWCSMatrix(AcGeMatrix3d& mat) const;
	Acad::ErrorStatus getDefinition(AcGePoint2dArray& pts, AcGeVector3d& normal, double& elevation,
									double& frontClip, double& backClip,
									bool& enabled) const;
	AcGeMatrix3d& getOriginalInverseBlockXform(AcGeMatrix3d& mat) const;
	Acad::ErrorStatus getVolume(AcGePoint3d& fromPt, AcGePoint3d& toPt, AcGeVector3d& upDir,
								AcGeVector2d& viewField) const;
	bool hasPerspectiveCamera() const;
	AcRxClass* indexClass() const override;
	ACDBCORE2D_PORT bool isInverted() const;
	virtual void queryBounds(AcDbExtents& ext, const AcDbBlockReference* pRefBlkRef) const;
	void queryBounds(AcDbExtents& ext) const;
	Acad::ErrorStatus setDefinition(const AcGePoint2dArray& pts, const AcGeVector3d& normal,
									double elevation, double frontClip, double backClip,
									bool enabled);
	ACDBCORE2D_PORT Acad::ErrorStatus setInverted(bool bInverted);
	Acad::ErrorStatus setPerspectiveCamera(const AcGePoint3d& fromPt);
};

#include "icarx/IcArxPackPop.h"

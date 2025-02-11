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
***     Description: Declaration of AcDbAbstractViewTableRecord class
***
*****************************************************************************/
#pragma once

#include "AcDbSymbolTableRecord.h"
#include "AcGiViewportTraits.h"

#include "../gepnt2d.h"
#include "../gepnt3d.h"

class AcDbViewTable;

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcDbAbstractViewTableRecord : public AcDbSymbolTableRecord
{
public:
	ACDB_DECLARE_MEMBERS(AcDbAbstractViewTableRecord);

	AcDbAbstractViewTableRecord();
	~AcDbAbstractViewTableRecord();

	AcCmColor ambientLightColor() const;
	double backClipDistance() const;
	bool backClipEnabled() const;
	const AcDbObjectId& background() const;
	AcDbObjectId& background();
	double brightness() const;
	AcGePoint2d centerPoint() const;
	double contrast() const;
	AcGiViewportTraits::DefaultLightingType defaultLightingType() const;
	double elevation() const;
	bool frontClipAtEye() const;
	double frontClipDistance() const;
	bool frontClipEnabled() const;
	Acad::ErrorStatus getUcs(AcGePoint3d& origin, AcGeVector3d& xAxis, AcGeVector3d& yAxis) const;
	double height() const;
	bool isDefaultLightingOn() const;
	bool isUcsOrthographic(AcDb::OrthographicView& view) const;
	bool isViewOrthographic(AcDb::OrthographicView& view) const;
	double lensLength() const;
	bool perspectiveEnabled() const;
	Acad::ErrorStatus setAmbientLightColor(const AcCmColor& clr);
	void setBackClipDistance(double distance);
	void setBackClipEnabled(bool enabled);
	Acad::ErrorStatus setBackground(const AcDbObjectId& backgroundId);
	Acad::ErrorStatus setBrightness(double);
	void setCenterPoint(const AcGePoint2d&);
	Acad::ErrorStatus setContrast(double);
	Acad::ErrorStatus setDefaultLightingOn(bool on);
	Acad::ErrorStatus setDefaultLightingType(AcGiViewportTraits::DefaultLightingType typ);
	Acad::ErrorStatus setElevation(double elev);
	void setFrontClipAtEye(bool atEye);
	void setFrontClipDistance(double distance);
	void setFrontClipEnabled(bool enabled);
	void setHeight(double height);
	void setLensLength(double length);
	void setPerspectiveEnabled(bool enabled);
	Acad::ErrorStatus setSun(AcDbObjectId& retId, AcDbObject* pSun);
	Acad::ErrorStatus setSun(AcDbObjectId& retId, AcDbObject* pSun, bool eraseOldSun);
	void setTarget(const AcGePoint3d& target);
	Acad::ErrorStatus setToneOperatorParameters(const AcGiToneOperatorParameters& params);
	Acad::ErrorStatus setUcs(const AcGePoint3d& origin, const AcGeVector3d& xAxis,
							 const AcGeVector3d& yAxis);
	Acad::ErrorStatus setUcs(AcDb::OrthographicView view);
	Acad::ErrorStatus setUcs(const AcDbObjectId& ucsId);
	Acad::ErrorStatus setUcsToWorld();
	void setViewDirection(const AcGeVector3d& viewDirection);
	Acad::ErrorStatus setViewDirection(AcDb::OrthographicView view);
	void setViewTwist(double angle);
	Acad::ErrorStatus setVisualStyle(const AcDbObjectId& visualStyleId);
	void setWidth(double width);
	AcDbObjectId sunId() const;
	AcGePoint3d target() const;
	Acad::ErrorStatus toneOperatorParameters(AcGiToneOperatorParameters& params) const;
	AcDbObjectId ucsName() const;
	AcGeVector3d viewDirection() const;
	double viewTwist() const;
	AcDbObjectId visualStyle() const;
	double width() const;
};

#include "IcArxPackPop.h"

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
***     Description: Declaration of AcDbGeoPositionMarker class
***
*****************************************************************************/
#pragma once

#include "acdbport.h"
#include "dbmain.h"
#include "rxboiler.h"
#include "gepnt3d.h"
#include "gevec3d.h"
#include "AcString.h"

class AcDbMText;

#include "icarx/IcArxPackPush.h"

class ACDBCORE2D_PORT AcDbGeoPositionMarker : public AcDbEntity
{
public:
	enum TextAlignmentType
	{
		kLeftAlignment = 0,
		kCenterAlignment = 1,
		kRightAlignment = 2
	};

protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACRX_DECLARE_MEMBERS(AcDbGeoPositionMarker);

	AcDbGeoPositionMarker();
	AcDbGeoPositionMarker(const AcGePoint3d& position, double radius, double landingGap);

	bool enableFrameText() const;
	AcGePoint3d geoPosition() const;
	double landingGap() const;
	Acad::ErrorStatus latLonAlt(double& lat, double& lon, double& alt) const;
	AcDbMText* mtext() const;
	bool mtextVisible() const;
	AcGeVector3d normal() const;
	AcString notes() const;
	AcGePoint3d position() const;
	double radius() const;
	Acad::ErrorStatus setEnableFrameText(bool enableFrameText);
	Acad::ErrorStatus setGeoPosition(const AcGePoint3d& position);
	Acad::ErrorStatus setLandingGap(double landingGap);
	Acad::ErrorStatus setLatLonAlt(double lat, double lon, double alt);
	Acad::ErrorStatus setMText(const AcDbMText* pMText);
	Acad::ErrorStatus setMTextVisible(bool visible);
	Acad::ErrorStatus setNotes(const AcString& notes);
	Acad::ErrorStatus setPosition(const AcGePoint3d& position);
	Acad::ErrorStatus setRadius(double radius);
	Acad::ErrorStatus setText(const AcString& text);
	Acad::ErrorStatus setTextAlignmentType(
			AcDbGeoPositionMarker::TextAlignmentType textAlignmentType);
	AcString text() const;
	AcDbGeoPositionMarker::TextAlignmentType textAlignmentType() const;
	AcDbObjectId textStyle() const;
};

#include "icarx/IcArxPackPop.h"

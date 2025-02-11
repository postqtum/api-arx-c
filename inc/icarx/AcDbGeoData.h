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
***     Description: Declaration of AcDbGeoData class
***
*****************************************************************************/
#pragma once

#include "../gept2dar.h"
#include "../gepnt3d.h"
#include "../AcDbCore2dDefs.h"

#include "AcDbObject.h"

#include "IcArxPackPush.h"

class AcDbGeoData : public AcDbObject
{
public:
	enum ScaleEstimationMethod
	{
		kScaleEstMethodUnity = 1,
		kScaleEstMethodUserDefined,
		kScaleEstMethodReferencePoint,
		kScaleEstMethodPrismoidal
	};

	enum TypeOfCoordinates
	{
		kCoordTypUnknown = 0,
		kCoordTypLocal,
		kCoordTypGrid,
		kCoordTypGeographic
	};

	typedef Acad::ErrorStatus (*ACDBGEODATA_DWGTOGEOGRAPHIC)(
			const AcDbGeoData* pGeoData, const double& dblDwgX, const double& dblDwgY,
			const double& dblDwgZ, double& dblLongitude, double& dblLatitude, double& dblAltitude);
	typedef Acad::ErrorStatus (*ACDBGEODATA_GEOGRAPHICTODWG)(
			const AcDbGeoData* pGeoData, const double& dblLongitude, const double& dblLatitude,
			const double& dblAltitude, double& dblDwgX, double& dblDwgY, double& dblDwgZ);
	typedef bool (*ACDBGEODATA_VALIDATE_CS)(const ACHAR* coordinateSystem);

public:
	ACDBCORE2D_DECLARE_MEMBERS(AcDbGeoData);

	ACDBCORE2D_PORT AcDbGeoData();
	ACDBCORE2D_PORT ~AcDbGeoData();

	ACDBCORE2D_PORT Acad::ErrorStatus addMeshFace(int faceIndex, int p0, int p1, int p2);
	ACDBCORE2D_PORT Acad::ErrorStatus addMeshPointMap(int index, const AcGePoint2d& sourcePt,
													  const AcGePoint2d& destPt);
	ACDBCORE2D_PORT AcDbObjectId blockTableRecordId() const;
	ACDBCORE2D_PORT double coordinateProjectionRadius() const;
	ACDBCORE2D_PORT const ACHAR* coordinateSystem() const;
	ACDBCORE2D_PORT TypeOfCoordinates coordinateType() const;
	ACDBCORE2D_PORT AcGePoint3d designPoint() const;
	ACDBCORE2D_PORT bool doSeaLevelCorrection() const;
	ACDBCORE2D_PORT Acad::ErrorStatus dwgInFields(AcDbDwgFiler*) override;
	ACDBCORE2D_PORT Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const override;
	ACDBCORE2D_PORT Acad::ErrorStatus dxfInFields(AcDbDxfFiler*) override;
	ACDBCORE2D_PORT Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const override;
	ACDBCORE2D_PORT Acad::ErrorStatus eraseFromDb(void);
	ACDBCORE2D_PORT const ACHAR* geoRSSTag() const;
	ACDBCORE2D_PORT Acad::ErrorStatus getMeshFace(int faceIndex, int& p0, int& p1, int& p2) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getMeshPointMap(int index, AcGePoint2d& sourcePt,
													  AcGePoint2d& destPt) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getMeshPointMaps(AcGePoint2dArray& sourcePts,
													   AcGePoint2dArray& destPts) const;
	static ACDBCORE2D_PORT const ACHAR* getTransformCallbacks(
			ACDBGEODATA_GEOGRAPHICTODWG& pFuncGeoToDwg, ACDBGEODATA_DWGTOGEOGRAPHIC& pFuncDwgToGeo);
	static ACDBCORE2D_PORT ACDBGEODATA_VALIDATE_CS getValidateCoordinateSystemCallback();
	ACDBCORE2D_PORT double horizontalUnitScale() const;
	ACDBCORE2D_PORT AcDb::UnitsValue horizontalUnits() const;
	ACDBCORE2D_PORT double northDirection() const;
	ACDBCORE2D_PORT AcGeVector2d northDirectionVector() const;
	ACDBCORE2D_PORT int numMeshFaces() const;
	ACDBCORE2D_PORT int numMeshPoints() const;
	ACDBCORE2D_PORT const ACHAR* observationCoverage() const;
	ACDBCORE2D_PORT const ACHAR* observationFrom() const;
	ACDBCORE2D_PORT const ACHAR* observationTo() const;
	ACDBCORE2D_PORT Acad::ErrorStatus postToDb(AcDbObjectId& objId);
	ACDBCORE2D_PORT AcGePoint3d referencePoint() const;
	ACDBCORE2D_PORT Acad::ErrorStatus resetMeshPointMaps();
	ACDBCORE2D_PORT ScaleEstimationMethod scaleEstimationMethod() const;
	ACDBCORE2D_PORT double scaleFactor() const;
	ACDBCORE2D_PORT double seaLevelElevation() const;
	ACDBCORE2D_PORT Acad::ErrorStatus setBlockTableRecordId(const AcDbObjectId& blockId);
	ACDBCORE2D_PORT Acad::ErrorStatus setCoordinateProjectionRadius(double value);
	ACDBCORE2D_PORT Acad::ErrorStatus setCoordinateSystem(const ACHAR* coordinateSystem);
	ACDBCORE2D_PORT Acad::ErrorStatus setCoordinateType(TypeOfCoordinates designCoordinateType);
	ACDBCORE2D_PORT Acad::ErrorStatus setDesignPoint(const AcGePoint3d& point);
	ACDBCORE2D_PORT Acad::ErrorStatus setDoSeaLevelCorrection(bool seaLevelCorrectionOn);
	ACDBCORE2D_PORT Acad::ErrorStatus setGeoRSSTag(const ACHAR* rssTag);
	ACDBCORE2D_PORT Acad::ErrorStatus setHorizontalUnitScale(double horzUnitScale);
	ACDBCORE2D_PORT Acad::ErrorStatus setHorizontalUnits(AcDb::UnitsValue horizUnits);
	ACDBCORE2D_PORT Acad::ErrorStatus setMeshPointMaps(const AcGePoint2dArray& sourcePts,
													   const AcGePoint2dArray& destPts);
	ACDBCORE2D_PORT Acad::ErrorStatus setNorthDirectionVector(const AcGeVector2d& north);
	ACDBCORE2D_PORT Acad::ErrorStatus setObservationCoverage(const ACHAR* coverage);
	ACDBCORE2D_PORT Acad::ErrorStatus setObservationFrom(const ACHAR* from);
	ACDBCORE2D_PORT Acad::ErrorStatus setObservationTo(const ACHAR* to);
	ACDBCORE2D_PORT Acad::ErrorStatus setReferencePoint(const AcGePoint3d& point);
	ACDBCORE2D_PORT Acad::ErrorStatus setScaleEstimationMethod(ScaleEstimationMethod value);
	ACDBCORE2D_PORT Acad::ErrorStatus setScaleFactor(double value);
	ACDBCORE2D_PORT Acad::ErrorStatus setSeaLevelElevation(double value);
	static ACDBCORE2D_PORT Acad::ErrorStatus setTransformCallbacks(
			const ACHAR* zoneDescription, ACDBGEODATA_GEOGRAPHICTODWG pFuncGeoToDwg,
			ACDBGEODATA_DWGTOGEOGRAPHIC pFuncDwgToGeo);
	ACDBCORE2D_PORT Acad::ErrorStatus setUpDirection(const AcGeVector3d& vec);
	static ACDBCORE2D_PORT Acad::ErrorStatus setValidateCoordinateSystemCallback(
			ACDBGEODATA_VALIDATE_CS pFuncValidateCs);
	ACDBCORE2D_PORT Acad::ErrorStatus setVerticalUnitScale(double vertUnitScale);
	ACDBCORE2D_PORT Acad::ErrorStatus setVerticalUnits(AcDb::UnitsValue vertUnits);
	ACDBCORE2D_PORT Acad::ErrorStatus transformFromLonLatAlt(const AcGePoint3d& geoPt,
															 AcGePoint3d& dwgPt) const;
	ACDBCORE2D_PORT Acad::ErrorStatus transformFromLonLatAlt(double lon, double lat, double alt,
															 double& x, double& y, double& z) const;
	ACDBCORE2D_PORT Acad::ErrorStatus transformToLonLatAlt(const AcGePoint3d& dwgPt,
														   AcGePoint3d& geoPt) const;
	ACDBCORE2D_PORT Acad::ErrorStatus transformToLonLatAlt(double x, double y, double z,
														   double& lon, double& lat,
														   double& alt) const;
	ACDBCORE2D_PORT AcGeVector3d upDirection() const;
	ACDBCORE2D_PORT Acad::ErrorStatus updateTransformationMatrix();
	ACDBCORE2D_PORT double verticalUnitScale() const;
	ACDBCORE2D_PORT AcDb::UnitsValue verticalUnits() const;
};

#include "IcArxPackPop.h"

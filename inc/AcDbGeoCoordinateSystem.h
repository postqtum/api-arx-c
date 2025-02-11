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

#include "acdb.h"
#include "AcDbCore2dDefs.h"
#include "AcString.h"
#include "gept3dar.h"
#include "acadstrc.h"

#include "icarx/AcDbExtents2d.h"

class AcDbGeoCoordinateSystem;

#include "icarx/IcArxPackPush.h"

struct AcDbGeoDatum
{
	AcString id;
	AcString desc;
};

struct AcDbGeoEllipsoid
{
	AcString id;
	AcString desc;
	double polarRadius;
	double eccentricity;
};

struct AcDbGeoProjectionParameter
{
	AcString name;
	double value;
};

class AcDbGeoCoordinateSystemCategory
{
public:
	virtual ~AcDbGeoCoordinateSystemCategory() = default;

	ACDBCORE2D_PORT static Acad::ErrorStatus createAll(
			AcArray<AcDbGeoCoordinateSystemCategory*>& allCategories);
	virtual Acad::ErrorStatus getCoordinateSystemAt(int index,
													AcDbGeoCoordinateSystem*& pCoordSys) const = 0;
	virtual Acad::ErrorStatus getId(AcString& categoryId) const = 0;
	virtual Acad::ErrorStatus getNumOfCoordinateSystem(int& num) const = 0;
};

class AcDbGeoCoordinateSystem
{
public:
	enum ProjectionCode
	{
		kProjectionCodeUnknown = 0,
		kProjectionCodeAlber = 4,
		kProjectionCodeAzede = 59,
		kProjectionCodeAzmea = 11,
		kProjectionCodeAzmed = 7,
		kProjectionCodeBipolar = 31,
		kProjectionCodeBonne = 24,
		kProjectionCodeCassini = 22,
		kProjectionCodeEckert4 = 25,
		kProjectionCodeEckert6 = 26,
		kProjectionCodeEdcnc = 12,
		kProjectionCodeEdcyl = 20,
		kProjectionCodeGaussK = 46,
		kProjectionCodeGnomonic = 19,
		kProjectionCodeGoode = 28,
		kProjectionCodeHom1uv = 1281,
		kProjectionCodeHom1xy = 1282,
		kProjectionCodeHom2uv = 1283,
		kProjectionCodeHom2xy = 1284,
		kProjectionCodeKrovak = 47,
		kProjectionCodeKrvk95 = 51,
		kProjectionCodeLL = 1,
		kProjectionCodeLm1sp = 36,
		kProjectionCodeLm2sp = 37,
		kProjectionCodeLmblg = 38,
		kProjectionCodeLmtan = 8,
		kProjectionCodeMiller = 13,
		kProjectionCodeMndotl = 41,
		kProjectionCodeMndott = 42,
		kProjectionCodeModpc = 10,
		kProjectionCodeMollweid = 27,
		kProjectionCodeMrcat = 6,
		kProjectionCodeMrcatK = 49,
		kProjectionCodeMstero = 15,
		kProjectionCodeNeacyl = 29,
		kProjectionCodeNerth = 55,
		kProjectionCodeNzealand = 16,
		kProjectionCodeOblqM = 5,
		kProjectionCodeObqcyl = 56,
		kProjectionCodeOrtho = 18,
		kProjectionCodeOstn02 = 60,
		kProjectionCodeOstn97 = 58,
		kProjectionCodeOstro = 34,
		kProjectionCodePlycn = 9,
		kProjectionCodePstro = 33,
		kProjectionCodePstrosl = 53,
		kProjectionCodeRskew = 1285,
		kProjectionCodeRskewc = 1286,
		kProjectionCodeRskewo = 1287,
		kProjectionCodeRobinson = 23,
		kProjectionCodeSinus = 17,
		kProjectionCodeSotrm = 43,
		kProjectionCodeSstro = 35,
		kProjectionCodeSwiss = 32,
		kProjectionCodeSys34 = 57,
		kProjectionCodeSys34_99 = 61,
		kProjectionCodeTeacyl = 30,
		kProjectionCodeTm = 3,
		kProjectionCodeTrmeraf = 54,
		kProjectionCodeTrmrkrg = 62,
		kProjectionCodeTrmrs = 45,
		kProjectionCodeVdgrntn = 21,
		kProjectionCodeWccsl = 39,
		kProjectionCodeWccst = 40,
		kProjectionCodeUtm = 44,
		kProjectionCodeWinkl = 63,
		kProjectionCodeNrthsrt = 64,
		kProjectionCodeLmbrtaf = 65,
		kProjectionCodeSys34_01 = 66,
		kProjectionCodeEdcylE = 67,
		kProjectionCodePlateCarree = 68,
		kProjectionCodePvMercator = 69,
	};

	enum Type
	{
		kTypeUnknown = 0,
		kTypeArbitrary = 1,
		kTypeGeographic = 2,
		kTypeProjected = 3
	};

	enum Unit
	{
		kUnitUnknown = 0,
		kUnitMeter = 1,
		kUnitFoot = 2,
		kUnitInch = 3,
		kUnitIFoot = 4,
		kUnitClarkeFoot = 5,
		kUnitIInch = 6,
		kUnitCentimeter = 7,
		kUnitKilometer = 8,
		kUnitYard = 9,
		kUnitSearsYard = 10,
		kUnitMile = 11,
		kUnitIYard = 12,
		kUnitIMile = 13,
		kUnitKnot = 14,
		kUnitNautM = 15,
		kUnitLat66 = 16,
		kUnitLat83 = 17,
		kUnitDecimeter = 18,
		kUnitMillimeter = 19,
		kUnitDekameter = 20,
		kUnitHectometer = 21,
		kUnitGermanMeter = 22,
		kUnitCaGrid = 23,
		kUnitClarkeChain = 24,
		kUnitGunterChain = 25,
		kUnitBenoitChain = 26,
		kUnitSearsChain = 27,
		kUnitClarkeLink = 28,
		kUnitGunterLink = 29,
		kUnitBenoitLink = 30,
		kUnitSearsLink = 31,
		kUnitRod = 32,
		kUnitPerch = 33,
		kUnitPole = 34,
		kUnitFurlong = 35,
		kUnitRood = 36,
		kUnitCapeFoot = 37,
		kUnitBrealey = 38,
		kUnitSearsFoot = 39,
		kUnitGoldCoastFoot = 40,
		kUnitMicroInch = 41,
		kUnitIndianYard = 42,
		kUnitIndianFoot = 43,
		kUnitIndianFt37 = 44,
		kUnitIndianFt62 = 45,
		kUnitIndianFt75 = 46,
		kUnitIndianYd37 = 47,
		kUnitDecameter = 48,
		kUnitInternationalChain = 49,
		kUnitInternationalLink = 50,
		kUnitDegree = 1001,
		kUnitGrad = 1002,
		kUnitGrade = 1003,
		kUnitMapInfo = 1004,
		kUnitMil = 1005,
		kUnitMinute = 1006,
		kUnitRadian = 1007,
		kUnitSecond = 1008,
		kUnitDecisec = 1009,
		kUnitCentisec = 1010,
		kUnitMillisec = 1011,
	};

public:
	virtual ~AcDbGeoCoordinateSystem() = default;

	ACDBCORE2D_PORT static Acad::ErrorStatus create(const AcString& coordSysIdOrFullDef,
													AcDbGeoCoordinateSystem*& pCoordSys);
	ACDBCORE2D_PORT static Acad::ErrorStatus createAll(
			const AcGePoint3d& geoPt, AcArray<AcDbGeoCoordinateSystem*>& allCoordSys);
	ACDBCORE2D_PORT static Acad::ErrorStatus createAll(
			AcArray<AcDbGeoCoordinateSystem*>& allCoordSys,
			const AcDbGeoCoordinateSystemCategory* pCategory = nullptr);
	virtual Acad::ErrorStatus getCartesianExtents(AcDbExtents2d& exts) const = 0;
	virtual Acad::ErrorStatus getDatum(AcDbGeoDatum& datum) const = 0;
	virtual Acad::ErrorStatus getDescription(AcString& coordSysDesc) const = 0;
	virtual Acad::ErrorStatus getEllipsoid(AcDbGeoEllipsoid& ellipsoid) const = 0;
	virtual Acad::ErrorStatus getEpsgCode(int& epsgCode) const = 0;
	virtual Acad::ErrorStatus getGeodeticExtents(AcDbExtents2d& exts) const = 0;
	virtual Acad::ErrorStatus getId(AcString& coordSysId) const = 0;
	virtual Acad::ErrorStatus getOffset(AcGeVector2d& offsetVec) const = 0;
	virtual Acad::ErrorStatus getProjectionCode(
			AcDbGeoCoordinateSystem::ProjectionCode& prjCode) const = 0;
	virtual Acad::ErrorStatus getProjectionParameters(
			AcArray<AcDbGeoProjectionParameter>& prjParams, bool includeSpecialParams) const = 0;
	virtual Acad::ErrorStatus getType(AcDbGeoCoordinateSystem::Type& type) const = 0;
	virtual Acad::ErrorStatus getUnit(AcDb::UnitsValue& unit) const = 0;
	virtual Acad::ErrorStatus getUnit(AcDbGeoCoordinateSystem::Unit& unit) const = 0;
	virtual Acad::ErrorStatus getUnitScale(double& unitScale) const = 0;
	virtual Acad::ErrorStatus getWktRepresentation(AcString& strWkt) const = 0;
	virtual Acad::ErrorStatus getXmlRepresentation(AcString& strXml) const = 0;
};

class AcDbGeoCoordinateSystemTransformer
{
public:
	virtual ~AcDbGeoCoordinateSystemTransformer() = default;

	ACDBCORE2D_PORT static Acad::ErrorStatus create(
			const AcString& sourceCoordSysId, const AcString& targetCoordSysId,
			AcDbGeoCoordinateSystemTransformer*& pCoordSysTransformer);
	virtual Acad::ErrorStatus getSourceCoordinateSystemId(AcString& sourceCoordSysId) const = 0;
	virtual Acad::ErrorStatus getTargetCoordinateSystemId(AcString& targetCoordSysId) const = 0;
	virtual Acad::ErrorStatus transformPoint(const AcGePoint3d& pointIn,
											 AcGePoint3d& pointOut) const = 0;
	ACDBCORE2D_PORT static Acad::ErrorStatus transformPoint(const AcString& sourceCoordSysId,
															const AcString& targetCoordSysId,
															const AcGePoint3d& pointIn,
															AcGePoint3d& pointOut);
	virtual Acad::ErrorStatus transformPoints(const AcGePoint3dArray& pointsIn,
											  AcGePoint3dArray& pointsOut) const = 0;
	ACDBCORE2D_PORT static Acad::ErrorStatus transformPoints(const AcString& sourceCoordSysId,
															 const AcString& targetCoordSysId,
															 const AcGePoint3dArray& pointsIn,
															 AcGePoint3dArray& pointsOut);
};

#include "icarx/IcArxPackPop.h"

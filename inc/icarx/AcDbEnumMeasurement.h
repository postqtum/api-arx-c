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
***     Description: Declaration of AcDbEnumMeasurement
***
*****************************************************************************/
#pragma once

#include "AcDb.h"

enum AcDb::MeasurementValue
{
	kEnglish = 0,
	kMetric = 1,
};

enum AcDb::UnitsValue
{
	kUnitsUndefined = 0,
	kUnitsInches = 1,
	kUnitsFeet = 2,
	kUnitsMiles = 3,
	kUnitsMillimeters = 4,
	kUnitsCentimeters = 5,
	kUnitsMeters = 6,
	kUnitsKilometers = 7,
	kUnitsMicroinches = 8,
	kUnitsMils = 9,
	kUnitsYards = 10,
	kUnitsAngstroms = 11,
	kUnitsNanometers = 12,
	kUnitsMicrons = 13,
	kUnitsDecimeters = 14,
	kUnitsDekameters = 15,
	kUnitsHectometers = 16,
	kUnitsGigameters = 17,
	kUnitsAstronomical = 18,
	kUnitsLightYears = 19,
	kUnitsParsecs = 20,
	kUnitsUSSurveyFeet = 21,
	kUnitsUSSurveyInch = 22,
	kUnitsUSSurveyYard = 23,
	kUnitsUSSurveyMile = 24,
	kUnitsMax = AcDb::UnitsValue::kUnitsUSSurveyMile
};

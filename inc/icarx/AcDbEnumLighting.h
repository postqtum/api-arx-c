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
***     Description: Declaration of AcDbEnumLighting
***
*****************************************************************************/
#pragma once

#include "AcDb.h"

namespace AcDb
{
enum ShadowFlags
{
	kShadowsCastAndReceive = 0x00,
	kShadowsDoesNotReceive = 0x01,
	kShadowsDoesNotCast = 0x02,
	kShadowsIgnore = kShadowsDoesNotCast | kShadowsDoesNotReceive
};

enum LightingUnits
{
	kLightingUnitsGeneric = 0,
	kLightingUnitsAmerican = 1,
	kLightingUnitsInternational = 2
};

}  // namespace AcDb

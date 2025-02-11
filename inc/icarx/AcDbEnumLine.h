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
***     Description: Declaration of AcDbEnumLine
***
*****************************************************************************/
#pragma once

#include "AcDb.h"

enum AcDb::LineSpacingStyle
{
	kAtLeast = 1,
	kExactly = 2
};

enum AcDb::LineWeight
{
	kLnWt000 = 0,
	kLnWt005 = 5,
	kLnWt009 = 9,
	kLnWt013 = 13,
	kLnWt015 = 15,
	kLnWt018 = 18,
	kLnWt020 = 20,
	kLnWt025 = 25,
	kLnWt030 = 30,
	kLnWt035 = 35,
	kLnWt040 = 40,
	kLnWt050 = 50,
	kLnWt053 = 53,
	kLnWt060 = 60,
	kLnWt070 = 70,
	kLnWt080 = 80,
	kLnWt090 = 90,
	kLnWt100 = 100,
	kLnWt106 = 106,
	kLnWt120 = 120,
	kLnWt140 = 140,
	kLnWt158 = 158,
	kLnWt200 = 200,
	kLnWt211 = 211,
	kLnWtByLayer = -1,
	kLnWtByBlock = -2,
	kLnWtByLwDefault = -3,
	kLnWtByDIPs = -4
};

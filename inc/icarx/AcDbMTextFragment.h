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
***     Description: Declaration of AcDbMTextFragment struct
***
*****************************************************************************/
#pragma once

#include "../dbmain.h"

#include "IcArxPackPush.h"

struct AcDbMTextFragment
{
	AcGePoint3d location;
	AcGeVector3d normal;
	AcGeVector3d direction;
	AcString msText;
	const ACHAR* text = nullptr;
	AcString msFont;
	const ACHAR* font = nullptr;
	AcString msBigFont;
	const ACHAR* bigfont = nullptr;
	AcGePoint2d extents;
	double capsHeight = 0.0;
	double widthFactor = 0.0;
	double obliqueAngle = 0.0;
	double trackingFactor = 0.0;
	AcCmEntityColor color;
	unsigned stackTop : 1;
	unsigned stackBottom : 1;
	unsigned underlined : 1;
	unsigned overlined : 1;
	unsigned strikethrough : 1;
	AcGePoint3d underPoints[2] = {};
	AcGePoint3d overPoints[2] = {};
	AcGePoint3d strikePoints[2] = {};
	AcString msFontName;
	const ACHAR* fontname = nullptr;
	bool bold = false;
	bool italic = false;
};

#include "IcArxPackPop.h"

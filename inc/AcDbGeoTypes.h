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
***     Description: Declaration of GeoMap related types
***
*****************************************************************************/
#pragma once

enum AcGeoMapResolution
{
	kCoarse = -1,
	kOptimal = 0,
	kFine = 1,
	kFiner = 2
};

enum AcGeoMapType
{
	kNoMap = 0,
	kAerial = 1,
	kRoad = 2,
	kHybrid = 3
};

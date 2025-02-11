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
***     Description: Declaration of AcDbEnumXref
***
*****************************************************************************/
#pragma once

#include "AcDb.h"

enum AcDb::XrefStatus
{
	kXrfNotAnXref = 0,
	kXrfResolved = 1,
	kXrfUnloaded = 2,
	kXrfUnreferenced = 3,
	kXrfFileNotFound = 4,
	kXrfUnresolved = 5
};

enum AcDb::XrefNotificationStatus
{
	kXrfNotifyNone = 0,
	kXrfNotifyResolvedMatch = 1,
	kXrfNotifyResolvedElsewhere = 2,
	kXrfNotifyResolvedWithUpdate = 3,
	kXrfNotifyResolvedUpdateAvailable = 4
};

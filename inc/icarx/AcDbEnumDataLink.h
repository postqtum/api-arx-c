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
***     Description: Declaration of AcDbEnumDataLink
***
*****************************************************************************/
#pragma once

#include "AcDb.h"

enum AcDb::DataLinkOption
{
	kDataLinkOptionNone = 0,
	kDataLinkOptionAnonymous = 0x1,
	kDataLinkOptionPersistCache = 0x2,
	kDataLinkOptionObsolete = 0x4,
	kDataLinkHasCutomData = 0x8,
};

enum AcDb::DataLinkGetSourceContext
{
	kDataLinkGetSourceContextUnknown = 0,
	kDataLinkGetSourceContextEtransmit = 1,
	kDataLinkGetSourceContextXrefManager = 2,
	kDataLinkGetSourceContextFileWatcher = 3,
	kDataLinkGetSourceContextOther = 4,
	kDataLinkGetSourceContextOrignalPath = (0x1 << 8),
};

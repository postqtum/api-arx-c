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
***     Description: Declaration of AcDbDgnRefFileData struct
***
*****************************************************************************/
#pragma once

#include "../AcString.h"

using AcDgnRefFileId = uint64_t;

#include "IcArxPackPush.h"

struct AcDbDgnRefFileData
{
	enum FileType
	{
		kDgnFile = 1,
		kDwgFile = 2,
		kImageFile = 3,
		kOtherFile = 4
	};

	FileType type;
	AcString savedPathAndName;
	AcString foundPathAndName;
	AcDgnRefFileId refId;
};

#include "IcArxPackPop.h"

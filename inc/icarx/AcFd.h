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
***     Description: Declaration of AcFd struct
***
*****************************************************************************/
#pragma once

#include "IcArxPackPush.h"

struct AcFd
{
	enum ConvertFieldToText
	{
		kConvertFieldToTextNone = 0,
		kEvaluateBeforeConversion = (0x1 << 0),
		kExcludeEvaluatorsInList = (0x1 << 1),
		kIgnoreEvaluatorVersion = (0x1 << 2),
	};

	enum EvalFields
	{
		kEvalRecursive = (0x1 << 0),
	};
};

#include "IcArxPackPop.h"

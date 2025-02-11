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
***     Description: Declaration of AcGsClientViewInfo struct
***
*****************************************************************************/
#pragma once

#include "../acgi.h"

class AcGiContextualAttributes;

#include "IcArxPackPush.h"

struct AcGsClientViewInfo
{
	IcArx::Integers::LongPtr viewportId;
	IcArx::Integers::LongPtr acadWindowId;
	IcArx::Integers::IntDbId viewportObjectId;
	AcGiContextualColors* contextColors;
	AcGiContextualAttributes* contextualAttributes;

	AcGsClientViewInfo()
			: viewportId(0)
			, acadWindowId(0)
			, viewportObjectId(0)
			, contextColors(nullptr)
			, contextualAttributes(nullptr)
	{
	}

	AcDbObjectId viewportObjectAsObjectId() const;
};

#include "IcArxPackPop.h"

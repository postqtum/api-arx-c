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
***     Description: Declaration of AcGsNode class
*** 				 Declaration of AcGsDrawableLink struct
***
*****************************************************************************/
#pragma once

#include "../drawable.h"

#include "IcArxPackPush.h"

class AcGsNode
{
public:
	virtual ~AcGsNode() = default;

	virtual AcGiDrawable* drawable() const = 0;
};

struct AcGsDrawableLink
{
	IcArx::Integers::IntDbId id;
	AcGiDrawable* pDrawable;
	AcGsNode* pNode;
};

#include "IcArxPackPop.h"

using AcGsDrawablePath = AcArray<AcGsDrawableLink>;

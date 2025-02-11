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
***     Description: Declaration of AcEdViewCubeReactor class
***
*****************************************************************************/
#pragma once

#include "AcEdViewCubePart.h"

class AcEdViewCube;

#include "IcArxPackPush.h"

class AcEdViewCubeReactor
{
public:
	virtual void onClicked(AcEdViewCube* pCube, AcEdViewCubePart part) = 0;
	virtual void onDragBegin(AcEdViewCube* pCube, AcEdViewCubePart part) = 0;
	virtual void onDragEnd(AcEdViewCube* pCube) = 0;
};

#include "IcArxPackPop.h"

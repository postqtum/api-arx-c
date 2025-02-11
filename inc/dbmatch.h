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
***     Description: Common includes for database support
***
*****************************************************************************/
#pragma once

#include "acdb.h"
#include "dbmain.h"

#include "icarx/IcArxPackPush.h"

class AcDbMatchProperties : public AcRxObject
{
public:
	enum Flags
	{
		kColorFlag = 0x1,
		kLayerFlag = 0x2,
		kLtypeFlag = 0x4,
		kThicknessFlag = 0x8,
		kLtscaleFlag = 0x10,
		kTextFlag = 0x20,
		kDimensionFlag = 0x40,
		kHatchFlag = 0x80,
		kLweightFlag = 0x100,
		kPlotstylenameFlag = 0x200,
		kPolylineFlag = 0x400,
		kViewportFlag = 0x800,
		kTableFlag = 0x1000,
		kMaterialFlag = 0x2000,
		kShadowDisplayFlag = 0x4000,
		kMultileaderFlag = 0x8000,
		kTransparencyFlag = 0x10000,
		kCenterObjectFlag = 0x20000,
		kSetAllFlagsOn = 0x3FFFF
	};

public:
	ACRX_DECLARE_MEMBERS(AcDbMatchProperties);

	virtual void copyProperties(AcDbEntity* pSrcEntity, AcDbEntity* pTrgEntity,
								unsigned int flag) const = 0;
};

#include "icarx/IcArxPackPop.h"

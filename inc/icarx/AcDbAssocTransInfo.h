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
***     Description: Declaration of AcDbAssocTransInfo struct
***
*****************************************************************************/
#pragma once

#include "../AcDbCore2dDefs.h"
#include "../gemat3d.h"

#include "IcArxPackPush.h"

struct AcDbAssocTransInfo
{
	enum TransType
	{
		kGeneral = 0,
		kScaling,
		kRadius,
		kMajorRadius,
		kMinorRadius,
		kFixedRadius,
		kFixed,
		kFixWhenPossible,
		kNone,
	};

	TransType mTransType = kGeneral;
	AcGeMatrix3d mTrans;
	double mRadius = -1.0;

	ACDBCORE2D_PORT AcDbAssocTransInfo() = default;
};

#include "IcArxPackPop.h"

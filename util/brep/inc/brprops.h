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
***     Description:
***
*****************************************************************************/
#pragma once

#include "inc/adesk.h"
#include "inc/gepnt3d.h"
#include "inc/gevec3d.h"

#include "inc/icarx/IcArxPackPush.h"

struct AcBrMassProps
{
	double mVolume;				// 2nd field in AmiMassProps
	double mMass;				// 1st field in AmiMassProps
	AcGePoint3d mCentroid;		// 5th field in AmiMassProps
	double mRadiiGyration[3];	// 3rd field in AmiMassProps
	double mMomInertia[3];		// 7th field in AmiMassProps
	double mProdInertia[3];		// 8th field in AmiMassProps
	double mPrinMoments[3];		// 4th field in AmiMassProps
	AcGeVector3d mPrinAxes[3];	// 6th field in AmiMassProps
};

#include "inc/icarx/IcArxPackPop.h"

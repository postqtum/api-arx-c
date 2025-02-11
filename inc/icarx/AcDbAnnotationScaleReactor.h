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
***     Description: Declaration of AcDbAnnotationScaleReactor class
***
*****************************************************************************/
#pragma once

#include "AcDbAnnotationScale.h"

#include "IcArxPackPush.h"

class AcDbAnnotationScaleReactor : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbAnnotationScaleReactor, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT virtual void annotationScaleChanged(const AcDbDatabase* pDb,
														const AcDbViewport* pVP,
														const AcDbAnnotationScale* pScale,
														const bool bInitializing);
};

#include "IcArxPackPop.h"

ACDBCORE2D_PORT bool acdbAddAnnotationScaleReactor(AcDbAnnotationScaleReactor* pReactor);
ACDBCORE2D_PORT bool acdbRemoveAnnotationScaleReactor(AcDbAnnotationScaleReactor* pReactor);

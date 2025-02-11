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
***     Description: Declaration of AcGiClipBoundary class
***
*****************************************************************************/
#pragma once

#include "../adesk.h"
#include "../gevec3d.h"
#include "../gepnt3d.h"
#include "../gept2dar.h"
#include "../gemat3d.h"

#include "IcArxPackPush.h"

struct AcGiClipBoundary
{
	AcGeVector3d m_vNormal;
	AcGePoint3d m_ptPoint;
	AcGePoint2dArray m_aptPoints;
	AcGeMatrix3d m_xToClipSpace;
	AcGeMatrix3d m_xInverseBlockRefXForm;
	bool m_bClippingFront = false;
	bool m_bClippingBack = false;
	double m_dFrontClipZ = 0.0;
	double m_dBackClipZ = 0.0;
	bool m_bDrawBoundary = false;
};

#include "IcArxPackPop.h"

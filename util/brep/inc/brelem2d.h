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
#include "inc/rxobject.h"
#include "inc/rxboiler.h"
#include "brgbl.h"
#include "brelem.h"

class AcGeVector3d;
class AcBrElement2dData;

#include "inc/icarx/IcArxPackPush.h"

class AcBrElement2d : public AcBrElement
{
public:
	ACRX_DECLARE_MEMBERS(AcBrElement2d);

	AcBrElement2d();
	AcBrElement2d(const AcBrElement2d& src);
	~AcBrElement2d();
	AcBrElement2d& operator=(const AcBrElement2d& src);
	AcBr::ErrorStatus get(AcBrElement2dData*& data) const;
	AcBr::ErrorStatus getNormal(AcGeVector3d& normal) const;
	AcBr::ErrorStatus set(AcBrElement2dData* data);
};

#include "inc/icarx/IcArxPackPop.h"

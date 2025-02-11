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
***     Description: Declaration of AcBrMesh2dControl class
***
*****************************************************************************/
#pragma once

#include "inc/adesk.h"
#include "inc/rxobject.h"
#include "inc/rxboiler.h"
#include "brgbl.h"
#include "brmctl.h"

class AcBrMeshControl;

#include "inc/icarx/IcArxPackPush.h"

class AcBrMesh2dControl : public AcBrMeshControl
{
public:
	ACRX_DECLARE_MEMBERS(AcBrMesh2dControl);

	AcBrMesh2dControl();
	AcBrMesh2dControl(const AcBrMesh2dControl& src);
	~AcBrMesh2dControl();
	AcBrMesh2dControl& operator=(const AcBrMesh2dControl& src);
	AcBr::ErrorStatus getElementShape(AcBr::Element2dShape& elementShape) const;
	AcBr::ErrorStatus getMaxAspectRatio(double& maxAspectRatio) const;
	AcBr::ErrorStatus setElementShape(
			const AcBr::Element2dShape& elementShape = *(AcBr::Element2dShape*)nullptr);
	AcBr::ErrorStatus setMaxAspectRatio(const double& maxAspectRatio = *(double*)nullptr);
};

#include "inc/icarx/IcArxPackPop.h"

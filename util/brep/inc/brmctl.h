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
***     Description: Declaration of AcBrMeshControl class
***
*****************************************************************************/
#pragma once

#include "inc/adesk.h"
#include "inc/rxobject.h"
#include "inc/rxboiler.h"
#include "brgbl.h"

class AcBrImpMeshControl;

#include "inc/icarx/IcArxPackPush.h"

class AcBrMeshControl : public AcRxObject
{
protected:
	AcBrImpMeshControl* mpImp;

	AcBrMeshControl();
	AcBrMeshControl(const AcBrMeshControl& src);
	AcBrMeshControl& operator=(const AcBrMeshControl& src);

public:
	ACRX_DECLARE_MEMBERS(AcBrMeshControl);

	virtual ~AcBrMeshControl();
	AcBr::ErrorStatus getAngTol(double& angTol) const;
	AcBr::ErrorStatus getDistTol(double& distTol) const;
	AcBr::ErrorStatus getMaxNodeSpacing(double& maxNodeSpace) const;
	AcBr::ErrorStatus getMaxSubdivisions(uint32_t& maxSubs) const;
	bool isEqualTo(const AcRxObject* other) const;
	AcBr::ErrorStatus setAngTol(const double& angTol = *(double*)nullptr);
	AcBr::ErrorStatus setDistTol(const double& distTol = *(double*)nullptr);
	AcBr::ErrorStatus setMaxNodeSpacing(const double& maxNodeSpace = *(double*)nullptr);
	AcBr::ErrorStatus setMaxSubdivisions(const uint32_t& maxSubs = *(uint32_t*)nullptr);
};

#include "inc/icarx/IcArxPackPop.h"

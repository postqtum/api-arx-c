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

#include "gemat3d.h"
#include "icarx/AxAutoExp.h"

#include "icarx/IcArxPackPush.h"

class AXAUTOEXP AcAxMatrix3d : public AcGeMatrix3d
{
private:
	AcAxMatrix3d& fromSafeArray(const SAFEARRAY* safeArrayPt) noexcept(false);

public:
	AcAxMatrix3d();
	AcAxMatrix3d(const SAFEARRAY* safeArrayPt) noexcept(false);
	AcAxMatrix3d(const VARIANT& var) noexcept(false);
	AcAxMatrix3d(const VARIANT* var) noexcept(false);
	AcAxMatrix3d& operator=(const SAFEARRAY* safeArrayPt) noexcept(false);
	AcAxMatrix3d& operator=(const VARIANT& var) noexcept(false);
	AcAxMatrix3d& operator=(const VARIANT* var) noexcept(false);
};

#include "icarx/IcArxPackPop.h"

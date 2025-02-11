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
***     Description: Declaration of AcAxPoint3d class
***
*****************************************************************************/
#pragma once

#include "AxAutoExp.h"
#include "../AcValue.h"
#include "../gepnt3d.h"

typedef struct tagSAFEARRAY SAFEARRAY;

#include "IcArxPackPush.h"
#pragma warning(disable : 4290)

class AXAUTOEXP AcAxPoint3d : public AcGePoint3d
{
private:
	AcAxPoint3d& fromSafeArray(const SAFEARRAY* safeArrayPt) noexcept(false);

public:
	AcAxPoint3d();
	AcAxPoint3d(double x, double y, double z);
	AcAxPoint3d(const AcGePoint3d& pt);
	AcAxPoint3d(const AcGeVector3d& pt);
	AcAxPoint3d(const SAFEARRAY* safeArrayPt) noexcept(false);
	AcAxPoint3d(const VARIANT& var) noexcept(false);
	AcAxPoint3d(const VARIANT* var) noexcept(false);
	AcAxPoint3d& operator=(const AcGePoint3d& pt);
	AcAxPoint3d& operator=(const AcGeVector3d& pt);
	AcAxPoint3d& operator=(const SAFEARRAY* safeArrayPt) noexcept(false);
	AcAxPoint3d& operator=(const VARIANT& var) noexcept(false);
	AcAxPoint3d& operator=(const VARIANT* var) noexcept(false);

	SAFEARRAY* asSafeArrayPtr() const noexcept(false);
	VARIANT* asVariantPtr() const noexcept(false);
	VARIANT& setVariant(VARIANT& var) const noexcept(false);
	VARIANT* setVariant(VARIANT* var) const noexcept(false);
};

#include "IcArxPackPop.h"

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
***     Description: Declaration of AcAxPoint2d class
***
*****************************************************************************/
#pragma once

#include "AxAutoExp.h"
#include "../AcValue.h"
#include "../gepnt2d.h"

typedef struct tagSAFEARRAY SAFEARRAY;

#include "IcArxPackPush.h"
#pragma warning(disable : 4290)

class AXAUTOEXP AcAxPoint2d : public AcGePoint2d
{
private:
	AcAxPoint2d& fromSafeArray(const SAFEARRAY* safeArrayPt) noexcept(false);

public:
	AcAxPoint2d();
	AcAxPoint2d(double x, double y);
	AcAxPoint2d(const AcGePoint2d& pt);
	AcAxPoint2d(const AcGeVector2d& pt);
	AcAxPoint2d(const SAFEARRAY* safeArrayPt) noexcept(false);
	AcAxPoint2d(const VARIANT& var) noexcept(false);
	AcAxPoint2d(const VARIANT* var) noexcept(false);
	AcAxPoint2d& operator=(const AcGePoint2d& pt);
	AcAxPoint2d& operator=(const AcGeVector2d& pt);
	AcAxPoint2d& operator=(const SAFEARRAY* safeArrayPt) noexcept(false);
	AcAxPoint2d& operator=(const VARIANT& var) noexcept(false);
	AcAxPoint2d& operator=(const VARIANT* var) noexcept(false);

	SAFEARRAY* asSafeArrayPtr() const noexcept(false);
	VARIANT* asVariantPtr() const noexcept(false);
	VARIANT& setVariant(VARIANT& var) const noexcept(false);
	VARIANT* setVariant(VARIANT* var) const noexcept(false);
};

#include "IcArxPackPop.h"

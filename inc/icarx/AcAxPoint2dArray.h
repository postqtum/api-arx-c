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
***     Description: Declaration of AcAxPoint2dArray class
***
*****************************************************************************/
#pragma once

#include "AxAutoExp.h"
#include "../AcValue.h"
#include "../gept2dar.h"

typedef struct tagSAFEARRAY SAFEARRAY;

#include "IcArxPackPush.h"
#pragma warning(disable : 4290)
#pragma warning(disable : 4275)

class AXAUTOEXP AcAxPoint2dArray : public AcGePoint2dArray
{
private:
	AcAxPoint2dArray& fromSafeArray(const SAFEARRAY* safeArrayPt) noexcept(false);

public:
	AcAxPoint2dArray& append(const AcGePoint2d& pt);
	AcAxPoint2dArray& append(const SAFEARRAY* safeArrayPt) noexcept(false);
	AcAxPoint2dArray& append(const VARIANT& var) noexcept(false);
	AcAxPoint2dArray& append(const VARIANT* var) noexcept(false);

	SAFEARRAY* asSafeArrayPtr() const noexcept(false);
	VARIANT& setVariant(VARIANT& var) const noexcept(false);
	VARIANT* setVariant(VARIANT* var) const noexcept(false);
};

#include "IcArxPackPop.h"

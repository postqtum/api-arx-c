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
***     Description: Declaration of AcAxPoint3dArray class
***
*****************************************************************************/
#pragma once

#include "AxAutoExp.h"
#include "../AcValue.h"
#include "../gept3dar.h"

typedef struct tagSAFEARRAY SAFEARRAY;

#include "IcArxPackPush.h"
#pragma warning(disable : 4290)
#pragma warning(disable : 4275)

class AXAUTOEXP AcAxPoint3dArray : public AcGePoint3dArray
{
private:
	AcAxPoint3dArray& fromSafeArray(const SAFEARRAY* safeArrayPt) noexcept(false);

public:
	AcAxPoint3dArray& append(const AcGePoint3d& pt);
	AcAxPoint3dArray& append(const SAFEARRAY* safeArrayPt) noexcept(false);
	AcAxPoint3dArray& append(const VARIANT& var) noexcept(false);
	AcAxPoint3dArray& append(const VARIANT* var) noexcept(false);

	SAFEARRAY* asSafeArrayPtr() const noexcept(false);
	VARIANT& setVariant(VARIANT& var) const noexcept(false);
	VARIANT* setVariant(VARIANT* var) const noexcept(false);
};

#include "IcArxPackPop.h"

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
***     Description: Declaration of AcBrElement
***
*****************************************************************************/
#pragma once

#include "inc/adesk.h"
#include "inc/rxobject.h"
#include "inc/rxboiler.h"
#include "brment.h"

#include "inc/icarx/IcArxPackPush.h"

class AcBrElement : public AcBrMeshEntity
{
protected:
	AcBrElement();
	AcBrElement(const AcBrElement& src);
	AcBrElement& operator=(const AcBrElement& src);

public:
	ACRX_DECLARE_MEMBERS(AcBrElement);

	virtual ~AcBrElement();
};

#include "inc/icarx/IcArxPackPop.h"

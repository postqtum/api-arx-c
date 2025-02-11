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
***     Description: Declaration of AcRxAttribute class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../pimplapi.h"

class AcRxAttributeImp;

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcRxAttribute : public Pimpl::ApiPart<AcRxObject, AcRxAttributeImp>
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcRxAttribute, ACBASE_PORT);
	ACBASE_PORT ~AcRxAttribute() = 0;

protected:
	ACBASE_PORT AcRxAttribute(AcRxAttributeImp*);
};

#include "IcArxPackPop.h"

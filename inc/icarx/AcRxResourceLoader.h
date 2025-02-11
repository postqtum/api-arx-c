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
***     Description: Declaration of AcRxResourceLoader class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcRxResourceLoader : public AcRxObject
{
private:
	virtual Acad::ErrorStatus subLoadString(unsigned int id, unsigned int sourceHint,
											AcString& result) = 0;

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcRxResourceLoader, ACBASE_PORT);

	ACBASE_PORT static Acad::ErrorStatus loadString(const AcRxObject* pClass, unsigned int id,
													unsigned int sourceHint, AcString& result);
};

#include "IcArxPackPop.h"

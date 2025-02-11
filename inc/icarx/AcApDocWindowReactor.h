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
***     Description: Declaration of AcApDocWindowReactor class
***
*****************************************************************************/
#pragma once

#include "../acadapidef.h"
#include "../acedinpt.h"

#include "IcArxPackPush.h"

class AcApDocWindowReactor
{
public:
	ACAD_PORT virtual void documentWindowLoaded();
	ACAD_PORT virtual void documentWindowUpdated();
};

#include "IcArxPackPop.h"

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
***     Description: AcFilterablePropertyContext enum define
***
*****************************************************************************/
#pragma once

typedef
#ifndef __clang__
	__declspec(uuid("ba8e61f1-88a2-414d-b9a0-7489bea8d322"))
#endif
enum AcFilterablePropertyContext {
	acQuickPropertiesContext = 0,
	acTooltipContext = 1
} AcFilterablePropertyContext;

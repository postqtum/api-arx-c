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

#include "adesk.h"
#include "acdbport.h"
#include "mgdhost-core2d.h"

ACDB_PORT HRESULT ADESK_STDCALL acdbInitializeManagedLayer();
ACDB_PORT HRESULT ADESK_STDCALL acdbTerminateManagedLayer();

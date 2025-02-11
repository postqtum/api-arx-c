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

#include "icarx/AcStatusBarItem.h"
#include "icarx/AcPane.h"
#include "icarx/AcTrayItemAnimationControl.h"
#include "icarx/AcTrayItemBubbleWindowControl.h"
#include "icarx/AcTrayItem.h"
#include "icarx/AcApStatusBar.h"
#include "icarx/AcStatusBarMenuItem.h"

#include "acdocman.h"
#include "adesk.h"

#define ACSB_NOBORDERS (1 << 0)
#define ACSB_INACTIVE (1 << 1)
#define ACSB_STRETCH (1 << 2)
#define ACSB_ACTIVE (1 << 3)
#define ACSB_COMMAND (1 << 4)
#define ACSB_POPUP (1 << 5)
#define ACSB_DIVIDER (1 << 6)
#define ACSB_SUBDIVIDER (1 << 7)
#define ACSB_INDETERMINATE (1 << 8)
#define ACSB_ONETIME (1 << 9)

#define ACSB_POPOUT ACSB_INACTIVE
#define ACSB_NORMAL ACSB_ACTIVE

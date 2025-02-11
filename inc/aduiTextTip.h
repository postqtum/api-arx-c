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
***     Description: Common includes for tool-tips support
***
*****************************************************************************/
#pragma once

#include "icarx/CAdUiTipWindow.h"
#include "icarx/CAdUiBalloonTip.h"
#include "icarx/CAdUiTextTip.h"
#include "icarx/CAdToolTipCtrl.h"
#include "icarx/CAdWthToolTipCtrl.h"

void ADUI_PORT AdUiHideBalloonTip(CWnd* control);
BOOL ADUI_PORT AdUiShowBalloonTip(CWnd* owner, CWnd* control, LPCTSTR text, BOOL beep);
BOOL ADUI_PORT AdUiShowBalloonTip(CWnd* owner, CWnd* control, CRect& rect, LPCTSTR text, BOOL beep);

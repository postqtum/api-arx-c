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

#include "icarx/AcColorSettings.h"
#include "icarx/AcColorSettingsEx.h"
#include "icarx/AcColorSettingsEx2.h"
#include "icarx/AcColorSettingsEx3.h"

#include "AcCoreDefs.h"
#include "AcHeapOpers.h"

class IAcEdRunLoopTask : public AcHeapOperators
{
public:
	virtual ~IAcEdRunLoopTask() = default;

	virtual void execute() = 0;
};

typedef double acedDwgPoint[3];
using TaskId = long long;
using AcedWatchWinMsgFn = void (*)(const MSG*);
using AcedFilterWinMsgFn = bool (*)(MSG*);
using AcedOnIdleMsgFn = void (*)();
using AcedOnModalFn = void (*)(bool bModal);
using AcedRunLoopFn = void (*)(void* pContext);
using AcedCommandBitmapQueryFn = HBITMAP (*)(const wchar_t* cmdName,
											 const COLORREF& backgroundColor);

class AcCommandToolTipInfo;
class AcApStatusBar;

ACCORE_PORT void acedCoordFromPixelToWorld(const CPoint& ptIn, acedDwgPoint ptOut);
ACCORE_PORT bool acedCoordFromPixelToWorld(int windnum, CPoint ptIn, acedDwgPoint ptOut);
ACCORE_PORT bool acedCoordFromWorldToPixel(int windnum, const acedDwgPoint ptIn, CPoint& ptOut);
ACCORE_PORT bool acedDrawingStatusBarsVisible();
ACCORE_PORT HINSTANCE acedGetAcadResourceInstance();
ACCORE_PORT AcApStatusBar* acedGetApplicationStatusBar();
ACCORE_PORT HBITMAP acedGetBitmapForCommand(const wchar_t* cmdName,
											const COLORREF& backgroundColor);
ACCORE_PORT HBITMAP acedGetCachedBitmapForCommand(const wchar_t* cmdName,
												  const COLORREF& backgroundColor);
ACCORE_PORT bool acedGetToolTipInfoForCommand(const ACHAR* cmdName, AcCommandToolTipInfo* pInfo);
int acedGetWinNum(int ptx, int pty);
ACCORE_PORT TaskId acedExecuteOnMainThread(const AcedRunLoopFn pfn, void* pContext,
										   bool bWaitUntilDone = false);
ACCORE_PORT TaskId acedExecuteOnMainThread(IAcEdRunLoopTask* pTask, bool bWaitUntilDone = false);
ACCORE_PORT bool acedIsInputPending();
ACCORE_PORT bool acedRegisterCommandBitmapQuery(const AcedCommandBitmapQueryFn pfn);
ACCORE_PORT bool acedRegisterFilterWinMsg(const AcedFilterWinMsgFn pfn);
ACCORE_PORT bool acedRegisterOnIdleWinMsg(const AcedOnIdleMsgFn pfn);
ACCORE_PORT bool acedRegisterOnModal(const AcedOnModalFn pfn);
ACCORE_PORT bool acedRegisterWatchWinMsg(const AcedWatchWinMsgFn pfn);
ACCORE_PORT bool acedRemoveCommandBitmapQuery(const AcedCommandBitmapQueryFn pfn);
ACCORE_PORT bool acedRemoveFilterWinMsg(const AcedFilterWinMsgFn pfn);
ACCORE_PORT bool acedRemoveOnIdleWinMsg(const AcedOnIdleMsgFn pfn);
ACCORE_PORT bool acedRemoveOnModal(const AcedOnModalFn pfn);
ACCORE_PORT void acedRemoveRunLoopTask(TaskId taskId);
ACCORE_PORT bool acedRemoveWatchWinMsg(const AcedWatchWinMsgFn pfn);
void acedRestoreStatusBar();
int acedSetStatusBarProgressMeter(const ACHAR* pszLabel, int nMinPos, int nMaxPos);
int acedSetStatusBarProgressMeterPos(int nPos);

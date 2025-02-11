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
***     Description: Declaration of AcEdInputPointManager class
***
*****************************************************************************/
#pragma once

#include "../acadstrc.h"

class AcEdInputPointFilter;
class AcEdInputPointMonitor;
class AcEdInputContextReactor;
class AcEdSubSelectFilter;

#include "IcArxPackPush.h"

class AcEdInputPointManager
{
protected:
	virtual ~AcEdInputPointManager();

public:
	virtual Acad::ErrorStatus addInputContextReactor(AcEdInputContextReactor* pReactor) = 0;
	virtual Acad::ErrorStatus addPointMonitor(AcEdInputPointMonitor* pMonitor) = 0;
	virtual Acad::ErrorStatus addSubSelectFilter(AcEdSubSelectFilter* pSSSubFilter) = 0;
	virtual AcEdInputPointFilter* currentPointFilter() const = 0;
	virtual Acad::ErrorStatus disableSystemCursorGraphics() = 0;
	virtual void enableMultiSubentPathSelection(bool bEnable) = 0;
	virtual Acad::ErrorStatus enableSystemCursorGraphics() = 0;
	virtual int forcedPickCount() const = 0;
	virtual int mouseHasMoved() const = 0;
	virtual Acad::ErrorStatus registerPointFilter(AcEdInputPointFilter* pFilter) = 0;
	virtual Acad::ErrorStatus removeInputContextReactor(AcEdInputContextReactor* pReact) = 0;
	virtual Acad::ErrorStatus removePointMonitor(AcEdInputPointMonitor* pMonitor) = 0;
	virtual Acad::ErrorStatus removeSubSelectFilter(AcEdSubSelectFilter* pSSSubFilter) = 0;
	virtual Acad::ErrorStatus revokePointFilter() = 0;
	virtual int systemCursorDisableCount() const = 0;
	virtual Acad::ErrorStatus turnOffForcedPick() = 0;
	virtual Acad::ErrorStatus turnOffSubentityWindowSelection() = 0;
	virtual Acad::ErrorStatus turnOnForcedPick() = 0;
	virtual Acad::ErrorStatus turnOnSubentityWindowSelection() = 0;
};

#include "IcArxPackPop.h"

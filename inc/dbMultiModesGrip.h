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
***     Description: Declaration of AcDbMultiModesGripPE class
***
*****************************************************************************/
#pragma once

#include "acdb.h"
#include "dbmain.h"
#include "AcString.h"

#include "icarx/IcArxPackPush.h"

class ADESK_NO_VTABLE AcDbMultiModesGripPE : public AcRxObject
{
public:
	enum GripActionType
	{
		kDragOn = 0,
		kImmediate,
		kCommand,
	};

	enum GripCursorType
	{
		kcNone = 0,
		kcCrosshairPlus,
		kcCrosshairMinus,
		kcCrosshairCurve,
		kcCrosshairLine,
		kcCrosshairAngle,
	};

	struct GripMode
	{
		GripMode();
		unsigned int Mode;
		AcString DisplayString;
		AcString ToolTip;
		AcString CLIDisplayString;
		AcString CLIPromptString;
		AcString CLIKeywordList;
		GripCursorType CursorType;
		GripActionType ActionType;
		AcString CommandString;
	};

	enum GripModeIdentifier
	{
		kNone = 0,
		kMove,
		kCustomStart = 100,
	};

	enum GripType
	{
		kPrimary,
		kSecondary
	};

public:
	ACRX_DECLARE_MEMBERS(AcDbMultiModesGripPE);

	virtual bool getGripModes(AcDbEntity* pThis, AcDbGripData* pGripData, AcArray<GripMode>& modes,
							  unsigned int& curMode) const = 0;
	virtual GripType gripType(AcDbEntity* pThis, AcDbGripData* pGripData) const = 0;
	virtual unsigned int mode(AcDbEntity* pThis, AcDbGripData* pGripData) const = 0;
	virtual GripMode modeEx(AcDbEntity* pThis, AcDbGripData* pGripData) const = 0;
	virtual void reset(AcDbEntity* pThis) = 0;
	virtual bool setMode(AcDbEntity* pThis, AcDbGripData* pGripData, unsigned int newMode) = 0;
};

#include "icarx/IcArxPackPop.h"

inline AcDbMultiModesGripPE::GripMode::GripMode()
		: Mode(AcDbMultiModesGripPE::kMove), ActionType(kDragOn), CursorType(kcNone)
{
}

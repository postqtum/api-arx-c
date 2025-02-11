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

#include "icarx/CAcUiComboBox.h"
#include "icarx/CAcUiAngleComboBox.h"
#include "icarx/CAcUiNumericComboBox.h"
#include "icarx/CAcUiStringComboBox.h"
#include "icarx/CAcUiSymbolComboBox.h"
#include "icarx/CAcUiMRUListBox.h"
#include "icarx/CAcUiMRUComboBox.h"
#include "icarx/CAcUiLTypeRecord.h"
#include "icarx/CAcUiLineTypeComboBox.h"
#include "icarx/CAcUiColorComboBox.h"
#include "icarx/CAcUiTrueColorComboBox.h"
#include "icarx/CAcUiLineWeightComboBox.h"
#include "icarx/CAcUiArrowHeadComboBox.h"
#include "icarx/CAcUiPlotStyleTablesComboBox.h"
#include "icarx/CAcUiPlotStyleNamesComboBox.h"
#include "icarx/CAcUiPredefBlockComboBox.h"

#include "aduiComboBox.h"
#include "acuiListBox.h"

#include <map>

typedef std::map<int, AcCmColor*> AcCmColorTable;

enum ACUI_MRU_CARGO
{
	kAcUiMRUCargo_Last = -106,
	kAcUiMRUCargo_Option2 = -105,
	kAcUiMRUCargo_Option1 = -104,
	kAcUiMRUCargo_Other2 = -103,
	kAcUiMRUCargo_Other1 = -102,
	kAcUiMRUCargo_None = -101
};

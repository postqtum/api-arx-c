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
***     Description: Declaration of AcDbEnumLayer
***
*****************************************************************************/
#pragma once

#include "AcDb.h"

enum AcDb::IndexCreation
{
	kNoIndex = 0,
	kIndexByLayer = 1,
	kIndexSpatially = 2
};

enum AcDb::LayerEvaluation
{
	kNoNewLayerEvaluation = 0,
	kEvalNewXrefLayers = 1,
	kEvalAllNewLayers = 2
};

enum AcDb::NewLayerNotification
{
	kNoNewLayerNotification = 0,
	kNotifyOnPlot = 1,
	kNotifyOnOpen = 2,
	kNotifyOnXrefAttachAndReload = 4,
	kNotifyOnLayerStateRestore = 8,
	kNotifyOnSave = 16,
	kNotifyOnInsert = 32
};

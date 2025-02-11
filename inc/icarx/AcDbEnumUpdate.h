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
***     Description: Declaration of AcDbEnumUpdate
***
*****************************************************************************/
#pragma once

#include "AcDb.h"

enum AcDb::UpdateDirection
{
	kUpdateDirSourceToData = 0x1,
	kUpdateDirDataToSource = 0x2,
};

enum AcDb::UpdateOption
{
	kUpdateOptionNone = 0,
	kUpdateOptionSkipFormat = 0x20000,
	kUpdateOptionUpdateRowHeight = 0x40000,
	kUpdateOptionUpdateColumnWidth = 0x80000,
	kUpdateOptionAllowSourceUpdate = 0x100000,
	kUpdateOptionForceFullSourceUpdate = 0x200000,
	kUpdateOptionOverwriteContentModifiedAfterUpdate = 0x400000,
	kUpdateOptionOverwriteFormatModifiedAfterUpdate = 0x800000,
	kUpdateOptionForPreview = 0x1000000,
	kUpdateOptionIncludeXrefs = 0x2000000,
	kSkipFormatAfterFirstUpdate = 0x4000000,
};

enum AcDb::DrawOrderFlags
{
	kDrawOrderInPlaceEditOn = 0x01,
	kDrawOrderInheritanceOn = 0x02
};

enum AcDb::UpdateThumbnailFlags
{
	kUpdateModelViews = 0x01,
	kUpdateSheetViews = 0x02,
	kUpdateSheets = 0x04,
	kUpdateWhenAccessed = 0x08,
	kUpdateWhenSaving = 0x10
};

enum AcDb::EnhancedBlockEvalType
{
	kInitialization = 1,
	kForUpdate = 2,
	kForRefresh = 3
};

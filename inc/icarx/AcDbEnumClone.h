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
***     Description: Declaration of AcDbEnumClone
***
*****************************************************************************/
#pragma once

#include "AcDb.h"

enum AcDb::DeepCloneType
{
	kDcCopy = 0,
	kDcExplode = 1,
	kDcBlock = 2,
	kDcXrefBind = 3,
	kDcSymTableMerge = 4,
	kDcInsert = 6,
	kDcWblock = 7,
	kDcObjects = 8,
	kDcXrefInsert = 9,
	kDcInsertCopy = 10,
	kDcWblkObjects = 11
};

enum AcDb::DuplicateRecordCloning
{
	kDrcNotApplicable = 0,
	kDrcIgnore = 1,
	kDrcReplace = 2,
	kDrcXrefMangleName = 3,
	kDrcMangleName = 4,
	kDrcUnmangleName = 5
};

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

#include "icarx/AcDbEvalContextIterator.h"
#include "icarx/AcDbEvalContextPair.h"
#include "icarx/AcDbEvalVariant.h"
#include "icarx/AcDbEvalConnectable.h"
#include "icarx/AcDbEvalExpr.h"
#include "icarx/AcDbEvalEdgeInfo.h"
#include "icarx/AcDbEvalGraph.h"
#include "icarx/AcDbEvalContext.h"

#include "dbmain.h"
#include "dbents.h"
#include "AcString.h"
#include "adscodes.h"
#include "adsdef.h"

using AcDbEvalNodeIdArray = AcArray<AcDbEvalNodeId>;
using AcDbEvalEdgeInfoArray = AcArray<AcDbEvalEdgeInfo*>;
using AcDbEvalExprPtrArray = AcArray<AcDbEvalExpr*>;
using AcDbEvalVariantArray =
		AcArray<AcDbEvalVariant, AcArrayObjectCopyReallocator<AcDbEvalVariant>>;

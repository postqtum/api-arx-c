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

#include "icarx/AcDmUtil.h"
#include "icarx/AcDbDimensionStyleOverrule.h"
#include "icarx/AcDbRadialDimensionLarge.h"
#include "icarx/AcDbArcDimension.h"
#include "icarx/AcDbDiametricDimension.h"
#include "icarx/AcDbRadialDimension.h"
#include "icarx/AcDb2LineAngularDimension.h"
#include "icarx/AcDb3PointAngularDimension.h"
#include "icarx/AcDbRotatedDimension.h"
#include "icarx/AcDbAlignedDimension.h"
#include "icarx/AcDbOrdinateDimension.h"
#include "icarx/AcDbDimension.h"

#include "dbmain.h"
#include "dbmtext.h"
#include "acgi.h"

#define DYNAMIC_CONSTRAINT_LAYER_OLD ACRX_T("LayerNameForDynamicConstraint")
#define DYNAMIC_CONSTRAINT_LAYER_HIDDEN_OLD ACRX_T("*LayerNameForDynamicConstraint")

#define DYNAMIC_CONSTRAINT_LAYER ACRX_T("ADSK_CONSTRAINTS")
#define DYNAMIC_CONSTRAINT_LAYER_HIDDEN ACRX_T("*ADSK_CONSTRAINTS")

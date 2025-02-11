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

#include "icarx/AcGsKernelDescriptor.h"
#include "icarx/AcGsClientViewInfo.h"
#include "icarx/AcGsRender.h"
#include "icarx/AcGsGraphicsKernel.h"
#include "icarx/AcGsConfig.h"
#include "icarx/AcGsDevice.h"
#include "icarx/AcGsModel.h"
#include "icarx/AcGsDrawableLink.h"
#include "icarx/AcGsDCPoint.h"
#include "icarx/AcGsDCRect.h"
#include "icarx/AcGsView.h"
#include "icarx/AcGsColor.h"
#include "icarx/AcGsEnum.h"

#include "acarray.h"
#include "AdAChar.h"
#include "gept3dar.h"
#include "dbid.h"
#include "AcString.h"
#include "acgi.h"

using AcGsWindowId = void*;
using AcGsGetInterfaceFunc = AcGiDrawable* (*)(IcArx::Integers::IntDbId objectId, bool bNeedsValidation);
using AcGsReleaseInterfaceFunc = void (*)(AcGiDrawable*);

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
***     Description: Common includes for Document Manager
***
*****************************************************************************/
#pragma once

#include "icarx/AcApDocument.h"
#include "icarx/AcApDocManagerReactor.h"
#include "icarx/AcApDocumentIterator.h"
#include "icarx/AcApDocManager.h"

#include "AcApDocLockMode.h"

Acad::ErrorStatus acedUpgradeDocOpen();
Acad::ErrorStatus acedDowngradeDocOpen(bool bPromptForSave);

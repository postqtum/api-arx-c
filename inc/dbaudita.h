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

#include "icarx/AcDbAuditInfo.h"
#include "icarx/AcDbRecoverCallBack.h"

#include "AdAChar.h"

#define ACDB_AUDIT_RETURN(pAuditInfo, baseEs, localEs, boilDownLocalStatus)           \
	return (baseEs != eOk)	  ? baseEs                                                \
		   : (eOk == localEs) ? eOk                                                   \
		   : boilDownLocalStatus                                                      \
				   ? (pAuditInfo->fixErrors() ? eFixedAllErrors : eLeftErrorsUnfixed) \
				   : localEs;

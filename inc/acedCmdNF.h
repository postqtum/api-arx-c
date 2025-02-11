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
***     Description: AcEd command functions
***
*****************************************************************************/
#pragma once

#include "acedinpt.h"
#include "acdocman.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "icarx/IcArxPackPush.h"

	ACAD_PORT void acedCallBackOnCancel();

	typedef int (*AcEdCoroutineCallback)(void* pData);

	ACAD_PORT int acedCmdC(AcEdCoroutineCallback pCallback, void* pReturnFcnParms,
						   const struct resbuf* rb);

	class AcApDocument;

	int acedCmdS(const resbuf* rb, bool forFutureUse = false,
				 AcApDocument* pForFutureUse = nullptr);

	ACAD_PORT bool acedCmdCWasCancelled();

	ACAD_PORT int acedCommandC(AcEdCoroutineCallback pCallback, void* pReturnFcnParms, int rtype,
							   ...);

	int acedCommandS(int rtype, ...);

	ACAD_PORT bool acedFiberWorld();

	ACAD_PORT bool acedPendingCmdCTokens();

	ACAD_PORT bool acedResumingInvocation();

#include "icarx/IcArxPackPop.h"
#ifdef __cplusplus
}
#endif /* __cplusplus */

ACAD_PORT bool acedPendingFiberlessDocSwitch(AcApDocument** pNextActiveDocument = nullptr);

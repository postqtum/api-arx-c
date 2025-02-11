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
***     Description: Declaration of AcEdCommandStack class
***
*****************************************************************************/
#pragma once

#include "../accoredefs.h"
#include "../rxobject.h"

#include "AcEdCommandStruc.h"

class AcEdCommandIterator;
class AcEdCommandStackReactor;

#include "IcArxPackPush.h"

class AcEdCommandStack : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcEdCommandStack, ACCORE_PORT);

	virtual Acad::ErrorStatus addCommand(
			const ACHAR* cmdGroupName, const ACHAR* cmdGlobalName, const ACHAR* cmdLocalName,
			int32_t commandFlags, AcRxFunctionPtr FunctionAddr, AcEdUIContext* UIContext = nullptr,
			int fcode = -1,
			const AcRxResourceInstance& resourceInstance = AcRxResourceInstance::empty(),
			AcEdCommand** cmdPtrRet = nullptr) = 0;
	virtual bool atPut(const ACHAR* cmdGroupName, AcRxDictionary*& cmdsGlobal,
					   AcRxDictionary*& cmdsLocal) = 0;
	virtual AcEdCommandIterator* iterator() = 0;
	virtual AcEdCommand* lookupCmd(const ACHAR* cmdName, bool globalFlag) = 0;
	virtual AcEdCommand* lookupCmd(const ACHAR* cmdName, bool globalFlag, bool allGroupsFlag) = 0;
	virtual AcEdCommand* lookupCmd(const ACHAR* cmdName, bool globalFlag, bool allGroupsFlag,
								   bool skipUndefed) = 0;
	virtual AcEdCommand* lookupCmd2(const ACHAR* cmdName, bool globalFlag, bool allGroupsFlag,
									int skipFlags, bool match = false) = 0;
	virtual AcEdCommand* lookupGlobalCmd(const ACHAR* cmdName) = 0;
	virtual AcEdCommand* lookupLocalCmd(const ACHAR* cmdName) = 0;
	virtual Acad::ErrorStatus popGroupToTop(const ACHAR* cmdGroupName) = 0;
	virtual Acad::ErrorStatus removeCmd(const ACHAR* cmdGroupName, const ACHAR* cmdGlobalName) = 0;
	virtual Acad::ErrorStatus removeGroup(const ACHAR* groupName) = 0;
	void addReactor(AcEdCommandStackReactor* pReactor);
	void removeReactor(AcEdCommandStackReactor* pReactor);
};


#define ACRX_COMMAND_DOCK ACRX_T("ACAD_REGISTERED_COMMANDS")

#define acedRegCmds AcEdCommandStack::cast(acrxSysRegistry()->at(ACRX_COMMAND_DOCK))

#include "IcArxPackPop.h"

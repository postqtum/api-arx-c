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

#include "rxobject.h"
#include "AdAChar.h"
#include "rxdlinkr.h"

class AcadAppInfoImp;

#include "icarx/IcArxPackPush.h"

class AcadAppInfo : public AcRxObject
{
public:
	enum CmdStatus
	{
		kNoAction = 0,
		kRetry = 1,
		kShowMsg = 2,
		kNoModule = 3
	};

	enum MgdType
	{
		kUnManaged = 0,
		kManaged = 1,
		kJavaScript = 2
	};

	enum ReadFlags
	{
		kNone = 0,
		kSkipFindFileForModuleName = 1
	};

	using LoaderFunPtr = AcadAppInfo::CmdStatus (*)(void*);

protected:
	AcadAppInfoImp* mpImp;

public:
	ACRX_DECLARE_MEMBERS(AcadAppInfo);

	AcadAppInfo();
	~AcadAppInfo();

	const ACHAR* appDesc() const;
	bool appImplements(const ACHAR*) const;
	const ACHAR* appName() const;
	ACDBCORE2D_PORT AcadApp::ErrorStatus delFromRegistry();
	ACDBCORE2D_PORT AcadApp::LoadReasons loadReason() const;
	AcadAppInfo::MgdType managed() const;
	const ACHAR* moduleName() const;
	AcadApp::ErrorStatus readFromRegistry();
	ACDBCORE2D_PORT AcadApp::ErrorStatus readFromRegistry(ReadFlags flags);
	AcadAppInfo::CmdStatus runAppLoader();
	void setAppDesc(const ACHAR*);
	void setAppLoader(LoaderFunPtr);
	void setAppName(const ACHAR*);
	void setLoadReason(AcadApp::LoadReasons);
	void setManaged(AcadAppInfo::MgdType mgdType);
	void setModuleName(const ACHAR*);
	AcadApp::ErrorStatus status() const;
	AcadApp::ErrorStatus writeCommandNameToRegistry(const ACHAR* globalCmdName,
													const ACHAR* localCmdName);
	AcadApp::ErrorStatus writeGroupNameToRegistry(const ACHAR* group);
	ACDBCORE2D_PORT AcadApp::ErrorStatus writeToRegistry();
};

#include "icarx/IcArxPackPop.h"

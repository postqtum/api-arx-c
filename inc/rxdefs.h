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

#include "adesk.h"

#include "icarx/IcArxPackPush.h"

struct AcRx
{
	enum AppMsgCode
	{
		kNullMsg = 0,
		kInitAppMsg = 1,
		kUnloadAppMsg = 2,
		kLoadDwgMsg = 3,
		kUnloadDwgMsg = 4,
		kInvkSubrMsg = 5,
		kCfgMsg = 6,
		kEndMsg = 7,
		kQuitMsg = 8,
		kSaveMsg = 9,
		kDependencyMsg = 10,
		kNoDependencyMsg = 11,
		kOleUnloadAppMsg = 12,
		kPreQuitMsg = 13,
		kInitDialogMsg = 14,
		kEndDialogMsg = 15,
		kSuspendMsg = 16,
		kInitTabGroupMsg = 17,
		kEndTabGroupMsg = 18
	};

	enum AppRetCode
	{
		kRetOK = 0,
		kRetError = 3
	};

	enum DictIterType
	{
		kDictSorted = 0,
		kDictCollated = 1
	};

	enum Ordering
	{
		kLessThan = -1,
		kEqual = 0,
		kGreaterThan = 1,
		kNotOrderable = 2
	};

	using FcnPtr = void (*)();
};

#include "icarx/IcArxPackPop.h"

class AcRxClass;
using ArxAppNameChangeFuncPtr = void (*)(const AcRxClass* classObj, ACHAR*& newAppName, int saveVer);

#define NULLFCN nullptr

#define ACRX_ULONG_MAX 0xFFFFFFFF

#define ACRX_ASCII_MAX 255
#define ACRX_EOS 0

#ifndef kLoadADSMsg
#	define kLoadADSMsg kLoadDwgMsg
#	define kUnloadADSMsg kUnloadDwgMsg
#endif

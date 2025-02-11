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

#include "icarx/AcPlObject.h"

#define ACPL_DECLARE_MEMBERS(CLASS_NAME)                                                        \
private:                                                                                        \
	friend class AcPlSystemInternals;                                                           \
                                                                                                \
protected:                                                                                      \
	CLASS_NAME(AcPlSystemInternals*);                                                           \
                                                                                                \
public:                                                                                         \
	ACPL_PORT virtual AcRxClass* isA() const;                                                   \
	ACPL_PORT static AcRxClass* gpDesc;                                                         \
	ACPL_PORT static AcRxClass* desc();                                                         \
	ACPL_PORT static CLASS_NAME* cast(const AcRxObject* inPtr)                                  \
	{                                                                                           \
		return (!inPtr || !inPtr->isKindOf(CLASS_NAME::desc())) ? nullptr : (CLASS_NAME*)inPtr; \
	};                                                                                          \
	ACPL_PORT static void rxInit();                                                             \
	ACPL_PORT static void rxInit(ArxAppNameChangeFuncPtr);

#ifndef _ACPL_BUILD
#	define ACPL_NO_CONS_DEFINE_MEMBERS ACRX_NO_CONS_DEFINE_MEMBERS
#else
#	define ACPL_NO_CONS_DEFINE_MEMBERS ACRX_NO_CONS_DEFINE_MEMBERS_AUTO
#endif

#define ACPL_DEFINE_MEMBERS(CLASS_NAME, BASE_CLASS)     \
	ACPL_NO_CONS_DEFINE_MEMBERS(CLASS_NAME, BASE_CLASS) \
	CLASS_NAME::CLASS_NAME(AcPlSystemInternals* pInternals) : BASE_CLASS(pInternals) {}

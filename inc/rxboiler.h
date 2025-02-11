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

#include "AdAChar.h"
#include "rxnames.h"
#include "acbasedefs.h"

class AcRxClass;
class AcRxObject;

ACBASE_PORT AcRxClass* acrxFindAcRxClass(const ACHAR* pClassName);

extern "C" [[noreturn]] ACBASE_PORT void acrx_abort(const ACHAR* format, ...);

template<typename T>
static AcRxObject* acrxInstantiateClass()
{
	return new T();
}

#define ACRX_AUTO_INIT_QUEUE_EXPR(CLASS_NAME) \
	acrxQueueClassForInitialization(&CLASS_NAME::gpDesc, &CLASS_NAME::rxInit)

#ifdef ACRX_AUTO_INIT
#	define ACRX_AUTO_INIT_DEFAULT(CLASS_NAME) ACRX_AUTO_INIT_QUEUE_EXPR(CLASS_NAME)
#else
#	define ACRX_AUTO_INIT_DEFAULT(CLASS_NAME) nullptr
#endif

#define ACRX_DEFINE_GPDESC(CLASS_NAME, AUTOINIT) \
	AcRxClass* CLASS_NAME::gpDesc = AUTOINIT(CLASS_NAME);

#define ACRX_DECLARE_GPDESC(CLASS_NAME) static AcRxClass* gpDesc;

#define ACRX_DECLARE_MEMBERS_EXPIMP(CLASS_NAME, EXPIMP)                                           \
	friend AcRxObject* ::acrxInstantiateClass<CLASS_NAME>();                                      \
	EXPIMP AcRxClass* isA() const override;                                                       \
	ACRX_DECLARE_GPDESC(CLASS_NAME);                                                              \
	EXPIMP static AcRxClass* desc();                                                              \
	static CLASS_NAME* cast(const AcRxObject* inPtr)                                              \
	{                                                                                             \
		return ((!inPtr) || !inPtr->isKindOf(CLASS_NAME::desc())) ? nullptr : (CLASS_NAME*)inPtr; \
	};                                                                                            \
	static void rxInit();                                                                         \
	static void rxInit(ArxAppNameChangeFuncPtr);                                                  \
	static const wchar_t* className() { return ACRX_T(#CLASS_NAME); }

#define ACRX_EMPTY

#define ACRX_DECLARE_MEMBERS(CLASS_NAME) ACRX_DECLARE_MEMBERS_EXPIMP(CLASS_NAME, ACRX_EMPTY)

#define ACRX_DEFINE_MEMBERS_WORKER(CLASS_NAME, AUTOINIT)       \
	AcRxClass* CLASS_NAME::desc()                              \
	{                                                          \
		if (gpDesc == nullptr)                                 \
			gpDesc = ::acrxFindAcRxClass(ACRX_T(#CLASS_NAME)); \
		return gpDesc;                                         \
	}                                                          \
	AcRxClass* CLASS_NAME::isA() const                         \
	{                                                          \
		if (gpDesc == nullptr)                                 \
			gpDesc = ::acrxFindAcRxClass(ACRX_T(#CLASS_NAME)); \
		return gpDesc;                                         \
	}                                                          \
	ACRX_DEFINE_GPDESC(CLASS_NAME, AUTOINIT)

#define ACRX_DEFINE_MEMBERS(CLASS_NAME) \
	ACRX_DEFINE_MEMBERS_WORKER(CLASS_NAME, ACRX_AUTO_INIT_DEFAULT)

#define ACRX_STATIC_CHECK(CLASS_NAME)                                 \
	if (gpDesc != nullptr)                                            \
	{                                                                 \
		AcRxClass* pClass = ::acrxFindAcRxClass(ACRX_T(#CLASS_NAME)); \
		if (pClass)                                                   \
		{                                                             \
			if (gpDesc == pClass)                                     \
				return;                                               \
			else                                                      \
				acrx_abort(ACRX_T(/*MSGO*/ "Class mismatch"));        \
		}                                                             \
	}

#define ACRX_NO_CONS_DEFINE_MEMBERS_WORKER(AUTOINIT, CLASS_NAME, PARENT_CLASS) \
	ACRX_DEFINE_MEMBERS_WORKER(CLASS_NAME, AUTOINIT);                          \
	void CLASS_NAME::rxInit()                                                  \
	{                                                                          \
		ACRX_STATIC_CHECK(CLASS_NAME);                                         \
		gpDesc = newAcRxClass(ACRX_T(#CLASS_NAME), ACRX_T(#PARENT_CLASS));     \
	}

#define ACRX_NO_CONS_DEFINE_MEMBERS(CLASS_NAME, PARENT_CLASS) \
	ACRX_NO_CONS_DEFINE_MEMBERS_WORKER(ACRX_AUTO_INIT_DEFAULT, CLASS_NAME, PARENT_CLASS)

#define ACRX_NO_CONS_DEFINE_MEMBERS_AUTO(CLASS_NAME, PARENT_CLASS) \
	ACRX_NO_CONS_DEFINE_MEMBERS_WORKER(ACRX_AUTO_INIT_QUEUE_EXPR, CLASS_NAME, PARENT_CLASS)

#define ACRX_NO_CONS_DEFINE_MEMBERS_WITH_PROPERTIES_WORKER(AUTOINIT, CLASS_NAME, PARENT_CLASS, \
														   MAKEPROPS)                          \
	ACRX_DEFINE_MEMBERS(CLASS_NAME);                                                           \
	void CLASS_NAME::rxInit()                                                                  \
	{                                                                                          \
		ACRX_STATIC_CHECK(CLASS_NAME);                                                         \
		gpDesc = newAcRxClass(ACRX_T(#CLASS_NAME), ACRX_T(#PARENT_CLASS), 0, 0, 0, 0, 0, 0, 0, \
							  MAKEPROPS);                                                      \
	}
#define ACRX_NO_CONS_DEFINE_MEMBERS_WITH_PROPERTIES(CLASS_NAME, PARENT_CLASS, MAKEPROPS)   \
	ACRX_NO_CONS_DEFINE_MEMBERS_WITH_PROPERTIES_WORKER(ACRX_AUTO_INIT_DEFAULT, CLASS_NAME, \
													   PARENT_CLASS, MAKEPROPS)

#define ACRX_NO_CONS_DEFINE_MEMBERS_WITH_PROPERTIES_AUTO(CLASS_NAME, PARENT_CLASS, MAKEPROPS) \
	ACRX_NO_CONS_DEFINE_MEMBERS_WITH_PROPERTIES_WORKER(ACRX_AUTO_INIT_QUEUE_EXPR, CLASS_NAME, \
													   PARENT_CLASS, MAKEPROPS)

#define ACRX_CONS_DEFINE_MEMBERS_WORKER(AUTOINIT, CLASS_NAME, PARENT_CLASS, VERNO) \
	ACRX_DEFINE_MEMBERS_WORKER(CLASS_NAME, AUTOINIT);                              \
	void CLASS_NAME::rxInit()                                                      \
	{                                                                              \
		ACRX_STATIC_CHECK(CLASS_NAME);                                             \
		gpDesc = newAcRxClass(ACRX_T(#CLASS_NAME), ACRX_T(#PARENT_CLASS), VERNO,   \
							  &acrxInstantiateClass<CLASS_NAME>);                  \
	}
#define ACRX_CONS_DEFINE_MEMBERS(CLASS_NAME, PARENT_CLASS, VERNO) \
	ACRX_CONS_DEFINE_MEMBERS_WORKER(ACRX_AUTO_INIT_DEFAULT, CLASS_NAME, PARENT_CLASS, VERNO)

#define ACRX_CONS_DEFINE_MEMBERS_AUTO(CLASS_NAME, PARENT_CLASS, VERNO) \
	ACRX_CONS_DEFINE_MEMBERS_WORKER(ACRX_AUTO_INIT_QUEUE_EXPR, CLASS_NAME, PARENT_CLASS, VERNO)

#define ACRX_DXF_DEFINE_MEMBERS(CLASS_NAME, PARENT_CLASS, DWG_VERSION, MAINTENANCE_VERSION,        \
								PROXY_FLAGS, DXF_NAME, APP)                                        \
	ACRX_DEFINE_MEMBERS(CLASS_NAME);                                                               \
	void CLASS_NAME::rxInit()                                                                      \
	{                                                                                              \
		ACRX_STATIC_CHECK(CLASS_NAME);                                                             \
		gpDesc = newAcRxClass(ACRX_T(#CLASS_NAME), ACRX_T(#PARENT_CLASS), DWG_VERSION,             \
							  MAINTENANCE_VERSION, PROXY_FLAGS, &acrxInstantiateClass<CLASS_NAME>, \
							  ACRX_T(#DXF_NAME), ACRX_T(#APP));                                    \
	}                                                                                              \
	void CLASS_NAME::rxInit(ArxAppNameChangeFuncPtr ptr)                                           \
	{                                                                                              \
		ACRX_STATIC_CHECK(CLASS_NAME);                                                             \
		gpDesc = newAcRxClass(ACRX_T(#CLASS_NAME), ACRX_T(#PARENT_CLASS), DWG_VERSION,             \
							  MAINTENANCE_VERSION, PROXY_FLAGS, &acrxInstantiateClass<CLASS_NAME>, \
							  ACRX_T(#DXF_NAME), ACRX_T(#APP), ptr);                               \
	}

#define ACRX_DXF_DEFINE_MEMBERS_WITH_PROPERTIES(CLASS_NAME, PARENT_CLASS, DWG_VERSION,             \
												MAINTENANCE_VERSION, PROXY_FLAGS, DXF_NAME, APP,   \
												MAKEPROPS)                                         \
	ACRX_DEFINE_MEMBERS(CLASS_NAME);                                                               \
	void CLASS_NAME::rxInit()                                                                      \
	{                                                                                              \
		ACRX_STATIC_CHECK(CLASS_NAME);                                                             \
		gpDesc = newAcRxClass(ACRX_T(#CLASS_NAME), ACRX_T(#PARENT_CLASS), DWG_VERSION,             \
							  MAINTENANCE_VERSION, PROXY_FLAGS, &acrxInstantiateClass<CLASS_NAME>, \
							  ACRX_T(#DXF_NAME), ACRX_T(#APP), NULL, MAKEPROPS);                   \
	}                                                                                              \
	void CLASS_NAME::rxInit(ArxAppNameChangeFuncPtr ptr)                                           \
	{                                                                                              \
		ACRX_STATIC_CHECK(CLASS_NAME);                                                             \
		gpDesc = newAcRxClass(ACRX_T(#CLASS_NAME), ACRX_T(#PARENT_CLASS), DWG_VERSION,             \
							  MAINTENANCE_VERSION, PROXY_FLAGS, &acrxInstantiateClass<CLASS_NAME>, \
							  ACRX_T(#DXF_NAME), ACRX_T(#APP), ptr, MAKEPROPS);                    \
	}

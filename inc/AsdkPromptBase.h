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

#include "icarx/AsdkPromptBase.h"

#include <string.h>
#include "dbjig.h"
#include "adscodes.h"

BOOL acedSetIUnknownForCurrentCommand(const LPUNKNOWN);

#define BEGIN_PROMPT_MAP(CLASSNAME)                                                            \
public:                                                                                        \
	CLASSNAME()                                                                                \
	{                                                                                          \
		HRESULT hr = S_OK;                                                                     \
		if (FAILED(hr = m_pWrapperObject.CoCreateInstance(m_CLSID_ObjectWrapper)))             \
		{                                                                                      \
			acutPrintf(L"Unable to Create Wrapper Class\n");                                   \
			throw hr;                                                                          \
		}                                                                                      \
		m_pBaseObj = m_pWrapperObject;                                                         \
		if (FAILED(hr = m_pBaseObj->CreateObject()))                                           \
			throw hr;                                                                          \
		SetDocument(curDoc());                                                                 \
		CComPtr<IUnknown> pUnkCmd;                                                             \
		hr = QueryInterface(IID_IUnknown, (void**)&pUnkCmd);                                   \
		if (FAILED(hr))                                                                        \
			throw hr;                                                                          \
		CComQIPtr<IConnectionPointContainer> pPtContainer;                                     \
		pPtContainer = m_pWrapperObject;                                                       \
		hr = pPtContainer->FindConnectionPoint(IID_IPropertyNotifySink, &m_pConPt);            \
		if (FAILED(hr))                                                                        \
			throw hr;                                                                          \
                                                                                               \
		if (FAILED(hr = GetPropertyTypeInfo()))                                                \
		{                                                                                      \
			acutPrintf(L"Unable to Obtain Correct Type Information from the Wrapper Class\n"); \
			throw hr;                                                                          \
		}                                                                                      \
		if (FAILED(hr = m_pConPt->Advise(pUnkCmd, &m_dConnectionID)))                          \
			throw hr;                                                                          \
                                                                                               \
		BOOL bRet = acedSetIUnknownForCurrentCommand(m_pWrapperObject);                        \
		m_pDb = acdbHostApplicationServices()->workingDatabase();                              \
                                                                                               \
		AcDbObject* pObj = NULL;                                                               \
		m_pBaseObj->GetObject(pObj);                                                           \
		m_pDbrObject = pObj;                                                                   \
		AcDbEntity* pEnt = (AcDbEntity*)AcDbEntity::cast(pObj);                                \
		if (pEnt)                                                                              \
			pEnt->setDatabaseDefaults();                                                       \
		m_pBaseObj->SetObject(pObj);                                                           \
		constructorCallback();                                                                 \
		initSampler();                                                                         \
	}                                                                                          \
	~CLASSNAME()                                                                               \
	{                                                                                          \
		m_pConPt->Unadvise(m_dConnectionID);                                                   \
		if (m_pBaseObj)                                                                        \
			m_pBaseObj->GetObject(m_pDbrObject);                                               \
	}                                                                                          \
	HRESULT STDMETHODCALLTYPE QueryInterface(REFIID refiid, void** ppv)                        \
	{                                                                                          \
		if (refiid == IID_IUnknown || refiid == IID_IPropertyNotifySink)                       \
			*ppv = this;                                                                       \
		else                                                                                   \
			return (E_NOINTERFACE);                                                            \
		static_cast<IUnknown*>(this)->AddRef();                                                \
		return (S_OK);                                                                         \
	}                                                                                          \
	ULONG STDMETHODCALLTYPE AddRef() { return (InterlockedIncrement(&m_cRef)); }               \
	ULONG STDMETHODCALLTYPE Release()                                                          \
	{                                                                                          \
		ULONG ul = InterlockedDecrement(&m_cRef);                                              \
		return (ul);                                                                           \
	}                                                                                          \
	virtual PROMPT_MAP_ENTRY* GetPromptMap()                                                   \
	{                                                                                          \
		static PROMPT_MAP_ENTRY pPromptMap[] = {

#define PROMPT_ENTRY(szDesc, dispId, promptType, defaultValueId, promptId, bJigThisProperty) \
	{szDesc, dispId, promptType, 1, 0, 0, defaultValueId, promptId, bJigThisProperty},

#define PROMPT_ENTRY_INITGET(szDesc, dispId, promptType, initget, keywordsId, defaultValueId, \
							 promptId, bJigThisProperty)                                      \
	{szDesc,		 dispId,   promptType,		1, initget, keywordsId,                       \
	 defaultValueId, promptId, bJigThisProperty},

#define PROMPT_ENTRY_SYMBOL(szDesc, dispId, defaultValueId, promptId, bJigThisProperty) \
	{szDesc, dispId, RTSTR, 0, 0, 0, defaultValueId, promptId, bJigThisProperty},

#define END_PROMPT_MAP                                 \
	{                                                  \
		NULL, 0, 0, 0, 0, 0, 0, false, false, VT_EMPTY \
	}                                                  \
	}                                                  \
	;                                                  \
	return (pPromptMap);                               \
	}

#define DEFINE_SAMPLER(CURSORTYPE, USERINPUTCONTROLS) \
	virtual void initSampler()                        \
	{                                                 \
		m_jigCursorType = CURSORTYPE;                 \
		m_jigUserInputControls = USERINPUTCONTROLS;   \
	}

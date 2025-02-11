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
***     Description: Declaration of CAcExtensionModule class
***
*****************************************************************************/
#pragma once

#include "IcArxAssert.h"

#include "IcArxPackPush.h"

class CAcExtensionModule
{
protected:
	bool m_bAttached;
	HINSTANCE m_hDefaultResource;
	HINSTANCE m_hModuleResource;
	AFX_EXTENSION_MODULE m_module;

public:
	CAcExtensionModule();
	~CAcExtensionModule();

	bool Attached() const;
	bool AttachInstance(HINSTANCE hExtInst, HINSTANCE hResInst);
	bool AttachInstance(HINSTANCE hExtInst) { return this->AttachInstance(hExtInst, hExtInst); }
	HINSTANCE DefaultResourceInstance() const;
	void DetachInstance();
	HINSTANCE ModuleResourceInstance() const;
};

#include "IcArxPackPop.h"

inline CAcExtensionModule::CAcExtensionModule()
		: m_bAttached(false), m_hDefaultResource(nullptr), m_hModuleResource(nullptr)
{
	m_module.bInitialized = FALSE;
	m_module.hModule = nullptr;
	m_module.hResource = nullptr;
	m_module.pFirstSharedClass = nullptr;
	m_module.pFirstSharedFactory = nullptr;
}

inline CAcExtensionModule::~CAcExtensionModule()
{
}

inline bool CAcExtensionModule::Attached() const
{
	return m_bAttached;
}

inline bool CAcExtensionModule::AttachInstance(HINSTANCE hExtInst, HINSTANCE hResInst)
{
	ICARX_ASSERT(hExtInst != nullptr);
	ICARX_ASSERT(hResInst != nullptr);
	if (m_bAttached)
		return false;
	ICARX_ASSERT(!m_module.bInitialized);
	m_bAttached = AfxInitExtensionModule(m_module, hExtInst) != 0;
	ICARX_ASSERT(this->m_hDefaultResource == nullptr);
	ICARX_ASSERT(this->m_hModuleResource == nullptr);
	if (m_bAttached)
	{
		this->m_hDefaultResource = ::AfxGetResourceHandle();
		this->m_hModuleResource = hResInst;
		ICARX_ASSERT(this->m_module.hModule == hExtInst);
		ICARX_ASSERT(this->m_module.hResource == hExtInst);
		this->m_module.hResource = hResInst;
		new CDynLinkLibrary(m_module);
	}
	return m_bAttached;
}

inline HINSTANCE CAcExtensionModule::DefaultResourceInstance() const
{
	return m_hDefaultResource;
}

inline void CAcExtensionModule::DetachInstance()
{
	if (m_bAttached)
	{
		AfxTermExtensionModule(m_module);
		this->m_hDefaultResource = nullptr;
		this->m_hModuleResource = nullptr;
		m_bAttached = FALSE;
	}
}

inline HINSTANCE CAcExtensionModule::ModuleResourceInstance() const
{
	return m_hModuleResource;
}

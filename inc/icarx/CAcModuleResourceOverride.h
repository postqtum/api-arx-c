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
***     Description: Declaration of CAcModuleResourceOverride class
***
*****************************************************************************/
#pragma once

#include "CAcExtensionModule.h"
#include "IcArxAssert.h"

#include "IcArxPackPush.h"

class CAcModuleResourceOverride
{
private:
	static CAcExtensionModule& m_extensionModule;
	HINSTANCE m_previousResourceInstance;

public:
	CAcModuleResourceOverride();
	CAcModuleResourceOverride(HINSTANCE hInst);
	~CAcModuleResourceOverride();

	static HINSTANCE ResourceInstance() { return m_extensionModule.ModuleResourceInstance(); }
};

#include "IcArxPackPop.h"

inline CAcModuleResourceOverride::CAcModuleResourceOverride() : CAcModuleResourceOverride(nullptr)
{
}

inline CAcModuleResourceOverride::CAcModuleResourceOverride(HINSTANCE hInst)
{
	m_previousResourceInstance = AfxGetResourceHandle();
	HINSTANCE hInstanceToSet = m_extensionModule.ModuleResourceInstance();
	if (hInst)
		hInstanceToSet = hInst;
	AfxSetResourceHandle(hInstanceToSet);
}

inline CAcModuleResourceOverride::~CAcModuleResourceOverride()
{
	ICARX_ASSERT(m_previousResourceInstance);
	AfxSetResourceHandle(m_previousResourceInstance);
	m_previousResourceInstance = nullptr;
}

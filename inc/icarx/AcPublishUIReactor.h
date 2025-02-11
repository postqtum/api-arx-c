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
***     Description: Declaration of AcPublishUIReactor class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "AcNameValuePair.h"

class AcPublishUIReactorInfo;
struct IUnknown;

#include "IcArxPackPush.h"

class AcPublishUIReactor : public AcRxObject
{
protected:
	AcPublishUIReactor() = default;

public:
	~AcPublishUIReactor() = default;

	virtual void OnInitAutoPublishSettingsDialog(IUnknown** pUnk, AcPublishUIReactorInfo* pInfo) {}
	virtual void OnInitExportOptionsDialog(IUnknown** pUnk, AcPublishUIReactorInfo* pInfo) {}
	virtual void OnInitPublishOptionsDialog(IUnknown** pUnk, AcPublishUIReactorInfo* pInfo) {}
	virtual void PersistenceRegistryForAutoPublishDialog(const ACHAR* lpszRegRoot,
														 bool bIsReadRegistry)
	{
	}
	virtual void PersistenceRegistryForExportOptionsDialog(const ACHAR* lpszRegRoot,
														   bool bIsReadRegistry)
	{
	}
	virtual void PersistenceRegistryForPublishOptionsDialog(const ACHAR* lpszRegRoot,
															bool bIsReadRegistry)
	{
	}
};

#include "IcArxPackPop.h"

void AcGlobAddPublishUIReactor(AcPublishUIReactor* pReactor);

void AcGlobRemovePublishUIReactor(AcPublishUIReactor* pReactor);

typedef void(__cdecl* ACGLOBADDPUBLISHUIREACTOR)(AcPublishUIReactor* pReactor);
typedef void(__cdecl* ACGLOBREMOVEPUBLISHUIREACTOR)(AcPublishUIReactor* pReactor);

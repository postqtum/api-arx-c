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
***     Description: Declaration of AcPublishReactor class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"

class AcPublishBeforeJobInfo;
class AcPublishBeginJobInfo;
class AcPublishSheetInfo;
class AcPublishAggregationInfo;
class AcPublishReactorInfo;

#include "IcArxPackPush.h"

class AcPublishReactor : public AcRxObject
{
protected:
	AcPublishReactor() = default;

public:
	~AcPublishReactor() = default;

	virtual void OnAboutToBeginBackgroundPublishing(AcPublishBeforeJobInfo* pInfo) {}
	virtual void OnAboutToBeginPublishing(AcPublishBeginJobInfo* pInfo) {}
	virtual void OnAboutToEndPublishing(AcPublishReactorInfo* pInfo) {}
	virtual void OnAboutToMoveFile(AcPublishReactorInfo* pInfo) {}
	virtual void OnBeginAggregation(AcPublishAggregationInfo* pInfo) {}
	virtual void OnBeginPublishingSheet(AcPublishSheetInfo* pInfo) {}
	virtual void OnCancelledOrFailedPublishing(AcPublishReactorInfo* pInfo) {}
	virtual void OnEndPublish(AcPublishReactorInfo* pInfo) {}
};

#include "IcArxPackPop.h"

void AcGlobAddPublishReactor(AcPublishReactor* pReactor);

void AcGlobRemovePublishReactor(AcPublishReactor* pReactor);

typedef void(__cdecl* ACGLOBADDPUBLISHREACTOR)(AcPublishReactor* pReactor);
typedef void(__cdecl* ACGLOBREMOVEPUBLISHREACTOR)(AcPublishReactor* pReactor);

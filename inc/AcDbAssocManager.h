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
***     Description: Declaration of AcDbAssocManager class
***
*****************************************************************************/
#pragma once

#include "AcString.h"
#include "AcDbAssocGlobal.h"

#include "icarx/AcDbObject.h"

#include "icarx/IcArxPackPush.h"
#pragma warning(disable : 4275)

class ACDBCORE2D_PORT AcDbAssocManager : public AcDbObject
{
public:
	ACRX_DECLARE_MEMBERS(AcDbAssocManager);

	AcDbAssocManager();

	static Acad::ErrorStatus addGlobalEvaluationCallback(AcDbAssocEvaluationCallback* pCallback,
														 int order);
	static Acad::ErrorStatus auditAssociativeData(AcDbDatabase* pDatabase,
												  bool traverseWholeDatabase);
	static AcDbObjectId currentlyEvaluatedAction(const AcDbDatabase*);
	static void enableProgressMeter(bool enableIt, const AcString& progressLabel = AcString());
	static bool evaluateTopLevelNetwork(AcDbDatabase* pDatabase,
										AcDbAssocEvaluationCallback* pCallback = nullptr,
										int callbackOrder = 0);
	static AcDbAssocEvaluationCallback* getCurrentEvaluationCallback(const AcDbDatabase*);
	static void getGlobalEvaluationCallbacks(AcArray<AcDbAssocEvaluationCallback*>& callbacks,
											 AcArray<int>& orders);
	static AcDbAssocEvaluationCallback* globalEvaluationMultiCallback();
	static bool hasAssocNetwork(const AcDbDatabase* pDatabase);
	static Acad::ErrorStatus initialize();
	static bool isActionEvaluationInProgress(const AcDbDatabase*);
	static Acad::ErrorStatus markSyncUpWithXrefsNeeded(AcDbDatabase* pDatabase);
	static Acad::ErrorStatus removeGlobalEvaluationCallback(AcDbAssocEvaluationCallback* pCallback);
	static Acad::ErrorStatus requestToEvaluate(
			const AcDbObjectId& objectId, AcDbAssocStatus newStatus = kChangedDirectlyAssocStatus,
			bool ownedActionsAlso = true);
	static Acad::ErrorStatus syncUpWithXrefs(AcDbDatabase* pHostDatabase);
	static void uninitialize();
};

class ACDBCORE2D_PORT AcDbAssocNetworkEvaluationDisabler
{
private:
	AcDbDatabase* mpDatabase = nullptr;
	bool mPreviouslyDisabled = false;

public:
	explicit AcDbAssocNetworkEvaluationDisabler(AcDbDatabase*, bool disableIt = true);
	~AcDbAssocNetworkEvaluationDisabler();

	static bool isDisabled(const AcDbDatabase*);
};

#include "icarx/IcArxPackPop.h"

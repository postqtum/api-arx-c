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

#include "AcDbAssocGlobal.h"
#include "AcValue.h"

#include "icarx/AcDbEvalVariant.h"
#include "icarx/AcDbObject.h"

#include "icarx/IcArxPackPush.h"

class AcDbAssocAction : public AcDbObject
{
	friend class AcDbImpAssocAction;

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbAssocAction, ACDBCORE2D_PORT);

public:
	ACDBCORE2D_PORT explicit AcDbAssocAction(AcDbAssocCreateImpObject createImpObject = kAcDbAssocCreateImpObject);

	ACDBCORE2D_PORT AcDbObjectId actionBody() const;
	ACDBCORE2D_PORT static AcDbObjectId actionBody(const AcDbObjectId& actionId);
	ACDBCORE2D_PORT Acad::ErrorStatus addDependency(const AcDbObjectId& dependencyId,
									bool setThisActionAsOwningAction = true);
	ACDBCORE2D_PORT Acad::ErrorStatus addDependency(AcRxClass* pDependencyClass, AcRxClass* pDependencyBodyClass,
									bool isReadDep, bool isWriteDep, int order,
									AcDbObjectId& dependencyId);
	ACDBCORE2D_PORT Acad::ErrorStatus addMoreObjectsToDeepClone(AcDbIdMapping& idMap,
												AcDbObjectIdArray& additionalObjectsToClone) const;
	ACDBCORE2D_PORT Acad::ErrorStatus addParam(const AcDbObjectId& paramId, int& paramIndex);
	ACDBCORE2D_PORT Acad::ErrorStatus addParam(const AcString& paramName, AcRxClass* pParamClass,
							   AcDbObjectId& paramId, int& paramIndex);
	ACDBCORE2D_PORT bool areDependenciesEqual(const AcDbAssocDependency* pDependency1,
							  const AcDbAssocDependency* pDependency2) const;
	ACDBCORE2D_PORT bool areDependenciesOnTheSameThing(const AcDbAssocDependency* pDependency1,
									   const AcDbAssocDependency* pDependency2) const;
	ACDBCORE2D_PORT AcDbAssocEvaluationCallback* currentEvaluationCallback() const;
	ACDBCORE2D_PORT void dependentObjectCloned(const AcDbAssocDependency* pDependency, const AcDbObject* pDbObj,
							   const AcDbObject* pNewObj);
	ACDBCORE2D_PORT static bool doesObjectHaveActiveActions(const AcDbObject* pObject);
	ACDBCORE2D_PORT void dragStatus(const AcDb::DragStat status);
	ACDBCORE2D_PORT void evaluate(AcDbAssocEvaluationCallback* pEvaluationCallback);
	ACDBCORE2D_PORT Acad::ErrorStatus evaluateDependencies();
	ACDBCORE2D_PORT void evaluateDependency(AcDbAssocDependency* pDependency);
	ACDBCORE2D_PORT AcDbAssocEvaluationPriority evaluationPriority() const;
	ACDBCORE2D_PORT static Acad::ErrorStatus getActionsDependentOnObject(const AcDbObject* pObject,
														 bool readDependenciesWanted,
														 bool writeDependenciesWanted,
														 AcDbObjectIdArray& actionIds);
	ACDBCORE2D_PORT Acad::ErrorStatus getDependencies(bool readDependenciesWanted, bool writeDependenciesWanted,
									  AcDbObjectIdArray& dependencyIds) const;
	ACDBCORE2D_PORT void getDependentActionsToEvaluate(
			AcDbActionsToEvaluateCallback* pActionsToEvaluateCallback) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getDependentObjects(bool readDependenciesWanted, bool writeDependenciesWanted,
										  AcDbObjectIdArray& objectIds) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getValueParam(const AcString& paramName, AcDbEvalVariant& value,
									AcString& expression, AcString& evaluatorId,
									int valueIndex = 0) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getValueParamArray(const AcString& paramName,
										 AcArray<AcDbEvalVariant>& values,
										 AcArray<AcString>& expressions,
										 AcArray<AcString>& evaluatorIds) const;
	ACDBCORE2D_PORT bool hasDependencyCachedValue(const AcDbAssocDependency* pDependency) const;
	ACDBCORE2D_PORT bool isActionBodyAProxy() const;
	ACDBCORE2D_PORT bool isActionEvaluationInProgress() const;
	ACDBCORE2D_PORT bool isEqualTo(const AcDbAssocAction* pOtherAction) const;
	ACDBCORE2D_PORT bool isExternalDependency(const AcDbAssocDependency* pDependency) const;
	ACDBCORE2D_PORT bool isOwnedDependency(const AcDbAssocDependency* pDependency) const;
	ACDBCORE2D_PORT bool isRelevantDependencyChange(const AcDbAssocDependency* pDependency) const;
	ACDBCORE2D_PORT static Acad::ErrorStatus markDependentActionsToEvaluate(const AcDbObjectId& actionId);
	ACDBCORE2D_PORT Acad::ErrorStatus notification(AcDbAssocNotificationData* pNotifData);
	ACDBCORE2D_PORT AcDbObjectId objectThatOwnsNetworkInstance() const;
	ACDBCORE2D_PORT Acad::ErrorStatus ownedDependencyStatusChanged(AcDbAssocDependency* pOwnedDependency,
												   AcDbAssocStatus previousStatus);
	ACDBCORE2D_PORT const AcDbObjectIdArray& ownedParams() const;
	ACDBCORE2D_PORT void ownedValueParamNames(AcArray<AcString>& paramNames) const;
	ACDBCORE2D_PORT AcDbObjectId owningNetwork() const;
	ACDBCORE2D_PORT AcDbObjectId paramAtIndex(int paramIndex) const;
	ACDBCORE2D_PORT AcDbObjectId paramAtName(const AcString& paramName, int index = 0) const;
	ACDBCORE2D_PORT int paramCount() const;
	ACDBCORE2D_PORT const AcDbObjectIdArray& paramsAtName(const AcString& paramName) const;
	ACDBCORE2D_PORT Acad::ErrorStatus postProcessAfterDeepClone(AcDbIdMapping& idMap);
	ACDBCORE2D_PORT Acad::ErrorStatus postProcessAfterDeepCloneCancel(AcDbIdMapping& idMap);
	ACDBCORE2D_PORT static Acad::ErrorStatus removeActionsControllingObject(
			const AcDbObjectId& objectToRemoveActionsFrom, int readOnlyDependencyHandling = 0,
			const AcDbObjectId& objectToRedirectReadOnlyDependenciesTo = AcDbObjectId::kNull);
	ACDBCORE2D_PORT Acad::ErrorStatus removeAllDependencies(bool alsoEraseThem);
	ACDBCORE2D_PORT Acad::ErrorStatus removeAllParams(bool alsoEraseThem);
	ACDBCORE2D_PORT Acad::ErrorStatus removeDependency(const AcDbObjectId& dependencyId, bool alsoEraseIt);
	ACDBCORE2D_PORT Acad::ErrorStatus removeParam(const AcDbObjectId& paramId, bool alsoEraseIt);
	ACDBCORE2D_PORT Acad::ErrorStatus removeValueParam(const AcString& paramName);
	ACDBCORE2D_PORT Acad::ErrorStatus scaleAllDistanceValueParams(double scaleFactor);
	ACDBCORE2D_PORT Acad::ErrorStatus setActionBody(const AcDbObjectId& actionBodyId);
	ACDBCORE2D_PORT Acad::ErrorStatus setOwningNetwork(const AcDbObjectId& networkId, bool alsoSetAsDatabaseOwner);
	ACDBCORE2D_PORT Acad::ErrorStatus setStatus(AcDbAssocStatus newStatus, bool notifyOwningNetwork = true,
								bool setInOwnedActions = false);
	ACDBCORE2D_PORT Acad::ErrorStatus setValueParam(const AcString& paramName, const AcDbEvalVariant& value,
									const AcString& expression, const AcString& evaluatorId,
									AcString& errorMessage, bool silentMode, int valueIndex = 0);
	ACDBCORE2D_PORT Acad::ErrorStatus setValueParamArray(const AcString& paramName,
										 const AcArray<AcDbEvalVariant>& values,
										 const AcArray<AcString>& expressions,
										 const AcArray<AcString>& evaluatorIds,
										 AcArray<AcString>& errorMessages, bool silentMode);
	ACDBCORE2D_PORT Acad::ErrorStatus setValueParamControlledObjectDep(const AcString& paramName,
													   const AcDbObjectId& controlledObjectDepId);
	ACDBCORE2D_PORT Acad::ErrorStatus setValueParamUnitType(const AcString& paramName, AcValue::UnitType unitType);
	ACDBCORE2D_PORT AcDbAssocStatus status() const;
	ACDBCORE2D_PORT Acad::ErrorStatus transformActionBy(const AcGeMatrix3d& transform);
	ACDBCORE2D_PORT Acad::ErrorStatus transformAllConstantGeometryParams(const AcGeMatrix3d& transform);
	ACDBCORE2D_PORT Acad::ErrorStatus updateAllObjectsControlledByValueParams() const;
	ACDBCORE2D_PORT Acad::ErrorStatus updateValueParamControlledObject(const AcString& paramName) const;
	ACDBCORE2D_PORT Acad::ErrorStatus updateValueParamFromControlledObject(const AcString& paramName);
	ACDBCORE2D_PORT Acad::ErrorStatus valueParamInputVariables(const AcString& paramName,
											   AcDbObjectIdArray& variableIds) const;
	ACDBCORE2D_PORT AcValue::UnitType valueParamUnitType(const AcString& paramName) const;
};

#include "icarx/IcArxPackPop.h"

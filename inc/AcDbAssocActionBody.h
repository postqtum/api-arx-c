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
***     Description: Declaration of AcDbAssocActionBody class
***
*****************************************************************************/
#pragma once

#include "AcDbAssocAction.h"

#include "dbeval.h" // Expected by entity/AssocFillet sample

#include "icarx/IcArxPackPush.h"

class AcDbAssocActionBody : public AcDbObject
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbAssocActionBody, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT explicit AcDbAssocActionBody(
			AcDbAssocCreateImpObject createImpObject = kAcDbAssocCreateImpObject);
	ACDBCORE2D_PORT ~AcDbAssocActionBody();

	ACDBCORE2D_PORT Acad::ErrorStatus addDependency(const AcDbObjectId& dependencyId,
													bool setThisActionAsOwningAction = true) const;
	ACDBCORE2D_PORT Acad::ErrorStatus addDependency(AcRxClass* pDependencyClass,
													AcRxClass* pDependencyBodyClass, bool isReadDep,
													bool isWriteDep, int order,
													AcDbObjectId& dependencyId) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus addMoreObjectsToDeepCloneOverride(
			AcDbIdMapping&, AcDbObjectIdArray&) const
	{
		return Acad::eNotImplemented;
	}
	ACDBCORE2D_PORT Acad::ErrorStatus addParam(const AcDbObjectId& paramId, int& paramIndex) const;
	ACDBCORE2D_PORT Acad::ErrorStatus addParam(const AcString& paramName, AcRxClass* pParamClass,
											   AcDbObjectId& paramId, int& paramIndex) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus areDependenciesEqualOverride(
			const AcDbAssocDependency* pDependency1, const AcDbAssocDependency* pDependency2,
			bool& areEqual) const
	{
		(void)(pDependency1);
		(void)(pDependency2);
		(void)(areEqual);
		return Acad::eNotImplemented;
	}
	ACDBCORE2D_PORT virtual Acad::ErrorStatus areDependenciesOnTheSameThingOverride(
			const AcDbAssocDependency* pDependency1, const AcDbAssocDependency* pDependency2,
			bool& areDependentOnSameThing) const
	{
		(void)(pDependency1);
		(void)(pDependency2);
		(void)(areDependentOnSameThing);
		return Acad::eNotImplemented;
	}
	ACDBCORE2D_PORT virtual void auditAssociativeDataOverride(
			AcDbAssocStatus& parentActionHandling);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus clonePersSubentNamingDataOverride(
			class AcDbAssocPersSubentManagerCloner* pCloner);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus collectPersSubentNamingDataOverride(
			AcDbPersStepIdArray& stepIds, AcDbPersSubentIdArray& persSubentIds) const;
	ACDBCORE2D_PORT static Acad::ErrorStatus createActionAndActionBodyAndPostToDatabase(
			AcRxClass* pActionBodyClass, const AcDbObjectId& objectId,
			AcDbObjectId& createdActionId, AcDbObjectId& createdActionBodyId);
	ACDBCORE2D_PORT AcDbAssocEvaluationCallback* currentEvaluationCallback() const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus dependentObjectClonedOverride(
			const AcDbAssocDependency* pDependency, const AcDbObject* pDbObj,
			const AcDbObject* pNewObj)
	{
		(void)(pDependency);
		(void)(pDbObj);
		(void)(pNewObj);
		return Acad::eNotImplemented;
	}
	ACDBCORE2D_PORT virtual Acad::ErrorStatus dragStatusOverride(const AcDb::DragStat status)
	{
		(void)(status);
		return Acad::eNotImplemented;
	}
	ACDBCORE2D_PORT Acad::ErrorStatus evaluateDependencies() const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus evaluateDependencyOverride(
			AcDbAssocDependency* pDependency)
	{
		(void)(pDependency);
		return Acad::eNotImplemented;
	}
	ACDBCORE2D_PORT virtual void evaluateOverride() = 0;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus evaluationPriorityOverride(
			AcDbAssocEvaluationPriority& priority) const
	{
		(void)(priority);
		return Acad::eNotImplemented;
	}
	ACDBCORE2D_PORT static Acad::ErrorStatus getActionBodiesOnObject(
			const AcDbObject* pObject, bool ignoreInternalActions, bool ignoreSuppressedActions,
			AcDbObjectId* pWriteOnlyActionBodyId, AcDbObjectIdArray* pReadWriteActionBodyIds,
			AcDbObjectIdArray* pReadOnlyActionBodyIds = nullptr);
	ACDBCORE2D_PORT Acad::ErrorStatus getDependencies(bool readDependenciesWanted,
													  bool writeDependenciesWanted,
													  AcDbObjectIdArray& dependencyIds) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getDependenciesOverride(
			bool readDependenciesWanted, bool writeDependenciesWanted,
			AcDbObjectIdArray& dependencyIds) const
	{
		(void)(readDependenciesWanted);
		(void)(writeDependenciesWanted);
		(void)(dependencyIds);
		return Acad::eNotImplemented;
	}
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getDependentActionsToEvaluateOverride(
			AcDbActionsToEvaluateCallback* pActionsToEvaluateCallback) const
	{
		(void)(pActionsToEvaluateCallback);
		return Acad::eNotImplemented;
	}
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getDependentObjectsOverride(
			bool readDependenciesWanted, bool writeDependenciesWanted,
			AcDbObjectIdArray& objectIds) const
	{
		(void)(readDependenciesWanted);
		(void)(writeDependenciesWanted);
		(void)(objectIds);
		return Acad::eNotImplemented;
	}
	ACDBCORE2D_PORT Acad::ErrorStatus getValueParam(const AcString& paramName,
													AcDbEvalVariant& value, AcString& expression,
													AcString& evaluatorId,
													int valueIndex = 0) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getValueParamArray(const AcString& paramName,
														 AcArray<AcDbEvalVariant>& values,
														 AcArray<AcString>& expressions,
														 AcArray<AcString>& evaluatorIds) const;
	ACDBCORE2D_PORT bool hasAnyErasedOrBrokenDependencies() const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus hasDependencyCachedValueOverride(
			const AcDbAssocDependency* pDependency, bool& hasDepCachedValue) const
	{
		(void)(pDependency);
		(void)(hasDepCachedValue);
		return Acad::eNotImplemented;
	}
	ACDBCORE2D_PORT bool isActionEvaluationInProgress() const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus isEqualToOverride(const AcDbAssocAction* pOtherAction,
																bool& isEqual) const
	{
		(void)(pOtherAction);
		(void)(isEqual);
		return Acad::eNotImplemented;
	}
	ACDBCORE2D_PORT virtual Acad::ErrorStatus isExternalDependencyOverride(
			const AcDbAssocDependency* pDependency, bool& isExternalDependency) const
	{
		(void)(pDependency);
		(void)(isExternalDependency);
		return Acad::eNotImplemented;
	}
	ACDBCORE2D_PORT virtual Acad::ErrorStatus isOwnedDependencyOverride(
			const AcDbAssocDependency* pDependency, bool& isOwnedDependency) const
	{
		(void)(pDependency);
		(void)(isOwnedDependency);
		return Acad::eNotImplemented;
	}
	ACDBCORE2D_PORT virtual Acad::ErrorStatus isRelevantDependencyChangeOverride(
			const AcDbAssocDependency* pDependency, bool& isRelevantDepChange) const
	{
		(void)(pDependency);
		(void)(isRelevantDepChange);
		return Acad::eNotImplemented;
	}
	ACDBCORE2D_PORT virtual Acad::ErrorStatus notificationOverride(
			class AcDbAssocNotificationData* pNotificationData);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus ownedDependencyStatusChangedOverride(
			AcDbAssocDependency* pOwnedDependency, AcDbAssocStatus previousStatus)
	{
		(void)(pOwnedDependency);
		(void)(previousStatus);
		return Acad::eNotImplemented;
	}
	ACDBCORE2D_PORT const AcDbObjectIdArray& ownedParams() const;
	ACDBCORE2D_PORT void ownedValueParamNames(AcArray<AcString>& paramNames) const;
	ACDBCORE2D_PORT AcDbObjectId owningNetwork() const;
	ACDBCORE2D_PORT AcDbObjectId paramAtIndex(int paramIndex) const;
	ACDBCORE2D_PORT AcDbObjectId paramAtName(const AcString& paramName, int index = 0) const;
	ACDBCORE2D_PORT int paramCount() const;
	ACDBCORE2D_PORT const AcDbObjectIdArray& paramsAtName(const AcString& paramName) const;
	ACDBCORE2D_PORT static AcDbObjectId parentAction(const AcDbObjectId& actionBodyId);
	ACDBCORE2D_PORT AcDbObjectId parentAction() const { return this->ownerId(); }
	ACDBCORE2D_PORT virtual Acad::ErrorStatus postProcessAfterDeepCloneCancelOverride(
			AcDbIdMapping&)
	{
		return Acad::eNotImplemented;
	}
	ACDBCORE2D_PORT virtual Acad::ErrorStatus postProcessAfterDeepCloneOverride(AcDbIdMapping&)
	{
		return Acad::eNotImplemented;
	}
	ACDBCORE2D_PORT virtual Acad::ErrorStatus removeActionsControllingObjectOverride(
			AcDbObject* pControlledObject)
	{
		(void)(pControlledObject);
		return Acad::eNotImplemented;
	}
	ACDBCORE2D_PORT Acad::ErrorStatus removeAllDependencies(bool alsoEraseThem) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus removeAllDependenciesOverride(bool alsoEraseThem)
	{
		(void)(alsoEraseThem);
		return Acad::eNotImplemented;
	}
	ACDBCORE2D_PORT Acad::ErrorStatus removeAllParams(bool alsoEraseThem) const;
	ACDBCORE2D_PORT Acad::ErrorStatus removeDependency(const AcDbObjectId& dependencyId,
													   bool alsoEraseIt) const;
	ACDBCORE2D_PORT Acad::ErrorStatus removeParam(const AcDbObjectId& paramId,
												  bool alsoEraseIt) const;
	ACDBCORE2D_PORT Acad::ErrorStatus removeValueParam(const AcString& paramName) const;
	ACDBCORE2D_PORT Acad::ErrorStatus scaleAllDistanceValueParams(double scaleFactor) const;
	ACDBCORE2D_PORT Acad::ErrorStatus setStatus(AcDbAssocStatus newStatus,
												bool notifyOwningNetwork = true,
												bool setInOwnedActions = false) const;
	ACDBCORE2D_PORT Acad::ErrorStatus setValueParam(const AcString& paramName,
													const AcDbEvalVariant& value,
													const AcString& expression,
													const AcString& evaluatorId,
													AcString& errorMessage, bool silentMode,
													int valueIndex = 0) const;
	ACDBCORE2D_PORT Acad::ErrorStatus setValueParamArray(const AcString& paramName,
														 const AcArray<AcDbEvalVariant>& values,
														 const AcArray<AcString>& expressions,
														 const AcArray<AcString>& evaluatorIds,
														 AcArray<AcString>& errorMessages,
														 bool silentMode) const;
	ACDBCORE2D_PORT Acad::ErrorStatus setValueParamControlledObjectDep(
			const AcString& paramName, const AcDbObjectId& controlledObjectDepId) const;
	ACDBCORE2D_PORT Acad::ErrorStatus setValueParamUnitType(const AcString& paramName,
															AcValue::UnitType unitType) const;
	ACDBCORE2D_PORT AcDbAssocStatus status() const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus transformActionByOverride(const AcGeMatrix3d&)
	{
		return Acad::eNotImplemented;
	}
	ACDBCORE2D_PORT Acad::ErrorStatus transformAllConstantGeometryParams(
			const AcGeMatrix3d& transform) const;
	ACDBCORE2D_PORT Acad::ErrorStatus updateAllObjectsControlledByValueParams() const;
	ACDBCORE2D_PORT Acad::ErrorStatus updateValueParamControlledObject(
			const AcString& paramName) const;
	ACDBCORE2D_PORT Acad::ErrorStatus updateValueParamFromControlledObject(
			const AcString& paramName) const;
	ACDBCORE2D_PORT Acad::ErrorStatus valueParamInputVariables(
			const AcString& paramName, AcDbObjectIdArray& variableIds) const;
	ACDBCORE2D_PORT AcValue::UnitType valueParamUnitType(const AcString& paramName) const;
};

#include "icarx/IcArxPackPop.h"

ACDBCORE2D_PORT AcString& dummyString();

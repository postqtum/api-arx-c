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
***     Description: Declaration of AcDbAssocDependency class
***
*****************************************************************************/
#pragma once

#include "AcDbAssocGlobal.h"
#include "AcDbCompoundObjectId.h"
#include "icarx/AcDbObject.h"

#include "icarx/IcArxPackPush.h"

class AcDbAssocDependency : public AcDbObject
{
	friend class AcDbImpAssocDependency;
	friend class AcDbAssocDeepCloneRxEventReactor;
	friend class AcDbAssocDeepCloneData;

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbAssocDependency, ACDBCORE2D_PORT);

public:
	ACDBCORE2D_PORT explicit AcDbAssocDependency(
			AcDbAssocCreateImpObject createImpObject = kAcDbAssocCreateImpObject);

	ACDBCORE2D_PORT Acad::ErrorStatus attachToObject(const AcDbCompoundObjectId& compoundId);
	ACDBCORE2D_PORT void copied(const AcDbObject* pDbObj, const AcDbObject* pNewObj) override;
	ACDBCORE2D_PORT AcDbAssocEvaluationCallback* currentEvaluationCallback() const;
	ACDBCORE2D_PORT AcDbObjectId dependencyBody() const;
	ACDBCORE2D_PORT AcDbObjectId dependentOnObject() const;
	ACDBCORE2D_PORT Acad::ErrorStatus dependentOnObjectStatus() const;
	ACDBCORE2D_PORT Acad::ErrorStatus detachFromObject();
	ACDBCORE2D_PORT void erased(const AcDbObject* dbObj, bool isErasing = true) override;
	ACDBCORE2D_PORT void evaluate();
	ACDBCORE2D_PORT static Acad::ErrorStatus getDependenciesOnObject(const AcDbObject* pObject,
													 bool readDependenciesWanted,
													 bool writeDependenciesWanted,
													 AcDbObjectIdArray& dependencyIds);
	ACDBCORE2D_PORT Acad::ErrorStatus getDependentOnCompoundObject(AcDbCompoundObjectId& compoundId) const;
	ACDBCORE2D_PORT static Acad::ErrorStatus getFirstDependencyOnObject(const AcDbObject* pObject,
														AcDbObjectId& firstDependencyId);
	ACDBCORE2D_PORT bool hasCachedValue() const;
	ACDBCORE2D_PORT bool isActionEvaluationInProgress() const;
	ACDBCORE2D_PORT bool isAttachedToObject() const { return !this->dependentOnObject().isNull(); }
	ACDBCORE2D_PORT bool isDelegatingToOwningAction() const;
	ACDBCORE2D_PORT bool isDependentOnCompoundObject() const;
	ACDBCORE2D_PORT bool isDependentOnObjectReadOnly() const;
	ACDBCORE2D_PORT bool isDependentOnTheSameThingAs(const AcDbAssocDependency* pOtherDependency) const;
	ACDBCORE2D_PORT bool isEqualTo(const AcDbAssocDependency* pOtherDependency) const;
	ACDBCORE2D_PORT bool isObjectStateDependent() const;
	ACDBCORE2D_PORT bool isReadDependency() const;
	ACDBCORE2D_PORT bool isRelevantChange() const;
	ACDBCORE2D_PORT bool isWriteDependency() const;
	ACDBCORE2D_PORT void modified(const AcDbObject* dbObj) override;
	ACDBCORE2D_PORT AcDbObjectId nextDependencyOnObject() const;
	ACDBCORE2D_PORT Acad::ErrorStatus notification(AcDbAssocNotificationData* pNotifData);
	ACDBCORE2D_PORT static Acad::ErrorStatus notifyDependenciesOnObject(const AcDbObject* pObject,
														AcDbAssocStatus newStatus);
	ACDBCORE2D_PORT int order() const;
	ACDBCORE2D_PORT AcDbObjectId owningAction() const { return this->ownerId(); }
	ACDBCORE2D_PORT AcDbObjectId prevDependencyOnObject() const;
	ACDBCORE2D_PORT Acad::ErrorStatus setDependencyBody(const AcDbObjectId& dependencyBodyId);
	ACDBCORE2D_PORT void setDependentOnObject(const AcDbCompoundObjectId& compoundId);
	ACDBCORE2D_PORT void setIsDelegatingToOwningAction(bool yesNo);
	ACDBCORE2D_PORT void setIsObjectStateDependent(bool yesNo);
	ACDBCORE2D_PORT void setIsReadDependency(bool yesNo);
	ACDBCORE2D_PORT void setIsWriteDependency(bool yesNo);
	ACDBCORE2D_PORT void setOrder(int newOrder);
	ACDBCORE2D_PORT Acad::ErrorStatus setOwningAction(const AcDbObjectId& actionId);
	ACDBCORE2D_PORT Acad::ErrorStatus setStatus(AcDbAssocStatus newStatus, bool notifyOwningAction = true);
	ACDBCORE2D_PORT AcDbAssocStatus status() const;
	ACDBCORE2D_PORT Acad::ErrorStatus transferToObject(const AcDbCompoundObjectId& compoundId);
	ACDBCORE2D_PORT Acad::ErrorStatus updateDependentOnObject();
};

class AcDbAssocDependencyNotificationDisabler
{
private:
	const bool mPrev;

public:
	ACDBCORE2D_PORT explicit AcDbAssocDependencyNotificationDisabler(bool disableIt = true);
	ACDBCORE2D_PORT ~AcDbAssocDependencyNotificationDisabler();
	ACDBCORE2D_PORT static bool isDisabled();
};

#include "icarx/IcArxPackPop.h"

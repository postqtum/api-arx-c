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
***     Description: Declaration of AcDbAssocDependencyBody class
***
*****************************************************************************/
#pragma once

#include "AcDbAssocDependency.h"

#include "icarx/IcArxPackPush.h"

class AcDbAssocDependencyBody : public AcDbObject
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbAssocDependencyBody, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT explicit AcDbAssocDependencyBody(
			AcDbAssocCreateImpObject createImpObject = kAcDbAssocCreateImpObject);
	ACDBCORE2D_PORT ~AcDbAssocDependencyBody();

	ACDBCORE2D_PORT virtual void auditAssociativeDataOverride(
			AcDbAssocStatus& parentActionHandling);
	ACDBCORE2D_PORT virtual void clonedOverride(const AcDbObject* pDbObj, const AcDbObject* pNewObj)
	{
		(void)(pDbObj);
		(void)(pNewObj);
	}
	ACDBCORE2D_PORT AcDbAssocEvaluationCallback* currentEvaluationCallback() const;
	ACDBCORE2D_PORT AcDbObjectId dependentOnObject() const;
	ACDBCORE2D_PORT virtual void erasedOverride(const AcDbObject* pDbObj, bool isErasing)
	{
		(void)(pDbObj);
		(void)(isErasing);
	}
	ACDBCORE2D_PORT virtual void evaluateOverride() = 0;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus hasCachedValueOverride(bool& hasCachedVal) const
	{
		(void)(hasCachedVal);
		return Acad::eNotImplemented;
	}
	ACDBCORE2D_PORT bool isActionEvaluationInProgress() const;
	ACDBCORE2D_PORT bool isAttachedToObject() const { return !this->dependentOnObject().isNull(); }
	ACDBCORE2D_PORT virtual Acad::ErrorStatus isDependentOnTheSameThingAsOverride(
			const AcDbAssocDependency* pOtherDependency, bool& isDependentOnSameThing) const
	{
		(void)(pOtherDependency);
		(void)(isDependentOnSameThing);
		return Acad::eNotImplemented;
	}
	ACDBCORE2D_PORT virtual Acad::ErrorStatus isEqualToOverride(
			const AcDbAssocDependency* pOtherDependency, bool& isEqual) const
	{
		(void)(pOtherDependency);
		(void)(isEqual);
		return Acad::eNotImplemented;
	}
	ACDBCORE2D_PORT virtual Acad::ErrorStatus isRelevantChangeOverride(bool& isRelevChange) const
	{
		(void)(isRelevChange);
		return Acad::eNotImplemented;
	}
	ACDBCORE2D_PORT virtual void modifiedOverride(const AcDbObject* pDbObj) { (void)(pDbObj); }
	ACDBCORE2D_PORT AcDbObjectId owningAction() const;
	ACDBCORE2D_PORT AcDbObjectId parentDependency() const { return this->ownerId(); }
	ACDBCORE2D_PORT Acad::ErrorStatus setStatus(AcDbAssocStatus newStatus,
												bool notifyOwningAction = true);
	ACDBCORE2D_PORT AcDbAssocStatus status() const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus updateDependentOnObjectOverride()
	{
		return Acad::eNotImplemented;
	}
};

#include "icarx/IcArxPackPop.h"

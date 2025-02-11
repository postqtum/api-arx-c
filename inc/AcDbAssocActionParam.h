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
***     Description: Declaration of AcDbAssocActionParam class
***
*****************************************************************************/
#pragma once

#include "AcDbAssocGlobal.h"
#include "AcDbCompoundObjectId.h"

#include "icarx/AcDbObject.h"

#include "icarx/IcArxPackPush.h"

class AcDbAssocActionParam : public AcDbObject
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbAssocActionParam, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT AcDbAssocActionParam(
			AcDbAssocCreateImpObject createImpObject = kAcDbAssocCreateImpObject);

	ACDBCORE2D_PORT virtual void auditAssociativeData(AcDbAssocStatus& parentActionHandling);
	ACDBCORE2D_PORT virtual void clonePersSubentNamingDataOverride(
			AcDbAssocPersSubentManagerCloner* pCloner);
	ACDBCORE2D_PORT virtual void collectPersSubentNamingDataOverride(
			AcDbPersStepIdArray& stepIds, AcDbPersSubentIdArray& persSubentIds) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus detachDependencies();
	ACDBCORE2D_PORT Acad::ErrorStatus getCompoundObjectIds(
			bool readDependenciesWanted, bool writeDependenciesWanted,
			AcArray<AcDbCompoundObjectId>& compoundObjectIds) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getDependencies(
			bool readDependenciesWanted, bool writeDependenciesWanted,
			AcDbObjectIdArray& dependencyIds) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus makeParamConstant();
	ACDBCORE2D_PORT virtual Acad::ErrorStatus makeParamEmpty(bool alsoEraseOwnedObjects);
	ACDBCORE2D_PORT const AcString& name() const;
	ACDBCORE2D_PORT AcDbObjectId parentAction() const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setName(const AcString& newName);
	ACDBCORE2D_PORT Acad::ErrorStatus setStatus(AcDbAssocStatus newStatus,
												bool notifyParentAction = true,
												bool setInOwnedParams = false);
	ACDBCORE2D_PORT AcDbAssocStatus status(bool alsoCheckDependencies) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus transformConstantGeometry(
			const AcGeMatrix3d& transform);
};

#include "icarx/IcArxPackPop.h"

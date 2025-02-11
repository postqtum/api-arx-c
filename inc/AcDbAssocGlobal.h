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
***     Description: AcDbAssoc library global declarations
***
*****************************************************************************/
#pragma once

#include "AcDbCore2dDefs.h"

#include "acadstrc.h"
#include "acarray.h"
#include "gepnt3d.h"
#include "AcDb.h"

#include "icarx/AcDbObjectId.h"

#include "icarx/IcArxPackPush.h"

class AcDbObject;
class AcDbAssocAction;
class AcDbAssocActionBody;
class AcDbAssocNetwork;
class AcDbAssocDependency;
class AcDbAssocDependencyBody;
class AcDbAssocGeomDependency;
class AcDbAssoc2dConstraintGroup;
class AcDbAssocPersSubentId;
class AcDbAssocSimplePersSubentId;
class AcDbAssocSingleEdgePersSubentId;
class AcDbAssocIndexPersSubentId;
class AcDbAssocExternalIndexPersSubentId;
class AcDbAssocPersSubentIdPE;
class AcDbAssocVariable;
class AcDbAssocValueDependency;
class AcDbAssocValueProviderPE;
class AcDbEvalContext;
class AcDbAssocPersSubentManager;
class AcDbAssocPersSubentManagerPE;
class AcDbAssocPersSubentManagerCloner;
class AcDbAssocNotificationData;

namespace PersSubentNaming
{
class AnnotationData;
class PersSubentManager;
}  // namespace PersSubentNaming

class ENTITY;
class COEDGE;
class EDGE;
class LOOP;
class FACE;
class SHELL;
class LUMP;
class BODY;
using AcDbAsmBodyArray = AcArray<BODY*>;
using AcDbAsmEntityArray = AcArray<ENTITY*>;
using AcDbAsmEdgeArray = AcArray<EDGE*>;
using AcDbAsmFaceArray = AcArray<FACE*>;
using AcDbAsmEdgeArray2d = AcArray<AcDbAsmEdgeArray>;

enum AcDbAssocStatus
{
	kIsUpToDateAssocStatus = 0,
	kChangedDirectlyAssocStatus,
	kChangedTransitivelyAssocStatus,
	kChangedNoDifferenceAssocStatus,
	kFailedToEvaluateAssocStatus,
	kErasedAssocStatus,
	kSuppressedAssocStatus,
	kUnresolvedAssocStatus,
};


inline int evaluationRequestSeverityLevel(AcDbAssocStatus status)
{
	switch (status)
	{
		case kChangedDirectlyAssocStatus: return 3;
		case kChangedTransitivelyAssocStatus: return 2;
		case kChangedNoDifferenceAssocStatus: return 1;
		default: return 0;
	}
}


inline bool isEvaluationRequest(AcDbAssocStatus status)
{
	return evaluationRequestSeverityLevel(status) > 0;
}


inline bool isToBeSkipped(AcDbAssocStatus status)
{
	return status == kErasedAssocStatus || status == kSuppressedAssocStatus;
}


enum AcDbAssocEvaluationPriority
{
	kCannotBeEvaluatedAssocEvaluationPriority = -1000,
	kCannotDermineAssocEvaluationPriority = 0,
	kCanBeEvaluatedAssocEvaluationPriority = 1000,
};


enum AcDbAssocEvaluationMode
{
	kModifyObjectsAssocEvaluationMode,
	kModifyActionAssocEvaluationMode,
};


enum AcDbAssocDraggingState
{
	kNotDraggingAssocDraggingState,
	kFirstSampleAssocDraggingState,
	kIntermediateSampleAssocDraggingState,
	kLastSampleAssocDraggingState,
};


enum AcDbAssocTransformationType
{
	kNotSpecified,
	kStretch,
	kRotate,
	kMove,
};

class ACDBCORE2D_PORT AcDbAssocEvaluationCallback
{
public:
	AcDbAssocEvaluationCallback() = default;
	virtual ~AcDbAssocEvaluationCallback() = default;

	virtual void allDependentActionsMarkedToEvaluate(AcDbAssocNetwork*) {}
	virtual void beginActionEvaluation(AcDbAssocAction* pAction) = 0;
	virtual void beginActionEvaluationUsingObject(AcDbAssocAction* pAction,
												  const AcDbObjectId& objectId,
												  bool objectIsGoingToBeUsed,
												  bool objectIsGoingToBeModified,
												  AcDbObject*& pSubstituteObject) = 0;
	virtual bool cancelActionEvaluation() { return false; }
	virtual AcDbAssocDraggingState draggingState() const { return kNotDraggingAssocDraggingState; }
	virtual void endActionEvaluation(AcDbAssocAction* pAction) = 0;
	virtual void endActionEvaluationUsingObject(AcDbAssocAction* pAction,
												const AcDbObjectId& objectId,
												AcDbObject* pObject) = 0;
	virtual AcDbAssocEvaluationMode evaluationMode() const
	{
		return kModifyObjectsAssocEvaluationMode;
	}
	virtual AcDbEvalContext* getAdditionalData() const { return 0; }
	virtual AcDbAssocTransformationType getTransformationType() const { return kNotSpecified; }
	virtual void setActionEvaluationErrorStatus(AcDbAssocAction* pAction,
												Acad::ErrorStatus errorStatus,
												const AcDbObjectId& objectId = AcDbObjectId::kNull,
												AcDbObject* pObject = nullptr,
												void* pErrorInfo = nullptr) = 0;
};


inline bool isDraggingProvidingSubstituteObjects(
		const AcDbAssocEvaluationCallback* pEvaluationCallback)
{
	if (!pEvaluationCallback)
		return false;

	const AcDbAssocDraggingState draggingState = pEvaluationCallback->draggingState();

	return draggingState == kFirstSampleAssocDraggingState ||
		   draggingState == kIntermediateSampleAssocDraggingState;
}


class AcDbActionsToEvaluateCallback
{
public:
	ACDBCORE2D_PORT AcDbActionsToEvaluateCallback() = default;
	ACDBCORE2D_PORT virtual ~AcDbActionsToEvaluateCallback() = default;

	ACDBCORE2D_PORT virtual void needsToEvaluate(const AcDbObjectId& objectId,
												 AcDbAssocStatus newStatus,
												 bool ownedActionsAlso = true) = 0;
};


enum AcDbAssocCreateImpObject
{
	kAcDbAssocCreateImpObject = 0,
	kAcDbAssocDoNotCreateImpObject = 1,
};


using AcDbPersElemId = unsigned;
using AcDbPersStepId = AcDbPersElemId;
using AcDbPersSubentId = AcDbPersElemId;
using AcDbPersElemIdArray = AcArray<AcDbPersElemId>;
using AcDbPersStepIdArray = AcArray<AcDbPersStepId>;
using AcDbPersSubentIdArray = AcArray<AcDbPersSubentId>;
using AcDbPersElemIdArray2d = AcArray<AcDbPersElemIdArray>;

const AcDbPersElemId kAcDbPersNullId = 0;

ACDBCORE2D_PORT Acad::ErrorStatus checkTopLevelNetworkIntegrity(const AcDbDatabase*);


enum AcDbAssocConstraintType
{
	kNoneAssocConstraintType = 0,
	kDistanceAssocConstraintType,
	kHorizontalDistanceAssocConstraintType,
	kVerticalDistanceAssocConstraintType,
	kAngle0AssocConstraintType,
	kAngle1AssocConstraintType,
	kAngle2AssocConstraintType,
	kAngle3AssocConstraintType,
	kRadiusAssocConstraintType,
	kDiameterAssocConstraintType,
};


class AcGeCurve3d;

class ACDBCORE2D_PORT AcDbSubentGeometry
{
private:
	AcDb::SubentType mSubentType = AcDb::kNullSubentType;
	AcGePoint3d mPoint;
	AcGeCurve3d* mpCurve = nullptr;

public:
	AcDbSubentGeometry() = default;
	AcDbSubentGeometry(const AcGePoint3d& pnt)
			: mSubentType(AcDb::kVertexSubentType), mPoint(pnt), mpCurve(0)
	{
	}
	AcDbSubentGeometry(AcGeCurve3d* pCurve)
			: mSubentType(AcDb::kEdgeSubentType), mPoint(), mpCurve(pCurve)
	{
	}

	AcGeCurve3d* curve() const { return mpCurve; }
	AcGePoint3d point() const { return mPoint; }
	AcDb::SubentType type() const { return mSubentType; }
};


class AcString;
class AcDbEvalVariant;


ACDBCORE2D_PORT bool acdbIsExpressionAConstant(const AcString& expression, AcDbEvalVariant& val);
ACDBCORE2D_PORT bool acdbIsExpressionANegativeConstant(const AcString& expression);
ACDBCORE2D_PORT bool acdbIsIdentifier(const AcString& name);

#include "icarx/IcArxPackPop.h"

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

#include "geplane.h"

#include "AcDbAssocAction.h"
#include "AcGeomConstraint.h"
#include "AcExplicitConstr.h"

#include "icarx/AcConstrainedLine.h"
#include "icarx/AcConstrainedPoint.h"

class AcAutoConstrainEvaluationCallback;

#include "icarx/IcArxPackPush.h"

class AcDbAssoc2dConstraintGroup : public AcDbAssocAction
{
public:
	enum SolutionStatus
	{
		kWellDefined = 0,
		kUnderConstrained,
		kOverConstrained,
		kInconsistent,
		kNotEvaluated,
		kNotAvailable,
		kRejectedByClient,
	};

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbAssoc2dConstraintGroup, ACDBCORE2D_PORT);

public:
	ACDBCORE2D_PORT AcDbAssoc2dConstraintGroup(const AcGePlane& plane = AcGePlane::kXYPlane);

	ACDBCORE2D_PORT Acad::ErrorStatus add3PointAngleConstraint(
			AcConstrainedPoint* pConsPoint1, AcConstrainedPoint* pConsPoint2,
			AcConstrainedPoint* pConsPoint3, AcAngleConstraint::SectorType sectorType,
			AcDbObjectId valueDependencyId, AcDbObjectId dimDependencyId,
			Ac3PointAngleConstraint** ppNewAngConstraint = nullptr);
	ACDBCORE2D_PORT Acad::ErrorStatus addAngleConstraint(
			AcConstrainedLine* pConsLine1, AcConstrainedLine* pConsLine2,
			AcAngleConstraint::SectorType sectorType, AcDbObjectId valueDependencyId,
			AcDbObjectId dimDependencyId, AcAngleConstraint** ppNewAngConstraint = nullptr);
	ACDBCORE2D_PORT Acad::ErrorStatus addConstrainedGeometry(const AcDbFullSubentPath& subentPath,
															 AcConstrainedGeometry*& pConsGeom);
	ACDBCORE2D_PORT Acad::ErrorStatus addDistanceConstraint(
			AcConstrainedGeometry* pConsGeom1, AcConstrainedGeometry* pConsGeom2,
			AcDistanceConstraint::DirectionType directionType, AcDbObjectId valueDependencyId,
			AcDbObjectId dimDependencyId, const AcGeVector3d* pFixedDirection = nullptr,
			const AcConstrainedLine* pDirectionLine = nullptr,
			AcDistanceConstraint** ppNewDisConstraint = nullptr);
	ACDBCORE2D_PORT Acad::ErrorStatus addGeometricalConstraint(
			AcGeomConstraint::GeomConstraintType type,
			const AcArray<AcConstrainedGeometry*>& apConsGeoms,
			AcGeomConstraint** ppNewConstraint = nullptr, const AcGeMatrix3d* pUCSCoord = nullptr);
	ACDBCORE2D_PORT Acad::ErrorStatus addGeometricalConstraint(
			AcGeomConstraint::GeomConstraintType type, const AcDbFullSubentPathArray& aPaths,
			AcGeomConstraint** ppNewConstraint = nullptr, const AcGeMatrix3d* pUCSCoord = nullptr);
	ACDBCORE2D_PORT Acad::ErrorStatus addRadiusDiameterConstraint(
			AcConstrainedGeometry* pConsGeom,
			AcRadiusDiameterConstraint::RadiusDiameterConstrType type,
			AcDbObjectId valueDependencyId, AcDbObjectId dimDependencyId,
			AcRadiusDiameterConstraint** ppNewRadDiaConstraint = nullptr);
	ACDBCORE2D_PORT Acad::ErrorStatus autoConstrain(const AcDbFullSubentPathArray& aPaths,
													const AcGeTol& tol,
													AcAutoConstrainEvaluationCallback* pCallback);
	ACDBCORE2D_PORT AcDbAssoc2dConstraintGroup::SolutionStatus constraintStatus(
			const AcGeomConstraint* pConstraint) const;
	ACDBCORE2D_PORT Acad::ErrorStatus deleteConstrainedGeometry(
			const AcDbObjectId& geomDependencyId);
	ACDBCORE2D_PORT Acad::ErrorStatus deleteConstraint(AcGeomConstraint* pGeomConst);
	ACDBCORE2D_PORT Acad::ErrorStatus geometryMirrored(AcDbAssocGeomDependency* pGeomDependency);
	ACDBCORE2D_PORT AcDbAssoc2dConstraintGroup::SolutionStatus geometryStatus(
			const AcConstrainedGeometry* pConsGeom) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getAllConnectedGeomDependencies(
			const AcDbObjectIdArray& srcGeomDependencyIds,
			AcDbObjectIdArray& allConnectedGeomDependencyIds) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getConstrainedGeometries(
			AcArray<AcConstrainedGeometry*>& aConstGeom) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getConstrainedGeometry(
			const AcDbFullSubentPath& fullSubentPath, AcConstrainedGeometry*& pConsGeom,
			bool bCreateArcLineMid = false);
	ACDBCORE2D_PORT Acad::ErrorStatus getConstrainedGeometry(
			const AcDbAssocGeomDependency* pGeomDependency, AcConstrainedGeometry*& pConsGeom,
			AcDb::ImplicitPointType* pPtType = nullptr, int defPtIndex = -1,
			bool bCreateArcLineMid = false);
	ACDBCORE2D_PORT Acad::ErrorStatus getConstraints(
			AcArray<AcGeomConstraint*>& apConstraints) const;
	ACDBCORE2D_PORT int getDOF();
	ACDBCORE2D_PORT AcConstraintGroupNode* getGroupNodePtr(const AcGraphNode::Id nodeId) const;
	ACDBCORE2D_PORT const AcGePlane getWorkPlane() const;
	ACDBCORE2D_PORT void regenDimensionSystem();
	ACDBCORE2D_PORT void setWorkPlane(const AcGePlane& newPlane);
	ACDBCORE2D_PORT AcDbAssoc2dConstraintGroup::SolutionStatus solutionStatus(
			bool bAlsoCheckForConstraints = true) const;
	ACDBCORE2D_PORT Acad::ErrorStatus transformActionBy(const AcGeMatrix3d& transform);

	static ACDBCORE2D_PORT void addGlobalCallback(class AcDbAssoc2dConstraintCallback* pCallback);
	static ACDBCORE2D_PORT bool doNotCheckNewlyAddedConstraints();
	static ACDBCORE2D_PORT AcDbAssoc2dConstraintCallback* globalCallback();
	static ACDBCORE2D_PORT void removeGlobalCallback(
			class AcDbAssoc2dConstraintCallback* pCallback);
	static ACDBCORE2D_PORT void setDoNotCheckNewlyAddedConstraints(bool doNotCheck);
};

class AcDbAssoc2dConstraintCallback
{
public:
	AcDbAssoc2dConstraintCallback() = default;
	virtual ~AcDbAssoc2dConstraintCallback() = default;

	virtual bool canBeRelaxed(const class AcExplicitConstraint* pConstraint)
	{
		(void)pConstraint;
		return false;
	}
	virtual void constraintDeactivated(const AcExplicitConstraint* pConstraint,
									   bool bDeactivated = true)
	{
		(void)pConstraint;
		(void)bDeactivated;
	}
};

class AcAutoConstrainEvaluationCallback
{
	friend class AcDbImpAssoc2dConstraintGroup;
	friend class AcAutoConstraintEvalManager;

private:
	AcArray<AcGeomConstraint*> mConstraints;

private:
	void constraintAdded(AcGeomConstraint* pNewCons);
	int getAutoConstraintMask() const;
	bool isValidConstraintType(AcGeomConstraint::GeomConstraintType type,
							   const AcGeomConstraint* pConstraint) const;
	void validate(void* pData);

public:
	ACDBCORE2D_PORT virtual ~AcAutoConstrainEvaluationCallback() = default;

	ACDBCORE2D_PORT virtual void getAutoConstrainPriority(
			AcArray<AcGeomConstraint::GeomConstraintType>& constraintList) const
	{
		constraintList.setLogicalLength(0);
		for (int type = (int)AcGeomConstraint::kHorizontal;
			 type < (int)AcGeomConstraint::kEqualRadius; ++type)
		{
			constraintList.append((AcGeomConstraint::GeomConstraintType)type);
		}
	}
	ACDBCORE2D_PORT virtual void getConstraintPriorityOverride(
			AcGeomConstraint::GeomConstraintType type,
			const AcArray<const AcConstrainedGeometry*>& geometries, int& priority) const
	{
		(void)type;
		(void)geometries;
		(void)priority;
		return;
	}
	ACDBCORE2D_PORT int getTotalConstraints(AcArray<AcGeomConstraint*>* pConstraints) const;
	ACDBCORE2D_PORT virtual bool isEvaluationCancelled() { return false; }
};

#include "icarx/IcArxPackPop.h"

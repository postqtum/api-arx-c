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
***     Description: Declaration of AcDbAssocSurfaceActionBody class
***
*****************************************************************************/
#pragma once

#include "AcDbAssocParamBasedActionBody.h"

#include "icarx/IcArxPackPush.h"

class ACDB_PORT AcDbAssocSurfaceActionBody : public AcDbAssocParamBasedActionBody
{
public:
	ACRX_DECLARE_MEMBERS(AcDbAssocSurfaceActionBody);

	explicit AcDbAssocSurfaceActionBody(
			AcDbAssocCreateImpObject createImpObject = kAcDbAssocCreateImpObject);

	Acad::ErrorStatus addMoreObjectsToDeepCloneOverride(
			AcDbIdMapping&, AcDbObjectIdArray& additionalObjectsToClone) const override;
	Acad::ErrorStatus dragStatusOverride(const AcDb::DragStat) override;
	void evaluateOverride() override;
	static Acad::ErrorStatus findActionsThatAffectedTopologicalSubentity(
			const AcDbEntity* pAsmBasedEntity, const AcDbSubentId&, AcDbObjectIdArray& actionIds);
	Acad::ErrorStatus getDependentActionsToEvaluateOverride(
			AcDbActionsToEvaluateCallback*) const override;
	virtual Acad::ErrorStatus getGripEntityUCS(const void* pGripAppData, AcGeVector3d& normalVec,
											   AcGePoint3d& origin, AcGeVector3d& xAxis) const;
	virtual Acad::ErrorStatus getGripPoints(AcGePoint3dArray& gripPoints, AcDbIntArray& osnapModes,
											AcDbIntArray& geomIds) const;
	virtual Acad::ErrorStatus getGripPoints(AcDbGripDataPtrArray& grips,
											const double curViewUnitSize, const int gripSize,
											const AcGeVector3d& curViewDir,
											const int bitflags) const;
	static Acad::ErrorStatus getSurfacesDirectlyDependentOnObject(
			const AcDbObject*, AcDbObjectIdArray& dependentSurfaceIds);
	static Acad::ErrorStatus getTopologicalSubentitiesForActionsOnEntity(
			const AcDbEntity* pAsmBasedEntity, bool alsoUseAdjacentTopology,
			AcDbObjectIdArray& actionIds, AcArray<AcArray<AcDbSubentId>>& actionSubentIds);
	virtual void gripStatus(const AcDb::GripStat status);
	bool isSemiAssociative() const;
	virtual bool isSemiAssociativitySatisfiedOverride() const;
	virtual void list() const;
	virtual Acad::ErrorStatus moveGripPoints(const AcDbIntArray& indices,
											 const AcGeVector3d& offset);
	virtual Acad::ErrorStatus moveGripPoints(const AcDbVoidPtrArray& gripAppData,
											 const AcGeVector3d& offset, const int bitflags);
	virtual Acad::ErrorStatus moveStretchPoints(const AcDbIntArray& indices,
												const AcGeVector3d& offset);
	AcDbObjectId resultingSurface() const;
	AcDbObjectId resultingSurfaceDep(bool createIfDoesNotExist, bool isWriteOnlyDependency = true);
	Acad::ErrorStatus setResultingSurface(const AcDbObjectId& surfaceId,
										  bool isWriteOnlyDependency = true);
};

#include "icarx/IcArxPackPop.h"

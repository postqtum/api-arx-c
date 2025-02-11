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
***     Description: Declaration of AcDbAssocArrayActionBody class
***
*****************************************************************************/
#pragma once

#include "AcDbAssocParamBasedActionBody.h"
#include "AcDbAssocArrayItem.h"

class AcDbVertexRef;
class AcDbAssocArrayParameters;

#include "icarx/IcArxPackPush.h"

class AcDbAssocArrayActionBody : public AcDbAssocParamBasedActionBody
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbAssocArrayActionBody, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT explicit AcDbAssocArrayActionBody(
			AcDbAssocCreateImpObject createImpObject = kAcDbAssocCreateImpObject);
	ACDBCORE2D_PORT ~AcDbAssocArrayActionBody();

	ACDBCORE2D_PORT Acad::ErrorStatus addMoreObjectsToDeepCloneOverride(
			AcDbIdMapping& idMap, AcDbObjectIdArray& additionalObjectsToClone) const override;
	ACDBCORE2D_PORT Acad::ErrorStatus addSourceEntity(AcDbObjectId entity,
													  const AcGePoint3d& basePoint);
	ACDBCORE2D_PORT virtual bool controlsItem(const AcDbAssocArrayItem& index) const;
	ACDBCORE2D_PORT static Acad::ErrorStatus createInstance(
			const AcDbObjectIdArray& sourceEntites, AcDbVertexRef& basePoint,
			const AcDbAssocArrayParameters* pParameters, AcDbObjectId& arrayId,
			AcDbObjectId& actionBodyId);
	ACDBCORE2D_PORT Acad::ErrorStatus deleteItem(const AcDbItemLocator& index, bool bErase = true);
	ACDBCORE2D_PORT Acad::ErrorStatus dragStatusOverride(const AcDb::DragStat status) override;
	ACDBCORE2D_PORT void evaluateOverride() override;
	ACDBCORE2D_PORT static Acad::ErrorStatus explode(AcDbEntity* pEntity,
													 AcDbObjectIdArray& newIds);
	ACDBCORE2D_PORT virtual AcDbObjectId getArrayEntity() const;
	ACDBCORE2D_PORT static Acad::ErrorStatus getArrayItemLocators(
			const AcDbFullSubentPathArray& subents, AcArray<AcDbItemLocator>& indices);
	ACDBCORE2D_PORT AcDbObjectId getArraySourceBTR() const;
	ACDBCORE2D_PORT static AcDbObjectId getControllingActionBody(
			const AcDbEntity* pEntity, const AcDbItemLocator* pItemIndex = nullptr);
	ACDBCORE2D_PORT inline const AcDbAssocArrayItem* getItemAt(const AcDbItemLocator& index) const
	{
		AcDbFullSubentPath path = AcDbFullSubentPath();
		return this->getItemAt(index, path);
	}
	ACDBCORE2D_PORT const AcDbAssocArrayItem* getItemAt(const AcDbItemLocator& index,
														AcDbFullSubentPath& path) const;
	ACDBCORE2D_PORT const AcDbAssocArrayItem* getItemAt(const AcDbFullSubentPath& path) const;
	ACDBCORE2D_PORT void getItems(AcArray<AcDbItemLocator>& indices, bool skipErased = true) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getSourceBasePoint(AcDbVertexRef& vertexRef,
														 AcGePoint3d& position) const;
	ACDBCORE2D_PORT AcDbObjectIdArray getSourceEntities() const;
	ACDBCORE2D_PORT virtual AcGeMatrix3d getTransform() const;
	ACDBCORE2D_PORT static bool isAssociativeArray(const AcDbEntity* pEntity);
	ACDBCORE2D_PORT AcDbAssocArrayParameters* parameters();
	ACDBCORE2D_PORT const AcDbAssocArrayParameters* parameters() const;
	ACDBCORE2D_PORT Acad::ErrorStatus postProcessAfterDeepCloneOverride(AcDbIdMapping& idMap) override;
	ACDBCORE2D_PORT Acad::ErrorStatus removeSourceEntity(AcDbObjectId entity);
	ACDBCORE2D_PORT static Acad::ErrorStatus resetArrayItems(
			AcDbObjectId arrayEntityId, const AcArray<AcDbItemLocator>& indices,
			bool resetAll = false);
	ACDBCORE2D_PORT Acad::ErrorStatus setSourceBasePoint(const AcDbVertexRef& basePoint);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus transformBy(const AcGeMatrix3d& xform);
	ACDBCORE2D_PORT Acad::ErrorStatus transformItemBy(const AcDbItemLocator& index,
													  const AcGeMatrix3d& xform);
};

#include "icarx/IcArxPackPop.h"

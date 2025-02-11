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

#include "AcDbAssocSimplePersSubentId.h"

#include "gemat3d.h"

class AcDbCompoundObjectId;
class AcDbIdMapping;

class AcGeCurve3d;
class AcGeEntity3d;
class AcGeSurface;

enum RigidSetType
{
	kNotRigidSet = 0,
	kScalableRigidSet,
	kNonScalableRigidSet
};

#include "icarx/IcArxPackPush.h"

class AcDbAssocPersSubentIdPE : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbAssocPersSubentIdPE, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT virtual AcDbAssocPersSubentId* createNewPersFaceSilhouetteId(
			AcDbEntity* pEntity, AcDbDatabase* pDatabase, AcRxObject* pContext,
			const AcDbCompoundObjectId& /*compId*/, const AcDbSubentId& faceSubentId,
			const AcGeMatrix3d* pEntityTransform, class AcDbGeometryProjector* pGeometryProjector,
			int transientSilhId)
	{
		(void)(pEntity);
		(void)(pDatabase);
		(void)(pContext);
		(void)(faceSubentId);
		(void)(pEntityTransform);
		(void)(pGeometryProjector);
		(void)(transientSilhId);
		return nullptr;
	}
	ACDBCORE2D_PORT virtual AcDbAssocPersSubentId* createNewPersSubent(
			AcDbEntity* pEntity, AcDbDatabase* pDatabase, const AcDbCompoundObjectId& /*compId*/,
			const AcDbSubentId& subentId)
	{
		(void)(pEntity);
		(void)(pDatabase);

		return new AcDbAssocSimplePersSubentId(subentId);
	}
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getAllSubentities(const AcDbEntity* pEntity,
																AcDb::SubentType subentType,
																AcArray<AcDbSubentId>& allSubentIds)
	{
		(void)(pEntity);
		(void)(subentType);
		(void)(allSubentIds);
		return Acad::eNotImplemented;
	}
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getAllSubentities(const AcDbEntity* pEntity,
																const AcRxClass* pSubentClass,
																AcArray<AcDbSubentId>& allSubentIds)
	{
		(void)(pEntity);
		(void)(pSubentClass);
		(void)(allSubentIds);
		return Acad::eNotImplemented;
	}
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getEdgeSubentityGeometry(
			const AcDbEntity* pEntity, const AcDbSubentId& edgeSubentId, AcGeCurve3d*& pEdgeCurve)
	{
		(void)(pEntity);
		(void)(edgeSubentId);
		(void)(pEdgeCurve);
		return Acad::eNotImplemented;
	}
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setEdgeSubentityGeometry(
			AcDbEntity* pEntity, const AcDbSubentId& edgeSubentId, const AcGeCurve3d* pNewEdgeCurve)
	{
		(void)(pEntity);
		(void)(edgeSubentId);
		(void)(pNewEdgeCurve);
		return Acad::eNotImplemented;
	}
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getEdgeVertexSubentities(
			const AcDbEntity* pEntity, const AcDbSubentId& edgeSubentId,
			AcDbSubentId& startVertexSubentId, AcDbSubentId& endVertexSubentId,
			AcArray<AcDbSubentId>& otherVertexSubentIds)
	{
		(void)(pEntity);
		(void)(edgeSubentId);
		(void)(startVertexSubentId);
		(void)(endVertexSubentId);
		(void)(otherVertexSubentIds);
		return Acad::eNotImplemented;
	}
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getFaceSilhouetteGeometry(
			AcDbEntity* pEntity, AcRxObject* pContext, const AcDbSubentId& faceSubentId,
			const AcGeMatrix3d* pEntityTransform, class AcDbGeometryProjector* pGeometryProjector,
			AcArray<int>& transientSilhIds,
			AcArray<AcGeCurve3d*>& silhCurves)
	{
		(void)(pEntity);
		(void)(pContext);
		(void)(faceSubentId);
		(void)(pEntityTransform);
		(void)(pGeometryProjector);
		(void)(transientSilhIds);

		silhCurves.removeAll();
		return Acad::eNotImplemented;
	}
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getFaceSubentityGeometry(
			const AcDbEntity* pEntity, const AcDbSubentId& faceSubentId, AcGeSurface*& pFaceSurface)
	{
		(void)(pEntity);
		(void)(faceSubentId);
		(void)(pFaceSurface);
		return Acad::eNotImplemented;
	}
	ACDBCORE2D_PORT virtual int getRigidSetState(const AcDbEntity* pEntity)
	{
		(void)(pEntity);
		return kNotRigidSet;
	}
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getRigidSetTransform(const AcDbEntity* pEntity,
																   AcGeMatrix3d& trans)
	{
		(void)(pEntity);
		(void)(trans);
		return Acad::eNotApplicable;
	}
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getSplineEdgeVertexSubentities(
			const AcDbEntity* pEntity, const AcDbSubentId& edgeSubentId,
			AcDbSubentId& startVertexSubentId, AcDbSubentId& endVertexSubentId,
			AcArray<AcDbSubentId>& controlPointSubentIds, AcArray<AcDbSubentId>& fitPointSubentIds)
	{
		(void)(pEntity);
		(void)(edgeSubentId);
		(void)(startVertexSubentId);
		(void)(endVertexSubentId);
		(void)(controlPointSubentIds);
		(void)(fitPointSubentIds);
		return Acad::eNotImplemented;
	}
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getSubentGeometryXform(
			const AcDbEntity* pEntity, const AcDbObjectIdArray& fullSubentPath,
			AcGeMatrix3d& trans) const
	{
		(void)(pEntity);
		(void)(fullSubentPath);
		(void)(trans);

		trans.setToIdentity();
		return Acad::eOk;
	}
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getSubentityGeometry(
			const AcDbEntity* pEntity, const AcDbSubentId& subentId,
			AcGeEntity3d*& pSubentityGeometry);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setSubentityGeometry(
			AcDbEntity* pEntity, const AcDbSubentId& subentId,
			const AcGeEntity3d* pNewSubentityGeometry);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getTransientFaceSilhouetteIds(
			AcDbEntity* pEntity, AcDbDatabase* pDatabase, AcRxObject* pContext,
			const AcDbSubentId& faceSubentId, const AcGeMatrix3d* pEntityTransform,
			class AcDbGeometryProjector* pGeometryProjector,
			const AcDbAssocPersSubentId* pPersSilhId, AcArray<int>& transientSilhIds)
	{
		(void)(pEntity);
		(void)(pDatabase);
		(void)(pContext);
		(void)(faceSubentId);
		(void)(pEntityTransform);
		(void)(pGeometryProjector);
		(void)(pPersSilhId);

		transientSilhIds.removeAll();
		return Acad::eNotImplemented;
	}
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getTransientSubentIds(
			const AcDbEntity* pEntity, AcDbDatabase* pDatabase,
			const AcDbAssocPersSubentId* pPersSubentId, AcArray<AcDbSubentId>& subents) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setVertexSubentityGeometry(
			AcDbEntity* pEntity, const AcDbSubentId& vertexSubentId,
			const AcGePoint3d& newVertexPosition)
	{
		(void)(pEntity);
		(void)(vertexSubentId);
		(void)(newVertexPosition);
		return Acad::eNotImplemented;
	}
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getVertexSubentityGeometry(
			const AcDbEntity* pEntity, const AcDbSubentId& vertexSubentId,
			AcGePoint3d& vertexPosition)
	{
		(void)(pEntity);
		(void)(vertexSubentId);
		(void)(vertexPosition);
		return Acad::eNotImplemented;
	}
	ACDBCORE2D_PORT virtual Acad::ErrorStatus makePersSubentPurgeable(
			AcDbEntity* pEntity, AcDbDatabase* pDatabase, const AcDbAssocPersSubentId* pPerSubentId,
			bool yesNo)
	{
		(void)(pEntity);
		(void)(pDatabase);
		(void)(yesNo);
		(void)(pPerSubentId);
		return Acad::eOk;
	}
	ACDBCORE2D_PORT virtual Acad::ErrorStatus mirrorPersSubent(
			const AcDbEntity* pMirroredEntity, AcDbDatabase* pDatabase,
			AcDbAssocPersSubentId* pPersSubentIdToMirror)
	{
		(void)(pMirroredEntity);
		(void)(pDatabase);
		(void)(pPersSubentIdToMirror);
		return Acad::eOk;
	}
	ACDBCORE2D_PORT virtual Acad::ErrorStatus releasePersSubent(
			AcDbEntity* pEntity, AcDbDatabase* pDatabase, const AcDbAssocPersSubentId* pPerSubentId)
	{
		(void)(pEntity);
		(void)(pDatabase);
		(void)(pPerSubentId);
		return Acad::eOk;
	}
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setFaceSubentityGeometry(
			AcDbEntity* pEntity, const AcDbSubentId& faceSubentId,
			const AcGeSurface* pNewFaceSurface)
	{
		(void)(pEntity);
		(void)(faceSubentId);
		(void)(pNewFaceSurface);
		return Acad::eNotImplemented;
	}
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setRigidSetTransform(AcDbEntity* pEntity,
																   const AcGeMatrix3d& trans)
	{
		(void)(pEntity);
		(void)(trans);
		return Acad::eNotApplicable;
	}
	ACDBCORE2D_PORT virtual Acad::ErrorStatus transferPersSubentToAnotherEntity(
			AcDbEntity* pToEntity, AcDbDatabase* pToDatabase, AcDbEntity* pFromEntity,
			AcDbDatabase* pFromDatabase, const AcDbAssocPersSubentId* pPersSubentId)
	{
		(void)(pToEntity);
		(void)(pToDatabase);
		(void)(pFromEntity);
		(void)(pFromDatabase);
		(void)(pPersSubentId);
		return Acad::eOk;
	}
};

class AcDbAssocPersSubentIdPE2 : public AcDbAssocPersSubentIdPE
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbAssocPersSubentIdPE2, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT virtual Acad::ErrorStatus getUnredirectedObject(
			const AcDbSubentId& redirectedSubentId,
			const AcDbCompoundObjectId& redirectedCompoundObjectId,
			AcDbCompoundObjectId& originalCompoundObjectId)
	{
		(void)(redirectedSubentId);
		(void)(redirectedCompoundObjectId);
		(void)(originalCompoundObjectId);
		return Acad::eNotApplicable;
	}
};

#include "icarx/IcArxPackPop.h"

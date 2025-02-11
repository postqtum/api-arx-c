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
***     Description: Declaration of AcDbAssocObjectPointer template class
***
*****************************************************************************/
#pragma once

#include "dbobjptr2.h"
#include "acdbassocactionbody.h"
#include "AcDbAssocDependencyBody.h"
#include "icarx/IcArxAssert.h"

ACDBCORE2D_PORT AcDbAssocAction* acdbAssocGetCurrentlyEvaluatedActionPointer(const AcDbDatabase*);

#include "icarx/IcArxPackPush.h"

template<class ACDB_CLASS>
class AcDbAssocObjectPointer
{
private:
	AcDbAssocAction* const mpActionBeingEvaluated = nullptr;
	const AcDbAssocActionBody* const mpActionBodyBeingEvaluated = nullptr;
	const AcDbAssocDependency* const mpDependencyBeingEvaluated = nullptr;
	const AcDbAssocDependencyBody* const mpDependencyBodyBeingEvaluated = nullptr;
	const AcDbObjectId mObjectId = AcDbObjectId::kNull;
	AcDbSmartObjectPointer<ACDB_CLASS> mObjectPtr;
	ACDB_CLASS* mpObject = nullptr;
	AcDbObject* mpSubstituteObject = nullptr;
	Acad::ErrorStatus mSubstituteObjectErrorStatus = Acad::eNullObjectId;

private:
	AcDbAssocObjectPointer() = delete;
	AcDbAssocObjectPointer(const AcDbAssocObjectPointer&) = delete;
	AcDbAssocObjectPointer(AcDbAssocObjectPointer&&) = delete;
	AcDbAssocObjectPointer& operator=(const AcDbAssocObjectPointer&) = delete;
	AcDbAssocObjectPointer& operator=(AcDbAssocObjectPointer&&) = delete;

	void setup(AcDbAssocAction* pActionBeingEvaluated, AcDb::OpenMode openMode, bool openErased,
			   bool openOnLockedLayer)
	{
		mpObject = nullptr;
		mpSubstituteObject = nullptr;
		mSubstituteObjectErrorStatus = Acad::eNullObjectId;

		if (mObjectId.isNull())
			return;

		if (pActionBeingEvaluated != nullptr)
		{
			AcDbAssocEvaluationCallback* const pCallback =
					pActionBeingEvaluated->currentEvaluationCallback();

			if (pCallback != nullptr)
			{
				pCallback->beginActionEvaluationUsingObject(pActionBeingEvaluated, mObjectId, true,
															openMode == AcDb::kForWrite,
															mpSubstituteObject);

				if (mpSubstituteObject != nullptr)
				{
					mpObject = ACDB_CLASS::cast(mpSubstituteObject);
					mSubstituteObjectErrorStatus =
							mpObject != nullptr ? Acad::eOk : Acad::eNotThatKindOfClass;
				}
			}
		}

		if (mpSubstituteObject == nullptr)
		{
			if (mObjectPtr.open(mObjectId, openMode, openErased, openOnLockedLayer) == Acad::eOk)
			{
				mpObject = mObjectPtr;
				ICARX_ASSERT(mpObject != nullptr);
			}
		}
	}

public:
	AcDbAssocObjectPointer(AcDbObjectId objectId, AcDb::OpenMode openMode, bool openErased = false,
						   bool openOnLockedLayer = false)
			: mpActionBeingEvaluated(acdbAssocGetCurrentlyEvaluatedActionPointer(objectId.database())), mObjectId(objectId)
	{
		setup(mpActionBeingEvaluated, openMode, openErased, openOnLockedLayer);
	}
	AcDbAssocObjectPointer(AcDbAssocAction* pActionBeingEvaluated, AcDbObjectId objectId,
						   AcDb::OpenMode openMode, bool openErased = false,
						   bool openOnLockedLayer = false)
			: mpActionBeingEvaluated(pActionBeingEvaluated), mObjectId(objectId)
	{
		setup(pActionBeingEvaluated, openMode, openErased, openOnLockedLayer);
	}
	AcDbAssocObjectPointer(const AcDbAssocActionBody* pActionBodyBeingEvaluated,
						   AcDbObjectId objectId, AcDb::OpenMode openMode, bool openErased = false,
						   bool openOnLockedLayer = false)
			: mpActionBodyBeingEvaluated(pActionBodyBeingEvaluated), mObjectId(objectId)
	{
		ICARX_ASSERT(mpActionBodyBeingEvaluated != nullptr);
		AcDbSmartObjectPointer<AcDbAssocAction> pActionBeingEvaluated;

		if (mpActionBodyBeingEvaluated != nullptr)
		{
			pActionBeingEvaluated.open(mpActionBodyBeingEvaluated->parentAction(), AcDb::kForRead,
									   true);
		}

		setup(pActionBeingEvaluated, openMode, openErased, openOnLockedLayer);
	}
	AcDbAssocObjectPointer(const AcDbAssocDependency* pDependencyBeingEvaluated,
						   AcDbObjectId objectId, AcDb::OpenMode openMode, bool openErased = false,
						   bool openOnLockedLayer = false)
			: mpDependencyBeingEvaluated(pDependencyBeingEvaluated), mObjectId(objectId)
	{
		ICARX_ASSERT(mpDependencyBeingEvaluated != nullptr);
		AcDbSmartObjectPointer<AcDbAssocAction> pActionBeingEvaluated;

		if (mpDependencyBeingEvaluated != nullptr)
		{
			pActionBeingEvaluated.open(mpDependencyBeingEvaluated->owningAction(), AcDb::kForRead,
									   true);
		}

		setup(pActionBeingEvaluated, openMode, openErased, openOnLockedLayer);
	}
	AcDbAssocObjectPointer(const AcDbAssocDependencyBody* pDependencyBodyBeingEvaluated,
						   AcDbObjectId objectId, AcDb::OpenMode openMode, bool openErased = false,
						   bool openOnLockedLayer = false)
			: mpDependencyBodyBeingEvaluated(pDependencyBodyBeingEvaluated), mObjectId(objectId)
	{
		ICARX_ASSERT(mpDependencyBodyBeingEvaluated != nullptr);
		AcDbSmartObjectPointer<AcDbAssocAction> pActionBeingEvaluated;

		if (mpDependencyBodyBeingEvaluated != nullptr)
		{
			AcDbSmartObjectPointer<AcDbAssocDependency> pDependencyBeingEvaluated(
					mpDependencyBodyBeingEvaluated->parentDependency(), AcDb::kForRead, true);

			if (pDependencyBeingEvaluated.openStatus() == Acad::eOk)
			{
				pActionBeingEvaluated.open(pDependencyBeingEvaluated->owningAction(),
										   AcDb::kForRead, true);
			}
		}

		setup(pActionBeingEvaluated, openMode, openErased, openOnLockedLayer);
	}
	AcDbAssocObjectPointer(AcDbAssocAction* pActionBeingEvaluated, ACDB_CLASS* pObject)
			: mpActionBeingEvaluated(pActionBeingEvaluated)
			, mpObject(pObject)
			, mpSubstituteObject(pObject)
			, mSubstituteObjectErrorStatus(pObject != nullptr ? Acad::eOk : Acad::eNullObjectId)
	{
		ICARX_ASSERT(mpActionBeingEvaluated != nullptr);
		if (pActionBeingEvaluated != nullptr)
		{
			AcDbAssocEvaluationCallback* const pCallback =
					pActionBeingEvaluated->currentEvaluationCallback();

			if (pCallback != nullptr)
			{
				AcDbObject* pInputObject = pObject;

				pCallback->beginActionEvaluationUsingObject(
						pActionBeingEvaluated, AcDbObjectId::kNull, true, true, pInputObject);

				ICARX_ASSERT(pInputObject == pObject);
			}
		}
	}
	AcDbAssocObjectPointer(const AcDbAssocActionBody* pActionBodyBeingEvaluated,
						   ACDB_CLASS* pObject)
			: mpActionBodyBeingEvaluated(pActionBodyBeingEvaluated)
			, mpObject(pObject)
			, mpSubstituteObject(pObject)
			, mSubstituteObjectErrorStatus(pObject != nullptr ? Acad::eOk : Acad::eNullObjectId)
	{
		ICARX_ASSERT(mpActionBodyBeingEvaluated != nullptr);
		if (mpActionBodyBeingEvaluated != nullptr)
		{
			AcDbSmartObjectPointer<AcDbAssocAction> pActionBeingEvaluated(
					mpActionBodyBeingEvaluated->parentAction(), AcDb::kForRead, true);

			if (pActionBeingEvaluated != nullptr)
			{
				AcDbAssocEvaluationCallback* const pCallback =
						pActionBeingEvaluated->currentEvaluationCallback();

				if (pCallback != nullptr)
				{
					AcDbObject* pInputObject = pObject;

					pCallback->beginActionEvaluationUsingObject(
							pActionBeingEvaluated, AcDbObjectId::kNull, true, true, pInputObject);

					ICARX_ASSERT(pInputObject == pObject);
				}
			}
		}
	}
	~AcDbAssocObjectPointer()
	{
		if (mObjectId.isNull() && mpSubstituteObject == nullptr)
			return;

		if (mpActionBeingEvaluated != nullptr)
		{
			AcDbAssocEvaluationCallback* const pCallback =
					mpActionBeingEvaluated->currentEvaluationCallback();

			if (pCallback != nullptr)
			{
				pCallback->endActionEvaluationUsingObject(mpActionBeingEvaluated, mObjectId,
														  mpObject);
			}
		}
		else
		{
			AcDbSmartObjectPointer<AcDbAssocAction> pActionBeingEvaluated;

			if (mpActionBodyBeingEvaluated != nullptr)
			{
				pActionBeingEvaluated.open(mpActionBodyBeingEvaluated->parentAction(),
										   AcDb::kForRead, true);
			}
			else if (mpDependencyBeingEvaluated != nullptr)
			{
				pActionBeingEvaluated.open(mpDependencyBeingEvaluated->owningAction(),
										   AcDb::kForRead, true);
			}
			else if (mpDependencyBodyBeingEvaluated != nullptr)
			{
				AcDbSmartObjectPointer<AcDbAssocDependency> pDependencyBeingEvaluated(
						mpDependencyBodyBeingEvaluated->parentDependency(), AcDb::kForRead, true);

				if (pDependencyBeingEvaluated.openStatus() == Acad::eOk)
				{
					pActionBeingEvaluated.open(pDependencyBeingEvaluated->owningAction(),
											   AcDb::kForRead, true);
				}
			}

			if (pActionBeingEvaluated.openStatus() == Acad::eOk)
			{
				AcDbAssocEvaluationCallback* const pCallback =
						pActionBeingEvaluated->currentEvaluationCallback();

				if (pCallback != nullptr)
				{
					pCallback->endActionEvaluationUsingObject(pActionBeingEvaluated, mObjectId,
															  mpObject);
				}
			}
		}
	}
	const ACDB_CLASS* operator->() const { return mpObject; }
	ACDB_CLASS* operator->() { return mpObject; }
	operator const ACDB_CLASS*() const { return mpObject; }
	operator ACDB_CLASS*() { return mpObject; }

	bool isSubstituteObject() const { return mpSubstituteObject != nullptr; }
	Acad::ErrorStatus openStatus() const
	{
		return mpSubstituteObject != nullptr ? mSubstituteObjectErrorStatus
											 : mObjectPtr.openStatus();
	}
};

#include "icarx/IcArxPackPop.h"

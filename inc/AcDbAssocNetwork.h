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

#include "AcString.h"
#include "AcDbAssocAction.h"
#include "icarx/IcArxAssert.h"

#include "icarx/IcArxPackPush.h"

class ACDBCORE2D_PORT AcDbAssocNetwork : public AcDbAssocAction
{
public:
	ACRX_DECLARE_MEMBERS(AcDbAssocNetwork);

	explicit AcDbAssocNetwork(AcDbAssocCreateImpObject createImpObject = kAcDbAssocCreateImpObject);

	Acad::ErrorStatus addAction(const AcDbObjectId& actionId, bool alsoSetAsDatabaseOwner);
	Acad::ErrorStatus addActions(const AcDbObjectIdArray& actionIds, bool alsoSetAsDatabaseOwner);
	const AcDbObjectIdArray& getActions() const;
	const AcDbObjectIdArray& getActionsToEvaluate() const;
	static AcDbObjectId getInstanceFromDatabase(AcDbDatabase* pDatabase, bool createIfDoesNotExist,
												const AcString& dictionaryKey = L"");
	static AcDbObjectId getInstanceFromObject(const AcDbObjectId& owningObjectId,
											  bool createIfDoesNotExist,
											  bool addToTopLevelNetwork = true,
											  const AcString& dictionaryKey = L"");
	Acad::ErrorStatus ownedActionStatusChanged(AcDbAssocAction* pOwnedAction,
											   AcDbAssocStatus previousStatus);
	Acad::ErrorStatus removeAction(const AcDbObjectId& actionId, bool alsoEraseIt);
	Acad::ErrorStatus removeAllActions(bool alsoEraseThem);
	static Acad::ErrorStatus removeInstanceFromDatabase(AcDbDatabase* pDatabase, bool alsoEraseIt,
														const AcString& dictionaryKey = L"");
	static Acad::ErrorStatus removeInstanceFromObject(const AcDbObjectId& owningObjectId,
													  bool alsoEraseIt,
													  const AcString& dictionaryKey = L"");
};

class ACDBCORE2D_PORT AcDbAssocNetworkIterator
{
private:
	const AcDbAssocNetwork* const mpNetwork = nullptr;
	int mIndex = -1;

public:
	explicit AcDbAssocNetworkIterator(const AcDbAssocNetwork* pNetwork)
			: mpNetwork(pNetwork), mIndex(-1)
	{
		ICARX_ASSERT(mpNetwork);
	}

	AcDbObjectId current() const
	{
		if (mpNetwork != nullptr && 0 <= mIndex && mIndex < mpNetwork->getActions().length())
		{
			return mpNetwork->getActions()[mIndex];
		}
		else
		{
			ICARX_ASSERT(false);
			return AcDbObjectId::kNull;
		}
	}
	bool moveNext()
	{
		return mpNetwork!= nullptr ? ++mIndex < mpNetwork->getActions().length() : false;
	}
	void reset() { mIndex = -1; }
};

#include "icarx/IcArxPackPop.h"

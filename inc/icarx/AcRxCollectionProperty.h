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
***     Description: Declaration of AcRxCollectionProperty class
***
*****************************************************************************/
#pragma once

#include "AcRxPropertyBase.h"
#include "AcRxValueIterator.h"

#include "IcArxPackPush.h"

class AcRxCollectionProperty : public AcRxPropertyBase
{
	friend class AcRxCollectionPropertyImp;
	friend class AcRxCollectionPropertyOverrule;

protected:
	AcRxCollectionProperty(AcRxCollectionPropertyImp* pImp);
	ACBASE_PORT AcRxCollectionProperty(const ACHAR* name, const AcRxValueType& type,
						   const AcRxObject* owner = nullptr);
	ACBASE_PORT  ~AcRxCollectionProperty();

	ACBASE_PORT virtual AcRxValueIterator* subNewValueIterator(const AcRxObject* pO) const;
	ACBASE_PORT virtual Acad::ErrorStatus subTryGetCount(const AcRxObject* pO, int& count) const;

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcRxCollectionProperty, ACBASE_PORT);

	ACBASE_PORT AcRxValueIterator* newValueIterator(const AcRxObject* pO) const;
	ACBASE_PORT Acad::ErrorStatus tryGetCount(const AcRxObject* pO, int& count) const;
};

#include "IcArxPackPop.h"

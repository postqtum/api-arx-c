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
***     Description: Declaration of AcRxIndexedProperty class
***
*****************************************************************************/
#pragma once

#include "AcRxCollectionProperty.h"

#include "IcArxPackPush.h"

class AcRxDictionaryProperty : public AcRxCollectionProperty
{
	friend class AcRxDictionaryPropertyImp;

private:
	AcRxDictionaryProperty(AcRxDictionaryPropertyImp* pImp);

protected:
	ACBASE_PORT AcRxDictionaryProperty(const ACHAR* name, const AcRxValueType& type,
									   const AcRxObject* owner = nullptr);
	ACBASE_PORT ~AcRxDictionaryProperty();

	ACBASE_PORT virtual Acad::ErrorStatus subGetValue(const AcRxObject* pO, const ACHAR* key,
													  AcRxValue& value) const;
	ACBASE_PORT virtual Acad::ErrorStatus subSetValue(AcRxObject* pO, const ACHAR* key,
													  const AcRxValue& value) const;

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcRxDictionaryProperty, ACBASE_PORT);

	ACBASE_PORT Acad::ErrorStatus getValue(const AcRxObject* pO, const ACHAR* key,
										   AcRxValue& value) const;
	ACBASE_PORT Acad::ErrorStatus setValue(AcRxObject* pO, const ACHAR* key,
										   const AcRxValue& value) const;
};

#include "IcArxPackPop.h"

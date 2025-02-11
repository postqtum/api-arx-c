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

class AcRxIndexedProperty : public AcRxCollectionProperty
{
	friend class AcRxIndexedPropertyImp;
	friend class AcDbPolylineVerticesProperty;

private:
	AcRxIndexedProperty(AcRxIndexedPropertyImp* pImp);

protected:
	ACBASE_PORT AcRxIndexedProperty(const ACHAR* name, const AcRxValueType& type,
						const AcRxObject* owner = nullptr);
	ACBASE_PORT  ~AcRxIndexedProperty();

	virtual Acad::ErrorStatus subGetValue(const AcRxObject* pO, int index, AcRxValue& value) const;
	ACBASE_PORT virtual Acad::ErrorStatus subInsertValue(AcRxObject* pO, int index,
											 const AcRxValue& value) const;
	ACBASE_PORT virtual Acad::ErrorStatus subRemoveValue(AcRxObject* pO, int index) const;
	ACBASE_PORT virtual Acad::ErrorStatus subSetValue(AcRxObject* pO, int index,
													 const AcRxValue& value) const;

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcRxIndexedProperty, ACBASE_PORT);

	ACBASE_PORT Acad::ErrorStatus getValue(const AcRxObject* pO, int index, AcRxValue& value) const;
	ACBASE_PORT Acad::ErrorStatus insertValue(AcRxObject* pO, int index,
											  const AcRxValue& value) const;
	ACBASE_PORT Acad::ErrorStatus removeValue(AcRxObject* pO, int index) const;
	ACBASE_PORT Acad::ErrorStatus setValue(AcRxObject* pO, int index, const AcRxValue& value) const;
};

#include "IcArxPackPop.h"

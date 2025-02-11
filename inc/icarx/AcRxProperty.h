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
***     Description: Declaration of AcRxProperty class
***
*****************************************************************************/
#pragma once

#include "AcRxPropertyBase.h"

#include "IcArxPackPush.h"

class AcRxProperty : public AcRxPropertyBase
{
	friend class AcRxPropertyImp;
	friend class AcRxPropertyOverrule;

protected:
	AcRxProperty(AcRxPropertyImp*);
	ACBASE_PORT AcRxProperty(const ACHAR* name, const AcRxValueType& type,
				 const AcRxObject* owner = nullptr) noexcept;
	ACBASE_PORT ~AcRxProperty();

	ACBASE_PORT virtual Acad::ErrorStatus subGetValue(const AcRxObject* pO, AcRxValue& value) const;
	ACBASE_PORT virtual Acad::ErrorStatus subSetValue(AcRxObject* pO, const AcRxValue& value) const;

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcRxProperty, ACBASE_PORT);

	ACBASE_PORT Acad::ErrorStatus getValue(const AcRxObject* pO, AcRxValue& value) const;
	ACBASE_PORT Acad::ErrorStatus setValue(AcRxObject* pO, const AcRxValue& value) const;
};

#include "IcArxPackPop.h"

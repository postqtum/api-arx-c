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
***     Description: Declaration of AcRxBoxedValue class
***
*****************************************************************************/
#pragma once

#include "AcRxValue.h"

#include "IcArxPackPush.h"

class AcRxBoxedValue : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcRxBoxedValue, ACBASE_PORT);

	ACBASE_PORT AcRxObject* clone() const override;
	ACBASE_PORT AcRx::Ordering comparedTo(const AcRxObject* other) const override;
	ACBASE_PORT Acad::ErrorStatus copyFrom(const AcRxObject* other) override;
	ACBASE_PORT bool isEqualTo(const AcRxObject* other) const override;
	ACBASE_PORT static AcRxBoxedValue* newBoxedValueOnHeap(const AcRxValue& value);
	ACBASE_PORT const AcRxObject* rxObject() const;
	ACBASE_PORT AcRxObject* rxObject();
	virtual const AcRxValue* value() const = 0;
	virtual AcRxValue* value() = 0;
};

#include "IcArxPackPop.h"

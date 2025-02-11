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
***     Description: Declaration of AcRxBoxedValueOnStack class
***
*****************************************************************************/
#pragma once

#include "AcRxBoxedValue.h"

#include "IcArxPackPush.h"

class AcRxBoxedValueOnStack : public AcRxBoxedValue
{
private:
	AcRxValue& m_value;

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcRxBoxedValueOnStack, ACBASE_PORT);

	ACBASE_PORT AcRxBoxedValueOnStack(const AcRxValue& value);

	ACBASE_PORT const AcRxValue* value() const override;
	ACBASE_PORT AcRxValue* value() override;
};

#include "IcArxPackPop.h"

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
***     Description: Declaration of AcRxEnumTag class
***
*****************************************************************************/
#pragma once

#include "AcRxMember.h"

#include "IcArxPackPush.h"

class AcRxEnumTagImp;

class AcRxEnumTag : public AcRxMember
{
protected:
	AcRxEnumTag(AcRxEnumTagImp*);
	ACBASE_PORT ~AcRxEnumTag();

	ACBASE_PORT virtual AcString subAlternateLocalName() const;

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcRxEnumTag, ACBASE_PORT);

	ACBASE_PORT AcRxEnumTag(const ACHAR* name, const AcRxValue& value) noexcept;

	ACBASE_PORT AcString alternateLocalName() const;
	ACBASE_PORT const AcRxValue& value() const;
};

#include "IcArxPackPop.h"

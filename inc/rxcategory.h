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
***     Description:  Declaration of AcRxCategory class
***
*****************************************************************************/
#pragma once

#include "acbasedefs.h"
#include "adesk.h"
#include "acadstrc.h"
#include "pimplapi.h"

#include "icarx/AcRxMember.h"

#include "icarx/IcArxPackPush.h"

class AcRxCategory : public AcRxMember
{
private:
	ACBASE_PORT ~AcRxCategory();

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcRxCategory, ACBASE_PORT);

	ACBASE_PORT AcRxCategory(const ACHAR* name, AcRxCategory* pOwner) noexcept;

	ACBASE_PORT AcRxCategory* findDescendant(const ACHAR* name) const;
	ACBASE_PORT Acad::ErrorStatus removeChild(AcRxCategory* pChildCategory);
	ACBASE_PORT static AcRxCategory* rootCategory();
};

#include "icarx/IcArxPackPop.h"

ACBASE_PORT Acad::ErrorStatus acdbGetLegacyCategoryId(const AcRxCategory* pCategory, int& legacyId);
ACBASE_PORT Acad::ErrorStatus acdbSetLegacyCategoryId(AcRxCategory* pCategory, int legacyId);

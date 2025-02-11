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
***     Description: Declaration of AcRxMemberOverrule class
***
*****************************************************************************/
#pragma once

#include "AcRxOverruleBase.h"
#include "AcRxMember.h"

#include "IcArxPackPush.h"

class AcRxMemberOverrule : public AcRxOverruleBase
{
public:
	struct Record
	{
		AcRxMember* m_pMember = nullptr;
		AcRxMemberOverrule* m_pOverrule = nullptr;

		Record() = default;
		Record(AcRxMember* pMember, AcRxMemberOverrule* pOverrule)
				: m_pMember(pMember), m_pOverrule(pOverrule)
		{
		}
	};

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcRxMemberOverrule, ACBASE_PORT);

	ACBASE_PORT static Acad::ErrorStatus addOverrule(AcRxMember* pOverruledSubject,
													 AcRxMemberOverrule* pOverrule,
													 bool bAddAtLast = false);
	ACBASE_PORT static Acad::ErrorStatus removeOverrule(AcRxMember* pOverruledSubject,
														AcRxMemberOverrule* pOverrule);
	ACBASE_PORT static Acad::ErrorStatus removeOverrules(const AcArray<Record>& overrules);
};

#include "IcArxPackPop.h"

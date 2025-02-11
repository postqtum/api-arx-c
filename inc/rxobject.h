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
***     Description: Declaration of AcRxObject class
***
*****************************************************************************/
#pragma once

#include "acbasedefs.h"
#include "adesk.h"
#include "rxdefs.h"
#include "rxboiler.h"
#include "acadstrc.h"
#include "acdbport.h"
#include "AcDbCore2dDefs.h"
#include "icarx/AcOdBridge.h"

#include "icarx/IcArxPackPush.h"

class ADESK_NO_VTABLE AcRxObject : public AcOdBridge
{
	friend class AcRxQueryXOverrule;

protected:
	ACBASE_PORT AcRxObject();

	ACBASE_PORT virtual AcRxObject* subQueryX(const AcRxClass* protocolClass) const;

public:
	virtual ~AcRxObject() = default;

	ACBASE_PORT AcRxObject* queryX(const AcRxClass* protocolClass) const;
	ACBASE_PORT AcRxObject* x(const AcRxClass* protocolClass) const;
	inline bool isKindOf(const AcRxClass* aClass) const;
	ACBASE_PORT static AcRxClass* desc();
	static AcRxObject* cast(const AcRxObject* inPtr) { return const_cast<AcRxObject*>(inPtr); }
	static const wchar_t* className() { return L"AcRxObject"; }
	ACBASE_PORT virtual Acad::ErrorStatus copyFrom(const AcRxObject* other);
	ACBASE_PORT virtual AcRx::Ordering comparedTo(const AcRxObject* other) const;
	ACBASE_PORT virtual AcRxClass* isA() const;
	ACBASE_PORT virtual AcRxObject* clone() const;
	ACBASE_PORT virtual bool isEqualTo(const AcRxObject* other) const;
};

#include "icarx/IcArxPackPop.h"

#include "rxclass.h"

#define ACRX_PE_PTR(RxObj, PEClass) PEClass::cast(RxObj->queryX(PEClass::desc()))

#define ACRX_X_CALL(RxObj, PEClass) PEClass::cast(RxObj->x(PEClass::desc()))

#include "rxdict.h"

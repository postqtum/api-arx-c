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
***     Description: Declaration of AcBrTraverser class
***
*****************************************************************************/
#pragma once

#include "inc/adesk.h"
#include "inc/rxobject.h"
#include "inc/rxboiler.h"
#include "./brgbl.h"

class AcBrTraverserData;
class OdBrTraverser;

#include "inc/icarx/IcArxPackPush.h"

class AcBrTraverser : public AcRxObject
{
protected:
	OdBrTraverser* mpImp;

	AcBrTraverser();
	AcBrTraverser(const AcBrTraverser& src);
	AcBrTraverser& operator=(const AcBrTraverser& src);

public:
	ACRX_DECLARE_MEMBERS(AcBrTraverser);

	virtual ~AcBrTraverser();
	bool brepChanged() const;
	bool done() const;
	AcBr::ErrorStatus get(AcBrTraverserData*& traverserData) const;
	AcBr::ErrorStatus getValidationLevel(AcBr::ValidationLevel& validationLevel) const;
	bool isEqualTo(const AcRxObject* other) const;
	bool isNull() const;
	AcBr::ErrorStatus next();
	AcBr::ErrorStatus restart();
	AcBr::ErrorStatus set(AcBrTraverserData* traverserData);
	AcBr::ErrorStatus setValidationLevel(
			const AcBr::ValidationLevel& = *(AcBr::ValidationLevel*)nullptr);
};

#include "inc/icarx/IcArxPackPop.h"

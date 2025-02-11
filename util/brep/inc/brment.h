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
***     Description:
***
*****************************************************************************/
#pragma once

#include "inc/adesk.h"
#include "inc/rxobject.h"
#include "inc/rxboiler.h"
#include "brgbl.h"

class AcBrEntity;
class AcBrImpMeshEntity;

#include "inc/icarx/IcArxPackPush.h"

class AcBrMeshEntity : public AcRxObject
{
protected:
	AcBrImpMeshEntity* mpImp;

	AcBrMeshEntity();
	AcBrMeshEntity(const AcBrMeshEntity&);
	AcBrMeshEntity& operator=(const AcBrMeshEntity&);

public:
	ACRX_DECLARE_MEMBERS(AcBrMeshEntity);

	virtual ~AcBrMeshEntity();
	bool brepChanged() const;
	AcBr::ErrorStatus getEntityAssociated(AcBrEntity*& entity) const;
	AcBr::ErrorStatus getValidationLevel(AcBr::ValidationLevel& validationLevel) const;
	bool isEqualTo(const AcRxObject* other) const;
	bool isNull() const;
	AcBr::ErrorStatus setValidationLevel(
			const AcBr::ValidationLevel& = *(AcBr::ValidationLevel*)nullptr);
};

#include "inc/icarx/IcArxPackPop.h"

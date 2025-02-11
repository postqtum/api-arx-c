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
***     Description: Declaration of AcBrHit class
***
*****************************************************************************/
#pragma once

#include "inc/adesk.h"
#include "inc/rxobject.h"
#include "inc/rxboiler.h"
#include "brgbl.h"

class AcGePoint3d;
class AcBrEntity;
class AcBrHitData;
class AcBrImpHit;

typedef AcBrHitData AcBrHitPath;

#include "inc/icarx/IcArxPackPush.h"

class AcBrHit : public AcRxObject
{
protected:
	AcBrImpHit* mpImp;

public:
	ACRX_DECLARE_MEMBERS(AcBrHit);

	AcBrHit();
	AcBrHit(const AcBrHit& src);
	~AcBrHit();
	AcBrHit& operator=(const AcBrHit& src);
	bool brepChanged() const;
	AcBr::ErrorStatus get(AcBrHitData*& hitData) const;
	AcBr::ErrorStatus getEntityAssociated(AcBrEntity*& entity) const;
	AcBr::ErrorStatus getEntityEntered(AcBrEntity*& entityEntered) const;
	AcBr::ErrorStatus getEntityHit(AcBrEntity*& entityHit) const;
	AcBr::ErrorStatus getPoint(AcGePoint3d*& point) const;
	AcBr::ErrorStatus getPoint(AcGePoint3d& point) const;
	AcBr::ErrorStatus getValidationLevel(AcBr::ValidationLevel& validationLevel) const;
	bool isEqualTo(const AcRxObject* other) const;
	bool isNull() const;
	AcBr::ErrorStatus set(AcBrHitData* hitData);
	AcBr::ErrorStatus setHitPath(AcBrHitPath& hitPath);
	AcBr::ErrorStatus setValidationLevel(
			const AcBr::ValidationLevel& validationLevel = *(AcBr::ValidationLevel*)nullptr);
};

#include "inc/icarx/IcArxPackPop.h"

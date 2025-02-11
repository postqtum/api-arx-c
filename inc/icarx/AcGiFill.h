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
***     Description: Declaration of AcGiFill class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../rxboiler.h"

class AcGiImpFill;

#include "IcArxPackPush.h"

class AcGiFill : public AcRxObject
{
private:
	AcGiImpFill* mpImp = nullptr;

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcGiFill, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT AcGiFill();
	ACDBCORE2D_PORT AcGiFill(const AcGiFill&);
	ACDBCORE2D_PORT ~AcGiFill();

	ACDBCORE2D_PORT double deviation() const;
	ACDBCORE2D_PORT void setDeviation(double dev);
};

#include "IcArxPackPop.h"

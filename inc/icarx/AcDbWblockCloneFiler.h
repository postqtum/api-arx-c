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
***     Description: Declaration of AcDbWblockCloneFiler class
***
*****************************************************************************/
#pragma once

#include "AcDbDeepCloneFiler.h"

#include "IcArxPackPush.h"

class AcDbWblockCloneFiler : public AcDbDeepCloneFiler
{
	friend class AcDbSystemInternals;

public:
	ACRX_DECLARE_MEMBERS(AcDbWblockCloneFiler);

	AcDbWblockCloneFiler();

	virtual Acad::ErrorStatus addReferences(AcDbIdRefQueue&) override;
	AcDb::FilerType filerType() const override;
	virtual bool getNextHardObject(AcDbObjectId& id);
	virtual bool moreHardObjects() const;
	virtual bool usesReferences() const override;
};

#include "IcArxPackPop.h"

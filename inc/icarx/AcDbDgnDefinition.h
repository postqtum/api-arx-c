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
***     Description: Declaration of AcDbDgnDefinition class
***
*****************************************************************************/
#pragma once

#include "AcDbUnderlayDefinition.h"

#include "IcArxPackPush.h"

class AcDbDgnDefinition : public AcDbUnderlayDefinition
{
private:
	const AcDbUnderlayHost* getUnderlayHost() const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbDgnDefinition);

	AcDbDgnDefinition();
	~AcDbDgnDefinition();

	void setShowRasterRef(bool bShow);
	void setUseMasterUnits(bool useMaster);
	void setXrefDepth(int depth);
	bool showRasterRef() const;
	bool useMasterUnits() const;
	int xrefDepth() const;
};

#include "IcArxPackPop.h"

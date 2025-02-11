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
***     Description: Declaration of AcDbIdMappingIter class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "AcDbIdMapping.h"

#include "IcArxPackPush.h"

class AcDbIdMappingIter : public AcRxObject
{
	friend class AcDbSystemInternals;

private:
	AcDbImpIdMappingIter* mpImp;

public:
	ACRX_DECLARE_MEMBERS(AcDbIdMappingIter);

	AcDbIdMappingIter(const AcDbIdMapping&);
	~AcDbIdMappingIter();
	AcDbIdMappingIter(const AcDbIdMappingIter&) = delete;
	AcDbIdMappingIter& operator=(const AcDbIdMappingIter&) = delete;

	virtual bool done();
	virtual bool getMap(AcDbIdPair&);
	virtual Acad::ErrorStatus iterateOn(const AcDbIdMapping&);
	virtual bool next();
	virtual void start();
};

#include "IcArxPackPop.h"

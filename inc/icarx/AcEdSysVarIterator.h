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
***     Description: Declaration of AcEdSysVarIterator class
***
*****************************************************************************/
#pragma once

#include "../acedinpt.h"

class AcRxVariable;
class AcEdImpSysVarIterator;

#include "IcArxPackPush.h"

class ACAD_PORT AcEdSysVarIterator
{
private:
	AcEdImpSysVarIterator* m_pImp = nullptr;

public:
	AcEdSysVarIterator();
	~AcEdSysVarIterator();

	bool done() const;
	const AcRxVariable* getSysVar();
	void reset();
	void step();
};

#include "IcArxPackPop.h"

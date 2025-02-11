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
***     Description: Declaration of AcDbIndexUpdateDataIterator class
***
*****************************************************************************/
#pragma once

#include "../dbmain.h"

class AcDbIndexUpdateData;
class OdDbIndexUpdateDataIterator;

#include "IcArxPackPush.h"

class AcDbIndexUpdateDataIterator
{
private:
	OdDbIndexUpdateDataIterator* m_Imp;

public:
	AcDbIndexUpdateDataIterator(const AcDbIndexUpdateData* p);
	~AcDbIndexUpdateDataIterator();
	AcDbIndexUpdateDataIterator(const AcDbIndexUpdateDataIterator&) = delete;
	AcDbIndexUpdateDataIterator& operator=(const AcDbIndexUpdateDataIterator&) = delete;

	Acad::ErrorStatus currentData(AcDbObjectId& id, uint8_t& flags,
								  IcArx::Integers::ULongPtr& data) const;
	bool done();
	void next();
	void start();
};

#include "IcArxPackPop.h"

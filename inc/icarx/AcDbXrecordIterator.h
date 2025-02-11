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
***     Description: Declaration of AcDbXrecordIterator class
***
*****************************************************************************/
#pragma once

#include "../adsdef.h"
#include "AcDbXrecord.h"

#define ACDB_XRECORD_ITERATOR_CLASS ACRX_T(/*MSG0*/ "AcDbXrecordClass")

class AcDbDatabase;

#include "IcArxPackPush.h"

class AcDbXrecordIterator : public AcRxObject
{
	friend class AcDbXrecord;
	friend class AcDbImpXrecord;

protected:
	AcDbXrecordIterator() = default;

public:
	ACRX_DECLARE_MEMBERS(AcDbXrecordIterator);

	AcDbXrecordIterator(const AcDbXrecord* pXrecord);
	~AcDbXrecordIterator();

	int curRestype() const;
	bool done() const;
	Acad::ErrorStatus getCurResbuf(resbuf& outItem, AcDbDatabase* db) const;
	ACDBCORE2D_PORT Acad::ErrorStatus insertRbChain(const resbuf& pRb);
	ACDBCORE2D_PORT Acad::ErrorStatus modifyCurResbuf(const resbuf& item);
	Acad::ErrorStatus next();
	ACDBCORE2D_PORT Acad::ErrorStatus removeCurResbuf();
	void start();
};

#include "IcArxPackPop.h"

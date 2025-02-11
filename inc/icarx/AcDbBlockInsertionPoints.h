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
***     Description: Declaration of AcDbBlockInsertionPoints class
***
*****************************************************************************/
#pragma once

#include "AcRxProtocolReactor.h"
#include "../gept3dar.h"
#include "../gevc3dar.h"

class AcDbBlockTableRecord;
class AcDbBlockReference;

#include "IcArxPackPush.h"

class AcDbBlockInsertionPoints : public AcRxProtocolReactor
{
public:
	ACRX_DECLARE_MEMBERS(AcDbBlockInsertionPoints);

	virtual Acad::ErrorStatus getInsertionPoints(const AcDbBlockTableRecord* pBlock,
												 const AcDbBlockReference* pBlkRef,
												 AcGePoint3dArray& insPts,
												 AcGeVector3dArray& alignmentDirections) = 0;
};

#include "IcArxPackPop.h"

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
***     Description: Declaration of AcApDocumentIterator class
***
*****************************************************************************/
#pragma once

#include "../accoredefs.h"
#include "../rxobject.h"

class AcApDocument;

#include "IcArxPackPush.h"

class ACCORE_PORT ADESK_NO_VTABLE AcApDocumentIterator : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcApDocumentIterator);

	virtual AcApDocument* document() = 0;
	virtual bool done() const = 0;
	virtual void step() = 0;
};

#include "IcArxPackPop.h"

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
***     Description: Declaration of AcEdCommand class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../rxresource.h"

typedef void (*AcRxFunctionPtr)();
class AcEdUIContext;
class AcEdCommandReactor;

#include "IcArxPackPush.h"

class AcEdCommand : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcEdCommand);

	virtual AcEdUIContext* UIContext() const = 0;
	virtual AcRxFunctionPtr functionAddr() const = 0;
	virtual int32_t commandFlags() const = 0;
	virtual const ACHAR* globalName() const = 0;
	virtual const ACHAR* localName() const = 0;
	virtual const AcRxResourceInstance& resourceInstance() const = 0;
	virtual int functionCode() const = 0;
	virtual void* commandApp() const = 0;
	virtual void commandUndef(bool undefIt) = 0;
	virtual void functionAddr(AcRxFunctionPtr fhdl) = 0;
	virtual void functionCode(int fcode) = 0;
	void addReactor(AcEdCommandReactor* pReactor);
	uint8_t defaultCommandVersion() const;
	void removeReactor(AcEdCommandReactor* pReactor);
};

#include "IcArxPackPop.h"

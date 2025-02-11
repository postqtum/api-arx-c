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
***     Description: Declaration of AcRxProtocolReactorManagerFactory class
***
*****************************************************************************/
#pragma once

#include "../rxsrvice.h"
#include "AcRxProtocolReactorManager.h"

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcRxProtocolReactorManagerFactory : public AcRxService
{
public:
	ACRX_DECLARE_MEMBERS(AcRxProtocolReactorManagerFactory);

	virtual AcRxProtocolReactorManager* createReactorManager(AcRxClass* pRxClass) const = 0;
};

#include "IcArxPackPop.h"

#define acrxProtocolReactors                 \
	AcRxProtocolReactorManagerFactory::cast( \
			acrxServiceDictionary->at(ACRX_PROTOCOL_REACTOR_MANAGER))

#define ACRX_PROTOCOL_REACTOR_MANAGER_AT(acrxClass) \
	acrxProtocolReactors->createReactorManager(acrxClass)

#define ACRX_PROTOCOL_REACTOR_LIST_AT(acrxClass, reactorClass) \
	ACRX_PROTOCOL_REACTOR_MANAGER_AT(acrxClass)->createReactorList(reactorClass)

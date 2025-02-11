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
***     Description: Declaration of AcRxKernel class
***
*****************************************************************************/
#pragma once

#include "rxsrvice.h"

class AcRxClass;
class AcRxDictionary;

#include "icarx/IcArxPackPush.h"

class ADESK_NO_VTABLE AcRxKernel : public AcRxService
{
public:
	ACRX_DECLARE_MEMBERS(AcRxKernel);

	AcRxKernel();
	~AcRxKernel();

	virtual AcRxDictionary* newAcRxDictionary(bool sorted = true,
											  bool ignoreCase = false) = 0;
	virtual AcRxDictionary* newAcRxDictionary(const AcRxClass* filter) = 0;
	virtual AcRxDictionary* newAcRxDictionary(uint32_t length, bool delObjects,
											  bool sorted = true,
											  bool ignoreCase = false) = 0;
};

#include "icarx/IcArxPackPop.h"

#define acrxKernel                                                                        \
	AcRxKernel::cast(AcRxDictionary::cast(acrxSysRegistry()->at(ACRX_SERVICE_DICTIONARY)) \
							 ->at(ACRX_KERNEL_SERVICES))

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
***     Description: Declaration of AcRxRefersToAttribute class
***
*****************************************************************************/
#pragma once

#include "../rxprop.h"
#include "AcRxAttribute.h"

using FindPropertyCallback = const AcRxPropertyBase* (*)(const AcRxObject* pObject,
														const ACHAR* pszPropName);
using ConvertValueCallback = bool (*)(const AcRxPropertyBase* pProperty, AcRxValue& value);

#include "IcArxPackPush.h"

class AcRxRefersToAttribute : public AcRxAttribute
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcRxRefersToAttribute, ACBASE_PORT);

	ACBASE_PORT AcRxRefersToAttribute(const ACHAR* path);

	ACBASE_PORT static const AcRxPropertyBase* parseReference(const ACHAR* path,
															  const AcRxObject* pObject,
															  FindPropertyCallback find = nullptr,
															  ConvertValueCallback convert = nullptr);
	ACBASE_PORT const ACHAR* path() const;
};

#include "IcArxPackPop.h"

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
***     Description: Declaration of AcRxAttributeCollection class
***
*****************************************************************************/
#pragma once

#include "AcRxAttribute.h"

class AcRxAttributeCollectionImp;

#include "IcArxPackPush.h"

class AcRxAttributeCollection : public Pimpl::ApiPart<void, AcRxAttributeCollectionImp>
{
public:
	ACBASE_PORT AcRxAttributeCollection();

	ACBASE_PORT Acad::ErrorStatus add(const AcRxAttribute* attribute);
	ACBASE_PORT int count() const;
	ACBASE_PORT AcRxAttribute* get(const AcRxClass* type);
	ACBASE_PORT const AcRxAttribute* get(const AcRxClass* type) const;
	ACBASE_PORT const AcRxAttribute* getAt(int index) const;
	ACBASE_PORT AcRxAttribute* getAt(int index);
	ACBASE_PORT Acad::ErrorStatus override(const AcRxAttribute* attribute);
	ACBASE_PORT Acad::ErrorStatus remove(const AcRxAttribute* attribute);
};

#include "IcArxPackPop.h"

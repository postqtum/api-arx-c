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
***     Description: Declaration of AcRxMemberCollection class
***
*****************************************************************************/
#pragma once

#include "AcRxMember.h"

class AcRxMemberCollectionImp;

#include "IcArxPackPush.h"

class AcRxMemberCollection : public Pimpl::ApiPart<void, AcRxMemberCollectionImp>
{
	friend class AcRxMemberCollectionImp;

private:
	AcRxMemberCollection(AcRxMemberCollectionImp* pImp);

protected:
	ACBASE_PORT AcRxMemberCollection();

public:
	ACBASE_PORT virtual ~AcRxMemberCollection();

	virtual int count() const;
	virtual AcRxMember* getAt(int index) const;
};

#include "IcArxPackPop.h"

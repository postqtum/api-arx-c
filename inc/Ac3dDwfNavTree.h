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
***     Description: Declaration of Ac3dDwfNavTreeNode class
***
*****************************************************************************/
#pragma once

#include "rxobject.h"
#include "AcString.h"
#include "acarray.h"

class Ac3dDwfNavTreeNode : public AcRxObject
{
public:
	virtual bool addChild(const Ac3dDwfNavTreeNode* node) = 0;
	virtual const AcArray<const Ac3dDwfNavTreeNode*>& children() const = 0;
	virtual const AcString& displayName() const = 0;
	virtual bool isBlock() const = 0;
	virtual bool isGroup() const = 0;
	virtual const AcArray<long>& keys() const = 0;
	virtual int nDescendants() const = 0;
	virtual bool removeChild(const Ac3dDwfNavTreeNode* node) = 0;
};

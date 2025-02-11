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
***     Description: Declaration of AcLyRelExpr, AcLyAndExpr, AcLyBoolExpr classes
***
*****************************************************************************/
#pragma once

#include "../acarray.h"

#include "IcArxPackPush.h"

class AcLyRelExpr
{
public:
	virtual ~AcLyRelExpr() = default;

	virtual const ACHAR* getConstant() const = 0;
	virtual const ACHAR* getVariable() const = 0;
};

class AcLyAndExpr
{
public:
	virtual ~AcLyAndExpr() = default;

	virtual const AcArray<AcLyRelExpr*>& getRelExprs() const = 0;
};

class AcLyBoolExpr
{
public:
	virtual ~AcLyBoolExpr() = default;

	virtual const AcArray<AcLyAndExpr*>& getAndExprs() const = 0;
};

#include "IcArxPackPop.h"

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
***     Description: Declaration of AcUnderlayLayer class
***
*****************************************************************************/
#pragma once

#include "../dbmain.h"

class AcImpUnderlayLayer;

#include "IcArxPackPush.h"

class AcUnderlayLayer
{
public:
	enum State
	{
		kOff = 0,
		kOn = 1
	};

private:
	AcImpUnderlayLayer* m_pImpUnderlayLayer;

public:
	AcUnderlayLayer();
	ACDBCORE2D_PORT AcUnderlayLayer(AcUnderlayLayer const&);
	ACDBCORE2D_PORT ~AcUnderlayLayer();
	ACDBCORE2D_PORT AcUnderlayLayer const& operator=(AcUnderlayLayer const&);
	friend ACDBCORE2D_PORT bool operator==(AcUnderlayLayer const& l, AcUnderlayLayer const& r);

	AcString name() const;
	Acad::ErrorStatus setName(const AcString& name);
	Acad::ErrorStatus setState(State state);
	State state() const;
};

#include "IcArxPackPop.h"

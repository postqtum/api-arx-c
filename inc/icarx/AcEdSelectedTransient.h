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
***     Description: Declaration of AcEdSelectedTransient class
***
*****************************************************************************/
#pragma once

#include "../acarray.h"
#include "../acadstrc.h"
#include "AcGiTransientManager.h"

class AcGsDCRect;
class AcGiDrawable;
class AcEdSelectedTransientImp;

#include "IcArxPackPush.h"

class AcEdSelectedTransient
{
	friend class AcEdTransientSelectionInternals;

protected:
	AcEdSelectedTransientImp* mImp;

public:
	AcEdSelectedTransient();
	AcEdSelectedTransient(const AcEdSelectedTransient&);
	AcEdSelectedTransient& operator=(const AcEdSelectedTransient&);
	~AcEdSelectedTransient();

	AcGiDrawable* drawable();
	IcArx::Integers::GsMarker marker();
	AcGiTransientDrawingMode mode();
	AcGiDrawable* parent();
	int subDrawingMode();
};

#include "IcArxPackPop.h"

Acad::ErrorStatus acedSelectTransients(const AcGsDCRect& rect, int viewportNumber,
									   AcArray<AcEdSelectedTransient>& result);

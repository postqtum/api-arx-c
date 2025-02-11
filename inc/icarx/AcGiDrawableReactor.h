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
***     Description: Declaration of AcGiDrawableReactor class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"

#include "AcGiDrawable.h"

#include "IcArxPackPush.h"

class AcGiDrawableReactor : public AcRxObject
{
public:
	enum RegenFlags
	{
		k2DRegen,
		k3DRegen
	};

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcGiDrawableReactor, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT virtual void added(AcGiDrawable* /*pDrawable*/,
									   IcArx::Integers::IntDbId /*parentID*/,
									   IcArx::Integers::LongPtr /*databasePtr*/)
	{
	}
	ACDBCORE2D_PORT virtual void beginRegen(AcGiDrawable* /*pDrawable*/, RegenFlags /*flags*/) {}
	ACDBCORE2D_PORT virtual void endRegen(AcGiDrawable* /*pDrawable*/, RegenFlags /*flags*/) {}
	ACDBCORE2D_PORT virtual void erased(AcGiDrawable* /*pDrawable*/) {}
	ACDBCORE2D_PORT virtual void erased(AcGiDrawable* /*pDrawable*/,
										IcArx::Integers::IntDbId /*parentID*/)
	{
	}
	ACDBCORE2D_PORT virtual void handOverTo(AcGiDrawable* /*pDrawableFrom*/,
											AcGiDrawable* /*pDrawableTo*/)
	{
	}
	ACDBCORE2D_PORT virtual void modified(AcGiDrawable* /*pDrawable*/) {}
	ACDBCORE2D_PORT virtual void modified(AcGiDrawable* /*pDrawable*/,
										  IcArx::Integers::IntDbId /*parentID*/)
	{
	}
};

#include "IcArxPackPop.h"

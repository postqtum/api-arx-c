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
***     Description: Declaration of AcGiTransientManager classes
***
*****************************************************************************/
#pragma once

#include "../acarray.h"

enum AcGiTransientDrawingMode
{
	kAcGiMain = 0,
	kAcGiSprite,
	kAcGiDirectShortTerm,
	kAcGiHighlight,
	kAcGiDirectTopmost,
	kAcGiContrast,
	kAcGiDrawingModeCount
};

class AcGiDrawable;

#include "IcArxPackPush.h"

class AcGiTransientManager
{
public:
	virtual ~AcGiTransientManager() = default;

	virtual bool addChildTransient(AcGiDrawable* pDrawable, AcGiDrawable* pParentDrawable) = 0;
	virtual bool addTransient(AcGiDrawable* pDrawable, AcGiTransientDrawingMode mode,
							  int subDrawingMode, const AcArray<int>& viewportNumbers) = 0;
	virtual bool eraseChildTransient(AcGiDrawable* pDrawable, AcGiDrawable* pParentDrawable) = 0;
	virtual bool eraseTransient(AcGiDrawable* pDrawable, const AcArray<int>& viewportNumbers) = 0;
	virtual bool eraseTransients(AcGiTransientDrawingMode mode, int subDrawingMode,
								 const AcArray<int>& viewportNumbers) = 0;
	virtual int getFreeSubDrawingMode(AcGiTransientDrawingMode mode, int& subDrawingMode,
									  const AcArray<int>& viewportNumbers) = 0;
	virtual void updateChildTransient(AcGiDrawable* pDrawable, AcGiDrawable* pParentDrawable) = 0;
	virtual void updateTransient(AcGiDrawable* pDrawable, const AcArray<int>& viewportNumbers) = 0;
};

#include "IcArxPackPop.h"

AcGiTransientManager* acgiGetTransientManager();
void acgiSetTransientManager(AcGiTransientManager* transientManager);

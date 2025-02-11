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
***     Description: Declaration of AcGiDrawableEvent class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "AcGiDrawableReactor.h"

#define acgiDrawableEvent (&AcGiDrawableEvent::instance())

#include "IcArxPackPush.h"

class AcGiDrawableEvent : public AcRxObject
{
private:
	class AcGiImpDrawableEvent* m_pImp;

private:
	AcGiDrawableEvent();
	AcGiDrawableEvent(const AcGiDrawableEvent&);
	~AcGiDrawableEvent();
	void operator=(const AcGiDrawableEvent&);

public:
	ACRX_DECLARE_MEMBERS(AcGiDrawableEvent);

	virtual void addReactor(AcGiDrawableReactor* pReactor);
	ACDBCORE2D_PORT static AcGiDrawableEvent& instance();
	virtual void removeReactor(AcGiDrawableReactor* pReactor);
	virtual void sendAdded(AcGiDrawable* pDrawable, IcArx::Integers::IntDbId parentID,
						   IcArx::Integers::LongPtr databasePtr);
	virtual void sendBeginRegen(AcGiDrawable* pDrawable, AcGiDrawableReactor::RegenFlags flags);
	virtual void sendEndRegen(AcGiDrawable* pDrawable, AcGiDrawableReactor::RegenFlags flags);
	virtual void sendErased(AcGiDrawable* pDrawable);
	virtual void sendErased(AcGiDrawable* pDrawable, IcArx::Integers::IntDbId parentID);
	virtual void sendHandOverTo(AcGiDrawable* pDrawableFrom, AcGiDrawable* pDrawableTo);
	virtual void sendModified(AcGiDrawable* pDrawable);
	virtual void sendModified(AcGiDrawable* pDrawable, IcArx::Integers::IntDbId parentID);
};

#include "IcArxPackPop.h"

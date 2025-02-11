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
***     Description: Declaration of AcApDocManagerReactor class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../accoredefs.h"
#include "../AcApDocLockmode.h"

class AcApDocument;

#include "IcArxPackPush.h"

class ACCORE_PORT ADESK_NO_VTABLE AcApDocManagerReactor : public AcRxObject
{
private:
	int8_t mVeto = 0;
	friend class AcApDocImpManager;

public:
	ACRX_DECLARE_MEMBERS(AcApDocManagerReactor);

protected:
	AcApDocManagerReactor() = default;
	Acad::ErrorStatus veto();

public:
	virtual ~AcApDocManagerReactor() = default;

	virtual void documentActivated(AcApDocument*) {}
	virtual void documentActivationModified(bool) {}
	virtual void documentBecameCurrent(AcApDocument*) {}
	virtual void documentCreateCanceled(AcApDocument*) {}
	virtual void documentCreateStarted(AcApDocument*) {}
	virtual void documentCreated(AcApDocument*) {}
	virtual void documentDestroyed(const ACHAR*) {}
	virtual void documentLockModeChangeVetoed(AcApDocument*, const ACHAR*) {}
	virtual void documentLockModeChanged(AcApDocument*, AcAp::DocLockMode, AcAp::DocLockMode,
										 AcAp::DocLockMode, const ACHAR*)
	{
	}
	virtual void documentLockModeWillChange(AcApDocument*, AcAp::DocLockMode, AcAp::DocLockMode,
											AcAp::DocLockMode, const ACHAR*)
	{
	}
	virtual void documentTitleUpdated(AcApDocument*) {}
	virtual void documentToBeActivated(AcApDocument*) {}
	virtual void documentToBeDeactivated(AcApDocument*) {}
	virtual void documentToBeDestroyed(AcApDocument*) {}
};

#include "IcArxPackPop.h"

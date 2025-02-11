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
***     Description: Declaration of AcEdUpdateDisplayPauseScope class
***
*****************************************************************************/
#pragma once

#include "../acadapidef.h"

ACAD_PORT bool acedIsUpdateDisplayPaused(void);
ACAD_PORT void acedUpdateDisplayPause(bool bEnable);

#include "IcArxPackPush.h"

class AcEdUpdateDisplayPauseScope
{
protected:
	bool m_bOldValue = false;
	bool m_bDidSet = false;

public:
	AcEdUpdateDisplayPauseScope() = default;
	AcEdUpdateDisplayPauseScope(bool bEnable) { SaveAndSet(bEnable); }
	~AcEdUpdateDisplayPauseScope() noexcept { Restore(); }

	void Restore()
	{
		if (m_bDidSet)
		{
			m_bDidSet = false;
			acedUpdateDisplayPause(m_bOldValue);
		}
	}
	void SaveAndSet(bool bDisable)
	{
		if (!m_bDidSet)
		{
			m_bDidSet = true;
			m_bOldValue = acedIsUpdateDisplayPaused();
			acedUpdateDisplayPause(bDisable);
		}
	}
};

#include "IcArxPackPop.h"

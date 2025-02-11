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
***     Description: Declaration of AcEdCommandEventArgs class
***
*****************************************************************************/
#pragma once

#include "../AdAChar.h"

class AcEdImpCommandEventArgs;

enum AcEdCommandStatusFlags
{
	kCmdStatusNone = 0x00000,
	kCmdStatusCancel = 0x00001,
	kCmdStatusFailed = 0x00002,
};

AcEdCommandStatusFlags& operator|=(AcEdCommandStatusFlags& f, int i);
AcEdCommandStatusFlags& operator&=(AcEdCommandStatusFlags& f, int i);

#include "IcArxPackPush.h"

class AcEdCommandEventArgs
{
	friend class AcEdImpCommandEventArgs;

protected:
	AcEdImpCommandEventArgs* m_pImp;

protected:
	AcEdCommandEventArgs(AcEdImpCommandEventArgs* pImp);
	AcEdCommandEventArgs(const AcEdCommandEventArgs& other);
	AcEdCommandEventArgs& operator=(const AcEdCommandEventArgs& other);

public:
	const ACHAR* groupName() const;
	void setStatus(AcEdCommandStatusFlags flags);
	AcEdCommandStatusFlags status() const;
};

#include "IcArxPackPop.h"

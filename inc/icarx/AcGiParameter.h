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
***     Description: Declaration of AcGiParameter classes
***
*****************************************************************************/
#pragma once

#include "../rxcopyonwriteobject.h"

class AcGiParameterImp;

#include "IcArxPackPush.h"

class AcGiParameter : public AcRxCopyOnWriteObject
{
	friend class AcGiParameterImp;

public:
	ACRX_DECLARE_MEMBERS_READWRITE_EXPIMP(AcGiParameter, AcGiParameterImp, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT AcGiParameter(AcGiParameterImp* pImp);
	ACDBCORE2D_PORT AcGiParameter(const AcGiParameter& other);
	ACDBCORE2D_PORT const AcGiParameter& operator=(const AcGiParameter& other);
};

#include "IcArxPackPop.h"

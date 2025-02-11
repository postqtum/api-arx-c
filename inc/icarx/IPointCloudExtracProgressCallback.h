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
***     Description: Declaration of IPointCloudExtracProgressCallback class
***
*****************************************************************************/
#pragma once

#include "../acdbport.h"

class AcString;

#include "IcArxPackPush.h"

class ACDB_PORT IPointCloudExtracProgressCallback
{
public:
	IPointCloudExtracProgressCallback() = default;
	virtual ~IPointCloudExtracProgressCallback() = default;

	virtual void cancel() = 0;
	virtual bool cancelled() const = 0;
	virtual void end() = 0;
	virtual void updateCaption(const AcString& caption) = 0;
	virtual void updateProgress(int progress) = 0;
	virtual void updateRemainTime(double remainTime) = 0;
};

#include "IcArxPackPop.h"

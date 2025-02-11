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
***     Description: Declaration of AcGiSentScanLines class
***
*****************************************************************************/
#pragma once

#include "../adesk.h"

#include "IcArxPackPush.h"

struct AcGiSentScanLines
{
	enum IsmRequestStatus
	{
		eOk,
		eInvalidInput,
		eInvalidColorDepth,
		eInvalidPixelRequest,
		eInvalidDeliveryMethod,
		eNoValidCompressors,
		eInsufficientMemory,
	};

	int8_t* mpPixelBuffer;
	uint32_t mRowBytes;
	void* mpImageId;
	int16_t mIsCancelled;
	int16_t mHasFailed;
	uint32_t mBytes;
	IsmRequestStatus mRequestStatus;
};

#include "IcArxPackPop.h"

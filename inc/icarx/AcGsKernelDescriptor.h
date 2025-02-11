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
***     Description: Declaration of AcGsKernelDescriptor class
***
*****************************************************************************/
#pragma once

#include "AcGiKernelDescriptor.h"

#ifndef DRAWBRIDGE_API
#	define DRAWBRIDGE_API
#endif
#ifndef DRAWBRIDGE_DATA_API
#	define DRAWBRIDGE_DATA_API __declspec(dllimport)
#endif

#include "IcArxPackPush.h"

class AcGsKernelDescriptor : public AcGiKernelDescriptor
{
public:
	static DRAWBRIDGE_DATA_API const AcUniqueString* k2DDrawing;
	static DRAWBRIDGE_DATA_API const AcUniqueString* k3DDrawing;
	static DRAWBRIDGE_DATA_API const AcUniqueString* k3DDrawing2;
	static DRAWBRIDGE_DATA_API const AcUniqueString* k3DSelection;
	static DRAWBRIDGE_DATA_API const AcUniqueString* k3DRapidRTRendering;

public:
	void addSupport(const AcUniqueString* capability)
	{
		if (capability)
			append(capability);
	}
	bool requires(const AcUniqueString* capability) const
	{
		return capability ? contains(capability) : false;
	}
};

#include "IcArxPackPop.h"

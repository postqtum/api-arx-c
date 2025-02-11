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
***     Description: Declaration of AcGiKernelDescriptor and AcGiGraphicsKernel classes
***
*****************************************************************************/
#pragma once

#include "../acarray.h"
#include "../AcString.h"

#include "IcArxPackPush.h"

class AcGiKernelDescriptor : public AcArray<const AcUniqueString*>
{
public:
	void addRequirement(const AcUniqueString* capability)
	{
		if (capability != nullptr)
			append(capability);
	}

	bool supports(const AcGiKernelDescriptor& desc) const
	{
		int len = desc.length();
		for (int i = 0; i < len; i++)
		{
			if (!contains(desc[i]) && desc[i] != nullptr)
				return false;
		}
		return true;
	}

	bool supports(const AcUniqueString* capability) const
	{
		return capability ? contains(capability) : false;
	}
};

class AcGiGraphicsKernel
{
private:
	AcGiKernelDescriptor m_descriptor;

public:
	virtual ~AcGiGraphicsKernel() = default;

	virtual const AcGiKernelDescriptor& getDescriptor() const { return m_descriptor; }
};

#include "IcArxPackPop.h"

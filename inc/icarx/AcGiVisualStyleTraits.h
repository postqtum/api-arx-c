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
***     Description: Declaration of AcGiVisualStyleTraits class
***
*****************************************************************************/
#pragma once

#include "AcGiDrawableTraits.h"

class AcGiVisualStyle;

#include "IcArxPackPush.h"

class AcGiVisualStyleTraits : public AcGiDrawableTraits
{
public:
	ACRX_DECLARE_MEMBERS(AcGiVisualStyleTraits);

	virtual const AcGiVisualStyle& acgiVisualStyle() const = 0;
	virtual void setAcGiVisualStyle(const AcGiVisualStyle& visualStyle) = 0;
};

#include "IcArxPackPop.h"

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
***     Description: Declaration of AcGiMaterialTexture, AcGiImageTexture,
***     AcGiProceduralTexture classes
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../rxboiler.h"

#include "IcArxPackPush.h"

class AcGiMaterialTexture : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcGiMaterialTexture);

	virtual bool operator==(const AcGiMaterialTexture& texture) const
	{
		return (texture.isA() == isA());
	}
};

class AcGiImageTexture : public AcGiMaterialTexture
{
public:
	ACRX_DECLARE_MEMBERS(AcGiImageTexture);
};

class AcGiProceduralTexture : public AcGiMaterialTexture
{
public:
	enum Type
	{
		kWood = 0,
		kMarble,
		kGeneric,
	};

	ACRX_DECLARE_MEMBERS(AcGiProceduralTexture);
};

#include "IcArxPackPop.h"

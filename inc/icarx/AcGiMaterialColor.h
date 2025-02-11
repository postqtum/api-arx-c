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
***     Description: Declaration of AcGiMaterialColor class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../rxboiler.h"
#include "AcGiMaterialDefs.h"

class AcGiImpMaterialColor;

#include "IcArxPackPush.h"

class AcGiMaterialColor : public AcRxObject
{
	friend class AcGiImpMaterialColor;

public:
	enum Method
	{
		kInherit = 0,
		kOverride,
	};

private:
	AcGiImpMaterialColor* mpAcGiImpMaterialColor;

public:
	ACGIMAT_IMPEXP static const AcGiMaterialColor kNull;

public:
	ACRX_DECLARE_MEMBERS(AcGiMaterialColor);

	AcGiMaterialColor();
	AcGiMaterialColor(const AcGiMaterialColor& matColor);
	~AcGiMaterialColor();
	AcGiMaterialColor& operator=(const AcGiMaterialColor& matColor);
	bool operator==(const AcGiMaterialColor& matColor) const;

	virtual const AcCmEntityColor& color() const;
	virtual double factor() const;
	virtual Method method() const;
	virtual void set(const AcGiMaterialColor& matColor);
	virtual void setColor(const AcCmEntityColor& color);
	virtual void setFactor(double dFactor);
	virtual void setMethod(Method method);
};

#include "IcArxPackPop.h"

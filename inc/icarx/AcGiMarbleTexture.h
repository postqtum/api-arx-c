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
***     Description: Declaration of AcGiMarbleTexture classes
***
*****************************************************************************/
#pragma once

#include "AcGiMaterialTexture.h"

class AcGiImpMarbleTexture;

#include "IcArxPackPush.h"

class AcGiMarbleTexture : public AcGiProceduralTexture
{
private:
	AcGiImpMarbleTexture* mpAcGiImpMarbleTexture;

public:
	ACRX_DECLARE_MEMBERS(AcGiMarbleTexture);

	AcGiMarbleTexture();
	AcGiMarbleTexture(const AcGiMarbleTexture& texture);
	~AcGiMarbleTexture();
	AcGiMarbleTexture& operator=(const AcGiMarbleTexture& texture);
	bool operator==(const AcGiMaterialTexture& texture) const override;

	Acad::ErrorStatus copyFrom(const AcRxObject* other) override;
	virtual void setStoneColor(const AcGiMaterialColor& stoneColor);
	virtual void setVeinColor(const AcGiMaterialColor& veinColor);
	virtual void setVeinSpacing(double veinSpacing);
	virtual void setVeinWidth(double veinWidth);
	virtual const AcGiMaterialColor& stoneColor() const;
	virtual const AcGiMaterialColor& veinColor() const;
	virtual double veinSpacing() const;
	virtual double veinWidth() const;
};

#include "IcArxPackPop.h"

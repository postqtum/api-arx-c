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
***     Description: Declaration of AcGiWoodTexture classes
***
*****************************************************************************/
#pragma once

#include "AcGiMaterialTexture.h"

class AcGiImpWoodTexture;

#include "IcArxPackPush.h"

class AcGiWoodTexture : public AcGiProceduralTexture
{
private:
	AcGiImpWoodTexture* mpAcGiImpWoodTexture;

public:
	ACRX_DECLARE_MEMBERS(AcGiWoodTexture);

	AcGiWoodTexture();
	AcGiWoodTexture(const AcGiWoodTexture& texture);
	~AcGiWoodTexture();
	AcGiWoodTexture& operator=(const AcGiWoodTexture& texture);
	bool operator==(const AcGiMaterialTexture& texture) const override;

	virtual double axialNoise() const;
	virtual const AcGiMaterialColor& color1() const;
	virtual const AcGiMaterialColor& color2() const;
	Acad::ErrorStatus copyFrom(const AcRxObject* other) override;
	virtual double grainThickness() const;
	virtual double radialNoise() const;
	virtual void setAxialNoise(double axialNoise);
	virtual void setGrainThickness(double grainThickness);
	virtual void setRadialNoise(double radialNoise);
	virtual void setColor1(const AcGiMaterialColor& woodColor1);
	virtual void setColor2(const AcGiMaterialColor& woodColor2);
};

#include "IcArxPackPop.h"

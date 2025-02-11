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
***     Description: Declaration of AcDbGradientBackground class
***
*****************************************************************************/
#pragma once

#include "AcDbBackground.h"

class AcCmEntityColor;

#include "IcArxPackPush.h"
#pragma warning(disable : 4275 4251)

class SCENEDLLIMPEXP AcDbGradientBackground : public AcDbBackground
{
	friend class AcDbImpGradientBackground;

protected:
	uint32_t subSetAttributes(AcGiDrawableTraits* pTraits) override;

public:
	ACRX_DECLARE_MEMBERS(AcDbGradientBackground);

	AcDbGradientBackground();
	~AcDbGradientBackground();

	AcCmEntityColor colorBottom() const;
	AcCmEntityColor colorMiddle() const;
	AcCmEntityColor colorTop() const;
	Acad::ErrorStatus copyFrom(const AcRxObject* other) override;
	AcGiDrawable::DrawableType drawableType() const override;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	double height() const;
	double horizon() const;
	double rotation() const;
	void setColorBottom(const AcCmEntityColor& color);
	void setColorMiddle(const AcCmEntityColor& color);
	void setColorTop(const AcCmEntityColor& color);
	void setHeight(double height);
	void setHorizon(double horizon);
	void setRotation(double rotation);
};

#include "IcArxPackPop.h"

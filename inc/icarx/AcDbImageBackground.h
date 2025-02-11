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
***     Description: Declaration of AcDbImageBackground class
***
*****************************************************************************/
#pragma once

#include "AcDbBackground.h"

#include "IcArxPackPush.h"
#pragma warning(disable : 4275 4251)

class SCENEDLLIMPEXP AcDbImageBackground : public AcDbBackground
{
	friend class AcDbImpImageBackground;

protected:
	uint32_t subSetAttributes(AcGiDrawableTraits* pTraits) override;

public:
	ACRX_DECLARE_MEMBERS(AcDbImageBackground);

	AcDbImageBackground();
	~AcDbImageBackground();

	Acad::ErrorStatus copyFrom(const AcRxObject* other) override;
	AcGiDrawable::DrawableType drawableType() const override;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	bool fitToScreen() const;
	const ACHAR* imageFilename() const;
	bool maintainAspectRatio() const;
	void setFitToScreen(bool bFitToScreen);
	void setImageFilename(const ACHAR* filename);
	void setMaintainAspectRatio(bool bMaintainAspectRatio);
	void setUseTiling(bool bUseTiling);
	void setXOffset(double xOffset);
	void setXScale(double xScale);
	void setYOffset(double yOffset);
	void setYScale(double yScale);
	bool useTiling() const;
	double xOffset() const;
	double xScale() const;
	double yOffset() const;
	double yScale() const;
};

#include "IcArxPackPop.h"

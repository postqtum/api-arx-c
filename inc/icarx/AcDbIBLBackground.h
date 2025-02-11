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
***     Description: Declaration of AcDbIBLBackground class
***
*****************************************************************************/
#pragma once

#include "AcDbBackground.h"

class AcString;

#include "IcArxPackPush.h"
#pragma warning(disable : 4275 4251)

class SCENEDLLIMPEXP AcDbIBLBackground : public AcDbBackground
{
protected:
	uint32_t subSetAttributes(AcGiDrawableTraits* pTraits) override;

public:
	ACRX_DECLARE_MEMBERS(AcDbIBLBackground);

	AcDbIBLBackground();
	~AcDbIBLBackground();
	virtual bool operator==(const AcDbIBLBackground& environment);

	virtual AcString IBLImageName() const;
	virtual bool displayImage() const;
	AcGiDrawable* drawable() override;
	AcGiDrawable::DrawableType drawableType() const override;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	virtual bool enable() const;
	virtual double rotation() const;
	virtual AcDbObjectId secondaryBackground() const;
	virtual Acad::ErrorStatus setDisplayImage(const bool bdisplay);
	virtual Acad::ErrorStatus setEnable(const bool bEnable);
	virtual Acad::ErrorStatus setIBLImageName(const AcString& name);
	virtual Acad::ErrorStatus setRotation(const double rotation);
	virtual Acad::ErrorStatus setSecondaryBackground(const AcDbObjectId bg);
};

#include "IcArxPackPop.h"

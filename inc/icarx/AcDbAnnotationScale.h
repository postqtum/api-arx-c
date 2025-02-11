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
***     Description: Declaration of AcDbAnnotationScale class
***
*****************************************************************************/
#pragma once

#include "../dbObjContext.h"

class AcDbImpAnnotationScale;

#include "IcArxPackPush.h"

class AcDbAnnotationScale
		: public AcDbObjectContext
		, public AcHeapOperators
{
	friend class AcDbSystemInternals;

protected:
	AcDbImpAnnotationScale* mpImp;

protected:
	AcDbAnnotationScale(bool);

public:
	ACRX_DECLARE_MEMBERS(AcDbAnnotationScale);

	AcDbAnnotationScale();
	~AcDbAnnotationScale();

	AcString collectionName() const override;
	Acad::ErrorStatus copyFrom(const AcRxObject* pOther) override;
	virtual Acad::ErrorStatus getDrawingUnits(double& dDrawingUnits) const;
	virtual Acad::ErrorStatus getIsTemporaryScale(bool& bTemporary) const;
	Acad::ErrorStatus getName(AcString& name) const override;
	virtual Acad::ErrorStatus getPaperUnits(double& dPaperUnits) const;
	virtual Acad::ErrorStatus getScale(double& dScale) const;
	virtual bool matchScaleId(IcArx::Integers::LongPtr id) const;
	virtual Acad::ErrorStatus setDrawingUnits(const double dDrawingUnits);
	Acad::ErrorStatus setName(const AcString& name) override;
	virtual Acad::ErrorStatus setPaperUnits(double dPaperUnits);
	IcArx::Integers::LongPtr uniqueIdentifier() const override;
};

#include "IcArxPackPop.h"

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
***     Description: Declaration of AcGiNonEntityTraits class
***
*****************************************************************************/
#pragma once

#include "AcGiDrawableTraits.h"
#include "IcArxAssert.h"

#include "IcArxPackPush.h"

class AcGiNonEntityTraits : public AcGiDrawableTraits
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcGiNonEntityTraits, ACDBCORE2D_PORT);

	void addLight(const AcDbObjectId& id) override { ICARX_ASSERT(false); }
	uint16_t color() const override
	{
		ICARX_ASSERT(false);
		return 0;
	}
	AcGiFillType fillType() const override
	{
		ICARX_ASSERT(false);
		return kAcGiFillAlways;
	}
	AcDbObjectId layerId() const override
	{
		ICARX_ASSERT(false);
		return AcDbObjectId::kNull;
	}
	AcDbObjectId lineTypeId() const override
	{
		ICARX_ASSERT(false);
		return AcDbObjectId::kNull;
	}
	double lineTypeScale() const override
	{
		ICARX_ASSERT(false);
		return 0.0;
	}
	AcDb::LineWeight lineWeight() const override
	{
		ICARX_ASSERT(false);
		return AcDb::kLnWt000;
	}
	AcDbObjectId materialId() const override
	{
		ICARX_ASSERT(false);
		return AcDbObjectId::kNull;
	}
	bool selectionGeom() const override
	{
		ICARX_ASSERT(false);
		return false;
	}
	void setColor(const uint16_t /*color*/) override { ICARX_ASSERT(false); }
	void setFillType(const AcGiFillType /*fillType*/) override { ICARX_ASSERT(false); }
	void setLayer(const AcDbObjectId /*layerId*/) override { ICARX_ASSERT(false); }
	void setLineType(const AcDbObjectId /*linetypeId*/) override { ICARX_ASSERT(false); }
	void setLineTypeScale(double dScale) override { ICARX_ASSERT(false); }
	void setLineWeight(const AcDb::LineWeight /*lw*/) override { ICARX_ASSERT(false); }
	void setMaterial(const AcDbObjectId /*matId*/) override { ICARX_ASSERT(false); }
	void setSelectionGeom(bool /*bSelectionflag*/) override { ICARX_ASSERT(false); }
	void setSelectionMarker(const IcArx::Integers::LongPtr /*markerId*/) override { ICARX_ASSERT(false); }
	void setThickness(double /*thickness*/) override { ICARX_ASSERT(false); }
	void setTransparency(const AcCmTransparency& /*transparency*/) override { ICARX_ASSERT(false); }
	void setTrueColor(const AcCmEntityColor& /*color*/) override { ICARX_ASSERT(false); }
	void setupForEntity(AcDbEntity* /*pEntity*/) override { ICARX_ASSERT(false); }
	double thickness() const override
	{
		ICARX_ASSERT(false);
		return 0.0;
	}
	AcCmTransparency transparency() const override
	{
		ICARX_ASSERT(false);
		return AcCmTransparency();
	}
	AcCmEntityColor trueColor() const override
	{
		ICARX_ASSERT(false);
		return AcCmEntityColor();
	}
};

#include "IcArxPackPop.h"

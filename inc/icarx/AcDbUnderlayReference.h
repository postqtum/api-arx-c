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
***     Description: Declaration of AcDbUnderlayReference class
***
*****************************************************************************/
#pragma once

#include "../dbmain.h"
#include "../gept2dar.h"

class AcUnderlayLayer;

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcDbUnderlayReference : public AcDbEntity
{
public:
	ACDB_DECLARE_MEMBERS(AcDbUnderlayReference);

	~AcDbUnderlayReference() = 0;

	const AcGePoint2dArray& clipBoundary() const;
	uint8_t contrast() const;
	static uint8_t contrastDefault();
	static uint8_t contrastLowerLimit();
	static uint8_t contrastUpperLimit();
	AcDbObjectId definitionId() const;
	uint8_t fade() const;
	static uint8_t fadeDefault();
	static uint8_t fadeLowerLimit();
	static uint8_t fadeUpperLimit();
	Acad::ErrorStatus generateClipBoundaryFromPline(AcDbObjectId polyId);
	Acad::ErrorStatus getUnderlayLayer(int index, AcUnderlayLayer& layer) const;
	ACDBCORE2D_PORT Acad::ErrorStatus height(double& width) const;
	bool isAdjustedForBackground() const;
	bool isClipInverted() const;
	bool isClipped() const;
	virtual bool isFramePlottable() const = 0;
	virtual bool isFrameVisible() const = 0;
	bool isMonochrome() const;
	bool isOn() const;
	AcGeVector3d normal() const;
	AcGePoint3d position() const;
	double rotation() const;
	AcGeScale3d scaleFactors() const;
	Acad::ErrorStatus setClipBoundary(const AcGePoint2dArray& clipBoundary);
	Acad::ErrorStatus setClipInverted(bool value);
	Acad::ErrorStatus setContrast(uint8_t value);
	Acad::ErrorStatus setDefinitionId(AcDbObjectId id);
	Acad::ErrorStatus setFade(uint8_t value);
	ACDBCORE2D_PORT Acad::ErrorStatus setHeight(double width);
	Acad::ErrorStatus setIsAdjustedForBackground(bool value);
	Acad::ErrorStatus setIsClipped(bool value);
	Acad::ErrorStatus setIsMonochrome(bool value);
	Acad::ErrorStatus setIsOn(bool value);
	Acad::ErrorStatus setNormal(const AcGeVector3d& normal);
	Acad::ErrorStatus setPosition(const AcGePoint3d& position);
	Acad::ErrorStatus setRotation(double rotation);
	Acad::ErrorStatus setScaleFactors(const AcGeScale3d& scale);
	Acad::ErrorStatus setTransform(const AcGeMatrix3d& transform);
	Acad::ErrorStatus setUnderlayLayer(int index, const AcUnderlayLayer& layer);
	ACDBCORE2D_PORT Acad::ErrorStatus setWidth(double width);
	AcGeMatrix3d transform() const;
	uint32_t underlayLayerCount() const;
	ACDBCORE2D_PORT Acad::ErrorStatus width(double& width) const;
};

#include "IcArxPackPop.h"

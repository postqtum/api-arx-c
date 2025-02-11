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
***     Description: Declaration of AcGiShadowParameters class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../rxboiler.h"

#include "IcArxPackPush.h"

class AcGiShadowParameters : public AcRxObject
{
public:
	enum ExtendedLightShape
	{
		kLinear = 0,
		kRectangle,
		kDisk,
		kCylinder,
		kSphere
	};

	enum ShadowType
	{
		kShadowsRayTraced = 0,
		kShadowMaps,
		kAreaSampled
	};

protected:
	bool mShadowsOn;
	ShadowType mShadowType;
	uint16_t mShadowMapSize;
	uint8_t mShadowMapSoftness;
	uint16_t mShadowSamples;
	bool mbShapeVisibility;
	ExtendedLightShape mExtLightShape;
	double mExtLightLength;
	double mExtLightWidth;
	double mExtLightRadius;

public:
	ACRX_DECLARE_MEMBERS(AcGiShadowParameters);

	AcGiShadowParameters();
	AcGiShadowParameters(const AcGiShadowParameters& other);
	~AcGiShadowParameters();

	AcGiShadowParameters& operator=(const AcGiShadowParameters& other);
	bool operator==(const AcGiShadowParameters& params) const;

	virtual bool setExtendedLightLength(double length);
	virtual bool setExtendedLightRadius(double radius);
	virtual bool setExtendedLightShape(ExtendedLightShape shape);
	virtual bool setExtendedLightWidth(double width);
	virtual bool setShadowMapSize(uint16_t sz);
	virtual bool setShadowMapSoftness(uint8_t soft);
	virtual bool setShadowSamples(uint16_t samples);
	virtual void setShadowType(ShadowType typ);
	virtual void setShadowsOn(bool on);
	virtual void setShapeVisibility(bool visible);
	virtual double extendedLightLength() const;
	virtual double extendedLightRadius() const;
	virtual ExtendedLightShape extendedLightShape() const;
	virtual double extendedLightWidth() const;
	virtual uint16_t shadowMapSize() const;
	virtual uint8_t shadowMapSoftness() const;
	virtual uint16_t shadowSamples() const;
	virtual ShadowType shadowType() const;
	virtual bool shadowsOn() const;
	virtual bool shapeVisibility() const;
};

#include "IcArxPackPop.h"

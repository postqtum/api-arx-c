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
***     Description: Declaration of AcGiViewport class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../rxboiler.h"
#include "../gevec3d.h"

class AcGeMatrix3d;
class AcGePoint2d;
class AcGePoint3d;
class AcDbObjectId;
class AcGiContextualColors;

#include "IcArxPackPush.h"

class AcGiViewport : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcGiViewport);

	virtual int16_t acadWindowId() const = 0;
	virtual const AcGiContextualColors* contextualColors() const { return nullptr; }
	virtual bool doInversePerspective(AcGePoint3d&) const = 0;
	virtual bool doPerspective(AcGePoint3d&) const = 0;
	virtual void getCameraLocation(AcGePoint3d& location) const = 0;
	virtual void getCameraTarget(AcGePoint3d& target) const = 0;
	virtual void getCameraUpVector(AcGeVector3d& upVector) const = 0;
	virtual void getEyeToModelTransform(AcGeMatrix3d&) const = 0;
	virtual void getEyeToWorldTransform(AcGeMatrix3d&) const = 0;
	virtual bool getFrontAndBackClipValues(bool& clip_front, bool& clip_back, double& front,
										   double& back) const = 0;
	virtual void getModelToEyeTransform(AcGeMatrix3d&) const = 0;
	virtual void getNumPixelsInUnitSquare(const AcGePoint3d& givenWorldpt, AcGePoint2d& pixelArea,
										  bool includePerspective = true) const = 0;
	virtual void getViewportDcCorners(AcGePoint2d& lower_left, AcGePoint2d& upper_right) const = 0;
	virtual void getWorldToEyeTransform(AcGeMatrix3d&) const = 0;
	virtual bool isPerspective() const = 0;
	virtual bool layerVisible(const AcDbObjectId& /*idLayer*/) const
	{
		return true;
	}
	virtual double linetypeGenerationCriteria() const = 0;
	virtual double linetypeScaleMultiplier() const = 0;
	virtual AcGeVector3d viewDir() const { return AcGeVector3d::kZAxis; }
	virtual IcArx::Integers::ULongPtr viewportId() const = 0;
};

#include "IcArxPackPop.h"

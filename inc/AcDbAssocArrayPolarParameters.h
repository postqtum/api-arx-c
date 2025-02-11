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
***     Description: Declaration of AcDbAssocArrayPolarParameters class
***
*****************************************************************************/
#pragma once

#include "AcDbAssocArrayCommonParameters.h"

class AcDbImpAssocArrayPolarParameters;

#include "icarx/IcArxPackPush.h"

class AcDbAssocArrayPolarParameters : public AcDbAssocArrayCommonParameters
{
	friend class AcDbImpAssocArrayPolarParameters;

public:
	enum Direction
	{
		kClockwise,
		kCounterClockwise
	};

	enum GripModes
	{
		kCenterPointGrip = 1 << 0,
		kStretchRadiusGrip = 1 << 1,
		kRowCountGrip = 1 << 2,
		kRowSpacingGrip = 1 << 3,
		kUniformRowSpacingGrip = 1 << 4,
		kLevelCountGrip = 1 << 5,
		kLevelSpacingGrip = 1 << 6,
		kUniformLevelSpacingGrip = 1 << 7,
		kItemCountGrip = 1 << 8,
		kAngleBetweenItemsGrip = 1 << 9,
		kFillAngleGrip = 1 << 10,
	};

protected:
	ACDBCORE2D_PORT explicit AcDbAssocArrayPolarParameters(AcDbImpAssocArrayPolarParameters* pSelf);

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbAssocArrayPolarParameters, ACDBCORE2D_PORT);

public:
	ACDBCORE2D_PORT AcDbAssocArrayPolarParameters(double angle = 15, double rowSpacing = 1,
												  double levelSpacing = 1, int itemCount = 1,
												  int rowCount = 1, int levelCount = 1,
												  double rowElevation = 1);
	ACDBCORE2D_PORT ~AcDbAssocArrayPolarParameters();

	ACDBCORE2D_PORT double angleBetweenItems(AcString& expression, AcString& evaluatorId) const;
	ACDBCORE2D_PORT inline double angleBetweenItems() const
	{
		AcString expression, evaluatorId;
		return this->angleBetweenItems(expression, evaluatorId);
	}
	ACDBCORE2D_PORT inline double angleBetweenItems(AcString& expression) const
	{
		AcString evaluatorId;
		return this->angleBetweenItems(expression, evaluatorId);
	}
	ACDBCORE2D_PORT AcDbAssocArrayPolarParameters::Direction direction() const;
	ACDBCORE2D_PORT double fillAngle(AcString& expression, AcString& evaluatorId) const;
	ACDBCORE2D_PORT inline double fillAngle() const
	{
		AcString expression, evaluatorId;
		return this->fillAngle(expression, evaluatorId);
	}
	ACDBCORE2D_PORT inline double fillAngle(AcString& expression) const
	{
		AcString evaluatorId;
		return this->fillAngle(expression, evaluatorId);
	}
	ACDBCORE2D_PORT Acad::ErrorStatus getItemPosition(const AcDbItemLocator& locator,
													  AcGePoint3d& position,
													  AcGeMatrix3d& xform) const override;
	ACDBCORE2D_PORT Acad::ErrorStatus getItems(AcArray<AcDbAssocArrayItem*>& items) const override;
	ACDBCORE2D_PORT int itemCount(AcString& expression, AcString& evaluatorId) const;
	ACDBCORE2D_PORT inline int itemCount() const
	{
		AcString expression, evaluatorId;
		return this->itemCount(expression, evaluatorId);
	}
	ACDBCORE2D_PORT inline int itemCount(AcString& expression) const
	{
		AcString evaluatorId;
		return this->itemCount(expression, evaluatorId);
	}
	ACDBCORE2D_PORT double radius(AcString& expression, AcString& evaluatorId) const;
	ACDBCORE2D_PORT inline double radius() const
	{
		AcString expression, evaluatorId;
		return this->radius(expression, evaluatorId);
	}
	ACDBCORE2D_PORT inline double radius(AcString& expression) const
	{
		AcString evaluatorId;
		return this->radius(expression, evaluatorId);
	}
	ACDBCORE2D_PORT bool rotateItems() const;
	ACDBCORE2D_PORT Acad::ErrorStatus setAngleBetweenItems(double angle,
														   const AcString& expression = AcString(),
														   const AcString& evaluatorId = AcString(),
														   AcString& errorMessage = dummyString());
	ACDBCORE2D_PORT Acad::ErrorStatus setDirection(
			AcDbAssocArrayPolarParameters::Direction direction);
	ACDBCORE2D_PORT Acad::ErrorStatus setFillAngle(double fillAngle,
												   const AcString& expression = AcString(),
												   const AcString& evaluatorId = AcString(),
												   AcString& errorMessage = dummyString());
	ACDBCORE2D_PORT Acad::ErrorStatus setItemCount(int nItems,
												   const AcString& expression = AcString(),
												   const AcString& evaluatorId = AcString(),
												   AcString& errorMessage = dummyString());
	ACDBCORE2D_PORT Acad::ErrorStatus setRadius(double radius,
												const AcString& expression = AcString(),
												const AcString& evaluatorId = AcString(),
												AcString& errorMessage = dummyString());
	ACDBCORE2D_PORT Acad::ErrorStatus setRotateItems(bool bRotateItems);
	ACDBCORE2D_PORT Acad::ErrorStatus setStartAngle(double angle,
													const AcString& expression = AcString(),
													const AcString& evaluatorId = AcString(),
													AcString& errorMessage = dummyString());
	ACDBCORE2D_PORT double startAngle(AcString& expression, AcString& evaluatorId) const;
};

#include "icarx/IcArxPackPop.h"

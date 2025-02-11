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
***     Description: Declaration of AcDbAssocArrayRectangularParameters class
***
*****************************************************************************/
#pragma once

#include "AcDbAssocArrayCommonParameters.h"

class AcDbImpAssocArrayRectangularParameters;

#include "icarx/IcArxPackPush.h"

class AcDbAssocArrayRectangularParameters : public AcDbAssocArrayCommonParameters
{
	friend class AcDbImpAssocArrayRectangularParameters;

public:
	enum GripModes
	{
		kStretchGrip = 1 << 0,
		kRowCountGrip = 1 << 1,
		kRowSpacingGrip = 1 << 2,
		kUniformRowSpacingGrip = 1 << 3,
		kColumnCountGrip = 1 << 4,
		kColumnSpacingGrip = 1 << 5,
		kUniformColSpacingGrip = 1 << 6,
		kRowColumnCountGrip = 1 << 7,
		kRowColumnSpacingGrip = 1 << 8,
		kColumnDirectionGrip = 1 << 9,
		kRowDirectionGrip = 1 << 10,
		kLevelCountGrip = 1 << 11,
		kLevelSpacingGrip = 1 << 12,
		kUniformLevelSpacingGrip = 1 << 13,
		kRowAxisAngleGrip = 1 << 14
	};

protected:
	ACDBCORE2D_PORT explicit AcDbAssocArrayRectangularParameters(
			AcDbImpAssocArrayRectangularParameters* pSelf);

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbAssocArrayRectangularParameters, ACDBCORE2D_PORT);

public:
	ACDBCORE2D_PORT AcDbAssocArrayRectangularParameters(double columnSpacing = 1,
														double rowSpacing = 1,
														double levelSpacing = 1,
														int columnCount = 1, int rowCount = 1,
														int levelCount = 1, double rowElevation = 1,
														double axesAngle = 90);
	ACDBCORE2D_PORT ~AcDbAssocArrayRectangularParameters();

	ACDBCORE2D_PORT double axesAngle(AcString& expression, AcString& evaluatorId) const;
	ACDBCORE2D_PORT inline double axesAngle() const
	{
		AcString expression, evaluatorId;
		return this->axesAngle(expression, evaluatorId);
	}
	ACDBCORE2D_PORT inline double axesAngle(AcString& expression) const
	{
		AcString evaluatorId;
		return this->axesAngle(expression, evaluatorId);
	}
	ACDBCORE2D_PORT AcGeVector3d axisDirection(AcGeVector3d* pYAxis = nullptr) const;
	ACDBCORE2D_PORT int columnCount(AcString& expression, AcString& evaluatorId) const;
	ACDBCORE2D_PORT inline int columnCount() const
	{
		AcString expression, evaluatorId;
		return this->columnCount(expression, evaluatorId);
	}
	ACDBCORE2D_PORT inline int columnCount(AcString& expression) const
	{
		AcString evaluatorId;
		return this->columnCount(expression, evaluatorId);
	}
	ACDBCORE2D_PORT double columnSpacing(AcString& expression, AcString& evaluatorId) const;
	ACDBCORE2D_PORT inline double columnSpacing() const
	{
		AcString expression, evaluatorId;
		return this->columnSpacing(expression, evaluatorId);
	}
	ACDBCORE2D_PORT inline double columnSpacing(AcString& expression) const
	{
		AcString evaluatorId;
		return this->columnSpacing(expression, evaluatorId);
	}
	ACDBCORE2D_PORT Acad::ErrorStatus getItemPosition(const AcDbItemLocator& locator,
													  AcGePoint3d& position,
													  AcGeMatrix3d& xform) const override;
	ACDBCORE2D_PORT Acad::ErrorStatus getItems(AcArray<AcDbAssocArrayItem*>& items) const override;
	ACDBCORE2D_PORT Acad::ErrorStatus setAxesAngle(double axesAngle,
												   const AcString& expression = AcString(),
												   const AcString& evaluatorId = AcString(),
												   AcString& errorMessage = dummyString());
	ACDBCORE2D_PORT Acad::ErrorStatus setAxisDirection(const AcGeVector3d& xAxis);
	ACDBCORE2D_PORT Acad::ErrorStatus setColumnCount(int nColumns,
													 const AcString& expression = AcString(),
													 const AcString& evaluatorId = AcString(),
													 AcString& errorMessage = dummyString());
	ACDBCORE2D_PORT Acad::ErrorStatus setColumnSpacing(double offset,
													   const AcString& expression = AcString(),
													   const AcString& evaluatorId = AcString(),
													   AcString& errorMessage = dummyString());
};

#include "icarx/IcArxPackPop.h"

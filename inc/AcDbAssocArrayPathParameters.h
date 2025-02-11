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
***     Description: Declaration of AcDbAssocArrayPathParameters class
***
*****************************************************************************/
#pragma once

#include "AcDbAssocArrayCommonParameters.h"

class AcDbImpAssocArrayPathParameters;
class AcDbEdgeRef;

#include "icarx/IcArxPackPush.h"

class AcDbAssocArrayPathParameters : public AcDbAssocArrayCommonParameters
{
	friend class AcDbImpAssocArrayPathParameters;

public:
	enum GripModes
	{
		kStretchGrip = 1 << 0,
		kRowCountGrip = 1 << 1,
		kRowSpacingGrip = 1 << 2,
		kUniformRowSpacingGrip = 1 << 3,
		kLevelCountGrip = 1 << 4,
		kLevelSpacingGrip = 1 << 5,
		kUniformLevelSpacingGrip = 1 << 6,
		kItemCountGrip = 1 << 7,
		kItemSpacingGrip = 1 << 8,
		kUniformItemSpacingGrip = 1 << 9
	};

	enum Method
	{
		kDivide,
		kMeasure
	};

protected:
	ACDBCORE2D_PORT explicit AcDbAssocArrayPathParameters(AcDbImpAssocArrayPathParameters* pSelf);

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbAssocArrayPathParameters, ACDBCORE2D_PORT);

public:
	ACDBCORE2D_PORT AcDbAssocArrayPathParameters(double itemSpacing = 1, double rowSpacing = 1,
												 double levelSpacing = 1, int itemCount = 1,
												 int rowCount = 1, int levelCount = 1,
												 double rowElevation = 1);
	ACDBCORE2D_PORT ~AcDbAssocArrayPathParameters();

	ACDBCORE2D_PORT bool alignItems() const;
	ACDBCORE2D_PORT inline double endOffset() const
	{
		AcString expression, evaluatorId;
		return this->endOffset(expression, evaluatorId);
	}
	ACDBCORE2D_PORT double endOffset(AcString& expression, AcString& evaluatorId) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getItemPosition(const AcDbItemLocator& locator,
													  AcGePoint3d& position,
													  AcGeMatrix3d& xform) const;
	ACDBCORE2D_PORT inline Acad::ErrorStatus getItemPosition(const AcDbItemLocator& locator,
															 AcGePoint3d& position) const
	{
		AcGeMatrix3d xform;
		return this->getItemPosition(locator, position, xform);
	}
	ACDBCORE2D_PORT Acad::ErrorStatus getItems(AcArray<AcDbAssocArrayItem*>& items) const;
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
	ACDBCORE2D_PORT double itemSpacing(AcString& expression, AcString& evaluatorId) const;
	ACDBCORE2D_PORT inline double itemSpacing() const
	{
		AcString expression, evaluatorId;
		return this->itemSpacing(expression, evaluatorId);
	}
	ACDBCORE2D_PORT inline double itemSpacing(AcString& expression) const
	{
		AcString evaluatorId;
		return this->itemSpacing(expression, evaluatorId);
	}
	ACDBCORE2D_PORT AcDbAssocArrayPathParameters::Method method() const;
	ACDBCORE2D_PORT AcDbEdgeRef path() const;
	ACDBCORE2D_PORT Acad::ErrorStatus setAlignItems(bool bAlignItems);
	ACDBCORE2D_PORT Acad::ErrorStatus setEndOffset(double endOffset,
												   const AcString& expression = AcString(),
												   const AcString& evaluatorId = AcString(),
												   AcString& errorMessage = dummyString());
	ACDBCORE2D_PORT Acad::ErrorStatus setItemCount(int nItems,
												   const AcString& expression = AcString(),
												   const AcString& evaluatorId = AcString(),
												   AcString& errorMessage = dummyString());
	ACDBCORE2D_PORT Acad::ErrorStatus setItemSpacing(double offset,
													 const AcString& expression = AcString(),
													 const AcString& evaluatorId = AcString(),
													 AcString& errorMessage = dummyString());
	ACDBCORE2D_PORT Acad::ErrorStatus setMethod(AcDbAssocArrayPathParameters::Method method);
	ACDBCORE2D_PORT Acad::ErrorStatus setPath(const AcDbEdgeRef& edgeRef);
	ACDBCORE2D_PORT Acad::ErrorStatus setPathDirection(bool bAlongParams);
	ACDBCORE2D_PORT Acad::ErrorStatus setStartOffset(double startOffset,
													 const AcString& expression = AcString(),
													 const AcString& evaluatorId = AcString(),
													 AcString& errorMessage = dummyString());
	ACDBCORE2D_PORT inline double startOffset() const
	{
		AcString expression, evaluatorId;
		return this->startOffset(expression, evaluatorId);
	}
	ACDBCORE2D_PORT double startOffset(AcString& expression, AcString& evaluatorId) const;
};

#include "icarx/IcArxPackPop.h"

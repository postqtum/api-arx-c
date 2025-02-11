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
***     Description: Declaration of AcDbAssocArrayCommonParameters class
***
*****************************************************************************/
#pragma once

#include "AcDbAssocArrayParameters.h"
#include "acdbassocactionbody.h"

class AcDbImpAssocArrayCommonParameters;
class AcDbVertexRef;
class AcDbFaceRef;

#include "icarx/IcArxPackPush.h"

class AcDbAssocArrayCommonParameters : public AcDbAssocArrayParameters
{
protected:
	ACDBCORE2D_PORT explicit AcDbAssocArrayCommonParameters(AcDbImpAssocArrayCommonParameters* pSelf);

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbAssocArrayCommonParameters, ACDBCORE2D_PORT);

public:
	ACDBCORE2D_PORT ~AcDbAssocArrayCommonParameters();

	ACDBCORE2D_PORT Acad::ErrorStatus getBasePlane(AcDbVertexRef& basePoint, AcGeVector3d& normal,
								   AcDbFaceRef* pFace = nullptr) const;
	ACDBCORE2D_PORT AcDbItemLocator getCanonicalForm(const AcDbItemLocator& locator) const override;
	ACDBCORE2D_PORT int levelCount(AcString& expression, AcString& evaluatorId) const;
	ACDBCORE2D_PORT inline int levelCount() const
	{
		AcString expression, evaluatorId;
		return this->levelCount(expression, evaluatorId);
	}
	ACDBCORE2D_PORT inline int levelCount(AcString& expression) const
	{
		AcString evaluatorId;
		return this->levelCount(expression, evaluatorId);
	}
	ACDBCORE2D_PORT double levelSpacing(AcString& expression, AcString& evaluatorId) const;
	ACDBCORE2D_PORT inline double levelSpacing() const
	{
		AcString expression, evaluatorId;
		return this->levelSpacing(expression, evaluatorId);
	}
	ACDBCORE2D_PORT inline double levelSpacing(AcString& expression) const
	{
		AcString evaluatorId;
		return this->levelSpacing(expression, evaluatorId);
	}
	ACDBCORE2D_PORT int rowCount(AcString& expression, AcString& evaluatorId) const;
	ACDBCORE2D_PORT inline int rowCount() const
	{
		AcString expression, evaluatorId;
		return this->rowCount(expression, evaluatorId);
	}
	ACDBCORE2D_PORT inline int rowCount(AcString& expression) const
	{
		AcString evaluatorId;
		return this->rowCount(expression, evaluatorId);
	}
	ACDBCORE2D_PORT double rowElevation(AcString& expression, AcString& evaluatorId) const;
	ACDBCORE2D_PORT inline double rowElevation() const
	{
		AcString expression, evaluatorId;
		return this->rowElevation(expression, evaluatorId);
	}
	ACDBCORE2D_PORT inline double rowElevation(AcString& expression) const
	{
		AcString evaluatorId;
		return this->rowElevation(expression, evaluatorId);
	}
	ACDBCORE2D_PORT double rowSpacing(AcString& expression, AcString& evaluatorId) const;
	ACDBCORE2D_PORT inline double rowSpacing() const
	{
		AcString expression, evaluatorId;
		return this->rowSpacing(expression, evaluatorId);
	}
	ACDBCORE2D_PORT inline double rowSpacing(AcString& expression) const
	{
		AcString evaluatorId;
		return this->rowSpacing(expression, evaluatorId);
	}
	ACDBCORE2D_PORT Acad::ErrorStatus setBasePlane(const AcDbVertexRef& basePoint, const AcGeVector3d& normal,
								   const AcDbFaceRef* pFace = nullptr);
	ACDBCORE2D_PORT Acad::ErrorStatus setLevelCount(int nLevels, const AcString& expression = AcString(),
									const AcString& evaluatorId = AcString(),
									AcString& errorMessage = dummyString());
	ACDBCORE2D_PORT Acad::ErrorStatus setLevelSpacing(double offset, const AcString& expression = AcString(),
									  const AcString& evaluatorId = AcString(),
									  AcString& errorMessage = dummyString());
	ACDBCORE2D_PORT Acad::ErrorStatus setRowCount(int nRows, const AcString& expression = AcString(),
								  const AcString& evaluatorId = AcString(),
								  AcString& errorMessage = dummyString());
	ACDBCORE2D_PORT Acad::ErrorStatus setRowElevation(double elevation, const AcString& expression = AcString(),
									  const AcString& evaluatorId = AcString(),
									  AcString& errorMessage = dummyString());
	ACDBCORE2D_PORT Acad::ErrorStatus setRowSpacing(double offset, const AcString& expression = AcString(),
									const AcString& evaluatorId = AcString(),
									AcString& errorMessage = dummyString());
};

#include "icarx/IcArxPackPop.h"

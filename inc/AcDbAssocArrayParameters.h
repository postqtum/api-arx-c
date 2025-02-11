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
***     Description: Declaration of AcDbAssocArrayParameters class
***
*****************************************************************************/
#pragma once

#include "acarray.h"
#include "AcValue.h"
#include "AcDbAssocArrayItem.h"

#include "gept3dar.h"
#include "gevec3d.h"

class AcDbArrayGripAppData;
class AcDbAssocArrayActionBody;
class AcDbEvalVariant;
class AcDbImpAssocArrayParameters;
class AcDbGeomRef;

class AcString;

#include "icarx/IcArxPackPush.h"

class AcDbAssocArrayParameters : public AcRxObject
{
	friend class AcDbImpAssocArrayParameters;

protected:
	AcDbImpAssocArrayParameters* mpSelf;

protected:
	ACDBCORE2D_PORT explicit AcDbAssocArrayParameters(AcDbImpAssocArrayParameters* pSelf = nullptr);

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbAssocArrayParameters, ACDBCORE2D_PORT);

public:
	ACDBCORE2D_PORT ~AcDbAssocArrayParameters();

	ACDBCORE2D_PORT Acad::ErrorStatus copyFrom(const AcRxObject* other) override;
	ACDBCORE2D_PORT virtual AcDbItemLocator getCanonicalForm(const AcDbItemLocator& locator) const = 0;
	ACDBCORE2D_PORT Acad::ErrorStatus getGeomParam(const AcString& paramName, AcDbGeomRef*& pGeomRef,
								   AcDbObjectId& paramId) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getGripPointAt(unsigned int mode, AcDbArrayGripAppData*& pGrip) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getGripPoints(AcArray<AcDbArrayGripAppData*>& grips) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getItemPosition(const AcDbItemLocator& locator, AcGePoint3d& position,
											  AcGeMatrix3d& xform) const = 0;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getItems(AcArray<AcDbAssocArrayItem*>& items) const = 0;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getStretchPoints(AcGePoint3dArray& stretchPoints);
	ACDBCORE2D_PORT Acad::ErrorStatus getValueParam(const AcString& paramName, AcDbEvalVariant& value,
									AcString& expression, AcString& evaluatorId,
									AcValue::UnitType& unitType) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus moveGripPointAt(const AcDbArrayGripAppData* pGrip,
											  const AcGeVector3d& offset, int& modificationBit);
	ACDBCORE2D_PORT void ownedGeomParamNames(AcArray<AcString>& paramNames) const;
	ACDBCORE2D_PORT void ownedValueParamNames(AcArray<AcString>& paramNames) const;
	ACDBCORE2D_PORT const AcDbAssocArrayActionBody* owner() const;
	ACDBCORE2D_PORT AcDbAssocArrayActionBody* owner();
	ACDBCORE2D_PORT Acad::ErrorStatus setGeomParam(const AcString& paramName, const AcDbGeomRef* pGeomRef,
								   AcDbObjectId& paramId);
	ACDBCORE2D_PORT Acad::ErrorStatus setOwner(class AcDbAssocArrayActionBody* pOwner);
	ACDBCORE2D_PORT Acad::ErrorStatus setValueParam(const AcString& paramName, const AcDbEvalVariant& value,
									const AcString& expression, const AcString& evaluatorId,
									AcString& errorMessage, AcValue::UnitType* pUnitType = nullptr);
};

#include "icarx/IcArxPackPop.h"

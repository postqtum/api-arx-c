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
***     Description: Declaration of AcDbDynBlockReferenceProperty class
***
*****************************************************************************/
#pragma once

#include "../dbeval.h"

class AcDbImpDynBlockReferenceProperty;

#include "IcArxPackPush.h"

class AcDbDynBlockReferenceProperty : public AcHeapOperators
{
	friend class AcDbImpDynBlockReferenceProperty;
	friend class AcDbImpDynBlockReference;

public:
	enum UnitsType
	{
		kNoUnits = 0,
		kAngular,
		kDistance,
		kArea
	};

private:
	AcDbImpDynBlockReferenceProperty* mpImp;

public:
	AcDbDynBlockReferenceProperty();
	AcDbDynBlockReferenceProperty(const AcDbDynBlockReferenceProperty& other);
	virtual ~AcDbDynBlockReferenceProperty();
	AcDbDynBlockReferenceProperty& operator=(const AcDbDynBlockReferenceProperty& other);
	bool operator==(const AcDbDynBlockReferenceProperty& other);

	AcDbObjectId blockId() const;
	AcString description() const;
	Acad::ErrorStatus getAllowedValues(AcDbEvalVariantArray& values);
	AcString propertyName() const;
	AcDb::DwgDataType propertyType() const;
	bool readOnly() const;
	Acad::ErrorStatus setValue(const AcDbEvalVariant& value);
	bool show() const;
	UnitsType unitsType() const;
	AcDbEvalVariant value() const;
	bool ACDBCORE2D_PORT visibleInCurrentVisibilityState() const;
};

#include "IcArxPackPop.h"

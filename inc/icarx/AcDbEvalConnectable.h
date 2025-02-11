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
***     Description: Declaration of AcDbEvalConnectable class
***
*****************************************************************************/
#pragma once

#include "AcDbEvalExpr.h"
#include "AcDbEnumCode.h"
#include "AcDbEvalVariant.h"

class AcDbEvalConnectable;
class AcDbEvalVariant;

using AcDbEvalNodeId = uint32_t;
using AcDbEvalNodeIdArray = AcArray<AcDbEvalNodeId>;

#include "IcArxPackPush.h"

class AcDbEvalConnectable : public AcDbEvalExpr
{
protected:
	AcDbEvalConnectable();

public:
	ACDB_DECLARE_MEMBERS(AcDbEvalConnectable);

	~AcDbEvalConnectable();

	virtual Acad::ErrorStatus connectTo(const AcString& thisConnection,
										const AcDbEvalNodeId sourceConnectableId,
										const AcString& sourceConnectionName);
	virtual bool connectionAllowed(const AcString& thisConnection,
								   const AcDbEvalNodeId sourceConnectableId,
								   const AcString& sourceConnectionName) const;
	virtual Acad::ErrorStatus disconnectFrom(const AcString& thisConnection,
											 const AcDbEvalNodeId sourceConnectableId,
											 const AcString& sourceConnectionName);
	virtual Acad::ErrorStatus getConnectedNames(const AcString& thisConnection,
												const AcDbEvalNodeId sourceConnectableId,
												AcStringArray& sourceConnectionNames) const;
	virtual Acad::ErrorStatus getConnectedObjects(const AcString& thisConnection,
												  AcDbEvalNodeIdArray& connectedObjects) const;
	virtual Acad::ErrorStatus getConnectionNames(AcStringArray& names) const;
	virtual Acad::ErrorStatus getConnectionType(const AcString& name,
												AcDb::DwgDataType& type) const;
	virtual Acad::ErrorStatus getConnectionValue(const AcString& name,
												 AcDbEvalVariant& value) const;
	virtual bool hasConnectionNamed(const AcString& name) const;
	virtual Acad::ErrorStatus setConnectionValue(const AcString& name,
												 const AcDbEvalVariant& value);
};

#include "IcArxPackPop.h"

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
***     Description: Declaration of AcDbDynBlockReference class
***
*****************************************************************************/
#pragma once

#include "../dbeval.h"

class AcDbDynBlockReferenceProperty;
class AcDbImpDynBlockReference;

using AcDbDynBlockReferencePropertyArray =
		AcArray<AcDbDynBlockReferenceProperty,
				AcArrayObjectCopyReallocator<AcDbDynBlockReferenceProperty>>;

#include "IcArxPackPush.h"

class AcDbDynBlockReference : public AcHeapOperators
{
private:
	AcDbImpDynBlockReference* mpImp;

private:
	AcDbDynBlockReference();

	AcDbDynBlockReference(const AcDbDynBlockReference&) = delete;
	AcDbDynBlockReference& operator=(const AcDbDynBlockReference&) = delete;

public:
	AcDbDynBlockReference(AcDbObjectId blockRefId);
	AcDbDynBlockReference(AcDbBlockReference* pRef);
	virtual ~AcDbDynBlockReference();

	AcDbObjectId anonymousBlockTableRecord() const;
	AcDbObjectId blockId() const;
	Acad::ErrorStatus convertToStaticBlock();
	Acad::ErrorStatus convertToStaticBlock(const AcString& newBlockName);
	AcDbObjectId dynamicBlockTableRecord() const;
	void getBlockProperties(AcDbDynBlockReferencePropertyArray& properties) const;
	static bool isDynamicBlock(AcDbObjectId blockTableRecordId);
	bool isDynamicBlock() const;
	Acad::ErrorStatus resetBlock();
};

#include "IcArxPackPop.h"

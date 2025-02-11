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
***     Description: Declaration of AcDbBreakPointRef class
***
*****************************************************************************/
#pragma once

#include "AcDbObject.h"
#include "../gept3dar.h"

class AcDbBreakPointRef;
class AcDbFullSubentPath;

#include "IcArxPackPush.h"

class AcDbBreakPointRef : public AcDbObject
{
public:
	enum BreakPointType
	{
		kDynamic = 0,
		kStatic = 1,
		kStatic2Point = 2
	};

public:
	ACDB_DECLARE_MEMBERS(AcDbBreakPointRef);

	AcDbBreakPointRef();
	~AcDbBreakPointRef();

	AcGePoint3d breakPoint() const;
	AcGePoint3d breakPoint2() const;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler*) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler*) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const override;
	Acad::ErrorStatus getBreakPointId(AcDbFullSubentPath& idPath) const;
	Acad::ErrorStatus intersectWith(const AcDbEntity* pEnt, AcGePoint3dArray& points,
									AcGePoint3dArray& textBoxPts);
	int32_t lineIndex() const;
	AcDbBreakPointRef::BreakPointType pointType() const;
	Acad::ErrorStatus setBreakPoint(const AcGePoint3d& pt);
	Acad::ErrorStatus setBreakPoint2(const AcGePoint3d& pt);
	Acad::ErrorStatus setBreakPointId(const AcDbFullSubentPath& idPath);
	Acad::ErrorStatus setLineIndex(int32_t index);
	Acad::ErrorStatus setPointType(AcDbBreakPointRef::BreakPointType newVal);
	AcDbEntity* subentPtr() const;
};

#include "IcArxPackPop.h"

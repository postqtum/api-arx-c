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
***     Description: Declaration of AcEdSelectionSetService class
***
*****************************************************************************/
#pragma once

#include "../acadstrc.h"
#include "../acarray.h"
#include "../gept3dar.h"
#include "AcDbFullSubentPath.h"
#include "AcDbFullSubentPathArray.h"

struct resbuf;
class AcDbObjectId;

#include "IcArxPackPush.h"

class AcEdSelectionSetService
{
public:
	virtual ~AcEdSelectionSetService() = default;

	virtual Acad::ErrorStatus add(const AcArray<resbuf*>& ssnameXList,
								  const AcArray<AcDbFullSubentPath*>* pPath,
								  bool bAddsAreUnique) = 0;
	virtual Acad::ErrorStatus add(resbuf* ssnameXList, const AcDbFullSubentPath* pPath = nullptr,
								  const AcDbObjectId* pEntselSubent = nullptr) = 0;
	virtual Acad::ErrorStatus addSubentities(resbuf* ssnameXList,
											 const AcArray<AcDbFullSubentPath>& subEntities,
											 bool bAddsAreUnique) = 0;
	virtual Acad::ErrorStatus addSubentity(resbuf* ssnameXList,
										   const AcDbFullSubentPath& subEntity) = 0;
	virtual Acad::ErrorStatus getSubSelectionPoints(AcGePoint3dArray& points) = 0;
	virtual Acad::ErrorStatus highlight(int subSelectionIndex, const AcDbFullSubentPath& path) = 0;
	virtual Acad::ErrorStatus remove(int index) = 0;
	virtual Acad::ErrorStatus remove(const AcArray<int>& indices) = 0;
	virtual Acad::ErrorStatus removeSubentities(int entityIndex,
												const AcArray<int>& subEntityIndices) = 0;
	virtual Acad::ErrorStatus removeSubentity(int entityIndex, int subEntityIndex) = 0;
	virtual Acad::ErrorStatus ssNameSubentities(bool bIsSubSelectionIndex, int index,
												AcDbFullSubentPathArray& subEntities) = 0;
	virtual Acad::ErrorStatus ssNameSubentityX(bool bIsSubSelectionIndex, int index,
											   int subentityIndex, resbuf*& result) = 0;
	virtual Acad::ErrorStatus ssNameX(bool bIsSubSelectionIndex, int index, resbuf*& result) = 0;
	virtual int subSelectionMode() = 0;
	virtual int subSelectionSubMode() = 0;
};

#include "IcArxPackPop.h"

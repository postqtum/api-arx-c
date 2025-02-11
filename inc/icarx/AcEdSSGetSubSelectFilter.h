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
***     Description: Declaration of AcEdSSGetSubSelectFilter class
***
*****************************************************************************/
#pragma once

#include "../acedinpt.h"
#include "../AcCoreDefs.h"

class AcApDocument;
class AcEdSubSelectFilterService;

#include "IcArxPackPush.h"

class AcEdSSGetSubSelectFilter : public AcEdInputContextReactor
{
public:
	ACAD_PORT virtual ~AcEdSSGetSubSelectFilter() = default;

	virtual Acad::ErrorStatus getSubentPathsAtGsMarker(
			AcDbEntity* pEnt, bool bAdding, const AcDbFullSubentPathArray& selectedPaths,
			AcDb::SubentType type, IcArx::Integers::GsMarker gsMark, const AcGePoint3d& pickPoint,
			const AcGeMatrix3d& viewXForm, int& numPaths, AcDbFullSubentPath*& subentPaths,
			int numInserts, AcDbObjectId* entAndInsertStack) = 0;
	virtual void ssgetAddFilter(int ssgetFlags, AcEdSubSelectFilterService& service,
								const AcDbObjectId& object,
								const AcDbFullSubentPathArray& selectedPaths,
								const AcDbFullSubentPathArray& addedPaths) = 0;
	virtual void ssgetRemoveFilter(int ssgetFlags, AcEdSubSelectFilterService& service,
								   const AcDbObjectId& object,
								   const AcDbFullSubentPathArray& selectedPaths,
								   const AcDbFullSubentPathArray& removedPaths) = 0;
	virtual Acad::ErrorStatus subSelectClassList(AcArray<AcRxClass*>& classes) = 0;
};

#include "IcArxPackPop.h"

ACCORE_PORT Acad::ErrorStatus addSSgetFilterInputContextReactor(AcApDocument* pDoc,
																AcEdSSGetSubSelectFilter* pFilter);
ACCORE_PORT Acad::ErrorStatus removeSSgetFilterInputContextReactor(
		AcApDocument* pDoc, AcEdSSGetSubSelectFilter* pFilter);

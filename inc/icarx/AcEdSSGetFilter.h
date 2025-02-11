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
***     Description: Declaration of AcEdSSGetFilter class
***
*****************************************************************************/
#pragma once

#include "../acedinpt.h"
#include "../AcCoreDefs.h"

using AcDbArrayIntArray = AcArray<AcDbIntArray, AcArrayObjectCopyReallocator<AcDbIntArray>>;

class AcEdSelectionSetService;
class AcApDocument;
struct resbuf;

#include "IcArxPackPush.h"

class AcEdSSGetFilter : public AcEdInputContextReactor
{
public:
	enum MethodGroups
	{
		kAddRemove = 1,
		kBeginEnd = 2,
		kRollover = 4,
		kMisc = 8,
		kAll = 15
	};

public:
	ACAD_PORT virtual ~AcEdSSGetFilter() = default;

	virtual void beginSSGetCustomKeywordCallback(const ACHAR* /*pKeyword*/) {}
	virtual void endEntsel(Acad::PromptStatus returnStatus, const AcDbObjectId& pickedEntity,
						   const AcGePoint3d& pickedPoint, AcEdSelectionSetService& service)
	{
		(void)(returnStatus);
		(void)(pickedEntity);
		(void)(pickedPoint);
		(void)(service);
	}
	virtual void endNEntsel(Acad::PromptStatus returnStatus, const AcDbObjectId& pickedEntity,
							const AcGePoint3d& pickedPoint, ads_point xformres[4],
							struct resbuf** refstkres, AcEdSelectionSetService& service)
	{
		(void)(returnStatus);
		(void)(pickedEntity);
		(void)(pickedPoint);
		(void)(xformres);
		(void)(refstkres);
		(void)(service);
	}
	virtual void endSSGet(Acad::PromptStatus returnStatus, int ssgetFlags,
						  AcEdSelectionSetService& service, const AcDbObjectIdArray& selectionSet)
	{
		(void)(returnStatus);
		(void)(ssgetFlags);
		(void)(service);
		(void)(selectionSet);
	}
	virtual void endSSGetCustomKeywordCallback(const ACHAR* /*pKeyword*/) {}
	virtual void ssgetAddFailed(int ssgetFlags, int ssgetMode, AcEdSelectionSetService& service,
								const AcDbObjectIdArray& selectionSet, resbuf* rbPoints)
	{
		(void)(ssgetFlags);
		(void)(ssgetMode);
		(void)(service);
		(void)(selectionSet);
		(void)(rbPoints);
	}
	virtual void ssgetAddFilter(int ssgetFlags, AcEdSelectionSetService& service,
								const AcDbObjectIdArray& selectionSet,
								const AcDbObjectIdArray& subSelectionSet)
	{
		(void)(ssgetFlags);
		(void)(service);
		(void)(selectionSet);
		(void)(subSelectionSet);
	}
	virtual void ssgetPreviewFilter(const AcDbFullSubentPathArray& subEntityPaths,
									AcDbFullSubentPathArray& highlightPaths)
	{
		(void)(subEntityPaths);
		(void)(highlightPaths);
	}
	virtual void ssgetRemoveFailed(int ssgetFlags, int ssgetMode, AcEdSelectionSetService& service,
								   const AcDbObjectIdArray& selectionSet, resbuf* rbPoints,
								   AcDbIntArray& removeIndexes,
								   AcDbArrayIntArray& removeSubentIndexes)
	{
		(void)(ssgetFlags);
		(void)(ssgetMode);
		(void)(service);
		(void)(selectionSet);
		(void)(rbPoints);
		(void)(removeIndexes);
		(void)(removeSubentIndexes);
	}
	virtual void ssgetRemoveFilter(int ssgetFlags, AcEdSelectionSetService& service,
								   const AcDbObjectIdArray& selectionSet,
								   const AcDbObjectIdArray& subSelectionSet,
								   AcDbIntArray& removeIndexes,
								   AcDbArrayIntArray& removeSubentIndexes)
	{
		(void)(ssgetFlags);
		(void)(service);
		(void)(selectionSet);
		(void)(subSelectionSet);
		(void)(removeIndexes);
		(void)(removeSubentIndexes);
	}
	virtual void ssgetRolloverFilter(const AcDbFullSubentPath& subEntityPath,
									 AcDbFullSubentPath& highlightPath)
	{
		(void)(subEntityPath);
		(void)(highlightPath);
	}
	virtual void ssgetRolloverFilter(const AcDbFullSubentPath& subEntityPath,
									 AcDbFullSubentPathArray& highlightPaths)
	{
		(void)(subEntityPath);
		(void)(highlightPaths);
	}
};

#include "IcArxPackPop.h"

using AcEdSSGetFilter2 = AcEdSSGetFilter;
using AcEdSSGetFilter3 = AcEdSSGetFilter;
using AcEdSSGetFilter4 = AcEdSSGetFilter;

ACCORE_PORT Acad::ErrorStatus addSSgetFilterInputContextReactor(
		AcApDocument* pDoc, AcEdSSGetFilter* pFilter,
		int nMethodsOverridden = AcEdSSGetFilter::MethodGroups::kAll);
ACCORE_PORT bool duplicateSelectionsAllowed(AcApDocument* pDoc);
ACCORE_PORT Acad::ErrorStatus removeSSgetFilterInputContextReactor(AcApDocument* pDoc,
																   AcEdSSGetFilter* pFilter);
ACCORE_PORT Acad::ErrorStatus setAllowDuplicateSelection(AcApDocument* pDoc, bool flag);


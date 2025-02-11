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
***     Description: Declaration of AcGiTextEngine class
***
*****************************************************************************/
#pragma once

#include "acedinpt.h"

using AcSubentPathArray = AcDbFullSubentPathArray;

class AcGiViewport;

#include "icarx/IcArxPackPush.h"

class AcEdSubSelectFilter : public AcRxObject
{
public:
	enum SubSelectStatus
	{
		kSubSelectionNone = 0,
		kSubSelectionAugment,
		kSubSelectionExclusive,
		kSubSelectAll
	};

public:
	ACRX_DECLARE_MEMBERS(AcEdSubSelectFilter);

	ACAD_PORT virtual ~AcEdSubSelectFilter();

	virtual Acad::ErrorStatus subSelectClassList(AcArray<AcRxClass*>& clsIds) { return Acad::eOk; }
	virtual SubSelectStatus subSelectEntity(const AcGePoint3d& wpt1, const AcGePoint3d& wpt2,
											const AcGeVector3d& wvwdir, const AcGeVector3d& wvwxdir,
											double wxaper, double wyaper, AcDb::SelectType seltype,
											bool bAugment, bool bIsInPickfirstSet, bool bEvery,
											const AcGiViewport* pCurVP, AcDbEntity* pEnt,
											AcDbFullSubentPathArray& paths)
	{
		return kSubSelectionNone;
	}
	virtual SubSelectStatus subSelectEntity(const resbuf* pResbuf, bool bAugment,
											bool bIsInPickfirstSet, bool bEvery,
											const AcGiViewport* pCurVP, AcDbEntity* pEnt,
											AcDbFullSubentPathArray& paths)
	{
		return kSubSelectionNone;
	}
	virtual bool cancelAllSubSelect() { return false; }
	virtual bool cancelSubSelect(AcDbEntity* pEnt) { return false; }
	virtual bool isSubSelected(AcDbEntity* pEnt) const { return false; }
	virtual bool onKey(uint32_t wMsg, unsigned int nChar, unsigned int rptCnt, unsigned int flags)
	{
		return false;
	}
	virtual bool reSubSelectEntity(AcDbEntity* pEnt, AcDbFullSubentPathArray& paths)
	{
		return false;
	}
	virtual bool selectEntity(const AcGePoint3d& wvpt, const AcGeVector3d& wvwdir,
							  const AcGeVector3d& wvwxdir, double wxaper, double wyaper,
							  int32_t flags, const AcGiViewport* pCurVp, AcDbEntity* pEnt) const
	{
		return false;
	}
	virtual bool selectEntity(const AcGePoint3dArray& wvpts, const AcGeVector3d& wvwdir,
							  const AcGeVector3d& wvwxdir, double wxaper, double wyaper,
							  int32_t flags, const AcGiViewport* pCurVp, AcDbEntity* pEnt) const
	{
		return false;
	}
};

#include "icarx/IcArxPackPop.h"

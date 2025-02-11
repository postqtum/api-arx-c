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
***     Description:  XRef related routines
***
*****************************************************************************/
#pragma once

#include "acdbport.h"
#include "dbidar.h"

class AcDbBlockTableRecord;
class AcDbDatabase;
class AcGePoint3d;
class AcGeScale3d;

void acedMarkForDelayXRefRelativePathResolve(const AcDbObjectId& xrefDefId);
ACDB_PORT Acad::ErrorStatus acedSetXrefResolvedWithUpdateStatus(AcDbBlockTableRecord* pBTR);
Acad::ErrorStatus acedSkipXrefNotification(AcDbDatabase* pHostDb, const ACHAR* xrefName);
void acedUnmarkForDelayXRefRelativePathResolve(const AcDbObjectId& xrefDefId);
Acad::ErrorStatus acedXrefAttach(const ACHAR* XrefPathname, const ACHAR* XrefBlockname,
								 AcDbObjectId* pXrefBTRid = nullptr, AcDbObjectId* pXrefRefid = nullptr,
								 const AcGePoint3d* pXrefInsertPt = nullptr,
								 const AcGeScale3d* pXrefScale = nullptr,
								 const double* pXrefRotateAngle = nullptr, const bool bQuiet = true,
								 AcDbDatabase* pHostDb = nullptr, const wchar_t* wszPassword = nullptr);
Acad::ErrorStatus acedXrefBind(const ACHAR* XrefBlockname, const bool bInsertBind = false,
							   const bool bQuiet = true, AcDbDatabase* pHostDb = nullptr);
Acad::ErrorStatus acedXrefCreateBlockname(const ACHAR* XrefPathname, ACHAR*& XrefBlockname);
Acad::ErrorStatus acedXrefDetach(const ACHAR* XrefBlockname, const bool bQuiet = true,
								 AcDbDatabase* pHostDb = nullptr);
Acad::ErrorStatus acedXrefNotifyCheckFileChanged(AcDbObjectId btrId, bool& hasChanged);
Acad::ErrorStatus acedXrefOverlay(const ACHAR* XrefPathname, const ACHAR* XrefBlockname,
								  AcDbObjectId* pXrefBTRid = nullptr, AcDbObjectId* pXrefRefid = nullptr,
								  const AcGePoint3d* pXrefInsertPt = nullptr,
								  const AcGeScale3d* pXrefScale = nullptr,
								  const double* pXrefRotateAngle = nullptr, const bool bQuiet = true,
								  AcDbDatabase* pHostDb = nullptr, const wchar_t* wszPassword = nullptr);
Acad::ErrorStatus acedXrefReload(const ACHAR* XrefBlockname, const bool bQuiet = true,
								 AcDbDatabase* pHostDb = nullptr);
Acad::ErrorStatus acedXrefReload(const AcDbObjectIdArray& XrefBTRids, bool bQuiet = true,
								 AcDbDatabase* pHostDb = nullptr);
Acad::ErrorStatus acedXrefResolve(AcDbDatabase* pHostDb, const bool bQuiet = true);
Acad::ErrorStatus acedXrefUnload(const ACHAR* XrefBlockname, const bool bQuiet = true,
								 AcDbDatabase* pHostDb = nullptr);
Acad::ErrorStatus acedXrefXBind(const AcDbObjectIdArray symbolIds, const bool bQuiet = true,
								AcDbDatabase* pHostDb = nullptr);

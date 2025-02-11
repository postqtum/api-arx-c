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
***     Description: Declaration of AcEdXrefFileLock class
***
*****************************************************************************/
#pragma once

#include "../dbidar.h"
#include "../acadstrc.h"

class AcDwgFileHandle;

class AcDbDatabase;

#include "IcArxPackPush.h"

class AcEdXrefFileLock
{
private:
	AcDwgFileHandle* mdwgfile;
	AcDbDatabase* mpXDB;
	AcDbDatabase* mpXDBlockFile;
	int mXldctltype;
	AcDbObjectId mXBTRid;
	AcDbObjectIdArray mXBTRidArray;
	bool mbIntTNmgmt;

public:
	ACDBCORE2D_PORT AcEdXrefFileLock();
	ACDBCORE2D_PORT ~AcEdXrefFileLock();

	ACDBCORE2D_PORT Acad::ErrorStatus consistencyCheck(int& retstatus,
													   const AcDbObjectId& selectedBTRid);
	ACDBCORE2D_PORT Acad::ErrorStatus consistencyCheck(int& retstatus,
													   const AcDbObjectId& selectedBTRid,
													   AcDbObjectIdArray& outofSyncBTRids);
	ACDBCORE2D_PORT Acad::ErrorStatus consistencyChecklocal(int& retstatus,
															const AcDbObjectId& selectedBTRid);
	ACDBCORE2D_PORT Acad::ErrorStatus lockFile(int& retstatus, const AcDbObjectId& selectedBTRid);
	ACDBCORE2D_PORT Acad::ErrorStatus releaseFile(int& retstatus, bool bSkipSaveback = false,
												  bool bReload = true);
	ACDBCORE2D_PORT Acad::ErrorStatus reloadFile(int& retstatus, const AcDbObjectIdArray& BTRids,
												 const int xldctltype = -1);
	ACDBCORE2D_PORT Acad::ErrorStatus reloadFile(int& retstatus, const int xldctltype = -1);
	ACDBCORE2D_PORT Acad::ErrorStatus xloadctlType(int& retstatus,
												   const AcDbObjectId& selectedBTRid);
	ACDBCORE2D_PORT AcDbObjectId getLockBtrId() const { return mXBTRid; }
	ACDBCORE2D_PORT const AcDbObjectIdArray& getoutofSyncIdArray() const { return mXBTRidArray; }
	ACDBCORE2D_PORT int getlockxloadctlType() const { return mXldctltype; }
	ACDBCORE2D_PORT void setInternalTNmgmt(bool bTNmgmt);
};

#include "IcArxPackPop.h"

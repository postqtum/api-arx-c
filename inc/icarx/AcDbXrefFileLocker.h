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
***     Description: Declaration of AcDbXrefFileLocker class
***
*****************************************************************************/
#pragma once

#include "AcEdXrefFileLock.h"
#include "AcDbEnumMode.h"

class AcDbDatabase;

#include "IcArxPackPush.h"

class AcDbXrefFileLocker
{
private:
	AcDbDatabase* mpXrefDatabase;
	AcEdXrefFileLock mXrefFileLock;
	Acad::ErrorStatus mStatus;
	bool mSaveBackToXrefFile;

private:
	AcDbXrefFileLocker() = delete;
	AcDbXrefFileLocker(const AcDbXrefFileLocker&) = delete;
	AcDbXrefFileLocker& operator=(AcDbXrefFileLocker&) = delete;

public:
	ACDBCORE2D_PORT explicit AcDbXrefFileLocker(AcDbDatabase* pXrefDatabase);
	ACDBCORE2D_PORT virtual ~AcDbXrefFileLocker();

	ACDBCORE2D_PORT Acad::ErrorStatus status() const;
	ACDBCORE2D_PORT static bool isXrefDatabase(const AcDbDatabase* pDatabase);
	ACDBCORE2D_PORT void release();
	ACDBCORE2D_PORT void setSaveBackToXrefFile(bool yesNo);
};

#include "IcArxPackPop.h"

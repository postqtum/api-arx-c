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
***     Description: Declaration of AcDbDgnRefFileRepath class
***
*****************************************************************************/
#pragma once

#include "../AcString.h"
#include "../acadstrc.h"
#include "AcDbDgnRefFileData.h"

using AcDbRefFileDataPtrArray = AcArray<AcDbDgnRefFileData*>;
using AcDbDgnRefFileIdArray = AcArray<AcDgnRefFileId>;

Acad::ErrorStatus acdbGetDgnFileReferences(const ACHAR* fileName, const ACHAR* pwd,
										   AcDbRefFileDataPtrArray& files);

#include "IcArxPackPush.h"

class AcDbDgnRefFileRepath
{
private:
	void* m_fileHandle = nullptr;

public:
	AcDbDgnRefFileRepath() = default;
	~AcDbDgnRefFileRepath();

	Acad::ErrorStatus getReferenceFilePaths(AcDbRefFileDataPtrArray& refFiles);
	Acad::ErrorStatus rePath(const AcDbDgnRefFileIdArray& refFileIds,
							 const AcStringArray& newRefFileNames);
	Acad::ErrorStatus setFile(const AcString& dgnPathAndFilename, const ACHAR* pwd);
};

#include "IcArxPackPop.h"

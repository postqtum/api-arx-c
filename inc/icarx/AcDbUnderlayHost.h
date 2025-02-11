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
***     Description: Declaration of AcDbUnderlayHost class
***
*****************************************************************************/
#pragma once

#include "AcDbUnderlayFile.h"

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcDbUnderlayHost
{
protected:
	virtual ~AcDbUnderlayHost() = 0;

public:
	static void getAdjustedColor(AcGeVector3d& rgbResult, const AcGeVector3d& rgbInputColor,
								 const AcGeVector3d& rgbCurrentBackgroundColor,
								 const AcGeVector3d& hslFadedContrastColor,
								 const AcDbUnderlayDrawContext& drawContext);
	virtual Acad::ErrorStatus getFile(const ACHAR* fullPath, const wchar_t* password,
									  AcDbUnderlayFile*& pFile) const = 0;
	virtual Acad::ErrorStatus getFile(IAcReadStream* pFileStream, const wchar_t* password,
									  AcDbUnderlayFile*& pFile) const = 0;
};

#include "IcArxPackPop.h"

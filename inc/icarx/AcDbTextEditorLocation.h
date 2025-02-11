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
***     Description: Declaration of AcDbTextEditorLocation class
***
*****************************************************************************/
#pragma once

#include "../AcDbCore2dDefs.h"

class TextEditorLocation;

#include "IcArxPackPush.h"

class AcDbTextEditorLocation
{
	friend class AcDbTextEditor;
	friend class AcDbTextEditorServices;
	friend class AcDbTextEditorCursor;

private:
	TextEditorLocation* m_pImp;

private:
	AcDbTextEditorLocation();
	~AcDbTextEditorLocation();
	bool operator==(const AcDbTextEditorLocation& other);

public:
	ACDBCORE2D_PORT void release();
};

#include "IcArxPackPop.h"

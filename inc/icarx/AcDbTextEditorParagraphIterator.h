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
***     Description: Declaration of AcDbTextEditorParagraphIterator class
***
*****************************************************************************/
#pragma once

#include "../AcDbCore2dDefs.h"

class AcDbTextEditor;
class AcDbTextEditorParagraph;
class AcDbImpTextEditorParagraphIterator;

#include "IcArxPackPush.h"

class AcDbTextEditorParagraphIterator
{
private:
	AcDbImpTextEditorParagraphIterator* m_pImp;

public:
	ACDBCORE2D_PORT AcDbTextEditorParagraphIterator(const AcDbTextEditor& textEditor);
	ACDBCORE2D_PORT ~AcDbTextEditorParagraphIterator();

	ACDBCORE2D_PORT AcDbTextEditorParagraph* current();
	ACDBCORE2D_PORT bool done();
	ACDBCORE2D_PORT void next();
};

#include "IcArxPackPop.h"

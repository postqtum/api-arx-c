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
***     Description: Declaration of AcDbTextEditorCursor class
***
*****************************************************************************/
#pragma once

#include "AcDbTextEditorSelectionBase.h"

class AcDbTextEditorParagraph;
class AcDbTextEditorColumn;
class AcDbTextEditorLocation;
class TextEditor;
class AcDbImpTextEditorCursor;

#include "IcArxPackPush.h"

class AcDbTextEditorCursor : public AcDbTextEditorSelectionBase
{
	friend class TextEditor;

protected:
	AcDbImpTextEditorCursor* m_pImpCursor;

protected:
	ACDBCORE2D_PORT AcDbTextEditorCursor(const TextEditor* pImp);
	AcDbTextEditorCursor(const AcDbTextEditorCursor&);
	ACDBCORE2D_PORT ~AcDbTextEditorCursor();
	AcDbTextEditorCursor& operator=(const AcDbTextEditorCursor&);

public:
	ACDBCORE2D_PORT AcDbTextEditorColumn* column();
	ACDBCORE2D_PORT AcDbTextEditorLocation* location() const;
	ACDBCORE2D_PORT AcDbTextEditorParagraph* paragraph();
	ACDBCORE2D_PORT Acad::ErrorStatus setLocation(const AcDbTextEditorLocation& location);
};

#include "IcArxPackPop.h"

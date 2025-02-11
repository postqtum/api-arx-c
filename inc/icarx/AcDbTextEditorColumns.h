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
***     Description: Declaration of AcDbTextEditorColumns class
***
*****************************************************************************/
#pragma once

#include "../acadstrc.h"
#include "../AcDbCore2dDefs.h"

#include "AcDbMText.h"

class AcDbTextEditorColumn;
class TextEditor;

#include "IcArxPackPush.h"

class AcDbTextEditorColumns
{
	friend class TextEditor;

private:
	TextEditor* m_pImp;

private:
	AcDbTextEditorColumns();
	~AcDbTextEditorColumns();
	AcDbTextEditorColumns(const AcDbTextEditorColumns&);
	AcDbTextEditorColumns& operator=(const AcDbTextEditorColumns&);

public:
	ACDBCORE2D_PORT bool autoHeight() const;
	ACDBCORE2D_PORT AcDbMText::ColumnType columnType() const;
	ACDBCORE2D_PORT int count() const;
	ACDBCORE2D_PORT AcDbTextEditorColumn* getAt(int i);
	ACDBCORE2D_PORT double gutter() const;
	ACDBCORE2D_PORT bool isFlowReversed() const;
	ACDBCORE2D_PORT static int maxCount();
	ACDBCORE2D_PORT Acad::ErrorStatus setAutoHeight(bool bAutoHeight);
	ACDBCORE2D_PORT Acad::ErrorStatus setColumnType(AcDbMText::ColumnType type);
	ACDBCORE2D_PORT Acad::ErrorStatus setCount(int count);
	ACDBCORE2D_PORT Acad::ErrorStatus setGutter(double value);
	ACDBCORE2D_PORT Acad::ErrorStatus setIsFlowReversed(bool isFlowReversed);
	ACDBCORE2D_PORT Acad::ErrorStatus setTotalWidth(double value);
	ACDBCORE2D_PORT Acad::ErrorStatus setWidth(double value);
	ACDBCORE2D_PORT double totalWidth() const;
	ACDBCORE2D_PORT double width() const;
};

#include "IcArxPackPop.h"

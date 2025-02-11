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
***     Description: Declaration of AcDbTextEditorStack class
***
*****************************************************************************/
#pragma once

#include "AcDbTextEditorSelectionBase.h"

class AcDbImpTextEditorStack;

#include "IcArxPackPush.h"

class AcDbTextEditorStack
{
public:
	enum StackType
	{
		kHorizontalStack,
		kDiagonalStack,
		kToleranceStack,
		kDecimalStack,
	};

private:
	AcDbImpTextEditorStack* m_pImpStack;

public:
	ACDBCORE2D_PORT AcDbTextEditorStack();
	ACDBCORE2D_PORT AcDbTextEditorStack(const AcDbTextEditorStack&);
	ACDBCORE2D_PORT ~AcDbTextEditorStack();
	ACDBCORE2D_PORT AcDbTextEditorStack& operator=(const AcDbTextEditorStack&);

	ACDBCORE2D_PORT AcDbTextEditorSelectionBase::FlowAlign alignType() const;
	ACDBCORE2D_PORT AcString bottom() const;
	ACDBCORE2D_PORT wchar_t decimalChar() const;
	ACDBCORE2D_PORT static double maxStackScale();
	ACDBCORE2D_PORT static double minStackScale();
	ACDBCORE2D_PORT double scale() const;
	ACDBCORE2D_PORT Acad::ErrorStatus setAlignType(AcDbTextEditorSelectionBase::FlowAlign align);
	ACDBCORE2D_PORT Acad::ErrorStatus setBottom(const AcString& bottom);
	ACDBCORE2D_PORT Acad::ErrorStatus setDecimalChar(wchar_t decimalChar);
	ACDBCORE2D_PORT Acad::ErrorStatus setScale(double scale);
	ACDBCORE2D_PORT Acad::ErrorStatus setTop(const AcString& top);
	ACDBCORE2D_PORT Acad::ErrorStatus setType(StackType type);
	ACDBCORE2D_PORT AcString top() const;
	ACDBCORE2D_PORT StackType type() const;
};

#include "IcArxPackPop.h"

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
***     Description: Declaration of AcDbTextEditorParagraphTab class
***
*****************************************************************************/
#pragma once

#include "../AcDbCore2dDefs.h"
#include "../acadstrc.h"

class AcDbImpTextEditorParagraphTab;

#include "IcArxPackPush.h"

class AcDbTextEditorParagraphTab
{
public:
	enum ParagraphTabType
	{
		kLeftTab,
		kCenterTab,
		kRightTab,
		kDecimalTab,
	};

private:
	AcDbImpTextEditorParagraphTab* m_pImp;

public:
	ACDBCORE2D_PORT AcDbTextEditorParagraphTab();
	ACDBCORE2D_PORT AcDbTextEditorParagraphTab(const AcDbTextEditorParagraphTab&);
	ACDBCORE2D_PORT ~AcDbTextEditorParagraphTab();
	ACDBCORE2D_PORT AcDbTextEditorParagraphTab& operator=(const AcDbTextEditorParagraphTab&);

	ACDBCORE2D_PORT wchar_t decimalChar() const;
	ACDBCORE2D_PORT double offset() const;
	ACDBCORE2D_PORT Acad::ErrorStatus setDecimalChar(wchar_t decchar);
	ACDBCORE2D_PORT Acad::ErrorStatus setOffset(double offdist);
	ACDBCORE2D_PORT Acad::ErrorStatus setType(ParagraphTabType type);
	ACDBCORE2D_PORT ParagraphTabType type() const;
};

#include "IcArxPackPop.h"

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
***     Description: Declaration of AcDbTextEditorParagraph class
***
*****************************************************************************/
#pragma once

#include "../AcDbCore2dDefs.h"
#include "../acadstrc.h"

#include "AcDbTextEditorSelectable.h"

class AcDbImpTextEditorParagraph;
class AcDbTextEditorParagraphTab;

#include "IcArxPackPush.h"

class AcDbTextEditorParagraph : public AcDbTextEditorSelectable
{
	friend class AcDbTextEditorParagraphIterator;
	friend class AcDbTextEditorServices;

public:
	enum AlignmentType
	{
		kAlignmentDefault,
		kAlignmentLeft,
		kAlignmentCenter,
		kAlignmentRight,
		kAlignmentJustify,
		kAlignmentDistribute
	};

	enum LineSpacingStyle
	{
		kLineSpacingDefault,
		kLineSpacingExactly,
		kLineSpacingAtLeast,
		kLineSpacingMultiple,
	};

	enum NumberingType
	{
		kOff = 0,
		kBullet,
		kNumber,
		kLetterLower,
		kLetterUpper,
		kNumberWide,
		kLetterLowerWide,
		kLetterUpperWide,
	};

private:
	AcDbImpTextEditorParagraph* m_pImp;

	AcDbTextEditorParagraph() = default;
	~AcDbTextEditorParagraph();
	AcDbTextEditorParagraph(const AcDbTextEditorParagraph&);
	AcDbTextEditorParagraph& operator=(const AcDbTextEditorParagraph&);

public:
	ACDBCORE2D_PORT Acad::ErrorStatus addTab(const AcDbTextEditorParagraphTab& tab);
	ACDBCORE2D_PORT AlignmentType alignment() const;
	ACDBCORE2D_PORT Acad::ErrorStatus continueNumbering();
	ACDBCORE2D_PORT AcDbTextEditorLocation* endOfText() override;
	ACDBCORE2D_PORT double firstIndent() const;
	ACDBCORE2D_PORT Acad::ErrorStatus getTab(int i, AcDbTextEditorParagraphTab& tab);
	ACDBCORE2D_PORT double leftIndent() const;
	ACDBCORE2D_PORT double lineSpacingFactor() const;
	ACDBCORE2D_PORT LineSpacingStyle lineSpacingStyle() const;
	ACDBCORE2D_PORT double maxLineSpacingFactor() const;
	ACDBCORE2D_PORT double maxSpaceValue() const;
	ACDBCORE2D_PORT double minLineSpacingFactor() const;
	ACDBCORE2D_PORT double minSpaceValue() const;
	ACDBCORE2D_PORT NumberingType numberingType() const;
	ACDBCORE2D_PORT void release();
	ACDBCORE2D_PORT Acad::ErrorStatus removeTab(const AcDbTextEditorParagraphTab& tab);
	ACDBCORE2D_PORT Acad::ErrorStatus restartNumbering();
	ACDBCORE2D_PORT double rightIndent() const;
	ACDBCORE2D_PORT Acad::ErrorStatus setAlignment(AlignmentType AlignmentType);
	ACDBCORE2D_PORT Acad::ErrorStatus setFirstIndent(double firstIndent);
	ACDBCORE2D_PORT Acad::ErrorStatus setLeftIndent(double leftIndent);
	ACDBCORE2D_PORT Acad::ErrorStatus setLineSpacingFactor(double lineSpacingFactor);
	ACDBCORE2D_PORT Acad::ErrorStatus setLineSpacingStyle(LineSpacingStyle lineSpacingStyle);
	ACDBCORE2D_PORT Acad::ErrorStatus setNumberingType(NumberingType type);
	ACDBCORE2D_PORT Acad::ErrorStatus setRightIndent(double rightIndent);
	ACDBCORE2D_PORT Acad::ErrorStatus setSpaceAfter(double spaceAfter);
	ACDBCORE2D_PORT Acad::ErrorStatus setSpaceBefore(double spaceBefore);
	ACDBCORE2D_PORT double spaceAfter() const;
	ACDBCORE2D_PORT double spaceBefore() const;
	ACDBCORE2D_PORT AcDbTextEditorLocation* startOfText() override;
	ACDBCORE2D_PORT int tabsCount() const;
};

#include "IcArxPackPop.h"

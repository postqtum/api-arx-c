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
***     Description: Declaration of AcDbTextEditor class
***
*****************************************************************************/
#pragma once

#include "../AcDbCore2dDefs.h"

#include "AcDbMText.h"
#include "AcDbTextEditorSelectable.h"
#include "AcDbTextEditorSelectionBase.h"
#include "AcDbMText.h"

class AcDbTextEditorColumns;
class AcDbTextEditorWipeout;
class AcDbTextEditorParagraphIterator;
class AcDbTextEditorSelection;
class AcDbTextEditorCursor;
class TextEditor;

#include "IcArxPackPush.h"

class AcDbTextEditor : public AcDbTextEditorSelectable
{
	friend class AcDbTextEditorLocation;
	friend class AcDbTextEditorParagraphIterator;

public:
	enum ExitStatus
	{
		kExitQuit = 0,
		kExitSave,
	};

	enum TextFindFlags
	{
		kFindMatchCase = 1 << 0,
		kFindWholeWord = 1 << 1,
		kFindHalfFullForm = 1 << 2,
		kFindIgnoreAccent = 1 << 3,
		kFindUseWildcards = 1 << 4,
	};

protected:
	TextEditor* m_pImp = nullptr;

protected:
	ACDBCORE2D_PORT AcDbTextEditor() = default;

public:
	ACDBCORE2D_PORT ~AcDbTextEditor();

private:
	AcDbTextEditor(const AcDbTextEditor& editor);
	AcDbTextEditor& operator=(const AcDbTextEditor& editor);

public:
	ACDBCORE2D_PORT double actualHeight() const;
	ACDBCORE2D_PORT double actualWidth() const;
	ACDBCORE2D_PORT AcDbMText::AttachmentPoint attachment() const;
	ACDBCORE2D_PORT bool autoCAPS();
	ACDBCORE2D_PORT bool autolistEnabled() const;
	ACDBCORE2D_PORT Acad::ErrorStatus clearSelection();
	ACDBCORE2D_PORT virtual void close(ExitStatus stat);
	ACDBCORE2D_PORT AcDbTextEditorColumns* columns();
	ACDBCORE2D_PORT static AcDbTextEditor* createDbTextEditor(AcDbMText* pMText);
	ACDBCORE2D_PORT int currentStyleIndex() const;
	ACDBCORE2D_PORT virtual AcDbTextEditorCursor* cursor();
	ACDBCORE2D_PORT AcDbTextEditorSelectionBase::FlowAlign defaultStackAlignment() const;
	ACDBCORE2D_PORT double defaultStackScale() const;
	ACDBCORE2D_PORT double definedHeight() const;
	ACDBCORE2D_PORT double definedWidth() const;
	ACDBCORE2D_PORT AcDbTextEditorLocation* endOfText() override;
	ACDBCORE2D_PORT Acad::ErrorStatus findText(const ACHAR* text, int flags,
											   AcDbTextEditorLocation*& pStart,
											   AcDbTextEditorLocation*& pEnd);
	ACDBCORE2D_PORT int getFontCount() const;
	ACDBCORE2D_PORT AcString getFontName(int index) const;
	ACDBCORE2D_PORT int getIndexFromStyleName(const AcString& styleName);
	ACDBCORE2D_PORT int getStyleCount() const;
	ACDBCORE2D_PORT AcString getStyleName(int index) const;
	ACDBCORE2D_PORT bool isAnnotativeStyle(int index) const;
	ACDBCORE2D_PORT bool isTrueTypeFont(int index) const;
	ACDBCORE2D_PORT bool isVerticalSHX() const;
	ACDBCORE2D_PORT bool isVerticalTTF() const;
	ACDBCORE2D_PORT Acad::ErrorStatus makeSelection(const AcDbTextEditorLocation* pStart,
													const AcDbTextEditorLocation* pEnd);
	ACDBCORE2D_PORT AcDbTextEditorParagraphIterator* newParagraphsIterator();
	ACDBCORE2D_PORT bool numberingEnabled() const;
	ACDBCORE2D_PORT void redraw();
	ACDBCORE2D_PORT Acad::ErrorStatus selectAll();
	ACDBCORE2D_PORT virtual AcDbTextEditorSelection* selection();
	ACDBCORE2D_PORT Acad::ErrorStatus setAttachment(AcDbMText::AttachmentPoint attachment);
	ACDBCORE2D_PORT Acad::ErrorStatus setAutoCAPS(bool autoCAPS);
	ACDBCORE2D_PORT Acad::ErrorStatus setAutolistEnabled(bool enabled);
	ACDBCORE2D_PORT Acad::ErrorStatus setDefaultStackAlignment(
			AcDbTextEditorSelectionBase::FlowAlign alignment);
	ACDBCORE2D_PORT Acad::ErrorStatus setDefaultStackScale(double scale);
	ACDBCORE2D_PORT Acad::ErrorStatus setDefinedHeight(double height);
	ACDBCORE2D_PORT Acad::ErrorStatus setDefinedWidth(double width);
	ACDBCORE2D_PORT Acad::ErrorStatus setEnableNumbering(bool bEnable);
	ACDBCORE2D_PORT Acad::ErrorStatus setStyle(int index);
	ACDBCORE2D_PORT Acad::ErrorStatus setStyle(AcDbObjectId styleId);
	ACDBCORE2D_PORT Acad::ErrorStatus setTabOnlyDelimiter(bool tabOnlyDelimiter);
	ACDBCORE2D_PORT Acad::ErrorStatus setTextHeight(double textHeight);
	ACDBCORE2D_PORT int stackCount() const;
	ACDBCORE2D_PORT AcDbTextEditorLocation* startOfText() override;
	ACDBCORE2D_PORT AcDbObjectId style(int index) const;
	ACDBCORE2D_PORT bool tabOnlyDelimiter() const;
	ACDBCORE2D_PORT double textHeight() const;
	ACDBCORE2D_PORT AcDbTextEditorWipeout* wipeout();
};

#include "IcArxPackPop.h"

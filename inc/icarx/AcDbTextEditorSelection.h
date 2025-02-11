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
***     Description: Declaration of AcDbTextEditorSelection class
***
*****************************************************************************/
#pragma once

#include "AcDbTextEditorSelectionBase.h"

class AcDbImpTextEditorSelection;
class AcDbTextEditorStack;
class AcDbTextEditorParagraph;
class AcDbTextEditorLocation;
class TextEditor;
class AcDbField;

#include "IcArxPackPush.h"

class AcDbTextEditorSelection : public AcDbTextEditorSelectionBase
{
	friend class TextEditor;

protected:
	AcDbImpTextEditorSelection* m_pImpSelection;

protected:
	ACDBCORE2D_PORT AcDbTextEditorSelection(const TextEditor* pImp);
	AcDbTextEditorSelection(const AcDbTextEditorSelection&);
	ACDBCORE2D_PORT ~AcDbTextEditorSelection();
	AcDbTextEditorSelection& operator=(const AcDbTextEditorSelection&);

public:
	ACDBCORE2D_PORT bool canChangeCase() const;
	ACDBCORE2D_PORT bool canStack() const;
	ACDBCORE2D_PORT bool canUnStack() const;
	ACDBCORE2D_PORT bool changeToLowercase();
	ACDBCORE2D_PORT bool changeToUppercase();
	ACDBCORE2D_PORT Acad::ErrorStatus combineParagraphs();
	ACDBCORE2D_PORT Acad::ErrorStatus convertToPlainText();
	ACDBCORE2D_PORT AcDbField* field() const;
	ACDBCORE2D_PORT bool fontSupported(const AcString& fontname, bool bTrueType) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getLocations(AcDbTextEditorLocation*& pStartLocation,
												   AcDbTextEditorLocation*& pEndLocation) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getSelectionText(AcString& txt) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getStack(AcDbTextEditorStack& stack) const;
	ACDBCORE2D_PORT bool languageSupported(Charset charset) const;
	ACDBCORE2D_PORT void paragraph(AcArray<AcDbTextEditorParagraph*>& paragraphs);
	ACDBCORE2D_PORT Acad::ErrorStatus removeAllFormatting();
	ACDBCORE2D_PORT Acad::ErrorStatus removeCharacterFormatting();
	ACDBCORE2D_PORT Acad::ErrorStatus removeParagraphFormatting();
	ACDBCORE2D_PORT Acad::ErrorStatus setStack(const AcDbTextEditorStack& stack);
	ACDBCORE2D_PORT bool singleFieldSelected() const;
	ACDBCORE2D_PORT bool singleStackSelected() const;
	ACDBCORE2D_PORT Acad::ErrorStatus stack();
	ACDBCORE2D_PORT Acad::ErrorStatus unStack();
	ACDBCORE2D_PORT Acad::ErrorStatus updateField();
};

#include "IcArxPackPop.h"

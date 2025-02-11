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
***     Description: Declaration of AcDbTextEditorSelectionBase class
***
*****************************************************************************/
#pragma once

#include "../AcDbCore2dDefs.h"
#include "../acadstrc.h"
#include "../AcString.h"
#include "../PAL/api/charset.h"

#include "AcCmColor.h"

class AcDbImpTextEditorSelectionBase;
class AcCmColor;

#include "IcArxPackPush.h"

class AcDbTextEditorSelectionBase
{
	friend class AcDbTextEditor;

public:
	enum FlowAlign
	{
		kFlowBase,
		kFlowCenter,
		kFlowTop
	};

	enum InsertTextType
	{
		kUnicodeMTextFormat,
		kMTextFormat,
		kRichTextFormat,
		kUnicodeDTextFormat,
		kDTextFormat,
		kUnicodeTextFormat,
		kMultibyteTextFormat
	};

protected:
	AcDbImpTextEditorSelectionBase* m_pImp;

protected:
	AcDbTextEditorSelectionBase();
	virtual ~AcDbTextEditorSelectionBase();
	AcDbTextEditorSelectionBase(const AcDbTextEditorSelectionBase&);
	AcDbTextEditorSelectionBase& operator=(const AcDbTextEditorSelectionBase&);

public:
	ACDBCORE2D_PORT bool bold() const;
	ACDBCORE2D_PORT AcCmColor color() const;
	ACDBCORE2D_PORT FlowAlign flowAlign() const;
	ACDBCORE2D_PORT AcString font() const;
	ACDBCORE2D_PORT double height() const;
	ACDBCORE2D_PORT Acad::ErrorStatus inputSpecialChar(uint32_t c);
	ACDBCORE2D_PORT Acad::ErrorStatus insertColumnBreak();
	ACDBCORE2D_PORT Acad::ErrorStatus insertImportedText(InsertTextType insertType, void* pData);
	ACDBCORE2D_PORT Acad::ErrorStatus insertString(const AcString& str);
	ACDBCORE2D_PORT Acad::ErrorStatus insertSymbol(ACHAR wch, Charset charset);
	ACDBCORE2D_PORT bool isTrueType() const;
	ACDBCORE2D_PORT bool italic() const;
	ACDBCORE2D_PORT Charset language() const;
	ACDBCORE2D_PORT static double maxObliqueAngle();
	ACDBCORE2D_PORT static double maxTrackingFactor();
	ACDBCORE2D_PORT static double maxWidthScale();
	ACDBCORE2D_PORT static double minObliqueAngle();
	ACDBCORE2D_PORT static double minTrackingFactor();
	ACDBCORE2D_PORT static double minWidthScale();
	ACDBCORE2D_PORT double obliqueAngle() const;
	ACDBCORE2D_PORT bool overline() const;
	ACDBCORE2D_PORT Acad::ErrorStatus setColor(const AcCmColor& color);
	ACDBCORE2D_PORT Acad::ErrorStatus setFlowAlign(FlowAlign flowAlign);
	ACDBCORE2D_PORT Acad::ErrorStatus setFont(const AcString& fontname, bool bTrueType);
	ACDBCORE2D_PORT Acad::ErrorStatus setHeight(double height);
	ACDBCORE2D_PORT Acad::ErrorStatus setLanguage(Charset charset);
	ACDBCORE2D_PORT Acad::ErrorStatus setObliqueAngle(double angle);
	ACDBCORE2D_PORT Acad::ErrorStatus setTrackingFactor(double factor);
	ACDBCORE2D_PORT Acad::ErrorStatus setWidthScale(double scale);
	ACDBCORE2D_PORT bool strikethrough() const;
	ACDBCORE2D_PORT Acad::ErrorStatus toggleBold();
	ACDBCORE2D_PORT Acad::ErrorStatus toggleItalic();
	ACDBCORE2D_PORT Acad::ErrorStatus toggleOverline();
	ACDBCORE2D_PORT Acad::ErrorStatus toggleStrikethrough();
	ACDBCORE2D_PORT Acad::ErrorStatus toggleUnderline();
	ACDBCORE2D_PORT double trackingFactor() const;
	ACDBCORE2D_PORT bool underline() const;
	ACDBCORE2D_PORT double widthScale() const;
};

#include "IcArxPackPop.h"

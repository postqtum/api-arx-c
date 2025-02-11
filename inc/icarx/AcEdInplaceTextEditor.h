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
***     Description: Declaration of AcEdInplaceTextEditor class
***
*****************************************************************************/
#pragma once

#include "../AcCoreDefs.h"
#include "../acadstrc.h"
#include "AcDbTextEditor.h"
#include "AcDbTextEditorParagraph.h"

class IPE_Editor;
class IAcEdInplaceTextEditorHost;
class AcEdInplaceTextEditorImp;
class AcEdInplaceTextEditorSettings;
class AcDbText;

#include "IcArxPackPush.h"

class AcEdInplaceTextEditor : public AcDbTextEditor
{
	friend class AcEdInplaceTextEditorImp;

public:
	enum TextUndoType
	{
		kUndoTyping = 1,
		kUndoBoldOn,
		kUndoBoldOff,
		kUndoItalicOn,
		kUndoItalicOff,
		kUndoUnderlineOn,
		kUndoUnderlineOff,
		kUndoOverlineOn,
		kUndoOverlineOff,
		kUndoFont,
		kUndoHeight,
		kUndoColor,
		kUndoObliqueAngle,
		kUndoWidthScale,
		kUndoTrackingFactor,
		kUndoLanguage,
		kUndoBackspace,
		kUndoDelete,
		kUndoPaste,
		kUndoCut,
		kUndoStack,
		kUndoUnstack,
		kUndoStackProperties,
		kUndoFieldInsert,
		kUndoFieldConvert,
		kUndoFieldUpdate,
		kUndoSymbolInsert,
		kUndoAutoField,
		kUndoAutoStack,
		kUndoAutoSymbol,
		kUndoAutoDTextEscape,
		kUndoAutoMifOrCif,
		kUndoAutoDimension,
		kUndoAutoDimBreak,
		kUndoAutoSpell,
		kUndoStyle,
		kUndoAttachment,
		kUndoChangeCase,
		kUndoImportText,
		kUndoCombineParagraphs,
		kUndoRemoveCharFormatting,
		kUndoRemoveParaFormatting,
		kUndoRemoveAllFormatting,
		kUndoReplaceAll,
		kUndoReplace,
		kUndoParagraphAttributes,
		kUndoSetDefinedWidth,
		kUndoSetDefinedHeight,
		kUndoCharAttributes,
		kUndoWipeout,
		kUndoDimensionInsert,
		kUndoDimBreakInsert,
		kUndoCustomConvert,
		kUndoDeleteAndMoveSelection,
		kUndoParagraphNumbering,
		kUndoCursorAttributes,
		kUndoColumns,
		kUndoAnnoState,
		kUndoDimensionTweak,
		kUndoDimensionSymbol,
		kUndoDimensionTemplate,
	};

protected:
	AcEdInplaceTextEditorImp* m_pEditorImp;
	IPE_Editor* m_pIPEEditorImp;

protected:
	AcEdInplaceTextEditor();
	~AcEdInplaceTextEditor();
	AcEdInplaceTextEditor(const AcEdInplaceTextEditor&);
	AcEdInplaceTextEditor& operator=(const AcEdInplaceTextEditor&);

public:
	ACCORE_PORT Acad::ErrorStatus addUndoMarker(TextUndoType type);
	ACCORE_PORT bool annotative() const;
	ACCORE_PORT Acad::ErrorStatus attachmentMenusInput(AcGePoint2d* menuPt, HWND parentHandle);
	ACCORE_PORT bool canCopy() const;
	ACCORE_PORT bool canCut() const;
	ACCORE_PORT bool canExitInplaceEditor();
	ACCORE_PORT bool canPaste() const;
	ACCORE_PORT bool canRedo() const;
	ACCORE_PORT bool canUndo() const;
	ACCORE_PORT void close(ExitStatus stat) override;
	ACCORE_PORT Acad::ErrorStatus columnMenusInput(AcGePoint2d* menuPt, HWND parentHandle);
	ACCORE_PORT Acad::ErrorStatus contextMenusInput(AcGePoint2d* menuPt, HWND parentHandle);
	ACCORE_PORT Acad::ErrorStatus copy();
	ACCORE_PORT static AcEdInplaceTextEditor* current();
	ACCORE_PORT Acad::ErrorStatus cut();
	ACCORE_PORT void drawHighlight();
	ACCORE_PORT void enableWysiwyg();
	ACCORE_PORT void findMatchItem(int findFlags, const AcString& findStr) const;
	ACCORE_PORT bool forcedOpaqueBackground();
	ACCORE_PORT AcDbTextEditorParagraph::AlignmentType getAlignmentFromAttachment() const;
	ACCORE_PORT void insertFile(const AcString& fileName);
	ACCORE_PORT static Acad::ErrorStatus invoke(AcDbMText* pMtext,
												const AcEdInplaceTextEditorSettings* pSettings);
	ACCORE_PORT static Acad::ErrorStatus invoke(AcDbText* pText,
												AcDbObjectIdArray* appendedEntities);
	ACCORE_PORT Acad::ErrorStatus invokeColumnsDialog(int iStaticColumnCount = 0);
	ACCORE_PORT Acad::ErrorStatus invokeFieldDialog(AcDbField* pField = nullptr);
	ACCORE_PORT Acad::ErrorStatus invokeFindReplaceDialog();
	ACCORE_PORT Acad::ErrorStatus invokeHelpDialog();
	ACCORE_PORT Acad::ErrorStatus invokeHightlightColorDialog();
	ACCORE_PORT Acad::ErrorStatus invokeImportTextDialog();
	ACCORE_PORT Acad::ErrorStatus invokeNewFeatureWorkshop();
	ACCORE_PORT Acad::ErrorStatus invokeParagraphDialog();
	ACCORE_PORT Acad::ErrorStatus invokeSpellSettingDialog();
	ACCORE_PORT Acad::ErrorStatus invokeSpellerDictionaryDialog();
	ACCORE_PORT Acad::ErrorStatus invokeStackPropertyDialog();
	ACCORE_PORT Acad::ErrorStatus invokeWipeoutDialog();
	ACCORE_PORT bool isMultiAttribute() const;
	ACCORE_PORT bool isParagraphSupported() const;
	ACCORE_PORT bool isSimpleMtext() const;
	ACCORE_PORT bool isTableCell() const;
	ACCORE_PORT bool isText() const;
	ACCORE_PORT COLORREF layerColor() const;
	ACCORE_PORT Acad::ErrorStatus lineSpaceMenusInput(AcGePoint2d* menuPt, HWND parentHandle);
	ACCORE_PORT Acad::ErrorStatus numberingMenusInput(AcGePoint2d* menuPt, HWND parentHandle);
	ACCORE_PORT bool opaqueBackground();
	ACCORE_PORT void otherSymbol();
	ACCORE_PORT Acad::ErrorStatus paste();
	ACCORE_PORT Acad::ErrorStatus pasteWithoutFormats();
	ACCORE_PORT Acad::ErrorStatus redo();
	ACCORE_PORT void removeHightlight();
	ACCORE_PORT void replaceAllMatchItems(int findFlags, const AcString& findStr,
										  const AcString& replaceStr) const;
	ACCORE_PORT void replaceCurrentMatchItem(int findFlags, const AcString& findStr,
											 const AcString& replaceStr) const;
	ACCORE_PORT bool rulerHidden() const;
	ACCORE_PORT bool rulerSupported() const;
	ACCORE_PORT Acad::ErrorStatus setAnnotative(bool bSet);
	ACCORE_PORT void setCanExitInplaceEditor(bool bCanExit);
	ACCORE_PORT void setHost(IAcEdInplaceTextEditorHost* pHost);
	ACCORE_PORT void setOpaqueBackground(bool opaqueBackground);
	ACCORE_PORT void setRulerHidden(bool hideRuler);
	ACCORE_PORT Acad::ErrorStatus setStaticColumnsWithCount(int columnCount);
	ACCORE_PORT Acad::ErrorStatus setTextLayer(const AcString& layername);
	ACCORE_PORT void setToolbarHidden(bool bHideToolbar);
	ACCORE_PORT void setToolbarOptionHidden(bool bHideOption);
	ACCORE_PORT Acad::ErrorStatus setUndoRecordingDisable(bool disabled);
	ACCORE_PORT bool spellerEnabled() const;
	ACCORE_PORT Acad::ErrorStatus symbolMenusInput(AcGePoint2d* menuPt, HWND parentHandle);
	ACCORE_PORT void toggleSpelling();
	ACCORE_PORT bool toolbarHidden() const;
	ACCORE_PORT bool toolbarOptionHidden() const;
	ACCORE_PORT Acad::ErrorStatus undo();
	ACCORE_PORT bool undoRecordingDisabled();
	ACCORE_PORT bool wysiwyg();
};

#include "IcArxPackPop.h"

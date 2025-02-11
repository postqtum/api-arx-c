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
***     Description: Declaration of AcDbEnumTable
***
*****************************************************************************/
#pragma once

#include "AcDb.h"

enum AcDb::CellType
{
	kUnknownCell = 0,
	kTextCell = 1,
	kBlockCell = 2,
	kMultipleContentCell = 3
};

enum AcDb::CellContentType
{
	kCellContentTypeUnknown = 0,
	kCellContentTypeValue = 0x1,
	kCellContentTypeField = 0x2,
	kCellContentTypeBlock = 0x4,
};

enum AcDb::CellEdgeMask
{
	kTopMask = 1,
	kRightMask = 2,
	kBottomMask = 4,
	kLeftMask = 8
};

enum AcDb::CellMargin
{
	kCellMarginTop = 0x1,
	kCellMarginLeft = 0x2,
	kCellMarginBottom = 0x4,
	kCellMarginRight = 0x8,
	kCellMarginHorzSpacing = 0x10,
	kCellMarginVertSpacing = 0x20
};

enum AcDb::CellContentLayout
{
	kCellContentLayoutFlow = 0x1,
	kCellContentLayoutStackedHorizontal = 0x2,
	kCellContentLayoutStackedVertical = 0x4,
};

enum AcDb::CellState
{
	kCellStateNone = 0,
	kCellStateContentLocked = 0x1,
	kCellStateContentReadOnly = 0x2,
	kCellStateLinked = 0x4,
	kCellStateContentModifiedAfterUpdate = 0x8,
	kCellStateFormatLocked = 0x10,
	kCellStateFormatReadOnly = 0x20,
	kCellStateFormatModifiedAfterUpdate = 0x40,
	kAllCellStates =
			(AcDb::CellState::kCellStateContentLocked | AcDb::CellState::kCellStateContentReadOnly |
			 AcDb::CellState::kCellStateLinked |
			 AcDb::CellState::kCellStateContentModifiedAfterUpdate |
			 AcDb::CellState::kCellStateFormatLocked | AcDb::CellState::kCellStateFormatReadOnly |
			 AcDb::CellState::kCellStateFormatModifiedAfterUpdate),
};

enum AcDb::CellClass
{
	kCellClassNone = 0,
	kCellClassLabel = 0x1,
	kCellClassData = 0x2,
};

enum AcDb::CellProperty
{
	kCellPropInvalid = 0,

	kCellPropDataType = 0x1,
	kCellPropDataFormat = 0x2,
	kCellPropRotation = 0x4,
	kCellPropScale = 0x8,
	kCellPropAlignment = 0x10,
	kCellPropContentColor = 0x20,
	kCellPropTextStyle = 0x40,
	kCellPropTextHeight = 0x80,
	kCellPropAutoScale = 0x100,

	kCellPropBackgroundColor = 0x200,
	kCellPropMarginLeft = 0x400,
	kCellPropMarginTop = 0x800,
	kCellPropMarginRight = 0x1000,
	kCellPropMarginBottom = 0x2000,
	kCellPropMarginHorzSpacing = 0x20000,
	kCellPropMarginVertSpacing = 0x40000,
	kCellPropContentLayout = 0x4000,

	kCellPropMergeAll = 0x8000,

	kCellPropFlowDirBtoT = 0x10000,

	kCellPropDataTypeAndFormat =
			(AcDb::CellProperty::kCellPropDataType | AcDb::CellProperty::kCellPropDataFormat),
	kCellPropContent =
			(AcDb::CellProperty::kCellPropDataType | AcDb::CellProperty::kCellPropDataFormat |
			 AcDb::CellProperty::kCellPropRotation | AcDb::CellProperty::kCellPropScale |
			 AcDb::CellProperty::kCellPropContentColor | AcDb::CellProperty::kCellPropTextStyle |
			 AcDb::CellProperty::kCellPropTextHeight | AcDb::CellProperty::kCellPropAutoScale),
	kCellPropBitProperties =
			(AcDb::CellProperty::kCellPropAutoScale | AcDb::CellProperty::kCellPropMergeAll |
			 AcDb::CellProperty::kCellPropFlowDirBtoT),
	kCellPropAll =
			(AcDb::CellProperty::kCellPropDataType | AcDb::CellProperty::kCellPropDataFormat |
			 AcDb::CellProperty::kCellPropRotation | AcDb::CellProperty::kCellPropScale |
			 AcDb::CellProperty::kCellPropAlignment | AcDb::CellProperty::kCellPropContentColor |
			 AcDb::CellProperty::kCellPropBackgroundColor | AcDb::CellProperty::kCellPropTextStyle |
			 AcDb::CellProperty::kCellPropTextHeight | AcDb::CellProperty::kCellPropMarginLeft |
			 AcDb::CellProperty::kCellPropMarginTop | AcDb::CellProperty::kCellPropMarginRight |
			 AcDb::CellProperty::kCellPropMarginBottom |
			 AcDb::CellProperty::kCellPropMarginHorzSpacing |
			 AcDb::CellProperty::kCellPropMarginVertSpacing |
			 AcDb::CellProperty::kCellPropAutoScale | AcDb::CellProperty::kCellPropMergeAll |
			 AcDb::CellProperty::kCellPropFlowDirBtoT | AcDb::CellProperty::kCellPropContentLayout),
};

enum AcDb::GridProperty
{
	kGridPropInvalid = 0,
	kGridPropLineStyle = 0x1,
	kGridPropLineWeight = 0x2,
	kGridPropLinetype = 0x4,
	kGridPropColor = 0x8,
	kGridPropVisibility = 0x10,
	kGridPropDoubleLineSpacing = 0x20,
	kGridPropAll =
			(AcDb::GridProperty::kGridPropLineStyle | AcDb::GridProperty::kGridPropLineWeight |
			 AcDb::GridProperty::kGridPropLinetype | AcDb::GridProperty::kGridPropColor |
			 AcDb::GridProperty::kGridPropVisibility |
			 AcDb::GridProperty::kGridPropDoubleLineSpacing),
};

enum AcDb::GridLineType
{
	kInvalidGridLine = 0,
	kHorzTop = 1,
	kHorzInside = 2,
	kHorzBottom = 4,
	kVertLeft = 8,
	kVertInside = 0x10,
	kVertRight = 0x20,
	kHorzGridLineTypes = AcDb::GridLineType::kHorzTop | AcDb::GridLineType::kHorzBottom |
						 AcDb::GridLineType::kHorzInside,
	kVertGridLineTypes = AcDb::GridLineType::kVertLeft | AcDb::GridLineType::kVertRight |
						 AcDb::GridLineType::kVertInside,
	kOuterGridLineTypes = AcDb::GridLineType::kHorzTop | AcDb::GridLineType::kHorzBottom |
						  AcDb::GridLineType::kVertLeft | AcDb::GridLineType::kVertRight,
	kInnerGridLineTypes = AcDb::GridLineType::kHorzInside | AcDb::GridLineType::kVertInside,
	kAllGridLineTypes =
			AcDb::GridLineType::kOuterGridLineTypes | AcDb::GridLineType::kInnerGridLineTypes
};

enum AcDb::GridLineStyle
{
	kGridLineStyleSingle = 1,
	kGridLineStyleDouble = 2,
};

enum AcDb::CellOption
{
	kCellOptionNone = 0,
	kInheritCellFormat = 0x1,
};

enum AcDb::GridLineTypes
{
	kAllGridLines = AcDb::GridLineType::kAllGridLineTypes
};

enum AcDb::CellAlignment
{
	kTopLeft = 1,
	kTopCenter = 2,
	kTopRight = 3,
	kMiddleLeft = 4,
	kMiddleCenter = 5,
	kMiddleRight = 6,
	kBottomLeft = 7,
	kBottomCenter = 8,
	kBottomRight = 9
};

enum AcDb::RowType
{
	kUnknownRow = 0,
	kDataRow = 1,
	kTitleRow = 2,
	kHeaderRow = 4,
	kAllRowTypes = AcDb::RowType::kDataRow | AcDb::RowType::kTitleRow | AcDb::RowType::kHeaderRow
};

enum AcDb::TableStyleFlags
{
	kHorzInsideLineFirst = 0x1,
	kHorzInsideLineSecond = 0x2,
	kHorzInsideLineThird = 0x4,
	kTableStyleModified = 0x8,
	kTableStyleDataTypeModified = 0x10,
};

enum AcDb::TableBreakOption
{
	kTableBreakNone = 0,
	kTableBreakEnableBreaking = 0x1,
	kTableBreakRepeatTopLabels = 0x2,
	kTableBreakRepeatBottomLabels = 0x4,
	kTableBreakAllowManualPositions = 0x8,
	kTableBreakAllowManualHeights = 0x10,
};

enum AcDb::TableBreakFlowDirection
{
	kTableBreakFlowRight = 0x1,
	kTableBreakFlowDownOrUp = 0x2,
	kTableBreakFlowLeft = 0x4,
};

enum AcDb::TableFillOption
{
	kTableFillNone = 0,
	kTableFillRow = 0x1,
	kTableFillReverse = 0x2,
	kTableFillGenerateSeries = 0x4,
	kTableFillCopyContent = 0x8,
	kTableFillCopyFormat = 0x10,
	kTableFillOverwriteReadOnlyContent = 0x20,
	kTableFillOverwriteReadOnlyFormat = 0x40,
};

enum AcDb::TableCopyOption
{
	kTableCopyNone = 0,
	kTableCopyExpandOrContractTable = 0x1,
	kTableCopySkipContent = 0x2,
	kTableCopySkipValue = 0x4,
	kTableCopySkipField = 0x8,
	kTableCopySkipFormula = 0x10,
	kTableCopySkipBlock = 0x20,
	kTableCopySkipDataLink = 0x40,
	kTableCopySkipLabelCell = 0x80,
	kTableCopySkipDataCell = 0x100,
	kTableCopySkipFormat = 0x200,
	kTableCopySkipCellStyle = 0x400,
	kTableCopyConvertFormatToOverrides = 0x800,
	kTableCopySkipCellState = 0x1000,
	kTableCopySkipContentFormat = 0x2000,
	kTableCopySkipDissimilarContentFormat = 0x4000,
	kTableCopySkipGeometry = 0x8000,
	kTableCopySkipMerges = 0x10000,
	kTableCopyFillTarget = 0x20000,
	kTableCopyOverwriteReadOnlyContent = 0x40000,
	kTableCopyOverwriteReadOnlyFormat = 0x80000,
	kTableCopyOverwriteContentModifiedAfterUpdate = 0x100000,
	kTableCopyOverwriteFormatModifiedAfterUpdate = 0x200000,
	kTableCopyOnlyContentModifiedAfterUpdate = 0x400000,
	kTableCopyOnlyFormatModifiedAfterUpdate = 0x800000,
	kTableCopyRowHeight = 0x1000000,
	kTableCopyColumnWidth = 0x2000000,
	kTableCopyFullCellState = 0x4000000,
	kTableCopyForRountrip = 0x8000000,
	kTableCopyConvertFieldToValue = 0x10000000,
	kTableCopySkipFieldTranslation = 0x20000000,
	kForceTableCopyForRountrip = 0x40000000,
};

enum AcDb::TableIteratorOption
{
	kTableIteratorNone = 0,
	kTableIteratorIterateSelection = 0x1,
	kTableIteratorIterateRows = 0x2,
	kTableIteratorIterateColumns = 0x4,
	kTableIteratorIterateDataLinks = 0x80,
	kTableIteratorReverseOrder = 0x8,
	kTableIteratorSkipReadOnlyContent = 0x10,
	kTableIteratorSkipReadOnlyFormat = 0x20,
	kTableIteratorSkipMerged = 0x40,
};

enum AcDb::MergeCellStyleOption
{
	kMergeCellStyleNone = 0,
	kMergeCellStyleCopyDuplicates = 0x1,
	kMergeCellStyleOverwriteDuplicates = 0x2,
	kMergeCellStyleConvertDuplicatesToOverrides = 0x4,
	kMergeCellStyleIgnoreNewStyles = 0x8,
};

enum AcDb::TableHitItem
{
	kTableHitNone = 0,
	kTableHitCell = 0x1,
	kTableHitRowIndicator = 0x2,
	kTableHitColumnIndicator = 0x4,
	kTableHitGridLine = 0x8,
};

enum AcDb::RowTypes
{
	kAllRows = AcDb::RowType::kDataRow | AcDb::RowType::kTitleRow | AcDb::RowType::kHeaderRow
};

enum AcDb::FlowDirection
{
	kTtoB = 0,
	kBtoT = 1
};

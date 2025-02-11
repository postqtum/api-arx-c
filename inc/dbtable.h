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
***     Description: Declaration of AcDbTable class
***
*****************************************************************************/
#pragma once

#include "dbmain.h"
#include "dbents.h"
#include "AcField.h"
#include "DbLinkedTableData.h"
#include "DbFormattedTableData.h"

class AcDbTableIterator;
class AcDbTableTemplate;

using AcSubentPathArray = AcDbFullSubentPathArray;

#include "icarx/IcArxPackPush.h"

class AcDbTable : public AcDbBlockReference
{
public:
	enum TableStyleOverrides
	{
		kTitleSuppressed = 1,
		kHeaderSuppressed = 2,
		kFlowDirection = 3,
		kHorzCellMargin = 4,
		kVertCellMargin = 5,
		kTitleRowColor = 6,
		kHeaderRowColor = 7,
		kDataRowColor = 8,
		kTitleRowFillNone = 9,
		kHeaderRowFillNone = 10,
		kDataRowFillNone = 11,
		kTitleRowFillColor = 12,
		kHeaderRowFillColor = 13,
		kDataRowFillColor = 14,
		kTitleRowAlignment = 15,
		kHeaderRowAlignment = 16,
		kDataRowAlignment = 17,
		kTitleRowTextStyle = 18,
		kHeaderRowTextStyle = 19,
		kDataRowTextStyle = 20,
		kTitleRowTextHeight = 21,
		kHeaderRowTextHeight = 22,
		kDataRowTextHeight = 23,
		kTitleRowDataType = 24,
		kHeaderRowDataType = 25,
		kDataRowDataType = 26,
		kTitleHorzTopColor = 40,
		kTitleHorzInsideColor = 41,
		kTitleHorzBottomColor = 42,
		kTitleVertLeftColor = 43,
		kTitleVertInsideColor = 44,
		kTitleVertRightColor = 45,
		kHeaderHorzTopColor = 46,
		kHeaderHorzInsideColor = 47,
		kHeaderHorzBottomColor = 48,
		kHeaderVertLeftColor = 49,
		kHeaderVertInsideColor = 50,
		kHeaderVertRightColor = 51,
		kDataHorzTopColor = 52,
		kDataHorzInsideColor = 53,
		kDataHorzBottomColor = 54,
		kDataVertLeftColor = 55,
		kDataVertInsideColor = 56,
		kDataVertRightColor = 57,
		kTitleHorzTopLineWeight = 70,
		kTitleHorzInsideLineWeight = 71,
		kTitleHorzBottomLineWeight = 72,
		kTitleVertLeftLineWeight = 73,
		kTitleVertInsideLineWeight = 74,
		kTitleVertRightLineWeight = 75,
		kHeaderHorzTopLineWeight = 76,
		kHeaderHorzInsideLineWeight = 77,
		kHeaderHorzBottomLineWeight = 78,
		kHeaderVertLeftLineWeight = 79,
		kHeaderVertInsideLineWeight = 80,
		kHeaderVertRightLineWeight = 81,
		kDataHorzTopLineWeight = 82,
		kDataHorzInsideLineWeight = 83,
		kDataHorzBottomLineWeight = 84,
		kDataVertLeftLineWeight = 85,
		kDataVertInsideLineWeight = 86,
		kDataVertRightLineWeight = 87,
		kTitleHorzTopVisibility = 100,
		kTitleHorzInsideVisibility = 101,
		kTitleHorzBottomVisibility = 102,
		kTitleVertLeftVisibility = 103,
		kTitleVertInsideVisibility = 104,
		kTitleVertRightVisibility = 105,
		kHeaderHorzTopVisibility = 106,
		kHeaderHorzInsideVisibility = 107,
		kHeaderHorzBottomVisibility = 108,
		kHeaderVertLeftVisibility = 109,
		kHeaderVertInsideVisibility = 110,
		kHeaderVertRightVisibility = 111,
		kDataHorzTopVisibility = 112,
		kDataHorzInsideVisibility = 113,
		kDataHorzBottomVisibility = 114,
		kDataVertLeftVisibility = 115,
		kDataVertInsideVisibility = 116,
		kDataVertRightVisibility = 117,
		kCellAlignment = 130,
		kCellBackgroundFillNone = 131,
		kCellBackgroundColor = 132,
		kCellContentColor = 133,
		kCellTextStyle = 134,
		kCellTextHeight = 135,
		kCellTopGridColor = 136,
		kCellRightGridColor = 137,
		kCellBottomGridColor = 138,
		kCellLeftGridColor = 139,
		kCellTopGridLineWeight = 140,
		kCellRightGridLineWeight = 141,
		kCellBottomGridLineWeight = 142,
		kCellLeftGridLineWeight = 143,
		kCellTopVisibility = 144,
		kCellRightVisibility = 145,
		kCellBottomVisibility = 146,
		kCellLeftVisibility = 147,
		kCellDataType = 148,
	};

protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbTable);

	AcDbTable();
	AcDbTable(const AcDbLinkedTableData* pTable, AcDb::TableCopyOption nCopyOption);
	~AcDbTable();

	virtual AcDb::CellAlignment alignment(AcDb::RowType type = AcDb::kDataRow) const;
	virtual AcDb::CellAlignment alignment(int row, int col) const;
	virtual AcGePoint3d attachmentPoint(int row, int col) const;
	AcGePoint3d attachmentPoint(int row, int col, int content) const;
	Acad::ErrorStatus audit(AcDbAuditInfo* pAuditInfo) override;
	virtual AcCmColor backgroundColor(AcDb::RowType type = AcDb::kDataRow) const;
	virtual AcCmColor backgroundColor(int row, int col) const;
	virtual double blockRotation(int row, int col) const;
	virtual double blockScale(int row, int col) const;
	virtual AcDbObjectId blockTableRecordId(int row, int col) const;
	AcDbObjectId blockTableRecordId(int row, int col, int nContent) const;
	AcDb::TableBreakFlowDirection breakFlowDirection() const;
	double breakHeight(int nIndex) const;
	AcGeVector3d breakOffset(int nIndex) const;
	AcDb::TableBreakOption breakOption() const;
	double breakSpacing() const;
	bool canDelete(int nIndex, int nCount, bool bRow) const;
	bool canInsert(int nIndex, bool bRow) const;
	ACDBCORE2D_PORT AcCellRange cellRange() const;
	AcDb::CellState cellState(int nRow, int nCol) const;
	const ACHAR* cellStyle(int nRow, int nCol) const;
	virtual bool cellStyleOverrides(int row, int col, AcDbIntArray& overrides) const;
	virtual AcDb::CellType cellType(int row, int col) const;
	void clearCellOverrides(int row, int column);
	virtual void clearSubSelection();
	virtual void clearTableStyleOverrides(int options = 0);
	virtual double columnWidth(int col) const;
	virtual AcCmColor contentColor(AcDb::RowType type = AcDb::kDataRow) const;
	virtual AcCmColor contentColor(int row, int col) const;
	AcCmColor contentColor(int row, int col, int nContent) const;
	AcDb::CellContentLayout contentLayout(int row, int col) const;
	AcDb::CellContentType contentType(int nRow, int nCol) const;
	AcDb::CellContentType contentType(int nRow, int nCol, int nIndex) const;
	Acad::ErrorStatus copyFrom(const AcDbLinkedTableData* pSrc, AcDb::TableCopyOption nOption);
	Acad::ErrorStatus copyFrom(const AcDbLinkedTableData* pSrc, AcDb::TableCopyOption nOption,
							   const AcCellRange& srcRange, const AcCellRange& targetRange,
							   AcCellRange* pNewTargetRangeOut);
	Acad::ErrorStatus copyFrom(const AcDbTable* pSrc, AcDb::TableCopyOption nOption,
							   const AcCellRange& srcRange, const AcCellRange& targetRange,
							   AcCellRange* pNewTargetRangeOut);
	int createContent(int nRow, int nCol, int nIndex);
	Acad::ErrorStatus createTemplate(AcDbTableTemplate*& pTemplate,
									 AcDb::TableCopyOption nCopyOption);
	AcString dataFormat(int row, int col) const;
	AcString dataFormat(int row, int col, int nContent) const;
	virtual Acad::ErrorStatus deleteCellContent(int row, int col);
	virtual Acad::ErrorStatus deleteColumns(int col, int nCols = 1);
	Acad::ErrorStatus deleteContent(int nRow, int nCol);
	Acad::ErrorStatus deleteContent(int nRow, int nCol, int nIndex);
	Acad::ErrorStatus deleteContent(const AcCellRange& range);
	virtual Acad::ErrorStatus deleteRows(int row, int nRows = 1);
	virtual AcGeVector3d direction() const;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler*) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler*) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const override;
	Acad::ErrorStatus enableBreak(bool bEnable);
	Acad::ErrorStatus enableMergeAll(int nRow, int nCol, bool bEnable);
	void erased(const AcDbObject* dbObj, bool pErasing = true) override;
	virtual AcDbObjectId fieldId(int row, int col) const;
	AcDbObjectId fieldId(int row, int col, int nContent) const;
	Acad::ErrorStatus fill(const AcCellRange& fillRange, const AcCellRange& srcRange,
						   AcDb::TableFillOption nOption);
	virtual AcDb::FlowDirection flowDirection() const;
	virtual const ACHAR* format(AcDb::RowType type);
	const ACHAR* format(int row, int col) const;
	virtual Acad::ErrorStatus generateLayout();
	virtual Acad::ErrorStatus getBlockAttributeValue(int row, int col, const AcDbObjectId& attdefId,
													 ACHAR*& value) const;
	Acad::ErrorStatus getBlockAttributeValue(int row, int col, int nContent,
											 const AcDbObjectId& attdefId, ACHAR*& value) const;
	virtual Acad::ErrorStatus getCellExtents(int row, int col, bool isOuterCell,
											 AcGePoint3dArray& pts) const;
	virtual Acad::ErrorStatus getCellExtents(int row, int col, double& cellWidth,
											 double& cellHeight, bool bAdjustForMargins) const;
	const ACHAR* getColumnName(int nIndex) const;
	int getCustomData(int nRow, int nCol) const;
	Acad::ErrorStatus getCustomData(int nRow, int nCol, const ACHAR* pszKey, AcValue* pData) const;
	AcDbObjectId getDataLink(int nRow, int nCol) const;
	Acad::ErrorStatus getDataLink(int nRow, int nCol, AcDbDataLink*& pDataLink,
								  AcDb::OpenMode mode) const;
	int getDataLink(const AcCellRange* pRange, AcDbObjectIdArray& dataLinkIds) const;
	AcCellRange getDataLinkRange(int nRow, int nCol) const;
	virtual Acad::ErrorStatus getDataType(AcValue::DataType& nDataType,
										  AcValue::UnitType& nUnitType, AcDb::RowType type) const;
	Acad::ErrorStatus getDataType(int row, int col, AcValue::DataType& nDataType,
								  AcValue::UnitType& nUnitType) const;
	Acad::ErrorStatus getDataType(int row, int col, int nContent, AcValue::DataType& nDataType,
								  AcValue::UnitType& nUnitType) const;
	AcString getFormula(int nRow, int nCol, int nContent) const;
	Acad::ErrorStatus getGridProperty(int nRow, int nCol, AcDb::GridLineType nGridLineType,
									  AcGridProperty& gridProp) const;
	Acad::ErrorStatus getIndicatorSize(double& fWidth, double& fHeight) const;
	AcDbTableIterator* getIterator() const;
	AcDbTableIterator* getIterator(const AcCellRange* pRange,
								   AcDb::TableIteratorOption nOption) const;
	AcCellRange getMergeRange(int nRow, int nCol) const;
	AcDb::CellProperty getOverride(int nRow, int nCol, int nContent) const;
	AcDb::GridProperty getOverride(int nRow, int nCol, AcDb::GridLineType nGridLineType) const;
	virtual Acad::ErrorStatus getSubSelection(int& rowMin, int& rowMax, int& colMin,
											  int& colMax) const;
	AcCellRange getSubSelection() const;
	AcString getToolTip(int nRow, int nCol) const;
	virtual AcCmColor gridColor(AcDb::GridLineType gridlineType,
								AcDb::RowType type = AcDb::kDataRow) const;
	virtual AcCmColor gridColor(int row, int col, AcDb::CellEdgeMask iEdge) const;
	AcCmColor gridColor(int nRow, int nCol, AcDb::GridLineType nGridLineType) const;
	double gridDoubleLineSpacing(int nRow, int nCol, AcDb::GridLineType nGridLineType) const;
	AcDb::GridLineStyle gridLineStyle(int nRow, int nCol, AcDb::GridLineType nGridLineType) const;
	virtual AcDb::LineWeight gridLineWeight(AcDb::GridLineType gridlineType,
											AcDb::RowType type = AcDb::kDataRow) const;
	virtual AcDb::LineWeight gridLineWeight(int row, int col, AcDb::CellEdgeMask iEdge) const;
	AcDb::LineWeight gridLineWeight(int nRow, int nCol, AcDb::GridLineType nGridLineType) const;
	AcDbObjectId gridLinetype(int nRow, int nCol, AcDb::GridLineType nGridLineType) const;
	virtual AcDb::Visibility gridVisibility(AcDb::GridLineType gridlineType,
											AcDb::RowType type = AcDb::kDataRow) const;
	virtual Acad::ErrorStatus setGridVisibility(AcDb::Visibility visible, int nBorders, int nRows);
	virtual AcDb::Visibility gridVisibility(int row, int col, AcDb::CellEdgeMask iEdge) const;
	AcDb::Visibility gridVisibility(int nRow, int nCol, AcDb::GridLineType nGridLineType) const;
	bool hasFormula(int nRow, int nCol, int nContent) const;
	virtual bool hasSubSelection() const;
	virtual double height() const;
	virtual bool hitTest(const AcGePoint3d& wpt, const AcGeVector3d& wviewVec, double wxaper,
						 double wyaper, int& resultRowIndex, int& resultColumnIndex);
	bool hitTest(const AcGePoint3d& wpt, const AcGeVector3d& wviewVec, double wxaper, double wyaper,
				 int& resultRowIndex, int& resultColumnIndex, int& contentIndex,
				 AcDb::TableHitItem& nItem);
	virtual double horzCellMargin() const;
	virtual Acad::ErrorStatus insertColumns(int col, double width, int nCols = 1);
	Acad::ErrorStatus insertColumnsAndInherit(int col, int nInheritFrom, int nNumCols);
	virtual Acad::ErrorStatus insertRows(int row, double height, int nRows = 1);
	Acad::ErrorStatus insertRowsAndInherit(int nIndex, int nInheritFrom, int nNumRows);
	virtual bool isAutoScale(int row, int col) const;
	bool isAutoScale(int row, int col, int nContent) const;
	virtual bool isBackgroundColorNone(AcDb::RowType type = AcDb::kDataRow) const;
	virtual bool isBackgroundColorNone(int row, int col) const;
	bool isBreakEnabled() const;
	bool isContentEditable(int nRow, int nCol) const;
	bool isEmpty(int nRow, int nCol) const;
	bool isFormatEditable(int nRow, int nCol) const;
	virtual bool isHeaderSuppressed() const;
	bool isLinked(int nRow, int nCol) const;
	bool isMergeAllEnabled(int nRow, int nCol) const;
	virtual bool isMergedCell(int row, int col, int* minRow = nullptr, int* maxRow = nullptr,
							  int* minCol = nullptr, int* maxCol = nullptr) const;
	bool isRegenerateTableSuppressed() const;
	virtual bool isTitleSuppressed() const;
	double margin(int nRow, int nCol, AcDb::CellMargin nMargin) const;
	virtual Acad::ErrorStatus mergeCells(int minRow, int maxRow, int minCol, int maxCol);
	virtual double minimumColumnWidth(int col) const;
	virtual double minimumRowHeight(int row) const;
	virtual double minimumTableHeight() const;
	virtual double minimumTableWidth() const;
	Acad::ErrorStatus moveContent(int nRow, int nCol, int nFromIndex, int nToIndex);
	virtual uint32_t numColumns() const;
	int numContents(int nRow, int nCol) const;
	virtual uint32_t numRows() const;
	void objectClosed(const AcDbObjectId objId) override;
	virtual Acad::ErrorStatus recomputeTableBlock(bool forceUpdate = true);
	Acad::ErrorStatus removeAllOverrides(int nRow, int nCol);
	Acad::ErrorStatus removeDataLink(int nRow, int nCol);
	Acad::ErrorStatus removeDataLink();
	virtual bool reselectSubRegion(AcDbFullSubentPathArray& paths) const;
	Acad::ErrorStatus resetValue(int row, int col);
	double rotation() const;
	double rotation(int row, int col, int nContent) const;
	virtual double rowHeight(int row) const;
	virtual AcDb::RowType rowType(int row) const;
	double scale(int row, int col, int nContent) const;
	virtual Acad::ErrorStatus select(const AcGePoint3d& wpt, const AcGeVector3d& wvwVec,
									 const AcGeVector3d& wvwxVec, double wxaper, double wyaper,
									 bool allowOutside, bool bInPickFirst, int& resultRowIndex,
									 int& resultColumnIndex,
									 AcDbFullSubentPathArray* pPaths = nullptr) const;
	virtual Acad::ErrorStatus selectSubRegion(const AcGePoint3d& wpt1, const AcGePoint3d& wpt2,
											  const AcGeVector3d& wvwVec,
											  const AcGeVector3d& wvwxVec, double wxaper,
											  double wyaper, AcDb::SelectType seltype,
											  bool bIncludeCurrentSelection, bool bInPickFirst,
											  int& rowMin, int& rowMax, int& colMin, int& colMax,
											  AcDbFullSubentPathArray* pPaths = nullptr) const;
	virtual Acad::ErrorStatus select_next_cell(int dir, int& resultRowIndex, int& resultColumnIndex,
											   AcDbFullSubentPathArray* pPaths = nullptr,
											   bool bSupportTextCellOnly = true) const;
	virtual Acad::ErrorStatus setAlignment(AcDb::CellAlignment align,
										   int rowTypes = AcDb::kAllRows);
	virtual Acad::ErrorStatus setAlignment(int row, int col, AcDb::CellAlignment align);
	virtual Acad::ErrorStatus setAutoScale(int row, int col, bool autoFit);
	Acad::ErrorStatus setAutoScale(int row, int col, int nContent, bool autoFit);
	virtual Acad::ErrorStatus setBackgroundColor(const AcCmColor& color,
												 int rowTypes = AcDb::kAllRows);
	virtual Acad::ErrorStatus setBackgroundColor(int row, int col, const AcCmColor& color);
	virtual Acad::ErrorStatus setBackgroundColorNone(bool value, int rowTypes = AcDb::kAllRows);
	virtual Acad::ErrorStatus setBackgroundColorNone(int row, int col, bool value);
	virtual Acad::ErrorStatus setBlockAttributeValue(int row, int col, const AcDbObjectId& attdefId,
													 const ACHAR* value);
	Acad::ErrorStatus setBlockAttributeValue(int row, int col, int nContent,
											 const AcDbObjectId& attdefId, const ACHAR* value);
	virtual Acad::ErrorStatus setBlockRotation(int row, int col, double rotAng);
	virtual Acad::ErrorStatus setBlockScale(int row, int col, double scale);
	virtual Acad::ErrorStatus setBlockTableRecordId(int row, int col, const AcDbObjectId& blkId,
													bool autoFit = false);
	Acad::ErrorStatus setBlockTableRecordId(int row, int col, int nContent,
											const AcDbObjectId& blkId, bool autoFit);
	Acad::ErrorStatus setBreakFlowDirection(AcDb::TableBreakFlowDirection nDir);
	Acad::ErrorStatus setBreakHeight(int nIndex, double fHeight);
	Acad::ErrorStatus setBreakOffset(int nIndex, const AcGeVector3d& vec);
	Acad::ErrorStatus setBreakOption(AcDb::TableBreakOption nOption);
	Acad::ErrorStatus setBreakSpacing(double fSpacing);
	Acad::ErrorStatus setCellState(int nRow, int nCol, AcDb::CellState nLock);
	Acad::ErrorStatus setCellStyle(int nRow, int nCol, const ACHAR* pszCellStyle);
	virtual Acad::ErrorStatus setCellType(int row, int col, AcDb::CellType type);
	Acad::ErrorStatus setColumnName(int nIndex, const ACHAR* pszName);
	virtual Acad::ErrorStatus setColumnWidth(int col, double width);
	virtual Acad::ErrorStatus setColumnWidth(double width);
	virtual Acad::ErrorStatus setContentColor(const AcCmColor& color,
											  int nRowType = AcDb::kAllRows);
	virtual Acad::ErrorStatus setContentColor(int row, int col, const AcCmColor& color);
	Acad::ErrorStatus setContentColor(int row, int col, int nContent, const AcCmColor& color);
	Acad::ErrorStatus setContentLayout(int row, int col, AcDb::CellContentLayout nLayout);
	Acad::ErrorStatus setCustomData(int nRow, int nCol, int nData);
	Acad::ErrorStatus setCustomData(int nRow, int nCol, const ACHAR* pszKey, const AcValue* pData);
	Acad::ErrorStatus setDataFormat(int row, int col, const ACHAR* pszFormat);
	Acad::ErrorStatus setDataFormat(int row, int col, int nContent, const ACHAR* pszFormat);
	Acad::ErrorStatus setDataLink(int nRow, int nCol, const AcDbObjectId& idDataLink, bool bUpdate);
	Acad::ErrorStatus setDataLink(const AcCellRange& range, const AcDbObjectId& idDataLink,
								  bool bUpdate);
	virtual Acad::ErrorStatus setDataType(AcValue::DataType nDataType, AcValue::UnitType nUnitType);

	virtual Acad::ErrorStatus setDataType(AcValue::DataType nDataType, AcValue::UnitType nUnitType,
										  int nRowTypes);
	Acad::ErrorStatus setDataType(int row, int col, AcValue::DataType nDataType,
								  AcValue::UnitType nUnitType);
	Acad::ErrorStatus setDataType(int row, int col, int nContent, AcValue::DataType nDataType,
								  AcValue::UnitType nUnitType);
	virtual Acad::ErrorStatus setDirection(const AcGeVector3d& horzVec);
	virtual Acad::ErrorStatus setFieldId(int row, int col, const AcDbObjectId& fieldId);

	virtual Acad::ErrorStatus setFieldId(int row, int col, const AcDbObjectId& fieldId,
										 AcDb::CellOption nFlag);
	Acad::ErrorStatus setFieldId(int row, int col, int nContent, const AcDbObjectId& fieldId,
								 AcDb::CellOption nFlag);
	virtual Acad::ErrorStatus setFlowDirection(AcDb::FlowDirection flow);
	virtual Acad::ErrorStatus setFormat(const ACHAR* pszFormat);
	virtual Acad::ErrorStatus setFormat(const ACHAR* pszFormat, int nRowTypes);
	Acad::ErrorStatus setFormat(int row, int col, const ACHAR* pszFormat);
	Acad::ErrorStatus setFormula(int nRow, int nCol, int nContent, const ACHAR* pszFormula);
	virtual Acad::ErrorStatus setGridColor(const AcCmColor& color, int nBorders, int nRows);
	virtual Acad::ErrorStatus setGridColor(int row, int col, short nEdges, const AcCmColor& color);
	Acad::ErrorStatus setGridColor(int nRow, int nCol, AcDb::GridLineType nGridlineTypes,
								   const AcCmColor& color);
	Acad::ErrorStatus setGridDoubleLineSpacing(int nRow, int nCol,
											   AcDb::GridLineType nGridLineTypes, double fSpacing);
	Acad::ErrorStatus setGridLineStyle(int nRow, int nCol, AcDb::GridLineType nGridLineTypes,
									   AcDb::GridLineStyle nLineStyle);
	virtual Acad::ErrorStatus setGridLineWeight(AcDb::LineWeight lwt, int nBorders, int nRows);
	virtual Acad::ErrorStatus setGridLineWeight(int row, int col, short nEdges,
												AcDb::LineWeight value);
	Acad::ErrorStatus setGridLineWeight(int nRow, int nCol, AcDb::GridLineType nGridLineTypes,
										AcDb::LineWeight nLineWeight);
	Acad::ErrorStatus setGridLinetype(int nRow, int nCol, AcDb::GridLineType nGridLineTypes,
									  const AcDbObjectId& idLinetype);
	Acad::ErrorStatus setGridProperty(int nRow, int nCol, AcDb::GridLineType nGridLineTypes,
									  const AcGridProperty& gridProp);
	Acad::ErrorStatus setGridProperty(const AcCellRange& rangeIn, AcDb::GridLineType nGridLineTypes,
									  const AcGridProperty& gridProp);
	virtual Acad::ErrorStatus setGridVisibility(int row, int col, short nEdges,
												AcDb::Visibility value);
	Acad::ErrorStatus setGridVisibility(int nRow, int nCol, AcDb::GridLineType nGridLineTypes,
										AcDb::Visibility nVisibility);
	virtual Acad::ErrorStatus setHeight(double height);
	virtual Acad::ErrorStatus setHorzCellMargin(double gap);
	Acad::ErrorStatus setMargin(int nRow, int nCol, AcDb::CellMargin nMargins, double fMargin);
	Acad::ErrorStatus setNormal(const AcGeVector3d& newVal) override;
	virtual Acad::ErrorStatus setNumColumns(int nCols);
	virtual Acad::ErrorStatus setNumRows(int nRows);
	Acad::ErrorStatus setOverride(int nRow, int nCol, int nContent, AcDb::CellProperty nOverride);
	Acad::ErrorStatus setOverride(int nRow, int nCol, AcDb::GridLineType nGridLineType,
								  AcDb::GridProperty nOverride);
	Acad::ErrorStatus setPosition(const AcGePoint3d&) override;
	ACDBCORE2D_PORT void setRecomputeTableBlock(bool newVal);
	virtual void setRegen();
	Acad::ErrorStatus setRotation(double fAngle) override;
	Acad::ErrorStatus setRotation(int row, int col, int nContent, double fAngle);
	virtual Acad::ErrorStatus setRowHeight(int row, double height);
	virtual Acad::ErrorStatus setRowHeight(double height);
	Acad::ErrorStatus setScale(int row, int col, int nContent, double scale);
	Acad::ErrorStatus setSize(int nRows, int nCols);
	virtual Acad::ErrorStatus setSubSelection(int rowMin, int rowMax, int colMin, int colMax);
	Acad::ErrorStatus setSubSelection(const AcCellRange& range);
	virtual Acad::ErrorStatus setTableStyle(const AcDbObjectId& id);
	virtual Acad::ErrorStatus setTextHeight(double height, int rowTypes = AcDb::kAllRows);
	virtual Acad::ErrorStatus setTextHeight(int row, int col, double height);
	Acad::ErrorStatus setTextHeight(int row, int col, int nContent, double height);
	virtual Acad::ErrorStatus setTextRotation(int row, int col, AcDb::RotationAngle rot);
	virtual Acad::ErrorStatus setTextString(int row, int col, const ACHAR* text);
	Acad::ErrorStatus setTextString(int row, int col, int nContent, const ACHAR* text);
	virtual Acad::ErrorStatus setTextStyle(const AcDbObjectId& id, int rowTypes = AcDb::kAllRows);
	virtual Acad::ErrorStatus setTextStyle(int row, int col, const AcDbObjectId& id);
	Acad::ErrorStatus setTextStyle(int row, int col, int nContent, const AcDbObjectId& id);
	Acad::ErrorStatus setToolTip(int nRow, int nCol, const ACHAR* pszToolTip);
	Acad::ErrorStatus setValue(int row, int col, const AcValue& val);
	Acad::ErrorStatus setValue(int row, int col, const wchar_t* pszText,
							   AcValue::ParseOption nOption);
	Acad::ErrorStatus setValue(int row, int col, int nContent, const AcValue& val);
	Acad::ErrorStatus setValue(int row, int col, int nContent, const AcValue& val,
							   AcValue::ParseOption nOption);
	Acad::ErrorStatus setValue(int row, int col, int nContent, const wchar_t* pszText,
							   AcValue::ParseOption nOption);
	virtual Acad::ErrorStatus setVertCellMargin(double gap);
	virtual Acad::ErrorStatus setWidth(double width);
	Acad::ErrorStatus subClose() override;
	virtual Acad::ErrorStatus suppressHeaderRow(bool value);
	virtual void suppressInvisibleGrid(bool value);
	void suppressRegenerateTable(bool bSuppress);
	virtual Acad::ErrorStatus suppressTitleRow(bool value);
	virtual AcDbObjectId tableStyle() const;
	virtual bool tableStyleOverrides(AcDbIntArray& overrides) const;
	virtual double textHeight(AcDb::RowType type = AcDb::kDataRow) const;
	virtual double textHeight(int row, int col) const;
	double textHeight(int row, int col, int nContent) const;
	virtual AcDb::RotationAngle textRotation(int row, int col) const;
	virtual ACHAR* textString(int row, int col) const;
	virtual Acad::ErrorStatus textString(int row, int col, AcValue::FormatOption nOption,
										 AcString& sText) const;
	AcString textString(int row, int col, int nContent) const;
	Acad::ErrorStatus textString(int row, int col, int nContent, AcValue::FormatOption nOption,
								 AcString& sText) const;
	virtual const ACHAR* textStringConst(int row, int col) const;
	virtual AcDbObjectId textStyle(AcDb::RowType type = AcDb::kDataRow) const;
	virtual AcDbObjectId textStyle(int row, int col) const;
	AcDbObjectId textStyle(int row, int col, int nContent) const;
	virtual Acad::ErrorStatus unmergeCells(int minRow, int maxRow, int minCol, int maxCol);
	Acad::ErrorStatus updateDataLink(int nRow, int nCol, AcDb::UpdateDirection nDir,
									 AcDb::UpdateOption nOption);
	Acad::ErrorStatus updateDataLink(AcDb::UpdateDirection nDir, AcDb::UpdateOption nOption);
	AcValue value(int row, int col) const;
	AcValue value(int row, int col, int nContent) const;
	AcValue value(int row, int col, int nContent, AcValue::FormatOption nOption) const;
	virtual double vertCellMargin() const;
	virtual double width() const;
};

#include "icarx/IcArxPackPop.h"

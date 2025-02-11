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
***     Description: Declaration of AcDbTableStyle class
***
*****************************************************************************/
#pragma once

#include "dbmain.h"
#include "AdAChar.h"
#include "AcValue.h"
#include "AcString.h"
#include "DbFormattedTableData.h"
#include "AcDbCore2dDefs.h"

class AcDbTableTemplate;

#include "icarx/IcArxPackPush.h"

class AcDbTableStyle : public AcDbObject
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbTableStyle);

	AcDbTableStyle();
	~AcDbTableStyle();

	virtual AcDb::CellAlignment alignment(AcDb::RowType rowType = AcDb::kDataRow) const;
	AcDb::CellAlignment alignment(const ACHAR* pszCellStyle) const;
	Acad::ErrorStatus audit(AcDbAuditInfo* pAuditInfo) override;
	virtual AcCmColor backgroundColor(AcDb::RowType rowType = AcDb::kDataRow) const;
	AcCmColor backgroundColor(const ACHAR* pszCellStyle) const;
	virtual uint32_t bitFlags() const;
	int cellClass(const ACHAR* pszCellStyle) const;
	virtual AcCmColor color(AcDb::RowType rowType = AcDb::kDataRow) const;
	AcCmColor color(const ACHAR* pszCellStyle) const;
	Acad::ErrorStatus copyCellStyle(const ACHAR* pszSrcCellStyle, const ACHAR* pszTargetCellStyle);
	Acad::ErrorStatus copyCellStyle(const AcDbTableStyle* pSrc, const ACHAR* pszSrcCellStyle,
									const ACHAR* pszTargetCellStyle);
	const ACHAR* createCellStyle();
	Acad::ErrorStatus createCellStyle(const ACHAR* pszCellStyle);
	Acad::ErrorStatus createCellStyle(const ACHAR* pszCellStyle, const ACHAR* pszFromCellStyle);
	Acad::ErrorStatus deleteCellStyle(const ACHAR* pszCellStyle);
	virtual const ACHAR* description() const;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	Acad::ErrorStatus enableMergeAll(bool bEnable, const ACHAR* pszCellStyle);
	virtual AcDb::FlowDirection flowDirection() const;
	virtual const ACHAR* format() const;
	virtual const ACHAR* format(AcDb::RowType rowType) const;
	const ACHAR* format(const ACHAR* pszCellStyle) const;
	int getCellStyles(AcStringArray& cellstyles) const;
	virtual Acad::ErrorStatus getDataType(AcValue::DataType& nDataType,
										  AcValue::UnitType& nUnitType) const;
	virtual Acad::ErrorStatus getDataType(AcValue::DataType& nDataType,
										  AcValue::UnitType& nUnitType,
										  AcDb::RowType rowType) const;
	Acad::ErrorStatus getDataType(AcValue::DataType& nDataType, AcValue::UnitType& nUnitType,
								  const ACHAR* pszCellStyle) const;
	Acad::ErrorStatus getGridProperty(AcGridProperty& gridProp, AcDb::GridLineType nGridLineTypes,
									  const ACHAR* pszCellStyle) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getName(AcString& sName) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getName(ACHAR*& pszName) const final;
	AcDbObjectId getTemplate() const;
	Acad::ErrorStatus getTemplate(AcDbTableTemplate*& pTemplate, AcDb::OpenMode mode);
	Acad::ErrorStatus getUniqueCellStyleName(const ACHAR* pszBaseName, AcString& sUniqueName) const;
	virtual AcCmColor gridColor(AcDb::GridLineType gridLineType,
								AcDb::RowType rowType = AcDb::kDataRow) const;
	AcCmColor gridColor(AcDb::GridLineType gridLineType, const ACHAR* pszCellStyle) const;
	double gridDoubleLineSpacing(AcDb::GridLineType gridLineType, const ACHAR* pszCellStyle) const;
	AcDb::GridLineStyle gridLineStyle(AcDb::GridLineType gridLineType,
									  const ACHAR* pszCellStyle) const;
	virtual AcDb::LineWeight gridLineWeight(AcDb::GridLineType gridLineType,
											AcDb::RowType rowType = AcDb::kDataRow) const;
	AcDb::LineWeight gridLineWeight(AcDb::GridLineType gridLineType,
									const ACHAR* pszCellStyle) const;
	AcDbObjectId gridLinetype(AcDb::GridLineType gridLineType, const ACHAR* pszCellStyle) const;
	virtual AcDb::Visibility gridVisibility(AcDb::GridLineType gridLineType,
											AcDb::RowType rowType = AcDb::kDataRow) const;
	AcDb::Visibility gridVisibility(AcDb::GridLineType gridLineType,
									const ACHAR* pszCellStyle) const;
	virtual double horzCellMargin() const;
	virtual bool isBackgroundColorNone(AcDb::RowType rowType = AcDb::kDataRow) const;
	bool isCellStyleInUse(const ACHAR* pszCellStyle) const;
	virtual bool isHeaderSuppressed() const;
	bool isMergeAllEnabled(const ACHAR* pszCellStyle) const;
	bool isRenamable() const;
	virtual bool isTitleSuppressed() const;
	double margin(AcDb::CellMargin nMargin, const ACHAR* pszCellStyle) const;
	int numCellStyles() const;
	virtual Acad::ErrorStatus postTableStyleToDb(AcDbDatabase* pDb, const ACHAR* styleName,
												 AcDbObjectId& tableStyleId);
	AcDbObjectId removeTemplate();
	Acad::ErrorStatus renameCellStyle(const ACHAR* pszOldName, const ACHAR* pszNewName);
	double rotation(const ACHAR* pszCellStyle) const;
	virtual Acad::ErrorStatus setAlignment(AcDb::CellAlignment alignment,
										   int rowTypes = AcDb::kAllRows);
	Acad::ErrorStatus setAlignment(AcDb::CellAlignment alignment, const ACHAR* pszCellStyle);
	virtual Acad::ErrorStatus setBackgroundColor(const AcCmColor& color,
												 int rowTypes = AcDb::kAllRows);
	Acad::ErrorStatus setBackgroundColor(const AcCmColor& color, const ACHAR* pszCellStyle);
	virtual Acad::ErrorStatus setBackgroundColorNone(bool bValue, int rowTypes = AcDb::kAllRows);
	virtual Acad::ErrorStatus setBitFlags(uint32_t flags);
	Acad::ErrorStatus setCellClass(int nClass, const ACHAR* pszCellStyle);
	virtual Acad::ErrorStatus setColor(const AcCmColor& color, int rowTypes = AcDb::kAllRows);
	Acad::ErrorStatus setColor(const AcCmColor& color, const ACHAR* pszCellStyle);
	virtual Acad::ErrorStatus setDataType(AcValue::DataType nDataType, AcValue::UnitType nUnitType);
	virtual Acad::ErrorStatus setDataType(AcValue::DataType nDataType, AcValue::UnitType nUnitType,
										  int rowTypes);
	Acad::ErrorStatus setDataType(AcValue::DataType nDataType, AcValue::UnitType nUnitType,
								  const ACHAR* pszCellStyle);
	virtual Acad::ErrorStatus setDescription(const ACHAR* pszDescription);
	virtual Acad::ErrorStatus setFlowDirection(AcDb::FlowDirection flow);
	virtual Acad::ErrorStatus setFormat(const ACHAR* pszFormat);
	virtual Acad::ErrorStatus setFormat(const ACHAR* pszFormat, int rowTypes);
	Acad::ErrorStatus setFormat(const ACHAR* pszFormat, const ACHAR* pszCellStyle);
	virtual Acad::ErrorStatus setGridColor(const AcCmColor color,
										   int gridLineTypes = AcDb::kAllGridLines,
										   int rowTypes = AcDb::kAllRows);
	Acad::ErrorStatus setGridColor(const AcCmColor color, AcDb::GridLineType gridLineTypes,
								   const ACHAR* pszCellStyle);
	Acad::ErrorStatus setGridDoubleLineSpacing(double fSpacing, AcDb::GridLineType gridLineTypes,
											   const ACHAR* pszCellStyle);
	Acad::ErrorStatus setGridLineStyle(AcDb::GridLineStyle nLineStyle,
									   AcDb::GridLineType gridLineTypes, const ACHAR* pszCellStyle);
	virtual Acad::ErrorStatus setGridLineWeight(AcDb::LineWeight lineWeight,
												int gridLineTypes = AcDb::kAllGridLines,
												int rowTypes = AcDb::kAllRows);
	Acad::ErrorStatus setGridLineWeight(AcDb::LineWeight lineWeight,
										AcDb::GridLineType gridLineTypes,
										const ACHAR* pszCellStyle);
	Acad::ErrorStatus setGridLinetype(const AcDbObjectId& id, AcDb::GridLineType gridLineTypes,
									  const ACHAR* pszCellStyle);
	Acad::ErrorStatus setGridProperty(const AcGridProperty& gridProp,
									  AcDb::GridLineType nGridLineTypes, const ACHAR* pszCellStyle);
	virtual Acad::ErrorStatus setGridVisibility(AcDb::Visibility visible,
												int gridLineTypes = AcDb::kAllGridLines,
												int rowTypes = AcDb::kAllRows);
	Acad::ErrorStatus setGridVisibility(AcDb::Visibility visible, AcDb::GridLineType gridLineTypes,
										const ACHAR* pszCellStyle);
	virtual Acad::ErrorStatus setHorzCellMargin(double dCellMargin);
	Acad::ErrorStatus setMargin(AcDb::CellMargin nMargins, double fMargin,
								const ACHAR* pszCellStyle);
	virtual Acad::ErrorStatus setName(const ACHAR* pszName);
	Acad::ErrorStatus setRotation(double fRotation, const ACHAR* pszCellStyle);
	Acad::ErrorStatus setTemplate(const AcDbObjectId& templateId,
								  AcDb::MergeCellStyleOption nOption);
	Acad::ErrorStatus setTemplate(AcDbTableTemplate* pTemplate, AcDb::MergeCellStyleOption nOption,
								  AcDbObjectId& templateId);
	virtual Acad::ErrorStatus setTextHeight(double dHeight, int rowTypes = AcDb::kAllRows);
	Acad::ErrorStatus setTextHeight(double dHeight, const ACHAR* pszCellStyle);
	virtual Acad::ErrorStatus setTextStyle(const AcDbObjectId id, int rowTypes = AcDb::kAllRows);
	Acad::ErrorStatus setTextStyle(const AcDbObjectId& id, const ACHAR* pszCellStyle);
	virtual Acad::ErrorStatus setVertCellMargin(double dCellMargin);
	virtual Acad::ErrorStatus suppressHeaderRow(bool bValue);
	virtual Acad::ErrorStatus suppressTitleRow(bool bValue);
	virtual double textHeight(AcDb::RowType rowType = AcDb::kDataRow) const;
	double textHeight(const ACHAR* pszCellStyle) const;
	virtual AcDbObjectId textStyle(AcDb::RowType rowType = AcDb::kDataRow) const;
	AcDbObjectId textStyle(const ACHAR* pszCellStyle) const;
	virtual double vertCellMargin() const;
};

#include "icarx/IcArxPackPop.h"

inline Acad::ErrorStatus AcDbTableStyle::getName(ACHAR*& pName) const
{
	return ::acutGetAcStringConvertToAChar(this, &AcDbTableStyle::getName, pName);
}

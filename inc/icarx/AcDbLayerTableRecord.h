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
***     Description: Declaration of AcDbLayerTableRecord class
***
*****************************************************************************/
#pragma once

#include "acut_str_util.h"
#include "AcDbSymbolTableRecord.h"
#include "AcDbEnumCode.h"
#include "AcCmColor.h"

class AcDbLayerTable;

#include "IcArxPackPush.h"

class AcDbLayerTableRecord : public AcDbSymbolTableRecord
{
public:
	using TableType = AcDbLayerTable;

	enum
	{
		kDxfLayerPlotBit = AcDb::kDxfBool
	};

protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbLayerTableRecord);

	AcDbLayerTableRecord();
	~AcDbLayerTableRecord();

	bool VPDFLT() const;
	AcCmColor color() const;
	AcCmColor color(const AcDbObjectId& viewportId, bool& isOverride) const;
	ACHAR* description() const;
	ACDBCORE2D_PORT Acad::ErrorStatus description(AcString&) const;
	AcGiDrawable* drawable() override;
	AcCmEntityColor entityColor(void) const;
	bool hasAnyOverrides() const;

	bool hasOverrides(const AcDbObjectId& viewportId) const;
	bool isFrozen() const;
	bool isHidden() const;
	static bool isHidden(AcDbObjectId);
	bool isInUse() const;
	bool isLocked() const;
	bool isOff() const;
	bool isPlottable() const;
	bool isReconciled() const;
	static bool isReconciled(const AcDbObjectId& id);
	AcDb::LineWeight lineWeight(const AcDbObjectId& viewportId, bool& isOverride) const;
	AcDb::LineWeight lineWeight() const;
	AcDbObjectId linetypeObjectId() const;
	AcDbObjectId linetypeObjectId(const AcDbObjectId& viewportId, bool& isOverride) const;
	AcDbObjectId materialId() const;
	ACHAR* plotStyleName() const;
	ACDBCORE2D_PORT Acad::ErrorStatus plotStyleName(AcString&) const;
	ACDBCORE2D_PORT Acad::ErrorStatus plotStyleName(const AcDbObjectId& viewportId, AcString& sName,
													bool& isOverride) const;
	ACHAR* plotStyleName(const AcDbObjectId& viewportId, bool& isOverride) const;
	AcDbObjectId plotStyleNameId() const;
	AcDbObjectId plotStyleNameId(const AcDbObjectId& viewportId, bool& isOverride) const;
	Acad::ErrorStatus removeAllOverrides();
	Acad::ErrorStatus removeColorOverride(const AcDbObjectId& viewportId);
	Acad::ErrorStatus removeLineWeightOverride(const AcDbObjectId& viewportId);
	Acad::ErrorStatus removeLinetypeOverride(const AcDbObjectId& viewportId);
	Acad::ErrorStatus removePlotStyleOverride(const AcDbObjectId& viewportId);
	Acad::ErrorStatus removeTransparencyOverride(const AcDbObjectId& viewportId);
	Acad::ErrorStatus removeViewportOverrides(const AcDbObjectId& viewportId);
	void setColor(const AcCmColor& color);
	Acad::ErrorStatus setColor(const AcCmColor& color, const AcDbObjectId& viewportId);
	Acad::ErrorStatus setDescription(const ACHAR* description);
	Acad::ErrorStatus setIsFrozen(bool frozen);
	Acad::ErrorStatus setIsHidden(bool on);
	void setIsLocked(bool locked);
	void setIsOff(bool off);
	Acad::ErrorStatus setIsPlottable(bool plot);
	Acad::ErrorStatus setIsReconciled(bool bReconcile = true);
	Acad::ErrorStatus setLineWeight(AcDb::LineWeight weight);
	Acad::ErrorStatus setLineWeight(AcDb::LineWeight weight, const AcDbObjectId& viewportId);
	ACDBCORE2D_PORT Acad::ErrorStatus setLinetypeObjectId(AcDbObjectId id);
	Acad::ErrorStatus setLinetypeObjectId(const AcDbObjectId& id, const AcDbObjectId& viewportId);
	Acad::ErrorStatus setMaterialId(AcDbObjectId id);
	Acad::ErrorStatus setPlotStyleName(const ACHAR* newName);
	Acad::ErrorStatus setPlotStyleName(const AcDbObjectId& newId);
	Acad::ErrorStatus setPlotStyleName(const ACHAR* newName, const AcDbObjectId& viewportId);
	Acad::ErrorStatus setPlotStyleName(const AcDbObjectId& newId, const AcDbObjectId& viewportId);
	Acad::ErrorStatus setTransparency(const AcCmTransparency& trans);
	Acad::ErrorStatus setTransparency(const AcCmTransparency& trans,
									  const AcDbObjectId& viewportId);
	void setVPDFLT(bool frozen);
	AcCmTransparency transparency(void) const;
	AcCmTransparency transparency(const AcDbObjectId& viewportId, bool& isOvr) const;
};

#include "IcArxPackPop.h"

inline ACHAR* AcDbLayerTableRecord::description() const
{
	AcString sDescription;
	return ::acutAcStringToAChar(sDescription, this->description(sDescription));
}
inline ACHAR* AcDbLayerTableRecord::plotStyleName() const
{
	AcString sName;
	return ::acutAcStringToAChar(sName, this->plotStyleName(sName));
}
inline ACHAR* AcDbLayerTableRecord::plotStyleName(const AcDbObjectId& viewportId,
												  bool& isOverride) const
{
	AcString sName;
	return ::acutAcStringToAChar(sName, this->plotStyleName(viewportId, sName, isOverride));
}

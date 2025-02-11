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
***     Description: Declaration of AcDbViewTableRecord class
***
*****************************************************************************/
#pragma once

#include "acut_str_util.h"
#include "AcDbAbstractViewTableRecord.h"
#include "../AcString.h"

#include "AcDbDatabase.h"

class AcDbViewTable;

#include "IcArxPackPush.h"

typedef struct tagBITMAPINFO BITMAPINFO;

class AcDbViewTableRecord : public AcDbAbstractViewTableRecord
{
public:
	using TableType = AcDbViewTable;

protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbViewTableRecord);

	AcDbViewTableRecord();
	~AcDbViewTableRecord();

	AcDbAnnotationScale* annotationScale() const;
	AcDbObjectId camera() const;
	Acad::ErrorStatus disassociateUcsFromView();
	ACDBCORE2D_PORT Acad::ErrorStatus getCategoryName(AcString& sCategoryName) const;
	Acad::ErrorStatus getCategoryName(ACHAR*& categoryName) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getLayerState(AcString& layerStateName) const;
	Acad::ErrorStatus getLayerState(ACHAR*& layerStateName) const;
	Acad::ErrorStatus getLayout(AcDbObjectId& layoutId) const;
	Acad::ErrorStatus getPreviewImage(Atil::Image*& pPreviewImage) const;
	Acad::ErrorStatus getThumbnail(BITMAPINFO*& thumbnail) const;
	bool isCameraPlottable() const;
	bool isPaperspaceView() const;
	bool isUcsAssociatedToView() const;
	bool isViewAssociatedToViewport() const;
	AcDbObjectId liveSection() const;
	Acad::ErrorStatus setAnnotationScale(const AcDbAnnotationScale* pScaleObj);
	Acad::ErrorStatus setCamera(AcDbObjectId cameraId);
	Acad::ErrorStatus setCategoryName(const ACHAR* categoryName);
	Acad::ErrorStatus setIsCameraPlottable(bool plottable);
	void setIsPaperspaceView(bool pspace);
	Acad::ErrorStatus setLayerState(const ACHAR* layerStateName);
	Acad::ErrorStatus setLayout(AcDbObjectId layoutId);
	Acad::ErrorStatus setLiveSection(const AcDbObjectId& liveSectionId);
	Acad::ErrorStatus setParametersFromViewport(AcDbObjectId objId);
	Acad::ErrorStatus setPreviewImage(const Atil::Image* pPreviewImage);
	Acad::ErrorStatus setSun(AcDbObjectId& retId, AcDbObject* pSun);
	Acad::ErrorStatus setSun(AcDbObjectId& retId, AcDbObject* pSun, bool eraseOldSun);
	Acad::ErrorStatus setThumbnail(const BITMAPINFO* thumbnail);
	Acad::ErrorStatus setViewAssociatedToViewport(bool bVPflag);
	AcDbObjectId sunId() const;
};

#include "IcArxPackPop.h"

inline Acad::ErrorStatus AcDbViewTableRecord::getCategoryName(ACHAR*& pCategoryName) const
{
	return ::acutGetAcStringConvertToAChar(this, &AcDbViewTableRecord::getCategoryName,
										   pCategoryName);
}
inline Acad::ErrorStatus AcDbViewTableRecord::getLayerState(ACHAR*& pLayerStateName) const
{
	return ::acutGetAcStringConvertToAChar(this, &AcDbViewTableRecord::getLayerState,
										   pLayerStateName);
}

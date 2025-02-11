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
***     Description: Declaration of AcDbLayout class
***
*****************************************************************************/
#pragma once

#include "dbmain.h"
#include "dbdict.h"
#include "AdAChar.h"
#include "dbPlotSettings.h"

namespace Atil
{
class Image;
}

typedef struct tagBITMAPINFO BITMAPINFO;

#include "icarx/IcArxPackPush.h"

class AcDbLayout : public AcDbPlotSettings
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbLayout);

	AcDbLayout();
	~AcDbLayout();

	virtual Acad::ErrorStatus addToLayoutDict(AcDbDatabase* towhichDb,
											  AcDbObjectId BlockTableRecordId);
	bool annoAllVisible() const;
	AcDbObjectId getBlockTableRecordId() const;
	void getExtents(AcGePoint3d& extMin, AcGePoint3d& extMax) const;
	ACDBCORE2D_PORT void getExtents(AcDbExtents& extent) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getLayoutName(const ACHAR*& layoutName) const;
	Acad::ErrorStatus getLayoutName(ACHAR*& layoutName) const;
	void getLimits(AcGePoint2d& limMin, AcGePoint2d& limMax) const;
	ACDBCORE2D_PORT void getLimits(AcDbExtents2d& extent) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getName(AcString& sName) const;
	Acad::ErrorStatus getPreviewImage(Atil::Image*& pPreviewImage) const;
	int getTabOrder() const;
	bool getTabSelected() const;
	Acad::ErrorStatus getThumbnail(BITMAPINFO*& thumbnail) const;
	AcDbObjectIdArray getViewportArray() const;
	Acad::ErrorStatus initialize(AcDbObjectId* paperVportId = nullptr);
	Acad::ErrorStatus setAnnoAllVisible(bool newVal);
	virtual Acad::ErrorStatus setBlockTableRecordId(AcDbObjectId BlockTableRecordId);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setLayoutName(const ACHAR* layoutName);
	Acad::ErrorStatus setPreviewImage(const Atil::Image* pPreviewImage);
	virtual void setTabOrder(int newOrder);
	virtual void setTabSelected(bool tabSelected);
	Acad::ErrorStatus setThumbnail(const BITMAPINFO* thumbnail);
};

#include "icarx/IcArxPackPop.h"

inline Acad::ErrorStatus AcDbLayout::getLayoutName(ACHAR*& layoutName) const
{
	return ::acutGetAcStringConvertToAChar(this, &AcDbLayout::getName, layoutName);
}

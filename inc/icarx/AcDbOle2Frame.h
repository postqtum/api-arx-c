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
***     Description: Declaration of AcDbOle2Frame class
***
*****************************************************************************/
#pragma once

#include "AcDbOleFrame.h"
#include "CRectangle3d.h"

class COleClientItem;

#include "IcArxPackPush.h"

class AcDbOle2Frame : public AcDbOleFrame
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbOle2Frame);

	AcDbOle2Frame();
	~AcDbOle2Frame();

	bool autoOutputQuality() const;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* filer) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* filer) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* filer) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* filer) const override;
	virtual bool getLinkName(ACHAR* pszName, int nNameSize) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getLinkName(AcString&) const;
	virtual bool getLinkPath(ACHAR* pszPath, int nPathSize) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getLinkPath(AcString&) const;
	virtual void getLocation(AcGePoint3d& point3d) const;
	COleClientItem* getOleClientItem(void) const;
	void* getOleItemHost() const;
	void* getOleObject(void) const override;
	virtual int getType(void) const;
	virtual void getUserType(ACHAR* pszName, int nNameSize) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getUserType(AcString&) const;
	ACDBCORE2D_PORT bool isLinked() const;
	bool lockAspect() const;
	virtual uint8_t outputQuality() const;
	virtual void position(CRectangle3d& rect3d) const;
	virtual void position(RECT& rect) const;
	double rotation() const;
	void saveAs(AcGiWorldDraw* mode, AcDb::SaveType st) override;
	double scaleHeight() const;
	double scaleWidth() const;
	void setAutoOutputQuality(uint8_t);
	void setLocation(const AcGePoint3d& point3d);
	Acad::ErrorStatus setLockAspect(const bool bLockAspect);
	Acad::ErrorStatus setOleClientItem(const COleClientItem* pItem);
	void setOleObject(const void* pItem) override;
	virtual void setOutputQuality(uint8_t);
	virtual void setPosition(const CRectangle3d& rect3d);
	virtual void setPosition(const RECT& rect);
	Acad::ErrorStatus setRotation(const double rotation);
	Acad::ErrorStatus setScaleHeight(const double scaleHeight);
	Acad::ErrorStatus setScaleWidth(const double scaleWidth);
	Acad::ErrorStatus setWcsHeight(const double wcsHeight);
	Acad::ErrorStatus setWcsWidth(const double wcsWidth);
	double wcsHeight() const;
	double wcsWidth() const;
};

#include "IcArxPackPop.h"

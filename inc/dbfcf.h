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
***     Description: Declaration of AcDbFcf class
***
*****************************************************************************/
#pragma once

#include "dbmain.h"
#include "AcDbCore2dDefs.h"

#include "icarx/IcArxPackPush.h"

class AcDbFcf : public AcDbEntity
{
public:
	enum whichLine
	{
		kAll = -1
	};

protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbFcf);

	AcDbFcf();
	AcDbFcf(const ACHAR*, const AcGePoint3d&, const AcGeVector3d&, const AcGeVector3d&);
	~AcDbFcf();

	AcCmColor dimclrd() const;
	AcCmColor dimclrt() const;
	virtual AcDbHardPointerId dimensionStyle() const;
	double dimgap() const;
	double dimscale() const;
	AcDbObjectId dimtxsty() const;
	double dimtxt() const;
	virtual AcGeVector3d direction() const;
	virtual void getBoundingPline(AcGePoint3dArray&) const;
	virtual void getBoundingPoints(AcGePoint3dArray&) const;
	Acad::ErrorStatus getDimstyleData(AcDbDimStyleTableRecord*& pRecord) const;
	virtual AcGePoint3d location() const;
	virtual AcGeVector3d normal() const;
	virtual void setDimVars();
	Acad::ErrorStatus setDimclrd(AcCmColor& val);
	Acad::ErrorStatus setDimclrt(AcCmColor& val);
	virtual void setDimensionStyle(AcDbHardPointerId);
	Acad::ErrorStatus setDimgap(double val);
	Acad::ErrorStatus setDimscale(double val);
	Acad::ErrorStatus setDimstyleData(AcDbDimStyleTableRecord* pNewData);
	Acad::ErrorStatus setDimstyleData(AcDbObjectId newDataId);
	Acad::ErrorStatus setDimtxsty(AcDbObjectId val);
	Acad::ErrorStatus setDimtxt(double val);
	virtual void setLocation(const AcGePoint3d&);
	virtual void setOrientation(const AcGeVector3d& norm, const AcGeVector3d& dir);
	virtual void setText(const ACHAR*);
	virtual ACHAR* text(int lineNo = kAll) const final;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus text(AcString& sText, int lineNo = kAll) const;
};

#include "icarx/IcArxPackPop.h"

inline ACHAR* AcDbFcf::text(int lineNo) const
{
	AcString sText;
	if (this->text(sText, lineNo) == Acad::eOutOfRange)
		return nullptr;
	ACHAR* pRet = nullptr;
	::acutNewString(sText.kwszPtr(), pRet);
	return pRet;
}

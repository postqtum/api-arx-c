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
***     Description: Declaration of AcDbMline class
***
*****************************************************************************/
#pragma once

#include "gevptar.h"
#include "dbmain.h"

#include "icarx/IcArxPackPush.h"

#ifndef OD_DBMLINE_H
struct Mline
{
	typedef int8_t MlineJustification;
	enum
	{
		kTop = 0,
		kZero = 1,
		kBottom = 2
	};
	enum
	{
		kOpen = 0,
		kClosed = 1,
		kMerged = 2
	};
};
#endif

class AcGePlane;

class AcDbMline : public AcDbEntity
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbMline);

	AcDbMline();
	~AcDbMline();

	Acad::ErrorStatus appendSeg(const AcGePoint3d& newVertex);
	AcGeVector3d axisAt(int index) const;
	bool closedMline() const;
	int element(const AcGePoint3d& pt) const;
	Acad::ErrorStatus getClosestPointTo(const AcGePoint3d& givenPoint, AcGePoint3d& pointOnCurve,
										bool extend, bool excludeCaps = false) const;
	Acad::ErrorStatus getClosestPointTo(const AcGePoint3d& givenPoint, const AcGeVector3d& normal,
										AcGePoint3d& pointOnCurve, bool extend,
										bool excludeCaps = false) const;
	Acad::ErrorStatus getParametersAt(int index, AcGeVoidPointerArray& params) const;
	void getPlane(AcGePlane&) const;
	Mline::MlineJustification justification() const;
	AcGeVector3d miterAt(int index) const;
	Acad::ErrorStatus moveVertexAt(int index, const AcGePoint3d& newPosition);
	AcGeVector3d normal() const;
	int numVertices() const;
	Acad::ErrorStatus removeLastSeg(AcGePoint3d& lastVertex);
	double scale() const;
	Acad::ErrorStatus setClosedMline(bool closed);
	Acad::ErrorStatus setJustification(Mline::MlineJustification newJust);
	Acad::ErrorStatus setNormal(const AcGeVector3d& newNormal);
	Acad::ErrorStatus setParametersAt(int index, AcGeVoidPointerArray& params);
	Acad::ErrorStatus setScale(double newScale);
	Acad::ErrorStatus setStyle(const AcDbObjectId& newStyleId);
	void setSupressEndCaps(bool supressIt);
	void setSupressStartCaps(bool supressIt);
	AcDbObjectId style() const;
	bool supressEndCaps() const;
	bool supressStartCaps() const;
	AcGePoint3d vertexAt(int index) const;
};

#include "icarx/IcArxPackPop.h"

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
***     Description: Declaration of AcDbSectionSymbol class
***
*****************************************************************************/
#pragma once

#include "gevc3dar.h"
#include "dbViewSymbol.h"

#include "icarx/IcArxPackPush.h"

#ifndef ACSYNERGY_PORT
#	define ACSYNERGY_PORT
#endif

class ACSYNERGY_PORT AcDbSectionSymbol : public AcDbViewSymbol
{
public:
	ACRX_DECLARE_MEMBERS(AcDbSectionSymbol);

	AcDbSectionSymbol();

	Acad::ErrorStatus addSectionPoint(const AcGePoint3d& pt, double bulge = 0);
	void clearSectionPoints();
	bool flipDirection();
	Acad::ErrorStatus getBulgeAt(int idx, double& bulge) const;
	Acad::ErrorStatus getLabelNameAt(int idx, AcString& sName) const;
	Acad::ErrorStatus getLabelOffsetAt(int idx, AcGeVector3d& offset) const;
	void getLabelOffsets(AcGeVector3dArray& offsets) const;
	Acad::ErrorStatus getSectionPointAt(int idx, AcGePoint3d& pt) const;
	void getSectionPoints(AcGePoint3dArray& pts) const;
	bool isHalfSection() const;
	bool isViewDirectionLeft() const;
	Acad::ErrorStatus removeSectionPointAt(int idx);
	void resetLabelOffsets(bool allOffsets = true);
	int sectionPointsCount() const;
	void setIsHalfSection(bool bHalfSection);
	Acad::ErrorStatus setLabelNameAt(int idx, const ACHAR* pName);
	Acad::ErrorStatus setLabelNames(const AcArray<AcString>& names);
	Acad::ErrorStatus setLabelOffsetAt(int idx, const AcGeVector3d& offset);
	Acad::ErrorStatus setLabelOffsets(const AcGeVector3dArray& offsets);
	Acad::ErrorStatus setSectionPointAt(int idx, const AcGePoint3d& pt, double bulge = 0);
	Acad::ErrorStatus setSectionPoints(const AcGePoint3dArray& pts);
	Acad::ErrorStatus setSectionPoints(const AcGePoint3dArray& pts, const AcGeDoubleArray& bulges);
	void setViewDirectionLeft(bool bLeft);
};

#include "icarx/IcArxPackPop.h"

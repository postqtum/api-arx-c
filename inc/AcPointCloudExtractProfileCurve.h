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
***     Description:
***
*****************************************************************************/
#pragma once

#include "icarx/IcArxPackPush.h"

class ACDB_PORT ProfileCurve2d
{
public:
	enum ProfileurveType
	{
		kLineSeg = 0,
		kArc,
	};

private:
	AcGeLineSeg2d m_seg;
	AcGeCircArc2d m_arc;
	ProfileurveType m_type;

public:
	ProfileCurve2d() { m_type = kLineSeg; }
	ProfileCurve2d(const AcGeLineSeg2d& seg)
	{
		m_seg = seg;
		m_type = kLineSeg;
	}
	ProfileCurve2d(const AcGeCircArc2d& arc)
	{
		m_arc = arc;
		m_type = kArc;
	}

	AcGeCircArc2d arc() const { return m_arc; }
	bool isSegment() const { return m_type == kLineSeg; }
	bool isArc() const { return m_type == kArc; }
	AcGeLineSeg2d lineSeg() const { return m_seg; }
	void setArc(const AcGeCircArc2d& arc)
	{
		m_arc = arc;
		m_type = kArc;
	}
	void setLineSeg(const AcGeLineSeg2d& lineSeg)
	{
		m_seg = lineSeg;
		m_type = kLineSeg;
	}
};

class ACDB_PORT AcPointCloudExtractResult
{
public:
	AcArray<ProfileCurve2d> Curves;
	AcGeMatrix3d transform;
	AcGePlane ProjectedPlane;
};

#include "icarx/IcArxPackPop.h"

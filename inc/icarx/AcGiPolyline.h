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
***     Description: Declaration of AcGiPolyline class
***
*****************************************************************************/
#pragma once

#include "../adesk.h"
#include "../AcGiParameter.h"

class AcGiImpPolyline;
class AcGePoint3d;
class AcGeVector3d;

#include "IcArxPackPush.h"

class AcGiPolyline : public AcGiParameter
{
public:
	enum LinetypeGeneration
	{
		kPerSegment,
		kEndToEnd
	};

	ACRX_DECLARE_MEMBERS_READWRITE_EXPIMP(AcGiPolyline, AcGiImpPolyline, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT AcGiPolyline();
	ACDBCORE2D_PORT AcGiPolyline(uint32_t nbPoints, AcGePoint3d* pVertexList,
								 AcGeVector3d* pNormal = nullptr,
								 IcArx::Integers::LongPtr lBaseSubEntMarker = -1);
	ACDBCORE2D_PORT ~AcGiPolyline();

	ACDBCORE2D_PORT virtual const bool* arcSegmentFlags() const;
	ACDBCORE2D_PORT virtual IcArx::Integers::LongPtr baseSubEntMarker() const;
	ACDBCORE2D_PORT virtual const double* bulge() const;
	ACDBCORE2D_PORT virtual double constantWidth() const;
	ACDBCORE2D_PORT virtual double elevation() const;
	ACDBCORE2D_PORT virtual bool getBulgeAt(unsigned int idx, double& bulge) const;
	ACDBCORE2D_PORT virtual bool getPointAt(unsigned int idx, AcGePoint3d& pt) const;
	ACDBCORE2D_PORT virtual bool getWidthsAt(unsigned int idx, double& startWidth,
											 double& endWidth) const;
	ACDBCORE2D_PORT virtual bool hasBulges() const;
	ACDBCORE2D_PORT virtual bool hasGsMarker() const;
	ACDBCORE2D_PORT virtual bool hasWidth() const;
	ACDBCORE2D_PORT virtual bool isClosed() const;
	ACDBCORE2D_PORT virtual LinetypeGeneration linetypeGen() const;
	ACDBCORE2D_PORT virtual const AcGeVector3d* normal() const;
	ACDBCORE2D_PORT virtual uint32_t points() const;
	ACDBCORE2D_PORT virtual void setArcSegmentFlags(const bool* pArcSegmentFlags);
	ACDBCORE2D_PORT virtual void setBaseSubEntMarker(IcArx::Integers::LongPtr lBaseSubEntMarker);
	ACDBCORE2D_PORT virtual void setBulge(const double* pBulge);
	ACDBCORE2D_PORT virtual void setClosed(bool val);
	ACDBCORE2D_PORT virtual void setConstantWidth(double val);
	ACDBCORE2D_PORT virtual void setElevation(double val);
	ACDBCORE2D_PORT virtual void setLinetypeGen(LinetypeGeneration ltgen);
	ACDBCORE2D_PORT virtual void setNormal(const AcGeVector3d* pNormal);
	ACDBCORE2D_PORT virtual void setSubEntMarkerList(const IcArx::Integers::LongPtr* pSubEntMarkerList);
	ACDBCORE2D_PORT virtual void setThickness(double val);
	ACDBCORE2D_PORT virtual void setVertexList(uint32_t nbPoints,
											   const AcGePoint3d* pVertexList);
	ACDBCORE2D_PORT virtual void setWidth(const double* pWidth);
	ACDBCORE2D_PORT virtual const IcArx::Integers::LongPtr* subEntMarkerList() const;
	ACDBCORE2D_PORT virtual double thickness() const;
	ACDBCORE2D_PORT virtual const AcGePoint3d* vertexList() const;
	ACDBCORE2D_PORT virtual const double* width() const;
};

#include "IcArxPackPop.h"

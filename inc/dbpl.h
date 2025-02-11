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
***     Description: Declaration of AcDbPolyline class
***
*****************************************************************************/
#pragma once

#include "dbmain.h"
#include "dbcurve.h"

#include "gelnsg2d.h"
#include "gelnsg3d.h"
#include "gearc2d.h"
#include "gearc3d.h"
#include "gept2dar.h"
#include "dbboiler.h"

class AcDb2dPolyline;

#include "icarx/IcArxPackPush.h"

class AcDbPolyline : public AcDbCurve
{
public:
	enum SegType
	{
		kLine,
		kArc,
		kCoincident,
		kPoint,
		kEmpty
	};

protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDBCORE2D_DECLARE_MEMBERS(AcDbPolyline);

public:
	AcDbPolyline();
	AcDbPolyline(unsigned int num_verts);
	~AcDbPolyline();

	DBCURVE_METHODS

	virtual Acad::ErrorStatus addVertexAt(unsigned int index, const AcGePoint2d& pt,
										  double bulge = 0., double startWidth = -1.,
										  double endWidth = -1., int32_t vertexIdentifier = 0);
	Acad::ErrorStatus applyPartialUndo(AcDbDwgFiler* filer, AcRxClass* classobj) override;
	virtual Acad::ErrorStatus convertFrom(AcDbEntity*& pPline, bool transferId = true);
	Acad::ErrorStatus convertTo(AcDb2dPolyline*& pPline, bool transferId = true) const;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* filer) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* filer) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* filer) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* filer) const override;
	double elevation() const;
	Acad::ErrorStatus getArcSegAt(unsigned int index, AcGeCircArc2d& arc) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getArcSegAt(unsigned int index, AcGeCircArc3d& arc) const;
	Acad::ErrorStatus getBulgeAt(unsigned int index, double& bulge) const;
	Acad::ErrorStatus getConstantWidth(double&) const;
	void getEcs(AcGeMatrix3d& retVal) const override;
	Acad::ErrorStatus getLineSegAt(unsigned int index, AcGeLineSeg2d& ln) const;
	Acad::ErrorStatus getPointAt(unsigned int, AcGePoint3d& pt) const;
	Acad::ErrorStatus getPointAt(unsigned int index, AcGePoint2d& pt) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getLineSegAt(unsigned int index, AcGeLineSeg3d& ln) const;
	Acad::ErrorStatus getVertexIdentifierAt(unsigned int index, int32_t& vertexIdentifier) const;
	Acad::ErrorStatus getWidthsAt(unsigned int index, double& startWidth, double& endWidth) const;
	bool hasBulges() const;
	bool hasPlinegen() const;
	bool hasVertexIdentifiers() const;
	bool hasWidth() const;
	bool isOnlyLines() const;
	ACDBCORE2D_PORT Acad::ErrorStatus makeClosedIfStartAndEndVertexCoincide(double distTol);
	Acad::ErrorStatus maximizeMemory();
	Acad::ErrorStatus minimizeMemory();
	AcGeVector3d normal() const;
	ACDBCORE2D_PORT unsigned int numVerts() const;
	virtual bool onSegAt(unsigned int index, const AcGePoint2d& pt2d, double& param) const;
	virtual Acad::ErrorStatus removeVertexAt(unsigned int index);
	virtual void reset(bool reuse, unsigned int numVerts);
	void saveAs(AcGiWorldDraw* mode, AcDb::SaveType st) override;
	ACDBCORE2D_PORT SegType segType(unsigned int index) const;
	virtual Acad::ErrorStatus setBulgeAt(unsigned int index, double bulge);
	virtual void setClosed(bool);
	virtual Acad::ErrorStatus setConstantWidth(double);
	virtual void setElevation(double);
	virtual Acad::ErrorStatus setNormal(const AcGeVector3d&);
	void setPlinegen(bool);
	virtual Acad::ErrorStatus setPointAt(unsigned int index, const AcGePoint2d& pt);
	virtual Acad::ErrorStatus setThickness(double);
	virtual Acad::ErrorStatus setVertexIdentifierAt(unsigned int index, int32_t suggestedValue);
	virtual Acad::ErrorStatus setWidthsAt(unsigned int index, double startWidth, double endWidth);
	double thickness() const;
};

#include "icarx/IcArxPackPop.h"

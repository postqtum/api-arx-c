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
***     Description: Declaration of AcDbLeader class
***
*****************************************************************************/
#pragma once

#include "dbmain.h"
#include "dbcurve.h"
#include "gescl3d.h"
#include "gepnt2d.h"
#include "geplane.h"

#include "icarx/IcArxPackPush.h"

class AcDbLeader : public AcDbCurve
{
public:
	enum AnnoType
	{
		kMText = 0,
		kFcf,
		kBlockRef,
		kNoAnno
	};

protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	AcDbLeader();
	~AcDbLeader();

	ACDB_DECLARE_MEMBERS(AcDbLeader);
	DBCURVE_METHODS

	double annoHeight() const;
	AnnoType annoType() const;
	double annoWidth() const;
	virtual AcDbObjectId annotationObjId() const;
	virtual AcGeVector3d annotationOffset() const;
	virtual bool appendVertex(const AcGePoint3d&);
	virtual Acad::ErrorStatus attachAnnotation(const AcDbObjectId& annoId);
	void copied(const AcDbObject*, const AcDbObject*) override;
	virtual Acad::ErrorStatus detachAnnotation();
	virtual double dimasz() const;
	virtual AcCmColor dimclrd() const;
	virtual AcDbHardPointerId dimensionStyle() const;
	virtual double dimgap() const;
	virtual AcDbObjectId dimldrblk() const;
	virtual AcDb::LineWeight dimlwd() const;
	virtual bool dimsah() const;
	virtual double dimscale() const;
	virtual int dimtad() const;
	virtual AcDbObjectId dimtxsty() const;
	virtual double dimtxt() const;
	virtual void disableArrowHead();
	virtual void enableArrowHead();
	void erased(const AcDbObject*, bool = true) override;
	virtual Acad::ErrorStatus evaluateLeader();
	virtual AcGePoint3d firstVertex() const;
	Acad::ErrorStatus getDimstyleData(AcDbDimStyleTableRecord*& pRecord) const;
	void goodbye(const AcDbObject*) override;
	virtual bool hasArrowHead() const;
	virtual bool hasHookLine() const;
	virtual bool isSplined() const;
	virtual AcGePoint3d lastVertex() const;
	void modified(const AcDbObject*) override;
	virtual AcGeVector3d normal() const;
	virtual int numVertices() const;
	virtual void removeLastVertex();
	ACDBCORE2D_PORT Acad::ErrorStatus setAnnotationObjId(const AcDbObjectId& annoId);
	virtual Acad::ErrorStatus setAnnotationOffset(const AcGeVector3d& offset);
	Acad::ErrorStatus setColorIndex(uint16_t, bool doSubents = true) override;
	virtual void setDimVars();
	virtual Acad::ErrorStatus setDimasz(double val);
	virtual Acad::ErrorStatus setDimclrd(AcCmColor& val);
	virtual void setDimensionStyle(const AcDbHardPointerId&);
	virtual Acad::ErrorStatus setDimgap(double val);
	virtual Acad::ErrorStatus setDimldrblk(AcDbObjectId val);
	virtual Acad::ErrorStatus setDimldrblk(const ACHAR* val);
	virtual Acad::ErrorStatus setDimlwd(AcDb::LineWeight v);
	virtual Acad::ErrorStatus setDimsah(bool val);
	virtual Acad::ErrorStatus setDimscale(double val);
	Acad::ErrorStatus setDimstyleData(AcDbDimStyleTableRecord* pNewData);
	Acad::ErrorStatus setDimstyleData(AcDbObjectId newDataId);
	virtual Acad::ErrorStatus setDimtad(int val);
	virtual Acad::ErrorStatus setDimtxsty(AcDbObjectId val);
	virtual Acad::ErrorStatus setDimtxt(double val);
	ACDBCORE2D_PORT void setHasArrowHead(bool bEnable);
	virtual void setPlane(const AcGePlane&);
	ACDBCORE2D_PORT void setSplined(bool bSplined);
	virtual void setToSplineLeader();
	virtual void setToStraightLeader();
	virtual bool setVertexAt(int, const AcGePoint3d&);
	virtual AcGePoint3d vertexAt(int) const;
};

#include "icarx/IcArxPackPop.h"

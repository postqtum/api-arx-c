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
***     Description: Declaration of AcDbMlineStyle class
***
*****************************************************************************/
#pragma once

#include "dbmain.h"
#include "AdAChar.h"

#define MSTYLE_NAME_LENGTH 32
#define MSTYLE_DESCRIPTION_LENGTH 256
#define LTYPE_LENGTH 32
#define MLINE_MAX_ELEMENTS 16

#define MIN_ANGLE (10.0 * PI / 180.0)

#define MAX_ANGLE (170.0 * PI / 180.0)

#define MSTYLE_DXF_FILL_ON (0x1)
#define MSTYLE_DXF_SHOW_MITERS (0x2)
#define MSTYLE_DXF_START_SQUARE_CAP (0x10)
#define MSTYLE_DXF_START_INNER_ARCS (0x20)
#define MSTYLE_DXF_START_ROUND_CAP (0x40)
#define MSTYLE_DXF_END_SQUARE_CAP (0x100)
#define MSTYLE_DXF_END_INNER_ARCS (0x200)
#define MSTYLE_DXF_END_ROUND_CAP (0x400)
#define MSTYLE_DXF_JUST_TOP (0x1000)
#define MSTYLE_DXF_JUST_ZERO (0x2000)
#define MSTYLE_DXF_JUST_BOT (0x4000)

#include "icarx/IcArxPackPush.h"

class AcDbMlineStyle : public AcDbObject
{
public:
	ACDB_DECLARE_MEMBERS(AcDbMlineStyle);

	AcDbMlineStyle();
	~AcDbMlineStyle();

	Acad::ErrorStatus addElement(int& index, double offset, const AcCmColor& color,
								 AcDbObjectId linetypeId, bool checkIfReferenced = true);
	Acad::ErrorStatus copyFrom(const AcRxObject* other) override;
	const ACHAR* description() const;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* filer) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* filer) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* filer) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* filer) const override;
	double endAngle() const;
	bool endInnerArcs() const;
	bool endRoundCap() const;
	bool endSquareCap() const;
	const AcCmColor& fillColor() const;
	bool filled() const;
	Acad::ErrorStatus getElementAt(int elem, double& offset, AcCmColor& color,
								   AcDbObjectId& linetypeId) const;
	void initMlineStyle();
	const ACHAR* name() const;
	int numElements() const;
	Acad::ErrorStatus removeElementAt(int elem);
	void set(const AcDbMlineStyle& src, bool checkIfReferenced = true);
	Acad::ErrorStatus setDescription(const ACHAR* description);
	Acad::ErrorStatus setElement(int& elem, double offset, const AcCmColor& color,
								 AcDbObjectId linetypeId);
	Acad::ErrorStatus setEndAngle(double ang);
	void setEndInnerArcs(bool showThem);
	void setEndRoundCap(bool showIt);
	void setEndSquareCap(bool showIt);
	Acad::ErrorStatus setFillColor(const AcCmColor& color);
	void setFilled(bool onOff);
	Acad::ErrorStatus setName(const ACHAR* name);
	void setShowMiters(bool showThem);
	Acad::ErrorStatus setStartAngle(double ang);
	void setStartInnerArcs(bool showThem);
	void setStartRoundCap(bool showIt);
	void setStartSquareCap(bool showIt);
	bool showMiters() const;
	double startAngle() const;
	bool startInnerArcs() const;
	bool startRoundCap() const;
	bool startSquareCap() const;
	Acad::ErrorStatus subErase(bool pErasing = true) override;
};

#include "icarx/IcArxPackPop.h"

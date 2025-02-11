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
***     Description: Declaration of AcDbHelix class
***
*****************************************************************************/
#pragma once

#include "gegbl.h"
#include "dbmain.h"
#include "dbspline.h"

#include "icarx/IcArxPackPush.h"

class AcDbHelix : public AcDbSpline
{
public:
	enum ConstrainType
	{
		kTurnHeight = 0,
		kTurns = 1,
		kHeight = 2
	};

protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	GEOMENT_DECLARE_MEMBERS(AcDbHelix);

	AcDbHelix();
	~AcDbHelix();

	virtual AcGePoint3d axisPoint() const;
	virtual AcGeVector3d axisVector() const;
	virtual double baseRadius() const;
	virtual ConstrainType constrain() const;
	Acad::ErrorStatus createHelix();
	virtual double height() const;
	Acad::ErrorStatus reverseCurve() override;
	virtual Acad::ErrorStatus setAxisPoint(const AcGePoint3d& axisPoint,
										   const bool bMoveStartPoint = true);
	virtual Acad::ErrorStatus setAxisVector(const AcGeVector3d& axisVector);
	virtual Acad::ErrorStatus setBaseRadius(double dRadius);
	virtual Acad::ErrorStatus setConstrain(ConstrainType constrain);
	virtual Acad::ErrorStatus setHeight(double dHeight);
	virtual Acad::ErrorStatus setStartPoint(const AcGePoint3d& startPoint);
	virtual Acad::ErrorStatus setTopRadius(double dRadius);
	virtual Acad::ErrorStatus setTurnHeight(double dTurnHeight);
	virtual Acad::ErrorStatus setTurns(double dTurns);
	virtual Acad::ErrorStatus setTwist(bool bTwist);
	virtual AcGePoint3d startPoint() const;
	virtual double topRadius() const;
	virtual double totalLength() const;
	virtual double turnHeight() const;
	virtual double turnSlope() const;
	virtual double turns() const;
	virtual bool twist() const;
};

#include "icarx/IcArxPackPop.h"

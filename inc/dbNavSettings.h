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
***     Description: Declaration of AcDbHomeView class
***
*****************************************************************************/
#pragma once

#include "acadstrc.h"
#include "gepnt3d.h"
#include "AcDbCore2dDefs.h"

class AcDbImpHomeView;
class AcDbDatabase;

#include "icarx/IcArxPackPush.h"

class AcDbHomeView
{
private:
	AcDbImpHomeView* mpImpObj;

public:
	ACDBCORE2D_PORT AcDbHomeView();
	ACDBCORE2D_PORT AcDbHomeView(const AcDbHomeView& rhvw);
	ACDBCORE2D_PORT virtual ~AcDbHomeView();
	ACDBCORE2D_PORT AcDbHomeView& operator=(const AcDbHomeView& rhvw);
	ACDBCORE2D_PORT bool operator==(const AcDbHomeView& rhvw) const;
	ACDBCORE2D_PORT bool operator!=(const AcDbHomeView& rhvw) const;

	ACDBCORE2D_PORT const AcGePoint3d& center() const;
	ACDBCORE2D_PORT const AcGePoint3d& eye() const;
	ACDBCORE2D_PORT Acad::ErrorStatus getHomeView(AcDbDatabase* pDb, bool bCreateDefault = false);
	ACDBCORE2D_PORT const double height() const;
	ACDBCORE2D_PORT bool isDefaultHomeView() const;
	ACDBCORE2D_PORT const bool isPerspective() const;
	ACDBCORE2D_PORT void setCenter(const AcGePoint3d& ptCenter);
	ACDBCORE2D_PORT void setEye(const AcGePoint3d& ptEye);
	ACDBCORE2D_PORT void setHeight(double dHeight);
	ACDBCORE2D_PORT Acad::ErrorStatus setHomeView(AcDbDatabase* pDb) const;
	ACDBCORE2D_PORT void setPerspective(bool bPerspective);
	ACDBCORE2D_PORT void setUp(const AcGeVector3d& vUp);
	ACDBCORE2D_PORT void setWidth(double dWidth);
	ACDBCORE2D_PORT void toggleDefaultSettings();
	ACDBCORE2D_PORT const AcGeVector3d& up() const;
	ACDBCORE2D_PORT const double width() const;
};

#include "icarx/IcArxPackPop.h"

ACDBCORE2D_PORT Acad::ErrorStatus acdbGetHomeView(AcDbDatabase* pDb, AcDbHomeView& hmView);
ACDBCORE2D_PORT Acad::ErrorStatus acdbGetShowCompass(AcDbDatabase* pDb, bool& bShow);
ACDBCORE2D_PORT Acad::ErrorStatus acdbSetHomeView(AcDbDatabase* pDb, const AcDbHomeView& hmView);
ACDBCORE2D_PORT Acad::ErrorStatus acdbSetShowCompass(AcDbDatabase* pDb, bool bShow);

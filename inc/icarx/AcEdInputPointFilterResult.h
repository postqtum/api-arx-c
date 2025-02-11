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
***     Description: Declaration of AcEdInputPointFilterResult class
***
*****************************************************************************/
#pragma once

#include "../acadapidef.h"
#include "../acarray.h"

class AcEdImpInputPointFilterResult;
class AcGePoint3d;

#include "IcArxPackPush.h"

class AcEdInputPointFilterResult
{
	friend class AcEdImpInputPointManager;

private:
	AcEdImpInputPointFilterResult* m_pImp = nullptr;

private:
	AcEdInputPointFilterResult();
	~AcEdInputPointFilterResult();
	AcEdInputPointFilterResult& operator=(const AcEdInputPointFilterResult&);

public:
	ACAD_PORT bool displayOsnapGlyph() const;
	ACAD_PORT const AcGePoint3d& newPoint() const;
	ACAD_PORT const ACHAR* newTooltipString() const;
	ACAD_PORT bool retry() const;
	ACAD_PORT void setDisplayOsnapGlyph(bool newValue);
	ACAD_PORT void setNewPoint(const AcGePoint3d& newValue);
	ACAD_PORT void setNewTooltipString(const ACHAR* newValue);
	ACAD_PORT void setRetry(bool newValue);
};

#include "IcArxPackPop.h"

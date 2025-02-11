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
***     Description: Declaration of ExtractOption class
***
*****************************************************************************/
#pragma once

#include "../acdbport.h"

#include "IcArxPackPush.h"

class ACDB_PORT ExtractOption
{
public:
	enum ExtractionType
	{
		kOutLine,
		kAllLine,
	};

public:
	ExtractionType m_extractionType;
	unsigned int m_processPoints;
	double m_fillGap;
	unsigned int m_snapAngle;
	double m_minSegLength;
	bool m_useLineSegmentOnly;

public:
	ExtractOption();
};

#include "IcArxPackPop.h"

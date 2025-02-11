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
***     Description: Declaration of AcPlPlotPageInfo class
***
*****************************************************************************/
#pragma once

#include "../AcPl.h"
#include "../AcPlObject.h"

#include "IcArxPackPush.h"

class AcPlPlotPageInfo : public AcPlObject
{
private:
	ACPL_DECLARE_MEMBERS(AcPlPlotPageInfo);

public:
	ACPL_PORT AcPlPlotPageInfo();
	ACPL_PORT ~AcPlPlotPageInfo();

	ACPL_PORT int32_t entityCount() const;
	ACPL_PORT int32_t gradientCount() const;
	ACPL_PORT int32_t oleObjectCount() const;
	ACPL_PORT int32_t rasterCount() const;
	ACPL_PORT int32_t shadedViewportType() const;
};

#include "IcArxPackPop.h"

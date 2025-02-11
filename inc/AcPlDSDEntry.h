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

#include "AcPl.h"
#include "AcPlObject.h"

#include "icarx/IcArxPackPush.h"

class AcPlDSDEntry : public AcPlObject
{
public:
	enum SetupType
	{
		kOriginalPS = 0,
		kNPSSameDWG = 1,
		kNPSOtherDWG = 2,
		k3dDwf = 3,
		kOverridePS = 4,
	};

	enum SheetType
	{
		kSingleDWF = 0,
		kMultiDWF = 1,
		kOriginalDevice = 2,
		kSingleDWFx = 3,
		kMultiDWFx = 4,
		kSinglePDF = 5,
		kMultiPDF = 6,
		kSingleSVF = 7,
		kMultiSVF = 8,
	};

private:
	ACPL_DECLARE_MEMBERS(AcPlDSDEntry)

public:
	ACPL_PORT AcPlDSDEntry();
	ACPL_PORT AcPlDSDEntry(const AcPlDSDEntry& src);
	ACPL_PORT ~AcPlDSDEntry();
	ACPL_PORT AcPlDSDEntry& operator=(const AcPlDSDEntry& src);

	ACPL_PORT const ACHAR* NPS() const;
	ACPL_PORT const ACHAR* NPSSourceDWG() const;
	ACPL_PORT const ACHAR* dwgName() const;
	ACPL_PORT bool has3dDwfSetup() const;
	ACPL_PORT const ACHAR* layout() const;
	ACPL_PORT const ACHAR* orgSheetPath() const;
	ACPL_PORT void setDwgName(const ACHAR* pName);
	ACPL_PORT void setHas3dDwfSetup(bool b3dDwfSetup);
	ACPL_PORT void setLayout(const ACHAR* pLayoutName);
	ACPL_PORT void setNPS(const ACHAR* pNPSName);
	ACPL_PORT void setNPSSourceDWG(const ACHAR* pNPWDWGName);
	ACPL_PORT void setSetupType(AcPlDSDEntry::SetupType eType);
	ACPL_PORT void setTitle(const ACHAR* pTitle);
	ACPL_PORT void setTraceSession(const ACHAR* pTraceSession);
	ACPL_PORT AcPlDSDEntry::SetupType setupType() const;
	ACPL_PORT const ACHAR* title() const;
	ACPL_PORT const ACHAR* traceSession() const;
};

#include "icarx/IcArxPackPop.h"

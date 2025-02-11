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
***     Description: AcDbAppSystemVariables declarations
***
*****************************************************************************/
#pragma once

#include "acdb.h"
#include "acadstrc.h"

enum
{
	kGroupsOn = 0x01,
	kHatchAssocOn = 0x02
};

#include "icarx/IcArxPackPush.h"

class AcDbAppSystemVariables
{
private:
	bool m_attdia = true;
	bool m_attreq = true;
	bool m_blipmode = false;
	short m_delobj = 3;
	short m_coords = 0;
	short m_statusbar = 1;
	bool m_menubar = false;
	bool m_appstatusbaruseicons = true;
	short m_dragmode = 2;
	short m_osmode = 0;
	short m_pkstyle = kGroupsOn;
	AcDb::LineWeight m_lwdefault = AcDb::kLnWt025;
	bool m_hpassoc = 1;

public:
	Acad::ErrorStatus setAppStatusBarUseIcons(bool value, bool bUndo = false);
	Acad::ErrorStatus setAttdia(bool value, bool bUndo = false);
	Acad::ErrorStatus setAttreq(bool, bool bUndo = false);
	Acad::ErrorStatus setBlipmode(bool, bool bUndo = false);
	Acad::ErrorStatus setCoords(int16_t value, bool bUndo = false);
	Acad::ErrorStatus setDelUsedObj(int16_t, bool bUndo = false);
	Acad::ErrorStatus setDragmode(int16_t, bool bUndo = false);
	Acad::ErrorStatus setHpassoc(bool value, bool bUndo = false);
	Acad::ErrorStatus setLwdefault(AcDb::LineWeight value, bool bUndo = false);
	Acad::ErrorStatus setMenubar(bool value, bool bUndo = false);
	Acad::ErrorStatus setOsmode(int16_t value, bool bUndo = false);
	Acad::ErrorStatus setPickstyle(int16_t value, bool bUndo = false);
	Acad::ErrorStatus setStatusbar(int16_t value, bool bUndo = false);
	inline AcDb::LineWeight lwdefault() const { return m_lwdefault; }
	inline int16_t coords() const { return m_coords; }
	inline int16_t delUsedObj() const { return m_delobj; }
	inline int16_t dragmode() const { return m_dragmode; }
	inline int16_t osmode() const { return m_osmode; }
	inline int16_t pickstyle() const { return m_pkstyle; }
	inline int16_t statusbar() const { return m_statusbar; }
	inline bool appstatusbaruseicons() const { return m_appstatusbaruseicons; }
	inline bool attdia() const { return m_attdia; }
	inline bool attreq() const { return m_attreq; }
	inline bool blipmode() const { return m_blipmode; }
	inline bool hpassoc() const { return m_hpassoc; }
	inline bool menubar() const { return m_menubar; }
};

#include "icarx/IcArxPackPop.h"

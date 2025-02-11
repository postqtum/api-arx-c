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
***     Description: Declaration of CAdUiDrawTipText class
***
*****************************************************************************/
#pragma once

#include <afxwin.h>

#include "../adui_port.h"

class ADUI_PORT CAdUiDrawTipText
{
public:
	CAdUiDrawTipText(CDC& dc, CRect& rect, CString& text);

public:
	CDC& m_dc;
	CRect& m_rect;
	CString& m_text;
};

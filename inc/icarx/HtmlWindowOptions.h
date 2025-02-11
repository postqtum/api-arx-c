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
***     Description: Declaration of HtmlWindowOptions struct
***
*****************************************************************************/
#pragma once

#include "IcArxPackPush.h"

struct HtmlWindowOptions
{
	enum HtmlWindowFlags
	{
		eAllowResize = 0x0001,
		eAllowMinimize = 0x0002,
		eAllowMaximize = 0x0004,
		eInitPosition = 0x0008,
		eInitSize = 0x0010,
		eMaxSize = 0x0020,
		eMinSize = 0x0040,
		ePersistSizeAndPosition = 0x0080,
		eCenterWindow = 0x0100,
		eDialogFrame = 0x0200,
		eAutoHiDpiScale = 0x0400
	};

	UINT flags;
	UINT x;
	UINT y;
	UINT width;
	UINT height;
	UINT maxWidth;
	UINT maxHeight;
	UINT minWidth;
	UINT minHeight;
	UINT dialogTemplateId;

	HtmlWindowOptions() { dialogTemplateId = 0; }
};

#include "IcArxPackPop.h"

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
***     Description: AcEd related enumeration
***
*****************************************************************************/
#pragma once

enum xrefSubcommandActivities
{
	kStart = 0,
	kStartItem = 2,
	kEndItem = 3,
	kEnd = 4,
	kWillAbort = 5,
	kAborted = 6,
	kStartXBindBlock = 7,
	kStartXBindSymbol = 8
};

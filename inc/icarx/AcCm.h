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
***     Description: Declaration of AcCm namespace
***
*****************************************************************************/
#pragma once

namespace AcCm
{

enum ACIColors
{
	kACIByBlock = 0,
	kACIRed = 1,
	kACIYellow = 2,
	kACIGreen = 3,
	kACICyan = 4,
	kACIBlue = 5,
	kACIMagenta = 6,
	kACIForeground = 7,
	kACIByLayer = 256,
};

enum DialogTabs
{
	kACITab = 1,
	kTrueColorTab = 2,
	kColorBookTab = 4,
};

}  // namespace AcCm

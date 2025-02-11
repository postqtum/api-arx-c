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
***     Description: Font Picth and Family enums
***
*****************************************************************************/
#pragma once

#ifdef PAL
#	undef PAL
#endif

namespace Autodesk
{
namespace AutoCAD
{
namespace PAL
{
namespace FontUtils
{

enum class FontFamily
{
	kDoNotCare = 0,
	kRoman = 16,
	kSwiss = 32,
	kModern = 48,
	kScript = 64,
	kDecorative = 80
};

enum class FontPitch
{
	kDefault,
	kFixed,
	kVariable
};

}  // namespace FontUtils
}  // namespace PAL
}  // namespace AutoCAD
};	// namespace Autodesk

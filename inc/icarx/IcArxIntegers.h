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

#include <cstdint>

namespace IcArx
{

struct Integers
{
	using Int8 = int8_t;
	using UInt8 = uint8_t;

	using Int16 = int16_t;
	using UInt16 = uint16_t;

	using Int32 = int32_t;
	using UInt32 = uint32_t;

	using Int64 = int64_t;
	using UInt64 = uint64_t;

	using LongPtr = int64_t;
	using ULongPtr = uint64_t;
	using IntPtr = int64_t;
	using UIntPtr = uint64_t;

	using IntDbId = LongPtr;
	using GsMarker = IntPtr;

	using uchar = unsigned char;
	using ushort = unsigned short;
	using uint = unsigned int;

	using Time64 = int64_t;

	using ColorRef = uint32_t;
	using RGBQuad = uint32_t;

	using Boolean = bool;
	static constexpr bool kFalse = false;
	static constexpr bool kTrue = true;
};

}  // namespace IcArx

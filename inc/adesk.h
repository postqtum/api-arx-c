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
***     Description: ADESK_ prefixed macro definitions
***
*****************************************************************************/
#pragma once

#include <stdint.h>
#include <stddef.h>
#include "AdAChar.h"

#define INTELLICAD_ADESK_H_HEADER 1

#if defined(__cplusplus)

#	include "icarx/IcArxIntegers.h"

using Adesk = IcArx::Integers;

#endif	// __cplusplus

#define Adesk_Boolean_is_bool 1
#define Adesk_Int32_is_int 1

#define _ADESK_WINDOWS_ 1

#define _AC64 1

#undef NULL
#define NULL 0

#define ADESK_NO_VTABLE __declspec(novtable)
#define ADESK_STDCALL __stdcall
#define ADESK_DEPRECATED __declspec(deprecated)
#define ADESK_DEPRECATED_MSG(MSG) __declspec(deprecated(MSG))
#define ADESK_DATA_IMPORT __declspec(dllimport)
#define ADESK_PACK_BEGIN __pragma(pack(push, 1))
#define ADESK_PACK_END __pragma(pack(pop))
#define ADESK_HIDDEN_SYMBOL

#define ADESK_SEALED final
#define ADESK_SEALED_VIRTUAL virtual

#define ADESK_FORCE_INLINE __forceinline

#define ADESK_UNREFED_PARAM(x) (void)(x)

#define ADESK_UNREACHABLE __assume(false)

#define ADESK_FORCE_OPTNONE

#define ADESK_EXPORT __declspec(dllexport)

#define ADESK_NODISCARD

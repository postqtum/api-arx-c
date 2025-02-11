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
***     Description: Declaration of ICARX_ASSERT macro
***
*****************************************************************************/

#undef ICARX_ASSERT
#if defined(ASSERT)
#	define ICARX_ASSERT ASSERT
#elif defined(assert)
#	define ICARX_ASSERT assert
#elif defined(_ASSERTE)
#	define ICARX_ASSERT _ASSERTE
#else
#	define ICARX_ASSERT(x)
#endif

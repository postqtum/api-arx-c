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

#include "idrelver.h"

#if defined(AC_BLDENV)
#	include "_idver.h"
#else
#	define ACADV_BLDMAJOR 0
#	define ACADV_BLDMINOR 0
#	define ACADV_BLDBRANCH 0
#	define ACADV_BLDSTREAM DevelopmentBranch
#endif

#define ACADV_RCFILEVER3 ACADV_BLDMAJOR
#define ACADV_RCFILEVER4 ACADV_BLDMINOR
#define ACADV_RCFILEVER5 ACADV_BLDBRANCH

#define ACADV_RCFILEVERSTR                                                \
	ID2STR(ACADV_RCFILEVER1)                                              \
	"." ID2STR(ACADV_RCFILEVER2) "." ID2STR(ACADV_RCFILEVER3) "." ID2STR( \
			ACADV_RCFILEVER5) "." ID2STR(ACADV_RCFILEVER4)

#define ACADV_PRODVERSION "R" ACADV_RCFILEVERSTR

#define ACADV_VERNUM                                                                       \
	ACRX_T(ID2STR(ACADV_BLDSTREAM))                                                        \
	ACRX_T(".")                                                                            \
	ACRX_T(ID2STR(ACADV_BLDMAJOR)) ACRX_T(".") ACRX_T(ID2STR(ACADV_BLDBRANCH)) ACRX_T(".") \
			ACRX_T(ID2STR(ACADV_BLDMINOR))

#if defined(PRODUCTION)
#	define ACADV_VERFULL ACADV_VERNAME
#else
#	define ACADV_VERFULL ACADV_VERNUM
#endif

#define ACADV_BLDVERSTR ACADV_VERNUM

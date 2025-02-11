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

#include "id.h"

#define VALUE2STR(x) #x
#define ID2STR(a) ID2STR__1(a)
#define ID2STR__1(a) VALUE2STR(a)

#define ACADV_RCFILEVER1 ACADV_RELMAJOR
#define ACADV_RCFILEVER2 ACADV_RELMINOR

#define ACADV_RCFILEVER1_CORRECTION (6 + ACADV_RCFILEVER1)

#define ACADV_VERNAME ACRX_T(ID2STR(ACADV_RELMAJOR)) ACRX_T(".") ACRX_T(ID2STR(ACADV_RELMINOR))

#define ACAD_COPYRIGHT "Copyright (C) 2022-2023 IntelliCAD Technology Consortium.  All rights reserved."
#define ACAD_COPYRIGHT_YEAR "2022"

#define ACAD_TLBVERSION_MAJOR 1
#define ACAD_TLBVERSION_MINOR 0
#define ACAD_TLBVERSION ACAD_TLBVERSION_MAJOR.ACAD_TLBVERSION_MINOR

#define ACAD_TLBVERSIONSTR \
	ACRX_T(ID2STR(ACAD_TLBVERSION_MAJOR)) ACRX_T(".") ACRX_T(ID2STR(ACAD_TLBVERSION_MINOR))

#define ACDB_TLBVERSION_MAJOR 1
#define ACDB_TLBVERSION_MINOR 0
#define ACDB_TLBVERSION ACDB_TLBVERSION_MAJOR.ACDB_TLBVERSION_MINOR

#define ACDB_TLBVERSIONSTR \
	ACRX_T(ID2STR(ACDB_TLBVERSION_MAJOR)) ACRX_T(".") ACRX_T(ID2STR(ACDB_TLBVERSION_MINOR))

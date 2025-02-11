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

#include "rxboiler.h"

#define ACDB_DECLARE_MEMBERS(CLASSNAME) \
private:                                \
	friend class AcDbSystemInternals;   \
                                        \
protected:                              \
	CLASSNAME(AcDbSystemInternals*);    \
                                        \
public:                                 \
	ACRX_DECLARE_MEMBERS(CLASSNAME)

#define ACDB_DECLARE_MEMBERS_EXPIMP(CLASSNAME, EXPIMP) \
private:                                               \
	friend class AcDbSystemInternals;                  \
                                                       \
protected:                                             \
	CLASSNAME(AcDbSystemInternals*);                   \
                                                       \
public:                                                \
	ACRX_DECLARE_MEMBERS_EXPIMP(CLASSNAME, EXPIMP)

#define ACDBCORE2D_DECLARE_MEMBERS(CLASSNAME) \
	ACDB_DECLARE_MEMBERS_EXPIMP(CLASSNAME, ACDBCORE2D_PORT)

#if defined(_ADESK_WINRT_) || defined(_ADESK_IOS_) || defined(_ADESK_WEB_) || \
		defined(_ADESK_ANDROID_)
#	define GEOMENT_DECLARE_MEMBERS(CLASSNAME) ACDBCORE2D_DECLARE_MEMBERS(CLASSNAME);
#else
#	define GEOMENT_DECLARE_MEMBERS(CLASSNAME) ACDB_DECLARE_MEMBERS(CLASSNAME);
#endif

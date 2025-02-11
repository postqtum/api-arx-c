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

#include "adesk.h"

#define TRUE 1
#define FALSE 0
#ifndef EOS
#	define EOS ACRX_T('\0')
#endif

typedef double ads_real;
typedef ads_real ads_point[3];
typedef int64_t ads_name[2];
typedef int64_t* ads_namep;
typedef ads_real ads_matrix[4][4];

typedef ads_real* ads_pointp;

#ifdef X
#	undef X
#endif
#ifdef Y
#	undef Y
#endif
#ifdef Z
#	undef Z
#endif
#ifdef T
#	undef T
#endif

#ifndef _XYZT_DEFINED
#	define _XYZT_DEFINED
enum
{
	X = 0,
	Y = 1,
	Z = 2
};
enum
{
	T = 3
};
#endif	// !_XYZT_DEFINED

#define PAUSE ACRX_T("\\")

enum
{
	RSG_NONULL = 0x0001,
	RSG_NOZERO = 0x0002,
	RSG_NONEG = 0x0004,
	RSG_NOLIM = 0x0008,
	RSG_GETZ = 0x0010,
	RSG_DASH = 0x0020,
	RSG_2D = 0x0040,
	RSG_OTHER = 0x0080,
	RSG_DDISTFIRST = 0x0100,
	RSG_TRACKUCS = 0x0200,
	RSG_NOORTHOZ = 0x0400,
	RSG_NOOSNAP = 0x0800,
	RSG_NODDIST = 0x1000,
};

enum
{
	INP_NNULL = RSG_NONULL,
	INP_NZERO = RSG_NOZERO,
	INP_NNEG = RSG_NONEG,
	INP_NLIM = RSG_NOLIM,
	INP_DASH = RSG_DASH,
	INP_NZCOORD = RSG_2D
};

enum SelectorType
{
	SELECT_TYPE_FREE = 0,
	SELECT_TYPE_PICK,
	SELECT_TYPE_WPOLY,
	SELECT_TYPE_CPOLY,
	SELECT_TYPE_FENCE,
	SELECT_TYPE_SUBENTITY,
	SELECT_TYPE_BAG,
	SELECT_TYPE_LAST,
	SELECT_TYPE_LEAF,
	SELECT_TYPE_GROUP,
	SELECT_TYPE_PASTE,
	SELECT_TYPE_HATCHASC,
	SELECT_TYPE_NRVP,
	SELECT_TYPE_OCCLASS
};

#include "icarx/IcArxPackPush.h"

struct ads_binary
{
	short clen;
	char* buf;
};

union ads_u_val
{
	ads_real rreal;
	ads_real rpoint[3];
	short rint;
	ACHAR* rstring;
	int64_t rlname[2];
	int64_t mnLongPtr;
	int32_t rlong;
	int64_t mnInt64;
	struct ads_binary rbinary;
	unsigned char ihandle[8];
};

struct resbuf
{
	struct resbuf* rbnext;
	short restype;
	union ads_u_val resval;
};

#include "icarx/IcArxPackPop.h"

typedef struct resbuf* pResbuf;
typedef const struct resbuf* kpResbuf;


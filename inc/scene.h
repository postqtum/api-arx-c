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

#include "icarx/AcReCallout.h"
#include "icarx/e2fxform.h"
#include "icarx/e2fent.h"
#include "icarx/e2flayer.h"
#include "icarx/e2fhdr.h"
#include "icarx/scnnode.h"
#include "icarx/scnvrtc.h"
#include "icarx/scncmesh.h"

#include "AdAChar.h"

#define FACEVER 0

#define HEADER 'H'
#define ENTITY 'E'
#define EVERTEX 'V'
#define POLYGON 'P'
#define CONTOUR 'X'
#define SHADER 'D'
#define CMESH 'H'
#define BLOCK_B 'U'
#define BLOCK_E 'O'
#define E_LAYER 'L'

/*#define CURVE 0x1*/
#define TOPBOT 0x2

#define ENT_HAS_CMESH 1
#define ENT_HAS_XFORM 2
#define ENT_HAS_XDATA 4
#define ENT_HAS_NORMAL 8
#define ENT_HAS_SUBENT 16

#define RENDER_CACHE 1

#define CMAPSIZE 32

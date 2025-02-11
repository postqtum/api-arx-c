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

#define ACRX_CMD_MODAL 0x00000000
#define ACRX_CMD_TRANSPARENT 0x00000001
#define ACRX_CMD_USEPICKSET 0x00000002
#define ACRX_CMD_REDRAW 0x00000004
#define ACRX_CMD_NOPERSPECTIVE 0x00000008
#define ACRX_CMD_NOMULTIPLE 0x00000010
#define ACRX_CMD_NOTILEMODE 0x00000020
#define ACRX_CMD_NOPAPERSPACE 0x00000040

#define ACRX_CMD_DEPRECATED ACRX_CMD_UNDEFINED

#define ACRX_CMD_NOOEM 0x00000100
#define ACRX_CMD_UNDEFINED 0x00000200
#define ACRX_CMD_INPROGRESS 0x00000400
#define ACRX_CMD_DEFUN 0x00000800
#define ACRX_CMD_LISPASCMD 0x00001000
#define ACRX_CMD_PGPINIT 0x00002000
#define ACRX_CMD_NONEWSTACK 0x00010000
#define ACRX_CMD_NOINTERNALLOCK 0x00020000
#define ACRX_CMD_DOCREADLOCK 0x00080000
#define ACRX_CMD_DOCEXCLUSIVELOCK 0x00100000
#define ACRX_CMD_SESSION 0x00200000
#define ACRX_CMD_INTERRUPTIBLE 0x00400000
#define ACRX_CMD_NOHISTORY 0x00800000
#define ACRX_CMD_NO_UNDO_MARKER 0x01000000
#define ACRX_CMD_NOBEDIT 0x02000000
#define ACRX_CMD_NOACTIONRECORDING 0x04000000
#define ACRX_CMD_ACTIONMACRO 0x08000000
#define ACRX_CMD_RELAXASSOC 0x10000000
#define ACRX_CMD_CORE 0x20000000
#define ACRX_CMD_NOINFERCONSTRAINT 0x40000000
#define ACRX_CMD_TEMPSHOWDYNDIM 0x80000000

#define ACRX_MAX_CMDNAME_LEN 64

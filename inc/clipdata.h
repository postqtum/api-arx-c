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

#include "AcCoreDefs.h"
#include "AdAChar.h"
#include "gepnt3d.h"

enum eClipInfoFlags
{
	kbDragGeometry = 0x01,
};

enum eExpandedClipDataTypes
{
	kDcPlotStyles = 1,
	kDcXrefs = 2,
	kDcLayouts = 3,
	kDcBlocks = 4,
	kDcLayers = 5,
	kDcDrawings = 6,
	kDcLinetypes = 7,
	kDcTextStyles = 8,
	kDcDimStyles = 9,
	kDcBlocksWithAttdef = 10,
	kDcHatches = 11,
	kTpXrefs = 12,
	kTpImages = 13,
	kTpTable = 14,
	kDcTableStyles = 15,
	kDcMultileaderStyles = 16,
	kDcVisualStyles = 17,
	kDcSectionViewStyles = 18,
	kDcDetailViewStyles = 19,
};

enum eXrefType
{
	kXrefTypeAttach = 1,
	kXrefTypeOverlay = 2
};

const int nBlockFileSize = 260;
const int nSignatureSize = 4;

#include "icarx/IcArxPackPush.h"

typedef struct tagClipboardInfo
{
	ACHAR szTempFile[nBlockFileSize];
	ACHAR szSourceFile[nBlockFileSize];
	ACHAR szSignature[nSignatureSize];
	int nFlags;
	AcGePoint3d dptInsert;
	RECT rectGDI;
	void* mpView;
	DWORD m_dwThreadId;
	int nLen;
	int nType;
	ACHAR chData[1];
} ClipboardInfo;

#include "icarx/IcArxPackPop.h"

#define szClipSignature ACRX_T(/*MSG0*/ "R15")

ACCORE_PORT const ACHAR* acedClipFormatName();

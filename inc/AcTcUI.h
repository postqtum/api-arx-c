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

#include "adui.h"
#include "AdAChar.h"
#include <afxtempl.h>

#ifdef _ACTCUI_BUILD
#	define ACTCUI_PORT __declspec(dllexport)
#else
#	define ACTCUI_PORT
#endif


class CAcTcUiManager;
class CAcTcUiToolPaletteSet;
class CAcTcUiToolPalette;
class CAcTcUiCatalogView;
class AcTcCatalogItem;
class AcTcCatalog;
class AcTcStockTool;
class AcTcTool;

typedef CTypedPtrArray<CPtrArray, AcTcCatalogItem*> AcTcCatalogItemArray;
typedef CTypedPtrArray<CPtrArray, AcTcStockTool*> AcTcStockToolArray;
typedef CTypedPtrArray<CPtrArray, AcTcCatalog*> AcTcCatalogArray;
typedef CTypedPtrArray<CPtrArray, CAcTcUiToolPaletteSet*> AcTcUiToolPaletteSetArray;
typedef CTypedPtrArray<CPtrArray, CAcTcUiToolPalette*> AcTcUiToolPaletteArray;
typedef CTypedPtrArray<CPtrArray, CAcTcUiCatalogView*> AcTcUiCatalogViewArray;


#define ACTCUI_DRAGFORMAT_CUSTOM (0x1 << 0)
#define ACTCUI_DRAGFORMAT_IDROP (0x1 << 1)
#define ACTCUI_DRAGFORMAT_HDROP (0x1 << 2)

#define ACTCUI_CNPS_NOCREATEWINDOW (0x1 << 0)
#define ACTCUI_CNPS_NOADD (0x1 << 1)
#define ACTCUI_CNPS_CREATEHIDDEN (0x1 << 2)

#define CF_ACTC_CATALOG_ITEM_17_11 ACRX_T(/*MSGO*/ "CF_ACTC_CATALOG_ITEM_17_11")
#define CF_ACTCUI_CATALOG_ITEM_HEADER_17_11 ACRX_T(/*MSGO*/ "CF_ACTCUI_CATALOG_ITEM_HEADER_17_11")
#define CF_ACTC_CATALOG_ITEM_17_1 ACRX_T(/*MSGO*/ "CF_ACTC_CATALOG_ITEM_17_1")
#define CF_ACTCUI_CATALOG_ITEM_HEADER_17_1 ACRX_T(/*MSGO*/ "CF_ACTCUI_CATALOG_ITEM_HEADER_17_1")
#define CF_ACTC_CATALOG_ITEM_16_1 ACRX_T(/*MSGO*/ "CF_ACTC_CATALOG_ITEM_16_1")
#define CF_ACTCUI_CATALOG_ITEM_HEADER_16_1 ACRX_T(/*MSGO*/ "CF_ACTCUI_CATALOG_ITEM_HEADER_16_1")
#define CF_ACTCUI_CATALOG_ITEM ACRX_T(/*MSGO*/ "CF_ACTC_CATALOG_ITEM")
#define CF_ACTCUI_CATALOG_ITEM_HEADER ACRX_T(/*MSGO*/ "CF_ACTCUI_CATALOG_ITEM_HEADER")
#define CF_IDROP_ACTCUI_TOOL ACRX_T(/*MSGO*/ "CF_IDROP.XML_ACTCUI_TOOL")
#define CF_IDROP_ACTCUI_PALETTE ACRX_T(/*MSGO*/ "CF_IDROP.XML_ACTCUI_PALETTE")
#define CF_IDROP_ACTCUI_PACKAGE ACRX_T(/*MSGO*/ "CF_IDROP.XML_ACTCUI_PACKAGE")
#define CF_IDROP_ACTCUI_CATEGORY ACRX_T(/*MSGO*/ "CF_IDROP.XML_ACTCUI_CATEGORY")
#define CF_IDROP_ACTCUI_CATALOG ACRX_T(/*MSGO*/ "CF_IDROP.XML_ACTCUI_CATALOG")
#define CF_IDROP_ACTCUI_STOCKTOOL ACRX_T(/*MSGO*/ "CF_IDROP.XML_ACTCUI_STOCKTOOL")
#define CF_ACTCUI_TOOLBAR_ITEM ACRX_T(/*MSGO*/ "CF_ACTCUI_TOOLBAR_ITEM")

#define ACTCUI_PI_SHOW_PROGRESS (0x1 << 0)
#define ACTCUI_PI_USE_NEW_IDS (0x1 << 1)
#define ACTCUI_PI_BREAK_SOURCE_LINK (0x1 << 2)
#define ACTCUI_PI_NOTIFY_TOOLS (0x1 << 3)

struct ACTCUI_DRAG_HEADER
{
	DWORD mdwDragFormat;
	CLIPFORMAT mcfClipFormat;
	BOOL mbAutoCADSource;
	DWORD mdwSourceProcessId;
	GUID mRootId;
	GUID mParentId;
	BOOL mbReadOnlySource;
	int mnCount;
	int mnStockTools;
	DWORD mdwItemTypes;
};

ACTCUI_PORT void AcTcUiInitialize();
ACTCUI_PORT CAcTcUiManager* AcTcUiGetManager(void);

ACTCUI_PORT BOOL AcTcUiCopyItems(COleDataSource* pDataSource, const AcTcCatalogItemArray* pItems,
								 BOOL bAutoCADSource);
ACTCUI_PORT BOOL AcTcUiGetDragInfo(IDataObject* pDataObject, ACTCUI_DRAG_HEADER* pHeader);
ACTCUI_PORT BOOL AcTcUiPasteItems(IDataObject* pDataObject, AcTcCatalogItemArray* pItems,
								  AcTcCatalogItemArray* pStockTools,
								  DWORD dwFlag = ACTCUI_PI_SHOW_PROGRESS);
ACTCUI_PORT CAcTcUiToolPaletteSet* AcTcUiGetToolPaletteWindow(void);
ACTCUI_PORT BOOL AcTcUiFilterShapesDialog(AcTcCatalogItem* pPackage,
										  AcTcCatalogItemArray* pActiveShapes,
										  AcTcTool*& pCurrentShape, CWnd* pParentWnd);

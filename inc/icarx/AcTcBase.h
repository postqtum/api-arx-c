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

#include "../AdAChar.h"

#ifdef _ACTC_BUILD
#	define ACTC_PORT __declspec(dllexport)
#else
#	define ACTC_PORT
#endif

#define ACTC_IMAGE_NORMAL (0x1 << 0)
#define ACTC_IMAGE_SELECTED (0x1 << 1)
#define ACTC_IMAGE_HALO (0x1 << 2)
#define ACTC_IMAGE_SHADOW (0x1 << 3)

#define ACTC_MAX_CATALOG_ITEM_NAME 256
#define ACTC_MAX_CATALOG_ITEM_DESCRIPTION 2048
#define ACTC_MAX_CATALOG_ITEM_KEYWORDS 1024
#define ACTC_MAX_CATALOG_ITEM_TOOLTIP_TEXT 1024
#define ACTC_MAX_CATALOG_ITEM_LINK_NAME 256
#define ACTC_MAX_SCHEME_NAME 256
#define ACTC_MAX_TOOL_NAME ACTC_MAX_CATALOG_ITEM_NAME
#define ACTC_MAX_STOCKTOOL_NAME ACTC_MAX_CATALOG_ITEM_NAME
#define ACTC_MAX_PALETTE_NAME ACTC_MAX_CATALOG_ITEM_NAME
#define ACTC_MAX_PACKAGE_NAME ACTC_MAX_CATALOG_ITEM_NAME
#define ACTC_MAX_CATEGORY_NAME ACTC_MAX_CATALOG_ITEM_NAME
#define ACTC_MAX_CATALOG_NAME ACTC_MAX_CATALOG_ITEM_NAME
#define ACTC_MAX_URL 1024
#define ACTC_MAX_PATH MAX_PATH
#define ACTC_MAX_COMMAND_NAME 256
#define ACTC_MAX_COMMAND_ARGS 1024
#define ACTC_MAX_HELPINFO_FILE ACTC_MAX_URL
#define ACTC_MAX_HELPINFO_COMMAND 256
#define ACTC_MAX_HELPINFO_DATA ACTC_MAX_URL
#define ACTC_MAX_PARENT_DOCUMENT_NAME 256
#define ACTC_MAX_PUBLISHER_NAME 256
#define ACTC_MAX_PRODUCT_NAME 256
#define ACTC_MAX_LOCALE 512

#define ACTC_POSTDOWNLOADCMD_EXECUTE ACRX_T(/*MSGO*/ "Execute")

#define ACTC_DEFAULTDIR_IMAGE ACRX_T(/*MSGO*/ "Images")
#define ACTC_DEFAULTFILE_IMAGE ACRX_T(/*MSGO*/ "Image")

namespace AcTc
{

enum AccessRight
{
	kAccessRead = (0x1 << 0),
	kAccessReadWrite = (0x1 << 1),
	kAccessReadOnlyFile = (0x1 << 2),
	kAccessMultiple = (0x1 << 3),
	kAccessNewerVersion = (0x1 << 4),
};

enum CatalogItemType
{
	kItemUnknown = 0,
	kItemTool = (0x1 << 0),
	kItemPackage = (0x1 << 1),
	kItemPalette = (0x1 << 2),
	kItemCategory = (0x1 << 3),
	kItemCatalog = (0x1 << 4),
	kItemStockTool = (0x1 << 5),
};

enum ReferencePath
{
	kLoadRefPath = 1,
	kSaveRefPath = 2,
};

enum ImageType
{
	kImageTypeUninitialized = -1,
	kImageTypeBitmap = 1,
	kImageTypeMetaFile = 2,
	kImageTypeIcon = 3,
	kImageTypeEnhMetaFile = 4,
	kImageTypeJpeg = 5,
	kImageTypePng = 6,
	kImageTypeGif = 7,
	kImageTypeTif = 8
};

enum ImageOption
{
	kImageOptionNone = 0x0,
	kImageOptionRenderBitmapOpaque = (0x1 << 0),
	kImageOptionUserOverride = (0x1 << 1),
};

enum LoadOption
{
	kLoadLinks = (0x1 << 0),
	kLoadImages = (0x1 << 1),
	kLoadOverlayImages = (0x1 << 2),
	kDoNotNotifyReactor = (0x1 << 3),
};

enum SaveOption
{
	kSaveLinksAsLinks = (0x1 << 0),
	kSaveLinksAsEmbedded = (0x1 << 1),
	kSaveImages = (0x1 << 2),
	kSaveAs = (0x1 << 3),
	kSaveOverlayImages = (0x1 << 4),
	kSaveAnsi = (0x1 << 5),
};

enum DownloadOption
{
	kDownloadItem = (0x1 << 0),
	kDownloadLinkedItem = (0x1 << 1),
	kDownloadImage = (0x1 << 2),
	kDownloadStockTool = (0x1 << 3),
	kDownloadChildren = (0x1 << 4),
	kDownloadAll = kDownloadItem | kDownloadLinkedItem | kDownloadImage | kDownloadStockTool |
				   kDownloadChildren,
	kDownloadCleanDownloadDir = (0x1 << 5),
	kDownloadShowProgress = (0x1 << 6),
	kDownloadUseNewIds = (0x1 << 7),
	kDownloadNotifyTool = (0x1 << 12)
};

enum RefreshOption
{
	kRefreshItem = kDownloadItem,
	kRefreshLinkedItem = kDownloadLinkedItem,
	kRefreshImage = kDownloadImage,
	kRefreshStockTool = kDownloadStockTool,
	kRefreshChildren = kDownloadChildren,
	kRefreshAll = kDownloadAll,
	kRefreshShowProgress = kDownloadShowProgress,
	kRefreshNotifyTool = (0x1 << 16)
};

enum CatalogType
{
	kCatalog = (0x1 << 0),
	kStockToolCatalog = (0x1 << 1),
	kShapeCatalog = (0x1 << 2)
};

enum ToolType
{
	kToolNormal = 1,
	kToolFlyout = 2,
	kToolText = 3,
	kToolSeparator = 4,
};

enum SortOption
{
	kSortByName = (0x1 << 0),
	kSortByStockTool = (0x1 << 1),
	kSortByCustom = (0x1 << 2),
	kAscending = (0x1 << 3),
	kDescending = (0x1 << 4),
};

enum ItemOption
{
	kItemOptionNone = 0x0,
	kItemOptionSupportsAutoImage = (0x1 << 0),
	kItemOptionSupportsUserImage = (0x1 << 1),
	kItemOptionMenuUpdateImage = (0x1 << 2),
	kItemOptionMenuSetImage = (0x1 << 3),
	kItemOptionMenuRemoveImage = (0x1 << 4),
};

};	// namespace AcTc

#include "IcArxPackPush.h"

struct ACTC_IMAGE_INFO
{
	SIZE mSize;
	ACHAR mszResourceName[MAX_PATH];
	ACHAR mszSourceFile[MAX_PATH];
};

struct ACTC_TARGET_PRODUCT_INFO
{
	ACHAR mszProductName[ACTC_MAX_PRODUCT_NAME];
	ACHAR mszLocaleIds[ACTC_MAX_LOCALE];
	DWORD mdwMinVersion;
	DWORD mdwMaxVersion;
};

#include "IcArxPackPop.h"

class AcTcManager;
class AcTcCatalogItem;

ACTC_PORT BOOL AcTcInitialize(void);
ACTC_PORT BOOL AcTcUninitialize(void);
ACTC_PORT AcTcManager* AcTcGetManager(void);
ACTC_PORT BOOL AcTcDownloadItem(LPCTSTR pszUrl, AcTcCatalogItem*& pNewItem, DWORD dwItemTypes = -1,
								DWORD dwDownloadFlag = AcTc::kDownloadAll,
								LPCTSTR pszDownloadPath = nullptr);
ACTC_PORT int AcTcDownloadItem(LPTSTR* pUrls, int nNumUrls, AcTcCatalogItem** pItems,
							   DWORD dwItemTypes = -1, DWORD dwDownloadFlag = AcTc::kDownloadAll,
							   LPCTSTR pszDownloadPath = nullptr);
ACTC_PORT BOOL AcTcRefreshItem(AcTcCatalogItem** pItems, int nNumItems, DWORD dwItemTypes = -1,
							   DWORD dwRefreshFlag = AcTc::kRefreshAll);
ACTC_PORT BOOL AcTcSort(AcTcCatalogItem** pItems, int nNumItems, int nSortOption);
ACTC_PORT BOOL AcTcSetHostInfo(long lCurrentMajorVersion, long lCurrentMinorVersion, bool bBldEnv);

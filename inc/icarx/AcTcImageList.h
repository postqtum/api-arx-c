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
***     Description: Declaration of AcTcImageList class
***
*****************************************************************************/
#pragma once

#include "AcTcBase.h"

#include "IcArxPackPush.h"

class ACTC_PORT AcTcImageList
{
	friend class AcTcImpCatalogItem;

public:
	virtual ~AcTcImageList();

	AcTcImageList& operator=(const AcTcImageList& acTcImageList);
	INT_PTR GetImageCount(void) const;
	BOOL GetImageInfo(INT_PTR iIndex, ACTC_IMAGE_INFO* pImageInfo,
					  BOOL bUseDarkTheme = FALSE) const;
	BOOL GetEditImageInfo(INT_PTR iIndex, ACTC_IMAGE_INFO* pImageInfo, BOOL bUseDarkTheme = FALSE);
	BOOL SetImageInfo(INT_PTR iIndex, const ACTC_IMAGE_INFO* pImageInfo,
					  BOOL bUseDarkTheme = FALSE);
	AcTcImage* GetImage(INT_PTR iIndex, BOOL bUseDarkTheme = FALSE);
	INT_PTR SetImage(INT_PTR iIndex, const AcTcImage* pImage, BOOL bUseDarkTheme = FALSE);
	INT_PTR Add(const AcTcImage* pImage, BOOL bUseDarkTheme = FALSE);
	INT_PTR Add(const ACTC_IMAGE_INFO* pImageInfo);
	INT_PTR UpdateImage(const AcTcImage* pImage, BOOL bUseDarkTheme = FALSE);
	BOOL Delete(INT_PTR iIndex);
	BOOL DeleteAllImages(void);
	BOOL LoadImage(INT_PTR iIndex, BOOL bUseDarkTheme = FALSE);
	INT_PTR GetImageIndex(const SIZE* pSize, BOOL bExactMatch = FALSE, BOOL bUseDarkTheme = FALSE);
	AcTc::ImageOption GetOption(void) const;
	BOOL SetOption(AcTc::ImageOption nOption);

protected:
	AcTcImageList(AcTcCatalogItem* pCatalogItem);
	void* mpImpObj;

private:
	friend class AcTcSystemInternals;
};

#include "IcArxPackPop.h"

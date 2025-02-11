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
***     Description: Declaration of AcTcImage class
***
*****************************************************************************/
#pragma once

#include "AcTcBase.h"

#include "IcArxPackPush.h"

class ACTC_PORT AcTcImage
{
public:
	AcTcImage();
	AcTcImage(const AcTcImage& srcImage);
	virtual ~AcTcImage();

	AcTcImage& operator=(const AcTcImage& acTcImage);
	BOOL Load(LPCTSTR pszFile);
	BOOL Load(HBITMAP hBitmap);
	BOOL Load(IStream* pStream);
	BOOL Save(LPCTSTR pszFile);
	BOOL Save(LPCTSTR sFileName, AcTc::ImageType nSaveAsType);
	BOOL Save(IStream* pStream);
	BOOL Render(HDC hDC, int xPos, int yPos, int nWidth, int nHeight,
				UINT nStyle = ACTC_IMAGE_NORMAL, BOOL bTransparentBitmap = TRUE);
	BOOL GetSize(LPSIZE pSize) const;
	AcTc::ImageType GetType(void) const;
	BOOL IsImageLoaded(void) const;
	BOOL GetHICON(HICON& hIcon);
	BOOL GetHBITMAP(COLORREF cBackGroundColor, HBITMAP& hBitmap);
	AcTc::ImageType GetSaveType(void) const;
	BOOL SetSaveType(AcTc::ImageType nSaveType);
	BOOL ConvertTo(AcTc::ImageType nToImageType, BOOL bTransparent);
	BOOL IsForDarkTheme(void) const;
	void SetIsForDarkTheme(BOOL bValue);

protected:
	void* mpImpObj;

private:
	friend class AcTcSystemInternals;
};

#include "IcArxPackPop.h"

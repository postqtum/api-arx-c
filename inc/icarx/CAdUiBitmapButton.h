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
***     Description: Declaration of CAdUiBitmapButton class
***
*****************************************************************************/
#pragma once

#include "CAdUiOwnerDrawButton.h"

#include "IcArxPackPush.h"

class ADUI_PORT CAdUiBitmapButton : public CAdUiOwnerDrawButton
{
	friend class CAdUiImpBitmapButton;

	DECLARE_DYNAMIC(CAdUiBitmapButton)

public:
	enum Constants
	{
		ThemedSize = 24
	};
	enum ImageDrawStyle
	{
		kImageDrawStyle_Default = 0,
		kImageDrawStyle_Static = 1,
		kImageDrawStyle_Center = 2,
		kImageDrawStyle_Stretch_BtnSize = 3
	};

protected:
	enum ImageType
	{
		kImageType_Undefined,
		kImageType_Bitmap,
		kImageType_Icon,
		kImageType_RCDATA
	};
	BOOL m_bAutoSizeToBitmap = false;
	CBitmap m_bmp;
	void* m_image = nullptr;
	CString m_bmpResId;
	int m_bmpHeight = 0;
	int m_bmpWidth = 0;
	int m_bmpX = 0;
	int m_bmpY = 0;
	int m_focusRectOffset = 0;
	BOOL m_isThemed = false;
	BOOL m_enableThemedHoverState = false;
	BOOL m_enableThemedClickState = false;
	AdUiThemeElement m_backgroundElement = AdUiThemeElement::kUnknownElements;
	CAdUiBitmapButton::ImageType m_imageType = ImageType::kImageType_Undefined;
	CAdUiBitmapButton::ImageDrawStyle m_imageDrawStyle = ImageDrawStyle::kImageDrawStyle_Default;

protected:
	void CalcBitmapSize();
	void ClearImages(bool bClearResId = false);
	void DrawButton(CDC& dc, int w, int h, BOOL isDefault, BOOL isDisabled, BOOL isSelected,
					BOOL isFocused);
	virtual void DrawButtonImage(CDC* pDC, const CRect& rect, BOOL isSelected, BOOL isDisabled);
	virtual void DrawFocusMark(CDC* pDC, CRect& rect, BOOL isDefault, BOOL isSelected,
							   BOOL isFocused);
	virtual void DrawThemedButton(CDC& dc, int x, int y, int width, int height, int statusId);
	BOOL LoadBitmapResource(LPCTSTR strResId, CBitmap& bmp, HINSTANCE hInst = nullptr);
	BOOL LoadIconResource(LPCTSTR strResId, HINSTANCE hInst = nullptr);
	BOOL LoadRCDATAResource(LPCTSTR strResId, HINSTANCE hInst = nullptr);
	BOOL OnAutoLoad();
	virtual BOOL OnLoadBitmap(LPCTSTR strResId);
	BOOL OnReload(LPCTSTR strResId);
	void SaveAndCalcSize(LPCTSTR strResId, CAdUiBitmapButton::ImageType type);
	void ThemeModified(AdUiThemeElement element);

	DECLARE_MESSAGE_MAP()

public:
	CAdUiBitmapButton();
	~CAdUiBitmapButton();
	virtual void EnableThemedState(BOOL bEnableHover, BOOL bEnableClick);
	BOOL GetAutoSizeToBitmap();
	CAdUiBitmapButton::ImageDrawStyle GetImageDrawStyle() const;
	virtual BOOL IsThemed() const;
	BOOL LoadBitmap(LPCTSTR strResId);
	void SetAutoSizeToBitmap(BOOL autoSizeToBitmap);
	bool SetBitmapOffsets(int nBorderOffset, int nFocusRectOffset);
	void SetImageDrawStyle(CAdUiBitmapButton::ImageDrawStyle style);
	virtual void SetIsThemed(BOOL isThemed);
	CAdUiTheme* SetTheme(CAdUiTheme * pTheme);
	virtual void SetThemeBackground(AdUiThemeElement nElement);
	void SizeToBitmap();
};

#include "IcArxPackPop.h"

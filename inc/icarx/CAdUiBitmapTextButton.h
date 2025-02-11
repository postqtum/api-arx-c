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
***     Description: Declaration of CAdUiBitmapTextButton class
***
*****************************************************************************/
#pragma once

#include "CAdUiBitmapButton.h"

#include "IcArxPackPush.h"

class ADUI_PORT CAdUiBitmapTextButton : public CAdUiBitmapButton
{
	friend class CAdUiImpBitmapButton;
	DECLARE_DYNAMIC(CAdUiBitmapTextButton)

public:
	enum ButtonType
	{
		kBitmap = 0x1,
		kText = 0x2
	};
	enum BitmapLocation
	{
		kLeft = 0x1,
		kTop = 0x2,
		kRight = 0x4,
		kBottom = 0x8
	};
	enum ButtonStyle
	{
		kButtonStyleNone = 0,
		kButtonStyleFlat = 0x1,
		kButtonStyleCheck = 0x2,
		kButtonHCenter = 0x300,
		kButtonVCenter = 0xC00
	};

private:
	void* mpImpObj = nullptr;

protected:
	void DrawButton(CDC& dc, int w, int h, BOOL isDefault, BOOL isDisabled, BOOL isSelected,
					BOOL isFocused);
	BOOL OnAutoLoad();
	BOOL OnLoadBitmap(LPCTSTR strResId);
	BOOL OnReload(LPCTSTR strResId);

	DECLARE_MESSAGE_MAP()

public:
	CAdUiBitmapTextButton();
	~CAdUiBitmapTextButton();
	BOOL GetAutoSizeToBitmap();
	BOOL GetAutoSizeToContent();
	HBITMAP GetBitmap() const;
	UINT GetBitmapLocation();
	CAdUiBitmapTextButton::ButtonStyle GetBitmapTextButtonStyle() const;
	UINT GetButtonType();
	int GetCheck();
	HICON GetIcon() const;
	void SetAutoSizeToBitmap(BOOL autoSizeToBitmap);
	void SetAutoSizeToContent(BOOL autoSizeToContent);
	HBITMAP SetBitmap(HBITMAP hBitmap, BOOL bRedraw = TRUE);
	UINT SetBitmapLocation(UINT imgPos);
	void SetBitmapOffsets(int nBorderOffset, int nFocusRectOffset);
	void SetBitmapTextButtonStyle(CAdUiBitmapTextButton::ButtonStyle nBtnStyle);
	void SetBkColor(COLORREF);
	void SetBorderColor(COLORREF);
	UINT SetButtonType(UINT btnType);
	void SetCheck(int nCheck);
	void SetContentOffsets(int nBorderOffset, int nFocusRectOffset);
	HICON SetIcon(HICON hIcon, BOOL bRedraw = TRUE);
	void SizeToBitmap();
	void SizeToContent();
};

#include "IcArxPackPop.h"

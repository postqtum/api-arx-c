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
***     Description: Declaration of CAdUiImage class
***
*****************************************************************************/
#pragma once

#ifndef _WINDOWS_
#	include <afxwin.h>
#	include <afxext.h>
#endif

#pragma push_macro("new")
#undef new
#include <minmax.h>
#include <gdiplus.h>
#undef min
#undef max
#pragma pop_macro("new")

#include <WinDef.h>

#include "../aduiTheme.h"

#include "IcArxPackPush.h"

class ADUI_PORT CAdUiImage
{
protected:
	Gdiplus::Bitmap* m_pBitmap = nullptr;
	bool m_bIsThemed = false;
	const CAdUiTheme* m_pTheme = nullptr;
	CString m_name;

private:
	static unsigned int g_instanceCount;
	static Gdiplus::GdiplusStartupInput g_gdiplusStartupInput;
	static ULONG_PTR g_gdiplusToken;

private:
	CAdUiImage(const CAdUiImage& image);
	void clear();
	void commonCtr(bool bIsThemed);
	void drawImage(CDC* pDC, int x, int y, int width, int height, int srcx, int srcy, int srcwidth,
				   int srcheight, bool isDisabled);
	CAdUiImage& operator=(const CAdUiImage& image);

protected:
	static bool IsCurrentPaletteThemeDark();
	bool IsThemeDark() const;

public:
	CAdUiImage(bool bIsThemed = false);
	CAdUiImage(LPCWSTR pFile, bool bIsThemed = false);
	CAdUiImage(HBITMAP hbmp, Gdiplus::PixelFormat format);
	virtual ~CAdUiImage();
	bool DrawImage(CDC* pDC, int x, int y, bool isDisabled = false);
	bool DrawImage(CDC* pDC, int x, int y, int width, int height, bool isDisabled = false);
	bool DrawImage(CDC* pDC, int x, int y, int srcx, int srcy, int srcwidth, int srcheight,
				   bool isDisabled = false);
	bool DrawImage(CDC* pDC, int x, int y, int width, int height, int srcx, int srcy, int srcwidth,
				   int srcheight, bool isDisabled = false);
	virtual void Empty();
	Gdiplus::Bitmap* GetBitmap() const { return m_pBitmap; }
	unsigned int GetHeight() const;
	static CString GetThemedFileName(LPCTSTR pName, const CAdUiTheme* pTheme = nullptr);
	unsigned int GetWidth() const;
	bool IsThemed() { return m_bIsThemed; }
	bool Load(LPCWSTR pFile);
	virtual bool Reload();
	void SetBitmap(Gdiplus::Bitmap* pBitmap);
	void SetIsThemed(bool bIsThemed) { m_bIsThemed = bIsThemed; }
	void SetTheme(const CAdUiTheme* theme);
};

#include "IcArxPackPop.h"

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
***     Description: Declaration of CAcUiArrowHeadComboBox class
***
*****************************************************************************/
#pragma once

#include "CAcUiMRUComboBox.h"
#include <vector>
#include <memory>

namespace Gdiplus
{
class Bitmap;
}

#include "IcArxPackPush.h"

class ACUI_PORT CAcUiArrowHeadComboBox : public CAcUiMRUComboBox
{
public:
	CAcUiArrowHeadComboBox();
	~CAcUiArrowHeadComboBox();

protected:
	void DrawItemImage(CDC& dc, CRect& r, INT_PTR cargo) override;
	int CalcItemHeight() override;
	BOOL GetOtherName(BOOL isOther2, CString& name) override;
	int ImageWidth() override;
	void OnAddItems() override;

	virtual bool LoadImages();

public:
	BOOL GetUseOrigin2();
	void SetUseOrigin2(BOOL use);

private:
	std::vector<std::unique_ptr<Gdiplus::Bitmap>> m_pArrowImages;
	int m_arrowCount;
	int m_arrowSize;
	BOOL m_bUseOrigin2;
	BOOL m_bThemedArrowImagesLoaded;

public:
	int AddArrowHeadToMRU(LPCTSTR name);
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) override;

protected:
	DECLARE_MESSAGE_MAP()
};

#include "IcArxPackPop.h"

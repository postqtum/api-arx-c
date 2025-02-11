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
***     Description: Declaration of CAcUiColorComboBox class
***
*****************************************************************************/
#pragma once

#include "CAcUiMRUComboBox.h"


#include "IcArxPackPush.h"

class AcCmColor;

class CAcIcadColorComboBoxBase;

class ACUI_PORT CAcUiColorComboBox
		: public CAcUiMRUComboBox
{
protected:
	int m_blockColorIndex = -1;
	CAcIcadColorComboBoxBase* m_pImp = nullptr;

protected:
	void DrawItemImage(CDC& dc, CRect& r, INT_PTR cargo) override;
	virtual BOOL GetOtherColorIndex(int defaultColorIndex, int layerColorIndex,
									BOOL enableMetaColors, int& colorIndex);
	BOOL GetOtherName(BOOL isOther2, CString& name);
	virtual BOOL GetWindowsColor(COLORREF& color);
	void OnAddItems() override;
	BOOL OnSelectOther(BOOL isOther2, int curSel, int& newSel);
	void RGBFill(CDC& dc, CRect& rFill);

	DECLARE_MESSAGE_MAP()

public:
	CAcUiColorComboBox();
	CAcUiColorComboBox(bool useDbcolors);
	~CAcUiColorComboBox();
	void AddColor(const AcCmColor& aCol);
	int AddColorToMRU(int colorIndex);
	int FindItemByColorIndex(int colorIndex);
	int GetBlockColorIndex();
	virtual COLORREF GetColorFromIndex(int colorIndex);
	virtual int GetColorIndex(COLORREF color);
	int GetCurrentItemColorIndex();
	virtual int GetCurrentLayerColorIndex();
	int GetItemColorIndex(int item);
	void Initialize();
	virtual COLORREF LookupColor(int colorIndex, LOGPALETTE* logPalette);
	void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	afx_msg BOOL OnSelchange();
	void PreSubclassWindow();
	void SetBlockColorIndex(int colorIndex);
	void SetSelectedColor(const AcCmColor& aColor);
};

#include "IcArxPackPop.h"

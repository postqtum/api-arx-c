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
***     Description: Declaration of CAcUiTrueColorComboBox class
***
*****************************************************************************/
#pragma once

#include "CAcUiMRUComboBox.h"

#include "AcCmColor.h"

#define ACUI_MAX_TRUECOLOR_COMBOBOX_MRU 16
#define ACUI_TRUECOLOR_COMBOBOX_TABLE_SIZE ACUI_MAX_TRUECOLOR_COMBOBOX_MRU + 9

#include "IcArxPackPush.h"

class CAcIcadColorComboBoxBase;

class ACUI_PORT CAcUiTrueColorComboBox
		: public CAcUiMRUComboBox
{
public:
	enum ColorTableIndex
	{
		kCargoOption1 = 0,
		kCargoOption2 = 1,
		kCargoStockItem1 = 2,
		kCargoStockItem2 = 3,
		kCargoStockItem3 = 4,
		kCargoStockItem4 = 5,
		kCargoStockItem5 = 6,
		kCargoStockItem6 = 7,
		kCargoStockItem7 = 8,
		kIndexOfFirstMRUItem = 9,
		kCargoOther1 = -1,
		kCargoOther2 = -2,
		kLastIndex = ACUI_TRUECOLOR_COMBOBOX_TABLE_SIZE - 1
	};

	CAcUiTrueColorComboBox();
	CAcUiTrueColorComboBox(bool useDbcolors, bool forceDWGmode = false);
	~CAcUiTrueColorComboBox();
	void setColorOptions(int opt);
	int getColorOptions();

	void Initialize();

	afx_msg BOOL OnSelchange();

	void SetSelectedColor(const AcCmColor& aColor);
	void SetByLayerColor(const AcCmColor& aColor);
	void AddColor(const AcCmColor& aCol);

	void AddItems();
	int AddItemToList(LPCTSTR name, int index, INT_PTR cargo);
	int AddItemToMRU(LPCTSTR name, int cargo);
	int AddColorToMRU(const AcCmColor& color);

	int FindItemByColor(const AcCmColor& color);
	void GetCurrentItemColor(AcCmColor& color);
	COLORREF getColorByCargo(int cargo);

	const AcCmColor& GetBlockColor();
	void SetBlockColor(const AcCmColor& color);

	virtual COLORREF GetColorFromIndex(int colorIndex);
	COLORREF getColorData(AcCmColor color);
	int GetColorIndex(COLORREF color);

	void SetSupportColorBook(BOOL newVal);
	BOOL GetSupportColorBook();

	void setUseCurrentInsteadNone(const bool val) /* override*/;

protected:
	CAcIcadColorComboBoxBase* m_pImp;
	int m_cargoOther1;
	int m_cargoOther2;
	AcCmColor m_blockColor;

	void DrawItemImage(CDC& dc, CRect& r, INT_PTR cargo) override;
	void OnAddItems() override;

	BOOL OnSelectOther(BOOL isOther2, int curSel, int& newSel) override;
	BOOL GetOtherColor(AcCmColor& defaultColor, const AcCmColor& layerColor, BOOL enableMetaColors);
	BOOL GetWindowsColor(AcCmColor& color);
	BOOL GetOtherName(BOOL isOther2, CString& name) override;

	AcCmColor* m_AcCmColorTable[ACUI_TRUECOLOR_COMBOBOX_TABLE_SIZE];
	int m_nextAcCmColorTableIndex;

	void initAcCmColorTable(void);

	void RGBFill(CDC& dc, CRect& rFill);

	bool GetCurrentLayerColor(AcCmColor& color);

	virtual COLORREF LookupColor(int colorIndex, LOGPALETTE* logPalette);

	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);

	void PreSubclassWindow() override;
	void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct) override;

protected:
	int CComboBox_AddString(LPCTSTR lpszString) /* override */;
	void CComboBox_ResetContent() /* override */;
	int CComboBox_FindStringExact(int nIndexStart, LPCTSTR lpszFind) const /* override */;
	int CComboBox_InsertString(int nIndex, LPCTSTR lpszString) /* override */;
	int CComboBox_GetCount() const /* override */;
	int CComboBox_SetItemData(int nIndex, DWORD_PTR dwItemData) /* override */;
	DWORD_PTR CComboBox_GetItemData(int nIndex) const /* override */;
	int CComboBox_SetCurSel(int nSelect) /* override */;
	int CComboBox_GetCurSel() const /* override */;
	int CComboBox_DeleteString(UINT nIndex) /* override */;
	int CComboBox_GetLBTextLen(int nIndex) const /* override */;
	void CComboBox_GetLBText(int nIndex, LPTSTR lpszString) const /* override */;
	void CComboBox_GetLBText(int nIndex, CString& csString) const /* override */;

	DECLARE_MESSAGE_MAP()
};

#include "IcArxPackPop.h"

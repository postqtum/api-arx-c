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
***     Description: Declaration of CAcUiMRUComboBox class
***
*****************************************************************************/
#pragma once

#include "CAcUiComboBox.h"

#define ACUI_MAX_COMBOBOX_MRU 6

#include "IcArxPackPush.h"

class ACUI_PORT CAcUiMRUComboBox : public CAcUiComboBox
{
public:
	CAcUiMRUComboBox();
	~CAcUiMRUComboBox();

	void GetContentExtent(LPCTSTR text, int& width, int& height) override;
	virtual BOOL GetItemColors(DRAWITEMSTRUCT& dis, COLORREF& fgColor, COLORREF& bgColor,
							   COLORREF& fillColor);

protected:
	BOOL OnGetTipRect(CRect& r) override;

protected:
	bool m_bIsDynamicCreation : 1;
	bool m_bUseOption1 : 1;
	bool m_bUseOption2 : 1;
	bool m_bUseOther1 : 1;
	bool m_bUseOther2 : 1;
	bool m_bOther1Selected : 1;
	bool m_bOther2Selected : 1;
	int m_cargoOption1;
	int m_cargoOption2;
	LOGPALETTE* m_logPalette;
	HPALETTE m_hPalette;
	CPalette* m_pOldPalette;
	int m_itemHeight;
	int m_lastSelection;
	int m_mruCargo[ACUI_MAX_COMBOBOX_MRU];
	int m_mruLen;
	CString m_mruName[ACUI_MAX_COMBOBOX_MRU];

	virtual int CalcItemHeight();

	virtual void DrawItemImage(CDC& dc, CRect& r, INT_PTR cargo);
	void DrawItemImageFromCargo(CDC* dc, CRect& r, int i);
	void DrawTextAndFocusRect(LPDRAWITEMSTRUCT lpDrawItemStruct, CDC* dc, CRect& rItem, int i,
							  COLORREF& fgColor, COLORREF& bgColor);
	void CreateAndSelectPalette(LPDRAWITEMSTRUCT lpDrawItemStruct, CDC* dc);
	void SetupForImageDraw(LPDRAWITEMSTRUCT lpDrawItemStruct, CDC* dc, CRect& rItem, CRect& rImage,
						   COLORREF& fgColor, COLORREF& bgColor);
	void ResetAndRestorePalette(CDC* dc, int savedState);

	BOOL FindCargoInMRU(int cargo);
	int GenerateCargoFromMRU(int seed);
	virtual BOOL GetOptionName(BOOL isOption2, CString& name);
	virtual BOOL GetOtherName(BOOL isOther2, CString& name);
	virtual void OnAddItems();
	virtual void OnComboBoxInit();
	virtual BOOL OnSelectOther(BOOL isOther2, int curSel, int& newSel);
	void SelectOther(BOOL isOther2);

public:
	int AddItemToList(LPCTSTR name, INT_PTR cargo);
	int AddItemToMRU(LPCTSTR name, int cargo);
	void AddItems();
	BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID) override;
	virtual int ExtraWidth();
	int FindItemByCargo(INT_PTR cargo);
	int GetCargoOption1();
	int GetCargoOption2();
	INT_PTR GetCurrentItemCargo();
	INT_PTR GetItemCargo(int item);
	LOGPALETTE* GetLogPalette();
	HPALETTE GetPalette();
	BOOL GetUseOption1();
	BOOL GetUseOption2();
	BOOL GetUseOther1();
	BOOL GetUseOther2();
	virtual int ImageWidth();
	int InsertItemInList(int index, LPCTSTR name, INT_PTR cargo);
	int ItemHeight();
	void RecalcHeight();
	void RemoveItemFromMRU(int cargo);
	void SetCargoOption1(int cargo);
	void SetCargoOption2(int cargo);
	void SetLastSelection(int sel);
	void SetLogPalette(LOGPALETTE* logPalette);
	void SetPalette(HPALETTE hPalette);
	void SetUseOption1(BOOL use);
	void SetUseOption2(BOOL use);
	void SetUseOther1(BOOL use);
	void SetUseOther2(BOOL use);

public:
	BOOL GetUseByBlock();
	BOOL GetUseByLayer();
	BOOL GetUseOther();
	BOOL GetUseWindows();
	void SetUseByBlock(BOOL use);
	void SetUseByLayer(BOOL use);
	void SetUseOther(BOOL use);
	void SetUseWindows(BOOL use);

public:
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) override;
	void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct) override;

protected:
	void PreSubclassWindow() override;
	LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam) override;

protected:
	BOOL m_bUseByBlock;
	BOOL m_bUseByLayer;
	BOOL m_bUseOther;
	BOOL m_bUseWindows;

	afx_msg BOOL OnCloseUp();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnDropDown();
	afx_msg BOOL OnSelEndOk();

	DECLARE_MESSAGE_MAP()
};

#include "IcArxPackPop.h"

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
***     Description: Declaration of CAcUiPlotStyleTablesComboBox class
***
*****************************************************************************/
#pragma once

#include "CAcUiMRUComboBox.h"

#include "IcArxPackPush.h"

class ACUI_PORT CAcUiPlotStyleTablesComboBox : public CAcUiMRUComboBox
{
public:
	CAcUiPlotStyleTablesComboBox();
	CAcUiPlotStyleTablesComboBox(BOOL bInitialize);
	~CAcUiPlotStyleTablesComboBox();
	void SetFileType(bool currentDrawing, bool named);
	int AddMissingStyleTable(LPCTSTR fullFileName, bool bMissing = true);
	bool IsMissing(int index);

	int ImageWidth() override;

	void GetLBText(int nIndex, CString& rString) const;

	int AddItemToList(LPCTSTR name, INT_PTR cargo);

protected:
	void DrawItemImage(CDC& dc, CRect& r, INT_PTR cargo) override;
	int CalcItemHeight() override;
	void OnAddItems() override;
	void OnComboBoxInit() override;

private:
	CBitmap m_plotStyleTablesBitmap;
	int m_plotStyleTableBitmapSize;
	BOOL m_bImageDisplayed;
	bool m_bCurrentDrawing;
	bool m_bNamed;
	BOOL m_bInitialize;

public:
	BOOL OnChildNotify(UINT, WPARAM, LPARAM, LRESULT*) override;

protected:
	afx_msg BOOL OnDropDown();

	DECLARE_MESSAGE_MAP()

private:
	BOOL AdjustDropDownListWidth();
};

#include "IcArxPackPop.h"

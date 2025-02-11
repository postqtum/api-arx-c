/***************************************************************************
***
***     Copyright (C) 2023 IntelliCAD Technology Consortium. All Rights Reserved.
***
***     Use of the information contained herein, in part or in whole,
***     in/as source code and/or in/as object code, in any way by anyone
***     other than authorized employees of The IntelliCAD Technology Consortium,
***     or by anyone to whom The IntelliCAD Technology Consortium  has not
***     granted use is illegal.
***
***     Description:
***
*****************************************************************************/
#pragma once
#include <inc/aduiDialog.h>
#include <inc/acuiComboBox.h>

class CAcUiPredefBlockComboBoxTest : public CAcUiPredefBlockComboBox
{
public:
	void testAddPredefBlockToMRU()
	{
		CString strs[] = {L"test", L"testName", L"testName1", L"testName11", L"1", L"2", L"3"};
		auto len = std::size(strs);
		for (int i = 0; i < len; i++) { AddPredefBlockToMRU(strs[i]); }
#if defined(DEBUG) || defined(_DEBUG)
		for (int i = 0; i < ACUI_MAX_COMBOBOX_MRU; i++)
		{
			ASSERT(strs[len - i - 1] == m_mruName[i]);
		}
#endif
	}
};

class CAdUiOwnerDrawButtonTest : public CAdUiOwnerDrawButton
{
public:
	void DrawTransparentBitmap(CDC& dc, CBitmap& bmp, int x, int y, int w, int h, BOOL isDisabled)
	{
		CAdUiOwnerDrawButton::DrawTransparentBitmap(dc, bmp, x, y, w, h, isDisabled);
	}
};

class CAdUiBitmapButtonTest : public CAdUiBitmapButton
{
public:

	CAdUiImage* GetCAdUiImage()
	{
		return static_cast<CAdUiImage*>(m_image);
	}

	BOOL LoadRCDATAResource(LPCTSTR strResId, HINSTANCE hInst)
	{
		return CAdUiBitmapButton::LoadRCDATAResource(strResId, hInst);
	}
	BOOL LoadIconResource(LPCTSTR strResId, HINSTANCE hInst)
	{
		return CAdUiBitmapButton::LoadIconResource(strResId, hInst);
	}
	BOOL OnAutoLoad()
	{
		return CAdUiBitmapButton::OnAutoLoad();
	}
};

class CAcUiMRUComboBoxDialogTest : public CAdUiDialog
{
	DECLARE_DYNAMIC(CAcUiMRUComboBoxDialogTest)
	CAcUiMRUComboBox m_comboBox;
	CAcUiLineTypeComboBox m_lineTypeComboBox;
	CAcUiColorComboBox m_colorComboBox;
	CAcUiTrueColorComboBox m_trueColorComboBox;
	CAcUiLineWeightComboBox m_lineWeightComboBox;
	CAcUiArrowHeadComboBox m_arrowHeadComboBox;
	CAcUiPlotStyleTablesComboBox m_plotStyleTablesComboBox;
	CAcUiPlotStyleNamesComboBox m_plotStyleNamesComboBox;
	CAcUiPredefBlockComboBoxTest m_predefBlockComboBox;
	CAdUiComboBox m_cAdUiComboBox;
	CAdUiEdit m_CAdUiEdit;
	CAdUiOwnerDrawButtonTest m_CAdUiOwnerDrawButton;
	CAdUiBitmapButtonTest m_CAdUiBitmapButton;
	CAdUiTrackButton m_CAdUiTrackButton;
	CAdUiBitmapTextButton m_CAdUiBitmapTextButton;

	enum
	{
		IDD = IDD_DIALOG_CAcUiMRUComboBox_Test,
	};

protected:
	BOOL OnInitDialog();

	void setNamedMode();
	void setColorMode();
	void drawTransparentBitmap();
	void drawLoadedCAdUiImage();
	void LoadRCDATAResource();
	void LoadIconResource();
	void LoadBitmapResource();
	void BitmapLocationkLeft();
	void BitmapLocationTop();
	void BitmapLocationRight();
	void BitmapLocationBottom();

public:
	CAcUiMRUComboBoxDialogTest(CWnd* pParent = nullptr)
	    : CAdUiDialog(IDD, pParent)
	{
	}
	virtual void DoDataExchange(CDataExchange* pDX);
	DECLARE_MESSAGE_MAP()
private:
	CBitmap m_bitmap;
	void LoadBmp();

public:
	afx_msg void OnBnClickedBtnother();

private:
	CButton m_chkOther;
};

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
#include "stdafx.h"
#include "CAcUiMRUComboBoxDialogTest.h"
#include <atlimage.h>
#include <functional>
#include <inc/aduiImage.h>


IMPLEMENT_DYNAMIC(CAcUiMRUComboBoxDialogTest, CAdUiDialog)

static const int nWidth = 32;
static const int nHeight = 32;

BOOL CAcUiMRUComboBoxDialogTest::OnInitDialog()
{
	auto res = CAdUiDialog::OnInitDialog();
	m_comboBox.AddItemToList(L"test0",0);
	m_comboBox.AddItemToList(L"test01", 0);
	m_comboBox.AddItemToList(L"test011", 0);
	m_comboBox.AddItemToList(L"test0111", 0);
	m_plotStyleTablesComboBox.AddMissingStyleTable(L"C:\\dev\\out.txt", false);
	m_plotStyleTablesComboBox.AddMissingStyleTable(L"C:\\dev\\in.txt");
	m_predefBlockComboBox.testAddPredefBlockToMRU();
	m_cAdUiComboBox.AddString(L"TestString0");
	m_cAdUiComboBox.AddString(L"TestString1");
	m_cAdUiComboBox.AddString(L"TestString2");
	m_cAdUiComboBox.SetToolTipText(L"toolTipText");
	LoadBmp();
	auto retVal = m_CAdUiBitmapButton.OnAutoLoad();
	m_CAdUiOwnerDrawButton.SetEnableFastDraw(TRUE);
	ASSERT(retVal);
	m_CAdUiBitmapTextButton.SetButtonType(3);
	return res;
}

void CAcUiMRUComboBoxDialogTest::setNamedMode()
{
	m_plotStyleNamesComboBox.SetNamedMode();
}

void CAcUiMRUComboBoxDialogTest::setColorMode()
{
	m_plotStyleNamesComboBox.SetColorDependentMode();
}

void CAcUiMRUComboBoxDialogTest::drawTransparentBitmap()
{
	CRect rect;
	m_CAdUiOwnerDrawButton.GetWindowRect(&rect);
	ScreenToClient(&rect);
	std::unique_ptr<CDC, std::function<void(CDC*)>> pDc(
	        GetDC(), [this](CDC* pDC) { ReleaseDC(pDC); });
	m_CAdUiOwnerDrawButton.DrawTransparentBitmap(
	        *pDc, m_bitmap, rect.right + 10, rect.top, nWidth, nHeight, FALSE);
}

void CAcUiMRUComboBoxDialogTest::drawLoadedCAdUiImage()
{

}

void CAcUiMRUComboBoxDialogTest::LoadRCDATAResource()
{
	auto hinst = AfxGetResourceHandle();
	auto retVal = m_CAdUiBitmapButton.LoadRCDATAResource(MAKEINTRESOURCE(IDB_TEST_ICON), hinst);
	ASSERT(!retVal);
	retVal = m_CAdUiBitmapButton.LoadRCDATAResource(MAKEINTRESOURCE(IDB_Transparent_Bitmap), hinst);
	ASSERT(retVal);
	retVal = m_CAdUiBitmapTextButton.Reload(MAKEINTRESOURCE(IDB_Transparent_Bitmap));
	ASSERT(retVal);
}

void CAcUiMRUComboBoxDialogTest::LoadIconResource()
{
	auto hinst = AfxGetResourceHandle();
	auto retVal =
	        m_CAdUiBitmapButton.LoadIconResource(MAKEINTRESOURCE(IDB_Transparent_Bitmap), hinst);
	ASSERT(!retVal);
	retVal = m_CAdUiBitmapButton.LoadIconResource(MAKEINTRESOURCE(IDB_TEST_ICON), hinst);
	ASSERT(retVal);
	m_CAdUiBitmapTextButton.Reload(MAKEINTRESOURCE(IDB_TEST_ICON));
}

void CAcUiMRUComboBoxDialogTest::LoadBitmapResource()
{
	auto retVal = m_CAdUiBitmapButton.LoadBitmap(L"IDB_TEST_CBITMAP_BITMAP");
	ASSERT(retVal);
	m_CAdUiBitmapTextButton.Reload(L"IDB_TEST_CBITMAP_BITMAP");
}

void CAcUiMRUComboBoxDialogTest::BitmapLocationkLeft()
{
	m_CAdUiBitmapTextButton.SetBitmapLocation(CAdUiBitmapTextButton::BitmapLocation::kLeft);
}

void CAcUiMRUComboBoxDialogTest::BitmapLocationTop()
{
	m_CAdUiBitmapTextButton.SetBitmapLocation(CAdUiBitmapTextButton::BitmapLocation::kTop);
}

void CAcUiMRUComboBoxDialogTest::BitmapLocationRight()
{
	m_CAdUiBitmapTextButton.SetBitmapLocation(CAdUiBitmapTextButton::BitmapLocation::kRight);
}

void CAcUiMRUComboBoxDialogTest::BitmapLocationBottom()
{
	m_CAdUiBitmapTextButton.SetBitmapLocation(CAdUiBitmapTextButton::BitmapLocation::kBottom);
}


void CAcUiMRUComboBoxDialogTest::DoDataExchange(CDataExchange* pDX)
{
	CAdUiDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDD_CAcUiMRUComboBox_Test, m_comboBox);
	DDX_Control(pDX, IDD_CAcUiLineTypeComboBox_Test, m_lineTypeComboBox);
	DDX_Control(pDX, IDD_CAcUiColorComboBox_Test, m_colorComboBox);
	DDX_Control(pDX, IDD_CAcUiTrueColorComboBox_Test, m_trueColorComboBox);
	DDX_Control(pDX, IDD_CAcUiLineWeightComboBox_Test, m_lineWeightComboBox);
	DDX_Control(pDX, IDD_CAcUiArrowHeadComboBox_Test, m_arrowHeadComboBox);
	DDX_Control(pDX, IDD_CCAcUiPlotStyleTablesComboBox_Test, m_plotStyleTablesComboBox);
	DDX_Control(pDX, IDD_CAcUiPlotStyleNamesComboBox_Test, m_plotStyleNamesComboBox);
	DDX_Control(pDX, IDD_CAcUiPredefBlockComboBox_Test, m_predefBlockComboBox);
	DDX_Control(pDX, IDD_CAdUiComboBox_Test, m_cAdUiComboBox);
	DDX_Control(pDX, IDC_CAdUiEdit, m_CAdUiEdit);
	DDX_Control(pDX, IDC_CAdUiOwnerDrawButton, m_CAdUiOwnerDrawButton);
	DDX_Control(pDX, IDC_CAdUiBitmapButton, m_CAdUiBitmapButton);
	DDX_Control(pDX, IDC_CAdUiTrackButton, m_CAdUiTrackButton);
	DDX_Control(pDX, IDC_CAdUiBitmapTextButton, m_CAdUiBitmapTextButton);
	DDX_Control(pDX, IDC_CHKOTHER2, m_chkOther);
}

void CAcUiMRUComboBoxDialogTest::LoadBmp()
{
	HRSRC hRes = ::FindResource(
	        AfxGetResourceHandle(), MAKEINTRESOURCE(IDB_Transparent_Bitmap), RT_RCDATA);
	if (hRes)
	{
		HGLOBAL hData = ::LoadResource(AfxGetResourceHandle(), hRes);
		if (hData)
		{
			LPVOID pData = ::LockResource(hData);
			if (pData)
			{
				m_bitmap.CreateBitmap(nWidth, nHeight, 1, 32, pData);
			}
		}
	}
}

void CAcUiMRUComboBoxDialogTest::OnBnClickedBtnother()
{
	CString strOtherName;
	class ProtectedAccessor : public CAcUiArrowHeadComboBox
	{
	public:
		using CAcUiArrowHeadComboBox::GetOtherName;
	};
	(m_arrowHeadComboBox.*&ProtectedAccessor::GetOtherName)(m_chkOther.GetCheck(), strOtherName);
	AfxMessageBox(strOtherName);
}

BEGIN_MESSAGE_MAP(CAcUiMRUComboBoxDialogTest, CAdUiDialog)
	ON_BN_CLICKED(IDC_Named_Mode, &CAcUiMRUComboBoxDialogTest::setNamedMode)
	ON_BN_CLICKED(IDC_Color_Mode, &CAcUiMRUComboBoxDialogTest::setColorMode)
	ON_BN_CLICKED(IDC_CAdUiOwnerDrawButton, &CAcUiMRUComboBoxDialogTest::drawTransparentBitmap)
	ON_BN_CLICKED(IDC_CAdUiBitmapButton, &CAcUiMRUComboBoxDialogTest::drawLoadedCAdUiImage)
	ON_BN_CLICKED(IDC_Load_Icon, &CAcUiMRUComboBoxDialogTest::LoadIconResource)
	ON_BN_CLICKED(IDC_LoadRCDATA, &CAcUiMRUComboBoxDialogTest::LoadRCDATAResource)
	ON_BN_CLICKED(IDC_LoadBITMAP, &CAcUiMRUComboBoxDialogTest::LoadBitmapResource)
	ON_BN_CLICKED(IDC_BitmapLocation_kLeft, &CAcUiMRUComboBoxDialogTest::BitmapLocationkLeft)
	ON_BN_CLICKED(IDC_BitmapLocation_kTop, &CAcUiMRUComboBoxDialogTest::BitmapLocationTop)
	ON_BN_CLICKED(IDC_BitmapLocation_kRight, &CAcUiMRUComboBoxDialogTest::BitmapLocationRight)
	ON_BN_CLICKED(IDC_BitmapLocation_kBottom, &CAcUiMRUComboBoxDialogTest::BitmapLocationBottom)
	ON_BN_CLICKED(IDC_BTNOTHER, &CAcUiMRUComboBoxDialogTest::OnBnClickedBtnother)
END_MESSAGE_MAP()

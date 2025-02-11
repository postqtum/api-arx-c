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
***     Description: Implementation of CAdUiImageDialogTest class
***
*****************************************************************************/

#include "stdafx.h"
#include "CAdUiImageDialogTest.h"

void CAdUiImageDialogTest::drawImage(CAdUiImage& pImg, int beginPosX, int beginPosY)
{

	auto pDc = GetDC();
	int posX = beginPosX;
	int posY = beginPosY;
	auto isDrawed = pImg.DrawImage(pDc, posX, posY);
	ASSERT(isDrawed);

	posX += pImg.GetWidth() + 1;
	isDrawed = pImg.DrawImage(pDc, posX, posY, true);
	ASSERT(isDrawed);

	posX = beginPosX;
	posY += pImg.GetHeight() + 1;

	int scalingX = pImg.GetWidth() * 3;
	int scalingY = pImg.GetHeight() * 2;
	int croppingX = pImg.GetWidth();
	int croppingY = pImg.GetHeight() / 2;

	isDrawed = pImg.DrawImage(pDc, posX, posY, scalingX, scalingY);
	ASSERT(isDrawed);

	posX += scalingX + 1;
	isDrawed = pImg.DrawImage(pDc, posX, posY, scalingX, scalingY, true);
	ASSERT(isDrawed);

	posX = beginPosX;
	posY += pImg.GetHeight() * 2 + 1;
	isDrawed = pImg.DrawImage(pDc, posX, posY, 0, 0, croppingX, croppingY);
	ASSERT(isDrawed);

	posX += pImg.GetWidth() + 1;
	isDrawed = pImg.DrawImage(pDc, posX, posY, 0, croppingY, croppingX, croppingY, true);
	ASSERT(isDrawed);

	posX = beginPosX;
	posY += pImg.GetHeight() + 1;
	isDrawed = pImg.DrawImage(pDc, posX, posY, scalingX, scalingY, 0, 0, croppingX, croppingY);
	ASSERT(isDrawed);

	posX += pImg.GetWidth() * 3 + 1;
	isDrawed = pImg.DrawImage(
	        pDc, posX, posY, scalingX, scalingY, 0, croppingY, croppingX, croppingY, true);
	ASSERT(isDrawed);
}

IMPLEMENT_DYNAMIC(CAdUiImageDialogTest, CAdUiDialog)

BOOL CAdUiImageDialogTest::OnInitDialog()
{
	auto res = CAdUiDialog::OnInitDialog();

	auto isLoaded = m_Image.Load(IDB_PRINT_WARNING, RT_RCDATA, AfxGetResourceHandle());
	ASSERT(isLoaded);
	isLoaded = m_Image1.Load(IDB_PRINT_WARNING, (UINT)(DWORD_PTR)RT_RCDATA, AfxGetResourceHandle());
	ASSERT(isLoaded);
	isLoaded = m_Image2.Load(IDB_PRINT_WARNING, IDB_PRINT_WARNING, (UINT)(DWORD_PTR)RT_RCDATA,
	        AfxGetResourceHandle());
	ASSERT(isLoaded);
	isLoaded = m_ImageIcon.Load(IDB_TEST_ICON, RT_GROUP_ICON, AfxGetResourceHandle());
	ASSERT(isLoaded);
	return res;
}

void CAdUiImageDialogTest::OnPaint()
{
	drawImage(m_Image, 0, 0);
	drawImage(m_Image1, 100, 0);
	drawImage(m_Image2, 200, 0);
	auto pDc = GetDC();
	m_ImageIcon.DrawImage(pDc,0, 200);
}

void CAdUiImageDialogTest::DoDataExchange(CDataExchange* pDX)
{
	CAdUiDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAdUiImageDialogTest, CAdUiDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()

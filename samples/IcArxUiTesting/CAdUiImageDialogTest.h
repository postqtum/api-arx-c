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
***     Description: Declaration of CAdUiImageDialogTest
***
*****************************************************************************/
#pragma once

#include <inc/aduiDialog.h>
#include <inc/aduiImage.h>

class CAdUiImageDialogTest : public CAdUiDialog
{
	DECLARE_DYNAMIC(CAdUiImageDialogTest)
	CAdUiImageResource m_Image;
	CAdUiImageResource m_Image1;
	CAdUiImageResource m_Image2;
	CAdUiImageResource m_ImageIcon;
	enum
	{
		IDD = IDD_DIALOG_CAdUiImageDialogTest,
	};
	void drawImage(CAdUiImage&, int, int);

protected:
	BOOL OnInitDialog();

public:
	afx_msg void OnPaint();
	CAdUiImageDialogTest(CWnd* pParent = nullptr)
	    : CAdUiDialog(IDD, pParent)
	{
	}
	virtual void DoDataExchange(CDataExchange* pDX);
	DECLARE_MESSAGE_MAP()
};

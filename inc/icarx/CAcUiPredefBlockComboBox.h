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
***     Description: Declaration of CAcUiPredefBlockComboBox class
***
*****************************************************************************/
#pragma once

#include "CAcUiMRUComboBox.h"

class CAdUiImage;

#include "IcArxPackPush.h"

class ACUI_PORT CAcUiPredefBlockComboBox : public CAcUiMRUComboBox
{
public:
	CAcUiPredefBlockComboBox();
	virtual ~CAcUiPredefBlockComboBox();

protected:
	void DrawItemImage(CDC& dc, CRect& r, INT_PTR cargo) override;
	int CalcItemHeight() override;
	BOOL GetOtherName(BOOL isOther2, CString& name) override;
	void OnAddItems() override;

	virtual bool LoadImages();

private:
	CAdUiImage* m_pBlockImages;
	int m_blockCount;
	int m_blockSize;
	BOOL m_bThemedBlockImagesLoaded;

public:
	int AddPredefBlockToMRU(LPCTSTR name);

protected:
	DECLARE_MESSAGE_MAP()
};

#include "IcArxPackPop.h"

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
***     Description:
***
*****************************************************************************/
#pragma once

#ifndef ANAV_PORT
#	define ANAV_PORT
#endif

#include <afxole.h>

#include "aduiListCtrl.h"

class CNavListCtrl;

class CNavDropSource : public COleDropSource
{
public:
	CNavListCtrl* m_pListCtrl = nullptr;

public:
	CNavDropSource() = default;

	SCODE GiveFeedback(DROPEFFECT dropEffect);
};

class ANAV_PORT CNavListCtrl : public CAdUiListCtrl
{
protected:
	CImageList* m_pDragImage = nullptr;
	CNavDropSource m_dropSource;

protected:
	afx_msg void OnBeginDrag(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg LRESULT OnHandleDrag(UINT_PTR pDataSource, LPARAM nSelectedItem);
	DECLARE_MESSAGE_MAP()

public:
	CNavListCtrl();
};

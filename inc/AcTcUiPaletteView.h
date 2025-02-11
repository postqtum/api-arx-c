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

#include "AcTcUiCatalogView.h"

class ACTCUI_PORT CAcTcUiPaletteView : public CAcTcUiCatalogView
{
public:
	CAcTcUiPaletteView();
	~CAcTcUiPaletteView();

protected:
	DROPEFFECT DragEnter(ADUI_DRAGDATA* pDragData) override;
	DROPEFFECT DragOver(ADUI_DRAGDATA* pDragData) override;
	void DragLeave(ADUI_DRAGDATA* pDragData) override;
	DROPEFFECT Drop(ADUI_DRAGDATA* pDragData) override;
	DROPEFFECT DropEx(ADUI_DRAGDATA* pDragData) override;

protected:
	CAcTcUiPaletteView(AcTcUiSystemInternals*);

protected:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnInvokeCommand(UINT nID);
	afx_msg void OnPaletteRemove();
	afx_msg void OnCatalogItemSpecifyImage();
	afx_msg void OnCatalogItemRemoveImage();
	afx_msg void OnCatalogItemUpdateImage();
	DECLARE_MESSAGE_MAP()
};

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

#include "AcTc.h"
#include "AcTcUi.h"

class CAcTcUiCatalogView;

#define ACTCUI_CVISTYLE_PUSHBUTTON 0x0
#define ACTCUI_CVISTYLE_SHOWTEXT (0x1 << 1)
#define ACTCUI_CVISTYLE_RIGHTTEXT (0x1 << 2)
#define ACTCUI_CVISTYLE_FLYOUT (0x1 << 3)
#define ACTCUI_CVISTYLE_FULLROW (0x1 << 4)
#define ACTCUI_CVISTYLE_HIDEIMAGE (0x1 << 5)
#define ACTCUI_CVISTYLE_TEXT (0x1 << 6)
#define ACTCUI_CVISTYLE_SEPARATOR (0x1 << 7)

#define ACTCUI_CVISTATE_HIGHLIGHTED (0x1 << 0)
#define ACTCUI_CVISTATE_SELECTED (0x1 << 1)
#define ACTCUI_CVISTATE_HALO (0x1 << 2)
#define ACTCUI_CVISTATE_FOCUSED (0x1 << 3)

#define ACTCUI_CVIR_BOUNDS (0x1 << 0)
#define ACTCUI_CVIR_IMAGE (0x1 << 1)
#define ACTCUI_CVIR_LABEL (0x1 << 2)
#define ACTCUI_CVIR_USEFULLLABEL (0x1 << 3)
#define ACTCUI_CVIR_TRIGGER (0x1 << 4)
#define ACTCUI_CVIR_WORLDRECT (0x1 << 5)

class ACTCUI_PORT CAcTcUiCatalogViewItem : public CObject
{
	friend class CAcTcUiImpCatalogView;

public:
	~CAcTcUiCatalogViewItem();

	BOOL Render(BOOL bEraseBackground = FALSE);
	BOOL Render(CDC* pDC, int x, int y);
	BOOL GetRect(LPRECT lpRect, int nCode) const;
	AcTcCatalogItem* GetCatalogItem(void) const;
	BOOL SetCatalogItem(AcTcCatalogItem* pCatalogItem);
	DWORD GetStyle(void) const;
	DWORD GetState(void) const;
	BOOL SetState(DWORD dwState);
	BOOL GetPosition(LPPOINT lpPoint) const;
	DWORD GetData(void) const;
	BOOL SetData(DWORD dwData);
	BOOL Highlight(BOOL bHighlight = TRUE);
	BOOL Select(BOOL bSelect = TRUE);
	BOOL Halo(BOOL bHalo = TRUE);

protected:
	CAcTcUiCatalogViewItem(CAcTcUiCatalogView* pCatalogView);
	CAcTcUiCatalogViewItem(CAcTcUiCatalogView* pCatalogView, AcTcCatalogItem* pCatalogItem,
						   const CSize& sizeImage, DWORD dwStyle = ACTCUI_CVISTYLE_PUSHBUTTON);

protected:
	void* mpImpObj;	 // Imp object CAcTcUiImpCatalogViewItem

private:
	friend class AcTcUiSystemInternals;
};

typedef CTypedPtrArray<CPtrArray, CAcTcUiCatalogViewItem*> CAcTcUiCatalogViewItemArray;

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
***     Description: Declaration of CAdUiDropTarget class
***
*****************************************************************************/
#pragma once

#include <afxole.h>

#define UM_ADUI_DRAGENTER (WM_USER + 120)
#define UM_ADUI_DRAGOVER (WM_USER + 121)
#define UM_ADUI_DRAGLEAVE (WM_USER + 122)
#define UM_ADUI_DROP (WM_USER + 123)
#define UM_ADUI_DROPEX (WM_USER + 124)
#define UM_ADUI_DRAGSCROLL (WM_USER + 125)

#include "icarx/IcArxPackPush.h"

typedef struct tagADUI_DRAGDATA
{
	CWnd* mpWnd;
	COleDataObject* mpDataObject;
	DWORD mdwKeyState;
	POINTL mPoint;
	DROPEFFECT mDropEffect;
	DROPEFFECT mDropList;

} ADUI_DRAGDATA, *PADUI_DRAGDATA;

#pragma warning(disable : 4275)

class CAdUiDropTarget : public COleDropTarget
{
protected:
	DWORD mdwKeyState = 0;
	int mnId = -1;
	CWnd* mpTargetWnd = nullptr;

protected:
	DROPEFFECT OnDragEnter(CWnd* pWnd, COleDataObject* pDataObject, DWORD dwKeyState, CPoint point);
	void OnDragLeave(CWnd* pWnd);
	DROPEFFECT OnDragOver(CWnd* pWnd, COleDataObject* pDataObject, DWORD dwKeyState, CPoint point);
	DROPEFFECT OnDragScroll(CWnd* pWnd, DWORD dwKeyState, CPoint point);
	BOOL OnDrop(CWnd* pWnd, COleDataObject* pDataObject, DROPEFFECT dropEffect, CPoint point);
	DROPEFFECT OnDropEx(CWnd* pWnd, COleDataObject* pDataObject, DROPEFFECT dropDefault,
						DROPEFFECT dropList, CPoint point);

public:
	CAdUiDropTarget();
	CAdUiDropTarget(int nId);
	~CAdUiDropTarget();
	BOOL SetTargetWindowForMessages(CWnd* pWnd);
};


#include "icarx/IcArxPackPop.h"

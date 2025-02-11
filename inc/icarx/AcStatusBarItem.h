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
***     Description: Declaration of AcStatusBarItem class
***
*****************************************************************************/
#pragma once

#ifndef ACAD_PORT
#	define ACAD_PORT
#endif

class CMenu;
class AcApImpStatusBarItem;

#include "IcArxPackPush.h"

class AcStatusBarItem
{
	friend class AcApImpStatusBarItem;

private:
	AcApImpStatusBarItem* m_Imp;

	//HICON m_hIcon;
	//CString m_strToolTipText;
	//BOOL m_bEnabled;
	//BOOL m_bVisible;
	//BOOL m_bContentChanged;
	//BOOL m_bVisibilityChanged;
	//void* m_pData;
	//void* m_pDocSwitchData;

protected:
	AcStatusBarItem(AcApImpStatusBarItem* imp);

public:
	AcStatusBarItem();
	ACAD_PORT AcStatusBarItem(const CString& strId, bool isTrayItem);
	virtual ~AcStatusBarItem();

	AcStatusBarItem(const AcStatusBarItem&) = delete;
	AcStatusBarItem& operator=(const AcStatusBarItem&) = delete;

	virtual BOOL ClientToScreen(LPPOINT lpPoint);
	virtual BOOL ClientToScreen(LPRECT lpRect);
	virtual BOOL ContentChanged() const;
	virtual UINT DisplayContextMenu(CMenu& menu, CPoint point);
	virtual void Enable(BOOL bValue);
	ACAD_PORT CString& GetActiveImageState() const;
	void* GetData();
	ACAD_PORT int GetID() const;
	virtual HICON GetIcon() const;
	virtual void* GetInternalData(BOOL bForDocSwitch = TRUE) const;
	ACAD_PORT const CString& GetName() const;
	virtual BOOL GetToolTipText(CString& strText) const;
	virtual BOOL IsEnabled();
	ACAD_PORT bool IsTrayItem() const;
	virtual BOOL IsVisible();
	virtual BOOL QueryToolTipText(CString& strText) const;
	virtual void OnDelete();
	virtual void OnLButtonDblClk(UINT nFlags, CPoint point);
	virtual void OnLButtonDown(UINT nFlags, CPoint point);
	virtual void OnRButtonDown(UINT nFlags, CPoint point);
	virtual BOOL ScreenToClient(LPPOINT lpPoint);
	virtual BOOL ScreenToClient(LPRECT lpRect);
	ACAD_PORT void SetActiveImageState(const CString& strActiveImageState);
	virtual void SetContentChanged(BOOL bChanged);
	ACAD_PORT void SetID(int id);
	virtual BOOL SetIcon(HICON hIcon);
	virtual void SetInternalData(void* pData, BOOL bForDocSwitch = FALSE);
	virtual BOOL SetToolTipText(const CString& strText);
	virtual void SetVisibilityChanged(BOOL bChanged);
	virtual void SetVisible(BOOL bIsVisible);
	virtual BOOL ShowTraySettingsDialog();
	virtual BOOL VisibilityChanged() const;
};

#include "IcArxPackPop.h"

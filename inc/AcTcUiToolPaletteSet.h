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

#include "AcTcUi.h"
#include "aduiPaletteSet.h"
#include "AcTcUiToolPalette.h"
#include "AcTcUiToolPaletteGroup.h"

class CAcTcUiImpToolPaletteSet;
class CAcTcUiScheme;

class ACTCUI_PORT CAcTcUiToolPaletteSet : public CAdUiPaletteSet
{
	friend CAcTcUiImpToolPaletteSet;

	DECLARE_DYNCREATE(CAcTcUiToolPaletteSet);

public:
	~CAcTcUiToolPaletteSet();

	BOOL Load(IUnknown* pUnk) override;
	BOOL Save(IUnknown* pUnk) override;
	virtual BOOL Import(IUnknown* pUnk, LPCTSTR pszRefPath);
	virtual BOOL Export(IUnknown* pUnk, LPCTSTR pszRefPath);
	virtual BOOL HitTest(CPoint pt, UINT& nFlag, DWORD& dwData);
	int AddPalette(CAdUiPalette* pPalette);
	int InsertPalette(int iIndex, CAdUiPalette* pPalette);
	BOOL RemovePalette(CAdUiPalette* pPalette);
	BOOL RemovePalette(int iIndex);
	void TitleBarLocationUpdated(AdUiTitleBarLocation newLoc) override;
	CAcTcUiToolPaletteGroup* GetToolPaletteGroup(BOOL bCreate = FALSE);
	CAcTcUiToolPaletteGroup* GetAllPalettesGroup(void);
	CAcTcUiToolPaletteGroup* GetActivePaletteGroup(void);
	BOOL GetActivePaletteGroup(LPTSTR pszGroup, int cbSize) const;
	BOOL SetActivePaletteGroup(CAcTcUiToolPaletteGroup* pGroup);
	BOOL SetActivePaletteGroup(LPCTSTR pszGroup);
	CAcTcUiScheme* GetScheme(void) const;
	BOOL Show(void);
	BOOL Show(BOOL bShow);
	BOOL SetActivePalette(CAdUiPalette* pPalette);
	BOOL SetActivePalette(int nPaletteIndex);
	BOOL SetActivePalette(LPCTSTR pszPalName, BOOL bSearchOnlyCurrentGroup) const;
	CAcTcUiToolPalette* FindPalette(LPCTSTR pszPalName, CAcTcUiToolPaletteGroup** ppGroup,
									BOOL bSearchOnlyCurrentGroup) const;

protected:
	CAcTcUiToolPaletteSet();

protected:
	BOOL AddContextMenuItems(CMenu* pMenu, int nHitFlag, int nRightClkTab = 0) override;

	void ThemeModified(AdUiThemeElement element) override;
	void OnTabDrag(CPtrArray& arrayPalettes) override;
	virtual BOOL OnBeginDrag(COleDataSource* pDataSource, CPtrArray& arrayPalettes);
	virtual void OnEndDrag(DROPEFFECT dropEffect);
	virtual BOOL OnBeginMove(COleDataSource* pDataSource, CPtrArray& arrayPalettes);
	virtual void OnEndMove(DROPEFFECT dropEffect);
	virtual BOOL OnRenderData(LPFORMATETC lpFormatEtc, LPSTGMEDIUM lpStgMedium);
	virtual void OnTearOff(CAdUiPaletteSet* pSet);
	virtual void DestroyStackedPaletteSet(void);

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
	afx_msg void OnWindowPosChanging(WINDOWPOS* lpwndpos);
	afx_msg void OnRemovePaletteSet();
	afx_msg void OnRemoveActivePalette();
	afx_msg void OnRemovePalette();
	afx_msg void OnViewOptions();
	afx_msg void OnSelectPaletteGroup(UINT nID);
	afx_msg void OnShowCustomizeDialog();
	afx_msg void OnShowCustomizeDialogCUI();
	afx_msg void OnNewPalette();
	afx_msg void OnPaste();
	afx_msg void OnPaletteProperties();
	afx_msg void OnRefreshPaletteSet();
	afx_msg void OnRefreshActivePalette();
	afx_msg void OnClose();
	afx_msg void OnMoveUp();
	afx_msg void OnMoveDown();
	afx_msg void OnInvokeCommand(UINT nID);
	afx_msg void OnTimer(UINT_PTR nIDEvent);

protected:
	afx_msg LRESULT OnDragEnter(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnDragOver(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnDrop(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnDropEx(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnDragLeave(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnUpdate(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnRenderData(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

protected:
	void* mpImpObj;

private:
	friend class AcTcUiSystemInternals;
};

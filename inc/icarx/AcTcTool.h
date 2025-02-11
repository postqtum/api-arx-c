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
***     Description: Declaration of AcTcTool class
***
*****************************************************************************/
#pragma once

#include "AcTcCatalogItem.h"

class AcTcStockTool;

#include "IcArxPackPush.h"

class ACTC_PORT AcTcTool : public AcTcCatalogItem
{
public:
	AcTcTool();
	AcTcTool(const AcTcTool& srcItem);
	~AcTcTool();

	virtual BOOL Execute(int nFlag, HWND hWnd, POINT point, DWORD dwKeyState);
	BOOL GetToolData(IUnknown** ppUnknown);
	AcTcStockTool* GetStockTool(void) const;
	BOOL CreateAcadTool(IUnknown** ppTool, BOOL bLoadData = TRUE);
	BOOL GetStockToolID(GUID* pId) const;
	BOOL SetStockToolID(const GUID* pId);
	int GetStockToolFileUrl(LPTSTR pszString, int cchSize) const;
	BOOL SetStockToolFileUrl(LPCTSTR pszString);
	AcTc::ToolType GetToolType(void) const;
	BOOL SetToolType(AcTc::ToolType nToolType);
	BOOL IsFlyoutEnabled(void) const;
	BOOL EnableFlyout(BOOL bUseFlyout);
	AcTcCatalogItem* GetShapePackage(void) const;
	BOOL SetShapePackage(AcTcCatalogItem* pPackage);
	AcTcTool* GetCurrentShape(void) const;
	BOOL SetCurrentShape(AcTcTool* pTool);
	BOOL SetCurrentShape(const GUID& id);
	BOOL GetActiveShapes(AcTcCatalogItem** pItems, INT_PTR& nNumItems);
	BOOL SetActiveShapes(AcTcCatalogItem** pItems, int nNumItems);

protected:
	AcTcTool(AcTcSystemInternals*);
};

#include "IcArxPackPop.h"

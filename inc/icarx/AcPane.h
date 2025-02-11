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
***     Description: Declaration of AcPane class
***
*****************************************************************************/
#pragma once

#include "AcStatusBarItem.h"

#include "IcArxPackPush.h"

class AcPane : public AcStatusBarItem
{
private:
	//CString m_strText;
	//int m_nStyle;
	//int m_cxMinWidth;
	//int m_cxMaxWidth;
	//CString m_strName;
	//CString m_strRegistryKey;

protected:
	AcPane(AcApImpStatusBarItem* imp);

public:
	AcPane();
	ACAD_PORT AcPane(const CString& strId);
	~AcPane();

	virtual UINT DisplayPopupPaneMenu(CMenu& menu);
	HICON GetIcon() const override;
	virtual int GetMaxWidth();
	virtual int GetMinWidth();
	ACAD_PORT virtual BOOL GetPaneName(CString& strName) const;
	ACAD_PORT virtual BOOL GetRegistryKey(CString& strRegistryKey) const;
	virtual int GetStyle() const;
	virtual BOOL GetText(CString& strText) const;
	BOOL SetIcon(HICON hIcon) override;
	virtual BOOL SetMaxWidth(int cxWidth);
	virtual BOOL SetMinWidth(int cxWidth);
	ACAD_PORT virtual BOOL SetPaneName(const CString& strName);
	ACAD_PORT virtual BOOL SetRegistryKey(const CString& strRegistryKey);
	virtual BOOL SetStyle(int nStyle);
	virtual BOOL SetText(const CString& strText);
};

#include "IcArxPackPop.h"

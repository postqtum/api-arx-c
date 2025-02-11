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
***     Description: Declaration of CAcUiLineTypeComboBox class
***
*****************************************************************************/
#pragma once

#include "CAcUiMRUComboBox.h"

class AcDbObjectId;
class AcDbDatabase;
class CAcUiLTypeRecord;

#include "IcArxPackPush.h"

class ACUI_PORT CAcUiLineTypeComboBox : public CAcUiMRUComboBox
{
public:
	CAcUiLineTypeComboBox();
	~CAcUiLineTypeComboBox();

	void OnComboBoxInit() override;

	void AddItems();

	AcDbObjectId getOIDSel(int sel);
	AcDbObjectId getOIDCurSel();
	void setCurSelByOID(const AcDbObjectId& oidCurSel);
	bool isOtherSelected();
	void forceSelectOther(BOOL isOther2);
	int getLastSelection();
	bool getDbReload();
	void setDbReload(bool bReload);
	void emptyLTypeLocalList();

protected:
	void DrawItemImage(CDC& dc, CRect& r, INT_PTR cargo) override;
	void OnAddItems() override;
	BOOL OnSelectOther(BOOL isOther2, int curSel, int& newSel) override;
	INT_PTR GetItemCargo(int item);
	int FindItemByCargo(AcDbObjectId cargo);
	void LoadContentsFromDatabase();
	void ShowLTypes(bool bForceReloadDB = false);
	int AddLTypeToControl(CAcUiLTypeRecord* pLTypeRecord);
	CAcUiLTypeRecord* CreateLTRecord(CString& cstrLTName, AcDbObjectId& oidLT);

	int ImageWidth() override;
	AcDbDatabase* getLTLocalMapDB();
	void setLTLocalMapDB(AcDbDatabase* pDb);

	CObList m_LTypeLocalList;
	AcDbDatabase* m_pLTLocalMapDB;
	bool m_bDbReload;

public:
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) override;

protected:
	DECLARE_MESSAGE_MAP()
};

#include "IcArxPackPop.h"

inline bool CAcUiLineTypeComboBox::getDbReload()
{
	return m_bDbReload;
}

inline void CAcUiLineTypeComboBox::setDbReload(bool bReload)
{
	m_bDbReload = bReload;
}

inline void CAcUiLineTypeComboBox::forceSelectOther(BOOL isOther2)
{
	SelectOther(isOther2);
}

inline int CAcUiLineTypeComboBox::getLastSelection()
{
	return m_lastSelection;
}

inline bool CAcUiLineTypeComboBox::isOtherSelected()
{
	CString otherName;
	CString curSelName;
	GetOtherName(false, otherName);
	GetLBText(GetCurSel(), curSelName);
	return curSelName == otherName;
}

inline AcDbObjectId CAcUiLineTypeComboBox::getOIDSel(int sel)
{
	AcDbObjectId oidLT;
	CAcUiLTypeRecord* pLTRec = (CAcUiLTypeRecord*)(GetItemDataPtr(sel));
	if (pLTRec)
		oidLT = pLTRec->objectId();
	return oidLT;
}

inline AcDbObjectId CAcUiLineTypeComboBox::getOIDCurSel()
{
	return getOIDSel(GetCurSel());
}

inline void CAcUiLineTypeComboBox::setCurSelByOID(const AcDbObjectId& oidCurSel)
{
	int i = FindItemByCargo(oidCurSel);
	SetCurSel(i >= 0 ? i : m_lastSelection);
	if (i >= 0)
		m_lastSelection = i;
}

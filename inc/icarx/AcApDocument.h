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
***     Description: Declaration of AcLispAppInfo and AcApDocument classes
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../accoredefs.h"
#include "../AcApDocLockmode.h"
#include "AcDbEnumMode.h"

class CDocument;
class AcTransactionManager;
class AcDbDatabase;
class AcApView;
class IAcApDocumentHost;
class AcEdInputPointManager;
class AcApStatusBar;
class AcApCommandLineEditor;
struct IDispatch;

#include "IcArxPackPush.h"

class AcLispAppInfo
{
public:
	static const int MaxPath = 260;
	ACHAR appFileName[MaxPath];
	bool bUnloadable;
};

class ACCORE_PORT ADESK_NO_VTABLE AcApDocument : public AcRxObject
{
public:
	enum SaveFormat
	{
		kUnknown = -1,
		kR12_dxf = 1,
		kR13_dwg = 4,
		kR13_dxf = 5,
		kR14_dwg = 8,
		kR14_dxf = 9,
		k2000_dwg = 12,
		k2000_dxf = 13,
		k2000_Template = 14,
		k2000_Standard = 15,
		k2000_xml = 16,
		k2004_dwg = 24,
		k2004_dxf = 25,
		k2004_Template = 26,
		k2004_Standard = 27,
		k2007_dwg = 36,
		k2007_dxf = 37,
		k2007_Template = 38,
		k2007_Standard = 39,
		k2010_dwg = 48,
		k2010_dxf = 49,
		k2010_Template = 50,
		k2010_Standard = 51,
		k2013_dwg = 60,
		k2013_dxf = 61,
		k2013_Template = 62,
		k2013_Standard = 63,
		k2018_dwg = 64,
		k2018_dxf = 65,
		k2018_Template = 66,
		k2018_Standard = 67,
		kNative = k2018_dwg,
		kNative_Template = k2018_Template
	};

public:
	ACRX_DECLARE_MEMBERS(AcApDocument);

public:
	virtual int GetCountOfLispList() const = 0;
	virtual IDispatch* GetIDispatch(bool bAddRef) = 0;
	virtual AcLispAppInfo* GetItemOfLispList(int nIndex) const = 0;
	virtual CDocument* cDoc() const = 0;
	AcApCommandLineEditor* commandLineEditor() const;
	virtual void* contextPtr() const = 0;
	virtual AcDbDatabase* database() const = 0;
	virtual const ACHAR* docTitle() const = 0;
	Acad::ErrorStatus downgradeDocOpen(bool bPromptForSave);
	virtual AcApStatusBar* drawingStatusBar() const = 0;
	virtual const ACHAR* fileName() const = 0;
	virtual AcApDocument::SaveFormat formatForSave() const = 0;
	static Acad::ErrorStatus getDwgVersionFromSaveFormat(
			AcApDocument::SaveFormat docFormat, AcDb::AcDbDwgVersion& dwgVer,
			AcDb::MaintenanceReleaseVersion& dwgMaintVer);
	virtual AcEdInputPointManager* inputPointManager() = 0;
	virtual bool isCommandInputInactive() const = 0;
	bool isNamedDrawing() const;
	virtual bool isQuiescent() const = 0;
	virtual bool isReadOnly() const = 0;
	virtual AcAp::DocLockMode lockMode(bool bIncludeMyLocks = false) const = 0;
	virtual AcAp::DocLockMode myLockMode() const = 0;
	Acad::ErrorStatus popDbmod();
	void pushDbmod();
	void setDocTitle(const ACHAR* title);
	void setHost(IAcApDocumentHost* pHost);
	virtual AcTransactionManager* transactionManager() const = 0;
	Acad::ErrorStatus upgradeDocOpen();
	AcApView* view() const;
};

#include "IcArxPackPop.h"

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
***     Description: Declaration of AcDbLayerStateManager class
***
*****************************************************************************/
#pragma once

#include "../dbmain.h"

class AcDbLayerStateManagerReactor;

#include "IcArxPackPush.h"

class AcDbLayerStateManager : public AcRxObject
{
	friend class AcDbImpDatabase;
	friend class AcDbImpLayerStateManager;

public:
	enum LayerStateMask
	{
		kNone = 0x0000,
		kOn = 0x0001,
		kFrozen = 0x0002,
		kLocked = 0x0004,
		kPlot = 0x0008,
		kNewViewport = 0x0010,
		kColor = 0x0020,
		kLineType = 0x0040,
		kLineWeight = 0x0080,
		kPlotStyle = 0x0100,
		kCurrentViewport = 0x0200,
		kTransparency = 0x0400,
		kAll = kOn | kFrozen | kLocked | kPlot | kNewViewport | kColor | kLineType | kLineWeight |
			   kPlotStyle | kCurrentViewport | kTransparency,
		kStateIsHidden = 0x8000,
		kLastRestored = 0x10000,
		kDecomposition = kAll | 0x20000
	};

	enum
	{
		kUndefDoNothing = 0,
		kUndefTurnOff = 1,
		kUndefFreeze = 2,
		kRestoreAsOverrides = 4
	};

private:
	AcDbImpLayerStateManager* mpImpLSM;

public:
	ACRX_DECLARE_MEMBERS(AcDbLayerStateManager);

	AcDbLayerStateManager();
	AcDbLayerStateManager(AcDbDatabase* pHostDb);
	~AcDbLayerStateManager();

	Acad::ErrorStatus addLayerStateLayers(const ACHAR* sName, const AcDbObjectIdArray& layerIds);
	bool addReactor(AcDbLayerStateManagerReactor* pReactor);
	bool compareLayerStateToDb(const ACHAR* sName, const AcDbObjectId& idVp);
	Acad::ErrorStatus deleteLayerState(const ACHAR* sName);
	Acad::ErrorStatus exportLayerState(const ACHAR* sNameToExport, const ACHAR* sFilename);
	AcDbDatabase* getDatabase() const;
	Acad::ErrorStatus getLastRestoredLayerState(AcString& sName, AcDbObjectId& restoredLSId);
	Acad::ErrorStatus getLayerStateDescription(const ACHAR* sName, ACHAR*& sDesc);
	Acad::ErrorStatus getLayerStateLayers(AcStringArray& layerArray, const ACHAR* sName,
										  bool bInvert = false);
	Acad::ErrorStatus getLayerStateMask(const ACHAR* sName, LayerStateMask& returnMask);
	Acad::ErrorStatus getLayerStateNames(AcStringArray& lsArray, bool bIncludeHidden = true,
										 bool bIncludeXref = true);
	bool hasLayerState(const ACHAR* sName);
	Acad::ErrorStatus importLayerState(const ACHAR* sFilename);
	Acad::ErrorStatus importLayerState(const ACHAR* sFilename, AcString& sName);
	Acad::ErrorStatus importLayerStateFromDb(const ACHAR* pStateName, AcDbDatabase* pDb);
	bool isDependentLayerState(const ACHAR* sName);
	bool layerStateHasViewportData(const ACHAR* sName);
	AcDbObjectId layerStatesDictionaryId(bool bCreateIfNotPresent = false);
	Acad::ErrorStatus removeLayerStateLayers(const ACHAR* sName, const AcStringArray& layerNames);
	bool removeReactor(AcDbLayerStateManagerReactor* pReactor);
	Acad::ErrorStatus renameLayerState(const ACHAR* sName, const ACHAR* sNewName);
	Acad::ErrorStatus restoreLayerState(const ACHAR* sName);
	Acad::ErrorStatus restoreLayerState(const ACHAR* sName, const AcDbObjectId& idVp,
										int nRestoreFlags = 0,
										const LayerStateMask* pClientMask = nullptr);
	Acad::ErrorStatus saveLayerState(const ACHAR* sName, LayerStateMask mask);
	Acad::ErrorStatus saveLayerState(const ACHAR* sName, LayerStateMask mask,
									 const AcDbObjectId& idVp);
	Acad::ErrorStatus setLayerStateDescription(const ACHAR* sName, const ACHAR* sDesc);
	Acad::ErrorStatus setLayerStateMask(const ACHAR* sName, LayerStateMask mask);
};

#include "IcArxPackPop.h"

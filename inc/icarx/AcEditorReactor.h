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
***     Description: Declaration of AcEditorReactor class
***
*****************************************************************************/
#pragma once

#include "../rxevent.h"
#include "../accoredefs.h"
#include "../dbptrar.h"
#include "../dbintar.h"
#include "../dbidar.h"

class AcDbDatabase;
class CAdUiPathname;

#include "IcArxPackPush.h"

class ACCORE_PORT AcEditorReactor : public AcRxEventReactor
{
private:
	uint8_t mVeto = 0;
	friend class AcEditorImp;

protected:
	Acad::ErrorStatus veto();

public:
	ACRX_DECLARE_MEMBERS(AcEditorReactor);

public:
	AcEditorReactor() = default;
	virtual ~AcEditorReactor();

	void abortAttach(AcDbDatabase*) override {}
	void abortDeepClone(AcDbIdMapping&) override {}
	void abortDxfIn(AcDbDatabase*) override {}
	void abortDxfOut(AcDbDatabase*) override {}
	void abortInsert(AcDbDatabase*) override {}
	void abortRestore(AcDbDatabase*) override {}
	void abortSave(AcDbDatabase*) override {}
	void abortWblock(AcDbDatabase*) override {}
	void beginAttach(AcDbDatabase*, const ACHAR*, AcDbDatabase*) override {}
	virtual void beginCloseAll() {}
	void beginDeepClone(AcDbDatabase*, AcDbIdMapping&) override {}
	void beginDeepCloneXlation(AcDbIdMapping&, Acad::ErrorStatus*) override {}
	virtual void beginDocClose(AcDbDatabase*) {}
	virtual void beginDoubleClick(const AcGePoint3d&) {}
	virtual void beginDwgOpen(const ACHAR*) {}
	void beginDxfIn(AcDbDatabase*) override {}
	void beginDxfOut(AcDbDatabase*) override {}
	void beginInsert(AcDbDatabase*, const AcGeMatrix3d&, AcDbDatabase*) override {}
	void beginInsert(AcDbDatabase*, const ACHAR*, AcDbDatabase*) override {}
	virtual void beginQuit() {}
	void beginRestore(AcDbDatabase*, const ACHAR*, AcDbDatabase*) override {}
	virtual void beginRightClick(const AcGePoint3d&) {}
	void beginSave(AcDbDatabase*, const ACHAR*) override {}
	void beginWblock(AcDbDatabase*, AcDbDatabase*, const AcGePoint3d*&) override {}
	void beginWblock(AcDbDatabase*, AcDbDatabase*, AcDbObjectId) override {}
	void beginWblock(AcDbDatabase*, AcDbDatabase*) override {}
	void beginWblockObjects(AcDbDatabase*, AcDbIdMapping&) override {}
	virtual void cmdIUnkModified(const ACHAR*) {}
	void comandeered(AcDbDatabase*, AcDbObjectId, AcDbDatabase*) override {}
	virtual void commandCancelled(const ACHAR*) {}
	virtual void commandEnded(const ACHAR*) {}
	virtual void commandFailed(const ACHAR*) {}
	virtual void commandWillStart(const ACHAR*) {}
	virtual void curDocOpenDowngraded(AcDbDatabase*, const CAdUiPathname&) {}
	virtual void curDocOpenUpgraded(AcDbDatabase*, const CAdUiPathname&) {}
	void databaseConstructed(AcDbDatabase*) override {}
	void databaseToBeDestroyed(AcDbDatabase*) override {}
	virtual void docCloseAborted(AcDbDatabase*) {}
	virtual void docCloseWillStart(AcDbDatabase*) {}
	virtual void docFrameMovedOrResized(IcArx::Integers::LongPtr, bool) {}
	virtual void dwgViewResized(IcArx::Integers::LongPtr) {}
	void dxfInComplete(AcDbDatabase*) override {}
	void dxfOutComplete(AcDbDatabase*) override {}
	void endAttach(AcDbDatabase*) override {}
	void endDeepClone(AcDbIdMapping&) override {}
	virtual void endDwgOpen(const ACHAR*, AcDbDatabase*) {}
	void endInsert(AcDbDatabase*) override {}
	void endRestore(AcDbDatabase*) override {}
	void endWblock(AcDbDatabase*) override {}
	virtual void fullRegenEnded(AcDbDatabase*, const AcDbIntArray&) {}
	virtual void fullRegenWillStart(AcDbDatabase*) {}
	void initialDwgFileOpenComplete(AcDbDatabase*) override {}
	virtual void layoutSwitched(const ACHAR*) {}
	virtual void layoutToBeSwitched(const ACHAR*, const ACHAR*) {}
	virtual void lispCancelled() {}
	virtual void lispEnded() {}
	virtual void lispWillStart(const ACHAR*) {}
	virtual void mainFrameMovedOrResized(IcArx::Integers::LongPtr, bool) {}
	virtual void modelessOperationEnded(const ACHAR*) {}
	virtual void modelessOperationWillStart(const ACHAR*) {}
	virtual void objectsLazyLoaded(const AcDbObjectIdArray&) {}
	void otherAttach(AcDbDatabase*, AcDbDatabase*) override {}
	void otherInsert(AcDbDatabase*, AcDbIdMapping&, AcDbDatabase*) override {}
	void otherWblock(AcDbDatabase*, AcDbIdMapping&, AcDbDatabase*) override {}
	void partialOpenNotice(AcDbDatabase*) override {}
	virtual void pickfirstModified() {}
	virtual void preXrefLockFile(AcDbObjectId) {}
	virtual void quitAborted() {}
	virtual void quitWillStart() {}
	void redirected(AcDbObjectId, AcDbObjectId) override {}
	virtual void redoSubcommandNumber(int, int) {}
	void saveComplete(AcDbDatabase*, const ACHAR*) override {}
	virtual void subcommandsWillBeUndone(int) {}
	virtual void sysVarChanged(const ACHAR*, int) {}
	virtual void sysVarChanged(const ACHAR*, bool) {}
	virtual void sysVarWillChange(const ACHAR*) {}
	virtual void toolbarBitmapSizeChanged(bool) {}
	virtual void toolbarBitmapSizeChanged(int) {}
	virtual void toolbarBitmapSizeWillChange(int) {}
	virtual void toolbarBitmapSizeWillChange(bool) {}
	virtual void undoSubcommandAuto(int, bool) {}
	virtual void undoSubcommandAuto(int, int) {}
	virtual void undoSubcommandBack(int) {}
	virtual void undoSubcommandBegin(int) {}
	virtual void undoSubcommandControl(int, int) {}
	virtual void undoSubcommandEnd(int) {}
	virtual void undoSubcommandMark(int) {}
	virtual void undoSubcommandNumber(int, int) {}
	virtual void undoWriteBoundary(int) {}
	virtual void unknownCommand(const ACHAR*, AcDbVoidPtrArray*) {}
	virtual void viewChanged() {}
	void wblockNotice(AcDbDatabase*) override {}
	virtual Acad::ErrorStatus xrefSubCommandStart(AcXrefSubCommand, const AcDbObjectIdArray&,
												  const ACHAR* const*, const ACHAR* const*)
	{
		return Acad::eOk;
	}
	void xrefSubcommandAttachItem(AcDbDatabase*, int, const ACHAR*) override {}
	void xrefSubcommandBindItem(AcDbDatabase*, int, AcDbObjectId) override {}
	void xrefSubcommandDetachItem(AcDbDatabase*, int, AcDbObjectId) override {}
	void xrefSubcommandOverlayItem(AcDbDatabase*, int, const ACHAR*) override {}
	void xrefSubcommandPathItem(int, AcDbObjectId, const ACHAR*) override {}
	void xrefSubcommandReloadItem(AcDbDatabase*, int, AcDbObjectId) override {}
	void xrefSubcommandUnloadItem(AcDbDatabase*, int, AcDbObjectId) override {}
};


#include "IcArxPackPop.h"

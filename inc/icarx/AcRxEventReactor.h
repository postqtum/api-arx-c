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
***     Description: Declaration of AcRxEventReactor class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../acarray.h"
#include "../rxobject.h"
#include "../AdAChar.h"
#include "../dbid.h"
#include "../AcDbCore2dDefs.h"

class AcDbDatabase;
class AcDbIdMapping;
class AcGeMatrix3d;
class AcGePoint3d;

enum AcXrefSubCommand
{
	kAttach = 0,
	kBind = 1,
	kDetach = 2,
	kOverlay = 3,
	kPath = 4,
	kReload = 5,
	kResolve = 6,
	kUnload = 7,
	kXBind = 8
};

#include "IcArxPackPush.h"

class AcRxEventReactor : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcRxEventReactor);

	ACDBCORE2D_PORT virtual ~AcRxEventReactor() = default;

	virtual void abortAttach(AcDbDatabase* /*pFrom*/) {}
	virtual void abortDeepClone(AcDbIdMapping&) {}
	virtual void abortDxfIn(AcDbDatabase*) {}
	virtual void abortDxfOut(AcDbDatabase*) {}
	virtual void abortInsert(AcDbDatabase* /*pTo*/) {}
	virtual void abortRestore(AcDbDatabase* /*pTo*/) {}
	virtual void abortSave(AcDbDatabase*) {}
	virtual void abortWblock(AcDbDatabase* /*pTo*/) {}
	virtual void beginAttach(AcDbDatabase* /*pTo*/, const ACHAR*, AcDbDatabase* /*pFrom*/) {}
	virtual void beginDeepClone(AcDbDatabase* /*pTo*/, AcDbIdMapping&) {}
	virtual void beginDeepCloneXlation(AcDbIdMapping&, Acad::ErrorStatus*) {}
	virtual void beginDxfIn(AcDbDatabase*) {}
	virtual void beginDxfOut(AcDbDatabase*) {}
	virtual void beginInsert(AcDbDatabase* /*pTo*/, const ACHAR* /*pBlockName*/,
							 AcDbDatabase* /*pFrom*/)
	{
	}
	virtual void beginInsert(AcDbDatabase* /*pTo*/, const AcGeMatrix3d& /*xform*/,
							 AcDbDatabase* /*pFrom*/)
	{
	}
	virtual void beginRestore(AcDbDatabase* /*pTo*/, const ACHAR*, AcDbDatabase* /*pFrom*/) {}
	virtual void beginSave(AcDbDatabase*, const ACHAR* /*pIntendedName*/) {}
	virtual void beginWblock(AcDbDatabase* /*pTo*/, AcDbDatabase* /*pFrom*/,
							 const AcGePoint3d*& /*insertionPoint*/)
	{
	}
	virtual void beginWblock(AcDbDatabase* /*pTo*/, AcDbDatabase* /*pFrom*/,
							 AcDbObjectId /*blockId*/)
	{
	}
	virtual void beginWblock(AcDbDatabase* /*pTo*/, AcDbDatabase* /*pFrom*/) {}
	virtual void beginWblockObjects(AcDbDatabase*, AcDbIdMapping&) {}
	virtual void comandeered(AcDbDatabase* /*pTo*/, AcDbObjectId /*id*/, AcDbDatabase* /*pFrom*/) {}
	virtual void databaseConstructed(AcDbDatabase*) {}
	virtual void databaseToBeDestroyed(AcDbDatabase*) {}
	virtual void dwgFileOpened(AcDbDatabase*, ACHAR*) {}
	virtual void dwgFileOpened(AcDbDatabase*, const ACHAR* /*fileName*/) {}
	virtual void dxfInComplete(AcDbDatabase*) {}
	virtual void dxfOutComplete(AcDbDatabase*) {}
	virtual void endAttach(AcDbDatabase* /*pTo*/) {}
	virtual void endDeepClone(AcDbIdMapping&) {}
	virtual void endInsert(AcDbDatabase* /*pTo*/) {}
	virtual void endRestore(AcDbDatabase* /*pTo*/) {}
	virtual void endWblock(AcDbDatabase* /*pTo*/) {}
	virtual void initialDwgFileOpenComplete(AcDbDatabase*) {}
	virtual void otherAttach(AcDbDatabase* /*pTo*/, AcDbDatabase* /*pFrom*/) {}
	virtual void otherInsert(AcDbDatabase* /*pTo*/, AcDbIdMapping& /*idMap*/,
							 AcDbDatabase* /*pFrom*/)
	{
	}
	virtual void otherWblock(AcDbDatabase* /*pTo*/, AcDbIdMapping&, AcDbDatabase* /*pFrom*/) {}
	virtual void partialOpenNotice(AcDbDatabase* /*pDb*/) {}
	virtual void preXrefLockFile(AcDbDatabase* /*pDb*/, AcDbObjectId /*btrId*/) {}
	virtual void redirected(AcDbObjectId /* newId*/, AcDbObjectId /*oldId*/) {}
	virtual void saveComplete(AcDbDatabase*, const ACHAR* /*pActualName*/) {}
	virtual void wblockNotice(AcDbDatabase* /*pDb*/) {}
	virtual void xrefSubCommandAborted(AcDbDatabase* /*pHostDb*/, AcXrefSubCommand /*op*/,
									   const AcArray<AcDbObjectId>& /*ids*/,
									   const ACHAR* const* /*btrNames*/,
									   const ACHAR* const* /*paths*/)
	{
	}
	virtual void xrefSubcommandAttachItem(AcDbDatabase* /*pHost*/, int /*activity*/,
										  const ACHAR* /*pPath*/)
	{
	}
	virtual void xrefSubcommandBindItem(AcDbDatabase* /*pHost*/, int /*activity*/,
										AcDbObjectId /*blockId*/)
	{
	}
	virtual void xrefSubcommandDetachItem(AcDbDatabase* /*pHost*/, int /*activity*/,
										  AcDbObjectId /*blockId*/)
	{
	}
	virtual void xrefSubCommandEnd(AcDbDatabase* /*pHostDb*/, AcXrefSubCommand /*op*/,
								   const AcArray<AcDbObjectId>& /*ids*/,
								   const ACHAR* const* /*btrNames*/, const ACHAR* const* /*paths*/)
	{
	}
	virtual void xrefSubcommandOverlayItem(AcDbDatabase* /*pHost*/, int /*activity*/,
										   const ACHAR* /*pPath*/)
	{
	}
	virtual void xrefSubcommandPathItem(int /*activity*/, AcDbObjectId /*blockId*/,
										const ACHAR* /*pNewPath*/)
	{
	}
	virtual void xrefSubcommandReloadItem(AcDbDatabase* /*pHost*/, int /*activity*/,
										  AcDbObjectId /*blockId*/)
	{
	}
	virtual void xrefSubCommandStart(AcDbDatabase* /*pHostDb*/, AcXrefSubCommand /*op*/,
									 const AcArray<AcDbObjectId>& /*ids*/,
									 const ACHAR* const* /*btrNames*/,
									 const ACHAR* const* /*paths*/, bool& /*vetoOp*/)
	{
	}
	virtual void xrefSubcommandUnloadItem(AcDbDatabase* /*pHost*/, int /*activity*/,
										  AcDbObjectId /*blockId*/)
	{
	}
};

#include "IcArxPackPop.h"

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
***     Description: XREF related API
***
*****************************************************************************/
#pragma once

#include "AdAChar.h"
#include "xgraph.h"

Acad::ErrorStatus acdbAttachXref(AcDbDatabase* pHostDb, const ACHAR* pFilename,
								 const ACHAR* pBlockName, AcDbObjectId& xrefBlkId);
Acad::ErrorStatus acdbBindXrefs(AcDbDatabase* pHostDb, const AcDbObjectIdArray& xrefBlkIds,
								const bool bInsertBind, const bool bAllowUnresolved = false,
								const bool bQuiet = true);
Acad::ErrorStatus acdbDetachXref(AcDbDatabase* pHostDb, const AcDbObjectId& xrefBlkId);
Acad::ErrorStatus acdbGetHostDwgXrefGraph(AcDbDatabase* pHostDb, AcDbXrefGraph& graph,
										  bool includeGhosts = false);
Acad::ErrorStatus acdbOverlayXref(AcDbDatabase* pHostDb, const ACHAR* pFilename,
								  const ACHAR* pBlockName, AcDbObjectId& xrefBlkId);
void acdbReleaseHostDwg(AcDbDatabase* pHostDb);
Acad::ErrorStatus acdbReloadXrefs(AcDbDatabase* pHostDb, const AcDbObjectIdArray& xrefBlkIds,
								  bool bQuiet = true);
Acad::ErrorStatus acdbResolveCurrentXRefs(AcDbDatabase* pHostDb, bool useThreadEngine = true,
										  bool doNewOnly = false);
Acad::ErrorStatus acdbUnloadXrefs(AcDbDatabase* pHostDb, const AcDbObjectIdArray& xrefBlkIds,
								  const bool bQuiet = true);
Acad::ErrorStatus acdbXBindXrefs(AcDbDatabase* pHostDb, const AcDbObjectIdArray xrefSymbolIds,
								 const bool bInsertBind, const bool bQuiet = true);

#include "icarx/IcArxPackPush.h"

class AcDbXrefObjectId
{
private:
	AcDbObjectId m_localId;
	AcDbHandle m_handle;

public:
	AcDbXrefObjectId();
	AcDbXrefObjectId(const AcDbXrefObjectId& other);
	AcDbXrefObjectId& operator=(const AcDbXrefObjectId& other);
	bool operator==(const AcDbXrefObjectId& other) const;
	bool operator!=(const AcDbXrefObjectId& other) const;

	Acad::ErrorStatus getLocalId(AcDbObjectId& objId) const;
	Acad::ErrorStatus getXrefId(AcDbObjectId& xrefBlkId, AcDbHandle& hObject) const;
	bool isNull() const { return this->m_localId.isNull(); }
	bool isValid() const;
	bool isXref() const { return !this->m_handle.isNull(); }
	Acad::ErrorStatus resolveObjectId(AcDbObjectId& id) const;
	Acad::ErrorStatus serializeFromResbuf(const resbuf* pResBuf, resbuf*& pNextInChain);
	Acad::ErrorStatus serializeToResbuf(resbuf*& pResBuf, resbuf*& pEndOfChain) const;
	Acad::ErrorStatus setLocalId(AcDbObjectId objId);
	Acad::ErrorStatus setNull();
	Acad::ErrorStatus setXrefId(AcDbObjectId xrefBlkId, const AcDbHandle& hObject);
};

#include "icarx/IcArxPackPop.h"

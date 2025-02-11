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
***     Description: Declaration of AcDbDataLinkManager class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../dbidar.h"
#include "AcDbEnumMode.h"

class AcDbDataLink;

#include "IcArxPackPush.h"

class AcDbDataLinkManager : public AcRxObject
{
	friend class AcTableSystemInternals;
	friend class AcDbImpDataLinkManager;

private:
	void* mpImpObj = nullptr;

protected:
	ACDB_PORT AcDbDataLinkManager();

public:
	ACRX_DECLARE_MEMBERS(AcDbDataLinkManager);

	ACDB_PORT ~AcDbDataLinkManager();

	ACDB_PORT Acad::ErrorStatus addDataLink(AcDbDataLink* pDataLink);
	ACDB_PORT Acad::ErrorStatus addDataLink(AcDbDataLink* pDataLink, AcDbObjectId& idDataLink);
	ACDB_PORT Acad::ErrorStatus createDataLink(const ACHAR* pszAdapterId, const ACHAR* pszName,
											   const ACHAR* pszDescription,
											   const ACHAR* pszConnectionString,
											   AcDbObjectId& idDataLink);
	ACDB_PORT int dataLinkCount() const;
	ACDB_PORT Acad::ErrorStatus getDataLink(const ACHAR* pszName, AcDbObjectId& idDataLink) const;
	ACDB_PORT Acad::ErrorStatus getDataLink(const ACHAR* pszName, AcDbDataLink*& pDataLink,
											AcDb::OpenMode mode) const;
	ACDB_PORT int getDataLink(AcDbObjectIdArray& dataLinks) const;
	Acad::ErrorStatus removeDataLink(const ACHAR* pszKey, AcDbObjectId& idDataLink);
	ACDB_PORT Acad::ErrorStatus removeDataLink(const AcDbObjectId& idDataLink);
	ACDB_PORT Acad::ErrorStatus update(const AcDbObjectIdArray& dataIds, AcDb::UpdateDirection nDir,
									   AcDb::UpdateOption nOption);
	ACDB_PORT Acad::ErrorStatus update(AcDb::UpdateDirection nDir, AcDb::UpdateOption nOption);
};

#include "IcArxPackPop.h"

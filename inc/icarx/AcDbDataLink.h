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
***     Description: Declaration of AcDbDataLink class
***
*****************************************************************************/
#pragma once

#include "AcDbObject.h"
#include "../AcString.h"

class AcValue;

#include "IcArxPackPush.h"

class AcDbDataLink : public AcDbObject
{
public:
	ACDB_DECLARE_MEMBERS(AcDbDataLink);

	ACDB_PORT AcDbDataLink();
	ACDB_PORT ~AcDbDataLink();

	ACDB_PORT const ACHAR* connectionString() const;
	ACDB_PORT const ACHAR* dataAdapterId() const;
	ACDB_PORT const ACHAR* description() const;
	ACDB_PORT Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	ACDB_PORT Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	ACDB_PORT Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	ACDB_PORT Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	ACDB_PORT Acad::ErrorStatus getCustomData(const ACHAR* pszKey, AcValue* pData) const;
	ACDB_PORT Acad::ErrorStatus getSourceFiles(AcDb::DataLinkGetSourceContext nContext,
											   AcStringArray& files) const;
	ACDB_PORT int getTargets(AcDbObjectIdArray& targetIds) const;
	ACDB_PORT AcString getToolTip() const;
	ACDBCORE2D_PORT Acad::ErrorStatus getUpdateStatus(AcDb::UpdateDirection* pDir, std::tm* pTime,
													  AcString* pErrMessage) const;
	ACDB_PORT bool isValid() const;
	ACDB_PORT AcString name() const;
	ACDB_PORT AcDb::DataLinkOption option() const;
	ACDB_PORT Acad::ErrorStatus repathSourceFiles(const wchar_t* pszBasePath,
												  AcDb::PathOption nOption);
	ACDB_PORT Acad::ErrorStatus setConnectionString(const ACHAR* pszConnectionString);
	ACDB_PORT Acad::ErrorStatus setCustomData(const ACHAR* pszKey, const AcValue* pData);
	ACDB_PORT Acad::ErrorStatus setDataAdapterId(const ACHAR* pszAdapterId);
	ACDB_PORT Acad::ErrorStatus setDescription(const ACHAR* pszDescription);
	ACDB_PORT Acad::ErrorStatus setName(const ACHAR* pszName);
	ACDB_PORT Acad::ErrorStatus setOption(AcDb::DataLinkOption nOption);
	ACDB_PORT Acad::ErrorStatus setToolTip(const ACHAR* pszToolTip);
	ACDB_PORT Acad::ErrorStatus setUpdateOption(int nOption);
	ACDB_PORT Acad::ErrorStatus setUpdateStatus(const ACHAR* pszErrMessage);
	ACDB_PORT Acad::ErrorStatus update(AcDb::UpdateDirection nDir, AcDb::UpdateOption nOption);
	ACDB_PORT int updateOption() const;
};

#include "IcArxPackPop.h"

typedef AcArray<AcDbDataLink*> AcDbDataLinkArray;

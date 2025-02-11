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
***     Description: Declaration of AcDbSectionManager class
***
*****************************************************************************/
#pragma once

#include "AcDbSection.h"

class AcDbSectionManagerIterator;

#include "IcArxPackPush.h"

class AcDbSectionManager : public AcDbObject
{
protected:
	ACDB_PORT Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbSectionManager);

	ACDB_PORT AcDbSectionManager();
	ACDB_PORT ~AcDbSectionManager();

	ACDB_PORT Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	ACDB_PORT Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	ACDB_PORT Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	ACDB_PORT Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	ACDB_PORT Acad::ErrorStatus getLiveSection(AcDbObjectId& id) const;
	ACDB_PORT Acad::ErrorStatus getLiveSection(AcDbSection*& pSecPlane, AcDb::OpenMode mode) const;
	ACDB_PORT Acad::ErrorStatus getSection(const ACHAR* pszName, AcDbObjectId& id) const;
	ACDB_PORT Acad::ErrorStatus getSection(const ACHAR* pszName, AcDbSection*& pSecPlane,
										   AcDb::OpenMode mode) const;
	ACDB_PORT Acad::ErrorStatus getUniqueSectionName(const ACHAR* pszBaseName,
													 AcString& sUniqueName) const;
	Acad::ErrorStatus getUniqueSectionName(const ACHAR* pszBaseName, ACHAR*& pszUniqueName) const;
	ACDB_PORT Acad::ErrorStatus newIterator(AcDbSectionManagerIterator*& pIterator) const;
	ACDB_PORT int numSections() const;
};

#include "IcArxPackPop.h"

inline Acad::ErrorStatus AcDbSectionManager::getUniqueSectionName(const ACHAR* pszBaseName,
																  ACHAR*& pszUniqueName) const
{
	AcString sUniqueName;
	return ::acutAcStringToAChar(sUniqueName, pszUniqueName,
								 this->getUniqueSectionName(pszBaseName, sUniqueName));
}

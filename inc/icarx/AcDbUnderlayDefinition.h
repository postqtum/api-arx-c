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
***     Description: Declaration of AcDbUnderlayDefinition class
***
*****************************************************************************/
#pragma once

#include "../dbmain.h"

class AcDbUnderlayItem;
class AcDbUnderlayHost;
class IAcReadStream;

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcDbUnderlayDefinition : public AcDbObject
{
private:
	virtual const AcDbUnderlayHost* getUnderlayHost() const = 0;

public:
	ACDB_DECLARE_MEMBERS(AcDbUnderlayDefinition);

	AcDbUnderlayDefinition();
	~AcDbUnderlayDefinition() = 0;

	static AcString dictionaryKey(const AcRxClass* underlayDefinitionType);
	Acad::ErrorStatus getActiveFileName(const ACHAR*& file) const;
	Acad::ErrorStatus getActiveFileName(AcString& file) const;
	const ACHAR* getItemName() const;
	IAcReadStream* getReadStream() const;
	const ACHAR* getSourceFileName() const;
	const AcDbUnderlayItem* getUnderlayItem() const;
	bool isLoaded() const;
	Acad::ErrorStatus load(const wchar_t* password);
	Acad::ErrorStatus setItemName(const ACHAR* item);
	Acad::ErrorStatus setSourceFileName(const ACHAR* file);
	Acad::ErrorStatus setUnderlayItem(const ACHAR* sourceFileName, const ACHAR* activeFileName,
									  AcDbUnderlayItem* pItem);
	void unload();
};

#include "IcArxPackPop.h"

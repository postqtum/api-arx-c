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
***     Description: Declaration of AcDbAttributeDefinition class
***
*****************************************************************************/
#pragma once

#include "AcDbText.h"
#include "../dbmtext.h"

#include "IcArxPackPush.h"

class AcDbAttributeDefinition : public AcDbText
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	AcDbAttributeDefinition();
	AcDbAttributeDefinition(const AcGePoint3d& position, const ACHAR* text, const ACHAR* tag,
							const ACHAR* prompt, AcDbObjectId style = AcDbObjectId::kNull);
	~AcDbAttributeDefinition();

	ACDB_DECLARE_MEMBERS(AcDbAttributeDefinition);

	Acad::ErrorStatus adjustAlignment(const AcDbDatabase* pDb = nullptr) override;
	Acad::ErrorStatus convertIntoMTextAttributeDefinition(bool val = true);
	uint16_t fieldLength() const;
	AcDbMText* getMTextAttributeDefinition() const;
	const AcDbMText* getMTextAttributeDefinitionConst() const;
	bool isConstant() const;
	bool isInvisible() const;
	bool isMTextAttributeDefinition() const;
	bool isPreset() const;
	bool isVerifiable() const;
	bool lockPositionInBlock() const;
	ACDBCORE2D_PORT Acad::ErrorStatus prompt(AcString& sTag) const;
	ACHAR* prompt() const;
	const ACHAR* promptConst() const;
	Acad::ErrorStatus setConstant(bool);
	Acad::ErrorStatus setFieldLength(uint16_t);
	Acad::ErrorStatus setInvisible(bool);
	Acad::ErrorStatus setLockPositionInBlock(bool bValue);
	Acad::ErrorStatus setMTextAttributeDefinition(AcDbMText*);
	ACDBCORE2D_PORT Acad::ErrorStatus setMTextAttributeDefinitionConst(const AcDbMText*);
	Acad::ErrorStatus setPreset(bool);
	Acad::ErrorStatus setPrompt(const ACHAR*);
	Acad::ErrorStatus setTag(const ACHAR*);
	Acad::ErrorStatus setVerifiable(bool);
	ACDBCORE2D_PORT Acad::ErrorStatus tag(AcString& sTag) const;
	ACHAR* tag() const;
	const ACHAR* tagConst() const;
	Acad::ErrorStatus updateMTextAttributeDefinition();
};

#include "IcArxPackPop.h"

inline ACHAR* AcDbAttributeDefinition::prompt() const
{
	return ::acutGetAcStringConvertToAChar(this, &AcDbAttributeDefinition::prompt);
}

inline ACHAR* AcDbAttributeDefinition::tag() const
{
	return ::acutGetAcStringConvertToAChar(this, &AcDbAttributeDefinition::tag);
}

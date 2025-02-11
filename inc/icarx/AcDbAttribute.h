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
***     Description: Declaration of AcDbAttribute class
***
*****************************************************************************/
#pragma once

#include "AcDbText.h"
#include "AcDbAttributeDefinition.h"

#include "IcArxPackPush.h"

class AcDbAttribute : public AcDbText
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	AcDbAttribute();
	AcDbAttribute(const AcGePoint3d& position, const ACHAR* text, const ACHAR* tag,
				  AcDbObjectId style = AcDbObjectId::kNull);
	~AcDbAttribute();

	ACDB_DECLARE_MEMBERS(AcDbAttribute);

	Acad::ErrorStatus convertIntoMTextAttribute(bool val = true);
	uint16_t fieldLength() const;
	AcDbMText* getMTextAttribute() const;
	const AcDbMText* getMTextAttributeConst() const;
	bool isConstant() const;
	bool isInvisible() const;
	bool isMTextAttribute() const;
	bool isPreset() const;
	bool isReallyLocked() const;
	bool isVerifiable() const;
	bool lockPositionInBlock() const;
	Acad::ErrorStatus setAttributeFromBlock(const AcGeMatrix3d& blkXform);
	Acad::ErrorStatus setAttributeFromBlock(const AcDbAttributeDefinition* pAttdef,
											const AcGeMatrix3d& blkXform);
	Acad::ErrorStatus setFieldLength(uint16_t);
	Acad::ErrorStatus setInvisible(bool);
	Acad::ErrorStatus setLockPositionInBlock(bool bValue);
	Acad::ErrorStatus setMTextAttribute(AcDbMText*);
	ACDBCORE2D_PORT Acad::ErrorStatus setMTextAttributeConst(const AcDbMText*);
	Acad::ErrorStatus setTag(const ACHAR* newTag);
	ACDBCORE2D_PORT Acad::ErrorStatus tag(AcString& sTag) const;
	ACHAR* tag() const;
	const ACHAR* tagConst() const;
	Acad::ErrorStatus updateMTextAttribute();
};

#include "IcArxPackPop.h"

inline ACHAR* AcDbAttribute::tag() const
{
	return ::acutGetAcStringConvertToAChar(this, &AcDbAttribute::tag);
}

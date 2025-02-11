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
***     Description: Declaration of AcDbDimStyleTableRecord classes
***
*****************************************************************************/
#pragma once

#include "acut_str_util.h"
#include "AcDbSymbolTableRecord.h"
#include "../dbdimvar.h"

class AcDbDimStyleTable;

#include "IcArxPackPush.h"

class AcDbDimStyleTableRecord : public AcDbSymbolTableRecord
{
public:
	using TableType = AcDbDimStyleTable;

protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbDimStyleTableRecord);

	AcDbDimStyleTableRecord();
	~AcDbDimStyleTableRecord();

	DIM_METHOD();

	AcDbObjectId arrowId(AcDb::DimArrowFlags whichArrow) const;
	int dimfit() const;
	int dimunit() const;
	Acad::ErrorStatus getDimapost(ACHAR*& pOutput) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getDimblk(AcString& sOutput) const;
	Acad::ErrorStatus getDimblk(ACHAR*& pOutput) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getDimblk1(AcString& sOutput) const;
	Acad::ErrorStatus getDimblk1(ACHAR*& pOutput) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getDimblk2(AcString& sOutput) const;
	Acad::ErrorStatus getDimblk2(ACHAR*& pOutput) const;
	Acad::ErrorStatus getDimpost(ACHAR*& pOutput) const;
	bool isModifiedForRecompute() const;
	Acad::ErrorStatus setDimfit(int fit);
	Acad::ErrorStatus setDimunit(int unit);
};

#include "IcArxPackPop.h"

inline Acad::ErrorStatus AcDbDimStyleTableRecord::getDimapost(ACHAR*& pOutput) const
{
	return ::acutNewString(this->dimapost(), pOutput);
}
inline Acad::ErrorStatus AcDbDimStyleTableRecord::getDimblk(ACHAR*& pOutput) const
{
	return ::acutGetAcStringConvertToAChar(this, &AcDbDimStyleTableRecord::getDimblk, pOutput);
}
inline Acad::ErrorStatus AcDbDimStyleTableRecord::getDimblk1(ACHAR*& pOutput) const
{
	return ::acutGetAcStringConvertToAChar(this, &AcDbDimStyleTableRecord::getDimblk1, pOutput);
}
inline Acad::ErrorStatus AcDbDimStyleTableRecord::getDimblk2(ACHAR*& pOutput) const
{
	return ::acutGetAcStringConvertToAChar(this, &AcDbDimStyleTableRecord::getDimblk2, pOutput);
}
inline Acad::ErrorStatus AcDbDimStyleTableRecord::getDimpost(ACHAR*& pOutput) const
{
	return ::acutNewString(this->dimpost(), pOutput);
}

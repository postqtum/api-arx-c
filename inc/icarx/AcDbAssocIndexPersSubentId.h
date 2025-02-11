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
***     Description: Declaration of AcDbAssocIndexPersSubentId class
***
*****************************************************************************/
#pragma once

#include "../AcDbAssocPersSubentId.h"

#include "IcArxPackPush.h"

class AcDbAssocIndexPersSubentId : public AcDbAssocPersSubentId
{
private:
	static const int kRoundTripOffset = 1000000;

private:
	virtual int roundTripOffset() const { return kRoundTripOffset; }

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbAssocIndexPersSubentId, ACDBCORE2D_PORT);

public:
	ACDBCORE2D_PORT explicit AcDbAssocIndexPersSubentId(
			AcDb::SubentType subentType = AcDb::kNullSubentType, unsigned int index = 0);
	ACDBCORE2D_PORT bool operator==(const AcDbAssocIndexPersSubentId& other) const;
	ACDBCORE2D_PORT bool operator<(const AcDbAssocIndexPersSubentId& other) const;

	ACDBCORE2D_PORT Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	ACDBCORE2D_PORT Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus dwgOutFieldsData(AcDbDwgFiler* pFiler) const;
	ACDBCORE2D_PORT Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	ACDBCORE2D_PORT Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus dxfOutFieldsData(AcDbDxfFiler* pFiler) const;
	ACDBCORE2D_PORT unsigned int index() const;
	ACDBCORE2D_PORT bool isNull() const override;
	ACDBCORE2D_PORT void setIndex(unsigned int newIndex);
	ACDBCORE2D_PORT void setSubentType(AcDb::SubentType subentType);
	ACDBCORE2D_PORT AcDb::SubentType subentType(const AcDbEntity*, AcDbDatabase*) const override;
};

#include "IcArxPackPop.h"

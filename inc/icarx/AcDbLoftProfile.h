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
***     Description: Declaration of AcDbLoftProfile class
***
*****************************************************************************/
#pragma once

#include "AcDb3dProfile.h"

#include "IcArxPackPush.h"

class AcDbLoftProfile : public AcDb3dProfile
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbLoftProfile, ACDB_PORT);

	ACDB_PORT AcDbLoftProfile();
	ACDB_PORT AcDbLoftProfile(const AcDbPathRef& pathRef);
	ACDB_PORT AcDbLoftProfile(const AcGePoint3d& pnt);
	ACDB_PORT AcDbLoftProfile(AcDbEntity* pEntity);
	ACDB_PORT AcDbLoftProfile(const AcDbLoftProfile& src);
	ACDB_PORT AcDbLoftProfile& operator=(const AcDbLoftProfile& src);
	ACDB_PORT AcDbLoftProfile& operator=(const AcDb3dProfile& src);

	ACDB_PORT int16_t continuity() const;
	ACDB_PORT Acad::ErrorStatus copyFrom(const AcRxObject* src) override;
	ACDB_PORT double magnitude() const;
	ACDB_PORT void setContinuity(int16_t value);
	ACDB_PORT void setMagnitude(double value);
};

#include "IcArxPackPop.h"

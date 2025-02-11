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
***     Description: Declaration of IAcPcDataBuffer class
***
*****************************************************************************/
#pragma once

#include "../acdbport.h"

class AcPcPointFloat;
class AcPcPointDouble;
class AcPcPointAttributes;
class AcGeMatrix3d;

#include "IcArxPackPush.h"

class ACDB_PORT IAcPcDataBuffer
{
public:
	virtual ~IAcPcDataBuffer() = 0 {};

	virtual void copyFrom(IAcPcDataBuffer const& from) = 0;
	virtual bool doublePoint(DWORD ptIx, AcPcPointDouble& pt) const = 0;
	virtual AcPcPointDouble* doublePoints() = 0;
	virtual bool entityTransform(AcGeMatrix3d& matrix) const = 0;
	virtual bool floatPoint(DWORD ptIx, AcPcPointFloat& pt) const = 0;
	virtual AcPcPointFloat* floatPoints() = 0;
	virtual bool nativeDbl() = 0;
	virtual bool offset(double& x, double& y, double& z) const = 0;
	virtual AcPcPointAttributes* pointAttributes() = 0;
	virtual bool resize(DWORD size) = 0;
	virtual bool setDoublePoint(DWORD ptIx, AcPcPointDouble& pt) = 0;
	virtual bool setFloatPoint(DWORD ptIx, AcPcPointFloat& pt) = 0;
	virtual bool shrink(DWORD size) = 0;
	virtual DWORD size() const = 0;
};

#include "IcArxPackPop.h"

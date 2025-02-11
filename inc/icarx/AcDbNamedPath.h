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
***     Description: Declaration of AcDbNamedPath class
***
*****************************************************************************/
#pragma once

#include "AcDbObject.h"
#include "SceneDllImpExp.h"

class AcGeCurve3d;

#include "IcArxPackPush.h"
#pragma warning(disable : 4275 4251)

class SCENEDLLIMPEXP AcDbNamedPath : public AcDbObject
{
	friend class AcDbImpNamedPath;

private:
	AcDbImpNamedPath* mpImp;

protected:
	AcDbNamedPath(AcDbImpNamedPath* pImp);
	AcDbImpNamedPath* imp() const;

public:
	ACRX_DECLARE_MEMBERS(AcDbNamedPath);

	~AcDbNamedPath();

	virtual Acad::ErrorStatus getGeometry(AcGeCurve3d*& pCurveGeometry) const = 0;
};

#include "IcArxPackPop.h"

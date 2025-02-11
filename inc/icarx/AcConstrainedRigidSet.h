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
***     Description: Declaration of AcConstrainedRigidSet class
***
*****************************************************************************/
#pragma once

#include "../gemat3d.h"

#include "AcConstrainedGeometry.h"

#include "IcArxPackPush.h"

class AcConstrainedRigidSet : public AcConstrainedGeometry
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcConstrainedRigidSet, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT explicit AcConstrainedRigidSet(bool bCreateImp = true);
	ACDBCORE2D_PORT explicit AcConstrainedRigidSet(bool bScalable, const AcGeMatrix3d& trans);

	ACDBCORE2D_PORT AcConstrainedGeometry* getConstrainedGeomAt(int index) const;
	ACDBCORE2D_PORT int numOfConstrainedGeoms() const;
	ACDBCORE2D_PORT AcGeMatrix3d transform() const;
};

#include "IcArxPackPop.h"

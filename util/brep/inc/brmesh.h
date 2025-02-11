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
***     Description: Declaration of AcBrMesh class
***
*****************************************************************************/
#pragma once

#include "inc/adesk.h"
#include "inc/rxobject.h"
#include "inc/rxboiler.h"
#include "brment.h"

#include "inc/icarx/IcArxPackPush.h"

class AcBrMesh : public AcBrMeshEntity
{
protected:
	AcBrMesh();
	AcBrMesh(const AcBrMesh&);
	AcBrMesh& operator=(const AcBrMesh&);

public:
	ACRX_DECLARE_MEMBERS(AcBrMesh);

	virtual ~AcBrMesh();
};

#include "inc/icarx/IcArxPackPop.h"

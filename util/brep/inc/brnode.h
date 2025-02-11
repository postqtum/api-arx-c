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
***     Description: Declaration of AcBrNode class
***
*****************************************************************************/
#pragma once

#include "inc/adesk.h"
#include "inc/rxobject.h"
#include "inc/rxboiler.h"
#include "inc/gegbl.h"
#include "brgbl.h"
#include "brment.h"

class AcGePoint3d;
class AcBrMeshEntity;
class AcBrNodeData;

#include "inc/icarx/IcArxPackPush.h"

class AcBrNode : public AcBrMeshEntity
{
public:
	ACRX_DECLARE_MEMBERS(AcBrNode);

	AcBrNode();
	AcBrNode(const AcBrNode& src);
	~AcBrNode();
	AcBrNode& operator=(const AcBrNode& src);
	AcBr::ErrorStatus get(AcBrNodeData*& nodeData) const;
	AcBr::ErrorStatus getPoint(AcGePoint3d& point) const;
	AcBr::ErrorStatus set(AcBrNodeData* nodeData);
};

#include "inc/icarx/IcArxPackPop.h"

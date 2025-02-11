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
***     Description: Declaration of AcLyLayerGroup class
***
*****************************************************************************/
#pragma once

#include "AcLyLayerFilter.h"
#include "../dbidar.h"

#include "IcArxPackPush.h"

class AcLyLayerGroup : public AcLyLayerFilter
{
protected:
	AcLyLayerGroup(AcLySystemInternals*);

public:
	ACRX_DECLARE_MEMBERS(AcLyLayerGroup);
	AcLyLayerGroup();

	virtual Acad::ErrorStatus addLayerId(const AcDbObjectId& id);
	virtual const AcDbObjectIdArray& layerIds() const;
	virtual Acad::ErrorStatus removeLayerId(const AcDbObjectId& id);
};

#include "IcArxPackPop.h"

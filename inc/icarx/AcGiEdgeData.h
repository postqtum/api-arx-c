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
***     Description: Declaration of AcGiEdgeData class
***
*****************************************************************************/
#pragma once

#include "../acgiparameter.h"

class AcGiImpEdgeData;
class AcCmEntityColor;
class AcDbObjectId;

#include "IcArxPackPush.h"

class AcGiEdgeData : public AcGiParameter
{
public:
	ACRX_DECLARE_MEMBERS_READWRITE_EXPIMP(AcGiEdgeData, AcGiImpEdgeData, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT AcGiEdgeData();
	ACDBCORE2D_PORT ~AcGiEdgeData();

	ACDBCORE2D_PORT virtual short* colors() const;
	ACDBCORE2D_PORT virtual AcDbObjectId* layerIds() const;
	ACDBCORE2D_PORT virtual AcDbObjectId* linetypeIds() const;
	ACDBCORE2D_PORT virtual IcArx::Integers::LongPtr* selectionMarkers() const;
	ACDBCORE2D_PORT virtual void setColors(const short* colors);
	ACDBCORE2D_PORT virtual void setLayers(const AcDbObjectId* layers);
	ACDBCORE2D_PORT virtual void setLineTypes(const AcDbObjectId* linetypes);
	ACDBCORE2D_PORT virtual void setSelectionMarkers(const IcArx::Integers::LongPtr* pSelectionMarkers);
	ACDBCORE2D_PORT virtual void setTrueColors(const AcCmEntityColor* colors);
	ACDBCORE2D_PORT virtual void setVisibility(const uint8_t* pVisibility);
	ACDBCORE2D_PORT virtual AcCmEntityColor* trueColors() const;
	ACDBCORE2D_PORT virtual uint8_t* visibility() const;
};

#include "IcArxPackPop.h"

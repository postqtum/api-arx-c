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
***     Description: Declaration of AcGiFaceData class
***
*****************************************************************************/
#pragma once

#include "../acgiparameter.h"

class AcGiImpFaceData;
class AcCmEntityColor;
class AcDbObjectId;
class AcGeVector3d;
class AcGiMapper;
class AcCmTransparency;

#include "IcArxPackPush.h"

class AcGiFaceData : public AcGiParameter
{
public:
	ACRX_DECLARE_MEMBERS_READWRITE_EXPIMP(AcGiFaceData, AcGiImpFaceData, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT AcGiFaceData();
	ACDBCORE2D_PORT ~AcGiFaceData();

	ACDBCORE2D_PORT virtual short* colors() const;
	ACDBCORE2D_PORT virtual AcDbObjectId* layerIds() const;
	ACDBCORE2D_PORT virtual AcGiMapper* mappers() const;
	ACDBCORE2D_PORT virtual AcDbObjectId* materials() const;
	ACDBCORE2D_PORT virtual AcGeVector3d* normals() const;
	ACDBCORE2D_PORT virtual IcArx::Integers::LongPtr* selectionMarkers() const;
	ACDBCORE2D_PORT virtual void setColors(const short* colors);
	ACDBCORE2D_PORT virtual void setLayers(const AcDbObjectId* layers);
	ACDBCORE2D_PORT virtual void setMappers(const AcGiMapper* mappers);
	ACDBCORE2D_PORT virtual void setMaterials(const AcDbObjectId* materials);
	ACDBCORE2D_PORT virtual void setNormals(const AcGeVector3d* pNormals);
	ACDBCORE2D_PORT virtual void setSelectionMarkers(const IcArx::Integers::LongPtr* pSelectionMarkers);
	ACDBCORE2D_PORT virtual void setTransparency(const AcCmTransparency* transparency);
	ACDBCORE2D_PORT virtual void setTrueColors(const AcCmEntityColor* colors);
	ACDBCORE2D_PORT virtual void setVisibility(const uint8_t* vis);
	ACDBCORE2D_PORT virtual AcCmTransparency* transparency() const;
	ACDBCORE2D_PORT virtual AcCmEntityColor* trueColors() const;
	ACDBCORE2D_PORT virtual uint8_t* visibility() const;
};

#include "IcArxPackPop.h"

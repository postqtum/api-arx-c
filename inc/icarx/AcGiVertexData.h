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
***     Description: Declaration of AcGiVertexData class
***
*****************************************************************************/
#pragma once

#include "../acgiparameter.h"
#include "../acgidefs.h"

class AcGiImpVertexData;
class AcCmEntityColor;
class AcGeVector3d;
class AcGePoint3d;

#include "IcArxPackPush.h"

class AcGiVertexData : public AcGiParameter
{
public:
	enum MapChannel
	{
		kAllChannels,
		kMapChannels
	};

	ACRX_DECLARE_MEMBERS_READWRITE_EXPIMP(AcGiVertexData, AcGiImpVertexData, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT AcGiVertexData();
	ACDBCORE2D_PORT ~AcGiVertexData();

	ACDBCORE2D_PORT virtual AcGePoint3d* mappingCoords(MapChannel mapChannel) const;
	ACDBCORE2D_PORT virtual AcGeVector3d* normals() const;
	ACDBCORE2D_PORT virtual AcGiOrientationType orientationFlag() const;
	ACDBCORE2D_PORT virtual void setMappingCoords(MapChannel mapChannel,
												  const AcGePoint3d* pCoords);
	ACDBCORE2D_PORT virtual void setNormals(const AcGeVector3d* pNormals);
	ACDBCORE2D_PORT virtual void setOrientationFlag(const AcGiOrientationType oflag);
	ACDBCORE2D_PORT virtual void setTrueColors(const AcCmEntityColor* colors);
	ACDBCORE2D_PORT virtual AcCmEntityColor* trueColors() const;
};

#include "IcArxPackPop.h"

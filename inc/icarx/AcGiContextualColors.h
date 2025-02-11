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
***     Description: Declaration of AcGiContextualColors and AcGiContextualColors2 classes
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../rxboiler.h"

class AcCmColor;

#include "IcArxPackPush.h"

class AcGiContextualColors : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcGiContextualColors);

	virtual uint32_t cameraClipping() const = 0;
	virtual uint32_t cameraFrustrum() const = 0;
	virtual uint32_t cameraGlyphs() const = 0;
	virtual bool flagsSet(uint32_t flg) const = 0;
	virtual int gridAxisLineTintXYZ() const = 0;
	virtual uint32_t gridAxisLines() const = 0;
	virtual int gridMajorLineTintXYZ() const = 0;
	virtual uint32_t gridMajorLines() const = 0;
	virtual int gridMinorLineTintXYZ() const = 0;
	virtual uint32_t gridMinorLines() const = 0;
	virtual uint32_t lightEndLimit() const = 0;
	virtual uint32_t lightFalloff() const = 0;
	virtual uint32_t lightGlyphs() const = 0;
	virtual uint32_t lightHotspot() const = 0;
	virtual uint32_t lightStartLimit() const = 0;
	virtual void setContextFlags(uint32_t flg, bool set = true) = 0;
};

class AcGiContextualColors2 : public AcGiContextualColors
{
public:
	ACRX_DECLARE_MEMBERS(AcGiContextualColors2);

	virtual AcCmColor lightDistanceColor() const = 0;
	virtual AcCmColor lightShapeColor() const = 0;
	virtual AcCmColor webMeshColor() const = 0;
	virtual AcCmColor webMeshMissingColor() const = 0;
};

#include "IcArxPackPop.h"

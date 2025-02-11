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
***     Description: Declaration of AcDbProxyEntity class
***
*****************************************************************************/
#pragma once

#include "AcDbProxyObject.h"

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcDbProxyEntity : public AcDbEntity
{
public:
	enum
	{
		kNoOperation = 0,
		kEraseAllowed = 0x1,
		kTransformAllowed = 0x2,
		kColorChangeAllowed = 0x4,
		kLayerChangeAllowed = 0x8,
		kLinetypeChangeAllowed = 0x10,
		kLinetypeScaleChangeAllowed = 0x20,
		kVisibilityChangeAllowed = 0x40,
		kCloningAllowed = 0x80,
		kLineWeightChangeAllowed = 0x100,
		kPlotStyleNameChangeAllowed = 0x200,
		kAllButCloningAllowed = 0x37F,
		kAllAllowedBits = 0xBFF,
		kDisableProxyWarning = 0x400,
		kMaterialChangeAllowed = 0x800,
	};

	enum GraphicsMetafileType
	{
		kNoMetafile = 0,
		kBoundingBox = 1,
		kFullGraphics = 2
	};

public:
	ACRX_DECLARE_MEMBERS(AcDbProxyEntity);

	~AcDbProxyEntity() = default;

	virtual const ACHAR* applicationDescription() const = 0;
	virtual Acad::ErrorStatus getReferences(AcDbObjectIdArray&, AcDbIntArray&) const = 0;
	virtual AcDbProxyEntity::GraphicsMetafileType graphicsMetafileType() const = 0;
	virtual const ACHAR* originalClassName() const = 0;
	virtual const ACHAR* originalDxfName() const = 0;
	virtual int proxyFlags() const = 0;
};

#include "IcArxPackPop.h"

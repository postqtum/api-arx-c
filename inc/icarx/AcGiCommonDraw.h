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
***     Description: Declaration of AcGiCommonDraw, AcGiWorldDraw, AcGiViewportDraw classes
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../rxboiler.h"
#include "../acgidefs.h"

class AcGiSubEntityTraits;
class AcGiGeometry;
class AcGePoint3d;
class AcGiContext;
class AcGiWorldGeometry;
class AcGiViewport;
class AcGiViewportGeometry;
class AcDbObjectId;

#include "IcArxPackPush.h"

class AcGiCommonDraw : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcGiCommonDraw);

	virtual AcGiContext* context() = 0;
	virtual double deviation(const AcGiDeviationType, const AcGePoint3d&) const = 0;
	virtual bool isDragging() const = 0;
	virtual uint32_t numberOfIsolines() const = 0;
	virtual AcGiGeometry* rawGeometry() const = 0;
	virtual bool regenAbort() const = 0;
	virtual AcGiRegenType regenType() const = 0;
	virtual bool secondaryCall() const { return false; }
	virtual AcGiSubEntityTraits& subEntityTraits() const = 0;
};

class AcGiWorldDraw : public AcGiCommonDraw
{
public:
	ACRX_DECLARE_MEMBERS(AcGiWorldDraw);

	virtual AcGiWorldGeometry& geometry() const = 0;
};

class AcGiViewportDraw : public AcGiCommonDraw
{
public:
	ACRX_DECLARE_MEMBERS(AcGiViewportDraw);

	virtual AcGiViewportGeometry& geometry() const = 0;
	virtual bool isValidId(const IcArx::Integers::ULongPtr acgiId) const = 0;
	virtual uint32_t sequenceNumber() const = 0;
	virtual AcGiViewport& viewport() const = 0;
	virtual AcDbObjectId viewportObjectId() const = 0;
};

#include "IcArxPackPop.h"

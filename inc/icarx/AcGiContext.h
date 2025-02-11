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
***     Description: Declaration of AcGiContext class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../rxboiler.h"
#include "../gepnt3d.h"
#include "../dbcolor.h"
#include "../acdb.h"
#include "../dbid.h"
#include "../PAL/api/charset.h"
#include "AcGiKernelDescriptor.h"

class AcDbDatabase;
class AcGiContextImp;
class AcFontHandle;
struct TextParams;
struct FontInfo;
class AcGiKernelDescriptor;

typedef void (*AcGiWorldSegmentCallback)(const AcGePoint3d*);

#include "IcArxPackPush.h"

class AcGiContext : public AcRxObject
{
	friend class AcGiTextHook;
	friend class CShFont;
	friend class AcDbImpText;

protected:
	virtual void bypassHiddenLineRemoval() {}
	virtual int drawTrueTypeText(const ACHAR*, double, int, bool, const TextParams&, Charset)
	{
		return 0;
	}
	virtual int getTrueTypeBoundingBox(AcGePoint3d const& /*location*/, const wchar_t* /*text*/,
									   int /*length*/, TextParams const* /*tp*/,
									   AcGePoint3d* /*bbox*/, float* /*char_widths*/)
	{
		return 0;
	}
	virtual int getTrueTypeTextExtents(ACHAR const*, Charset, double, int, int, int, short, int,
									   double, double, AcGePoint2d&, AcGePoint2d&)
	{
		return -1;
	}
	virtual AcFontHandle* loadTrueTypeFont(const ACHAR*, bool, bool, Charset, int, FontInfo&)
	{
		return nullptr;
	}
	virtual int restoreTrueTypeTransform() { return 0; }
	virtual int setTextStyle(int);
	virtual int setTrueTypeTransform(const AcGePoint3d&, const AcGeVector3d&, double, double,
									 double, bool, bool)
	{
		return 0;
	}
	virtual AcGiWorldSegmentCallback wSegTaker() const { return nullptr; }

public:
	ACRX_DECLARE_MEMBERS(AcGiContext);

	virtual AcDb::LineWeight byBlockLineWeight() const { return AcDb::kLnWt000; }
	virtual AcDbObjectId byBlockMaterialId() const { return AcDbObjectId::kNull; }
	virtual AcDbObjectId byBlockPlotStyleNameId() const { return AcDbObjectId::kNull; }
	virtual AcDbDatabase* database() const = 0;
	virtual void disableFastMoveDrag() const {}
	virtual AcCmEntityColor effectiveColor() const { return AcCmEntityColor(); }
	virtual const AcGiContextImp* getConstImpPtr() const { return nullptr; }
	virtual AcGiContextImp* getImpPtr() { return nullptr; }
	ACDBCORE2D_PORT virtual AcGiGraphicsKernel& graphicsKernel();
	virtual bool isBoundaryClipping() const = 0;
	virtual bool isNesting() const { return false; }
	virtual bool isPlotGeneration() const = 0;
	virtual bool isPsOut() const = 0;
	virtual bool supportsFastRenderBuffer() const { return false; }
	virtual bool supportsFillTrait() const { return false; }
	virtual bool supportsNativePointCloudRender() const { return false; }
	virtual bool supportsOwnerDraw() { return false; }
	virtual bool supportsTrueTypeText() { return false; }
};

#include "IcArxPackPop.h"

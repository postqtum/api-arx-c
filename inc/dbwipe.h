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
***     Description: Declaration of AcDbWipeout class
***
*****************************************************************************/
#pragma once

#ifdef _DBWIPEOBJ_
#	define DLLIMPEXP __declspec(dllexport)
#else
#	define DLLIMPEXP
#endif

#include "imgdef.h"
#include "imgent.h"

namespace Atil
{
class Image;
};

#define WIPEOUTOBJSERVICE /*NOXLATE*/ ACRX_T("WipeOut")

#include "icarx/IcArxPackPush.h"
#pragma warning(disable : 4275)

class DLLIMPEXP AcDbWipeout : public AcDbRasterImage
{
public:
	static long mImageData;

private:
	void* operator new[](size_t nSize) noexcept { return nullptr; }
	void operator delete[](void* p) {}
	void* operator new[](size_t nSize, const char* file, int line) noexcept { return nullptr; }

protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
	Acad::ErrorStatus subGetTransformedCopy(const AcGeMatrix3d& xform,
											AcDbEntity*& ent) const override;
	void subList() const override;
	Acad::ErrorStatus subMoveGripPointsAt(const AcDbVoidPtrArray& gripAppData,
										  const AcGeVector3d& offset, const int bitflags) override;
	Acad::ErrorStatus subMoveGripPointsAt(const AcDbIntArray& indices,
										  const AcGeVector3d& offset) override;
	uint32_t subSetAttributes(AcGiDrawableTraits* traits) override;
	Acad::ErrorStatus subTransformBy(const AcGeMatrix3d& xform) override;
	void subViewportDraw(AcGiViewportDraw* mode) override;
	bool subWorldDraw(AcGiWorldDraw* mode) override;

public:
	ACRX_DECLARE_MEMBERS(AcDbWipeout);

	AcDbWipeout();

	Acad::ErrorStatus append(AcDbObjectId& id);
	int8_t brightness() const override;
	AcRxObject* clone() const override;
	int8_t contrast() const override;
	static Acad::ErrorStatus createImageDefinition();
	int8_t fade() const override;
	static Acad::ErrorStatus fitPointsToImage(AcGePoint2dArray& pointArray, AcGePoint2d& minPoint,
											  double& scale, bool bFlipY = false);
	bool frame() const;
	AcGiSentScanLines* getScanLines(const AcGiRequestScanLines& req) const override;
	AcGeVector2d imageSize(bool bGetCachedValue = false) const override;
	bool isClipped() const;
	bool isSetDisplayOpt(ImageDisplayOpt option) const override;
	AcGeVector2d scale() const override;
	Acad::ErrorStatus setBrightness(int8_t value) override;
	Acad::ErrorStatus setContrast(int8_t value) override;
	void setDisplayOpt(ImageDisplayOpt option, bool bValue) override;
	Acad::ErrorStatus setFade(int8_t value) override;
};

#include "icarx/IcArxPackPop.h"

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
***     Description:
***
*****************************************************************************/
#pragma once

#include "dbmain.h"
#include "imgdef.h"
#include "icarx/IsmDllAccess.h"

class AcDbImpRasterVariables;

#include "icarx/IcArxPackPush.h"
#pragma warning(disable : 4275)

class ISMDLLACCESS AcDbRasterVariables : public AcDbObject
{
public:
	enum FrameSettings
	{
		kImageFrameInvalid = -1,
		kImageFrameOff = 0,
		kImageFrameAbove = 1,
		kImageFrameBelow = 2,
		kImageFrameOnNoPlot = 3
	};

	enum ImageQuality
	{
		kImageQualityInvalid = -1,
		kImageQualityDraft = 0,
		kImageQualityHigh = 1
	};

private:
	AcDbImpRasterVariables* mpImp = nullptr;
	static ClassVersion mVersion;

private:
	void operator delete[](void*){};
	void* operator new[](size_t) noexcept { return nullptr; }
	void* operator new[](size_t, const char*, int) noexcept { return nullptr; }

public:
	ACRX_DECLARE_MEMBERS(AcDbRasterVariables);

	AcDbRasterVariables();
	~AcDbRasterVariables();

	static ClassVersion classVersion() { return mVersion; }
	static AcDbRasterVariables* create();
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* filer) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* filer) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* filer) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* filer) const override;
	virtual FrameSettings imageFrame() const;
	virtual ImageQuality imageQuality() const;
	static AcDbRasterVariables* openRasterVariables(AcDb::OpenMode mode,
													AcDbDatabase* pDatabase = 0);
	virtual Acad::ErrorStatus setImageFrame(FrameSettings value);
	virtual Acad::ErrorStatus setImageQuality(ImageQuality value);
	virtual Acad::ErrorStatus setUserScale(AcDbRasterImageDef::Units units);
	virtual AcDbRasterImageDef::Units userScale() const;
};

#pragma warning(default : 4275)
#include "icarx/IcArxPackPop.h"

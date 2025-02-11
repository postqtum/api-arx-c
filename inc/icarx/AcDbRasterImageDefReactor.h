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
***     Description: Declaration of AcDbRasterImageDefReactor class
***
*****************************************************************************/
#pragma once

#include "../dbmain.h"

#include "IsmDllAccess.h"
#include "AcDbRasterImageDef.h"

#include "IcArxPackPush.h"
#pragma warning(disable : 4275)

class ISMDLLACCESS AcDbRasterImageDefReactor : public AcDbObject
{
public:
	enum DeleteImageEvent
	{
		kUnload = 1,
		kErase = 2,
	};

private:
	static ClassVersion mVersion;

public:
	ACRX_DECLARE_MEMBERS(AcDbRasterImageDefReactor);

	AcDbRasterImageDefReactor();
	~AcDbRasterImageDefReactor();

	static ClassVersion classVersion() { return mVersion; }
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* filer) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* filer) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* filer) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* filer) const override;
	void erased(const AcDbObject* dbObj, bool pErasing = true) override;
	void modified(const AcDbObject* dbObj) override;
	virtual bool onDeleteImage(const AcDbRasterImageDef* pImageDef, const Atil::Image* pImage,
							   DeleteImageEvent event, bool cancelAllowed);
	static void setEnable(bool enable);
};

#include "IcArxPackPop.h"

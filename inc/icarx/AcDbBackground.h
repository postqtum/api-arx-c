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
***     Description: Declaration of AcDbBackground class
***
*****************************************************************************/
#pragma once

#include "AcDbObject.h"

#undef SCENEDLLIMPEXP
#ifdef SCENEOE
#	define SCENEDLLIMPEXP __declspec(dllexport)
#else
#	define SCENEDLLIMPEXP	//__declspec( dllimport )
#endif

class AcDbImpBackground;

#include "IcArxPackPush.h"
#pragma warning(disable : 4275 4251)

class SCENEDLLIMPEXP AcDbBackground : public AcDbObject
{
	friend class AcDbImpBackground;
protected:
	AcDbBackground(AcDbImpBackground* pImp);

	AcDbImpBackground* imp() const;

public:
	ACRX_DECLARE_MEMBERS(AcDbBackground);

	~AcDbBackground();

	AcGiDrawable* drawable() override;
};

#include "IcArxPackPop.h"

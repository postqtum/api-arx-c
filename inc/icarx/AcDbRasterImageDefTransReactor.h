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
***     Description: Declaration of AcDbRasterImageDefTransReactor class
***
*****************************************************************************/
#pragma once

#include "AcDbObjectReactor.h"
#include "AcDbRasterImageDef.h"
#include "AcDbRasterImageDefReactor.h"

#include "IcArxPackPush.h"
#pragma warning(disable : 4275)

class ISMDLLACCESS AcDbRasterImageDefTransReactor : public AcDbObjectReactor
{
public:
	ACRX_DECLARE_MEMBERS(AcDbRasterImageDefTransReactor);

	~AcDbRasterImageDefTransReactor();

	virtual bool onDeleteImage(const AcDbRasterImageDef* pImageDef, const Atil::Image* pImage,
							   AcDbRasterImageDefReactor::DeleteImageEvent imageEvent,
							   bool cancelAllowed) = 0;
};

#include "IcArxPackPop.h"


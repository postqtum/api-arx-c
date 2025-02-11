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
***     Description: Declaration of AcDbRasterImageDefFileAccessReactor class
***
*****************************************************************************/
#pragma once

#include "AcDbObjectReactor.h"
#include "AcDbRasterImageDef.h"

#include "IcArxPackPush.h"
#pragma warning(disable : 4275)

class ISMDLLACCESS AcDbRasterImageDefFileAccessReactor : public AcDbObjectReactor
{
public:
	ACRX_DECLARE_MEMBERS(AcDbRasterImageDefFileAccessReactor);

	~AcDbRasterImageDefFileAccessReactor();

	virtual void onAttach(const AcDbRasterImageDef*, const ACHAR* pPath) = 0;
	virtual void onClose(const AcDbRasterImageDef*, const ACHAR* pPath) = 0;
	virtual void onDetach(const AcDbRasterImageDef*, const ACHAR* pPath) = 0;
	virtual void onDialog(AcDbRasterImageDef*, const ACHAR* pCaption,
						  const ACHAR* pFileExtensions) = 0;
	virtual bool onOpen(const AcDbRasterImageDef*, const ACHAR* pPath, const ACHAR* pActivePath,
						bool& replacePath, ACHAR*& replacementPath) = 0;
	virtual bool onPathChange(const AcDbRasterImageDef*, const ACHAR* pPath,
							  const ACHAR* pActivePath, bool& replacePath,
							  ACHAR*& replacementPath) = 0;
};

#include "IcArxPackPop.h"


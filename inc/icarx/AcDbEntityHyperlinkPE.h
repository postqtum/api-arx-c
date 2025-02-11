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
***     Description: Declaration of AcDbEntityHyperlinkPE class
***
*****************************************************************************/
#pragma once

#include "../AdAChar.h"
#include "../rxobject.h"
#include "../acarray.h"
#include "AcDbObjectId.h"

class AcDbObject;
class AcDbHyperlinkCollection;

#include "IcArxPackPush.h"

class AcDbEntityHyperlinkPE : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcDbEntityHyperlinkPE);

	virtual Acad::ErrorStatus getHyperlinkCollection(const AcArray<AcDbObjectId>*& idContainers,
													 AcDbHyperlinkCollection*& pcHCL,
													 bool bOneOnly = false,
													 bool bIgnoreBlockDefinition = true) = 0;
	virtual Acad::ErrorStatus getHyperlinkCollection(AcDbObject* pObj,
													 AcDbHyperlinkCollection*& pcHCL,
													 bool bOneOnly = false,
													 bool bIgnoreBlockDefinition = true) = 0;
	virtual Acad::ErrorStatus getHyperlinkCount(const AcArray<AcDbObjectId>*& idContainers,
												unsigned int& nCount,
												bool bIgnoreBlockDefinition = true) = 0;
	virtual Acad::ErrorStatus getHyperlinkCount(AcDbObject* pObj, unsigned int& nCount,
												bool bIgnoreBlockDefinition = true) = 0;
	virtual Acad::ErrorStatus hasHyperlink(const AcArray<AcDbObjectId>*& idContainers,
										   bool& bHasHyperlink,
										   bool bIgnoreBlockDefinition = true) = 0;
	virtual Acad::ErrorStatus hasHyperlink(AcDbObject* pObj, bool& bHasHyperlink,
										   bool bIgnoreBlockDefinition = true) = 0;
	virtual Acad::ErrorStatus setHyperlinkCollection(AcDbObject* pObj,
													 AcDbHyperlinkCollection* pcHCL) = 0;
};

#include "IcArxPackPop.h"

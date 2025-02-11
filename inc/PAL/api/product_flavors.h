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
***     Description: ProdIdCode enumeration
***
*****************************************************************************/
#pragma once

#ifndef OBJARX_EXCLUDE_CONFLICTS
enum ProdIdCode
{
	kProd_ACAD = 1,
	kProd_OEM = 3,
	kProd_AcDb = 4,
};
#else
#	define kProd_AcDb kProd_OdDb
#endif

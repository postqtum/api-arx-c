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

#include <vector>

typedef int PROPCAT;

#include "IcArxPackPush.h"

struct CATEGORY_ENTRY
{
	PROPCAT m_CatID;
	UINT m_nNameId;
	UINT m_nDescId;
	PROPCAT m_ParentCatID;
	long m_nWeight;
};

#include "IcArxPackPop.h"

#define BEGIN_CAT_MAP()                  \
	static CATEGORY_ENTRY* GetCatArray() \
	{                                    \
		static CATEGORY_ENTRY pCatArray[] = {

#define CATEGORY_MAP_ENTRY(nId, NameId, DescId, nParentId, nWeight) \
	{nId, NameId, DescId, nParentId, nWeight},

#define END_CAT_MAP()    \
	{                    \
		-1, 0, 0, -1, -1 \
	}                    \
	}                    \
	;                    \
	return pCatArray;    \
	}

typedef std::vector<CATEGORY_ENTRY> CATEGORY_VECTOR;

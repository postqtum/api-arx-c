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

#include "../AdAChar.h"

typedef int PROPCAT;

#include "IcArxPackPush.h"

struct ACAD_OPMPROPMAP_ENTRY
{
	UINT nDescID;
	DISPID dispid;
	PROPCAT catid;
	UINT nCatNameID;
	UINT nElementStrID;
	UINT nPredefinedStrID;
	const ACHAR* predefinedValues;
	unsigned short grouping;
	bool editable;
	const CLSID* pclsidOther;
	const CLSID* pclsidPropPage;
	const IID* piidDispatch;
	LPCOLESTR szEllipsesTxt;
};

#include "IcArxPackPop.h"

#define BEGIN_OPMPROP_MAP()                           \
	static ACAD_OPMPROPMAP_ENTRY* GetOPMPropertyMap() \
	{                                                 \
		static ACAD_OPMPROPMAP_ENTRY pPropMap[] = {

#define OPMPROP_ENTRY(nDesID, dpid, ctid, ctNameID, elementsID, predefID, vals, grp, editable, \
					  other, clsid, ellipsesTxt)                                               \
	{nDesID, dpid,	   ctid,   ctNameID, elementsID,	 predefID,			 vals,             \
	 grp,	 editable, &other, &clsid,	 &IID_IDispatch, OLESTR(ellipsesTxt)},

#define OPMPROP_CAT_ENTRY(nDesID, dpid, ctid, ctNameID)                          \
	{nDesID, dpid,		ctid,	   ctNameID,	   0,		  0, _ACRX_T(""), 0, \
	 1,		 &IID_NULL, &IID_NULL, &IID_IDispatch, OLESTR("")},

#define OPMPROP_DESC_ENTRY(nDesID, dpid)                                          \
	{nDesID,	dpid,			-2,		   0, 0, 0, _ACRX_T(""), 0, 1, &IID_NULL, \
	 &IID_NULL, &IID_IDispatch, OLESTR("")},

#define OPMPROP_PREDEFINED_ENTRY(nDesID, dpid, predefID, values, other) \
	{nDesID, dpid, -2, 0, 0, predefID, values, 0, 1, &other, &IID_NULL, &IID_IDispatch, OLESTR("")},

#define OPMPROP_ELEMENT_ENTRY(dpid, ctid, ctNameID, elementsID, grouping)          \
	{0,		   dpid, ctid,		ctNameID,  elementsID,	   0,		  _ACRX_T(""), \
	 grouping, 1,	 &IID_NULL, &IID_NULL, &IID_IDispatch, OLESTR("")},

#define OPMPROP_PAGE(nDesID, dpid, ctid, ctNameID, clsid)                     \
	{nDesID, dpid,		ctid,	ctNameID,		0,		   0, _ACRX_T(""), 0, \
	 1,		 &IID_NULL, &clsid, &IID_IDispatch, OLESTR("")},

#define END_OPMPROP_MAP()                                         \
	{                                                             \
		0, 0, 0, 0, 0, 0, NULL, 0, 0, NULL, NULL, &IID_NULL, NULL \
	}                                                             \
	}                                                             \
	;                                                             \
	return pPropMap;                                              \
	}

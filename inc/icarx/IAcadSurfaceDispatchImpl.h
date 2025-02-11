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
***     Description: Declaration of IAcadSurfaceDispatchImpl class
***
*****************************************************************************/
#pragma once

#include "IAcadEntityDispatchImpl.h"

#include "IcArxPackPush.h"

template<class C, const CLSID* pclsid, class T, const IID* piid, const GUID* plibid,
		 WORD wMajor = 1, WORD wMinor = 0, class tihclass = CComTypeInfoHolder>
class ATL_NO_VTABLE IAcadSurfaceDispatchImpl
		: public IAcadEntityDispatchImpl<C, pclsid, T, piid, plibid, wMajor, wMinor, tihclass>
{
public:
	STDMETHOD(get_EdgeExtensionDistances)(VARIANT* extDistances)
	{
		return AcAxGetEdgeExtensionDistances(m_objId, extDistances);
	}
	STDMETHOD(get_MaintainAssociativity)(int* maintainAssoc)
	{
		return AcAxGetMaintainAssociativity(m_objId, maintainAssoc);
	}
	STDMETHOD(get_ShowAssociativity)(VARIANT_BOOL* bEnabled)
	{
		return AcAxGetShowAssociativity(m_objId, bEnabled);
	}
	STDMETHOD(get_SurfTrimAssociativity)(VARIANT* associative)
	{
		return AcAxGetSurfTrimAssociativity(m_objId, associative);
	}
	STDMETHOD(get_UIsolineDensity)(long* density)
	{
		return AcAxGet_UIsolineDensity(m_objId, density);
	}
	STDMETHOD(get_VIsolineDensity)(long* density)
	{
		return AcAxGet_VIsolineDensity(m_objId, density);
	}
	STDMETHOD(get_WireframeType)(AcWireframeType* type)
	{
		return AcAxGet_WireframeType(m_objId, type);
	}
	STDMETHOD(put_EdgeExtensionDistances)(VARIANT extDistances)
	{
		return AcAxPutEdgeExtensionDistances(m_objId, extDistances);
	}
	STDMETHOD(put_MaintainAssociativity)(int maintainAssoc)
	{
		return AcAxPutMaintainAssociativity(m_objId, maintainAssoc);
	}
	STDMETHOD(put_ShowAssociativity)(VARIANT_BOOL bEnabled)
	{
		return AcAxPutShowAssociativity(m_objId, bEnabled);
	}
	STDMETHOD(put_SurfTrimAssociativity)(VARIANT associative)
	{
		return AcAxPutSurfTrimAssociativity(m_objId, associative);
	}
	STDMETHOD(put_UIsolineDensity)(long density)
	{
		return AcAxPut_UIsolineDensity(m_objId, density);
	}
	STDMETHOD(put_VIsolineDensity)(long density)
	{
		return AcAxPut_VIsolineDensity(m_objId, density);
	}
	STDMETHOD(put_WireframeType)(AcWireframeType type)
	{
		return AcAxPut_WireframeType(m_objId, type);
	}
};

#include "IcArxPackPop.h"

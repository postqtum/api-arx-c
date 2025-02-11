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
***     Description: Declaration of IAcadEntityDispatchImpl class
***
*****************************************************************************/
#pragma once

#include "IAcadObjectDispatchImpl.h"

#include "IcArxPackPush.h"

template<class C, const CLSID* pclsid, class T, const IID* piid, const GUID* plibid,
		 WORD wMajor = 1, WORD wMinor = 0, class tihclass = CComTypeInfoHolder>
class ATL_NO_VTABLE IAcadEntityDispatchImpl
		: public IAcadObjectDispatchImpl<C, pclsid, T, piid, plibid, wMajor, wMinor, tihclass>
{
public:
	STDMETHODIMP ArrayPolar(int numObjs, double fillAngle, VARIANT basePoint, VARIANT* pArrayObjs)
	{
		return AcAxArrayPolar(this->m_objRef, this->m_App, numObjs, fillAngle, basePoint, pArrayObjs);
	}
	STDMETHODIMP ArrayRectangular(int numRows, int numCols, int numLvls, double disRows,
								  double disCols, double disLvls, VARIANT* pArrayObjs)
	{
		return AcAxArrayRectangular(this->m_objRef, this->m_App, numRows, numCols, numLvls, disRows, disCols,
									disLvls, pArrayObjs);
	}
	STDMETHODIMP Copy(LPDISPATCH* pCopyObj) { return AcAxCopy(this->m_objRef, this->m_App, pCopyObj); }
	STDMETHODIMP GetBoundingBox(VARIANT* minPoint, VARIANT* maxPoint)
	{
		return AcAxGetBoundingBox(this->m_objRef, minPoint, maxPoint);
	}
	STDMETHODIMP Highlight(VARIANT_BOOL bFlag) { return AcAxHighlight(this->m_objRef, bFlag); }
	STDMETHODIMP IntersectWith(LPDISPATCH pEntity, AcExtendOption option, VARIANT* intPoints)
	{
		return AcAxIntersectWith(this->m_objRef, pEntity, option, intPoints);
	}
	STDMETHODIMP Mirror(VARIANT point1, VARIANT point2, LPDISPATCH* pMirrorObj)
	{
		return AcAxMirror(this->m_objRef, this->m_App, point1, point2, pMirrorObj);
	}
	STDMETHODIMP Mirror3D(VARIANT point1, VARIANT point2, VARIANT point3, LPDISPATCH* pMirrorObj)
	{
		return AcAxMirror3D(this->m_objRef, this->m_App, point1, point2, point3, pMirrorObj);
	}
	STDMETHODIMP Move(VARIANT fromPoint, VARIANT toPoint)
	{
		return AcAxMove(this->m_objRef, fromPoint, toPoint);
	}
	STDMETHODIMP Rotate(VARIANT basePoint, double rotationAngle)
	{
		return AcAxRotate(this->m_objRef, basePoint, rotationAngle);
	}
	STDMETHODIMP Rotate3D(VARIANT point1, VARIANT point2, double rotationAngle)
	{
		return AcAxRotate3D(this->m_objRef, point1, point2, rotationAngle);
	}
	STDMETHODIMP ScaleEntity(VARIANT basePoint, double scaleFactor)
	{
		return AcAxScaleEntity(this->m_objRef, basePoint, scaleFactor);
	}
	STDMETHODIMP TransformBy(VARIANT transMatrix) { return AcAxTransformBy(this->m_objRef, transMatrix); }
	STDMETHODIMP Update() { return AcAxUpdate(this->m_objRef); }
	STDMETHODIMP get_Color(AcColor* pVal) { return AcAxGetColor(this->m_objRef, pVal); }
	STDMETHOD(get_EntityName)(BSTR* pVal) { return AcAxGetObjectName(this->m_objRef, pVal); }
	STDMETHOD(get_EntityType)(long* /*entType*/) { return E_NOTIMPL; }
	STDMETHODIMP get_EntityTransparency(BSTR* pVal) { return AcAxGetTransparency(this->m_objRef, pVal); }
	STDMETHODIMP get_Hyperlinks(IAcadHyperlinks** pHyperlinks)
	{
		return AcAxGetHyperlinks(this->m_objRef, this->m_App, pHyperlinks);
	}
	STDMETHODIMP get_Layer(BSTR* pVal) { return AcAxGetLayer(this->m_objRef, pVal); }
	STDMETHODIMP get_Linetype(BSTR* pVal) { return AcAxGetLinetype(this->m_objRef, pVal); }
	STDMETHODIMP get_LinetypeScale(double* pVal) { return AcAxGetLinetypeScale(this->m_objRef, pVal); }
	STDMETHODIMP get_Lineweight(ACAD_LWEIGHT* lineweight)
	{
		return AcAxGetLineWeight(this->m_objRef, lineweight);
	}
	STDMETHODIMP get_Material(BSTR* pVal) { return AcAxGetMaterial(this->m_objRef, pVal); }
	STDMETHODIMP get_PlotStyleName(BSTR* plotStyleName)
	{
		return AcAxGetPlotStyleName(this->m_objRef, plotStyleName);
	}
	STDMETHODIMP get_TrueColor(IAcadAcCmColor** pColor)
	{
		return AcAxGetTrueColor(this->m_objRef, pColor);
	}
	STDMETHODIMP get_Visible(VARIANT_BOOL* pVal) { return AcAxGetVisible(this->m_objRef, pVal); }
	STDMETHODIMP put_Color(AcColor newVal) { return AcAxPutColor(this->m_objRef, newVal); }
	STDMETHODIMP put_EntityTransparency(BSTR newVal)
	{
		return AcAxPutTransparency(this->m_objRef, newVal);
	}
	STDMETHODIMP put_Layer(BSTR newVal) { return AcAxPutLayer(this->m_objRef, newVal); }
	STDMETHODIMP put_Linetype(BSTR newVal) { return AcAxPutLinetype(this->m_objRef, newVal); }
	STDMETHODIMP put_LinetypeScale(double newVal) { return AcAxPutLinetypeScale(this->m_objRef, newVal); }
	STDMETHODIMP put_Lineweight(ACAD_LWEIGHT lineweight)
	{
		return AcAxPutLineWeight(this->m_objRef, lineweight);
	}
	STDMETHODIMP put_Material(BSTR newVal) { return AcAxPutMaterial(this->m_objRef, newVal); }
	STDMETHODIMP put_PlotStyleName(BSTR plotStyleName)
	{
		return AcAxPutPlotStyleName(this->m_objRef, plotStyleName);
	}
	STDMETHODIMP put_TrueColor(IAcadAcCmColor* color) { return AcAxPutTrueColor(this->m_objRef, color); }
	STDMETHODIMP put_Visible(VARIANT_BOOL newVal) { return AcAxPutVisible(this->m_objRef, newVal); }
};

#include "IcArxPackPop.h"

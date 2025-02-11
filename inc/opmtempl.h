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

#include "AdAChar.h"

#define ELEMENTGET 0
#define ELEMENTSET 1
#define ELEMENTCOUNT -1

struct OPMLPOLESTR;
struct OPMDWORD;
class AcDbObject;

#include "icarx/IcArxPackPush.h"

template<class T>
class ATL_NO_VTABLE IOPMPropertyExpanderImpl : public IOPMPropertyExpander
{
public:
	IOPMPropertyExpanderImpl() = default;
	virtual ~IOPMPropertyExpanderImpl() = default;

	STDMETHODIMP GetElementGrouping(
			/* [in] */ DISPID dispID,
			/* [out] */ short* groupingNumber)
	{
		ACAD_OPMPROPMAP_ENTRY* pMap = T::GetOPMPropertyMap();

		*groupingNumber = 0;
		for (int i = 0; pMap[i].pclsidPropPage != NULL; i++)
		{
			if (pMap[i].dispid == dispID)
			{
				*groupingNumber = pMap[i].grouping;
				break;
			}
		}

		return NOERROR;
	}
	STDMETHODIMP GetElementStrings(
			/* [in] */ DISPID dispID,
			/* [out] */ OPMLPOLESTR* pCaStringsOut,
			/* [out] */ OPMDWORD* pCaCookiesOut)
	{
		CComPtr<IAcadBaseObject> pAcadBaseObject;
		HRESULT hr = QueryInterface(IID_IAcadBaseObject, (LPVOID*)&pAcadBaseObject);
		if (FAILED(hr))
			return RAISEEXCEPTION1(IAcadObject, QueryInterfaceFail, _ACRX_T("IID_IAcadBaseObject"));

		AcDbObjectId objId;
		pAcadBaseObject->GetObjectId(&objId);

		ACAD_OPMPROPMAP_ENTRY* pMap = T::GetOPMPropertyMap();

		LPOLESTR pNames = NULL;
		int elemCnt = 0;

		for (unsigned int i = 0; pMap[i].pclsidPropPage != NULL; i++)
		{
			if (pMap[i].dispid == dispID)
			{
				if (pMap[i].nElementStrID == 0)
					return E_UNEXPECTED;

				ACHAR strBuf[2048];

				int nBytes = LoadString(GetResourceInstance(), pMap[i].nElementStrID, strBuf,
										sizeof(strBuf) / sizeof(ACHAR));
				if (nBytes == 0)
					return E_UNEXPECTED;

				pNames = strBuf;
				if (pNames == NULL)
					return E_FAIL;

				LPOLESTR token = NULL;
				TCHAR* ptrTemp = NULL;
				token = wcstok_s(pNames, OLESTR(";"), &ptrTemp);

				pCaStringsOut->pElems = NULL;
				pCaCookiesOut->pElems = NULL;

				while (token != NULL)
				{
					elemCnt++;

					pCaStringsOut->pElems = (LPOLESTR*)CoTaskMemRealloc(pCaStringsOut->pElems,
																		sizeof(LPOLESTR) * elemCnt);
					pCaCookiesOut->pElems = (DWORD*)CoTaskMemRealloc(pCaCookiesOut->pElems,
																	 sizeof(DWORD) * elemCnt);
					pCaCookiesOut->pElems[elemCnt - 1] = elemCnt - 1;

					pCaStringsOut->pElems[elemCnt - 1] = SysAllocString(token);
					/* While there are tokens in "string" */
					/* Get next token: */
					token = wcstok_s(NULL, OLESTR(";"), &ptrTemp);
				}

				pCaStringsOut->cElems = elemCnt;
				pCaCookiesOut->cElems = elemCnt;

				return NOERROR;
			}
		}
		return E_NOTIMPL;
	}
	STDMETHODIMP GetElementValue(
			/* [in] */ DISPID dispID,
			/* [in] */ DWORD dwCookie,
			/* [out] */ VARIANT* pVarOut)
	{
		CComPtr<IAcadBaseObject> pAcadBaseObject;
		HRESULT hr = QueryInterface(IID_IAcadBaseObject, (LPVOID*)&pAcadBaseObject);
		if (FAILED(hr))
			return RAISEEXCEPTION1(IAcadObject, QueryInterfaceFail, _ACRX_T("IID_IAcadBaseObject"));

		AcDbObjectId objId;
		pAcadBaseObject->GetObjectId(&objId);

		hr = VariantClear(pVarOut);
		if (FAILED(hr))
			return hr;

		Acad::ErrorStatus es;
		AcDbObject* pObj = NULL;

		if ((es = acdbOpenAcDbObject(pObj, objId, AcDb::kForRead)) != Acad::eOk)
			return RAISEARXEXCEPTION(IAcadEntity, es);

		if (SetGetElementValue(ELEMENTGET, dispID, dwCookie, pVarOut, pObj) == FALSE)
		{
			pObj->close();
			return E_FAIL;
		}

		pObj->close();
		return S_OK;
	}
	STDMETHODIMP GetGroupCount(
			/* [in] */ DISPID dispID,
			/* [out] */ long* nGroupCnt)
	{
		CComPtr<IAcadBaseObject> pAcadBaseObject;
		HRESULT hr = QueryInterface(IID_IAcadBaseObject, (LPVOID*)&pAcadBaseObject);
		if (FAILED(hr))
			return RAISEEXCEPTION1(IAcadObject, QueryInterfaceFail, _ACRX_T("IID_IAcadBaseObject"));

		AcDbObjectId objId;
		pAcadBaseObject->GetObjectId(&objId);

		ACAD_OPMPROPMAP_ENTRY* pMap = T::GetOPMPropertyMap();

		Acad::ErrorStatus es;

		for (unsigned int i = 0; pMap[i].pclsidPropPage != NULL; i++)
		{
			if (pMap[i].dispid == dispID)
			{
				if (pMap[i].grouping)
				{
					AcDbObject* pObj = NULL;
					VARIANT VarOut;

					if ((es = acdbOpenAcDbObject(pObj, objId, AcDb::kForRead)) != Acad::eOk)
						return RAISEARXEXCEPTION(IAcadEntity, es);

					if (SetGetElementValue(ELEMENTCOUNT, dispID, 0, &VarOut, pObj) == FALSE)
					{
						pObj->close();
						return E_FAIL;
					}
					else
						*nGroupCnt = V_I4(&VarOut);

					pObj->close();

					return NOERROR;
				}
			}
		}
		return E_NOTIMPL;
	}
	virtual HINSTANCE GetResourceInstance() = 0;
	virtual int SetGetElementValue(int GetOrSet, DISPID dispid, DWORD cookie, VARIANT* val,
								   AcDbObject* pObj) = 0;
	STDMETHODIMP SetElementValue(
			/* [in] */ DISPID dispID,
			/* [in] */ DWORD dwCookie,
			/* [in] */ VARIANT VarIn)
	{
		CComPtr<IAcadBaseObject> pAcadBaseObject;
		HRESULT hr = QueryInterface(IID_IAcadBaseObject, (LPVOID*)&pAcadBaseObject);
		if (FAILED(hr))
			return RAISEEXCEPTION1(IAcadObject, QueryInterfaceFail, _ACRX_T("IID_IAcadBaseObject"));

		AcDbObjectId objId;
		pAcadBaseObject->GetObjectId(&objId);

		AXEntityDocLock(objId);

		Acad::ErrorStatus es;
		AcDbObject* pObj = NULL;
		AcDbLine* pLine = NULL;

		if (V_VT(&VarIn) != VT_R8 && V_VT(&VarIn) != VT_I4)
			return E_INVALIDARG;

		if ((es = acdbOpenAcDbObject(pObj, objId, AcDb::kForWrite)) != Acad::eOk)
			return RAISEARXEXCEPTION(IAcadEntity, es);

		if (SetGetElementValue(ELEMENTSET, dispID, dwCookie, &VarIn, pObj) == FALSE)
		{
			pObj->close();
			return E_FAIL;
		}

		pObj->close();
		return S_OK;
	}
};

#include "icarx/IcArxPackPop.h"

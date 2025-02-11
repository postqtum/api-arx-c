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
***     Description: Declaration of AsdkPromptBase class and PROMPT_MAP_ENTRY struct
***
*****************************************************************************/
#pragma once

#include <atlbase.h>
#include <atlcom.h>

#include "../axboiler.h"
#include "../dbjig.h"

class AcApDocument;

#define IDR_ASDKPROMPTBASE 700

#include "IcArxPackPush.h"

struct PROMPT_MAP_ENTRY
{
	LPCWSTR m_szDesc;
	DISPID m_dispId;
	int m_promptType;
	int m_cronly;
	int m_nInitget;
	UINT m_nKeywords;
	UINT m_nDefaultValue;
	UINT m_nPrompt;
	bool m_bJigThisProperty;
	bool m_bGotThisProperty;
	VARTYPE m_paramType;
	VARIANT m_vValue;
};

template<typename T, const GUID* TCLSIDWrapper>
class ATL_NO_VTABLE AsdkPromptBase
		: public CComObjectRootEx<CComSingleThreadModel>
		, public CComCoClass<AsdkPromptBase<T, TCLSIDWrapper>, static_cast<const GUID*>(NULL)>
		, public IPropertyNotifySink
		, public AcEdJig
{
protected:
	CComPtr<T> m_pWrapperObject;
	CLSID m_CLSID_ObjectWrapper;
	AcDbObject* m_pDbrObject;
	DWORD m_dConnectionID;
	CComQIPtr<IAcadBaseObject2> m_pBaseObj;
	CComPtr<IConnectionPoint> m_pConPt;
	AcDbDatabase* m_pDb;
	AcApDocument* m_pDoc;
	AcGePoint3d m_cursor3dPos, m_pos3d;
	AcGePoint2d m_cursorPos, m_pos;
	double m_cursorDist, m_dist;
	double m_cursorAngle, m_angle;
	TCHAR *m_szCursorString, *m_szString;
	AcEdJig::CursorType m_jigCursorType;
	AcEdJig::UserInputControls m_jigUserInputControls;
	volatile LONG m_cRef;

protected:
	AsdkPromptBase()
			: AcEdJig()
			, m_cursor3dPos()
			, m_pos3d()
			, m_cursorPos()
			, m_pos()
			, m_cursorDist(0)
			, m_dist(0)
			, m_cursorAngle(0)
			, m_angle(0)
			, m_szCursorString(NULL)
			, m_szString(NULL)
	{
		m_CLSID_ObjectWrapper = *TCLSIDWrapper;
	}

	virtual ~AsdkPromptBase() = default;

	DECLARE_REGISTRY_RESOURCEID(IDR_ASDKPROMPTBASE)
	DECLARE_PROTECT_FINAL_CONSTRUCT()

	BEGIN_COM_MAP(AsdkPromptBase)
	COM_INTERFACE_ENTRY(IPropertyNotifySink)
	END_COM_MAP()

	LPCWSTR BuildPromptString(int index)
	{
		PROMPT_MAP_ENTRY* pPromptMap = GetPromptMap();

		static TCHAR szPrompt[256];
		LoadString(pPromptMap[index].m_nPrompt, szPrompt);

		TCHAR szDefaultVal[256];
		*szDefaultVal = L'\0';
		if (defaultValueCallback(index, szDefaultVal) == false)
			LoadString(pPromptMap[index].m_nDefaultValue, szDefaultVal);
		if (*szDefaultVal != L'\0')
		{
			wcscat(szPrompt, L" <");
			wcscat(szPrompt, szDefaultVal);
			wcscat(szPrompt, L">");
		}
		wcscat(szPrompt, L": ");
		return (szPrompt);
	}
	virtual PROMPT_MAP_ENTRY* GetPromptMap() = 0;
	int GetPromptMapSize()
	{
		PROMPT_MAP_ENTRY* pPromptMap = GetPromptMap();
		int i = 0;
		while (pPromptMap[i].m_szDesc) i++;
		return (i);
	}
	HRESULT GetPropertyTypeInfo()
	{
		PROMPT_MAP_ENTRY* pPromptMap = GetPromptMap();
		unsigned int count = 0;
		if (!SUCCEEDED(m_pWrapperObject->GetTypeInfoCount(&count)))
			return (E_FAIL);
		if (!count)
			return (E_FAIL);
		CComPtr<ITypeInfo> pTypeInfo;
		if (!SUCCEEDED(m_pWrapperObject->GetTypeInfo(0, NULL, &pTypeInfo)))
			return (E_FAIL);
		TYPEATTR* pTypeAttr;
		if (!SUCCEEDED(pTypeInfo->GetTypeAttr(&pTypeAttr)))
			return (E_FAIL);
		int numFuncs = pTypeAttr->cFuncs;
		pTypeInfo->ReleaseTypeAttr(pTypeAttr);
		for (int i = 0; i < numFuncs; i++)
		{
			FUNCDESC* pFuncDesc;
			if (!SUCCEEDED(pTypeInfo->GetFuncDesc(i, &pFuncDesc)))
				return (E_FAIL);
			MEMBERID memberID;
			memberID = pFuncDesc->memid;
			int ii = 0;
			for (int ii = 0; ii < GetPromptMapSize(); ii++)
			{
				if (memberID == pPromptMap[ii].m_dispId)
				{
					UINT nNamesArraySize = pFuncDesc->cParams + 1, nReturnedNames;
					BSTR* pBstrNames = new BSTR[nNamesArraySize];
					if (!SUCCEEDED(pTypeInfo->GetNames(memberID, pBstrNames,
														nNamesArraySize, &nReturnedNames)))
						return (E_FAIL);
					delete[] pBstrNames;
					if (nReturnedNames < 1)
						continue;
					if (pFuncDesc->invkind == INVOKE_PROPERTYGET)
						continue;

					pPromptMap[ii].m_paramType = propertyTypeCallback(
							ii, pFuncDesc->lprgelemdescParam[nReturnedNames - 1].tdesc.vt);
				}
			}
		}
		return (S_OK);
	}
	virtual HINSTANCE GetResourceInstance() = 0;
	HRESULT FinalConstruct() { return (S_OK); }
	void FinalRelease() {}
	int LoadString(UINT uID, LPWSTR szString, int nBufferMax = 255)
	{
		int ret = 0;
		*szString = L'\0';
		if (uID != 0 && uID != (UINT)-1)
			ret = ::LoadString(GetResourceInstance(), uID, szString, nBufferMax);
		return (ret);
	}
	STDMETHODIMP OnChanged(DISPID dispId)
	{
		PROMPT_MAP_ENTRY* pPromptMap = GetPromptMap();
		int i = 0;
		while (pPromptMap[i].m_szDesc)
		{
			if (dispId == pPromptMap[i].m_dispId)
			{
				pPromptMap[i].m_bGotThisProperty = true;
				break;
			}
			i++;
		}
		if (m_pDoc != NULL)
			acDocManager->sendModelessInterrupt(m_pDoc);
		return (S_OK);
	}
	STDMETHODIMP OnRequestEdit(DISPID dispID) { return (S_OK); }
	HRESULT PutProperty(int index)
	{
		static bool bDontLoop = false;
		WORD wflags = DISPATCH_PROPERTYPUT;
		DISPID putid = DISPID_PROPERTYPUT;

		CComPtr<IDispatch> pDisp;
		m_pWrapperObject.QueryInterface(&pDisp);
		PROMPT_MAP_ENTRY* pPromptMap = GetPromptMap();


		DISPPARAMS dispparams;
		dispparams.rgvarg = &pPromptMap[index].m_vValue;
		dispparams.rgdispidNamedArgs = &putid;
		dispparams.cArgs = 1;
		dispparams.cNamedArgs = 1;
		HRESULT hr =
				pDisp->Invoke(pPromptMap[index].m_dispId, IID_NULL, LOCALE_USER_DEFAULT,
								wflags, &dispparams, NULL, NULL, NULL);
		if (hr != S_OK && !bDontLoop)
		{
			bDontLoop = true;
			setPropertyDefault(index);
			bDontLoop = false;
		}
		return (hr);
	}
	void SetDocument(AcApDocument * pDoc) { m_pDoc = pDoc; }
	virtual void constructorCallback() {}
	virtual bool defaultValueCallback(int index, LPWSTR szDefaultVal) { return (false); }
	virtual AcDbEntity* entity() const
	{
		if (m_pDbrObject == NULL)
			m_pBaseObj->GetObject((AcDbObject*&)m_pDbrObject);
		return ((AcDbEntity*)m_pDbrObject);
	}
	virtual void initSampler() = 0;
	virtual bool keywordCallback(int index, TCHAR* kword, void* value) { return (false); }
	virtual int promptCallback(int index) { return (RTINPUTTRUNCATED); }
	virtual VARTYPE propertyTypeCallback(int index, VARTYPE varType) { return (varType); }
	virtual AcEdJig::DragStatus sampler()
	{
		setSpecialCursorType(m_jigCursorType);
		setUserInputControls(m_jigUserInputControls);
		AcEdJig::DragStatus stat = AcEdJig::kCancel;
		PROMPT_MAP_ENTRY* pPromptMap = GetPromptMap();
		int i = 0;
		while (pPromptMap[i].m_szDesc)
		{
			if (pPromptMap[i].m_bJigThisProperty && !pPromptMap[i].m_bGotThisProperty)
			{
				bool compareChange = false;
				if (pPromptMap[i].m_nKeywords != 0)
				{
					TCHAR szKeywords[256];
					LoadString(pPromptMap[i].m_nKeywords, szKeywords);
					setKeywordList(szKeywords);
				}
				stat = samplerCallback(i, compareChange);
				if (stat >= AcEdJig::kKW1)
					keywordCallback(i, (TCHAR*)&stat, NULL);
				if (stat == AcEdJig::kOther)
				{
					switch (pPromptMap[i].m_promptType)
					{
						case RTPOINT: {
							AcGePoint3d pos;
							stat = acquirePoint(pos);
							m_cursorPos.x = pos.x;
							m_cursorPos.y = pos.y;
							if (stat >= AcEdJig::kKW1)
								keywordCallback(i, (TCHAR*)&stat, &m_pos);
							compareChange = (m_cursorPos.isEqualTo(m_pos) ? true : false);
							break;
						}
						case RT3DPOINT:
							stat = acquirePoint(m_cursor3dPos);
							if (stat >= AcEdJig::kKW1)
								keywordCallback(i, (TCHAR*)&stat, &m_cursor3dPos);
							compareChange =
									(m_cursor3dPos.isEqualTo(m_pos3d) ? true : false);
							break;
						case RTREAL:
							stat = acquireDist(m_cursorDist);
							if (stat >= AcEdJig::kKW1)
								keywordCallback(i, (TCHAR*)&stat, &m_cursorDist);
							compareChange = (m_cursorDist != m_dist);
							break;
						case RTANG:
							stat = acquireAngle(m_cursorAngle);
							if (stat >= AcEdJig::kKW1)
								keywordCallback(i, (TCHAR*)&stat, &m_cursorAngle);
							compareChange = (m_cursorAngle != m_angle);
							break;
						case RTSTR:
							stat = acquireString(m_szCursorString);
							if (stat >= AcEdJig::kKW1)
								keywordCallback(i, (TCHAR*)&stat, &m_szCursorString);
							compareChange = (m_szCursorString != m_szString);
							break;
					}
					if (stat == AcEdJig::kNull)
						pPromptMap[i].m_bGotThisProperty = true;
				}
				if (stat == AcEdJig::kCancel)
					return (stat);
				if (!compareChange)
				{
					return (stat == AcEdJig::kNull ? stat : AcEdJig::kNoChange);
				}
				else
				{
					m_pos = m_cursorPos;
					m_pos3d = m_cursor3dPos;
					m_dist = m_cursorDist;
					m_angle = m_cursorAngle;
					m_szString = m_szCursorString;
					return (stat);
				}
			}
			i++;
		}
		return (stat);
	}
	virtual AcEdJig::DragStatus samplerCallback(int index, bool& compareChange)
	{
		return (kOther);
	}
	virtual void setProperty(int index, VARIANT& var, short val)
	{
		if (V_VT(&var) == VT_I4)
			V_I4(&var) = static_cast<long>(val);
		else if (V_VT(&var) == VT_I2)
			V_I2(&var) = val;
	}
	virtual void setProperty(int index, VARIANT& var, long val)
	{
		if (V_VT(&var) == VT_I4)
			V_I4(&var) = val;
		else if (V_VT(&var) == VT_I2)
			V_I2(&var) = static_cast<short>(val);
	}
	virtual void setProperty(int index, VARIANT& var, float val)
	{
		if (V_VT(&var) == VT_R8)
			V_R8(&var) = static_cast<double>(val);
		else if (V_VT(&var) == VT_R4)
			V_R4(&var) = val;
	}
	virtual void setProperty(int index, VARIANT& var, double val)
	{
		if (V_VT(&var) == VT_R8)
			V_R8(&var) = val;
		else if (V_VT(&var) == VT_R4)
			V_R4(&var) = static_cast<float>(val);
	}
	virtual void setProperty(int index, VARIANT& var, TCHAR* val)
	{
		V_BSTR(&var) = _bstr_t(val).copy();
	}
	virtual void setProperty(int index, VARIANT& var, AcGePoint2d& val)
	{
		AcAxPoint2d pt(val);
		pt.setVariant(var);
	}
	virtual void setProperty(int index, VARIANT& var, AcGePoint3d& val)
	{
		AcAxPoint3d pt(val);
		pt.setVariant(var);
	}
	void setPropertyDefault(int i)
	{
		PROMPT_MAP_ENTRY* pPromptMap = GetPromptMap();
		pPromptMap[i].m_vValue.vt = pPromptMap[i].m_paramType;
		TCHAR szDefaultValue[256];
		if (defaultValueCallback(i, szDefaultValue) == false)
			LoadString(pPromptMap[i].m_nDefaultValue, szDefaultValue);
		switch (pPromptMap[i].m_paramType)
		{
			case VT_I4:
				setProperty(i, pPromptMap[i].m_vValue, _ttol(szDefaultValue));
				break;
			case VT_I2:
				setProperty(i, pPromptMap[i].m_vValue,
							static_cast<short>(_ttoi(szDefaultValue)));
				break;
			case VT_ARRAY | VT_R8: {
				TCHAR seps[] = L" ,";
				TCHAR szDefault[MAX_PATH];
				wcscpy(szDefault, szDefaultValue);
				AcGePoint3d defPt;
				TCHAR* token = wcstok(szDefault, seps);
				for (long index = 0; token; index++)
				{
					if (index < 3)
						defPt[index] = _tstof(token);
					token = wcstok(NULL, seps);
				}
				setProperty(i, pPromptMap[i].m_vValue, defPt);
				break;
			}
			case VT_BSTR: setProperty(i, pPromptMap[i].m_vValue, szDefaultValue); break;
			case VT_R8:
				setProperty(i, pPromptMap[i].m_vValue, _tstof(szDefaultValue));
				break;
			case VT_R4:
				setProperty(i, pPromptMap[i].m_vValue,
							static_cast<float>(_tstof(szDefaultValue)));
				break;
		}
		if (pPromptMap[i].m_dispId)
			PutProperty(i);
		pPromptMap[i].m_bGotThisProperty = false;
	}
	virtual void setPropertyDefaults(int index = -1)
	{
		PROMPT_MAP_ENTRY* pPromptMap = GetPromptMap();
		if (index == -1)
		{
			for (int i = 0; pPromptMap[i].m_szDesc; i++) setPropertyDefault(i);
		}
		else
		{
			setPropertyDefault(index);
		}
	}
	virtual bool update()
	{
		PROMPT_MAP_ENTRY* pPromptMap = GetPromptMap();
		for (int i = 0; pPromptMap[i].m_szDesc; i++)
		{
			if (pPromptMap[i].m_bJigThisProperty && !pPromptMap[i].m_bGotThisProperty)
			{
				if (updateCallback(i) == false)
				{
					switch (pPromptMap[i].m_promptType)
					{
						case RTPOINT: {
							setProperty(i, pPromptMap[i].m_vValue, m_cursorPos);
							break;
						}
						case RT3DPOINT: {
							setProperty(i, pPromptMap[i].m_vValue, m_cursor3dPos);
							break;
						}
						case RTREAL:
							setProperty(i, pPromptMap[i].m_vValue, m_cursorDist);
							break;
						case RTANG:
							setProperty(i, pPromptMap[i].m_vValue, m_cursorAngle);
							break;
						case RTSTR:
							setProperty(i, pPromptMap[i].m_vValue, m_szCursorString);
							break;
						default:
							acutPrintf(L"Type %s not handled by Jig mechanism!\n",
										pPromptMap[i].m_szDesc);
							break;
					}
					PutProperty(i);
					pPromptMap[i].m_bGotThisProperty = false;
					break;
				}
			}
		}
		return true;
	}
	virtual bool updateCallback(int index) { return (false); }

public:
	virtual AcDbObjectId promptLoop()
	{
		setPropertyDefaults(-1);
		DragStatus stat = kNormal;
		int retval = RTNORM;
		PROMPT_MAP_ENTRY* pPromptMap = GetPromptMap();
		int i = 0;
		while (true)
		{
			bool done = true;
			while (pPromptMap[i].m_szDesc)
			{
				if (!pPromptMap[i].m_bJigThisProperty && !pPromptMap[i].m_bGotThisProperty)
				{
					done = false;
					retval = promptCallback(i);
					if (retval == RTCAN)
						break;
					if (retval == RTINPUTTRUNCATED)
					{
						TCHAR szKeyword[133];
						if (pPromptMap[i].m_nKeywords != 0)
						{
							LoadString(pPromptMap[i].m_nKeywords, szKeyword, 132);
							acedInitGet(pPromptMap[i].m_nInitget, szKeyword);
						}
						LPCWSTR szPrompt = BuildPromptString(i);
						switch (pPromptMap[i].m_promptType)
						{
							case RTPOINT: {
								ads_point point;
								retval = acedGetPoint(NULL, szPrompt, point);
								if (retval == RTKWORD)
								{
									acedGetInput(szKeyword);
									if (keywordCallback(i, szKeyword, point) == true)
										retval = RTNORM;
								}
								if (retval == RTNORM)
								{
									AcGePoint2d pt2d(point[X], point[Y]);
									setProperty(i, pPromptMap[i].m_vValue, pt2d);
									PutProperty(i);
								}
								break;
							}
							case RT3DPOINT: {
								ads_point point;
								retval = acedGetPoint(NULL, szPrompt, point);
								if (retval == RTKWORD)
								{
									acedGetInput(szKeyword);
									if (keywordCallback(i, szKeyword, point) == true)
										retval = RTNORM;
								}
								if (retval == RTNORM)
								{
									AcGePoint3d pt3d(point[0], point[1], point[2]);
									setProperty(i, pPromptMap[i].m_vValue, pt3d);
									PutProperty(i);
								}
								break;
							}
							case RTREAL: {
								double dist = 0;
								retval = acedGetReal(szPrompt, &dist);
								if (retval == RTKWORD)
								{
									acedGetInput(szKeyword);
									if (keywordCallback(i, szKeyword, &dist) == true)
										retval = RTNORM;
								}
								if (retval == RTNORM)
								{
									setProperty(i, pPromptMap[i].m_vValue, dist);
									PutProperty(i);
								}
								break;
							}
							case RTANG: {
								double angle = 0;
								retval = acedGetAngle(NULL, szPrompt, &angle);
								if (retval == RTKWORD)
								{
									acedGetInput(szKeyword);
									if (keywordCallback(i, szKeyword, &angle) == true)
										retval = RTNORM;
								}
								if (retval == RTNORM)
								{
									setProperty(i, pPromptMap[i].m_vValue, angle);
									PutProperty(i);
								}
								break;
							}
							case RTSTR: {
								TCHAR szBuffer[132];
								*szBuffer = L'\0';
								retval = acedGetString(pPromptMap[i].m_cronly, szPrompt,
														szBuffer);
								if (retval == RTKWORD)
								{
									acedGetInput(szKeyword);
									if (keywordCallback(i, szKeyword, szBuffer) == true)
										retval = RTNORM;
								}
								if (retval == RTNORM)
								{
									if (wcslen(szBuffer))
										setProperty(i, pPromptMap[i].m_vValue, szBuffer);
									PutProperty(i);
								}
								break;
							}
							case RTLONG: {
								int _int = 0;
								retval = acedGetInt(szPrompt, &_int);
								if (retval == RTKWORD)
								{
									acedGetInput(szKeyword);
									if (keywordCallback(i, szKeyword, &_int) == true)
										retval = RTNORM;
								}
								if (retval == RTNORM)
								{
									setProperty(i, pPromptMap[i].m_vValue,
												static_cast<long>(_int));
									PutProperty(i);
								}
								break;
							}
							case RTSHORT: {
								int _int = 0;
								retval = acedGetInt(szPrompt, &_int);
								if (retval == RTKWORD)
								{
									acedGetInput(szKeyword);
									if (keywordCallback(i, szKeyword, &_int) == true)
										retval = RTNORM;
								}
								if (retval == RTNORM)
								{
									setProperty(i, pPromptMap[i].m_vValue,
												static_cast<short>(_int));
									PutProperty(i);
								}
								break;
							}
							case RTENAME: {
								ads_name ename;
								ads_point pt;
								retval = acedEntSel(szPrompt, ename, pt);
								if (retval == RTKWORD)
								{
									acedGetInput(szKeyword);
									if (keywordCallback(i, szKeyword, ename) == true)
										retval = RTNORM;
								}
								if (retval == RTNORM)
								{
									setProperty(i, pPromptMap[i].m_vValue,
												static_cast<long>(ename[0]));
									PutProperty(i);
								}
								break;
							}
						}
					}
					if (retval == RTNONE)
						pPromptMap[i].m_bGotThisProperty = true;
					if (retval == RTCAN)
					{
						done = true;
						break;
					}
					if (pPromptMap[i].m_bGotThisProperty == true)
						i++;
				}
				else
				{
					i++;
				}
			}
			if (done)
				break;
			else
				i = 0;
		}
		if (retval == RTCAN)
			return (AcDbObjectId::kNull);
		i = 0;
		while (true)
		{
			bool done = true;
			while (pPromptMap[i].m_szDesc)
			{
				if (pPromptMap[i].m_bJigThisProperty && !pPromptMap[i].m_bGotThisProperty)
				{
					done = false;
					retval = promptCallback(i);
					if (retval == RTINPUTTRUNCATED)
					{
						setDispPrompt(BuildPromptString(i));
						stat = drag();
						if (stat == AcEdJig::kNormal)
						{
							switch (pPromptMap[i].m_promptType)
							{
								case RTPOINT: {
									setProperty(i, pPromptMap[i].m_vValue, m_cursorPos);
									PutProperty(i);
									break;
								}
								case RT3DPOINT: {
									setProperty(i, pPromptMap[i].m_vValue, m_cursor3dPos);
									PutProperty(i);
									break;
								}
								case RTREAL:
									setProperty(i, pPromptMap[i].m_vValue, m_cursorDist);
									PutProperty(i);
									break;
								case RTANG:
									setProperty(i, pPromptMap[i].m_vValue, m_cursorAngle);
									PutProperty(i);
									break;
								case RTSTR:
									setProperty(i, pPromptMap[i].m_vValue,
												m_szCursorString);
									PutProperty(i);
									break;
							}
						}
						if (stat == AcEdJig::kCancel)
						{
							done = true;
							break;
						}
					}
					if (retval == RTCAN || retval == AcEdJig::kCancel)
					{
						stat = AcEdJig::kCancel;
						done = true;
						break;
					}
					if (pPromptMap[i].m_bGotThisProperty == true)
						i++;
				}
				else
				{
					i++;
				}
			}
			if (done)
				break;
			else
				i = 0;
		}
		if (stat != AcEdJig::kCancel)
		{
			if (m_pBaseObj)
				m_pBaseObj->GetObject(m_pDbrObject);
			return (append());
		}
		return (AcDbObjectId::kNull);
	}
};

#include "IcArxPackPop.h"

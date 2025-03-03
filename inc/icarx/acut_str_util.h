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
***     Description: Declaration of string util functions
***
*****************************************************************************/
#pragma once

#include "../AcDbCore2dDefs.h"
#include "../acadstrc.h"
#include "../AcString.h"

ACDBCORE2D_PORT Acad::ErrorStatus acutNewString(const ACHAR* pInput, ACHAR*& pOutput);

// Helper function for legacy functions that return an allocated ACHAR buffer.
// Might want to move these helpers to their own header..
//
template<class ObjType>
inline Acad::ErrorStatus acutGetAcStringConvertToAChar(
		const ObjType* pObj, Acad::ErrorStatus (ObjType::*pFunc)(AcString&) const, ACHAR*& pOutput)
{
	AcString sOutput;
	const Acad::ErrorStatus es = (pObj->*pFunc)(sOutput);
	if (es != Acad::eOk)
	{
		pOutput = nullptr;
		return es;
	}
	return ::acutNewString(sOutput.kwszPtr(), pOutput);
}

template<class ObjType>
inline ACHAR* acutGetAcStringConvertToAChar(const ObjType* pObj,
											Acad::ErrorStatus (ObjType::*pFunc)(AcString&) const)
{
	AcString sOutput;
	const Acad::ErrorStatus es = (pObj->*pFunc)(sOutput);
	ACHAR* pRet = nullptr;
	if (es == Acad::eOk)
		::acutNewString(sOutput.kwszPtr(), pRet);
	return pRet;
}

// Helper functions to take result of a query returning AcString and convert it to ACHAR
inline ACHAR* acutAcStringToAChar(const AcString& s, Acad::ErrorStatus es)
{
	ACHAR* pBuf = nullptr;
	if (es == Acad::eOk)
		::acutNewString(s.kwszPtr(), pBuf);
	return pBuf;
}
inline Acad::ErrorStatus acutAcStringToAChar(const AcString& s, ACHAR*& pBuf, Acad::ErrorStatus es)
{
	pBuf = nullptr;
	if (es != Acad::eOk)
		return es;
	return ::acutNewString(s.kwszPtr(), pBuf);
}



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
***     Description: Declaration of AcRxMember class
***
*****************************************************************************/
#pragma once

#include "../pimplapi.h"
#include "../rxobject.h"
#include "../AcString.h"
#include "../rxvaluetype.h"
#include "../acarray.h"

class AcRxMemberImp;

#include "IcArxPackPush.h"

class AcRxMember : public Pimpl::ApiPart<AcRxObject, AcRxMemberImp>
{
	friend class AcRxMemberImp;

private:
#pragma push_macro("new")
#undef new
	static void* operator new[](size_t size);
	static void* operator new[](size_t size, const char* pFName, int nLine);
#pragma pop_macro("new")

	ACBASE_PORT virtual Acad::ErrorStatus subChildrenEx(
			AcArray<const AcRxMember*>*& pChildren) const;

protected:
	ACBASE_PORT AcRxMember(AcRxMemberImp*) noexcept;
	ACBASE_PORT ~AcRxMember() noexcept;

	ACBASE_PORT virtual Acad::ErrorStatus subChildren(AcArray<const AcRxMember*>& children) const;
	ACBASE_PORT virtual AcString subLocalName() const;

public:
#pragma push_macro("new")
#undef new
	ACBASE_PORT static void* operator new(size_t size);
	ACBASE_PORT static void* operator new(size_t size, const char* pFName, int nLine);
#pragma pop_macro("new")
protected:
#pragma push_macro("delete")
#undef delete
	ACBASE_PORT static void operator delete(void* p);
	ACBASE_PORT static void operator delete(void* p, const char* pFName, int nLine);
	ACBASE_PORT static void operator delete[](void* p);
	ACBASE_PORT static void operator delete[](void* p, const char* pFName, int nLine);
#pragma pop_macro("delete")


public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcRxMember, ACBASE_PORT);


	ACBASE_PORT AcRxAttributeCollection& attributes() noexcept;
	ACBASE_PORT AcString localName() const noexcept;
	ACBASE_PORT const AcArray<const AcRxMember*>* children() const noexcept;
	ACBASE_PORT const ACHAR* name() const noexcept;
	ACBASE_PORT const AcRxAttributeCollection& attributes() const noexcept;
	ACBASE_PORT const AcRxObject* owner() const noexcept;
	ACBASE_PORT const AcRxValueType& type() const noexcept;
	ACBASE_PORT static void deleteMember(const AcRxMember* pMember) noexcept;
};

#include "IcArxPackPop.h"

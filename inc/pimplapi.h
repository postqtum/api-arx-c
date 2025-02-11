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
***     Description: Declaration of ApiPart classes
***
*****************************************************************************/
#pragma once

#include "icarx/IcArxPackPush.h"

namespace Pimpl
{

class ImpBase;

template<typename Base, class ImpPart>
class ApiPart : public Base
{
	friend class ImpBase;

private:
	ImpPart* m_pImp;

protected:
	ApiPart(ImpPart* pImp) noexcept : m_pImp(pImp) {}
	~ApiPart();
	ApiPart(const ApiPart&) = delete;
	ApiPart& operator=(const ApiPart&) = delete;
};

template<class ImpPart>
class ApiPart<void, ImpPart>
{
	friend class ImpBase;

private:
	ImpPart* m_pImp;

protected:
	ApiPart(ImpPart* pImp) noexcept : m_pImp(pImp) {}
	~ApiPart();
	ApiPart(const ApiPart&) = delete;
	ApiPart& operator=(const ApiPart&) = delete;
};

}  // namespace Pimpl

#include "icarx/IcArxPackPop.h"

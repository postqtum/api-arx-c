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
***     Description: Utility class to associate data with a document
***
*****************************************************************************/
#pragma once

#include "acdocman.h"
#include <map>
#include <stdexcept>

#include "icarx/IcArxPackPush.h"

template<class T>
class AcApDataManager : public AcApDocManagerReactor
{
private:
	std::map<AcApDocument*, T> m_dataMap;

public:
	AcApDataManager()
	{
		if (acDocManager)
		{
			acDocManager->addReactor(this);
		}
	}
	~AcApDataManager()
	{
		if (acDocManager)
		{
			acDocManager->removeReactor(this);
		}
	}

	T& docData(AcApDocument* pDoc)
	{
		if (!pDoc)
		{
			throw std::invalid_argument("pDoc");
		}
		if (auto iter = m_dataMap.find(pDoc); iter != m_dataMap.end())
		{
			return iter->second;
		}
		else
		{
			return m_dataMap[pDoc];
		}
	}
	T& docData()
	{
		if (!acDocManager)
		{
			throw std::out_of_range("acDocManager");
		}
		return (docData(acDocManager->curDocument()));
	}
	void documentToBeDestroyed(AcApDocument* pDoc) override { m_dataMap.erase(pDoc); }
};

#include "icarx/IcArxPackPop.h"

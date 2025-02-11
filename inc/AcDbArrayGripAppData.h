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

#include <memory>

#include "AcDbAssocArrayItem.h"
#include "dbDimData.h"
#include "gepnt3d.h"

#include "icarx/IcArxPackPush.h"

class ACDB_PORT AcDbArrayGripAppData : public AcRxObject
{
private:
	AcGePoint3d m_Position;
	unsigned int m_Modes = 0;
	void* m_pAppData = nullptr;
	AcRxClass* m_pAppDataClass = nullptr;
	AcDbItemLocator m_Locator;
	bool m_bArrowGrip = false;
	AcGeVector3d m_Directions[2];
	AcDbDimDataPtrArray m_DimData;
	std::unique_ptr<AcGePoint3d> m_pBasePoint;

public:
	ACRX_DECLARE_MEMBERS(AcDbArrayGripAppData);

public:
	AcDbArrayGripAppData(const AcGePoint3d& position = AcGePoint3d(), unsigned int modes = 0);
	~AcDbArrayGripAppData();

	void addGripMode(unsigned int mode) { this->m_Modes |= mode; }
	void appendDimData(AcDbDimData* pData);
	bool& arrowGrip() { return this->m_bArrowGrip; }
	const AcGePoint3d* basePoint() const { return this->m_pBasePoint.get(); }
	void deleteDimData();
	const AcDbDimDataPtrArray& dimData() const { return this->m_DimData; }
	void* getAppData(AcRxClass** ppClass = nullptr) const
	{
		if (0 != ppClass)
		{
			*ppClass = this->m_pAppDataClass;
		}
		return this->m_pAppData;
	}
	AcDbItemLocator& locator() { return this->m_Locator; }
	unsigned int modes() const { return this->m_Modes; }
	const AcGePoint3d& position() const { return this->m_Position; }
	void setAppData(void* pData, AcRxClass* pClass)
	{
		this->m_pAppData = pData;
		this->m_pAppDataClass = pClass;
	}
	void setBasePoint(AcGePoint3d& basePoint);
	AcGeVector3d& xDir() { return this->m_Directions[0]; }
	AcGeVector3d& yDir() { return this->m_Directions[1]; }
};

#include "icarx/IcArxPackPop.h"

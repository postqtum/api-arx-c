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
***     Description: Declaration of AcDbXrefGraphNode class
***
*****************************************************************************/
#pragma once

#include "AcDbGraphNode.h"

#include "IcArxPackPush.h"

class AcDbXrefGraphNode : public AcDbGraphNode
{
private:
	void* mpxdata = nullptr;
	ACHAR* mpName = nullptr;
	AcDbObjectId mBtrId;
	AcDb::XrefStatus mStatus = AcDb::kXrfResolved;
	AcDb::XrefNotificationStatus mNotifyStatus = AcDb::kXrfNotifyNone;

public:
	AcDbXrefGraphNode(const ACHAR* pName = nullptr, const AcDbObjectId& btrId = AcDbObjectId::kNull,
					  AcDbDatabase* pDb = nullptr, AcDb::XrefStatus status = AcDb::kXrfResolved);
	~AcDbXrefGraphNode();

	AcDbObjectId btrId() const { return mBtrId; }
	AcDbDatabase* database() const { return (AcDbDatabase*)data(); }
	bool isNested() const { return !isMarkedAs(kFirstLevel); }
	const ACHAR* name() const { return mpName; }
	void setBtrId(const AcDbObjectId& id) { mBtrId = id; }
	void setDatabase(AcDbDatabase* pDb) { setData(pDb); }
	Acad::ErrorStatus setName(const ACHAR* pName);
	void setXrefNotificationStatus(AcDb::XrefNotificationStatus stat) { mNotifyStatus = stat; }
	void setXrefStatus(AcDb::XrefStatus stat) { mStatus = stat; }
	void setxData(void* pXData) { mpxdata = pXData; }
	void* xData() { return mpxdata; }
	AcDb::XrefNotificationStatus xrefNotificationStatus() const { return mNotifyStatus; }
	Acad::ErrorStatus xrefReadSubstatus() const;
	AcDb::XrefStatus xrefStatus() const { return mStatus; }
};

#include "IcArxPackPop.h"

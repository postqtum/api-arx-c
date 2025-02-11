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
***     Description: Declaration of WritableAcDbObject class
***
*****************************************************************************/
#pragma once

#include "../acadstrc.h"
#include "AcDbObject.h"

ACDBCORE2D_PORT Acad::ErrorStatus accessAcDbObjectForWrite(AcDbObject* pObj,
														   bool& bWasNotifyEnabled,
														   bool& bWasWriteEnabled,
														   int& readCountClosed,
														   bool openOnLockedLayer);
ACDBCORE2D_PORT Acad::ErrorStatus revertAcDbObjectFromWrite(AcDbObject* pObj,
															Acad::ErrorStatus accessStatus,
															bool bWasNotifyEnabled,
															bool bWasWriteEnabled,
															int readCountClosed);

#include "IcArxPackPush.h"

class WritableAcDbObject
{
private:
	AcDbObject* mpObj{nullptr};
	Acad::ErrorStatus mEs{Acad::eNullObjectPointer};
	bool mbWasNotifyEnabled = false;
	bool mbWasWriteEnabled = false;
	bool mbOpenOnLockedLayer;
	int mReadCountClosed{0};

public:
	WritableAcDbObject() : mbOpenOnLockedLayer(false) {}
	WritableAcDbObject(AcDbObject* pObj, bool enableNow = true, bool openOnLockedLayer = false)
			: mbOpenOnLockedLayer(openOnLockedLayer)
	{
		replaceObject(pObj, enableNow);
	}
	WritableAcDbObject(const WritableAcDbObject&) = delete;
	WritableAcDbObject operator=(const WritableAcDbObject&) = delete;
	~WritableAcDbObject() { revertWrite(); }

	bool enableWrite()
	{
		if (isWritable())
			return true;
		if (nullptr == mpObj)
			return false;
		mEs = accessAcDbObjectForWrite(mpObj, mbWasNotifyEnabled, mbWasWriteEnabled,
									   mReadCountClosed, mbOpenOnLockedLayer);
		return isWritable();
	}
	void forget()
	{
		mpObj = nullptr;
		mEs = Acad::eNullObjectPointer;
	}
	bool isWritable() const { return (Acad::eOk == mEs); };
	void replaceObject(AcDbObject* pObj, bool enableNow = true)
	{
		revertWrite();
		mpObj = pObj;
		if (nullptr == pObj)
		{
			mEs = Acad::eNullObjectPointer;
			return;
		}
		mEs = Acad::eNotOpenForWrite;
		if (enableNow)
			enableWrite();
	}
	void revertWrite()
	{
		if ((nullptr != mpObj) && !mpObj->objectId().isNull())
			mEs = revertAcDbObjectFromWrite(mpObj, mEs, mbWasNotifyEnabled, mbWasWriteEnabled,
											mReadCountClosed);
		forget();
	}
	void setOpenOnLockedLayer(bool openOnLockedLayer) { mbOpenOnLockedLayer = openOnLockedLayer; }
	Acad::ErrorStatus statusCode() const { return mEs; };
};

#include "IcArxPackPop.h"

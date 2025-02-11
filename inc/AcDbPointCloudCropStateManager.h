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
***     Description: Declaration of AcDbPointCloudCropStateManager class
***
*****************************************************************************/
#pragma once

#include "acdbport.h"
#include "acadstrc.h"
#include "AcString.h"

class AcDbPointCloudCropStateManagerImp;
class AcDbPointCloudEx;

#include "icarx/IcArxPackPush.h"

class ACDB_PORT AcDbPointCloudCropStateManager
{
	friend class PointCloudExImp;
	friend class PointCloudCropStateRoundtripManager;

private:
	AcDbPointCloudCropStateManagerImp* m_pImpCropStatesManager;

private:
	AcDbPointCloudCropStateManager();
	AcDbPointCloudCropStateManager(AcDbPointCloudEx* pCloud);
	virtual ~AcDbPointCloudCropStateManager();

	AcDbPointCloudCropStateManager(const AcDbPointCloudCropStateManager&) = delete;
	AcDbPointCloudCropStateManager& operator=(const AcDbPointCloudCropStateManager&) = delete;

public:
	Acad::ErrorStatus addCropState(const AcString& state);
	AcString currentCropState() const;
	Acad::ErrorStatus getAllCropStates(AcArray<AcString>& states) const;
	Acad::ErrorStatus removeCropState(const AcString& name);
	Acad::ErrorStatus renameCropState(const AcString& oldName, const AcString& newName);
	Acad::ErrorStatus restoreCropState(const AcString& name);
};

#include "icarx/IcArxPackPop.h"

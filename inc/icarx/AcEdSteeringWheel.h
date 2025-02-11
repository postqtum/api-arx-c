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
***     Description: Declaration of AcEdSteeringWheel class
***
*****************************************************************************/
#pragma once

class AcEdSteeringWheelReactor;
class AcGsModel;
class AcGsView;
class AcDbHomeView;

#include "IcArxPackPush.h"

class AcEdSteeringWheel
{
public:
	enum MenuType
	{
		kMenuNone = 0,
		kMenuInterior,
		kMenuExterior,
		kMenuFull,
		kMenu2D
	};

	enum WheelType
	{
		kExterior = 0,
		kInterior,
		kFull,
		k2D,
		kMini,
		kMiniOther,
		kMiniEight,
		kTotalCount,
		kWheelNone
	};

public:
	virtual void addReactor(AcEdSteeringWheelReactor* pReactor) = 0;
	virtual bool attachView(HWND hDevice, AcGsView* pGsView) = 0;
	virtual void detachView() = 0;
	virtual void enableWheel(bool enable) = 0;
	virtual WheelType getActiveWheel() = 0;
	virtual HWND getDeviceHandle() = 0;
	virtual int getLargeWheelOpacity() = 0;
	virtual int getMiniWheelOpacity() = 0;
	virtual AcGsModel* getModel() = 0;
	virtual AcGsView* getView() = 0;
	virtual double getWalkSpeed() = 0;
	virtual bool isWheelEnabled() = 0;
	virtual void onKeyDown(UINT nChar, UINT nRepCount, UINT nFlags) = 0;
	virtual void onKeyUp(UINT nChar, UINT nRepCount, UINT nFlags) = 0;
	virtual void onLButtonDown(UINT nFlags, POINT pt) = 0;
	virtual void onLButtonUp(UINT nFlags, POINT pt) = 0;
	virtual void onMButtonDown(UINT nFlags, POINT pt) = 0;
	virtual void onMButtonUp(UINT nFlags, POINT pt) = 0;
	virtual void onMouseMove(UINT nFlags, POINT pt) = 0;
	virtual bool onMouseWheel(UINT nFlags, short zDelta, POINT pt) = 0;
	virtual void onRButtonDown(UINT nFlags, POINT pt) = 0;
	virtual void onRButtonUp(UINT nFlags, POINT pt) = 0;
	virtual void removeReactor(AcEdSteeringWheelReactor* pReactor) = 0;
	virtual bool setActiveWheel(WheelType type) = 0;
	virtual void setHomeCamera(const AcDbHomeView& home) = 0;
	virtual bool setLargeWheelOpacity(int nOpacity) = 0;
	virtual bool setMiniWheelOpacity(int nOpacity) = 0;
	virtual bool setWalkSpeed(double speed) = 0;
};

#include "IcArxPackPop.h"

AcEdSteeringWheel* acedCreateSteeringWheel();
void acedDestroySteeringWheel(AcEdSteeringWheel* pWheel);

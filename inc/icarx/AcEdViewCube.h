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
***     Description: Declaration of AcEdViewCube class
***
*****************************************************************************/
#pragma once

#include "AcEdViewCubePart.h"

class AcDbUcsPlane;
class AcDbHomeView;
class AcEdViewCubeReactor;
class AcGiDrawable;
class AcGsView;
class AcGsModel;
class AcGeVector3d;

#include "IcArxPackPush.h"

class AcEdViewCube
{
public:
	virtual void addReactor(AcEdViewCubeReactor* pReactor) = 0;
	virtual bool attachView(AcGsView* pGsView) = 0;
	virtual AcGsView* detachView() = 0;
	virtual AcEdViewCubePart getActivePart() const = 0;
	virtual HWND getDeviceHandle() const = 0;
	virtual bool getDragSnap() const = 0;
	virtual bool getDrawCompass() const = 0;
	virtual bool getDrawUCSMenu() const = 0;
	virtual AcGiDrawable* getDrawable() const = 0;
	virtual const AcDbHomeView& getHomeCamera() const = 0;
	virtual int getLocation() const = 0;
	virtual int getMinOpacity() const = 0;
	virtual AcGsModel* getModel() const = 0;
	virtual int getSize() const = 0;
	virtual bool getOrientToUCS() const = 0;
	virtual bool getPerspWithOrtho() const = 0;
	virtual bool getPreserveSceneUp() const = 0;
	virtual const AcGeVector3d& getSceneFrontDirection() const = 0;
	virtual const AcGeVector3d& getSceneUpDirection() const = 0;
	virtual int getTransitionDuration() const = 0;
	virtual const AcDbUcsPlane& getUCSPlane() const = 0;
	virtual AcGsView* getView() const = 0;
	virtual bool getZoomToFitScene() const = 0;
	virtual void goToHomeView() = 0;
	virtual bool isEnable() const = 0;
	virtual bool isMouseInRegion() const = 0;
	virtual bool isOverride() const = 0;
	virtual bool isVisible() const = 0;
	virtual void onLButtonDown(UINT nFlags, POINT pt) = 0;
	virtual void onLButtonUp(UINT nFlags, POINT pt) = 0;
	virtual void onMouseMove(UINT nFlags, POINT pt) = 0;
	virtual void redraw() const = 0;
	virtual void removeReactor(AcEdViewCubeReactor* pReactor) = 0;
	virtual void setDeviceHandle(HWND hDevice) = 0;
	virtual void setDragSnap(bool bDragSnap) = 0;
	virtual void setDrawCompass(bool bDrawCompass) = 0;
	virtual void setDrawUCSMenu(bool bDrawUCSMenu) = 0;
	virtual void setHomeCamera(const AcDbHomeView& home) = 0;
	virtual void setEnable(bool bEnable) = 0;
	virtual void setLocation(int nLocation) = 0;
	virtual void setMinOpacity(int nMinOpacity) = 0;
	virtual void setOrientToUCS(bool bOrientToUCS) = 0;
	virtual void setOverride(bool bOverride) = 0;
	virtual void setPerspWithOrtho(bool bPerspWithOrtho) = 0;
	virtual void setPreserveSceneUp(bool bPreserveSceneUp) = 0;
	virtual void setSceneFrontDirection(const AcGeVector3d& front) = 0;
	virtual void setSceneUpDirection(const AcGeVector3d& up) = 0;
	virtual void setSize(int nSize) = 0;
	virtual void setTransitionDuration(int nTransitionDuration) = 0;
	virtual void setUCSPlane(const AcDbUcsPlane& ucs) = 0;
	virtual void setVisible(bool bVisible) = 0;
	virtual void setZoomToFitScene(bool bZoomToFitScene) = 0;
};

#include "IcArxPackPop.h"

AcEdViewCube* acedCreateViewCube(AcGsView* pGsView);
void acedDestroyViewCube(AcEdViewCube* pCube);

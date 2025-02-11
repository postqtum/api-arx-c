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
***     Description: Declaration of AcGsManager class
***
*****************************************************************************/
#pragma once

#include "../gs.h"

#ifndef DRAWBRIDGE_API
#	define DRAWBRIDGE_API
#endif	// DRAWBRIDGE_API

#include "IcArxPackPush.h"

class AcDbViewportTableRecord;

class AcGsManager
{
public:
	AcGsManager() = default;
	virtual ~AcGsManager() = default;

	static DRAWBRIDGE_API AcGsGraphicsKernel* acquireGraphicsKernel(
			const AcGsKernelDescriptor& descriptor);
	virtual AcGsDevice* createAutoCADDevice(AcGsGraphicsKernel& kernel,
											AcGsWindowingSystemID id) = 0;
	virtual AcGsModel* createAutoCADModel(AcGsGraphicsKernel& kernel) = 0;
	virtual AcGsDevice* createAutoCADOffScreenDevice(AcGsGraphicsKernel& kernel) = 0;
	virtual AcGsView* createAutoCADView(AcGsGraphicsKernel& kernel, AcGiDrawable* pDrawable) = 0;
	virtual AcGsView* createAutoCADViewport(AcGsGraphicsKernel& kernel,
											AcDbViewportTableRecord* pVTR) = 0;
	virtual AcGsView* createView(AcGsDevice* pDevice) = 0;
	virtual AcGsView* createViewport(AcGsDevice* pDevice, AcDbViewportTableRecord* pVTR) = 0;
	virtual void destroyAutoCADDevice(AcGsDevice* pDevice) = 0;
	virtual void destroyAutoCADModel(AcGsModel* pModel) = 0;
	virtual void destroyAutoCADView(AcGsView* pView) = 0;
	virtual void destroyView(AcGsView*, AcDbViewportTableRecord* pVTR = nullptr) = 0;
	static DRAWBRIDGE_API AcGsConfig* getConfig();
	virtual AcGsModel* getDBModel(AcGsGraphicsKernel& kernel) = 0;
	virtual AcGsDevice* getGUIDevice(AcGsGraphicsKernel& kernel) = 0;
	virtual AcGsDevice* getOffScreenDevice(AcGsGraphicsKernel& kernel) = 0;
	virtual AcGsView* getOffScreenView(AcGsGraphicsKernel& kernel,
									   AcGsClientViewInfo& clientViewInfo) = 0;
	virtual AcGsModel* gsHighlightModel(const AcDbDatabase* pDb) const = 0;
	virtual AcGsModel* gsModel(const AcDbDatabase* pDb) const = 0;
	virtual bool hasGsModel(const AcDbDatabase* pDb) const = 0;
	virtual bool invalidateGsModel(const AcDbDatabase* pDb) = 0;
	static DRAWBRIDGE_API void releaseGraphicsKernel(AcGsGraphicsKernel* pKernel);
	virtual void setGsHighlightModel(const AcDbDatabase* pDb, AcGsModel* pModel) = 0;
	virtual void setGsModel(const AcDbDatabase* pDb, AcGsModel* pModel) = 0;
};

#include "IcArxPackPop.h"

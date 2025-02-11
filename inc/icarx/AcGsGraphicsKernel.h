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
***     Description: Declaration of AcGsModelReactor, AcGsReactor, AcGsGraphicsKernel classes
***
*****************************************************************************/
#pragma once

#include "AcGiKernelDescriptor.h"
#include "AcGsModel.h"
#include "AcGsEnum.h"

class AcGsView;
class AcGsGraphicsKernel;
class AcGsKernelDescriptor;
struct AcGsClientViewInfo;
class AcGsDevice;
using AcGsWindowingSystemID = void*;
class AcGsConfig;

using AcGsGetInterfaceFunc = AcGiDrawable* (*)(IcArx::Integers::IntDbId objectId, bool bNeedsValidation);
using AcGsReleaseInterfaceFunc = void (*)(AcGiDrawable*);

#ifndef DRAWBRIDGE_API
#	define DRAWBRIDGE_API
#endif

#define DRAWBRIDGE_MAC_API

#include "IcArxPackPush.h"

class AcGsModelReactor
{
public:
	AcGsModelReactor() = default;
	virtual ~AcGsModelReactor() = default;

	virtual bool onAdded(AcGsModel* /*pModel*/, AcGiDrawable* /*pAdded*/, AcGiDrawable* /*pParent*/)
	{
		return true;
	}
	virtual bool onAdded(AcGsModel* /*pModel*/, AcGiDrawable* /*pAdded*/,
						 IcArx::Integers::IntDbId /*parentID*/)
	{
		return true;
	}
	virtual bool onErased(AcGsModel* /*pModel*/, AcGiDrawable* /*pErased*/,
						  AcGiDrawable* /*pParent*/)
	{
		return true;
	}
	virtual bool onErased(AcGsModel* /*pModel*/, AcGiDrawable* /*pErased*/,
						  IcArx::Integers::IntDbId /*parentID*/)
	{
		return true;
	}
	virtual bool onModified(AcGsModel* /*pModel*/, AcGiDrawable* /*pModified*/,
							AcGiDrawable* /*pParent*/)
	{
		return true;
	}
	virtual bool onModified(AcGsModel* /*pModel*/, AcGiDrawable* /*pModified*/,
							IcArx::Integers::IntDbId /*parentID*/)
	{
		return true;
	}
	virtual bool onSceneGraphRootAdded(AcGsModel* /*pModel*/, AcGiDrawable* /*pAdded*/)
	{
		return true;
	}
	virtual bool onSceneGraphRootErased(AcGsModel* /*pModel*/, AcGiDrawable* /*pErased*/)
	{
		return true;
	}
};

class AcGsReactor
{
public:
	enum ViewUpdateFlags
	{
		kCameraChanged = 1
	};

public:
	AcGsReactor() = default;
	DRAWBRIDGE_API virtual ~AcGsReactor();

	virtual void gsToBeUnloaded(AcGsGraphicsKernel*) {}
	virtual void viewInteractivityToBeChanged(const AcGsView*, bool /*interactive*/) {}
	virtual void viewInteractivityWasChanged(const AcGsView*, bool /*interactive*/) {}
	virtual void viewToBeDestroyed(AcGsView*) {}
	virtual void viewToBeUpdated(AcGsView*, int /*viewUpdateflags*/) {}
	virtual void viewWasCreated(AcGsView*) {}
	virtual void viewWasUpdated(AcGsView*, int /*viewUpdateflags*/) {}
};

class DRAWBRIDGE_MAC_API AcGsGraphicsKernel : public AcGiGraphicsKernel
{
protected:
	int m_refCount = 0;

public:
	AcGsGraphicsKernel() = default;
	~AcGsGraphicsKernel() = default;

	virtual void addModelReactor(AcGsModel* pModel, AcGsModelReactor* pReactor) = 0;
	virtual void addReactor(AcGsReactor* pReactor) = 0;
	DRAWBRIDGE_API void addRef();
	virtual void associate(IcArx::Integers::LongPtr databasePtr, AcGsModel* pModel,
						   AcGsModel::RenderType renderType) = 0;
	virtual AcGsDevice* createDevice(AcGsWindowingSystemID id,
									 GS::DeviceType deviceType = GS::kScreenDevice) = 0;
	virtual AcGsModel* createModel(AcGsModel::RenderType type, IcArx::Integers::IntDbId databaseId,
								   AcGsGetInterfaceFunc getFunc,
								   AcGsReleaseInterfaceFunc releaseFunc) = 0;
	virtual AcGsDevice* createOffScreenDevice() = 0;
	virtual AcGsView* createView(const AcGsClientViewInfo* pClientViewInfo = nullptr,
								 bool bEnableLayerVisibilityPerView = false) = 0;
	DRAWBRIDGE_API bool delRef();
	virtual void deleteDevice(AcGsDevice* pDevice) = 0;
	virtual void deleteModel(AcGsModel* pModel) = 0;
	virtual void deleteView(AcGsView* pView) = 0;
	virtual AcGsModel* find(IcArx::Integers::LongPtr databasePtr,
							AcGsModel::RenderType renderType) = 0;
	virtual AcGsConfig* getConfig() const = 0;
	virtual bool isCompatibleWith(const AcGsKernelDescriptor& descriptor) const = 0;
	virtual void removeModelReactor(AcGsModel* pModel, AcGsModelReactor* pReactor) = 0;
	virtual void removeReactor(AcGsReactor* pReactor) = 0;
};

#include "IcArxPackPop.h"

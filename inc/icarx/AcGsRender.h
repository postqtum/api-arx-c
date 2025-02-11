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
***     Description: Declaration of AcGsRenderInterrupter, AcGsRenderStatistics, AcGsRenderProgressMonitor classes
***
*****************************************************************************/
#pragma once

#include "AcGsModel.h"

class AcGsView;

#include "IcArxPackPush.h"

class AcGsRenderInterrupter
{
public:
	virtual bool interrupt(AcGsView* pView, AcGsModel::RenderType nType) = 0;
};

struct AcGsRenderStatistics
{
public:
	float fRenderTime;
	size_t iMemory;
	size_t iMaterialCount;
	size_t iLightCount;
	size_t iTriangleCount;
};

class AcGsRenderProgressMonitor
{
public:
	enum Phase
	{
		kTranslation,
		kPhotonEmission,
		kFinalGather,
		kRender,
		kDraft,
		kInitialize,
	};

	enum RenderingStatus
	{
		kRendering,
		kPaused,
		kFinished,
		kAborted,
		kWillNotRender,
		kSoftOutOfMemory,
		kHardOutOfMemory,
		kError,
	};

public:
	virtual ~AcGsRenderProgressMonitor() = default;

	virtual bool IsAsync() { return false; }
	virtual bool IsOutputImageFlipped() { return false; }
	virtual bool IsValid() { return true; }
	virtual bool OnProgress(Phase ePhase, float fOverallProgress, int iRenderTimeSpent,
							int iCurrentRenderLevel, float fCurrentLevelProgress,
							int iTileIndex = 0) = 0;
	virtual void OnStatusChanged(RenderingStatus status) = 0;
	virtual void OnTile(int x, int y, int w, int h, const unsigned char* pPixels) = 0;
	virtual void SetStatistics(const AcGsRenderStatistics* pStats) = 0;
	virtual bool ShouldReuseDatabase() { return false; }
};

#include "IcArxPackPop.h"

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

#include "icarx/AcGs2DViewLimitManager.h"
#include "icarx/AcGsScreenShot.h"
#include "icarx/AcGsStruct.h"

#include "adesk.h"
#include "acdb.h"
#include "stdlib.h"
#include "AdAChar.h"
#include "acgitransient.h"
#include "AcCoreDefs.h"
#include "acgidefs.h"

class AcDbDatabase;
class AcGiDrawable;
class AcGsView;
class AcGsModel;
class AcGsManager;
class AcGsManager2;
class CView;
class AcGePoint3d;
class AcGeVector3d;
class AcGsGraphicsKernel;

using acgsCustomUpdateMethod = void (*)(void* pParm, int left, int right, int bottom, int top);

bool acgsDisplayImage(int viewportNumber, int32_t originLeft, int32_t originTop, int imageWidth,
					  int imageHeight, void const* imageData, int hasTransparency);
ACCORE_PORT bool acgsDrawableCached(AcGiDrawable* pDrawable);
ACCORE_PORT bool acgsDrawableCached(AcGsGraphicsKernel* pKernel, AcGiDrawable* pDrawable);
bool acgsDrawableErased(AcGiDrawable* pDrawable, AcGiDrawable* pParentDrawable);
bool acgsDrawableModified(AcGiDrawable* pDrawable, AcGiDrawable* pParentDrawable);
ACCORE_PORT bool acgsGetActiveGraphicsKernels(AcArray<AcGsGraphicsKernel*>& result);
ACCORE_PORT bool acgsGetActiveModels(AcArray<AcGsModel*>& result);
ACCORE_PORT bool acgsGetActiveModels(const AcDbDatabase* pDb, AcArray<AcGsModel*>& result);
ACCORE_PORT AcGsView* acgsGetCurrent3dAcGsView(int vpNum);
ACCORE_PORT AcGsView* acgsGetCurrentAcGsView(int vpNum);
ACCORE_PORT AcGsManager* acgsGetCurrentGsManager();
ACCORE_PORT AcGsManager2* acgsGetCurrentGsManager2();
bool acgsGetDisplayInfo(int& drawingWidth, int& drawingHeight, int& aspectWidth, int& aspectHeight);
ACCORE_PORT AcGsModel* acgsGetGsHighlightModel(const AcDbDatabase* pDb);
ACCORE_PORT AcGsModel* acgsGetGsHighlightModel(AcGsGraphicsKernel* pKernel,
											   const AcDbDatabase* pDb);
AcGsManager* acgsGetGsManager(CView* pView = nullptr);
ACCORE_PORT AcGsModel* acgsGetGsModel(const AcDbDatabase* pDb);
AcGsModel* acgsGetGsModel(AcGiTransientDrawingMode mode, int subDrawingMode, int viewportNumber);
ACCORE_PORT AcGsModel* acgsGetGsModel(AcGsGraphicsKernel* pKernel, const AcDbDatabase* pDb);
ACCORE_PORT uint16_t acgsGetHighlightColor();
ACCORE_PORT AcGs::LinePattern acgsGetHighlightLinePattern();
ACCORE_PORT uint16_t acgsGetHighlightLineWeight();
ACCORE_PORT AcGiHighlightStyle acgsGetHighlightStyle();
bool acgsGetLensLength(int viewportNumber, double& lensLength);
bool acgsGetOrthoViewParameters(int viewportNumber, AcDb::OrthographicView view,
								AcGeVector3d* pViewDir, AcGeVector3d* pUpVector);
bool acgsGetViewParameters(int viewportNumber, AcGsView* pView);
bool acgsGetViewportInfo(int viewportNumber, int& left, int& bottom, int& right, int& top);
ACCORE_PORT AcGsView* acgsObtainAcGsView(int vpNum, const class AcGsKernelDescriptor&);
ACCORE_PORT void acgsRedrawShortTermGraphics(int minx, int miny, int maxx, int maxy);
bool acgsRemoveAnonymousGraphics(int viewportNumber);
bool acgsSetCustomUpdateMethod(acgsCustomUpdateMethod custom_update_method, void* pParm);
ACCORE_PORT void acgsSetGsHighlightModel(const AcDbDatabase* pDb, AcGsModel* pModel);
ACCORE_PORT void acgsSetGsHighlightModel(AcGsGraphicsKernel* pKernel, const AcDbDatabase* pDb,
										 AcGsModel* pModel);
ACCORE_PORT void acgsSetGsModel(const AcDbDatabase* pDb, AcGsModel* pModel);
ACCORE_PORT void acgsSetGsModel(AcGsGraphicsKernel* pKernel, const AcDbDatabase* pDb,
								AcGsModel* pModel);
ACCORE_PORT void acgsSetHighlightColor(uint16_t colorIndex);
ACCORE_PORT void acgsSetHighlightLinePattern(AcGs::LinePattern pattern);
ACCORE_PORT void acgsSetHighlightLineWeight(uint16_t weight);
ACCORE_PORT void acgsSetHighlightStyle(AcGiHighlightStyle style);
bool acgsSetLensLength(int viewportNumber, const double& lensLength);
bool acgsSetView2D(int viewportNumber);
bool acgsSetViewParameters(int viewportNumber, const AcGsView* pView, bool bRegenRequired,
						   bool bRescaleRequired, bool bSyncRequired = false);
void acgsSetViewportRenderFlag(int viewportNumber);
void acgsWriteViewToUndoController(int viewportNumber);

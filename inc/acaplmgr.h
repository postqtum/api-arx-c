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
***     Description: AcDbLayout manipulation common includes
***
*****************************************************************************/
#pragma once

#include "AcDbLMgr.h"

class AcDbObjectId;
class AcGePoint2d;
class AcGePoint3d;

template<class T>
class AcArrayMemCopyReallocator;
template<class T, class R>
class AcArray;
typedef AcArray<AcGePoint2d> AcGePoint2dArray;

#include "icarx/IcArxPackPush.h"

class AcApLayoutManager : public AcDbLayoutManager
{
public:
	virtual Acad::ErrorStatus createLayoutFromTemplate(const ACHAR* newLayoutName,
													   AcDbObjectId& newLayoutId,
													   const ACHAR* templatePath,
													   const ACHAR* layoutName,
													   AcDbDatabase* pDb = 0) = 0;
	virtual Acad::ErrorStatus generateNextNewLayoutName(AcString& sName,
														AcDbDatabase* useDb = nullptr) = 0;
	virtual Acad::ErrorStatus getActiveTab(AcString& sName) = 0;
	virtual Acad::ErrorStatus getClipBoundaryElaboration(AcDbObjectId clipId,
														 AcGePoint2dArray*& clipBoundary) = 0;
	virtual Acad::ErrorStatus pointInViewports(const AcGePoint3d& pickPt,
											   AcDbObjectIdArray& viewports) = 0;
	virtual bool createViewports() = 0;
	virtual bool showPageSetup() = 0;
	virtual bool showPaperBackground() = 0;
	virtual bool showPaperMargins() = 0;
	virtual bool showPrintBorder() = 0;
	virtual bool showTabs() = 0;
	virtual int pageSetup(AcDbObjectId layoutBTRId = AcDbObjectId::kNull, void* pParent = nullptr,
						  bool isPageSetupDlg = true) = 0;
	virtual void setCaptureOnLayoutSwitch(bool bCaptureOnLayout) = 0;
	virtual void setCreateViewports(bool createViewports) = 0;
	virtual void setDefaultPlotConfig(AcDbObjectId layoutBTRId) = 0;
	virtual void setShowPageSetup(bool showPageSetupDlg) = 0;
	virtual void setShowPaperBackground(bool showPaperBackground) = 0;
	virtual void setShowPaperMargins(bool showPaperMargins) = 0;
	virtual void setShowPrintBorder(bool showPrintBorder) = 0;
	virtual void setShowTabs(bool showTabs) = 0;
	virtual void updateCurrentPaper(bool zoomToPaper = false) = 0;
	virtual void updateLayoutTabs() = 0;
};

#include "icarx/IcArxPackPop.h"


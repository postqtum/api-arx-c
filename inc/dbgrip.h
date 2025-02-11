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

#include "acdb.h"
#include "acarray.h"
#include "dbdimdata.h"
#include "dbgripoperations.h"

#include "AcDbCore2dDefs.h"

class AcGiViewport;
class AcDbEntity;
class AcDbGripData;
class AcGiWorldDraw;
class AcGiViewportDraw;
class AcDbCustomOsnapMode;

using AcDbGripDataArray = AcArray<AcDbGripData, AcArrayObjectCopyReallocator<AcDbGripData>>;
using AcDbGripDataPtrArray = AcArray<AcDbGripData*, AcArrayMemCopyReallocator<AcDbGripData*>>;

using ContextMenuItemIndexPtr = void (*)(unsigned int itemIndex);
using GripCLIDisplayStringPtr = const ACHAR* (*)(AcDbGripData* pThis);
using GripCLIPromptPtr = const ACHAR* (*)(AcDbGripData* pThis);
using GripDimensionPtr = void (*)(AcDbGripData* pThis, const AcDbObjectId& entId, double dimScale,
								  AcDbDimDataPtrArray& dimData);
using GripInputPointPtr = AcDbGripOperations::ReturnValue (*)(
		AcDbGripData* pThis, const AcDbObjectId& entId, bool& changedPoint, AcGePoint3d& newPoint,
		const AcGiViewport& viewContext, const AcDbObjectId& viewportId, bool pointComputed,
		int history, const AcGePoint3d& lastPoint, const AcGePoint3d& rawPoint,
		const AcGePoint3d& grippedPoint, const AcGePoint3d& cartesianSnappedPoint,
		const AcGePoint3d& osnappedPoint, AcDb::OsnapMask osnapMask,
		const AcArray<AcDbCustomOsnapMode*>& customOsnapModes, AcDb::OsnapMask osnapOverrides,
		const AcArray<AcDbCustomOsnapMode*>& customOsnapOverrides,
		const AcArray<AcDbObjectId>& pickedEntities,
		const AcArray<AcDbObjectIdArray, AcArrayObjectCopyReallocator<AcDbObjectIdArray>>&
				nestedPickedEntities,
		const AcArray<IcArx::Integers::GsMarker>& gsSelectionMark,
		const AcArray<AcDbObjectId>& keyPointEntities,
		const AcArray<AcDbObjectIdArray, AcArrayObjectCopyReallocator<AcDbObjectIdArray>>&
				nestedKeyPointEntities,
		const AcArray<IcArx::Integers::GsMarker>& keyPointGsSelectionMark,
		const AcArray<AcGeCurve3d*>& alignmentPaths, const AcGePoint3d& computedPoint);
using GripOpStatusPtr = void (*)(AcDbGripData* pThis, const AcDbObjectId& entId,
								 AcDbGripOperations::GripStatus stat);
using GripOperationPtr = AcDbGripOperations::ReturnValue (*)(AcDbGripData* pThis,
															 const AcDbObjectId& entId,
															 int contextFlags);
using GripRightClickHandler = AcDbGripOperations::ReturnValue (*)(AcDbGripDataArray& hotGrips,
																  const AcDbObjectIdArray& ents,
																  AcRxObject*& handler);
using GripRtClkHandler = AcDbGripOperations::ReturnValue (*)(AcDbGripDataArray& hotGrips,
															 const AcDbObjectIdArray& ents,
															 ACHAR*& menuName, HMENU& menu,
															 ContextMenuItemIndexPtr& cb);
using GripToolTipPtr = const ACHAR* (*)(AcDbGripData* pThis);
using GripViewportDrawPtr = void (*)(AcDbGripData* pThis, AcGiViewportDraw* pWd,
									 const AcDbObjectId& entId, AcDbGripOperations::DrawType type,
									 AcGePoint3d* imageGripPoint, int gripSize);
using GripWorldDrawPtr = bool (*)(AcDbGripData* pThis, AcGiWorldDraw* pWd,
								  const AcDbObjectId& entId, AcDbGripOperations::DrawType type,
								  AcGePoint3d* imageGripPoint, double dGripSize);

#include "icarx/IcArxPackPush.h"

class AcDbGripData
{
private:
	AcGePoint3d m_gripPt;
	AcGePoint3d* m_pAltBasePt;
	void* m_pAppData;
	GripOperationPtr m_pHotGripFunc;
	GripOperationPtr m_pHoverFunc;
	union
	{
		GripRtClkHandler oldHandler;
		GripRightClickHandler newHandler;
	} m_pRtClk;
	GripWorldDrawPtr m_pWorldDraw;
	GripViewportDrawPtr m_pViewportDraw;
	GripOpStatusPtr m_pGripOpStatFunc;
	GripToolTipPtr m_pToolTipFunc;
	GripDimensionPtr m_pHoverDimensionFunc;
	GripDimensionPtr m_pHotGripDimensionFunc;
	unsigned int m_bitFlags;
	GripInputPointPtr m_pInputPointFunc;
	AcRxClass* m_pAppDataClass;
	GripCLIPromptPtr m_pCLIPromptFunc;
	GripCLIDisplayStringPtr m_pCLIDisplayStringFunc;

private:
	void* m_pReserved = nullptr;
	friend class IcAcDbGripData;

public:
	ACDBCORE2D_PORT AcDbGripData();
	AcDbGripData(const AcGePoint3d&, void*, AcRxClass*, GripOperationPtr hotGrip = nullptr,
				 GripOperationPtr hoverGrip = nullptr, GripRtClkHandler RtClk = nullptr,
				 GripWorldDrawPtr wd = nullptr, GripViewportDrawPtr vd = nullptr,
				 GripOpStatusPtr stat = nullptr, GripToolTipPtr tt = nullptr,
				 GripDimensionPtr hoverDim = nullptr, GripDimensionPtr hotGripDim = nullptr,
				 unsigned int bitFlags = 0, AcGePoint3d* altBasePt = nullptr,
				 GripInputPointPtr inputPointFunc = nullptr);
	AcDbGripData(const AcGePoint3d&, void*, GripOperationPtr hotGrip = nullptr,
				 GripOperationPtr hoverGrip = nullptr, GripRtClkHandler RtClk = nullptr,
				 GripWorldDrawPtr wd = nullptr, GripViewportDrawPtr vd = nullptr,
				 GripOpStatusPtr stat = nullptr, GripToolTipPtr tt = nullptr,
				 GripDimensionPtr hoverDim = nullptr, GripDimensionPtr hotGripDim = nullptr,
				 unsigned int bitFlags = 0, AcGePoint3d* altBasePt = nullptr,
				 GripInputPointPtr inputPointFunc = nullptr);
	ACDBCORE2D_PORT AcDbGripData(const AcDbGripData&);
	ACDBCORE2D_PORT AcDbGripData( AcDbGripData&&) noexcept;
	ACDBCORE2D_PORT AcDbGripData& operator=(const AcDbGripData&);
	ACDBCORE2D_PORT AcDbGripData& operator=(AcDbGripData&&) noexcept;
	ACDBCORE2D_PORT ~AcDbGripData();

	AcGePoint3d* alternateBasePoint() const;
	void* appData() const;
	AcRxClass* appDataAcRxClass() const;
	bool areModeKeywordsDisabled() const;
	unsigned int bitFlags() const;
	void disableGrip(bool disable);
	void disableModeKeywords(bool disable);
	void disableRubberBandLine(bool disable);
	bool drawAtDragImageGripPoint() const;
	bool forcedPickOn() const;
	GripCLIDisplayStringPtr getCLIDisplayStringFunc() const;
	GripCLIPromptPtr getCLIPromptFunc() const;
	bool gizmosEnabled() const;
	bool gripIsDisabled() const;
	bool gripIsPerViewport() const;
	GripOpStatusPtr gripOpStatFunc() const;
	const AcGePoint3d& gripPoint() const;
	bool gripRightClickIsNewStyle() const;
	GripDimensionPtr hotGripDimensionFunc() const;
	GripOperationPtr hotGripFunc() const;
	GripDimensionPtr hoverDimensionFunc() const;
	GripOperationPtr hoverFunc() const;
	GripInputPointPtr inputPointFunc() const;
	bool isRubberBandLineDisabled() const;
	bool mapGripHotToRtClk() const;
	GripRightClickHandler righClick() const;
	GripRtClkHandler rtClk() const;
	void setAllData(const AcGePoint3d&, void*, GripOperationPtr hotGrip = nullptr,
					GripOperationPtr hoverGrip = nullptr, GripRtClkHandler RtClk = nullptr,
					GripWorldDrawPtr wd = nullptr, GripViewportDrawPtr vd = nullptr,
					GripOpStatusPtr stat = nullptr, GripToolTipPtr tt = nullptr,
					GripDimensionPtr hoverDim = nullptr, GripDimensionPtr hotGripDim = nullptr,
					unsigned int bitFlags = 0, AcGePoint3d* altBasePt = nullptr,
					GripInputPointPtr inputPointFunc = nullptr, AcRxClass* appDataAcRxClass = nullptr);
	void setAlternateBasePoint(AcGePoint3d* altBasePt);
	void setAppData(void* appData);
	void setAppDataAcRxClass(AcRxClass* pClass);
	void setBitFlags(unsigned int flags);
	void setCLIDisplayStringFunc(GripCLIDisplayStringPtr pFunc);
	void setCLIPromptFunc(GripCLIPromptPtr pFunc);
	void setDrawAtDragImageGripPoint(bool atDragPoint);
	void setForcedPickOn(bool on);
	void setGizmosEnabled(bool on);
	void setGripIsPerViewport(bool on);
	void setGripOpStatFunc(GripOpStatusPtr pFunc);
	void setGripPoint(const AcGePoint3d& pt);
	void setHotGripDimensionFunc(GripDimensionPtr pFunc);
	void setHotGripFunc(GripOperationPtr pFunc);
	void setHoverDimensionFunc(GripDimensionPtr pFunc);
	void setHoverFunc(GripOperationPtr pFunc);
	void setInputPointFunc(GripInputPointPtr pFunc);
	void setMapGripHotToRtClk(bool on);
	void setRightClick(GripRightClickHandler pFunc);
	void setRtClk(GripRtClkHandler pFunc);
	void setSkipWhenShared(bool skip);
	void setToolTipFunc(GripToolTipPtr pFunc);
	void setTriggerGrip(bool trigger);
	void setViewportDraw(GripViewportDrawPtr pFunc);
	void setWorldDraw(GripWorldDrawPtr pFunc);
	bool skipWhenShared() const;
	GripToolTipPtr toolTipFunc() const;
	bool triggerGrip() const;
	GripViewportDrawPtr viewportDraw() const;
	GripWorldDrawPtr worldDraw() const;
};

#include "icarx/IcArxPackPop.h"

inline AcDbGripData::AcDbGripData(const AcGePoint3d& pt, void* AppData, AcRxClass* pAppDataClass,
								  GripOperationPtr hotGrip, GripOperationPtr hoverGrip,
								  GripRtClkHandler RtClk, GripWorldDrawPtr wd,
								  GripViewportDrawPtr vd, GripOpStatusPtr stat, GripToolTipPtr tt,
								  GripDimensionPtr hoverDim, GripDimensionPtr hotGripDim,
								  unsigned int bitFlags, AcGePoint3d* altBasePt, GripInputPointPtr inputPointFunc)
    : AcDbGripData()
{
	m_gripPt = pt;
	m_pAltBasePt = altBasePt;
	m_pAppData = AppData;
	m_pHotGripFunc = hotGrip;
	m_pHoverFunc = hoverGrip;
	m_pWorldDraw = wd;
	m_pViewportDraw = vd;
	m_pGripOpStatFunc = stat;
	m_pToolTipFunc = tt;
	m_pHoverDimensionFunc = hoverDim;
	m_pHotGripDimensionFunc = hotGripDim;
	m_bitFlags = bitFlags;
	m_pInputPointFunc = inputPointFunc;
	m_pAppDataClass = pAppDataClass;
	m_pCLIPromptFunc = nullptr;
	m_pCLIDisplayStringFunc = nullptr;
	setRtClk(RtClk);
}

inline AcDbGripData::AcDbGripData(const AcGePoint3d& pt, void* AppData, GripOperationPtr hotGrip,
								  GripOperationPtr hoverGrip, GripRtClkHandler RtClk,
								  GripWorldDrawPtr wd, GripViewportDrawPtr vd, GripOpStatusPtr stat,
								  GripToolTipPtr tt, GripDimensionPtr hoverDim,
								  GripDimensionPtr hotGripDim, unsigned int bitFlags, AcGePoint3d* altBasePt,
        GripInputPointPtr inputPointFunc)
    : AcDbGripData()
{
	m_gripPt = pt;
	m_pAltBasePt = altBasePt;
	m_pAppData = AppData;
	m_pHotGripFunc = hotGrip;
	m_pHoverFunc = hoverGrip;
	m_pWorldDraw = wd;
	m_pViewportDraw = vd;
	m_pGripOpStatFunc = stat;
	m_pToolTipFunc = tt;
	m_pHoverDimensionFunc = hoverDim;
	m_pHotGripDimensionFunc = hotGripDim;
	m_bitFlags = bitFlags;
	m_pInputPointFunc = inputPointFunc;
	m_pAppDataClass = nullptr;
	m_pCLIPromptFunc = nullptr;
	m_pCLIDisplayStringFunc = nullptr;
	setRtClk(RtClk);
}

inline AcGePoint3d* AcDbGripData::alternateBasePoint() const
{
	return m_pAltBasePt;
}

inline void* AcDbGripData::appData() const
{
	return m_pAppData;
}

inline AcRxClass* AcDbGripData::appDataAcRxClass() const
{
	return m_pAppDataClass;
}

inline bool AcDbGripData::areModeKeywordsDisabled() const
{
	return !!(m_bitFlags & AcDbGripOperations::kDisableModeKeywords);
}

inline unsigned int AcDbGripData::bitFlags() const
{
	return m_bitFlags;
}

inline void AcDbGripData::disableGrip(bool disable)
{
	if (disable)
		m_bitFlags |= AcDbGripOperations::kGripIsDisabled;
	else
		m_bitFlags &= ~AcDbGripOperations::kGripIsDisabled;
}

inline void AcDbGripData::disableModeKeywords(bool disable)
{
	if (disable)
		m_bitFlags |= AcDbGripOperations::kDisableModeKeywords;
	else
		m_bitFlags &= ~AcDbGripOperations::kDisableModeKeywords;
}

inline void AcDbGripData::disableRubberBandLine(bool disable)
{
	if (disable)
		m_bitFlags |= AcDbGripOperations::kDisableRubberBandLine;
	else
		m_bitFlags &= ~AcDbGripOperations::kDisableRubberBandLine;
}

inline bool AcDbGripData::drawAtDragImageGripPoint() const
{
	return !!(m_bitFlags & AcDbGripOperations::kDrawAtDragImageGripPoint);
}

inline bool AcDbGripData::forcedPickOn() const
{
	return !!(m_bitFlags & AcDbGripOperations::kTurnOnForcedPick);
}

inline GripCLIDisplayStringPtr AcDbGripData::getCLIDisplayStringFunc() const
{
	return m_pCLIDisplayStringFunc;
}

inline GripCLIPromptPtr AcDbGripData::getCLIPromptFunc() const
{
	return m_pCLIPromptFunc;
}

inline bool AcDbGripData::gizmosEnabled() const
{
	return !!(m_bitFlags & AcDbGripOperations::kGizmosEnabled);
}

inline bool AcDbGripData::gripIsDisabled() const
{
	return !!(m_bitFlags & AcDbGripOperations::kGripIsDisabled);
}

inline bool AcDbGripData::gripIsPerViewport() const
{
	return !!(m_bitFlags & AcDbGripOperations::kGripIsPerViewport);
}

inline GripOpStatusPtr AcDbGripData::gripOpStatFunc() const
{
	return m_pGripOpStatFunc;
}

inline const AcGePoint3d& AcDbGripData::gripPoint() const
{
	return m_gripPt;
}

inline bool AcDbGripData::gripRightClickIsNewStyle() const
{
	return !!(m_bitFlags & AcDbGripOperations::kGripRightClickIsNewStyle);
}

inline GripDimensionPtr AcDbGripData::hotGripDimensionFunc() const
{
	return m_pHotGripDimensionFunc;
}

inline GripOperationPtr AcDbGripData::hotGripFunc() const
{
	return m_pHotGripFunc;
}

inline GripDimensionPtr AcDbGripData::hoverDimensionFunc() const
{
	return m_pHoverDimensionFunc;
}

inline GripOperationPtr AcDbGripData::hoverFunc() const
{
	return m_pHoverFunc;
}

inline GripInputPointPtr AcDbGripData::inputPointFunc() const
{
	return m_pInputPointFunc;
}

inline bool AcDbGripData::isRubberBandLineDisabled() const
{
	return !!(m_bitFlags & AcDbGripOperations::kDisableRubberBandLine);
}

inline bool AcDbGripData::mapGripHotToRtClk() const
{
	return !!(m_bitFlags & AcDbGripOperations::kMapGripHotToRtClk);
}

inline GripRightClickHandler AcDbGripData::righClick() const
{
	return m_pRtClk.newHandler;
}

inline GripRtClkHandler AcDbGripData::rtClk() const
{
	return m_pRtClk.oldHandler;
}

inline void AcDbGripData::setAllData(const AcGePoint3d& pt, void* AppData, GripOperationPtr hotGrip,
									 GripOperationPtr hoverGrip, GripRtClkHandler RtClk,
									 GripWorldDrawPtr wd, GripViewportDrawPtr vd,
									 GripOpStatusPtr stat, GripToolTipPtr tt,
									 GripDimensionPtr hoverDim, GripDimensionPtr hotGripDim,
									 unsigned int bitFlags, AcGePoint3d* altBasePt,
									 GripInputPointPtr inputPointFunc, AcRxClass* pAppDataClass)
{
	m_gripPt = pt;
	m_pAppData = AppData;
	m_pAppDataClass = pAppDataClass;
	m_pHotGripFunc = hotGrip;
	m_pHoverFunc = hoverGrip;
	setRtClk(RtClk);
	m_pWorldDraw = wd;
	m_pViewportDraw = vd;
	m_pGripOpStatFunc = stat;
	m_pToolTipFunc = tt;
	m_pHoverDimensionFunc = hoverDim;
	m_pHotGripDimensionFunc = hotGripDim;
	m_bitFlags = bitFlags;
	m_pAltBasePt = altBasePt;
	m_pInputPointFunc = inputPointFunc;
}

inline void AcDbGripData::setAlternateBasePoint(AcGePoint3d* altBasePt)
{
	m_pAltBasePt = altBasePt;
}

inline void AcDbGripData::setAppData(void* appData)
{
	m_pAppData = appData;
}

inline void AcDbGripData::setAppDataAcRxClass(AcRxClass* appDataClass)
{
	m_pAppDataClass = appDataClass;
}

inline void AcDbGripData::setBitFlags(unsigned int flags)
{
	m_bitFlags = flags;
}

inline void AcDbGripData::setCLIDisplayStringFunc(GripCLIDisplayStringPtr pFunc)
{
	m_pCLIDisplayStringFunc = pFunc;
}

inline void AcDbGripData::setCLIPromptFunc(GripCLIPromptPtr pFunc)
{
	m_pCLIPromptFunc = pFunc;
}

inline void AcDbGripData::setDrawAtDragImageGripPoint(bool atDragPoint)
{
	if (atDragPoint)
		m_bitFlags |= AcDbGripOperations::kDrawAtDragImageGripPoint;
	else
		m_bitFlags &= ~AcDbGripOperations::kDrawAtDragImageGripPoint;
}

inline void AcDbGripData::setForcedPickOn(bool on)
{
	if (on)
		m_bitFlags |= AcDbGripOperations::kTurnOnForcedPick;
	else
		m_bitFlags &= ~AcDbGripOperations::kTurnOnForcedPick;
}

inline void AcDbGripData::setGizmosEnabled(bool on)
{
	if (on)
		m_bitFlags |= AcDbGripOperations::kGizmosEnabled;
	else
		m_bitFlags &= ~AcDbGripOperations::kGizmosEnabled;
}

inline void AcDbGripData::setGripIsPerViewport(bool on)
{
	if (on)
		m_bitFlags |= AcDbGripOperations::kGripIsPerViewport;
	else
		m_bitFlags &= ~AcDbGripOperations::kGripIsPerViewport;
}

inline void AcDbGripData::setGripOpStatFunc(GripOpStatusPtr pFunc)
{
	m_pGripOpStatFunc = pFunc;
}

inline void AcDbGripData::setGripPoint(const AcGePoint3d& pt)
{
	m_gripPt = pt;
}

inline void AcDbGripData::setHotGripDimensionFunc(GripDimensionPtr pFunc)
{
	m_pHotGripDimensionFunc = pFunc;
}

inline void AcDbGripData::setHotGripFunc(GripOperationPtr pFunc)
{
	m_pHotGripFunc = pFunc;
}

inline void AcDbGripData::setHoverDimensionFunc(GripDimensionPtr pFunc)
{
	m_pHoverDimensionFunc = pFunc;
}

inline void AcDbGripData::setHoverFunc(GripOperationPtr pFunc)
{
	m_pHoverFunc = pFunc;
}

inline void AcDbGripData::setInputPointFunc(GripInputPointPtr pFunc)
{
	m_pInputPointFunc = pFunc;
}

inline void AcDbGripData::setMapGripHotToRtClk(bool on)
{
	if (on)
		m_bitFlags |= AcDbGripOperations::kMapGripHotToRtClk;
	else
		m_bitFlags &= ~AcDbGripOperations::kMapGripHotToRtClk;
}

inline void AcDbGripData::setRightClick(GripRightClickHandler pFunc)
{
	m_bitFlags |= AcDbGripOperations::kGripRightClickIsNewStyle;
	m_pRtClk.newHandler = pFunc;
}

inline void AcDbGripData::setRtClk(GripRtClkHandler pFunc)
{
	m_bitFlags &= ~AcDbGripOperations::kGripRightClickIsNewStyle;
	m_pRtClk.oldHandler = pFunc;
}

inline void AcDbGripData::setSkipWhenShared(bool skip)
{
	if (skip)
		m_bitFlags |= AcDbGripOperations::kSkipWhenShared;
	else
		m_bitFlags &= ~AcDbGripOperations::kSkipWhenShared;
}

inline void AcDbGripData::setToolTipFunc(GripToolTipPtr pFunc)
{
	m_pToolTipFunc = pFunc;
}

inline void AcDbGripData::setTriggerGrip(bool trigger)
{
	if (trigger)
		m_bitFlags |= AcDbGripOperations::kTriggerGrip | AcDbGripOperations::kSkipWhenShared;
	else
		m_bitFlags &= ~(AcDbGripOperations::kTriggerGrip | AcDbGripOperations::kSkipWhenShared);
}

inline void AcDbGripData::setViewportDraw(GripViewportDrawPtr pFunc)
{
	m_pViewportDraw = pFunc;
}

inline void AcDbGripData::setWorldDraw(GripWorldDrawPtr pFunc)
{
	m_pWorldDraw = pFunc;
}

inline bool AcDbGripData::skipWhenShared() const
{
	return !!(m_bitFlags & AcDbGripOperations::kSkipWhenShared);
}

inline GripToolTipPtr AcDbGripData::toolTipFunc() const
{
	return m_pToolTipFunc;
}

inline bool AcDbGripData::triggerGrip() const
{
	return !!(m_bitFlags & AcDbGripOperations::kTriggerGrip);
}

inline GripViewportDrawPtr AcDbGripData::viewportDraw() const
{
	return m_pViewportDraw;
}

inline GripWorldDrawPtr AcDbGripData::worldDraw() const
{
	return m_pWorldDraw;
}

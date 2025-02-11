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
***     Description: Declaration of AcDbPointCloudEx class
***
*****************************************************************************/
#pragma once

#include <tchar.h>
#include "icarx/AcDbEntity.h"
#include "AcPointCloudItem.h"

class AcDbPointCloudCrop;
class AcDbPointCloudExLimitBox;
class PointCloudPerfMonitor;
class IAcDbPointCloudAttributeFilter;
class IAcDbPointCloudDataBuffer;
class IAcDbPointCloudPointProcessor;
class IAcDbPointCloudSpatialFilter;
class IAcDbPointCloudAttributeFilter;
class AcPointCloudExtractedCylinder;
class AcDbPointCloudCropStateManager;
class CPoint;

namespace Autodesk
{
namespace RealityComputing
{
namespace Data
{
class RCProject;
}
}  // namespace RealityComputing
}  // namespace Autodesk

#include "icarx/IcArxPackPush.h"

class ACDB_PORT AcDbPointCloudEx : public AcDbEntity
{
	friend class AcDbPointCloudCropStateManagerImp;

public:
	enum DispOptionOutOfRange
	{
		kUseMinMaxColors = 0,
		kUseRGBScanColors,
		kHidePoints
	};

	enum PointCloudOSnapMode
	{
		kOsModePNod = 0,
		kOsModePNea = 1,
		kOsModePPer = 2,
		kOsModePEdgeNea = 3,
		kOsModePEdgePer = 4,
		kOsModePInt = 5,
		kOsModePCL = 6,
		kOsModePCorner = 7
	};

	enum StylizationType
	{
		kTrueColor = 1,
		kSingleColor,
		kNormalRamp,
		kHeightRamp,
		kIntensityRamp,
		kClassificationRamp
	};

public:
	ACRX_DECLARE_MEMBERS(AcDbPointCloudEx);

protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
	Acad::ErrorStatus subGetGeomExtents(AcDbExtents& extents) const override;
	bool subIsContentSnappable() const override;
	void subList() const override;
	Acad::ErrorStatus subTransformBy(const AcGeMatrix3d& xform) override;
	bool subWorldDraw(AcGiWorldDraw* mode) override;

public:
	AcDbPointCloudEx();
	~AcDbPointCloudEx();

	Acad::ErrorStatus addAttributeFilter(IAcDbPointCloudAttributeFilter* pFilter);
	void addCroppingBoundary(const AcDbPointCloudCrop& cropping);
	Acad::ErrorStatus addSpatialFilter(IAcDbPointCloudSpatialFilter* pFilter);
	void applyGeoLocation(bool useDrawingGeo = false, const AcString& geoCS = L"");
	void clearAttributeFilters();
	Acad::ErrorStatus clearCropping();
	void clearGeoLocation();
	void clearSpatialFilters();
	Acad::ErrorStatus copyFrom(const AcRxObject* pObj) override;
	AcDbPointCloudCropStateManager* cropStatesManager();
	const AcDbPointCloudCropStateManager* cropStatesManagerConst() const;
	Acad::ErrorStatus decomposeForSave(AcDb::AcDbDwgVersion ver, AcDbObject*& replaceObj,
									   AcDbObjectId& replaceId, bool& exchangeXData) override;
	Acad::ErrorStatus detectPointBelonger(const AcGePoint3d& ptInWCS, AcString& scanGuid,
										  uint16_t& segmentIndex) const;
	void dragStatus(const AcDb::DragStat status) override;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	bool elevationApplyToFixedRange() const;
	AcDbPointCloudEx::DispOptionOutOfRange elevationOutOfRangeBehavior() const;
	AcPointCloudItem* findRegionItem(int regionId);
	AcPointCloudItem* findScanItem(const AcString& scanGuid);
	bool geolocate() const;
	bool getActiveFileName(AcString& strActiveFileName) const;
	Acad::ErrorStatus getCandidatePlane(const CPoint& pt, AcGePlane& result,
										double& distToEdge, double& objWidth, double& objHeight,
										void*& context) const;
	AcString getColorSchemeForStylization(AcDbPointCloudEx::StylizationType type) const;
	int getCroppingCount() const;
	bool getCroppingInvert() const;
	AcString getCurrentColorScheme() const;
	Acad::ErrorStatus getCustomOsnapInfo(AcDbPointCloudEx::PointCloudOSnapMode snapMode,
										 const AcGePoint3d& pickPoint, const AcGePoint3d& lastPoint,
										 const AcGeMatrix3d& viewXform,
										 AcArray<AcGePoint3d>& snapPoints);
	Acad::ErrorStatus getCylinderAt(const AcGeMatrix3d& viewXform, const AcGePoint3d& pickPt,
									AcGePoint3d& origin, AcGeVector3d& axis, double& height,
									double& radius);
	Acad::ErrorStatus getCylinderAt(const AcGeMatrix3d& viewXform, const AcGePoint3d& pickPt,
									AcPointCloudExtractedCylinder& extractedCylinder);
	unsigned int getDisplayedVisiblePointCount() const;
	void getEcs(AcGeMatrix3d& retVal) const override;
	Acad::ErrorStatus getEstimatedPointCountByPrecision(
			unsigned long long& pointCount, double distPrecision,
			IAcDbPointCloudSpatialFilter* pSpatialFilter = nullptr,
			IAcDbPointCloudAttributeFilter* pAttributeFilter = nullptr) const;
	void getLimitBox(AcDbPointCloudExLimitBox& limitBox) const;
	unsigned int getLoadedVisiblePointCount() const;
	Acad::ErrorStatus getMinDistPrecision(double& minDistPrecision) const;
	void getNativeCloudExtent(AcDbExtents& extents) const;
	bool getPlaneBoundaryAt(const AcGeMatrix3d& viewXform, const AcGePoint3d& pickPt,
							AcGePoint3dArray& arrPlaneVertices);
	bool getPlaneOrPointAt(const AcGeMatrix3d& viewXform, const AcGePoint3d& pickPt,
						   AcArray<AcGePoint3d>& points);
	AcDbPointCloudCrop* getPointCloudCropping(int index);
	const AcDbPointCloudCrop* getPointCloudCroppingConst(int index) const;
	const AcPointCloudItemArray* getPointCloudDataList() const;
	AcString getPointCloudName() const;
	PointCloudPerfMonitor* getPointCloudPerfMonitor();
	Acad::ErrorStatus getPointDataByPointCount(IAcDbPointCloudDataBuffer*& pointData,
											   uint32_t pointCount,
											   IAcDbPointCloudSpatialFilter* pSpatialFilter,
											   IAcDbPointCloudAttributeFilter* pAttributeFilter,
											   uint32_t dataTypes,
											   uint32_t maxPointLimitation) const;
	Acad::ErrorStatus getPointDataByPointCount(IAcDbPointCloudDataBuffer*& pointData,
											   uint32_t pointCount,
											   const AcArray<AcString>& arrScanGuids,
											   IAcDbPointCloudSpatialFilter* pSpatialFilter,
											   IAcDbPointCloudAttributeFilter* pAttributeFilter,
											   uint32_t dataTypes,
											   uint32_t maxPointLimitation) const;
	Acad::ErrorStatus getPointDataByPrecision(
			IAcDbPointCloudDataBuffer*& pointData, double distPrecision,
			IAcDbPointCloudSpatialFilter* pSpatialFilter = nullptr,
			IAcDbPointCloudAttributeFilter* pAttributeFilter = nullptr, uint32_t dataTypes = 0,
			uint32_t maxPointLimitation = 1000000ULL) const;
	Acad::ErrorStatus getPointDataBySegment(IAcDbPointCloudDataBuffer*& pointData,
											const AcString& scanGuid, uint16_t nSegmentIndex,
											uint32_t nExpectedCount) const;
	void* getQuery();
	Autodesk::RealityComputing::Data::RCProject* getReCapProject() const;
	bool getScanViewInfo(const AcString& scanGuid, AcGePoint3d& origin, AcDbExtents& extent) const;
	unsigned int getVisiblePointCount() const;
	AcDbPointCloudEx::DispOptionOutOfRange intensityOutOfRangeBehavior() const;
	AcGePoint3d location() const;
	bool locked() const;
	double maxElevation() const;
	int32_t maxIntensity() const;
	double minElevation() const;
	int32_t minIntensity() const;
	void objectToWorldMatrix(AcGeMatrix3d& mat) const;
	AcDbObjectId pointCloudDefExId() const;
	AcDbObjectId reactorId() const;
	Acad::ErrorStatus removeAttributeFilter(IAcDbPointCloudAttributeFilter* pFilter);
	Acad::ErrorStatus removeLastCropping();
	Acad::ErrorStatus removeSpatialFilter(IAcDbPointCloudSpatialFilter* pFilter);
	void resetLimitBox();
	void resetScanRegionVisibility();
	double rotation() const;
	double scale() const;
	bool setActiveFileName(const wchar_t* strActiveFileName);
	void setAllRegionHighlight(bool bHighlight, bool bIncludeUnassignedPoints = false);
	void setAllRegionsVisibility(bool bVisible, bool includeUnassigned = false);
	void setAllScanHighlight(bool bHighlight);
	void setAllScansVisibility(bool bVisible);
	void setAllScansVisibilityByRegion(int regionId, bool bVisible);
	Acad::ErrorStatus setColorSchemeForStylization(const AcString& guid,
												   AcDbPointCloudEx::StylizationType type);
	Acad::ErrorStatus setCroppingInvert(bool invert);
	Acad::ErrorStatus setCurrentColorScheme(const AcString& guid);
	void setElevationApplyToFixedRange(bool val);
	void setElevationOutOfRangeBehavior(AcDbPointCloudEx::DispOptionOutOfRange dispOp);
	void setHighlightLimitboxBoundary(bool val);
	void setInCreatingCroppingMode(bool bCreating);
	void setIntensityOutOfRangeBehavior(AcDbPointCloudEx::DispOptionOutOfRange dispOp);
	Acad::ErrorStatus setLimitBox(const AcDbPointCloudExLimitBox& limitBox);
	Acad::ErrorStatus setLocation(const AcGePoint3d& pt);
	void setLocked(bool locked);
	Acad::ErrorStatus setMinMaxElevation(double min, double max);
	Acad::ErrorStatus setMinMaxIntensity(int min, int max);
	void setPointCloudDefExId(const AcDbObjectId& defExId);
	Acad::ErrorStatus setPointCloudName(const AcString& name);
	void setReactorId(const AcDbObjectId& reactorId);
	void setRegionVisibility(int regionId, bool bVisible);
	Acad::ErrorStatus setRotation(double val);
	Acad::ErrorStatus setScale(double val);
	void setScanVisibility(const AcString& scanGuid, bool bVisible);
	Acad::ErrorStatus setShowCropped(bool bShowCropped);
	void setShowElevationAsGradient(bool b);
	void setShowIntensityAsGradient(bool b);
	Acad::ErrorStatus setStylizationType(AcDbPointCloudEx::StylizationType type);
	bool showCropped() const;
	bool showElevationAsGradient() const;
	bool showIntensityAsGradient() const;
	AcDbPointCloudEx::StylizationType stylizationType() const;
	Acad::ErrorStatus subErase(bool erasing) override;
	Acad::ErrorStatus subSwapIdWith(AcDbObjectId otherId, bool swapXdata = false,
									bool swapExtDict = false) override;
	Acad::ErrorStatus traverseAllPointData(IAcDbPointCloudPointProcessor* processor,
										   IAcDbPointCloudSpatialFilter* pSpatialFilter,
										   uint32_t dataTypes, int LODLevel) const;
	Acad::ErrorStatus traverseAllPointData(IAcDbPointCloudPointProcessor* processor,
										   IAcDbPointCloudSpatialFilter* pSpatialFilter,
										   uint32_t dataTypes, int LODLevel,
										   const AcArray<AcString>& arrScanGuids) const;
	void updateGeoLocation();
};

#include "icarx/IcArxPackPop.h"

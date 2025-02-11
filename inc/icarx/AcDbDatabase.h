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
***     Description: Declaration of AcDbDatabase class
***
*****************************************************************************/
#pragma once

#include "../AcDbCore2dDefs.h"
#include "../PAL/api/codepgid.h"
#include "../rxobject.h"
#include "../AcHeapOpers.h"
#include "../dbdate.h"
#include "../dbid.h"
#include "../acarray.h"
#include "../dbidar.h"
#include "../dbsecurity.h"
#include "../dbdimvar.h"

#include "AcCmColor.h"
#include "AcDb.h"
#include "acut_str_util.h"

class AcDbObjectId;
class AcDbObject;
class AcDbSymbolTable;
class AcDbBlockTable;
class AcDbLayerTable;
class AcDbTextStyleTable;
class AcDbLinetypeTable;
class AcDbViewTable;
class AcDbUCSTable;
class AcDbViewportTable;
class AcDbRegAppTable;
class AcDbDimStyleTable;
class AcDbDictionary;
class AcDbDictionaryWithDefault;
class AcDbSectionManager;
class AcDbDataLinkManager;
class AcDbObjectIdGraph;
class AcDbHandle;
class AcDwgFileHandle;
class IAcReadStream;
class AcGePoint2d;
class AcGePoint3d;
class AcGeMatrix3d;
class AcGeVector3d;
class AcDbIdMapping;
class AcDbDatabaseReactor;
class AcDbAuditInfo;
class AcDbUndoController;
class AcDbTransactionManager;
class AcString;
class AcDbDimStyleTableRecord;
class AcDbSpatialFilter;
class AcDbLayerFilter;
class AcDbLayerStateManager;
class AcDbObjectContextManager;
class AcDbAnnotationScale;

namespace Atil
{
class Image;
}

class AcDbImpDatabase;

#include "IcArxPackPush.h"

class AcDbDatabase
		: public AcRxObject
		, public AcHeapOperators
{
	friend class AcDbSystemInternals;

public:
	enum OpenMode
	{
		kForReadAndReadShare = 1,
		kForReadAndWriteNoShare = 2,
		kForReadAndAllShare = 3,
		kTryForReadShare = 4
	};

	enum EraseMask
	{
		kZeroLengthCurve = 0x01,
		kEmptyText = 0x02,
		kAllEmptyObj = 0xFFFFFFFF
	};

private:
	AcDbImpDatabase* mpImpDb = nullptr;

private:
	AcDbDatabase(AcDbSystemInternals*);
	AcDbDatabase(const AcDbDatabase&) = delete;
	AcDbDatabase& operator=(const AcDbDatabase&) = delete;

public:
	ACRX_DECLARE_MEMBERS(AcDbDatabase);

	DIM_METHOD();

	ACDBCORE2D_PORT AcDbDatabase(bool buildDefaultDrawing = true, bool noDocument = false);
	ACDBCORE2D_PORT ~AcDbDatabase();

	ACDBCORE2D_PORT AcDbObjectId UCSTableId() const;
	void abortDeepClone(AcDbIdMapping& idMap);
	ACDBCORE2D_PORT Acad::ErrorStatus addAcDbObject(AcDbObjectId& id, AcDbObject* pObj);
	ACDBCORE2D_PORT Acad::ErrorStatus addAcDbObject(AcDbObject* pObj);
	ACDBCORE2D_PORT Acad::ErrorStatus addReactor(AcDbDatabaseReactor* pReactor) const;
	double angbase() const;
	bool angdir() const;
	bool annoAllVisible() const;
	bool annotativeDwg() const;
	Acad::ErrorStatus applyPartialOpenFilters(const AcDbSpatialFilter* pSpatialFilter,
											  const AcDbLayerFilter* pLayerFilter);
	int approxNumObjects() const;
	bool attdia() const;
	int16_t attmode() const;
	bool attreq() const;
	Acad::ErrorStatus auditXData(AcDbAuditInfo* pInfo);
	int16_t aunits() const;
	int16_t auprec() const;
	bool blipmode() const;
	ACDBCORE2D_PORT AcDbObjectId blockTableId() const;
	AcDbObjectId byBlockLinetype() const;
	AcDbObjectId byBlockMaterial() const;
	AcDbObjectId byLayerLinetype() const;
	AcDbObjectId byLayerMaterial() const;
	int16_t cDynDisplayMode() const;
	bool cameraDisplay() const;
	double cameraHeight() const;
	AcDbAnnotationScale* cannoscale() const;
	AcCmColor cecolor() const;
	double celtscale() const;
	AcDbObjectId celtype() const;
	AcDb::LineWeight celweight() const;
	AcCmTransparency cetransparency() const;
	double chamfera() const;
	double chamferb() const;
	double chamferc() const;
	double chamferd() const;
	const ACHAR* classDxfName(const AcRxClass* pClass);
	AcDbObjectId clayer() const;
	const SecurityParams* cloneSecurityParams();
	Acad::ErrorStatus closeInput(bool bCloseFile);
	AcDbObjectId cmaterial() const;
	int16_t cmljust() const;
	double cmlscale() const;
	AcDbObjectId cmlstyleID() const;
	ACDBCORE2D_PORT AcDbObjectId colorDictionaryId() const;
	AcDbObjectId continuousLinetype() const;
	int16_t coords() const;
	uint32_t countEmptyObjects(const uint32_t flags);
	Acad::ErrorStatus countHardReferences(const AcDbObjectIdArray& ids, uint32_t* pCount);
	uint8_t cshadow() const;
	AcDbObjectId currentSpaceId() const;
	AcDbObjectId dataLinkDictionaryId(void) const;
	ACDBCORE2D_PORT Acad::ErrorStatus deepCloneObjects(const AcDbObjectIdArray& objectIds,
													   const AcDbObjectId& owner,
													   AcDbIdMapping& idMap,
													   bool deferXlation = false);
	int16_t delUsedObj() const;
	ACDBCORE2D_PORT AcDbObjectId detailViewStyle() const;
	ACDBCORE2D_PORT AcDbObjectId detailViewStyleDictionaryId() const;
	uint8_t dgnframe() const;
	uint8_t dimAssoc() const;
	ACDBCORE2D_PORT AcDbObjectId dimStyleTableId() const;
	bool dimaso() const;
	bool dimsho() const;
	int dimfit() const;
	AcDbObjectId dimstyle() const;
	int dimunit() const;
	void disablePartialOpen();
	void disableUndoRecording(bool disable);
	ACDBCORE2D_PORT bool dispSilh() const;
	static void disposeSecurityParams(const SecurityParams* pSecParams);
	AcDbObjectId dragVisStyle() const;
	int16_t dragmode() const;
	uint8_t drawOrderCtl() const;
	uint8_t dwfframe() const;
	bool dwgFileWasSavedByAutodeskSoftware() const;
	int16_t dxeVal() const;
	Acad::ErrorStatus dxfIn(const ACHAR* dxfFilename, const ACHAR* logFilename = nullptr);
	Acad::ErrorStatus dxfIn(IAcReadStream* pInputStream, const ACHAR* logFilename = nullptr);
	ACDBCORE2D_PORT Acad::ErrorStatus dxfOut(const ACHAR* fileName, int precision = 16,
											 AcDb::AcDbDwgVersion dwgVer = AcDb::kDHL_CURRENT,
											 bool saveThumbnailImage = false);
	ACDBCORE2D_PORT Acad::ErrorStatus dxfOutEx(
			const ACHAR* fileName, int precision = 16,
			AcDb::AcDbDwgVersion dwgVer = AcDb::kDHL_CURRENT, int nFlags = 0,
			code_page_id nCodePage = static_cast<code_page_id>(0));
	double elevation() const;
	AcDb::EndCaps endCaps() const;
	uint32_t eraseEmptyObjects(const uint32_t flags);
	Acad::ErrorStatus evaluateFields(int nContext, const ACHAR* pszPropName = nullptr,
									 AcDbDatabase* pDb = nullptr, int* pNumFound = nullptr,
									 int* pNumEvaluated = nullptr);
	AcGePoint3d extmax() const;
	AcGePoint3d extmin() const;
	ACDBCORE2D_PORT double facetres() const;
	double filletrad() const;
	bool fillmode() const;
	void forceWblockDatabaseCopy();

	template<class TableType>
	AcDbObjectId getSymbolTableId() const;

	ACDBCORE2D_PORT AcString geoCoordinateSystemId() const;
	bool geoMarkerVisibility() const;
	double get3dDwfPrec() const;
	ACDBCORE2D_PORT Acad::ErrorStatus getAcDbObjectId(AcDbObjectId& retId, bool createIfNotFound,
													  const AcDbHandle& objHandle,
													  uint32_t xRefId = 0);
	Acad::ErrorStatus getBlockTable(AcDbSymbolTable*& pTable, AcDb::OpenMode mode = AcDb::kForRead);
	Acad::ErrorStatus getBlockTable(AcDbBlockTable*& pTable, AcDb::OpenMode mode = AcDb::kForRead);
	AcDb::PlotStyleNameType getCePlotStyleNameId(AcDbObjectId& id) const;
	Acad::ErrorStatus getColorDictionary(AcDbDictionary*& pDict,
										 AcDb::OpenMode mode = AcDb::kForRead);
	Acad::ErrorStatus getDataLinkDictionary(AcDbDictionary*& pDict,
											AcDb::OpenMode mode = AcDb::kForRead);
	AcDbDataLinkManager* getDataLinkManager(void) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getDetailViewStyleDictionary(
			AcDbDictionary*& pDict, AcDb::OpenMode mode = AcDb::kForRead);
	Acad::ErrorStatus getDimRecentStyleList(AcDbObjectIdArray& objIds) const;
	Acad::ErrorStatus getDimStyleTable(AcDbSymbolTable*& pTable,
									   AcDb::OpenMode mode = AcDb::kForRead);
	Acad::ErrorStatus getDimStyleTable(AcDbDimStyleTable*& pTable,
									   AcDb::OpenMode mode = AcDb::kForRead);
	Acad::ErrorStatus getDimapost(ACHAR*& pOutput) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getDimblk(AcString& sOutput) const;
	Acad::ErrorStatus getDimblk(ACHAR*& pOutput) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getDimblk1(AcString& sOutput) const;
	Acad::ErrorStatus getDimblk1(ACHAR*& pOutput) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getDimblk2(AcString& sOutput) const;
	Acad::ErrorStatus getDimblk2(ACHAR*& pOutput) const;
	Acad::ErrorStatus getDimpost(ACHAR*& pOutput) const;
	Acad::ErrorStatus getDimstyleChildData(const AcRxClass* pDimClass,
										   AcDbDimStyleTableRecord*& pRec,
										   AcDbObjectId& style) const;
	AcDbObjectId getDimstyleChildId(const AcRxClass* pDimClass, AcDbObjectId& parentStyle) const;
	Acad::ErrorStatus getDimstyleData(AcDbDimStyleTableRecord*& pRec) const;
	AcDbObjectId getDimstyleParentId(AcDbObjectId& childStyle) const;
	Acad::ErrorStatus getFilename(const ACHAR*& pOutput) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getFingerprintGuid(AcString& guidString) const;
	Acad::ErrorStatus getFingerprintGuid(ACHAR*& guidString) const;
	Acad::ErrorStatus getGroupDictionary(AcDbDictionary*& pDict,
										 AcDb::OpenMode mode = AcDb::kForRead);
	ACDBCORE2D_PORT Acad::ErrorStatus getHyperlinkBase(AcString& sHyperlinkBase) const;
	Acad::ErrorStatus getHyperlinkBase(ACHAR*& pOutput) const;
	AcDbLayerStateManager* getLayerStateManager() const;
	Acad::ErrorStatus getLayerTable(AcDbSymbolTable*& pTable, AcDb::OpenMode mode = AcDb::kForRead);
	Acad::ErrorStatus getLayerTable(AcDbLayerTable*& pTable, AcDb::OpenMode mode = AcDb::kForRead);
	Acad::ErrorStatus getLayoutDictionary(AcDbDictionary*& pDict,
										  AcDb::OpenMode mode = AcDb::kForRead);
	Acad::ErrorStatus getLinetypeTable(AcDbSymbolTable*& pTable,
									   AcDb::OpenMode mode = AcDb::kForRead);
	Acad::ErrorStatus getLinetypeTable(AcDbLinetypeTable*& pTable,
									   AcDb::OpenMode mode = AcDb::kForRead);
	Acad::ErrorStatus getMLStyleDictionary(AcDbDictionary*& pDict,
										   AcDb::OpenMode mode = AcDb::kForRead);
	Acad::ErrorStatus getMLeaderStyleDictionary(AcDbDictionary*& pDict,
												AcDb::OpenMode mode = AcDb::kForRead);
	Acad::ErrorStatus getMaterialDictionary(AcDbDictionary*& pDict,
											AcDb::OpenMode mode = AcDb::kForRead);
	ACDBCORE2D_PORT Acad::ErrorStatus getMenu(AcString& sMenuName) const;
	Acad::ErrorStatus getMenu(ACHAR*& pOutput) const;
	Acad::ErrorStatus getNamedObjectsDictionary(AcDbDictionary*& pDict,
												AcDb::OpenMode mode = AcDb::kForRead);
	static AcDb::LineWeight getNearestLineWeight(int weight);
	Acad::ErrorStatus getPlotSettingsDictionary(AcDbDictionary*& pTable,
												AcDb::OpenMode mode = AcDb::kForRead);
	Acad::ErrorStatus getPlotStyleNameDictionary(AcDbDictionaryWithDefault*& pDict,
												 AcDb::OpenMode mode = AcDb::kForRead);
	ACDBCORE2D_PORT Acad::ErrorStatus getProjectName(AcString& sProjectName) const;
	Acad::ErrorStatus getProjectName(ACHAR*& pOutput) const;
	Acad::ErrorStatus getRegAppTable(AcDbSymbolTable*& pTable,
									 AcDb::OpenMode mode = AcDb::kForRead);
	Acad::ErrorStatus getRegAppTable(AcDbRegAppTable*& pTable,
									 AcDb::OpenMode mode = AcDb::kForRead);
	Acad::ErrorStatus getScaleListDictionary(AcDbDictionary*& pDict,
											 AcDb::OpenMode mode = AcDb::kForRead);
	AcDbObjectId getSectionManager(void) const;
	Acad::ErrorStatus getSectionManager(AcDbSectionManager*& pMgr,
										AcDb::OpenMode mode = AcDb::kForRead) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getSectionViewStyleDictionary(
			AcDbDictionary*& pDict, AcDb::OpenMode mode = AcDb::kForRead);
	ACDBCORE2D_PORT Acad::ErrorStatus getStyleSheet(AcString& sStyleSheet) const;
	Acad::ErrorStatus getStyleSheet(ACHAR*& pOutput) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getSymbolTable(AcDbBlockTable*& pTable,
													 AcDb::OpenMode mode = AcDb::kForRead);
	Acad::ErrorStatus getSymbolTable(AcDbLayerTable*& pTable, AcDb::OpenMode mode = AcDb::kForRead);
	Acad::ErrorStatus getSymbolTable(AcDbTextStyleTable*& pTable,
									 AcDb::OpenMode mode = AcDb::kForRead);
	Acad::ErrorStatus getSymbolTable(AcDbLinetypeTable*& pTable,
									 AcDb::OpenMode mode = AcDb::kForRead);
	Acad::ErrorStatus getSymbolTable(AcDbViewTable*& pTable, AcDb::OpenMode mode = AcDb::kForRead);
	Acad::ErrorStatus getSymbolTable(AcDbUCSTable*& pTable, AcDb::OpenMode mode = AcDb::kForRead);
	Acad::ErrorStatus getSymbolTable(AcDbViewportTable*& pTable,
									 AcDb::OpenMode mode = AcDb::kForRead);
	Acad::ErrorStatus getSymbolTable(AcDbRegAppTable*& pTable,
									 AcDb::OpenMode mode = AcDb::kForRead);
	Acad::ErrorStatus getSymbolTable(AcDbDimStyleTable*& pTable,
									 AcDb::OpenMode mode = AcDb::kForRead);
	Acad::ErrorStatus getTableStyleDictionary(AcDbDictionary*& pDict,
											  AcDb::OpenMode mode = AcDb::kForRead);
	Acad::ErrorStatus getTextStyleTable(AcDbSymbolTable*& pTable,
										AcDb::OpenMode mode = AcDb::kForRead);
	Acad::ErrorStatus getTextStyleTable(AcDbTextStyleTable*& pTable,
										AcDb::OpenMode mode = AcDb::kForRead);
	Acad::ErrorStatus getTimeZoneInfo(AcDb::TimeZone tz, double& offset, AcString& desc) const;
	Acad::ErrorStatus getUCSTable(AcDbSymbolTable*& pTable, AcDb::OpenMode mode = AcDb::kForRead);
	Acad::ErrorStatus getUCSTable(AcDbUCSTable*& pTable, AcDb::OpenMode mode = AcDb::kForRead);
	ACDBCORE2D_PORT Acad::ErrorStatus getVersionGuid(AcString& guidString) const;
	Acad::ErrorStatus getVersionGuid(ACHAR*& guidString) const;
	Acad::ErrorStatus getViewTable(AcDbSymbolTable*& pTable, AcDb::OpenMode mode = AcDb::kForRead);
	Acad::ErrorStatus getViewTable(AcDbViewTable*& pTable, AcDb::OpenMode mode = AcDb::kForRead);
	Acad::ErrorStatus getViewportArray(AcDbObjectIdArray& vportIds,
									   bool bGetPaperspaceVports = true) const;
	Acad::ErrorStatus getViewportTable(AcDbSymbolTable*& pTable,
									   AcDb::OpenMode mode = AcDb::kForRead);
	Acad::ErrorStatus getViewportTable(AcDbViewportTable*& pTable,
									   AcDb::OpenMode mode = AcDb::kForRead);
	Acad::ErrorStatus getVisualStyleDictionary(AcDbDictionary*& pDict,
											   AcDb::OpenMode mode = AcDb::kForRead);
	Acad::ErrorStatus getVisualStyleList(AcArray<const ACHAR*>& vstyleList);
	AcDbObjectId globalMaterial() const;
	ACDBCORE2D_PORT AcDbObjectId groupDictionaryId() const;
	uint8_t haloGap() const;
	AcDbHandle handseed() const;
	bool hasClass(const AcRxClass* pClass) const;
	uint8_t hideText() const;
	bool hpInherit() const;
	AcGePoint2d hpOrigin() const;
	uint8_t indexctl() const;
	AcDwgFileHandle* inputFiler() const;
	AcGePoint3d insbase() const;
	Acad::ErrorStatus insert(AcDbObjectId& blockId, const ACHAR* pBlockName, AcDbDatabase* pDb,
							 bool preserveSourceDatabase = true);

	Acad::ErrorStatus insert(const AcGeMatrix3d& xform, AcDbDatabase* pDb,
							 bool preserveSourceDatabase = true);

	Acad::ErrorStatus insert(AcDbObjectId& blockId, const ACHAR* pSourceBlockName,
							 const ACHAR* pDestinationBlockName, AcDbDatabase* pDb,
							 bool preserveSourceDatabase = true);
	AcDb::UnitsValue insunits() const;
	AcCmColor interfereColor() const;
	AcDbObjectId interfereObjVisStyle() const;
	AcDbObjectId interfereVpVisStyle() const;
	uint16_t intersectColor() const;
	uint8_t intersectDisplay() const;
	ACDBCORE2D_PORT bool isBeingDestroyed() const;
	bool isEMR() const;
	static bool isObjectNonPersistent(AcDbObjectId id);
	bool isPartiallyOpened() const;
	bool isPucsOrthographic(AcDb::OrthographicView& orthoView) const;
	bool isUcsOrthographic(AcDb::OrthographicView& orthoView) const;
	static bool isValidLineWeight(int weight);
	ACDBCORE2D_PORT int16_t isolines() const;
	AcDb::JoinStyle joinStyle() const;
	AcDb::MaintenanceReleaseVersion lastSavedAsMaintenanceVersion() const;
	AcDb::AcDbDwgVersion lastSavedAsVersion() const;
	double latitude() const;
	uint8_t layerEval() const;
	int16_t layerNotify() const;
	ACDBCORE2D_PORT AcDbObjectId layerTableId() const;
	AcDbObjectId layerZero() const;
	ACDBCORE2D_PORT AcDbObjectId layoutDictionaryId() const;
	double lensLength() const;
	uint8_t lightGlyphDisplay() const;
	uint8_t lightingUnits() const;
	bool lightsInBlocks() const;
	bool limcheck() const;
	AcGePoint2d limmax() const;
	AcGePoint2d limmin() const;
	bool lineWeightDisplay() const;
	ACDBCORE2D_PORT AcDbObjectId linetypeTableId() const;
	Acad::ErrorStatus loadLineTypeFile(const ACHAR* ltn, const ACHAR* filename);
	double loftAng1() const;
	double loftAng2() const;
	double loftMag1() const;
	double loftMag2() const;
	uint8_t loftNormals() const;
	uint16_t loftParam() const;
	double longitude() const;
	double ltscale() const;
	int16_t lunits() const;
	int16_t luprec() const;
	ACDBCORE2D_PORT AcDbObjectId mLStyleDictionaryId() const;
	AcDb::MaintenanceReleaseVersion maintenanceReleaseVersion() const
	{
		return AcDb::kMReleaseCurrent;
	}
	static Acad::ErrorStatus markObjectNonPersistent(AcDbObjectId id, bool value);
	ACDBCORE2D_PORT AcDbObjectId materialDictionaryId() const;
	int16_t maxactvp() const;
	AcDb::MeasurementValue measurement() const;
	bool mirrtext() const;
	AcDbObjectId mleaderStyleDictionaryId() const;
	double mleaderscale() const;
	AcDbObjectId mleaderstyle() const;
	double msOleScale() const;
	bool msltscale() const;
	ACDBCORE2D_PORT AcDbObjectId namedObjectsDictionaryId() const;
	ACDBCORE2D_PORT bool needsRecovery() const;
	double northDirection() const;
	int32_t numberOfSaves() const;
	AcDbObjectContextManager* objectContextManager() const;
	uint16_t obscuredColor() const;
	uint8_t obscuredLineType() const;
	bool oleStartUp() const;
	AcDb::MaintenanceReleaseVersion originalFileMaintenanceVersion() const;
	const ACHAR* originalFileName() const;
	AcDb::MaintenanceReleaseVersion originalFileSavedByMaintenanceVersion() const;
	AcDb::AcDbDwgVersion originalFileSavedByVersion() const;
	AcDb::AcDbDwgVersion originalFileVersion() const;
	bool orthomode() const;
	AcDbObjectId paperSpaceVportId() const;
	int16_t pdmode() const;
	int8_t pdfframe() const;
	double pdsize() const;
	double pelevation() const;
	AcGePoint3d pextmax() const;
	AcGePoint3d pextmin() const;
	int16_t pickstyle() const;
	AcGePoint3d pinsbase() const;
	bool plimcheck() const;
	AcGePoint2d plimmax() const;
	AcGePoint2d plimmin() const;
	bool plineEllipse() const;
	bool plinegen() const;
	double plinewid() const;
	ACDBCORE2D_PORT AcDbObjectId plotSettingsDictionaryId() const;
	bool plotStyleMode() const;
	ACDBCORE2D_PORT AcDbObjectId plotStyleNameDictionaryId() const;
	int16_t previewType() const;
	bool psltscale() const;
	double psolHeight() const;
	double psolWidth() const;
	AcDbObjectId pucsBase() const;
	AcDbObjectId pucsname() const;
	AcGePoint3d pucsorg() const;
	ACDBCORE2D_PORT AcGeVector3d pucsxdir() const;
	ACDBCORE2D_PORT AcGeVector3d pucsydir() const;
	Acad::ErrorStatus purge(AcDbObjectIdArray& ids);
	Acad::ErrorStatus purge(AcDbObjectIdGraph& idGraph);
	bool qtextmode() const;
	ACDBCORE2D_PORT Acad::ErrorStatus readDwgFile(const ACHAR* fileName,
												  OpenMode shmode = kForReadAndReadShare,
												  bool bAllowCPConversion = false,
												  const wchar_t* wszPassword = nullptr);
	ACDBCORE2D_PORT Acad::ErrorStatus readDwgFile(AcDwgFileHandle* pDwgFile,
												  bool bAllowCPConversion = false,
												  const wchar_t* wszPassword = nullptr);
	bool realWorldScale() const;
	Acad::ErrorStatus reclaimMemoryFromErasedObjects(const AcDbObjectIdArray& erasedObjects);
	ACDBCORE2D_PORT AcDbObjectId regAppTableId() const;
	bool regenmode() const;
	ACDBCORE2D_PORT Acad::ErrorStatus removeReactor(AcDbDatabaseReactor* pReactor) const;
	Acad::ErrorStatus resetTimes();
	Acad::ErrorStatus restoreForwardingXrefSymbols();
	Acad::ErrorStatus restoreOriginalXrefSymbols();
	bool retainOriginalThumbnailBitmap() const;
	Acad::ErrorStatus save();
	inline Acad::ErrorStatus saveAs(const ACHAR* fileName, const SecurityParams* pSecParams = 0)
	{
		return saveAs(fileName, true, AcDb::kDHL_CURRENT, pSecParams);
	}
	ACDBCORE2D_PORT Acad::ErrorStatus saveAs(const ACHAR* fileName, const bool bBakAndRename,
											 const AcDb::AcDbDwgVersion dwgVer = AcDb::kDHL_CURRENT,
											 const SecurityParams* pSecParams = 0);
	ACDBCORE2D_PORT Acad::ErrorStatus saveAs(AcDwgFileHandle* pOutputFiler,
											 const SecurityParams* pSecParams = 0,
											 bool crashing = false);
	int16_t saveproxygraphics() const;
	ACDBCORE2D_PORT AcDbObjectId scaleListDictionaryId() const;
	ACDBCORE2D_PORT AcDbObjectId sectionViewStyle() const;
	ACDBCORE2D_PORT AcDbObjectId sectionViewStyleDictionaryId() const;
	Acad::ErrorStatus set3dDwfPrec(double DwfPrec);
	Acad::ErrorStatus setAngbase(double angle);
	Acad::ErrorStatus setAngdir(bool dir);
	Acad::ErrorStatus setAnnoAllVisible(bool allvis);
	Acad::ErrorStatus setAnnotativeDwg(bool anno);
	Acad::ErrorStatus setAttdia(bool dia);
	Acad::ErrorStatus setAttmode(int16_t mode);
	Acad::ErrorStatus setAttreq(bool req);
	Acad::ErrorStatus setAunits(int16_t aunits);
	Acad::ErrorStatus setAuprec(int16_t auprec);
	Acad::ErrorStatus setBlipmode(bool mode);
	Acad::ErrorStatus setCDynDisplayMode(int16_t val);
	Acad::ErrorStatus setCameraDisplay(const bool cameraDisplay);
	Acad::ErrorStatus setCameraHeight(const double cameraHeight);
	Acad::ErrorStatus setCannoscale(AcDbAnnotationScale*);
	Acad::ErrorStatus setCePlotStyleName(AcDb::PlotStyleNameType,
										 AcDbObjectId newId = AcDbObjectId::kNull);
	Acad::ErrorStatus setCecolor(const AcCmColor& color);
	Acad::ErrorStatus setCeltscale(double scale);
	Acad::ErrorStatus setCeltype(AcDbObjectId objId);
	Acad::ErrorStatus setCelweight(AcDb::LineWeight weight);
	Acad::ErrorStatus setCetransparency(const AcCmTransparency& transparency);
	Acad::ErrorStatus setChamfera(double val);
	Acad::ErrorStatus setChamferb(double val);
	Acad::ErrorStatus setChamferc(double val);
	Acad::ErrorStatus setChamferd(double val);
	ACDBCORE2D_PORT Acad::ErrorStatus setClayer(AcDbObjectId objId);
	Acad::ErrorStatus setCmaterial(AcDbObjectId objId);
	Acad::ErrorStatus setCmljust(int16_t just);
	Acad::ErrorStatus setCmlscale(double scale);
	Acad::ErrorStatus setCmlstyleID(AcDbObjectId objId);
	Acad::ErrorStatus setCoords(int16_t coords);
	Acad::ErrorStatus setCshadow(uint8_t val);
	Acad::ErrorStatus setDelUsedObj(int16_t deleteObj);
	ACDBCORE2D_PORT Acad::ErrorStatus setDetailViewStyle(AcDbObjectId objId);
	Acad::ErrorStatus setDgnframe(uint8_t);
	Acad::ErrorStatus setDimAssoc(uint8_t val);
	Acad::ErrorStatus setDimaso(bool aso);
	Acad::ErrorStatus setDimfit(int fit);
	Acad::ErrorStatus setDimsho(bool sho);
	Acad::ErrorStatus setDimstyle(AcDbObjectId styleId);
	Acad::ErrorStatus setDimstyleData(AcDbDimStyleTableRecord* pRec);
	Acad::ErrorStatus setDimstyleData(AcDbObjectId id);
	Acad::ErrorStatus setDimunit(int unit);
	Acad::ErrorStatus setDispSilh(bool silh);
	Acad::ErrorStatus setDragVisStyle(AcDbObjectId id);
	Acad::ErrorStatus setDragmode(int16_t mode);
	Acad::ErrorStatus setDrawOrderCtl(uint8_t val);
	Acad::ErrorStatus setDwfframe(uint8_t);
	Acad::ErrorStatus setDxeVal(int16_t val);
	Acad::ErrorStatus setElevation(double elev);
	Acad::ErrorStatus setEndCaps(AcDb::EndCaps type);
	Acad::ErrorStatus setExtmax(const AcGePoint3d& max);
	Acad::ErrorStatus setExtmin(const AcGePoint3d& min);
	ACDBCORE2D_PORT Acad::ErrorStatus setFacetres(double facetres);
	Acad::ErrorStatus setFilletrad(double radius);
	Acad::ErrorStatus setFillmode(bool mode);
	Acad::ErrorStatus setFingerprintGuid(const ACHAR* pNewGuid);
	ACDBCORE2D_PORT void setFullSaveRequired();
	Acad::ErrorStatus setGeoMarkerVisibility(bool value);
	Acad::ErrorStatus setHaloGap(uint8_t val);
	Acad::ErrorStatus setHandseed(const AcDbHandle& handle);
	Acad::ErrorStatus setHideText(uint8_t val);
	Acad::ErrorStatus setHpInherit(const bool inherit);
	Acad::ErrorStatus setHpOrigin(const AcGePoint2d& origin);
	Acad::ErrorStatus setHyperlinkBase(const ACHAR*);
	Acad::ErrorStatus setIndexctl(uint8_t val);
	Acad::ErrorStatus setInsbase(const AcGePoint3d& base);
	Acad::ErrorStatus setInsunits(const AcDb::UnitsValue units);
	Acad::ErrorStatus setInterfereColor(const AcCmColor& color);
	Acad::ErrorStatus setInterfereObjVisStyle(AcDbObjectId id);
	Acad::ErrorStatus setInterfereVpVisStyle(AcDbObjectId id);
	Acad::ErrorStatus setIntersectColor(uint16_t val);
	Acad::ErrorStatus setIntersectDisplay(uint8_t val);
	Acad::ErrorStatus setIsolines(int16_t isolines);
	Acad::ErrorStatus setJoinStyle(AcDb::JoinStyle style);
	Acad::ErrorStatus setLatitude(double lat);
	Acad::ErrorStatus setLayerEval(uint8_t val);
	Acad::ErrorStatus setLayerNotify(int16_t val);
	Acad::ErrorStatus setLensLength(const double lensLength);
	Acad::ErrorStatus setLightGlyphDisplay(uint8_t val);
	Acad::ErrorStatus setLightingUnits(uint8_t val);
	Acad::ErrorStatus setLightsInBlocks(bool val);
	Acad::ErrorStatus setLimcheck(bool check);
	Acad::ErrorStatus setLimmax(const AcGePoint2d& max);
	Acad::ErrorStatus setLimmin(const AcGePoint2d& min);
	Acad::ErrorStatus setLineWeightDisplay(bool display);
	Acad::ErrorStatus setLoftAng1(double ang1);
	Acad::ErrorStatus setLoftAng2(double ang2);
	Acad::ErrorStatus setLoftMag1(double mag1);
	Acad::ErrorStatus setLoftMag2(double mag2);
	Acad::ErrorStatus setLoftNormals(uint8_t value);
	Acad::ErrorStatus setLoftParam(uint16_t flags);
	Acad::ErrorStatus setLongitude(double lng);
	Acad::ErrorStatus setLtscale(double scale);
	Acad::ErrorStatus setLunits(int16_t lunits);
	Acad::ErrorStatus setLuprec(int16_t prec);
	Acad::ErrorStatus setMLeaderscale(double scale);
	Acad::ErrorStatus setMLeaderstyle(AcDbObjectId objId);
	Acad::ErrorStatus setMaxactvp(int16_t max);
	Acad::ErrorStatus setMeasurement(AcDb::MeasurementValue type);
	Acad::ErrorStatus setMirrtext(bool mirror);
	Acad::ErrorStatus setMsOleScale(double val);
	Acad::ErrorStatus setMsltscale(bool val);
	Acad::ErrorStatus setNorthDirection(double northdir);
	Acad::ErrorStatus setObscuredColor(uint16_t val);
	Acad::ErrorStatus setObscuredLineType(uint8_t val);
	Acad::ErrorStatus setOleStartUp(bool val);
	Acad::ErrorStatus setOrthomode(bool mode);
	Acad::ErrorStatus setPdfframe(int8_t val);
	Acad::ErrorStatus setPdmode(int16_t mode);
	Acad::ErrorStatus setPdsize(double size);
	Acad::ErrorStatus setPelevation(double elev);
	Acad::ErrorStatus setPextmax(const AcGePoint3d& max);
	Acad::ErrorStatus setPextmin(const AcGePoint3d& min);
	Acad::ErrorStatus setPickstyle(int16_t style);
	Acad::ErrorStatus setPinsbase(const AcGePoint3d& base);
	Acad::ErrorStatus setPlimcheck(bool check);
	Acad::ErrorStatus setPlimmax(const AcGePoint2d& max);
	Acad::ErrorStatus setPlimmin(const AcGePoint2d& min);
	Acad::ErrorStatus setPlineEllipse(bool pline);
	Acad::ErrorStatus setPlinegen(bool gen);
	Acad::ErrorStatus setPlinewid(double width);
	Acad::ErrorStatus setPreviewType(int16_t val);
	Acad::ErrorStatus setProjectName(const ACHAR*);
	Acad::ErrorStatus setPsltscale(bool scale);
	Acad::ErrorStatus setPsolHeight(double height);
	Acad::ErrorStatus setPsolWidth(double width);
	ACDBCORE2D_PORT Acad::ErrorStatus setPucs(const AcGePoint3d& ucsOrigin,
											  const AcGeVector3d& ucsXDir,
											  const AcGeVector3d& ucsYDir);
	Acad::ErrorStatus setPucsBase(const AcDbObjectId& ucsid);
	ACDBCORE2D_PORT Acad::ErrorStatus setPucsname(const AcDbObjectId& ucsRecId);
	Acad::ErrorStatus setQtextmode(bool mode);
	Acad::ErrorStatus setRealWorldScale(const bool realWorldScale);
	Acad::ErrorStatus setRegenmode(bool mode);
	void setRetainOriginalThumbnailBitmap(bool retain);
	Acad::ErrorStatus setSaveproxygraphics(int16_t saveimg);
	ACDBCORE2D_PORT Acad::ErrorStatus setSectionViewStyle(AcDbObjectId objId);
	bool setSecurityParams(const SecurityParams* pSecParams, bool bSetDbMod = true);
	Acad::ErrorStatus setShadedif(int16_t dif);
	Acad::ErrorStatus setShadedge(int16_t mode);
	Acad::ErrorStatus setShadowPlaneLocation(double val);
	Acad::ErrorStatus setShowHist(uint8_t val);
	Acad::ErrorStatus setSketchinc(double inc);
	Acad::ErrorStatus setSkpoly(bool asPoly);
	Acad::ErrorStatus setSolidHist(uint8_t val);
	Acad::ErrorStatus setSortEnts(uint8_t sortEnts);
	Acad::ErrorStatus setSplframe(bool disp);
	Acad::ErrorStatus setSplinesegs(int16_t segs);
	Acad::ErrorStatus setSplinetype(int16_t type);
	Acad::ErrorStatus setStepSize(double stepSize);
	Acad::ErrorStatus setStepsPerSec(double stepsPerSec);
	Acad::ErrorStatus setStyleSheet(const ACHAR*);
	Acad::ErrorStatus setSurftab1(int16_t tab1);
	Acad::ErrorStatus setSurftab2(int16_t tab2);
	Acad::ErrorStatus setSurftype(int16_t type);
	Acad::ErrorStatus setSurfu(int16_t u);
	Acad::ErrorStatus setSurfv(int16_t v);
	Acad::ErrorStatus setTStackAlign(int val);
	Acad::ErrorStatus setTStackSize(int val);
	Acad::ErrorStatus setTablestyle(AcDbObjectId objId);
	Acad::ErrorStatus setTextsize(double size);
	Acad::ErrorStatus setTextstyle(AcDbObjectId objId);
	Acad::ErrorStatus setThickness(double thickness);
	Acad::ErrorStatus setThumbnailBitmap(void* pBmp);
	Acad::ErrorStatus setThumbnailImage(const Atil::Image* pPreviewImage);
	Acad::ErrorStatus setTileModeLightSynch(uint8_t val);
	Acad::ErrorStatus setTilemode(bool mode);
	Acad::ErrorStatus setTimeZone(AcDb::TimeZone tz);
	Acad::ErrorStatus setTimeZoneAsUtcOffset(double offset);
	Acad::ErrorStatus setTracewid(double width);
	Acad::ErrorStatus setTreedepth(int16_t depth);
	ACDBCORE2D_PORT Acad::ErrorStatus setUcs(const AcGePoint3d& ucsOrigin,
											 const AcGeVector3d& ucsXDir,
											 const AcGeVector3d& ucsYDir);
	Acad::ErrorStatus setUcsBase(AcDbObjectId ucsid);
	ACDBCORE2D_PORT Acad::ErrorStatus setUcsname(const AcDbObjectId& ucsRecId);
	Acad::ErrorStatus setUnitmode(int16_t mode);
	Acad::ErrorStatus setUpdateThumbnail(uint8_t val);
	Acad::ErrorStatus setUseri1(int16_t val);
	Acad::ErrorStatus setUseri2(int16_t val);
	Acad::ErrorStatus setUseri3(int16_t val);
	Acad::ErrorStatus setUseri4(int16_t val);
	Acad::ErrorStatus setUseri5(int16_t val);
	Acad::ErrorStatus setUserr1(double val);
	Acad::ErrorStatus setUserr2(double val);
	Acad::ErrorStatus setUserr3(double val);
	Acad::ErrorStatus setUserr4(double val);
	Acad::ErrorStatus setUserr5(double val);
	Acad::ErrorStatus setUsrtimer(bool timer);
	Acad::ErrorStatus setVersionGuid(const ACHAR* pNewGuid);
	Acad::ErrorStatus setViewportScaleDefault(double newDefaultVPScale);
	Acad::ErrorStatus setVisretain(bool retain);
	Acad::ErrorStatus setWorldPucsBaseOrigin(const AcGePoint3d& origin,
											 AcDb::OrthographicView orthoView);
	Acad::ErrorStatus setWorldUcsBaseOrigin(const AcGePoint3d& origin,
											AcDb::OrthographicView orthoView);
	Acad::ErrorStatus setWorldview(bool view);
	Acad::ErrorStatus setXclipFrame(uint8_t disp);
	Acad::ErrorStatus setXrefEditEnabled(bool enable);
	int16_t shadedge() const;
	int16_t shadedif() const;
	double shadowPlaneLocation() const;
	uint8_t showHist() const;
	double sketchinc() const;
	bool skpoly() const;
	uint8_t solidHist() const;
	uint8_t sortEnts() const;
	ACDBCORE2D_PORT bool splframe() const;
	int16_t splinesegs() const;
	int16_t splinetype() const;
	double stepSize() const;
	double stepsPerSec() const;
	int16_t surftab1() const;
	int16_t surftab2() const;
	int16_t surftype() const;
	int16_t surfu() const;
	int16_t surfv() const;
	AcDbObjectId tableStyleDictionaryId() const;
	AcDbObjectId tablestyle() const;
	const AcDbDate tdcreate() const;
	const AcDbDate tdindwg() const;
	const AcDbDate tducreate() const;
	const AcDbDate tdupdate() const;
	const AcDbDate tdusrtimer() const;
	const AcDbDate tduupdate() const;
	ACDBCORE2D_PORT AcDbObjectId textStyleTableId() const;
	double textsize() const;
	AcDbObjectId textstyle() const;
	double thickness() const;
	void* thumbnailBitmap() const;
	Acad::ErrorStatus thumbnailImage(Atil::Image*& pPreviewImage) const;
	uint8_t tileModeLightSynch() const;
	ACDBCORE2D_PORT bool tilemode() const;
	AcDb::TimeZone timeZone() const;
	double tracewid() const;
	AcDbTransactionManager* transactionManager() const;
	int16_t treedepth() const;
	int tstackalign() const;
	int tstacksize() const;
	AcDbObjectId ucsBase() const;
	AcDbObjectId ucsname() const;
	AcGePoint3d ucsorg() const;
	ACDBCORE2D_PORT AcGeVector3d ucsxdir() const;
	ACDBCORE2D_PORT AcGeVector3d ucsydir() const;
	AcDbUndoController* undoController() const;
	bool undoRecording() const;
	int16_t unitmode() const;
	Acad::ErrorStatus updateDataLink(AcDb::UpdateDirection nDir, AcDb::UpdateOption nOption);
	Acad::ErrorStatus updateExt(bool doBestFit = false);
	uint8_t updateThumbnail() const;
	int16_t useri1() const;
	int16_t useri2() const;
	int16_t useri3() const;
	int16_t useri4() const;
	int16_t useri5() const;
	double userr1() const;
	double userr2() const;
	double userr3() const;
	double userr4() const;
	double userr5() const;
	bool usrtimer() const;
	ACDBCORE2D_PORT AcDbObjectId viewTableId() const;
	double viewportScaleDefault() const;
	ACDBCORE2D_PORT AcDbObjectId viewportTableId() const;
	bool visretain() const;
	ACDBCORE2D_PORT AcDbObjectId visualStyleDictionaryId() const;
	Acad::ErrorStatus wblock(AcDbDatabase*& pOutputDb, const AcDbObjectIdArray& outObjIds,
							 const AcGePoint3d& basePoint);

	Acad::ErrorStatus wblock(AcDbDatabase* pOutputDb, const AcDbObjectIdArray& outObjIds,
							 const AcGePoint3d& basePoint, AcDb::DuplicateRecordCloning drc);
	Acad::ErrorStatus wblock(AcDbDatabase*& pOutputDb, AcDbObjectId blockId);
	Acad::ErrorStatus wblock(AcDbDatabase*& pOutputDb);
	ACDBCORE2D_PORT Acad::ErrorStatus wblockCloneObjects(const AcDbObjectIdArray& objectIds,
														 const AcDbObjectId& owner,
														 AcDbIdMapping& idMap,
														 AcDb::DuplicateRecordCloning drc,
														 bool deferXlation = false);
	AcGePoint3d worldPucsBaseOrigin(AcDb::OrthographicView orthoView) const;
	AcGePoint3d worldUcsBaseOrigin(AcDb::OrthographicView orthoView) const;
	bool worldview() const;
	uint8_t xclipFrame() const;
	AcDbObjectId xrefBlockId() const;
	bool xrefEditEnabled() const;
};

#include "IcArxPackPop.h"

inline Acad::ErrorStatus AcDbDatabase::getBlockTable(AcDbBlockTable*& pTable, AcDb::OpenMode mode)
{
	return getSymbolTable(pTable, mode);
}

inline Acad::ErrorStatus AcDbDatabase::getDimStyleTable(AcDbDimStyleTable*& pTable,
														AcDb::OpenMode mode)
{
	return getSymbolTable(pTable, mode);
}

inline Acad::ErrorStatus AcDbDatabase::getDimapost(ACHAR*& pOutput) const
{
	return ::acutNewString(this->dimapost(), pOutput);
}

inline Acad::ErrorStatus AcDbDatabase::getDimblk(ACHAR*& pOutput) const
{
	return ::acutGetAcStringConvertToAChar(this, &AcDbDatabase::getDimblk, pOutput);
}

inline Acad::ErrorStatus AcDbDatabase::getDimblk1(ACHAR*& pOutput) const
{
	return ::acutGetAcStringConvertToAChar(this, &AcDbDatabase::getDimblk1, pOutput);
}

inline Acad::ErrorStatus AcDbDatabase::getDimblk2(ACHAR*& pOutput) const
{
	return ::acutGetAcStringConvertToAChar(this, &AcDbDatabase::getDimblk2, pOutput);
}

inline Acad::ErrorStatus AcDbDatabase::getDimpost(ACHAR*& pOutput) const
{
	return ::acutNewString(this->dimpost(), pOutput);
}

inline Acad::ErrorStatus AcDbDatabase::getFingerprintGuid(ACHAR*& pOutput) const
{
	return ::acutGetAcStringConvertToAChar(this, &AcDbDatabase::getFingerprintGuid, pOutput);
}

inline Acad::ErrorStatus AcDbDatabase::getHyperlinkBase(ACHAR*& pOutput) const
{
	return ::acutGetAcStringConvertToAChar(this, &AcDbDatabase::getHyperlinkBase, pOutput);
}

inline Acad::ErrorStatus AcDbDatabase::getLayerTable(AcDbLayerTable*& pTable, AcDb::OpenMode mode)
{
	return getSymbolTable(pTable, mode);
}

inline Acad::ErrorStatus AcDbDatabase::getLinetypeTable(AcDbLinetypeTable*& pTable,
														AcDb::OpenMode mode)
{
	return getSymbolTable(pTable, mode);
}

inline Acad::ErrorStatus AcDbDatabase::getMenu(ACHAR*& pOutput) const
{
	return ::acutGetAcStringConvertToAChar(this, &AcDbDatabase::getMenu, pOutput);
}

inline Acad::ErrorStatus AcDbDatabase::getProjectName(ACHAR*& pOutput) const
{
	return ::acutGetAcStringConvertToAChar(this, &AcDbDatabase::getProjectName, pOutput);
}

inline Acad::ErrorStatus AcDbDatabase::getRegAppTable(AcDbRegAppTable*& pTable, AcDb::OpenMode mode)
{
	return getSymbolTable(pTable, mode);
}

inline Acad::ErrorStatus AcDbDatabase::getStyleSheet(ACHAR*& pOutput) const
{
	return ::acutGetAcStringConvertToAChar(this, &AcDbDatabase::getStyleSheet, pOutput);
}

template<>
inline AcDbObjectId AcDbDatabase::getSymbolTableId<AcDbBlockTable>() const
{
	return this->blockTableId();
}

template<>
inline AcDbObjectId AcDbDatabase::getSymbolTableId<AcDbDimStyleTable>() const
{
	return this->dimStyleTableId();
}

template<>
inline AcDbObjectId AcDbDatabase::getSymbolTableId<AcDbLayerTable>() const
{
	return this->layerTableId();
}

template<>
inline AcDbObjectId AcDbDatabase::getSymbolTableId<AcDbLinetypeTable>() const
{
	return this->linetypeTableId();
}

template<>
inline AcDbObjectId AcDbDatabase::getSymbolTableId<AcDbRegAppTable>() const
{
	return this->regAppTableId();
}

template<>
inline AcDbObjectId AcDbDatabase::getSymbolTableId<AcDbTextStyleTable>() const
{
	return this->textStyleTableId();
}

template<>
inline AcDbObjectId AcDbDatabase::getSymbolTableId<AcDbUCSTable>() const
{
	return this->UCSTableId();
}

template<>
inline AcDbObjectId AcDbDatabase::getSymbolTableId<AcDbViewTable>() const
{
	return this->viewTableId();
}

template<>
inline AcDbObjectId AcDbDatabase::getSymbolTableId<AcDbViewportTable>() const
{
	return this->viewportTableId();
}

inline Acad::ErrorStatus AcDbDatabase::getTextStyleTable(AcDbTextStyleTable*& pTable,
														 AcDb::OpenMode mode)
{
	return getSymbolTable(pTable, mode);
}

inline Acad::ErrorStatus AcDbDatabase::getUCSTable(AcDbUCSTable*& pTable, AcDb::OpenMode mode)
{
	return getSymbolTable(pTable, mode);
}

inline Acad::ErrorStatus AcDbDatabase::getVersionGuid(ACHAR*& pOutput) const
{
	return ::acutGetAcStringConvertToAChar(this, &AcDbDatabase::getVersionGuid, pOutput);
}

inline Acad::ErrorStatus AcDbDatabase::getViewTable(AcDbViewTable*& pTable, AcDb::OpenMode mode)
{
	return getSymbolTable(pTable, mode);
}

inline Acad::ErrorStatus AcDbDatabase::getViewportTable(AcDbViewportTable*& pTable,
														AcDb::OpenMode mode)
{
	return getSymbolTable(pTable, mode);
}

inline Acad::ErrorStatus acdbDxfOutAs2000(AcDbDatabase* pDb, const ACHAR* fileName,
										  const int precision = 16)
{
	return pDb->dxfOut(fileName, precision, AcDb::kDHL_1015);
}

inline Acad::ErrorStatus acdbDxfOutAs2004(AcDbDatabase* pDb, const ACHAR* fileName,
										  const int precision = 16)
{
	return pDb->dxfOut(fileName, precision, AcDb::kDHL_1800);
}

inline Acad::ErrorStatus acdbDxfOutAsR12(AcDbDatabase* pDb, const ACHAR* fileName,
										 const int precision = 16)
{
	return pDb->dxfOut(fileName, precision, AcDb::kDHL_1009);
}

inline Acad::ErrorStatus acdbSaveAs2000(AcDbDatabase* pDb, const ACHAR* fileName)
{
	return pDb->saveAs(fileName, false, AcDb::kDHL_1015);
}

inline Acad::ErrorStatus acdbSaveAs2004(AcDbDatabase* pDb, const ACHAR* fileName)
{
	return pDb->saveAs(fileName, false, AcDb::kDHL_1800);
}

inline Acad::ErrorStatus acdbSaveAsR14(AcDbDatabase* pDb, const ACHAR* fileName)
{
	return pDb->saveAs(fileName, false, AcDb::kDHL_1014);
}

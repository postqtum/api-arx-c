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

#include "adesk.h"
#include "acadapidef.h"
#include "rxevent.h"
#include "rxsrvice.h"
#include "ads.h"
#include "acutmem.h"

#include "icarx/AcEdUpdateDisplayPauseScope.h"
#include "icarx/AcEdSysVarIterator.h"
#include "icarx/AcEdUIContext.h"
#include "icarx/AcEditor.h"
#include "icarx/AcEditorReactor.h"
#include "icarx/AcEdServices.h"

#include "icarx/IcArxPackPush.h"

struct IDispatch;
class AcEdSelectionSetService;

enum AcadContextMenuMode
{
	kDefault = 0,
	kEdit,
	kCommand,
	kHotGrip,
	kOsnap,
};

#include "aced-xref.h"

enum undoSubcommandActivities
{
	kNone = 0,
	kOne = 1,
	kAll = 2
};

#include "icarx/IcArxPackPop.h"
#include "accmd.h"
#include "icarx/IcArxPackPush.h"

struct AcEdCommandStruc;
class AcString;
class AcGiImageBGRA32;
class AcDbViewport;
class AcDbViewTableRecord;

ACAD_PORT bool acedCmdLookup2(const ACHAR* cmdStr, bool globalLookup, AcEdCommandStruc* retStruc,
							  int sf = ACRX_CMD_DEFUN);

inline bool acedCmdLookup(const ACHAR* cmdStr, bool globalLookup, AcEdCommandStruc* retStruc,
						  bool skipUndef = false)
{
	return ::acedCmdLookup2(cmdStr, globalLookup, retStruc,
							skipUndef ? (ACRX_CMD_DEFUN | ACRX_CMD_UNDEFINED) : ACRX_CMD_DEFUN);
}

ACAD_PORT int acedCmdUndefine(const ACHAR* cmdStr, int undefIt);

ACAD_PORT int acedPopCommandDirectory(const ACHAR* cmdDirName);

class AcApDocument;
ACAD_PORT Acad::ErrorStatus acedGetCommandForDocument(const AcApDocument* pDoc, AcString& sCmdName,
													  bool bLocalized = false);

inline Acad::ErrorStatus acedGetCommandForDocument(const AcApDocument* pDoc, ACHAR*& pGlobalCmdName)
{
	pGlobalCmdName = nullptr;
	AcString sOutput;
	const Acad::ErrorStatus es = acedGetCommandForDocument(pDoc, sOutput, false);
	if (es == Acad::eOk)
		::acutNewString(sOutput.kwszPtr(), pGlobalCmdName);
	return es;
}

ACAD_PORT bool acedSetOLELock(int handle, int flags = 0);

ACAD_PORT bool acedClearOLELock(int handle);

ACAD_PORT void acedPostCommandPrompt();

Acad::ErrorStatus acedSyncFileOpen(const ACHAR* pszFileToOpen, const wchar_t* wszPassword = nullptr);

bool acedSetColorDialog(int& nColor, bool bAllowMetaColor, int nCurLayerColor);

bool acedSetColorDialogTrueColor(
		AcCmColor& color, bool bAllowMetaColor, const AcCmColor& curLayerColor,
		AcCm::DialogTabs tabs = (AcCm::DialogTabs)(AcCm::kACITab | AcCm::kTrueColorTab |
												   AcCm::kColorBookTab));

typedef void(ADESK_STDCALL* AcEdColorDialogCallbackFunction)(void* pCallbackData,
															 const AcCmColor& newColor);

ACAD_PORT bool acedSetColorDialogTrueColorWithCallback(
		AcCmColor& color, bool bAllowMetaColor, const AcCmColor& curLayerColor,
		AcCm::DialogTabs tabs = (AcCm::DialogTabs)(AcCm::kACITab | AcCm::kTrueColorTab |
												   AcCm::kColorBookTab),
		AcEdColorDialogCallbackFunction callback = nullptr, void* pCallbackData = nullptr);

ACAD_PORT bool acedSetColorPrompt(const ACHAR* promptString, AcCmColor& color,
								  bool bAllowMetaColor);

bool acedIsMenuGroupLoaded(const ACHAR* pszGroupName);

bool acedLoadPartialMenu(const wchar_t* pszMenuFile);

bool acedUnloadPartialMenu(const wchar_t* pszMenuFile);

void acedReloadMenus(bool bIncrementalReloading);

void acedSendModelessOperationStart(const ACHAR* strContext);
void acedSendModelessOperationEnded(const ACHAR* strContext);

void acedUpdateDisplay();

ACAD_PORT void acedUpdateDisplayPause(bool bEnable);

ACAD_PORT bool acedIsUpdateDisplayPaused(void);

bool acedInitDialog(bool useDialog = true);

uint8_t acedInitCommandVersion(uint8_t nVersion = 0);

uint8_t acedGetCommandVersion();

void acedDisableDefaultARXExceptionHandler(bool disable = true);

Acad::ErrorStatus acedVportTableRecords2Vports();

Acad::ErrorStatus acedVports2VportTableRecords();

Acad::ErrorStatus acedVPLayer(const AcDbObjectId& vpId, const AcDbObjectIdArray& layerIds,
							  AcDb::VpFreezeOps operation);

#define acedServices AcEdServices::cast(acrxServiceDictionary->at(ACED_SERVICES))

#define AcEditorReactor2 AcEditorReactor
#define AcEditorReactor3 AcEditorReactor

#define acedEditor AcEditor::cast(acrxSysRegistry()->at(ACED_EDITOR_OBJ))

bool acedSetCMBaseAlias(const wchar_t* strAlias, AcadContextMenuMode mode);
const wchar_t* acedGetCMBaseAlias(AcadContextMenuMode mode);

Acad::ErrorStatus acedMspace();
Acad::ErrorStatus acedPspace();
Acad::ErrorStatus acedSetCurrentVPort(int vpnumber);
Acad::ErrorStatus acedSetCurrentVPort(const AcDbViewport* pVp);

int acedIsDragging(void);

Acad::ErrorStatus acedSetCurrentView(AcDbViewTableRecord* pVwRec, AcDbViewport* pVP);

Acad::ErrorStatus acedRestoreCurrentView(const AcDbObjectId& namedViewId);

short acedGetCurVportCircleSides();
Acad::ErrorStatus acedSetCurVportCircleSides(short value);

void acedGetCurVportPixelToDisplay(double& xFactor, double& yFactor);
void acedGetCurVportScreenToDisplay(double& xFactor, double& yFactor);

Acad::ErrorStatus acedSetCurrentUCS(const AcGeMatrix3d& mat);
Acad::ErrorStatus acedGetCurrentUCS(AcGeMatrix3d& mat);
Acad::ErrorStatus acedRestorePreviousUCS();

class AcDbFcf;
class AcDbMText;

void acedEditToleranceInteractive(AcDbFcf* pTol);

int acedEditMTextInteractive(AcDbMText* pMText, bool useNewUI = false, bool allowTabs = false);

enum DimstyleTabSuppressed
{
	kSymbolsArrowsTabSuppressed = 0x01,
	kTextTabSuppressed = 0x02,
	kFitTabSuppressed = 0x04,
	kPrimaryTabSuppressed = 0x08,
	kAlternateTabSuppressed = 0x10,
	kToleranceTabSuppressed = 0x20
};

int acedEditDimstyleInteractiveEx(AcDbDatabase* pDb, AcDbDimStyleTableRecord* pRec, int familyType,
								  const ACHAR* title = nullptr, int tabCtrlFlags = 0);

ACAD_PORT IcArx::Integers::ColorRef acedGetRGB(int color);

Acad::ErrorStatus acedGetCurrentSelectionSet(AcDbObjectIdArray& sset);

Acad::ErrorStatus acedGetFullSubentPathsForCurrentSelection(
		const AcDbObjectId& selectedObject, AcDbFullSubentPathArray& selectedSubentities);

class AcDbHatch;
class AcDbEntity;

extern "C" IDispatch* AcadGetIDispatch(bool bAddRef);
#define acedGetIDispatch AcadGetIDispatch

AcDbObjectId acedActiveViewportId();

AcDbObjectId acedViewportIdFromNumber(int nVpNum);

int acedNumberOfViewports();

AcDbObjectId acedGetCurViewportObjectId();

Acad::ErrorStatus acedConvertEntityToHatch(AcDbHatch* pHatch, AcDbEntity*& pEnt, bool transferId);


#include "aced-hatch.h"

Acad::ErrorStatus acedManageHatchEditorReactor(AcDbObjectId hatchId, AcHatchEdReact action,
											   AcDbObjectId boundaryId = AcDbObjectId::kNull,
											   AcHatchNotifier notifyType = kNobody,
											   bool transformed = false);


enum AcEdDrawOrderCmdType
{
	kDrawOrderNone = 0,
	kDrawOrderBottom,
	kDrawOrderTop,
	kDrawOrderBelow,
	kDrawOrderAbove
};


Acad::ErrorStatus acedDrawOrderInherit(AcDbObjectId parent, AcDbObjectIdArray& childArray,
									   AcEdDrawOrderCmdType cmd);


Acad::ErrorStatus acedCreateViewportByView(AcDbDatabase* pDb, const AcDbObjectId& view,
										   const AcGePoint2d& location, double scale,
										   AcDbObjectId& viewportId);


ACAD_PORT Acad::ErrorStatus acedCreateEnhancedViewportOnDrop(
		const ACHAR* filename, const ACHAR* viewName, const AcGePoint2d& location, double scale,
		AcDbObjectId labelBlockId, AcDbObjectId& sheetViewId, AcDbObjectId& viewportId);


ACAD_PORT Acad::ErrorStatus acedCreateEnhancedViewportOnDropDWG(
		const ACHAR* filename, AcDbExtents* extents, const AcGePoint2d& location, double scale,
		AcDbObjectId labelBlockId, AcDbObjectId& sheetViewId, AcDbObjectId& viewportId);

ACAD_PORT Acad::ErrorStatus acedGetUnitsValueString(AcDb::UnitsValue units, AcString& sUnits);

inline const AcString* acedGetUnitsValueString(AcDb::UnitsValue units)
{
	static AcString sRetVal;
	::acedGetUnitsValueString(units, sRetVal);
	return &sRetVal;
}


bool acedGetUnitsConversion(AcDb::UnitsValue blkInsunits, double& conversionFactor);


bool acdbCanonicalToSystemRange(int eUnits, const AcString& strIn, AcString& strOut);


bool acdbSystemRangeToCanonical(int eUnits, const AcString& strIn, AcString& strOut);

void acedEnableUsrbrk();
void acedDisableUsrbrk();
bool acedIsUsrbrkDisabled();

bool acedIsInBackgroundMode();

enum BlockEditModeFlags
{
	kBlkEditModeNone = 0x0,
	kBlkEditModeActive = 0x01,
	kBlkEditModeOpen = 0x02,
	kBlkEditModeDirty = 0x04,
	kBlkEditModeBSaved = 0x08
};

unsigned int acedGetBlockEditMode();

void acedOpenDocWindowsMinimized(bool bMinimized);

bool acedCompareToCurrentViewport(const AcDbViewTableRecord* pVwRec);


uint32_t acedGetAnimationFrameId(void);


ACAD_PORT bool acedShowConstraintBar(AcDbFullSubentPathArray& subentPaths);


ACAD_PORT bool acedHideConstraintBar(AcDbFullSubentPathArray& subentPaths);


ACAD_PORT bool acedShowConstraintBarForAll(bool bToShow);


ACAD_PORT bool acedDisplayBorder(bool bShow);

Acad::ErrorStatus acedTraceBoundary(const AcGePoint3d& seedPoint, bool detectIslands,
									AcDbVoidPtrArray& resultingBoundarySet);

void acedSetDrawComplexShape(int val);
int acedGetDrawComplexShape();

void acedSetRecursingLinetypeVectorGeneration(int val);
int acedGetRecursingLinetypeVectorGeneration();

struct flagmat* acedGetComplexLineTypeTransformPtr();

ACAD_PORT Acad::ErrorStatus acedAudit(AcDbDatabase* pDb, bool bFixErrors, bool bCmdLnEcho = false);


ACCORE_PORT bool acedAddSupplementalCursorImage(const AcGiImageBGRA32* pSuppCursorImage,
												int priorityOrder = 0);


ACCORE_PORT bool acedRemoveSupplementalCursorImage(const AcGiImageBGRA32* pSuppCursorImage);


ACAD_PORT bool acedHasSupplementalCursorImage();


ACCORE_PORT void acedSetSupplementalCursorOffset(int x, int y);


ACAD_PORT void acedGetSupplementalCursorOffset(int& x, int& y);


ACCORE_PORT float acedGetDpiScalingValue();


ACAD_PORT bool acedScaleImageWithGDIPlus(const AcGiImageBGRA32* pSrcImg,
										 const AcGiImageBGRA32* pDstImg);


ACCORE_PORT void acedSetFieldUpdateEnabled(AcApDocument* pDoc, bool enabled);


ACCORE_PORT bool acedIsFieldUpdateEnabled(const AcApDocument* pDoc);


ACCORE_PORT bool acedGetFullSubentPathArray(AcEdSelectionSetService* service,
											bool bIsSubSelectionIndex, int index,
											AcDbFullSubentPathArray& fullPaths);


ACCORE_PORT void acedSetIgnoredEntAndDuplicatedBlkCount(AcEdSelectionSetService* service,
														int ignoredEntCount,
														int duplicatedBlkCount);

// <progesoft comment = "function to abort the save operation from the event intercetted from _RUBBERSHEET command">

ACCORE_PORT void acedAbortSaveCommand();

// </progesoft>

// <progesoft comment = "function to reload all images cache">

ACCORE_PORT Acad::ErrorStatus acedRegenImagesCache(AcDbDatabase* pDatabase);

// </progesoft>

#include "icarx/IcArxPackPop.h"

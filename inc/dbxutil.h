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

#include "icarx/AcDbDisableAnnoAutoScale.h"
#include "icarx/AcDbCustomDynStyleReactor.h"
#include "icarx/AcDbCustomDynStyleNotifier.h"

#include "adesk.h"
#include "acadstrc.h"
#include "adesk.h"
#include "adsdef.h"
#include "dbidar.h"
#include "dbid.h"
#include "acutmem.h"
#include "acgi.h"

class AcGeMatrix3d;
class AcDbObject;
class AcDbOle2Frame;
class AcCmColor;
class AcDbViewport;
struct AcConstrainedGeometryDraggingInfo;

ACDBCORE2D_PORT Acad::ErrorStatus acdbAddConstrainedGeometryDraggingInfo(
		const AcConstrainedGeometryDraggingInfo* pDraggingInfo);
Acad::ErrorStatus acdbAssignGelibCurveToAcDbCurve(const AcGeCurve3d& geCurve, AcDbCurve* pDbCurve,
												  AcGeVector3d* normal = nullptr,
												  const AcGeTol& tol = AcGeContext::gTol);
Acad::ErrorStatus acdbConvertAcDbCurveToGelibCurve(const AcDbCurve* dbCurve, AcGeCurve3d*& pGeCurve,
												   const AcGeTol& tol = AcGeContext::gTol);
ACDBCORE2D_PORT Acad::ErrorStatus acdbConvertGelibCurveToAcDbCurve(
		const AcGeCurve3d& geCurve, AcDbCurve*& pDbCurve, AcGeVector3d* normal = nullptr,
		const AcGeTol& tol = AcGeContext::gTol);
Acad::ErrorStatus acdbCreateViewByViewport(AcDbDatabase* pDb, AcDbObjectId viewportId,
										   const ACHAR* name, const ACHAR* categoryName,
										   AcDbObjectId labelBlockId, AcDbObjectId& view);
ACDBCORE2D_PORT bool ADESK_STDCALL acdbDwkFileExists(const ACHAR* pszFileName);
bool acdbEcs2Ucs(ads_point p, ads_point q, ads_point norm, bool vec);
bool acdbEcs2Wcs(ads_point p, ads_point q, ads_point norm, bool vec);
Acad::ErrorStatus acdbForceTextAdjust(const AcDbObjectIdArray& objIds);
bool acdbGetArcLengthSymbolPlacement(AcDbObject* pObj, int& nValue);
Acad::ErrorStatus acdbGetCurUserViewportId(AcDbDatabase* pDb, AcDbObjectId& vpId);
AcDbObjectId acdbGetCurVportId(AcDbDatabase* pDb);
AcDbObjectId acdbGetCurVportTableRecordId(AcDbDatabase* pDb);
bool acdbGetDimAngExtOn(AcDbObject* pObj, int& dimExtFlag);
bool acdbGetDimBreakSize(AcDbObject* pObj, double& dimBreakSize);
bool acdbGetDimExt1Linetype(AcDbObject* pObj, AcDbObjectId& oidValue);
bool acdbGetDimExt2Linetype(AcDbObject* pObj, AcDbObjectId& oidValue);
bool acdbGetDimExtensionLength(AcDbObject* pObj, double& fValue);
bool acdbGetDimFlipArrow(AcDbObject* pObj, int& nValue);
bool acdbGetDimFlipArrowWhich(AcDbObject* pObj, int& nValue);
bool acdbGetDimJogSymbolPosition(AcDbObject* pObj, int& dimJagFlag, AcGePoint3d& pos);
bool acdbGetDimJogSymbolSize(AcDbObject* pObj, int& dimJagFlag, double& dimJagSize);
bool acdbGetDimLineLinetype(AcDbObject* pObj, AcDbObjectId& oidValue);
ACDBCORE2D_PORT AcDbObjectId acdbGetDimStyleId(AcDbDatabase* pDb, const ACHAR* styleName,
											   const ACHAR* lockName);
bool acdbGetDimTextBackground(AcDbObject* pObj, int& bgFlag, AcCmColor& bgColor);
bool acdbGetDimTextDirection(AcDbObject* pObj, int& nValue);
bool acdbGetDimTolAlign(AcDbObject* pObj, int& dimTolAlignFlag);
ACDBCORE2D_PORT AcDbObjectId acdbGetDynDimStyleId(AcDbDatabase* pDb = nullptr);
bool acdbGetExemptCheckFlag(AcDbObject* pObj, int& bitFlags);
Acad::ErrorStatus acdbGetExtnames(bool& value, AcDbDatabase* pDb);
bool acdbGetFixedLengthExtLineEnabled(AcDbObject* pObj, int& nValue);
bool acdbGetLargeRadDimJogAngle(AcDbObject* pObj, double& fJogAngle);
ACDBCORE2D_PORT const ACHAR* acdbGetMappedFontName(const ACHAR* fontName);
Acad::ErrorStatus acdbGetProxyInfo(AcDbObject* pObj, ACHAR*& dxfName, ACHAR*& className,
								   ACHAR*& appName);
bool acdbGetRadialExtensionAngles(AcDbObject* pObj, int& dimExtFlag, double& dimExtAng1,
								  double& dimExtAng2);
const ACHAR* acdbGetReservedString(AcDb::reservedStringEnumType reservedType,
								   bool bGetLocalized = true);
Acad::ErrorStatus acdbGetUnitsConversion(AcDb::UnitsValue from, AcDb::UnitsValue to,
										 double& conversionFactor);
AcDbObjectId acdbGetViewportVisualStyle();
ACDBCORE2D_PORT Acad::ErrorStatus acdbGetVisualStyleIdByIndex(AcDbObjectId& visualStyleId,
															  int visualStyleIndex);
ACDBCORE2D_PORT int acdbGetVisualStyleIndexById(AcDbObjectId visualStyleId);
ACDBCORE2D_PORT int acdbGetVisualStyleIndexByName(const wchar_t* visualStyleName);
bool acdbIsInLongTransaction(AcDbObjectId id);
bool acdbIsReservedString(const ACHAR* strString, AcDb::reservedStringEnumType reservedType);
bool acdbPSLayoutAnnoAllVisible(AcDbObjectId viewportEntityId);
bool acdbPSLayoutAnnoAllVisible(AcDbViewport* pVport);
Acad::ErrorStatus acdbQueueAnnotationEntitiesForRegen(AcDbDatabase* pDb);
int ADESK_STDCALL acdbQueueForRegen(const AcDbObjectId* pIdArray, int nNumIds);
Acad::ErrorStatus acdbOleGetOriginalSelectedFontName(const AcDbOle2Frame* pOleEnt,
													 ACHAR*& fontName);
Acad::ErrorStatus acdbOleGetOriginalSelectedFontPointSize(const AcDbOle2Frame* pOleEnt,
														  int& pointSize);
Acad::ErrorStatus acdbOleGetOriginalSelectedTextSizeInAcadUnits(const AcDbOle2Frame* pOleEnt,
																double& sizeInAcadUnits);
Acad::ErrorStatus acdbOleGetOriginalWidthHeight(const AcDbOle2Frame* pOleEnt, double& width,
												double& height);
Acad::ErrorStatus acdbOleGetRotationMatrix(const AcDbOle2Frame* pOleEnt, AcGeMatrix3d& rotMat);
Acad::ErrorStatus acdbOleGetSelectedFontName(const AcDbOle2Frame* pOleEnt, ACHAR*& fontName);
Acad::ErrorStatus acdbOleGetSelectedFontPointSize(const AcDbOle2Frame* pOleEnt, int& pointSize);
Acad::ErrorStatus acdbOleGetSelectedTextSizeInAcadUnits(const AcDbOle2Frame* pOleEnt,
														double& sizeInAcadUnits);
Acad::ErrorStatus acdbOleHitTest(const AcDbOle2Frame* pOleEnt, const AcGePoint3d& wvpt,
								 const AcGeVector3d& wvwdir);
Acad::ErrorStatus acdbOleSetOriginalSelectedFontName(const AcDbOle2Frame* pOleEnt,
													 const ACHAR* fontName);
Acad::ErrorStatus acdbOleSetOriginalSelectedFontPointSize(const AcDbOle2Frame* pOleEnt,
														  const int pointSize);
Acad::ErrorStatus acdbOleSetOriginalSelectedTextSizeInAcadUnits(const AcDbOle2Frame* pOleEnt,
																const double sizeInAcadUnits);
Acad::ErrorStatus acdbOleSetOriginalWidthHeight(const AcDbOle2Frame* pOleEnt, const double width,
												const double height);
Acad::ErrorStatus acdbOleSetSelectedFontName(const AcDbOle2Frame* pOleEnt, const ACHAR* fontName);
Acad::ErrorStatus acdbOleSetSelectedFontPointSize(const AcDbOle2Frame* pOleEnt,
												  const int pointSize);
Acad::ErrorStatus acdbOleSetSelectedTextSizeInAcadUnits(const AcDbOle2Frame* pOleEnt,
														const double sizeInAcadUnits);
bool acdbSetArcLengthSymbolPlacement(AcDbObject* pObj, int nValue, bool autoClearOverride = true);
bool acdbSetDimAngExtOn(AcDbObject* pObj, int dimExtFlag);
bool acdbSetDimBreakSize(AcDbObject* pObj, double dimBreakSize, bool autoClearOverride = true);
bool acdbSetDimExt1Linetype(AcDbObject* pObj, AcDbObjectId oidValue, bool autoClearOverride = true);
bool acdbSetDimExt2Linetype(AcDbObject* pObj, AcDbObjectId oidValue, bool autoClearOverride = true);
bool acdbSetDimExtensionLength(AcDbObject* pObj, double fValue, bool autoClearOverride = true);
bool acdbSetDimFlipArrow(AcDbObject* pObj, int nValue, bool autoClearOverride = true);
bool acdbSetDimFlipArrowWhich(AcDbObject* pObj, int nValue, bool autoClearOverride = true);
bool acdbSetDimJogSymbolPosition(AcDbObject* pObj, int& dimJagFlag, const AcGePoint3d& pos,
								 bool autoClearOverride = true);
bool acdbSetDimJogSymbolSize(AcDbObject* pObj, int dimJagFlag, const double dimJagSize,
							 bool autoClearOverride = true);
bool acdbSetDimLineLinetype(AcDbObject* pObj, AcDbObjectId oidValue, bool autoClearOverride = true);
bool acdbSetDimTextBackground(AcDbObject* pObj, int bgFlag, AcCmColor* pBgColor,
							  bool autoClearOverride = true);
bool acdbSetDimTextDirection(AcDbObject* pObj, int nValue, bool autoClearOverride = true);
bool acdbSetDimTolAlign(AcDbObject* pObj, int dimTolAlignFlag, bool autoClearOverride = true);
bool acdbSetExemptCheckFlag(AcDbObject* pObj, int bitFlags);
Acad::ErrorStatus acdbSetExtnames(AcDbDatabase* pDb, bool value);
bool acdbSetFixedLengthExtLineEnabled(AcDbObject* pObj, int nValue, bool autoClearOverride = true);
bool acdbSetLargeRadDimJogAngle(AcDbObject* pObj, double fJogAngle, bool autoClearOverride = true);
bool acdbSetRadialExtensionAngles(AcDbObject* pObj, int dimExtFlag, double dimExtAng1,
								  double dimExtAng2);
Acad::ErrorStatus acdbSetViewportVisualStyle(AcDbObjectId visualStyleId);
bool acdbUcs2Ecs(ads_point p, ads_point q, ads_point norm, bool vec);
bool acdbUcs2Wcs(ads_point p, ads_point q, bool vec);
bool acdbUcsMatrix(AcGeMatrix3d& mat, AcDbDatabase* pDb = nullptr);
Acad::ErrorStatus acdbValidateDbConsistency(AcDbObject* pHostObject, AcDbDatabase* pDatabase,
											Acad::ErrorStatus es = Acad::eOk);
Acad::ErrorStatus acdbValidateDbConsistency(AcDbObject* pHostObject, AcDbObjectId objId,
											Acad::ErrorStatus es = Acad::eOk);
bool acdbWcs2Ecs(ads_point p, ads_point q, ads_point norm, bool vec);
bool acdbWcs2Ucs(ads_point p, ads_point q, bool vec);
const ACHAR* acdbXlateReservedString(const ACHAR* strSource, bool bGetLocalized = true);
ACDBCORE2D_PORT bool isMSpaceActive(AcDbDatabase* pDb);
bool regAppName(const wchar_t* pAppName, AcDbDatabase* pDatabase);
void ucsNormalVector(AcGeVector3d& ucsNormalVec);
AcGeVector3d ucsXDir();
AcGeVector3d ucsYDir();

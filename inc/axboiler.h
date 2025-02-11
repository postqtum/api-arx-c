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

#include "icarx/IAcadBaseObject.h"
#include "icarx/IAcadBaseObject2.h"
#include "icarx/IRetrieveApplication.h"
#include "icarx/IAcadBaseDatabase.h"
#include "icarx/IMetaColorSuppressor.h"
#include "icarx/IAcadAcCmColorAccess.h"
#include "icarx/IAcadBaseSubEntity.h"
#include "icarx/AxAutoExp.h"

#include <atlbase.h>

#include "adesk.h"
#include "axobjref.h"

struct IAcadHyperlinks;
struct IAcadDictionary;
struct IAcadAcCmColor;
enum AcWireframeType;
enum AcShadowDisplayType;
enum AcExtendOption;
enum AcColor;
typedef enum AcLineWeight ACAD_LWEIGHT;

HRESULT AXAUTOEXP AcAxArrayPolar(AcDbObjectId& objId, LPDISPATCH pAppDisp, int numObjs,
								 double fillAngle, VARIANT basePoint, VARIANT* pArrayObjs);
HRESULT AXAUTOEXP AcAxArrayPolar(AcAxObjectRef& objRef, LPDISPATCH pAppDisp, int numObjs,
								 double fillAngle, VARIANT basePoint, VARIANT* pArrayObjs);
HRESULT AXAUTOEXP AcAxArrayRectangular(AcDbObjectId& objId, LPDISPATCH pAppDisp, int numRows,
									   int numCols, int numLvls, double disRows, double disCols,
									   double disLvls, VARIANT* pArrayObjs);
HRESULT AXAUTOEXP AcAxArrayRectangular(AcAxObjectRef& objRef, LPDISPATCH pAppDisp, int numRows,
									   int numCols, int numLvls, double disRows, double disCols,
									   double disLvls, VARIANT* pArrayObjs);
HRESULT AXAUTOEXP AcAxCopy(AcDbObjectId& objId, LPDISPATCH pAppDisp, LPDISPATCH* pCopyObj,
						   AcDbObjectId ownerId = AcDbObjectId::kNull);
HRESULT AXAUTOEXP AcAxCopy(AcAxObjectRef& objRef, LPDISPATCH pAppDisp, LPDISPATCH* pCopyObj,
						   AcDbObjectId ownerId = AcDbObjectId::kNull);
HRESULT AXAUTOEXP AcAxEnableShadowDisplay(AcDbObjectId& objId, bool* pEnabled);
HRESULT AXAUTOEXP AcAxEnableShadowDisplay(AcAxObjectRef& objRef, bool* pEnabled);
HRESULT AXAUTOEXP AcAxErase(AcAxObjectRef& objRef);
HRESULT AXAUTOEXP AcAxErase(AcDbObjectId& objId);
HRESULT AXAUTOEXP AcAxGet_UIsolineDensity(AcDbObjectId& objId, long* density);
HRESULT AXAUTOEXP AcAxGet_VIsolineDensity(AcDbObjectId& objId, long* density);
HRESULT AXAUTOEXP AcAxGet_WireframeType(AcDbObjectId& objId, AcWireframeType* type);
HRESULT AXAUTOEXP AcAxGetBoundingBox(AcDbObjectId& objId, VARIANT* minPoint, VARIANT* maxPoint);
HRESULT AXAUTOEXP AcAxGetBoundingBox(AcAxObjectRef& objRef, VARIANT* minPoint, VARIANT* maxPoint);
HRESULT AXAUTOEXP AcAxGetColor(AcDbObjectId& objId, AcColor* pColor);
HRESULT AXAUTOEXP AcAxGetColor(AcAxObjectRef& objRef, AcColor* pColor);
HRESULT AXAUTOEXP AcAxGetDatabase(AcDbDatabase* pDb, LPDISPATCH pAppDisp, LPDISPATCH* pDisp);
HRESULT AXAUTOEXP AcAxGetEdgeExtensionDistances(AcDbObjectId& objId, VARIANT* extDistances);
HRESULT AXAUTOEXP AcAxGetExtensionDictionary(AcDbObjectId& objId, LPDISPATCH pAppDisp,
											 IAcadDictionary** pExtDictionary);
HRESULT AXAUTOEXP AcAxGetExtensionDictionary(AcAxObjectRef& objRef, LPDISPATCH pAppDisp,
											 IAcadDictionary** pExtDictionary);
HRESULT AXAUTOEXP AcAxGetHandle(AcDbObjectId& objId, BSTR* pHandle);
HRESULT AXAUTOEXP AcAxGetHandle(AcAxObjectRef& objRef, BSTR* pHandle);
HRESULT AXAUTOEXP AcAxGetHyperlinks(AcDbObjectId& objId, LPDISPATCH pAppDisp,
									IAcadHyperlinks** pHyperlinks);
HRESULT AXAUTOEXP AcAxGetHyperlinks(AcAxObjectRef& objRef, LPDISPATCH pAppDisp,
									IAcadHyperlinks** pHyperlinks);
HRESULT AXAUTOEXP AcAxGetIUnknownOfObject(LPUNKNOWN* ppUnk, AcDbObject* pObj, LPDISPATCH pApp);
HRESULT AXAUTOEXP AcAxGetIUnknownOfObject(LPUNKNOWN* ppUnk, AcDbObjectId& objId, LPDISPATCH pApp);
HRESULT AXAUTOEXP AcAxGetLayer(AcDbObjectId& objId, BSTR* pLayer);
HRESULT AXAUTOEXP AcAxGetLayer(AcAxObjectRef& objRef, BSTR* pLayer);
HRESULT AXAUTOEXP AcAxGetLineWeight(AcDbObjectId& objId, ACAD_LWEIGHT* lineWeight);
HRESULT AXAUTOEXP AcAxGetLineWeight(AcAxObjectRef& objRef, ACAD_LWEIGHT* lineWeight);
HRESULT AXAUTOEXP AcAxGetLinetype(AcDbObjectId& objId, BSTR* pLinetype);
HRESULT AXAUTOEXP AcAxGetLinetype(AcAxObjectRef& objRef, BSTR* pLinetype);
HRESULT AXAUTOEXP AcAxGetLinetypeScale(AcDbObjectId& objId, double* pLinetypeScale);
HRESULT AXAUTOEXP AcAxGetLinetypeScale(AcAxObjectRef& objRef, double* pLinetypeScale);
HRESULT AXAUTOEXP AcAxGetMaintainAssociativity(AcDbObjectId& objId, int* maintainAssoc);
HRESULT AXAUTOEXP AcAxGetMaterial(AcDbObjectId& objId, BSTR* pMaterial);
HRESULT AXAUTOEXP AcAxGetMaterial(AcAxObjectRef& objRef, BSTR* pMaterial);
int32_t AXAUTOEXP AcAxGetObjectId32(const IcArx::Integers::IntDbId& objId);
IcArx::Integers::IntDbId AXAUTOEXP AcAxGetObjectId64(const int32_t& objId);
HRESULT AXAUTOEXP AcAxGetObjectName(AcDbObjectId& objId, BSTR* pName);
HRESULT AXAUTOEXP AcAxGetObjectName(AcAxObjectRef& objRef, BSTR* pName);
HRESULT AXAUTOEXP AcAxGetOwnerId(AcDbObjectId& objId, IcArx::Integers::IntDbId* pOwnerId);
HRESULT AXAUTOEXP AcAxGetOwnerId(AcAxObjectRef& objRef, IcArx::Integers::IntDbId* pOwnerId);
HRESULT AXAUTOEXP AcAxGetPlotStyleName(AcDbObjectId& objId, BSTR* plotStyleName);
HRESULT AXAUTOEXP AcAxGetPlotStyleName(AcAxObjectRef& objRef, BSTR* plotStyleName);
HRESULT AXAUTOEXP AcAxGetShadowDisplay(AcDbObjectId& objId, AcShadowDisplayType* pShadowDisplay);
HRESULT AXAUTOEXP AcAxGetShadowDisplay(AcAxObjectRef& objRef, AcShadowDisplayType* pShadowDisplay);
HRESULT AXAUTOEXP AcAxGetShowAssociativity(AcDbObjectId& objId, VARIANT_BOOL* bEnabled);
HRESULT AXAUTOEXP AcAxGetSurfTrimAssociativity(AcDbObjectId& objId, VARIANT* associative);
HRESULT AXAUTOEXP AcAxGetTransparency(AcDbObjectId& objId, BSTR* pTransparency);
HRESULT AXAUTOEXP AcAxGetTransparency(AcAxObjectRef& objRef, BSTR* pTransparency);
HRESULT AXAUTOEXP AcAxGetTrueColor(AcDbObjectId& objId, IAcadAcCmColor** pColor);
HRESULT AXAUTOEXP AcAxGetTrueColor(AcAxObjectRef& objRef, IAcadAcCmColor** pColor);
HRESULT AXAUTOEXP AcAxGetVisible(AcDbObjectId& objId, VARIANT_BOOL* pVisible);
HRESULT AXAUTOEXP AcAxGetVisible(AcAxObjectRef& objRef, VARIANT_BOOL* pVisible);
HRESULT AXAUTOEXP AcAxGetXData(AcDbObjectId& objId, BSTR bstrName, VARIANT* type, VARIANT* data);
HRESULT AXAUTOEXP AcAxGetXData(AcAxObjectRef& objRef, BSTR bstrName, VARIANT* type, VARIANT* data);
HRESULT AXAUTOEXP AcAxHasExtensionDictionary(AcDbObjectId& objId, VARIANT_BOOL* bHasDictionary);
HRESULT AXAUTOEXP AcAxHasExtensionDictionary(AcAxObjectRef& objRef, VARIANT_BOOL* bHasDictionary);
HRESULT AXAUTOEXP AcAxHighlight(AcDbObjectId& objId, VARIANT_BOOL bHighlight);
HRESULT AXAUTOEXP AcAxHighlight(AcAxObjectRef& objRef, VARIANT_BOOL bHighlight);
HRESULT AXAUTOEXP AcAxIntersectWith(AcDbObjectId& objId, LPDISPATCH pEntity, AcExtendOption option,
									VARIANT* intPoints);
HRESULT AXAUTOEXP AcAxIntersectWith(AcAxObjectRef& objRef, LPDISPATCH pEntity,
									AcExtendOption option, VARIANT* intPoints);
HRESULT AXAUTOEXP AcAxMirror(AcDbObjectId& objId, LPDISPATCH pAppDisp, VARIANT point1,
							 VARIANT point2, LPDISPATCH* pMirrorObj);
HRESULT AXAUTOEXP AcAxMirror(AcAxObjectRef& objRef, LPDISPATCH pAppDisp, VARIANT point1,
							 VARIANT point2, LPDISPATCH* pMirrorObj);
HRESULT AXAUTOEXP AcAxMirror3D(AcDbObjectId& objId, LPDISPATCH pAppDisp, VARIANT point1,
							   VARIANT point2, VARIANT point3, LPDISPATCH* pMirrorObj);
HRESULT AXAUTOEXP AcAxMirror3D(AcAxObjectRef& objRef, LPDISPATCH pAppDisp, VARIANT point1,
							   VARIANT point2, VARIANT point3, LPDISPATCH* pMirrorObj);
HRESULT AXAUTOEXP AcAxMove(AcDbObjectId& objId, VARIANT fromPoint, VARIANT toPoint);
HRESULT AXAUTOEXP AcAxMove(AcAxObjectRef& objRef, VARIANT fromPoint, VARIANT toPoint);
HRESULT AXAUTOEXP AcAxPut_UIsolineDensity(AcDbObjectId& objId, long density);
HRESULT AXAUTOEXP AcAxPut_VIsolineDensity(AcDbObjectId& objId, long density);
HRESULT AXAUTOEXP AcAxPut_WireframeType(AcDbObjectId& objId, AcWireframeType type);
HRESULT AXAUTOEXP AcAxPutColor(AcDbObjectId& objId, AcColor color);
HRESULT AXAUTOEXP AcAxPutColor(AcAxObjectRef& objRef, AcColor color);
HRESULT AXAUTOEXP AcAxPutEdgeExtensionDistances(AcDbObjectId& objId, VARIANT extDistances);
HRESULT AXAUTOEXP AcAxPutLayer(AcDbObjectId& objId, BSTR layer);
HRESULT AXAUTOEXP AcAxPutLayer(AcAxObjectRef& objRef, BSTR layer);
HRESULT AXAUTOEXP AcAxPutLineWeight(AcDbObjectId& objId, ACAD_LWEIGHT lineWeight);
HRESULT AXAUTOEXP AcAxPutLineWeight(AcAxObjectRef& objRef, ACAD_LWEIGHT lineWeight);
HRESULT AXAUTOEXP AcAxPutLinetype(AcDbObjectId& objId, BSTR linetype);
HRESULT AXAUTOEXP AcAxPutLinetype(AcAxObjectRef& objRef, BSTR linetype);
HRESULT AXAUTOEXP AcAxPutLinetypeScale(AcDbObjectId& objId, double linetypeScale);
HRESULT AXAUTOEXP AcAxPutLinetypeScale(AcAxObjectRef& objRef, double linetypeScale);
HRESULT AXAUTOEXP AcAxPutMaintainAssociativity(AcDbObjectId& objId, int maintainAssoc);
HRESULT AXAUTOEXP AcAxPutMaterial(AcDbObjectId& objId, BSTR material);
HRESULT AXAUTOEXP AcAxPutMaterial(AcAxObjectRef& objRef, BSTR material);
HRESULT AXAUTOEXP AcAxPutPlotStyleName(AcDbObjectId& objId, BSTR plotStyleName);
HRESULT AXAUTOEXP AcAxPutPlotStyleName(AcAxObjectRef& objRef, BSTR plotStyleName);
HRESULT AXAUTOEXP AcAxPutShadowDisplay(AcDbObjectId& objId, AcShadowDisplayType shadowDisplay);
HRESULT AXAUTOEXP AcAxPutShadowDisplay(AcAxObjectRef& objRef, AcShadowDisplayType shadowDisplay);
HRESULT AXAUTOEXP AcAxPutShowAssociativity(AcDbObjectId& objId, VARIANT_BOOL bEnabled);
HRESULT AXAUTOEXP AcAxPutSurfTrimAssociativity(AcDbObjectId& objId, VARIANT associative);
HRESULT AXAUTOEXP AcAxPutTransparency(AcDbObjectId& objId, BSTR transparency);
HRESULT AXAUTOEXP AcAxPutTransparency(AcAxObjectRef& objRef, BSTR transparency);
HRESULT AXAUTOEXP AcAxPutTrueColor(AcDbObjectId& objId, IAcadAcCmColor* color);
HRESULT AXAUTOEXP AcAxPutTrueColor(AcAxObjectRef& objRef, IAcadAcCmColor* color);
HRESULT AXAUTOEXP AcAxPutVisible(AcDbObjectId& objId, VARIANT_BOOL visible);
HRESULT AXAUTOEXP AcAxPutVisible(AcAxObjectRef& objRef, VARIANT_BOOL visible);
HRESULT AXAUTOEXP AcAxRotate(AcDbObjectId& objId, VARIANT basePoint, double rotationAngle);
HRESULT AXAUTOEXP AcAxRotate(AcAxObjectRef& objRef, VARIANT basePoint, double rotationAngle);
HRESULT AXAUTOEXP AcAxRotate3D(AcDbObjectId& objId, VARIANT point1, VARIANT point2,
							   double rotationAngle);
HRESULT AXAUTOEXP AcAxRotate3D(AcAxObjectRef& objRef, VARIANT point1, VARIANT point2,
							   double rotationAngle);
HRESULT AXAUTOEXP AcAxScaleEntity(AcDbObjectId& objId, VARIANT basePoint, double scaleFactor);
HRESULT AXAUTOEXP AcAxScaleEntity(AcAxObjectRef& objRef, VARIANT basePoint, double scaleFactor);
HRESULT AXAUTOEXP AcAxSetXData(AcDbObjectId& objId, VARIANT type, VARIANT data);
HRESULT AXAUTOEXP AcAxSetXData(AcAxObjectRef& objRef, VARIANT type, VARIANT data);
HRESULT AXAUTOEXP AcAxTransformBy(AcDbObjectId& objId, VARIANT transMatrix);
HRESULT AXAUTOEXP AcAxTransformBy(AcAxObjectRef& objRef, VARIANT transMatrix);
HRESULT AXAUTOEXP AcAxUpdate(AcDbObjectId& objId);
HRESULT AXAUTOEXP AcAxUpdate(AcAxObjectRef& objRef);
HRESULT AXAUTOEXP RaiseAcAXException(REFGUID iid, HRESULT hRes, DWORD dwException, ...);
HRESULT AXAUTOEXP RaiseArxException(REFGUID iid, HRESULT hRes, Acad::ErrorStatus es);

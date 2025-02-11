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
***     Description:  Declaration of AcDbVisualStyle class
***
*****************************************************************************/
#pragma once

#include "dbmain.h"
#include "acgi.h"

#include "icarx/AcGiVisualStyle.h"

const ACHAR kszVSFlat[] = /*MSG0*/ ACRX_T("Flat");
const ACHAR kszVSFlatWithEdges[] = /*MSG0*/ ACRX_T("FlatWithEdges");
const ACHAR kszVSGouraud[] = /*MSG0*/ ACRX_T("Gouraud");
const ACHAR kszVSGouraudWithEdges[] = /*MSG0*/ ACRX_T("GouraudWithEdges");

const ACHAR kszVS2DWireframe[] = /*MSG0*/ ACRX_T("2dWireframe");
const ACHAR kszVS3DWireframe[] = /*MSG0*/ ACRX_T("Wireframe");
const ACHAR kszVSBasic[] = /*MSG0*/ ACRX_T("Basic");
const ACHAR kszVSHidden[] = /*MSG0*/ ACRX_T("Hidden");
const ACHAR kszVSRealistic[] = /*MSG0*/ ACRX_T("Realistic");
const ACHAR kszVSConceptual[] = /*MSG0*/ ACRX_T("Conceptual");
const ACHAR kszVSCustom[] = /*MSG0*/ ACRX_T("Custom");
const ACHAR kszVSShadesOfGray[] = /*MSG0*/ ACRX_T("Shades of Gray");
const ACHAR kszVSSketchy[] = /*MSG0*/ ACRX_T("Sketchy");
const ACHAR kszVSXRay[] = /*MSG0*/ ACRX_T("X-Ray");

const ACHAR kszVSShadedWithEdges[] = /*MSG0*/ ACRX_T("Shaded with edges");
const ACHAR kszVSShaded[] = /*MSG0*/ ACRX_T("Shaded");

const ACHAR kszVSDim[] = /*MSG0*/ ACRX_T("Dim");
const ACHAR kszVSBrighten[] = /*MSG0*/ ACRX_T("Brighten");
const ACHAR kszVSThicken[] = /*MSG0*/ ACRX_T("Thicken");
const ACHAR kszVSTransparent[] = /*MSG0*/ ACRX_T("Transparent");
const ACHAR kszVSLinePattern[] = /*MSG0*/ ACRX_T("Linepattern");
const ACHAR kszVSFacePattern[] = /*MSG0*/ ACRX_T("Facepattern");
const ACHAR kszVSColorChange[] = /*MSG0*/ ACRX_T("ColorChange");

const ACHAR kszVSJitterOff[] = /*MSG0*/ ACRX_T("JitterOff");
const ACHAR kszVSOverhangOff[] = /*MSG0*/ ACRX_T("OverhangOff");
const ACHAR kszVSEdgeColorOff[] = /*MSG0*/ ACRX_T("EdgeColorOff");

#include "icarx/IcArxPackPush.h"

class AcDbVisualStyle : public AcDbObject
{
public:
	ACDB_DECLARE_MEMBERS(AcDbVisualStyle);

	AcDbVisualStyle();
	~AcDbVisualStyle();

	virtual Acad::ErrorStatus copyFrom(const AcGiVisualStyle* pSrc);
	virtual Acad::ErrorStatus copyTo(AcGiVisualStyle* pDest) const;
	Acad::ErrorStatus decomposeForSave(AcDb::AcDbDwgVersion ver, AcDbObject*& replaceObj,
									   AcDbObjectId& replaceId, bool& exchangeXData) override;
	const ACHAR* description(void) const;
	AcGiDrawable* drawable(void) override;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	virtual bool isInternalUseOnly() const;
	ACDBCORE2D_PORT Acad::ErrorStatus name(AcString& value) const;
	Acad::ErrorStatus setDescription(const ACHAR* pDescription);
	virtual void setInternalUseOnly(bool bInternalUseOnly);
	Acad::ErrorStatus setTrait(
			AcGiVisualStyleProperties::Property prop, const AcGiVariant* pVal,
			AcGiVisualStyleOperations::Operation op = AcGiVisualStyleOperations::kSet);
	Acad::ErrorStatus setTrait(
			AcGiVisualStyleProperties::Property prop, int nVal,
			AcGiVisualStyleOperations::Operation op = AcGiVisualStyleOperations::kSet);
	Acad::ErrorStatus setTrait(
			AcGiVisualStyleProperties::Property prop, bool bVal,
			AcGiVisualStyleOperations::Operation op = AcGiVisualStyleOperations::kSet);
	Acad::ErrorStatus setTrait(
			AcGiVisualStyleProperties::Property prop, double dVal,
			AcGiVisualStyleOperations::Operation op = AcGiVisualStyleOperations::kSet);
	Acad::ErrorStatus setTrait(
			AcGiVisualStyleProperties::Property prop, double red, double green, double blue,
			AcGiVisualStyleOperations::Operation op = AcGiVisualStyleOperations::kSet);
	Acad::ErrorStatus setTrait(
			AcGiVisualStyleProperties::Property prop, const AcCmColor* pColor,
			AcGiVisualStyleOperations::Operation op = AcGiVisualStyleOperations::kSet);
	Acad::ErrorStatus setTraitFlag(AcGiVisualStyleProperties::Property flagProp, uint32_t flagVal,
								   bool bEnable = true);
	Acad::ErrorStatus setType(AcGiVisualStyle::Type type);
	const AcGiVariant& trait(AcGiVisualStyleProperties::Property prop,
							 AcGiVisualStyleOperations::Operation* pOp = nullptr) const;
	bool traitFlag(AcGiVisualStyleProperties::Property flagProp, uint32_t flagVal) const;
	AcGiVisualStyle::Type type() const;
};

#include "icarx/IcArxPackPop.h"

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
***     Description: Declaration of AcGiVisualStyle class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../rxboiler.h"
#include "AcGiVisualStyleProperties.h"
#include "AcGiVisualStyleOperations.h"

class AcGiImpVisualStyle;

#include "IcArxPackPush.h"

class AcGiVisualStyle : public AcRxObject
{
	friend class AcDbImpVisualStyle;

public:
	using Property = AcGiVisualStyleProperties::Property;
	using Operation = AcGiVisualStyleOperations::Operation;

	enum Type
	{
		kFlat,
		kFlatWithEdges,
		kGouraud,
		kGouraudWithEdges,
		k2DWireframe,
		k3DWireframe,
		kHidden,
		kBasic,
		kRealistic,
		kConceptual,
		kCustom,
		kDim,
		kBrighten,
		kThicken,
		kLinePattern,
		kFacePattern,
		kColorChange,
		kFaceOnly,
		kEdgeOnly,
		kDisplayOnly,
		kJitterOff,
		kOverhangOff,
		kEdgeColorOff,
		kShadesOfGray,
		kSketchy,
		kXRay,
		kShadedWithEdges,
		kShaded,
		kByViewport,
		kByLayer,
		kByBlock,
		kEmptyStyle,
	};

private:
	AcGiImpVisualStyle* mpAcGiImpVisualStyle;

private:
	const AcGiImpVisualStyle* readImp() const;
	AcGiImpVisualStyle* writeImp();

public:
	ACRX_DECLARE_MEMBERS(AcGiVisualStyle);

	AcGiVisualStyle();
	AcGiVisualStyle(Type type);
	AcGiVisualStyle(const AcGiVisualStyle& visualStyle);
	~AcGiVisualStyle();
	AcGiVisualStyle& operator=(const AcGiVisualStyle& visualStyle);
	bool operator==(const AcGiVisualStyle& visualStyle) const;

	ACDBCORE2D_PORT virtual Operation operation(Property prop) const;
	ACDBCORE2D_PORT static AcGiVariant::VariantType propertyType(Property prop);
	ACDBCORE2D_PORT virtual bool setTrait(Property prop, Operation op);
	ACDBCORE2D_PORT virtual bool setTrait(Property prop, bool bVal,
										  Operation op = AcGiVisualStyleOperations::kSet);
	ACDBCORE2D_PORT virtual bool setTrait(Property prop, int nVal,
										  Operation op = AcGiVisualStyleOperations::kSet);
	ACDBCORE2D_PORT virtual bool setTrait(Property prop, double dVal,
										  Operation op = AcGiVisualStyleOperations::kSet);
	ACDBCORE2D_PORT virtual bool setTrait(Property prop, double red, double green, double blue,
										  Operation op = AcGiVisualStyleOperations::kSet);
	ACDBCORE2D_PORT virtual bool setTrait(Property prop, const AcCmColor* pColor,
										  Operation op = AcGiVisualStyleOperations::kSet);
	ACDBCORE2D_PORT virtual bool setTrait(Property prop, const AcGiVariant* pVal,
										  Operation op = AcGiVisualStyleOperations::kSet);
	ACDBCORE2D_PORT virtual bool setTrait(Property prop, const AcString* pStr,
										  Operation op = AcGiVisualStyleOperations::kSet);
	ACDBCORE2D_PORT virtual bool setTraitFlag(Property flagProp, uint32_t flagVal,
											  bool bEnable = true);
	ACDBCORE2D_PORT bool setType(Type type);
	ACDBCORE2D_PORT virtual const AcGiVariant& trait(Property prop, Operation* pOp = nullptr) const;
	ACDBCORE2D_PORT virtual bool traitFlag(Property flagProp, uint32_t flagVal) const;
	ACDBCORE2D_PORT Type type() const;
};

#include "IcArxPackPop.h"

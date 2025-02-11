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
***     Description: Declaration of AcGiSubEntityTraits class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../rxboiler.h"
#include "../acgidefs.h"
#include "../acdb.h"
#include "../dbid.h"
#include "../dbcolor.h"

class AcCmEntityColor;
class AcGiMapper;
class AcCmTransparency;
class AcGiFill;

#include "IcArxPackPush.h"

class AcGiSubEntityTraits : public AcRxObject
{
public:
	enum DrawFlags
	{
		kNoDrawFlags = 0,
		kDrawBackfaces = 1,
		kDrawHatchGroup = 2,
		kDrawFrontfacesOnly = 4,
		kDrawGradientFill = 8,
		kDrawSolidFill = 16,
		kDrawNoLineWeight = 32,
		kDrawNoOptimization = 64,
		kDrawUseAcGiEntityForDgnLineType = 128,
		kDrawFillTextBoundaryStart = 256,
		kDrawFillTextBoundaryEnd = 512,
		kDrawFillSelectionWindow = 1024,
		kDrawNoForceByLayer = 2048
	};

	enum ShadowFlags
	{
		kShadowsCastAndReceive = 0x00,
		kShadowsDoesNotCast = 0x01,
		kShadowsDoesNotReceive = 0x02,
		kShadowsIgnore = kShadowsDoesNotCast | kShadowsDoesNotReceive,
	};

	enum SelectionFlags
	{
		kNoSelectionFlags = 0x00,
		kSelectionIgnore = 0x01
	};

	ACRX_DECLARE_MEMBERS_EXPIMP(AcGiSubEntityTraits, ACDBCORE2D_PORT);

	virtual void clearMarkerOverride() {}
	virtual uint16_t color() const = 0;
	virtual uint32_t drawFlags() const;
	virtual AcDb::PlotStyleNameType getPlotStyleNameId(AcDbObjectId& /*idResult*/) const
	{
		return AcDb::kPlotStyleNameByLayer;
	}
	virtual const AcGiFill* fill() const;
	virtual AcGiFillType fillType() const = 0;
	virtual AcDbObjectId layerId() const = 0;
	virtual AcDbObjectId lineTypeId() const = 0;
	virtual double lineTypeScale() const = 0;
	virtual AcDb::LineWeight lineWeight() const = 0;
	virtual AcDbObjectId materialId() const;
	virtual const AcGiMapper* mapper() const;
	virtual void popMarkerOverride() {}
	virtual void pushMarkerOverride(bool /*flag*/, const IcArx::Integers::LongPtr /*markerId*/) {}
	virtual bool sectionable() const;
	virtual bool selectionGeom() const;
	virtual void setColor(const uint16_t color) = 0;
	virtual Acad::ErrorStatus setDrawFlags(uint32_t flags);
	virtual void setFill(const AcGiFill* pFill);
	virtual void setFillType(const AcGiFillType) = 0;
	virtual void setLayer(const AcDbObjectId layerId) = 0;
	virtual void setLineType(const AcDbObjectId linetypeId) = 0;
	virtual void setLineTypeScale(double dScale = 1.0) = 0;
	virtual void setLineWeight(const AcDb::LineWeight lw) = 0;
	virtual void setLineWeight(const AcDb::LineWeight lw, const char lweight_index);
	virtual void setMapper(const AcGiMapper* mapper);
	virtual void setMaterial(const AcDbObjectId materialId);
	virtual void setPlotStyleName(AcDb::PlotStyleNameType /*type*/,
								  const AcDbObjectId& /*id*/ = AcDbObjectId::kNull)
	{
	}
	virtual void setSectionable(bool bSectionable);
	virtual void setSelectionGeom(bool bSelectionflag);
	virtual void setSelectionMarker(const IcArx::Integers::LongPtr markerId) = 0;
	virtual Acad::ErrorStatus setShadowFlags(ShadowFlags flags);
	virtual void setThickness(double dThickness) = 0;
	virtual void setTransparency(const AcCmTransparency& transparency);
	virtual void setTrueColor(const AcCmEntityColor& color) = 0;
	virtual void setVisualStyle(const AcDbObjectId visualStyleId);
	virtual ShadowFlags shadowFlags() const;
	virtual double thickness() const = 0;
	virtual AcCmTransparency transparency() const;
	virtual AcCmEntityColor trueColor() const = 0;
	virtual AcDbObjectId visualStyle() const;
};

#include "IcArxPackPop.h"

inline uint32_t AcGiSubEntityTraits::drawFlags() const
{
	return 0;
}

inline const AcGiFill* AcGiSubEntityTraits::fill() const
{
	return nullptr;
}

inline const AcGiMapper* AcGiSubEntityTraits::mapper() const
{
	return nullptr;
}

inline AcDbObjectId AcGiSubEntityTraits::materialId() const
{
	return AcDbObjectId::kNull;
}

inline bool AcGiSubEntityTraits::sectionable() const
{
	return false;
}

inline bool AcGiSubEntityTraits::selectionGeom() const
{
	return false;
}

inline Acad::ErrorStatus AcGiSubEntityTraits::setDrawFlags(uint32_t /*flags*/)
{
	return Acad::eNotImplementedYet;
}

inline void AcGiSubEntityTraits::setFill(const AcGiFill* /*pFill*/)
{
}

inline void AcGiSubEntityTraits::setLineWeight(const AcDb::LineWeight lw,
											   const char /*lweight_index*/)
{
	setLineWeight(lw);
}

inline void AcGiSubEntityTraits::setMapper(const AcGiMapper* /*mapper*/)
{
}

inline void AcGiSubEntityTraits::setMaterial(const AcDbObjectId /*materialId*/)
{
}

inline void AcGiSubEntityTraits::setSectionable(bool /*bSectionable*/)
{
}

inline void AcGiSubEntityTraits::setSelectionGeom(bool)
{
}

inline Acad::ErrorStatus AcGiSubEntityTraits::setShadowFlags(ShadowFlags /*flags*/)
{
	return Acad::eNotImplementedYet;
}

inline void AcGiSubEntityTraits::setTransparency(const AcCmTransparency&)
{
}

inline void AcGiSubEntityTraits::setVisualStyle(AcDbObjectId /*visualStyleId*/)
{
}

inline AcGiSubEntityTraits::ShadowFlags AcGiSubEntityTraits::shadowFlags() const
{
	return kShadowsCastAndReceive;
}

inline AcCmTransparency AcGiSubEntityTraits::transparency() const
{
	return AcCmTransparency();
}

inline AcDbObjectId AcGiSubEntityTraits::visualStyle() const
{
	return AcDbObjectId::kNull;
}

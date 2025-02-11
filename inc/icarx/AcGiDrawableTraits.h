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
***     Description: Declaration of AcGiDrawableTraits class
***
*****************************************************************************/
#pragma once

#include "AcGiSubEntityTraits.h"
#include "AcGiVariant.h"
#include "AcGiLineAttributes.h"

class AcDbEntity;
class AcGiContext;

#include "IcArxPackPush.h"

class AcGiDrawableTraits : public AcGiSubEntityTraits
{
	friend class AcDbImpLayerTableRecord;

protected:
	enum LayerFlags
	{
		kNone = 0x00,
		kOff = 0x01,
		kFrozen = 0x02,
		kZero = 0x04,
		kLocked = 0x08
	};

	virtual void setLayerFlags(uint8_t /*flags*/) {}

public:
	enum HighlightProperty
	{
		kVertexRolloverHighlightSize,
	};

	ACRX_DECLARE_MEMBERS_EXPIMP(AcGiDrawableTraits, ACDBCORE2D_PORT);

	virtual void addLight(const AcDbObjectId& lightId);
	virtual AcGiContext* context() const { return nullptr; }
	virtual AcGiVariant highlightProperty(HighlightProperty property) const;
	virtual AcGiLineType linePattern() const;
	virtual SelectionFlags selectionFlags() const;
	virtual Acad::ErrorStatus setHighlightProperty(HighlightProperty property, AcGiVariant& value);
	virtual void setLinePattern(const AcGiLineType linePattern);
	virtual Acad::ErrorStatus setSelectionFlags(const SelectionFlags flags);
	ACDBCORE2D_PORT virtual void setupForEntity(AcDbEntity* pEntity);
};

#include "IcArxPackPop.h"

inline void AcGiDrawableTraits::addLight(const AcDbObjectId& /*lightId*/)
{
}

inline AcGiVariant AcGiDrawableTraits::highlightProperty(HighlightProperty /*property*/) const
{
	return AcGiVariant();
}

inline AcGiLineType AcGiDrawableTraits::linePattern() const
{
	return kLineTypeSolid;
}

inline AcGiSubEntityTraits::SelectionFlags AcGiDrawableTraits::selectionFlags() const
{
	return kNoSelectionFlags;
}

inline Acad::ErrorStatus AcGiDrawableTraits::setHighlightProperty(HighlightProperty /*property*/,
																  AcGiVariant& /*value*/)
{
	return Acad::eOk;
}

inline void AcGiDrawableTraits::setLinePattern(const AcGiLineType /*linePattern*/)
{
}

inline Acad::ErrorStatus AcGiDrawableTraits::setSelectionFlags(const SelectionFlags /*flags*/)
{
	return Acad::eOk;
}

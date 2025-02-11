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
***     Description: Declaration of AcGiStyleAttributes classes
***
*****************************************************************************/
#pragma once

#include "AcCmEntityColor.h"
#include "AcDbObjectId.h"

class AcGiLineAttributes;

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcGiStyleAttributes
{
public:
	enum AttributeFlags
	{
		kNothing = 0x00,
		kColor = 0x01,
		kLine = 0x02,
		kLineType = 0x04,
		kPlotStyle = 0x08,
		kEverything = 0x0F
	};

protected:
	AcCmEntityColor m_colorAttribute;
	AcDbObjectId m_idLinetype;
	AcDbObjectId m_idPlotstyle;

public:
	AcGiStyleAttributes() = default;
	AcGiStyleAttributes(const AcGiStyleAttributes& source);
	virtual ~AcGiStyleAttributes() = default;

	virtual void EnsureColorVisibility(AcCmEntityColor& color) = 0;
	const AcCmEntityColor& getColorAttribute() const { return m_colorAttribute; }
	AcCmEntityColor& getColorAttribute() { return m_colorAttribute; }
	virtual const AcGiLineAttributes* getLineAttribute() const = 0;
	virtual AcGiLineAttributes* getLineAttribute() = 0;
	AcDbObjectId linetypeObjectId() const { return m_idLinetype; }
	AcDbObjectId plotStyleNameId() const { return m_idPlotstyle; }
	void setColorAttribute(const AcCmEntityColor& color) { m_colorAttribute = color; }
	virtual void setLineAttribute(const AcGiLineAttributes* pLineAttributes) = 0;
	void setLinetypeObjectId(const AcDbObjectId& newId) { m_idLinetype = newId; }
	void setPlotStyleName(const AcDbObjectId& newId) { m_idPlotstyle = newId; }
};

#include "IcArxPackPop.h"

inline AcGiStyleAttributes::AcGiStyleAttributes(const AcGiStyleAttributes& source)
{
	m_colorAttribute = source.getColorAttribute();
	m_idLinetype = source.linetypeObjectId();
	m_idPlotstyle = source.plotStyleNameId();
}

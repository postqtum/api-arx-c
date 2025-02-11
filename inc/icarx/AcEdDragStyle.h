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
***     Description: Declaration of AcEdDragStyle class
***
*****************************************************************************/
#pragma once

#include "../dbdimdata.h"
#include "../AcCoreDefs.h"

class AcEdImpDragStyle;

#include "IcArxPackPush.h"

class AcEdDragStyle
{
	friend class AcEdImpDragStyle;

public:
	enum StyleType
	{
		kNone = 0,
		kHide,
		kTransparent25,
		kTransparent75,
		kDeletedEffect,
		kHighlight,
		kNotSet,
		kOpacity
	};

private:
	AcEdImpDragStyle* mpOriginalDragStyle;
	AcEdImpDragStyle* mpDraggedDragStyle;

public:
	ACCORE_PORT AcEdDragStyle();
	ACCORE_PORT AcEdDragStyle(StyleType styleTypeForOriginal, StyleType styleTypeForDragged);
	ACCORE_PORT AcEdDragStyle(const AcEdDragStyle& dragStyle);
	ACCORE_PORT ~AcEdDragStyle();
	ACCORE_PORT AcEdDragStyle& operator=(const AcEdDragStyle& src);
	ACCORE_PORT bool operator==(const AcEdDragStyle& other) const;
	ACCORE_PORT bool operator!=(const AcEdDragStyle& other) const;

	ACCORE_PORT Acad::ErrorStatus setStyleTypeForDragged(StyleType styleType);
	ACCORE_PORT Acad::ErrorStatus setStyleTypeForOriginal(StyleType styleType);
	ACCORE_PORT StyleType styleTypeForDragged() const;
	ACCORE_PORT StyleType styleTypeForOriginal() const;
};

#include "IcArxPackPop.h"

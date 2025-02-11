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
***     Description: Declaration of AcEdInplaceTextEditorSettings class
***
*****************************************************************************/
#pragma once

#include "../AcCoreDefs.h"
#include "../acadstrc.h"

class AcEdInplaceTextEditorSettingsImp;

#include "IcArxPackPush.h"

class AcEdInplaceTextEditorSettings
{
public:
	enum EditFlags
	{
		kForceOpaqueBackground = 1 << 0,
		kSelectAll = 1 << 1,
		kCursorAtEnd = 1 << 2,
	};

	enum EntityType
	{
		kDefault,
		kTableCell,
		kMultiAttribute
	};

protected:
	AcEdInplaceTextEditorSettingsImp* m_pImp;

public:
	ACCORE_PORT AcEdInplaceTextEditorSettings();
	ACCORE_PORT ~AcEdInplaceTextEditorSettings();
	AcEdInplaceTextEditorSettings(const AcEdInplaceTextEditorSettings&) = delete;
	AcEdInplaceTextEditorSettings& operator=(const AcEdInplaceTextEditorSettings&) = delete;

	ACCORE_PORT double definedHeight() const;
	ACCORE_PORT int editFlags() const;
	ACCORE_PORT Acad::ErrorStatus setDefinedHeight(double height);
	ACCORE_PORT Acad::ErrorStatus setEditFlags(int flags);
	ACCORE_PORT Acad::ErrorStatus setSimpleMText(bool bSimpleMText);
	ACCORE_PORT Acad::ErrorStatus setSourceEntityType(EntityType type);
	ACCORE_PORT Acad::ErrorStatus setSupportTab(bool bTab);
	ACCORE_PORT bool simpleMText() const;
	ACCORE_PORT EntityType sourceEntityType() const;
	ACCORE_PORT bool tabSupported() const;
};

#include "IcArxPackPop.h"

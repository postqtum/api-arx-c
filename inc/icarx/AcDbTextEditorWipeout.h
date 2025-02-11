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
***     Description: Declaration of AcDbTextEditorWipeout class
***
*****************************************************************************/
#pragma once

#include "../acadstrc.h"
#include "../AcDbCore2dDefs.h"

#include "AcCmColor.h"

class TextEditor;

#include "IcArxPackPush.h"

class AcDbTextEditorWipeout
{
	friend class TextEditor;

private:
	TextEditor* m_pEditor;

private:
	AcDbTextEditorWipeout();
	~AcDbTextEditorWipeout();
	AcDbTextEditorWipeout(const AcDbTextEditorWipeout&);
	AcDbTextEditorWipeout& operator=(const AcDbTextEditorWipeout&);

public:
	ACDBCORE2D_PORT bool enableBackgroundFill() const;
	ACDBCORE2D_PORT AcCmColor getBackgroundFillColor() const;
	ACDBCORE2D_PORT double getBackgroundScaleFactor() const;
	ACDBCORE2D_PORT static double maxBackgroundScaleFactor();
	ACDBCORE2D_PORT static double minBackgroundScaleFactor();
	ACDBCORE2D_PORT Acad::ErrorStatus setBackgroundFillColor(AcCmColor color);
	ACDBCORE2D_PORT Acad::ErrorStatus setBackgroundScaleFactor(double factor);
	ACDBCORE2D_PORT Acad::ErrorStatus setEnableBackgroundFill(bool bEnable);
	ACDBCORE2D_PORT Acad::ErrorStatus setUseBackgroundColor(bool bUse);
	ACDBCORE2D_PORT bool useBackgroundColor() const;
};

#include "IcArxPackPop.h"

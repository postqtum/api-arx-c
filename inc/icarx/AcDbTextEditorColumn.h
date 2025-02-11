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
***     Description: Declaration of AcDbTextEditorColumn class
***
*****************************************************************************/
#pragma once

#include "../acadstrc.h"
#include "../AcDbCore2dDefs.h"

#include "AcDbTextEditorSelectable.h"

class AcDbTextEditorLocation;
class AcDbImpTextEditorColumn;

#include "IcArxPackPush.h"

class AcDbTextEditorColumn : public AcDbTextEditorSelectable
{
	friend class AcDbTextEditorServices;

private:
	AcDbImpTextEditorColumn* m_pImp;

private:
	AcDbTextEditorColumn();
	~AcDbTextEditorColumn();
	AcDbTextEditorColumn(const AcDbTextEditorColumn&);
	AcDbTextEditorColumn& operator=(const AcDbTextEditorColumn&);

public:
	ACDBCORE2D_PORT AcDbTextEditorLocation* endOfText() override;
	ACDBCORE2D_PORT double height();
	ACDBCORE2D_PORT void release();
	ACDBCORE2D_PORT Acad::ErrorStatus setHeight(double height);
	ACDBCORE2D_PORT AcDbTextEditorLocation* startOfText() override;
};

#include "IcArxPackPop.h"

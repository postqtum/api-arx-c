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
***     Description: Declaration of AcRxVariable class
***
*****************************************************************************/
#pragma once

#include "../acarray.h"

#include "AcRxVariable.h"

class AcRxVariableReactor;

#include "IcArxPackPush.h"

class AcRxVariablesDictionary
{
	friend class AcRxImpVariablesDictionary;

private:
	AcRxImpVariablesDictionary* m_pImp = nullptr;

private:
	AcRxVariablesDictionary(AcRxImpVariablesDictionary*);

public:
	~AcRxVariablesDictionary() = default;

	ACDBCORE2D_PORT Acad::ErrorStatus reset(AcRxVariable::StorageType filter);
	ACDBCORE2D_PORT AcRxVariable* getVariable(const ACHAR* name) const;
	ACDBCORE2D_PORT const AcArray<AcString>& getAllNames() const;
	ACDBCORE2D_PORT static Acad::ErrorStatus setBool(AcRxVariable*, bool val);
	ACDBCORE2D_PORT static Acad::ErrorStatus setBool(const ACHAR* name, bool val);
	ACDBCORE2D_PORT static Acad::ErrorStatus setDouble(AcRxVariable* pVar, double val);
	ACDBCORE2D_PORT static Acad::ErrorStatus setDouble(const ACHAR* name, double val);
	ACDBCORE2D_PORT static Acad::ErrorStatus setInt16(AcRxVariable* pVar, short val);
	ACDBCORE2D_PORT static Acad::ErrorStatus setInt16(const ACHAR* name, short val);
	ACDBCORE2D_PORT static Acad::ErrorStatus setString(AcRxVariable* pVar, const ACHAR* val);
	ACDBCORE2D_PORT static Acad::ErrorStatus setString(const ACHAR* name, const ACHAR* val);
	ACDBCORE2D_PORT static AcRxVariablesDictionary* get();
	ACDBCORE2D_PORT static AcString getString(const ACHAR* name);
	ACDBCORE2D_PORT static AcString getString(const AcRxVariable* pVar);
	ACDBCORE2D_PORT static bool getBool(const ACHAR* name, bool def);
	ACDBCORE2D_PORT static bool getBool(const AcRxVariable* pVar, bool def);
	ACDBCORE2D_PORT static double getDouble(const ACHAR* name, double def);
	ACDBCORE2D_PORT static double getDouble(const AcRxVariable* pVar, double def);
	ACDBCORE2D_PORT static short getInt16(const ACHAR* name, short def);
	ACDBCORE2D_PORT static short getInt16(const AcRxVariable* pVar, short def);
	ACDBCORE2D_PORT void addReactor(AcRxVariableReactor* reactor);
	ACDBCORE2D_PORT void removeReactor(AcRxVariableReactor* reactor);

};

#include "IcArxPackPop.h"

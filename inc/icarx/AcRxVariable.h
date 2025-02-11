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

#include "../AcDbCore2dDefs.h"
#include "../AcString.h"
#include "../acadstrc.h"

class AcRxVariableReactor;
struct resbuf;

#include "IcArxPackPush.h"

class AcRxVariable
{
	friend class AcRxImpVariable;

public:
	struct Range
	{
		int lowerBound = 0;
		int upperBound = 0;

		Range() = default;
		Range(int lb, int ub) : lowerBound(lb), upperBound(ub) {}
	};

	enum SecondaryType
	{
		kSecondaryTypeNone = 0,
		kSecondaryTypeBoolean = 1,
		kSecondaryTypeSymbolName = 2,
		kSecondaryTypeArea = 3,
		kSecondaryTypeDistance = 4,
		kSecondaryTypeAngle = 5,
		kSecondaryTypeUnitlessReal = 6,
		kSecondaryTypeLast = 6,
	};

	enum StorageType
	{
		kStoragePerSession = 0,
		kStoragePerUser = 1,
		kStoragePerProfile = 2,
		kStoragePerDatabase = 3,
		kStoragePerViewport = 4
	};

	enum TypeFlags
	{
		kTypeFlagsNone = 0,
		kTypeFlagSpacesAllowed = 1,
		kTypeFlagDotMeansEmpty = 2,
		kTypeFlagNoUndo = 4,
		kTypeFlagsChatty = 8,
		kTypeDeprecated = 16,
	};

private:
	AcRxImpVariable* m_pImp;

private:
	AcRxVariable(AcRxImpVariable*);

public:
	ACDBCORE2D_PORT ~AcRxVariable();

	ACDBCORE2D_PORT Acad::ErrorStatus getValue(resbuf& value) const;
	ACDBCORE2D_PORT Acad::ErrorStatus reset();
	ACDBCORE2D_PORT Acad::ErrorStatus setIsReadOnly(bool value, void* ownerId,
												   const AcString* reason = nullptr);
	ACDBCORE2D_PORT Acad::ErrorStatus setValue(const resbuf& value, void* ownerId = nullptr,
							   AcString* failReason = nullptr, bool disableUndoRecording = false);
	ACDBCORE2D_PORT AcRxVariable::SecondaryType secondaryType() const;
	ACDBCORE2D_PORT AcRxVariable::StorageType storageType() const;
	ACDBCORE2D_PORT bool isLocked() const;
	ACDBCORE2D_PORT bool isReadOnly(AcString* reason = nullptr) const;
	ACDBCORE2D_PORT const ACHAR* name() const;
	ACDBCORE2D_PORT const AcRxVariable::Range* range() const;
	ACDBCORE2D_PORT short primaryType() const;
	ACDBCORE2D_PORT short typeFlags() const;
	ACDBCORE2D_PORT void addReactor(AcRxVariableReactor* reactor);
	ACDBCORE2D_PORT void removeReactor(AcRxVariableReactor* reactor);
};

#include "IcArxPackPop.h"

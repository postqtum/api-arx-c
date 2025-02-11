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
***     Description: Declaration of AcDbAssocVariable class
***
*****************************************************************************/
#pragma once

#include "AcDbAssocValueProviderPE.h"
#include "AcDbAssocAction.h"

ACDBCORE2D_PORT AcString& dummyString();

class AcDbAssocVariableCallback;

#include "icarx/IcArxPackPush.h"

class ACDBCORE2D_PORT AcDbAssocVariable : public AcDbAssocAction
{
public:
	ACRX_DECLARE_MEMBERS(AcDbAssocVariable);

	explicit AcDbAssocVariable(
			AcDbAssocCreateImpObject createImpObject = kAcDbAssocCreateImpObject);

	static void addGlobalCallback(AcDbAssocVariableCallback* pCallback);
	const AcString& description() const;
	static Acad::ErrorStatus evaluateExpression(const AcString& expression,
												const AcString& evaluatorId,
												const AcDbObjectId& networkId,
												AcDbEvalVariant& evaluatedExpressionValue,
												AcString& assignedToSymbolName,
												AcString& errorMessage = dummyString());
	Acad::ErrorStatus evaluateExpression(AcDbObjectIdArray& objectIds,
										 AcArray<AcDbEvalVariant>& objectValues,
										 AcDbEvalVariant& evaluatedExpressionValue,
										 AcString& errorMessage = dummyString()) const;
	Acad::ErrorStatus evaluateExpression(AcDbEvalVariant& evaluatedExpressionValue,
										 AcString& errorMessage = dummyString()) const;
	const AcString& evaluatorId() const;
	const AcString& expression() const;
	const AcString& expression(bool convertSymbolNamesFromCanonicalForm) const;
	AcDbObjectId findObjectByName(const AcString& objectName, const AcRxClass* pObjectClass) const;
	static AcDbAssocVariableCallback* globalCallback();
	bool isAnonymous() const;
	bool isMergeable() const;
	AcString mergeableVariableName() const;
	bool mustMerge() const;
	const AcString& name() const;
	static void removeGlobalCallback(AcDbAssocVariableCallback* pCallback);
	Acad::ErrorStatus setDescription(const AcString& newDescription);
	Acad::ErrorStatus setEvaluatorId(const AcString& evalId);
	Acad::ErrorStatus setExpression(const AcString& newExpression, const AcString& evaluatorId,
									bool checkForCyclicalDependencies,
									bool updateDependenciesOnReferencedSymbols,
									AcString& errorMessage = dummyString(),
									bool silentMode = false);
	void setIsMergeable(bool isMerg, bool mustMerg = false,
						const AcString& mergeableVariableName = AcString());
	Acad::ErrorStatus setName(const AcString& newName, bool updateReferencingExpressions);
	Acad::ErrorStatus setValue(const AcDbEvalVariant& newValue);
	Acad::ErrorStatus validateNameAndExpression(const AcString& nameToValidate,
												const AcString& expressionToValidate,
												AcString& errorMessage) const;
	const AcDbEvalVariant& value() const;
};

class ACDBCORE2D_PORT AcDbAssocVariableCallback
{
public:
	AcDbAssocVariableCallback() = default;
	virtual ~AcDbAssocVariableCallback() = default;

	virtual bool canBeErased(const AcDbAssocVariable* pVariable) = 0;
	virtual Acad::ErrorStatus validateNameAndExpression(const AcDbAssocVariable* pVariable,
														const AcString& nameToValidate,
														const AcString& expressionToValidate,
														AcString& errorMessage) = 0;
};

#include "icarx/IcArxPackPop.h"

ACDBCORE2D_PORT void stringDefaultArgumentTest(AcString& str = dummyString());

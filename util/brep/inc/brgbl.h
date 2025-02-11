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
***     Description:
***
*****************************************************************************/
#pragma once

#include "inc/adesk.h"
#include "inc/acadstrc.h"

struct AcBr
{
	enum ErrorStatus
	{
		eOk = 0,
		eNotImplementedYet = Acad::eNotImplementedYet,
		eNotApplicable = Acad::eNotApplicable,
		eInvalidInput = Acad::eInvalidInput,
		eOutOfMemory = Acad::eOutOfMemory,
		eNullObjectPointer = Acad::eUnrecoverableErrors,
		eWrongObjectType = Acad::eWrongObjectType,
		eWrongSubentityType = Acad::eWrongSubentityType,
		eNullObjectId = Acad::eNullObjectId,
		eNullSubentityId = Acad::eInvalidIndex,
		eObjectIdMismatch = Acad::eWrongDatabase,
		eTopologyMismatch = Acad::eWrongDatabase,
		eUnsuitableGeometry = Acad::eAmbiguousOutput,
		eMissingGeometry = Acad::eDegenerateGeometry,
		eMissingSubentity = Acad::eNotInDatabase,
		eInvalidObject = Acad::eUnrecoverableErrors,
		eAmbiguousOutput = Acad::eAmbiguousOutput,
		eBrepChanged = 3008,
		eUnsuitableTopology = 3013,
		eDegenerateTopology = 3020,
		eUninitialisedObject = 3021
	};

	enum Relation
	{
		kUnknown = 0,
		kOutside = 1,
		kInside = 2,
		kBoundary = 3,
		kCoincident = 4,
		kTangent = 5,
		kIntersect = 6
	};

	enum Element2dShape
	{
		kDefault = 0,
		kAllPolygons = 1,
		kAllQuadrilaterals = 2,
		kAllTriangles = 3
	};

	enum LoopType
	{
		kUnclassified = 0,
		kExterior = 1,
		kInterior = 2,
		kWinding = 3,
		kLoopUnclassified = kUnclassified,
		kLoopExterior = kExterior,
		kLoopInterior = kInterior,
		kLoopWinding = kWinding
	};

	enum ValidationLevel
	{
		kFullValidation = 0,
		kNoValidation = 1
	};

	enum ShellType
	{
		kShellUnclassified = 0,
		kShellExterior = 1,
		kShellInterior = 2
	};
};

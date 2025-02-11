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

#include "acadstrc.h"
#include "brgbl.h"

typedef AcBr::ErrorStatus AcBrErrorStatus;
typedef AcBr::Relation AcBrRelation;
typedef AcBr::Element2dShape AcBrElement2dShape;
typedef AcBr::LoopType AcBrLoopType;
typedef AcBr::ValidationLevel AcBrValidationLevel;
typedef AcBr::ShellType AcBrShellType;

const AcBrErrorStatus eOk = AcBr::eOk;
const AcBrErrorStatus eNotImplementedYet = AcBr::eNotImplementedYet;
const AcBrErrorStatus eNotApplicable = AcBr::eNotApplicable;
const AcBrErrorStatus eInvalidInput = AcBr::eInvalidInput;
const AcBrErrorStatus eOutOfMemory = AcBr::eOutOfMemory;
const AcBrErrorStatus eNullObjectPointer = AcBr::eNullObjectPointer;
const AcBrErrorStatus eWrongObjectType = AcBr::eWrongObjectType;
const AcBrErrorStatus eWrongSubentityType = AcBr::eWrongSubentityType;
const AcBrErrorStatus eBrepChanged = AcBr::eBrepChanged;
const AcBrErrorStatus eNullObjectId = AcBr::eNullObjectId;
const AcBrErrorStatus eNullSubentityId = AcBr::eNullSubentityId;
const AcBrErrorStatus eObjectIdMismatch = AcBr::eObjectIdMismatch;
const AcBrErrorStatus eTopologyMismatch = AcBr::eTopologyMismatch;
const AcBrErrorStatus eUnsuitableTopology = AcBr::eUnsuitableTopology;
const AcBrErrorStatus eUnsuitableGeometry = AcBr::eUnsuitableGeometry;
const AcBrErrorStatus eMissingGeometry = AcBr::eMissingGeometry;
const AcBrErrorStatus eMissingSubentity = AcBr::eMissingSubentity;
const AcBrErrorStatus eInvalidObject = AcBr::eInvalidObject;
const AcBrErrorStatus eAmbiguousOutput = AcBr::eAmbiguousOutput;
const AcBrErrorStatus eDegenerateTopology = AcBr::eDegenerateTopology;
const AcBrErrorStatus eUninitialisedObject = AcBr::eUninitialisedObject;

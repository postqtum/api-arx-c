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
***     Description: Declaration of AcDbEnumType
***
*****************************************************************************/
#pragma once

#include "AcDb.h"

enum AcDb::FilerType
{
	kFileFiler = 0,
	kCopyFiler = 1,
	kUndoFiler = 2,
	kBagFiler = 3,
	kIdXlateFiler = 4,
	kPageFiler = 5,
	kDeepCloneFiler = 6,
	kIdFiler = 7,
	kPurgeFiler = 8,
	kWblockCloneFiler = 9
};

enum AcDb::FilerSeekType
{
	kSeekFromStart = 0,
	kSeekFromCurrent = 1,
	kSeekFromEnd = 2
};

enum AcDb::SliceModelType
{
	kKeepBothSides = 0x01,
	kUseCurrentColor = 0x02
};

enum AcDb::CollisionType
{
	kCollisionTypeNone = 0,
	kCollisionTypeSolid = 1
};

enum AcDb::Intersect
{
	kOnBothOperands = 0,
	kExtendThis = 1,
	kExtendArg = 2,
	kExtendBoth = 3
};

enum AcDb::LoftParamType
{
	kLoftNoParam = 0x00,
	kLoftNoTwist = 0x01,
	kLoftAlignDirection = 0x02,
	kLoftSimplify = 0x04,
	kLoftClose = 0x08,
	kLoftPeriodic = 0x10,
	kLoftDefault = AcDb::LoftParamType::kLoftNoTwist | AcDb::LoftParamType::kLoftAlignDirection |
				   AcDb::LoftParamType::kLoftSimplify
};

enum AcDb::LoftNormalsType
{
	kLoftRuled = 0,
	kLoftSmooth = 1,
	kLoftFirstNormal = 2,
	kLoftLastNormal = 3,
	kLoftEndsNormal = 4,
	kLoftAllNormal = 5,
	kLoftUseDraftAngles = 6
};

enum AcDb::SelectType
{
	kWindow = 1,
	kCrossing = 2
};

namespace AcDb
{

enum
{
	kNullSubentType = 0,
	kFaceSubentType = 1,
	kEdgeSubentType = 2,
	kVertexSubentType = 3,
	kMlineSubentCache = 4,
	kClassSubentType = 5,
	kAxisSubentType = 6,
	kSilhouetteSubentType = 7,
};

}

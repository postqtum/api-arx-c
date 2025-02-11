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
***     Description: Declaration of AcEdJig class
***
*****************************************************************************/
#pragma once

#include "../dbdimdata.h"
#include "../AcCoreDefs.h"

class AcEdImpJig;
class AcEdDragStyle;

#include "IcArxPackPush.h"

class AcEdJig : public AcRxObject
{
	friend class AcEdJigInputHelper;

public:
	enum CursorType
	{
		kNoSpecialCursor = -1,
		kCrosshair = 0,
		kRectCursor,
		kRubberBand,
		kNotRotated,
		kTargetBox,
		kRotatedCrosshair,
		kCrosshairNoRotate,
		kInvisible,
		kEntitySelect,
		kParallelogram,
		kEntitySelectNoPersp,
		kPkfirstOrGrips,
		kCrosshairDashed
	};

	enum DragStatus
	{
		kModeless = -17,
		kNoChange = -6,
		kCancel = -4,
		kOther = -3,
		kNull = -1,
		kNormal = 0,
		kKW1,
		kKW2,
		kKW3,
		kKW4,
		kKW5,
		kKW6,
		kKW7,
		kKW8,
		kKW9
	};

	enum UserInputControls
	{
		kGovernedByOrthoMode = 0x000001,
		kNullResponseAccepted = 0x000002,
		kDontEchoCancelForCtrlC = 0x000004,
		kDontUpdateLastPoint = 0x000008,
		kNoDwgLimitsChecking = 0x000010,
		kNoZeroResponseAccepted = 0x000020,
		kNoNegativeResponseAccepted = 0x000040,
		kAccept3dCoordinates = 0x000080,
		kAcceptMouseUpAsPoint = 0x000100,
		kAnyBlankTerminatesInput = 0x000200,
		kInitialBlankTerminatesInput = 0x000400,
		kAcceptOtherInputString = 0x000800,
		kGovernedByUCSDetect = 0x001000,
		kNoZDirectionOrtho = 0x002000,
		kImpliedFaceForUCSChange = 0x004000,
		kUseBasePointElevation = 0x008000,
		kDisableDirectDistanceInput = 0x010000,
	};

public:
	ACRX_DECLARE_MEMBERS(AcEdJig);

	AcEdJig();
	~AcEdJig();

	DragStatus acquireAngle(double& ang);
	DragStatus acquireAngle(double& ang, const AcGePoint3d& basePnt);
	DragStatus acquireDist(double& dist);
	DragStatus acquireDist(double& dist, const AcGePoint3d& basePnt);
	DragStatus acquirePoint(AcGePoint3d&);
	DragStatus acquirePoint(AcGePoint3d&, const AcGePoint3d& basePnt);
	ACCORE_PORT DragStatus acquireString(AcString& s);
	ACCORE_PORT DragStatus acquireString(ACHAR (&str)[2049]);
	AcDbObjectId append();
	virtual AcDbDimDataPtrArray* dimData(const double dimScale);
	const ACHAR* dispPrompt();
	DragStatus drag();
	ACCORE_PORT DragStatus drag(const AcEdDragStyle& style);
	virtual AcDbEntity* entity() const;
	const ACHAR* keywordList();
	virtual DragStatus sampler();
	virtual Acad::ErrorStatus setDimValue(const AcDbDimData* dimData, const double dimValue);
	void setDispPrompt(const ACHAR*, ...);
	void setKeywordList(const ACHAR*);
	void setSpecialCursorType(CursorType);
	void setUserInputControls(AcEdJig::UserInputControls);
	AcEdJig::CursorType specialCursorType();
	AcEdJig::UserInputControls userInputControls();
	virtual bool update();
};

#include "IcArxPackPop.h"

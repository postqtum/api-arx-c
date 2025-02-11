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
***     Description: Declaration of AcDbMotionPath class
***
*****************************************************************************/
#pragma once

#include "dbmain.h"

#include "icarx/SceneDllImpExp.h"

const ACHAR ACDB_MOTIONPATH_DICTIONARY[] = /*MSG0*/ ACRX_T("ACAD_MOTION");

Acad::ErrorStatus SCENEDLLIMPEXP acdbGetMotionPathDictionary(AcDbDatabase* pDb,
															 AcDbDictionary*& pDict,
															 AcDb::OpenMode mode,
															 bool createIfNonExist);
Acad::ErrorStatus SCENEDLLIMPEXP acdbGetMotionPathDictionary(AcDbDatabase* pDb,
															 AcDbDictionary*& pDict,
															 AcDb::OpenMode mode);

class AcDbImpMotionPath;

#include "icarx/IcArxPackPush.h"
#pragma warning(disable : 4275 4251)

class SCENEDLLIMPEXP AcDbMotionPath : public AcDbObject
{
	friend class AcDbImpMotionPath;

protected:
	AcDbImpMotionPath* imp() const;
	uint32_t subSetAttributes(AcGiDrawableTraits* pTraits) override;

public:
	ACRX_DECLARE_MEMBERS(AcDbMotionPath);

	AcDbMotionPath();
	~AcDbMotionPath();

	AcDbObjectId cameraPath() const;
	bool cornerDecel() const;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	uint32_t frameRate() const;
	uint32_t frames() const;
	Acad::ErrorStatus setCameraPath(const AcDbObjectId& id);
	Acad::ErrorStatus setCornerDecel(bool cornerDecel);
	Acad::ErrorStatus setFrameRate(uint16_t rate);
	Acad::ErrorStatus setFrames(uint16_t frames);
	Acad::ErrorStatus setTargetPath(const AcDbObjectId& id);
	Acad::ErrorStatus setViewTableRecordId(const AcDbObjectId& id);
	AcDbObjectId viewTableRecordId() const;
	AcDbObjectId targetPath() const;
};

#include "icarx/IcArxPackPop.h"

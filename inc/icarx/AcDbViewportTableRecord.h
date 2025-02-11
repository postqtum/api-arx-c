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
***     Description: Declaration of AcDbViewportTableRecord class
***
*****************************************************************************/
#pragma once

#include "AcDbAbstractViewTableRecord.h"
#include "AcGsView.h"

#include "IcArxPackPush.h"

class AcDbViewportTableRecord : public AcDbAbstractViewTableRecord
{
public:
	using TableType = AcDbViewportTable;

protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbViewportTableRecord);

	AcDbViewportTableRecord();
	~AcDbViewportTableRecord();

	uint16_t circleSides() const;
	AcGiDrawable* drawable() override;
	bool fastZoomsEnabled() const { return true; }
	bool gridEnabled() const;
	AcGePoint2d gridIncrements() const;
	int16_t gridMajor() const;
	AcGsView* gsView() const;
	bool iconAtOrigin() const;
	bool iconEnabled() const;
	bool isGridAdaptive() const;
	bool isGridBoundToLimits() const;
	bool isGridFollow() const;
	bool isGridSubdivisionRestricted() const;
	bool isUcsSavedWithViewport() const;
	bool isometricSnapEnabled() const;
	AcGePoint2d lowerLeftCorner() const;
	int16_t number() const;
	AcDbObjectId previousBackground(
			AcGiDrawable::DrawableType type = AcGiDrawable::kGeometry) const;
	bool previousBackgroundForcedSwitch(void) const;
	Acad::ErrorStatus setBackground(const AcDbObjectId& backgroundId);
	void setCircleSides(uint16_t circleSides);
	void setFastZoomsEnabled(bool enabled) { (void)(enabled); }
	void setGridAdaptive(bool enabled);
	void setGridBoundToLimits(bool enabled);
	void setGridEnabled(bool enabled);
	void setGridFollow(bool enabled);
	void setGridIncrements(const AcGePoint2d& base);
	void setGridMajor(int16_t value);
	void setGridSubdivisionRestricted(bool enabled);
	void setGsView(AcGsView* pView);
	void setIconAtOrigin(bool atOrigin);
	void setIconEnabled(bool enabled);
	void setIsometricSnapEnabled(bool enabled);
	void setLowerLeftCorner(const AcGePoint2d& pt);
	Acad::ErrorStatus setPreviousBackground(
			AcDbObjectId backgroundId, AcGiDrawable::DrawableType type = AcGiDrawable::kGeometry);
	Acad::ErrorStatus setPreviousBackground(AcDbObjectId backgroundId,
											AcGiDrawable::DrawableType type, bool bForcedSwitch);
	void setSnapAngle(double angle);
	void setSnapBase(const AcGePoint2d& base);
	void setSnapEnabled(bool enabled);
	void setSnapIncrements(const AcGePoint2d& base);
	void setSnapPair(int16_t pairType);
	void setUcsFollowMode(bool enabled);
	void setUcsPerViewport(bool ucsvp);
	void setUpperRightCorner(const AcGePoint2d& pt);
	double snapAngle() const;
	AcGePoint2d snapBase() const;
	bool snapEnabled() const;
	AcGePoint2d snapIncrements() const;
	int16_t snapPair() const;
	bool ucsFollowMode() const;
	AcGePoint2d upperRightCorner() const;
};

#include "IcArxPackPop.h"

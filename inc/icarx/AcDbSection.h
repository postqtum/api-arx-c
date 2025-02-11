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
***     Description: Declaration of AcDbSection class
***
*****************************************************************************/
#pragma once

#include <map>

#include "../gemat3d.h"
#include "../dbmain.h"

using AcDbSectionGeometryMap = std::map<AcDbEntity*, uint32_t>;

class AcDbSectionSettings;

#include "IcArxPackPush.h"

class AcDbSection : public AcDbEntity
{
public:
	enum State
	{
		kPlane = (0x1 << 0),
		kBoundary = (0x1 << 1),
		kVolume = (0x1 << 2),
	};

	enum SubItem
	{
		kNone = 0,
		kSectionLine = (0x1 << 0),
		kSectionLineTop = (0x1 << 1),
		kSectionLineBottom = (0x1 << 2),
		kBackLine = (0x1 << 3),
		kBackLineTop = (0x1 << 4),
		kBackLineBottom = (0x1 << 5),
		kVerticalLineTop = (0x1 << 6),
		kVerticalLineBottom = (0x1 << 7),
	};

	enum Height
	{
		kHeightAboveSectionLine = 0x1,
		kHeightBelowSectionLine = 0x2,
	};

protected:
	ACDB_PORT Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbSection);

	ACDB_PORT AcDbSection();
	ACDB_PORT AcDbSection(const AcGePoint3dArray& pts, const AcGeVector3d& verticalDir);
	ACDB_PORT AcDbSection(const AcGePoint3dArray& pts, const AcGeVector3d& verticalDir,
						  const AcGeVector3d& vecViewingDir);
	ACDB_PORT ~AcDbSection();

	ACDB_PORT Acad::ErrorStatus addVertex(int nInsertAt, const AcGePoint3d& pt);
	ACDB_PORT double bottomPlane() const;
	ACDB_PORT Acad::ErrorStatus createJog(const AcGePoint3d& ptOnSection);
	ACDB_PORT Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	ACDB_PORT Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	ACDB_PORT Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	ACDB_PORT Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	ACDB_PORT double elevation() const;
	ACDB_PORT Acad::ErrorStatus enableLiveSection(bool bEnable);
	ACDB_PORT Acad::ErrorStatus generateSectionGeometry(
			AcDbEntity* pEnt, AcArray<AcDbEntity*>& intBoundaryEnts,
			AcArray<AcDbEntity*>& intFillEnts, AcArray<AcDbEntity*>& backgroundEnts,
			AcArray<AcDbEntity*>& foregroundEnts, AcArray<AcDbEntity*>& curveTangencyEnts) const;
	ACDB_PORT Acad::ErrorStatus generateSectionGeometry(
			const AcArray<AcDbEntity*>& entset, AcArray<AcDbEntity*>& intBoundaryEnts,
			AcArray<AcDbEntity*>& intFillEnts, AcArray<AcDbEntity*>& backgroundEnts,
			AcArray<AcDbEntity*>& foregroundEnts, AcArray<AcDbEntity*>& curveTangencyEnts) const;

	ACDB_PORT Acad::ErrorStatus generateSectionGeometry(
			const AcDbVoidPtrArray& bodies, const AcDbIntArray& instanceCount,
			const AcArray<AcGeMatrix3d>& xforms, const AcArray<AcRxClass*>& providerClasses,
			AcArray<AcDbEntity*>& intBoundaryEnts, AcArray<AcDbEntity*>& intFillEnts,
			AcArray<AcDbEntity*>& backgroundEnts, AcArray<AcDbEntity*>& foregroundEnts,
			AcArray<AcDbEntity*>& curveTangencyEnts, AcDbSectionGeometryMap* = nullptr) const;
	ACDB_PORT const ACHAR* getName() const;
	ACDB_PORT Acad::ErrorStatus getName(AcString& sName) const;
	Acad::ErrorStatus getName(ACHAR*& pszName) const;
	ACDB_PORT AcDbObjectId getSettings() const;
	ACDB_PORT Acad::ErrorStatus getSettings(AcDbSectionSettings*& pSettings,
											AcDb::OpenMode mode) const;
	ACDB_PORT Acad::ErrorStatus getVertex(int nIndex, AcGePoint3d& pt) const;
	ACDB_PORT Acad::ErrorStatus getVertices(AcGePoint3dArray& pts) const;
	ACDB_PORT bool hasJogs() const;
	ACDB_PORT double height(AcDbSection::Height nHeightType) const;
	ACDB_PORT bool hitTest(const AcGePoint3d& ptHit, int* pSegmentIndex, AcGePoint3d* ptOnSegment,
						   AcDbSection::SubItem* pSubItem) const;
	ACDB_PORT AcCmColor indicatorFillColor() const;
	ACDB_PORT int indicatorTransparency() const;
	ACDB_PORT bool isLiveSectionEnabled() const;
	ACDB_PORT bool isSlice() const;
	ACDB_PORT AcGeVector3d normal() const;
	ACDB_PORT int numVertices() const;
	ACDB_PORT Acad::ErrorStatus plane(AcGeVector3d& uAxis, AcGeVector3d& vAxis) const;
	ACDB_PORT Acad::ErrorStatus removeVertex(int nIndex);
	ACDB_PORT double sectionPlaneOffset() const;
	ACDB_PORT Acad::ErrorStatus setBottomPlane(double);
	ACDB_PORT Acad::ErrorStatus setElevation(double elev);
	ACDB_PORT Acad::ErrorStatus setHeight(AcDbSection::Height nHeightType, double fHeight);
	ACDB_PORT Acad::ErrorStatus setIndicatorFillColor(const AcCmColor& color);
	ACDB_PORT Acad::ErrorStatus setIndicatorTransparency(int nTransparency);
	ACDB_PORT Acad::ErrorStatus setIsSlice(bool value);
	ACDB_PORT Acad::ErrorStatus setName(const ACHAR* pszName);
	ACDB_PORT Acad::ErrorStatus setSectionPlaneOffset(double offset);
	ACDB_PORT Acad::ErrorStatus setState(AcDbSection::State nState);
	ACDB_PORT Acad::ErrorStatus setThicknessDepth(double fThickness);
	ACDB_PORT Acad::ErrorStatus setTopPlane(double);
	ACDB_PORT Acad::ErrorStatus setVertex(int nIndex, const AcGePoint3d& pt);
	ACDB_PORT Acad::ErrorStatus setVerticalDirection(const AcGeVector3d& dir);
	ACDB_PORT Acad::ErrorStatus setVertices(const AcGePoint3dArray& pts);
	ACDB_PORT Acad::ErrorStatus setViewingDirection(const AcGeVector3d& dir);
	ACDB_PORT AcDbSection::State state() const;
	ACDB_PORT Acad::ErrorStatus subClose() override;
	ACDB_PORT double thicknessDepth() const;
	ACDB_PORT double topPlane() const;
	ACDB_PORT AcGeVector3d verticalDirection() const;
	ACDB_PORT AcGeVector3d viewingDirection() const;
};

#include "IcArxPackPop.h"

inline Acad::ErrorStatus AcDbSection::getName(ACHAR*& pszName) const
{
	return ::acutGetAcStringConvertToAChar(this, &AcDbSection::getName, pszName);
}

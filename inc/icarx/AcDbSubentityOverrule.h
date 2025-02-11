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
***     Description: Declaration of AcDbSubentityOverrule class
***
*****************************************************************************/
#pragma once

#include "../rxoverrule.h"
#include "AcDbEntity.h"

#include "IcArxPackPush.h"

class AcDbSubentityOverrule : public AcRxOverrule
{
public:
	ACRX_DECLARE_MEMBERS(AcDbSubentityOverrule);

	ACDBCORE2D_PORT AcDbSubentityOverrule();

	ACDBCORE2D_PORT virtual Acad::ErrorStatus addSubentPaths(
			AcDbEntity* pSubject, const AcDbFullSubentPathArray& newPaths);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus deleteSubentPaths(
			AcDbEntity* pSubject, const AcDbFullSubentPathArray& paths);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getCompoundObjectTransform(const AcDbEntity* pSubject,
																		 AcGeMatrix3d& xMat);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getGripPointsAtSubentPath(
			const AcDbEntity* pSubject, const AcDbFullSubentPath& path, AcDbGripDataPtrArray& grips,
			const double curViewUnitSize, const int gripSize, const AcGeVector3d& curViewDir,
			const int bitflags);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getGsMarkersAtSubentPath(
			const AcDbEntity* pSubject, const AcDbFullSubentPath& subPath,
			AcArray<IcArx::Integers::GsMarker>& gsMarkers);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getSubentClassId(const AcDbEntity* pSubject,
															   const AcDbFullSubentPath& path,
															   CLSID* clsId);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getSubentPathGeomExtents(
			const AcDbEntity* pSubject, const AcDbFullSubentPath& path, AcDbExtents& extents);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getSubentPathsAtGsMarker(
			const AcDbEntity* pSubject, AcDb::SubentType type, IcArx::Integers::GsMarker gsMark,
			const AcGePoint3d& pickPoint, const AcGeMatrix3d& viewXform, int& numPaths,
			AcDbFullSubentPath*& subentPaths, int numInserts = 0,
			AcDbObjectId* entAndInsertStack = nullptr);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus moveGripPointsAtSubentPaths(
			AcDbEntity* pSubject, const AcDbFullSubentPathArray& paths,
			const AcDbVoidPtrArray& gripAppData, const AcGeVector3d& offset, const int bitflags);
	ACDBCORE2D_PORT virtual void subentGripStatus(AcDbEntity* pSubject, const AcDb::GripStat status,
												  const AcDbFullSubentPath& subentity);
	ACDBCORE2D_PORT virtual AcDbEntity* subentPtr(const AcDbEntity* pSubject,
												  const AcDbFullSubentPath& id);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus transformSubentPathsBy(
			AcDbEntity* pSubject, const AcDbFullSubentPathArray& paths, const AcGeMatrix3d& xform);
};

#include "IcArxPackPop.h"

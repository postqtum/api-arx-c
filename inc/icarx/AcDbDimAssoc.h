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
***     Description: Declaration of AcDbDimAssoc class
***
*****************************************************************************/
#pragma once

#include "../dbmain.h"

class AcDbPointRef;
class AcDbRotatedDimension;
class AcDbAlignedDimension;
class AcDbRadialDimension;
class AcDbRadialDimensionLarge;
class AcDbDiametricDimension;
class AcDb2LineAngularDimension;
class AcDb3PointAngularDimension;
class AcDbOrdinateDimension;
class AcDbArcDimension;
class AcDbLeader;
class AcDbMLeader;

#include "IcArxPackPush.h"

class AcDbDimAssoc : public AcDbObject
{
public:
	enum
	{
		kMaxPointRefs = 4
	};

	enum AssocFlags
	{
		kFirstPointRef = 1,
		kSecondPointRef = 2,
		kThirdPointRef = 4,
		kFourthPointRef = 8
	};

	enum PointType
	{
		kXline1Point = 0,
		kXline2Point = 1,
		kOriginPoint = 0,
		kDefiningPoint = 1,
		kXline1Start = 0,
		kXline1End = 1,
		kXline2Start = 2,
		kXline2End = 3,
		kVertexPoint = 2,
		kChordPoint = 0,
		kCenterPoint = 1,
		kFarChordPoint = 1,
		kOverrideCenterPoint = 2,
		kAngLineStart = 2,
		kJogPoint = 3,
		kAngLineEnd = 3,
		kLeaderPoint = 0
	};

	enum RotatedDimType
	{
		kUnknown = 0,
		kParallel = 1,
		kPerpendicular = 2
	};

protected:
	Acad::ErrorStatus calculate2LineAngDimArcLocation(
			const AcGePoint3d* kpOldPts, const AcGePoint3d& kOldArcPt,
			const AcGePoint3d& kOldTextPt, const AcGePoint3d* kpNewPts, const AcGeVector3d& kNormal,
			AcGePoint3d& newArcPt, AcGePoint3d& newTextPt);
	Acad::ErrorStatus calculate3PointAngDimArcLocation(
			const AcGePoint3d* kpOldPts, const AcGePoint3d& kOldArcPt,
			const AcGePoint3d& kOldTextPt, const AcGePoint3d* kpNewPts, const AcGeVector3d& normal,
			AcGePoint3d& newArcPt, AcGePoint3d& newTextPt);
	bool isPointBetweenRays(const AcGePoint3d& vertex, const AcGePoint3d& firstPt,
							const AcGePoint3d& secondPt, const AcGePoint3d& angPt,
							const AcGeVector3d& normal);
	Acad::ErrorStatus removeDimExtDict(void);
	Acad::ErrorStatus setPointRefReactor(int ptType, bool isAdd = true);
	Acad::ErrorStatus updateDimLineAndTextLocation(AcDbRotatedDimension* pAlnDim,
												   const AcGePoint3d* kpOldPts,
												   const AcGePoint3d* kpNewPts);
	Acad::ErrorStatus updateDimLineAndTextLocation(AcDbAlignedDimension* pAlnDim,
												   const AcGePoint3d* pOldPts,
												   const AcGePoint3d* pNewPts);
	Acad::ErrorStatus updateDimLineAndTextLocation(AcDb2LineAngularDimension* pA2Dim,
												   const AcGePoint3d* pOldPts,
												   const AcGePoint3d* pNewPts);
	Acad::ErrorStatus updateDimLineAndTextLocation(AcDb3PointAngularDimension* pA3Dim,
												   const AcGePoint3d* pOldPts,
												   const AcGePoint3d* pNewPts);
	Acad::ErrorStatus updateDimLineAndTextLocation(AcDbArcDimension* pArcDim,
												   const AcGePoint3d* kpOldPts,
												   const AcGePoint3d* kpNewPts);
	Acad::ErrorStatus updateDimension(AcDbRotatedDimension* pRotDim, AcGePoint3d* pNewPts,
									  bool bUpdate = true);
	Acad::ErrorStatus updateDimension(AcDbAlignedDimension* pAlnDim, AcGePoint3d* pNewPts,
									  bool bUpdate = true);
	Acad::ErrorStatus updateDimension(AcDbRadialDimension* pRadDim, AcGePoint3d* pNewPts,
									  bool bUpdate = true);
	Acad::ErrorStatus updateDimension(AcDbRadialDimensionLarge* pRadDimLarge, AcGePoint3d* pNewPts,
									  bool bUpdate = true);
	Acad::ErrorStatus updateDimension(AcDbDiametricDimension* pDiaDim, AcGePoint3d* pNewPts,
									  bool bUpdate = true);
	Acad::ErrorStatus updateDimension(AcDb2LineAngularDimension* pA2Dim, AcGePoint3d* pNewPts,
									  bool bUpdate = true);
	Acad::ErrorStatus updateDimension(AcDb3PointAngularDimension* pA3Dim, AcGePoint3d* pNewPts,
									  bool bUpdate = true);
	Acad::ErrorStatus updateDimension(AcDbOrdinateDimension* pOrdDim, AcGePoint3d* pNewPts,
									  bool bUpdate = true);
	Acad::ErrorStatus updateDimension(AcDbArcDimension* pArcDim, AcGePoint3d* pNewPts,
									  bool bUpdate = true);
	Acad::ErrorStatus updateDimension(AcDbLeader* pLeader, AcGePoint3d* pNewPts,
									  bool bUpdate = true);
	Acad::ErrorStatus updateDimension(AcDbMLeader* pMLeader, AcGePoint3d* pNewPts,
									  bool bUpdate = true);

public:
	ACDB_DECLARE_MEMBERS(AcDbDimAssoc);

	AcDbDimAssoc();
	~AcDbDimAssoc();

	Acad::ErrorStatus addToDimensionReactor(bool isAdd = true);
	Acad::ErrorStatus addToPointRefReactor();
	bool assocFlag(int ptType) const;
	int assocFlag(void);
	AcDbObjectId dimObjId() const;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler*) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler*) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const override;
	Acad::ErrorStatus getDimAssocGeomIds(AcDbObjectIdArray& geomIds) const;
	bool hasOopsWatcher(void) const;
	bool isAllGeomErased() const;
	bool isTransSpatial() const;
	void modifiedGraphics(const AcDbEntity* pObj) override;
	const AcDbPointRef* pointRef(int ptType) const;
	Acad::ErrorStatus post(AcDbObjectId dimId, AcDbObjectId& dimAssocId, bool isActive = true);
	Acad::ErrorStatus removeAssociativity(bool force = true);
	void removeOopsWatcher(void);
	Acad::ErrorStatus removePointRef(int ptType);
	Acad::ErrorStatus restoreAssocFromOopsWatcher(void);
	RotatedDimType rotatedDimType() const;
	Acad::ErrorStatus setAssocFlag(int ptType, bool value);
	void setAssocFlag(int assocFlg);
	Acad::ErrorStatus setDimObjId(const AcDbObjectId& dimId);
	Acad::ErrorStatus setPointRef(int ptType, AcDbPointRef* ptRef);
	Acad::ErrorStatus setRotatedDimType(RotatedDimType dimType);
	Acad::ErrorStatus setTransSpatial(bool value);
	Acad::ErrorStatus startCmdWatcher();
	Acad::ErrorStatus startOopsWatcher(bool bAddAll = true);
	Acad::ErrorStatus swapReferences(const AcDbIdMapping& idMap) override;
	Acad::ErrorStatus updateAssociativity(const AcDbObjectIdArray& ids);
	Acad::ErrorStatus updateDimension(bool update = true, bool skipReactors = false);
	void updateDueToMirror(bool wasInMirror);
	Acad::ErrorStatus updateFillet(const AcDbObjectIdArray& ids);
	Acad::ErrorStatus updateSubentPath(AcDbIdMapping& idMap);
	Acad::ErrorStatus updateXrefSubentPath();
};

#include "IcArxPackPop.h"

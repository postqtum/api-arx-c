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
***     Description: AcDbCamera class declaration
***
*****************************************************************************/
#pragma once

#include "icarx/AcDbEntity.h"

#ifdef CAMERADLLIMPEXP
#	undef CAMERADLLIMPEXP
#endif
#ifdef ACCAMERA_EXPORTS
#	define CAMERADLLIMPEXP __declspec(dllexport)
#else
#	define CAMERADLLIMPEXP
#endif

class AcDbImpCamera;

#include "icarx/IcArxPackPush.h"
#pragma warning(disable : 4275 4251)

class CAMERADLLIMPEXP AcDbCamera : public AcDbEntity
{
	friend class AcDbSystemInternals;
	friend class AcDbImpCamera;

private:
	AcDbImpCamera* pImp = nullptr;

public:
	AcDbCamera();
	~AcDbCamera();
	ACDB_DECLARE_MEMBERS(AcDbCamera);

private:
	Acad::ErrorStatus baseDeepClone(AcDbObject* pOwner, AcDbObject*& pClonedObject,
									AcDbIdMapping& idMap, bool isPrimary) const;
	Acad::ErrorStatus baseGetStretchPoints(AcGePoint3dArray& stretchPoints) const;
	Acad::ErrorStatus baseHighlight(const AcDbFullSubentPath& subId,
									const bool highlightAll) const;
	Acad::ErrorStatus baseMoveStretchPointsAt(const AcDbIntArray& indices,
											  const AcGeVector3d& offset);
	Acad::ErrorStatus baseUnhighlight(const AcDbFullSubentPath& subId,
									  const bool highlightAll) const;
	Acad::ErrorStatus baseWblockClone(AcRxObject* pOwnerObject, AcDbObject*& pClonedObject,
									  AcDbIdMapping& idMap, bool isPrimary) const;
	uint32_t baseSetAttributes(AcGiDrawableTraits* pTraits);

protected:
	Acad::ErrorStatus subDeepClone(AcDbObject* pOwnerObject, AcDbObject*& pClonedObject,
								   AcDbIdMapping& idMap,
								   bool isPrimary = true) const;
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const;
	Acad::ErrorStatus subGetGeomExtents(AcDbExtents& extents) const;
	Acad::ErrorStatus subGetGripPoints(AcDbGripDataPtrArray& grips, const double curViewUnitSize,
									   const int gripSize, const AcGeVector3d& curViewDir,
									   const int bitflags) const;
	Acad::ErrorStatus subGetStretchPoints(AcGePoint3dArray& stretchPoints) const;
	Acad::ErrorStatus subHighlight(const AcDbFullSubentPath& subId = kNullSubent,
								   const bool highlightAll = false) const;
	Acad::ErrorStatus subMoveGripPointsAt(const AcDbVoidPtrArray& gripAppData,
										  const AcGeVector3d& offset, const int bitflags);
	Acad::ErrorStatus subMoveStretchPointsAt(const AcDbIntArray& indices,
											 const AcGeVector3d& offset);
	Acad::ErrorStatus subTransformBy(const AcGeMatrix3d& xform);
	Acad::ErrorStatus subUnhighlight(const AcDbFullSubentPath& subId = kNullSubent,
									 const bool highlightAll = false) const;
	Acad::ErrorStatus subWblockClone(AcRxObject* pOwnerObject, AcDbObject*& pClonedObject,
									 AcDbIdMapping& idMap,
									 bool isPrimary = true) const;
	bool subWorldDraw(AcGiWorldDraw* mode);
	uint32_t subSetAttributes(AcGiDrawableTraits* pTraits);
	void subList() const;
	void subViewportDraw(AcGiViewportDraw* mode);

public:
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* filer);
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* filer) const;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* filer);
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* filer) const;
	Acad::ErrorStatus setView(const AcDbObjectId viewId);
	Acad::ErrorStatus subClose();
	Acad::ErrorStatus subErase(bool erasing);
	Acad::ErrorStatus subOpen(AcDb::OpenMode openMode);
	AcDbObjectId view() const;
};

#include "icarx/IcArxPackPop.h"

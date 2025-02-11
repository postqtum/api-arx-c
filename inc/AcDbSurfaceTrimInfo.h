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
***     Description: Declaration of AcDbSurfaceTrimInfo class
***
*****************************************************************************/
#pragma once

#include "AcDbAssocEdgeActionParam.h"
#include "AcDbCompoundObjectId.h"

class ENTITY;

#include "icarx/IcArxPackPush.h"

class ACDB_PORT AcDbSurfaceTrimInfo
{
public:
	enum TrimRelation
	{
		outside_tool,
		inside_tool
	};

private:
	bool mbCurve = false;
	AcGeVector3d mProjVector = AcGeVector3d::kZAxis;
	AcDbCompoundObjectId mToolBodyId;
	AcDbSubentId mToolFaceSubentId;
	mutable ENTITY* mToolBody = nullptr;
	AcDbSurfaceTrimInfo::TrimRelation mRelation = outside_tool;

public:
	AcDbSurfaceTrimInfo();
	virtual ~AcDbSurfaceTrimInfo();

	AcDbSubentId faceSubentId() const;
	bool isCurve() const;
	AcGeVector3d projVector() const;
	AcDbSurfaceTrimInfo::TrimRelation relation() const;
	void setProjVector(const AcGeVector3d& projVector);
	void setRelation(AcDbSurfaceTrimInfo::TrimRelation relation);
	void setToolBody(ENTITY* pEntity);
	void setToolBodyId(const AcDbCompoundObjectId& toolId);
	void setTrimInfo(const AcDbCompoundObjectId& curveId, const AcGeVector3d& projVector,
					 AcDbSurfaceTrimInfo::TrimRelation relation);
	void setTrimInfo(ENTITY* pWireBody, const AcGeVector3d& projVector,
					 AcDbSurfaceTrimInfo::TrimRelation relation);
	void setTrimInfo(const AcDbCompoundObjectId& surfaceId,
					 AcDbSurfaceTrimInfo::TrimRelation relation, const AcDbSubentId& subentId);
	void setTrimInfo(ENTITY* pAsmBody, AcDbSurfaceTrimInfo::TrimRelation relation,
					 const AcDbSubentId& subentId);
	ENTITY* toolBody() const;
	AcDbCompoundObjectId toolBodyId() const;
};

#include "icarx/IcArxPackPop.h"

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
***     Description: Declaration of AcDb3dProfile class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../acarray.h"
#include "../AcDbGeomRef.h"

class AcDb3dProfileData;
class AcDbEntity;
class AcDbFullSubentPath;
class AcDbPathRef;
class AcDbVertexRef;

#include "IcArxPackPush.h"

class AcDb3dProfile : public AcRxObject
{
	friend class AcDb3dProfileData;
	friend class AcDbLoftProfile;

private:
	AcDb3dProfileData* mProfileData;

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDb3dProfile, ACDB_PORT);

	ACDB_PORT AcDb3dProfile();
	ACDB_PORT AcDb3dProfile(const AcDbFullSubentPath& faceSubentPath);
	ACDB_PORT AcDb3dProfile(const AcDbPathRef& pathRef);
	ACDB_PORT AcDb3dProfile(const AcDbVertexRef& vertexRef);
	ACDB_PORT AcDb3dProfile(AcDbEntity* pEntity);
	ACDB_PORT AcDb3dProfile(const AcDb3dProfile& src);
	ACDB_PORT ~AcDb3dProfile();
	ACDB_PORT AcDb3dProfile& operator=(const AcDb3dProfile& src);

	ACDB_PORT Acad::ErrorStatus convertProfile(bool explodeMultiFaceRegions,
											   bool convertSurfaceToEdges, bool nonPlanarOnly,
											   bool outerLoopOnly,
											   AcArray<AcDb3dProfile*>& convertedProfileArr) const;
	ACDB_PORT static AcDb3dProfile* convertProfile(const AcArray<AcDbPathRef>&);
	ACDB_PORT Acad::ErrorStatus copyFrom(const AcRxObject* src) override;
	ACDB_PORT AcDbEntity* entity() const;
	ACDB_PORT Acad::ErrorStatus getPathRef(AcDbPathRef& pathRef) const;
	ACDB_PORT Acad::ErrorStatus getVertexRef(AcDbVertexRef& vertexRef) const;
	ACDB_PORT bool isClosed() const;
	ACDB_PORT bool isEdge() const;
	ACDB_PORT bool isFace() const;
	ACDB_PORT bool isPlanar() const;
	ACDB_PORT bool isSubent() const;
	ACDB_PORT bool isValid() const;
	ACDB_PORT static Acad::ErrorStatus mergeProfiles(const AcArray<AcDb3dProfile*>& profileArr,
													 bool mergeEdges, bool mergeCurves,
													 AcArray<AcDb3dProfile*>& mergedProfileArr);

	ACDB_PORT Acad::ErrorStatus set(const AcDbPathRef& pathRef);
	ACDB_PORT Acad::ErrorStatus set(const AcDbVertexRef& vertexRef);
	ACDB_PORT Acad::ErrorStatus set(AcDbEntity* pEntity);
};

#include "IcArxPackPop.h"

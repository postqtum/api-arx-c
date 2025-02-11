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
***     Description:
***
*****************************************************************************/
#pragma once

#include "inc/adesk.h"
#include "inc/rxobject.h"
#include "inc/rxboiler.h"
#include "inc/gegbl.h"
#include "./brgbl.h"
#include "./brprops.h"

class AcDbFullSubentPath;
class AcGeBoundBlock3d;
class AcGePoint3d;
class AcGeLinearEnt3d;
class AcBrHit;
class AcBrBrep;
class OdBrEntity;
class AcBrBrepData;

#include "inc/icarx/IcArxPackPush.h"

class AcBrEntity : public AcRxObject
{
protected:
	OdBrEntity* mpImp = nullptr;

	AcBrEntity();
	AcBrEntity(const AcBrEntity& src);
	AcBrEntity& operator=(const AcBrEntity& src);

public:
	ACRX_DECLARE_MEMBERS(AcBrEntity);

	virtual ~AcBrEntity();
	bool brepChanged() const;
	bool checkEntity() const;
	AcBr::ErrorStatus get(AcDbFullSubentPath& path) const;
	AcBr::ErrorStatus get(AcBrBrepData*& data) const;
	void* getEntity() const;
	AcBr::ErrorStatus getBoundBlock(AcGeBoundBlock3d& block) const;
	AcBr::ErrorStatus getBrep(AcBrBrep& brep) const;
	AcBr::ErrorStatus getLineContainment(const AcGeLinearEnt3d& line,
										 const uint32_t& numHitsWanted,
										 uint32_t& numHitsFound, AcBrHit*& hits) const;
	AcBr::ErrorStatus getMassProps(AcBrMassProps& massProps,
								   const double& density = *(double*)nullptr,
								   const double& tolRequired = *(double*)nullptr,
								   double& tolAchieved = *(double*)nullptr) const;
	AcBr::ErrorStatus getPerimeterLength(double& length,
										 const double& tolRequired = *(double*)nullptr,
										 double& tolAchieved = *(double*)nullptr) const;
	AcBr::ErrorStatus getPointContainment(const AcGePoint3d& point,
										  AcGe::PointContainment& containment,
										  AcBrEntity*& container) const;
	AcBr::ErrorStatus getSubentPath(AcDbFullSubentPath& subPath) const;
	AcBr::ErrorStatus getSurfaceArea(double& area, const double& tolRequired = *(double*)nullptr,
									 double& tolAchieved = *(double*)nullptr) const;
	AcBr::ErrorStatus getValidationLevel(AcBr::ValidationLevel& level) const;
	AcBr::ErrorStatus getVolume(double& volume, const double& tolRequired = *(double*)nullptr,
								double& tolAchieved = *(double*)nullptr) const;
	bool isEqualTo(const AcRxObject* other) const;
	bool isNull() const;
	AcBr::ErrorStatus set(const AcDbFullSubentPath& path);
	AcBr::ErrorStatus set(AcBrBrepData* data);
	AcBr::ErrorStatus setEntity(void* pData,
								AcDbFullSubentPath& subPath = *(AcDbFullSubentPath*)nullptr);
	AcBr::ErrorStatus setSubentPath(AcDbFullSubentPath& subpath);
	AcBr::ErrorStatus setValidationLevel(
			const AcBr::ValidationLevel& level = *(AcBr::ValidationLevel*)nullptr);
};

#include "inc/icarx/IcArxPackPop.h"

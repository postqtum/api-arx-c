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

#include "acdbport.h"
#include "gevec3d.h"
#include "gepnt3d.h"
#include <memory>

class AcPointCloudExtractedCylinderImp;

#include "icarx/IcArxPackPush.h"

class ACDB_PORT AcPointCloudExtractedCylinder
{
private:
	std::unique_ptr<AcPointCloudExtractedCylinderImp> m_pImp;

public:
	const static AcPointCloudExtractedCylinder kInvalid;

public:
	AcPointCloudExtractedCylinder();
	AcPointCloudExtractedCylinder(double radius, double height,
								  AcGeVector3d axis = AcGeVector3d::kZAxis,
								  AcGePoint3d origin = AcGePoint3d::kOrigin);
	AcPointCloudExtractedCylinder(const AcPointCloudExtractedCylinder&);
	virtual ~AcPointCloudExtractedCylinder();
	AcPointCloudExtractedCylinder& operator=(const AcPointCloudExtractedCylinder&);
	bool operator==(const AcPointCloudExtractedCylinder&) const;
	bool operator!=(const AcPointCloudExtractedCylinder&) const;

	void clear();
	AcGeVector3d getAxis() const;
	double getHeight() const;
	AcGePoint3d getOrigin() const;
	double getRadius() const;
	bool isValid() const;
	void setAxis(AcGeVector3d axis);
	void setHeight(double height);
	void setOrigin(AcGePoint3d origin);
	void setRadius(double radius);
};

#include "icarx/IcArxPackPop.h"

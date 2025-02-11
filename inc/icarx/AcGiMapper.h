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
***     Description: Declaration of AcGiMapper classes
***
*****************************************************************************/
#pragma once

#include "../acgiparameter.h"
#include "AcGiMaterialDefs.h"

class AcGiImpMapper;

#include "IcArxPackPush.h"

class AcGiMapper : public AcGiParameter
{
public:
	enum AutoTransform
	{
		kInheritAutoTransform = 0x0,
		kNone = 0x1,
		kObject = 0x2,
		kModel = 0x4
	};

	enum Projection
	{
		kInheritProjection = 0,
		kPlanar,
		kBox,
		kCylinder,
		kSphere
	};

	enum Tiling
	{
		kInheritTiling = 0,
		kTile,
		kCrop,
		kClamp,
		kMirror,
	};

public:
	ACGIMAT_IMPEXP static const AcGiMapper kIdentity;

public:
	ACRX_DECLARE_MEMBERS_READWRITE(AcGiMapper, AcGiImpMapper);

	ACDBCORE2D_PORT AcGiMapper();
	ACDBCORE2D_PORT AcGiMapper(const AcGiMapper& mapper);
	ACDBCORE2D_PORT ~AcGiMapper();
	ACDBCORE2D_PORT AcGiMapper& operator=(const AcGiMapper& mapper);
	ACDBCORE2D_PORT bool operator==(const AcGiMapper& mapper) const;
	bool operator!=(const AcGiMapper& mapper) const { return !(*this == mapper); };

	virtual AutoTransform autoTransform() const;
	virtual Projection projection() const;
	virtual void set(const AcGiMapper& mapper);
	ACDBCORE2D_PORT virtual void setAutoTransform(AutoTransform autoTransform);
	ACDBCORE2D_PORT virtual void setProjection(Projection projection);
	ACDBCORE2D_PORT virtual void setTransform(const AcGeMatrix3d& transform);
	ACDBCORE2D_PORT void setUTiling(Tiling tiling);
	ACDBCORE2D_PORT void setVTiling(Tiling tiling);
	virtual const AcGeMatrix3d& transform() const;
	ACDBCORE2D_PORT Tiling uTiling() const;
	Tiling vTiling() const;
};

#include "IcArxPackPop.h"

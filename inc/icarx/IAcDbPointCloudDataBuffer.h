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
***     Description: Declaration of IAcDbPointCloudDataBuffer interface
***
*****************************************************************************/
#pragma once

#include "../gepnt3d.h"
#include "../gevec3d.h"

#include "IcArxPackPush.h"

class __declspec(novtable) IAcDbPointCloudDataBuffer
{
public:
	enum DataType
	{
		kIntensity = 1,
		kClassification = 2,
		kColor = 4,
		kNormal = 8
	};

	typedef uint8_t RGBA[4];

public:
	virtual ~IAcDbPointCloudDataBuffer() = 0 {}

	virtual const uint8_t* classifications() const = 0;
	virtual const IAcDbPointCloudDataBuffer::RGBA* colors() const = 0;
	virtual void freeObject() = 0;
	virtual void* getBuffer() const = 0;
	virtual const uint8_t* intensity() const = 0;
	virtual const AcGeVector3d* normals() const = 0;
	virtual uint64_t numPoints() const = 0;
	virtual const AcGePoint3d* points() const = 0;
	virtual const AcGeMatrix3d& transform() const = 0;
};

#include "IcArxPackPop.h"

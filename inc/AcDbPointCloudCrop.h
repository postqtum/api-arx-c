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
***     Description: Declaration of AcDbPointCloudCrop class
***
*****************************************************************************/
#pragma once

#include <cstdint>

#include "acdbport.h"
#include "acadstrc.h"
#include "gept3dar.h"
#include "geplane.h"

namespace Autodesk
{
namespace RealityStudio
{
namespace SDK
{
namespace Interface
{
class ARCSpatialFilter;
}
}  // namespace SDK
}  // namespace RealityStudio
};	// namespace Autodesk

class AcDbDwgFiler;
class AcDbDxfFiler;
class AcGiGeometry;
class AcDbPointCloudDxfHandler;

#include "icarx/IcArxPackPush.h"

class ACDB_PORT AcDbPointCloudCrop
{
public:
	enum CropType
	{
		kInvalid = 0,
		kRectangular,
		kPolygonal,
		kCircular
	};

private:
	AcDbPointCloudCrop::CropType m_cropType;
	bool m_isInside;
	bool m_isInverted;
	AcGePlane m_cropPlane;
	AcGePoint3dArray m_point3dArray;
	AcDbPointCloudDxfHandler* m_dxfHandler;

public:
	AcDbPointCloudCrop();
	AcDbPointCloudCrop(const AcDbPointCloudCrop& other);
	virtual ~AcDbPointCloudCrop();
	AcDbPointCloudCrop& operator=(const AcDbPointCloudCrop& other);
	bool operator==(const AcDbPointCloudCrop& other) const;
	bool operator!=(const AcDbPointCloudCrop& other) const;

	void clear();
	virtual void draw(AcGiGeometry& geom);
	virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler);
	virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const;
	virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler, int16_t& dxfInt8, int16_t& dxfInt32,
										  int16_t& dxfXCoord, int16_t& dxfNormalX);
	virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler, int16_t& dxfInt8,
										   int16_t& dxfInt32, int16_t& dxfXCoord,
										   int16_t& dxfNormalX) const;
	const AcGePoint3dArray& get();
	bool getCropPlane(AcGePlane& plane);
	bool isInside() const;
	bool isInverted() const;
	bool isValid() const;
	int length() const;
	void set(const AcGePoint3dArray& points);
	void setCropPlane(const AcGePlane& plane);
	void setCropType(AcDbPointCloudCrop::CropType type);
	void setDxfHandler(AcDbPointCloudDxfHandler* dxfHandler);
	void setInside(bool bInside);
	void setInvert(bool toInvert);
	virtual Autodesk::RealityStudio::SDK::Interface::ARCSpatialFilter* toSpatialFilter() const;
	AcDbPointCloudCrop::CropType type() const;
};

#include "icarx/IcArxPackPop.h"

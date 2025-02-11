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
***     Description: Declaration of AcDbPointCloudDefEx class
***
*****************************************************************************/
#pragma once

#include <tchar.h>

#include "../AcString.h"

#include "AcDbObject.h"

typedef struct tagBITMAPINFO BITMAPINFO;

static const TCHAR* kpPointCloudExDictionaryName = /*NOXLATE*/ ACRX_T("ACAD_POINTCLOUD_EX_DICT");

class PointCloudDefExImp;

namespace Autodesk
{
namespace RealityStudio
{
namespace SDK
{
namespace Interface
{
class IRCData;
}
}  // namespace SDK
}  // namespace RealityStudio
}  // namespace Autodesk

#include "IcArxPackPush.h"

class ACDB_PORT AcDbPointCloudDefEx : public AcDbObject
{
public:
	enum PropState
	{
		kNone = -1,
		kSome = 0,
		kAll = 1
	};

	enum Property
	{
		kColor = 1,
		kIntensity = 2,
		kClassification = 3,
		kNormal = 4,
		kSegmentation = 5,
		kGeoGraphic = 6
	};

private:
	PointCloudDefExImp* m_pImp = nullptr;
	static int m_nVersion;

public:
	ACRX_DECLARE_MEMBERS(AcDbPointCloudDefEx);

	AcDbPointCloudDefEx();
	~AcDbPointCloudDefEx();

	const TCHAR* activeFileName() const;
	static int classVersion();
	const TCHAR* coordinateSystemName() const;
	static Acad::ErrorStatus createPointCloudExDictionary(AcDbDatabase* pDb, AcDbObjectId& dictId);
	Acad::ErrorStatus createThumbnailBitmap(BITMAPINFO*& pBmpInfo, int width, int height) const;
	double defaultHeight() const;
	double defaultLength() const;
	double defaultWidth() const;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	int entityCount(bool* pbLocked = 0) const;
	AcDbExtents extents() const;
	const TCHAR* fileType() const;
	void getAllRcsFilePaths(AcStringArray& list) const;
	static AcDbDictionary* getPointCloudExDictionary(AcDbPointCloudDefEx* pDefEx);
	Autodesk::RealityStudio::SDK::Interface::IRCData* getRCData();
	const TCHAR* getRcsFilePath(const AcString& guid) const;
	AcDbPointCloudDefEx::PropState hasProperty(AcDbPointCloudDefEx::Property prop) const;
	bool isLoaded() const;
	Acad::ErrorStatus load();
	static AcDbObjectId pointCloudExDictionary(AcDbDatabase* pDb);
	Acad::ErrorStatus setActiveFileName(const TCHAR* pPathName);
	Acad::ErrorStatus setSourceFileName(const TCHAR* pPathName);
	const TCHAR* sourceFileName() const;
	Acad::ErrorStatus subErase(bool erasing) override;
	unsigned long long totalPointsCount() const;
	int totalRegionsCount() const;
	int totalScansCount() const;
	Acad::ErrorStatus unload();
};

#include "IcArxPackPop.h"

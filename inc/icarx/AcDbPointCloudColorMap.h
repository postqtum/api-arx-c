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
***     Description: Declaration of AcDbPointCloudColorMap class
***
*****************************************************************************/
#pragma once

#include "../acdbport.h"
#include "../AcString.h"

#include "AcDbObject.h"

class AcPointCloudColorSchemeCollectionReactor;
class AcDbPointCloudColorRamp;
class AcDbPointCloudClassificationColorRamp;
class PointCloudColorMapImp;

#include "IcArxPackPush.h"

class ACDB_PORT AcDbPointCloudColorMap : public AcDbObject
{
	friend class PointCloudColorMapImp;

private:
	static const uint16_t kCurrentObjectVersion;

private:
	AcDbPointCloudColorMap();

public:
	ACRX_DECLARE_MEMBERS(AcDbPointCloudColorMap);
	~AcDbPointCloudColorMap();

	void addColorSchemeCollectionReactor(AcPointCloudColorSchemeCollectionReactor* pReactor);
	bool classificationScheme(const wchar_t* GUID,
							  AcDbPointCloudClassificationColorRamp& target) const;
	AcArray<AcString> classificationSchemeGUIDs() const;
	bool colorScheme(const wchar_t* GUID, AcDbPointCloudColorRamp& target) const;
	AcArray<AcString> colorSchemeGUIDs() const;
	const AcString defaultClassificationColorScheme() const;
	const AcString defaultElevationColorScheme() const;
	const AcString defaultIntensityColorScheme() const;
	bool deleteClassificationScheme(const wchar_t* GUID);
	bool deleteColorScheme(const wchar_t* GUID);
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	void getClassificationColorSchemeInUse(AcArray<AcString>& GUIDs) const;
	static Acad::ErrorStatus getColorMap(AcDbObjectId& id, AcDbDatabase* pDb,
										 bool bCreateIfNone = true);
	void getColorSchemeInUse(AcArray<AcString>& GUIDs) const;
	bool hasClassificationScheme(const wchar_t* GUID) const;
	bool hasColorScheme(const wchar_t* GUID) const;
	void notifyColorSchemeCollectionChanged() const;
	void removeColorSchemeCollectionReactor(AcPointCloudColorSchemeCollectionReactor* pReactor);
	bool setClassificationScheme(const wchar_t* GUID,
								 const AcDbPointCloudClassificationColorRamp& source);
	bool setColorScheme(const wchar_t* GUID, const AcDbPointCloudColorRamp& source);
	bool setDefaultClassificationColorScheme(const AcString GUID);
	bool setDefaultElevationColorScheme(const AcString GUID);
	bool setDefaultIntensityColorScheme(const AcString GUID);
	Acad::ErrorStatus subClose() override;
};

#include "IcArxPackPop.h"

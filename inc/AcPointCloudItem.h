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

#include "acarray.h"
#include "adsdef.h"
#include "AcString.h"
#include "acdbport.h"

class AcPointCloudItem;
using PPointCloudItem = AcPointCloudItem*;
using AcPointCloudItemArray = AcArray<AcPointCloudItem*>;

#include "icarx/IcArxPackPush.h"

class ACDB_PORT AcPointCloudItem
{
public:
	enum AcPointCloudItemType
	{
		kLegacyPointCloud = 0,
		kPointCloudProject,
		kIndividualScan,
		kScan,
		kRegion,
		kScanRootGroup,
		kRegionRootGroup,
		kUnassignedPoint
	};

private:
	AcString m_name;
	AcString m_projectName;
	AcString m_guid;
	int m_id = 0;
	bool m_visibility = true;
	bool m_highlight = false;
	ads_name m_adsName = {0, 0};
	float m_red = 0.0;
	float m_green = 0.0;
	float m_blue = 0.0;
	AcPointCloudItemType m_itemType = kPointCloudProject;

public:
	AcPointCloudItem() = default;
	AcPointCloudItem(const AcString& name, const AcString& projectname, int objectid,
					 AcPointCloudItemType categoryid, bool visibility = true,
					 bool highlight = false, AcString guid = L"");
	AcPointCloudItem(const AcPointCloudItem& item) = default;
	~AcPointCloudItem() = default;
	AcPointCloudItem& operator=(const AcPointCloudItem& other) = default;

	static AcPointCloudItem* CreateFromCmdString(const ACHAR* cmd);
	const ads_name& adsName() const;
	float blue() const;
	float green() const;
	const AcString& guid() const;
	bool highlight() const;
	int id() const;
	AcPointCloudItemType itemType() const;
	AcString name() const;
	AcString projectName() const;
	float red() const;
	void setAdsName(const ads_name& val);
	void setColor(float red, float green, float blue);
	void setGuid(const AcString& val);
	void setHighlight(bool val);
	void setId(int val);
	void setItemType(AcPointCloudItemType val);
	void setName(const AcString& val);
	void setProjectName(const AcString& val);
	void setVisibility(bool val);
	bool visibility() const;
};

#include "icarx/IcArxPackPop.h"

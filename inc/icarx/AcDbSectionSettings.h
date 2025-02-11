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
***     Description: Declaration of AcDbSectionSettings class
***
*****************************************************************************/
#pragma once

#include "../dbmain.h"
#include "../dbhatch.h"

#include "IcArxPackPush.h"

class AcDbSectionSettings : public AcDbObject
{
public:
	enum Generation
	{
		kSourceAllObjects = (0x1 << 0),
		kSourceSelectedObjects = (0x1 << 1),
		kDestinationNewBlock = (0x1 << 4),
		kDestinationReplaceBlock = (0x1 << 5),
		kDestinationFile = (0x1 << 6),
	};

	enum Geometry
	{
		kIntersectionBoundary = (0x1 << 0),
		kIntersectionFill = (0x1 << 1),
		kBackgroundGeometry = (0x1 << 2),
		kForegroundGeometry = (0x1 << 3),
		kCurveTangencyLines = (0x1 << 4),
	};

	enum SectionType
	{
		kLiveSection = (0x1 << 0),
		k2dSection = (0x1 << 1),
		k3dSection = (0x1 << 2),
	};

protected:
	ACDB_PORT Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbSectionSettings);

	AcDbSectionSettings();
	~AcDbSectionSettings();

	ACDB_PORT AcCmColor color(AcDbSectionSettings::SectionType nSecType,
							  AcDbSectionSettings::Geometry nGeometry) const;
	ACDB_PORT AcDbSectionSettings::SectionType currentSectionType() const;
	ACDB_PORT AcDbObjectId destinationBlock(AcDbSectionSettings::SectionType nSecType) const;
	ACDB_PORT const ACHAR* destinationFile(AcDbSectionSettings::SectionType nSecType) const;
	ACDB_PORT bool divisionLines(AcDbSectionSettings::SectionType nSecType,
								 AcDbSectionSettings::Geometry nGeometry) const;
	ACDB_PORT int edgeTransparency(AcDbSectionSettings::SectionType nSecType,
								   AcDbSectionSettings::Geometry nGeometry) const;
	ACDB_PORT int faceTransparency(AcDbSectionSettings::SectionType nSecType,
								   AcDbSectionSettings::Geometry nGeometry) const;
	ACDB_PORT AcDbSectionSettings::Generation generationOptions(
			AcDbSectionSettings::SectionType nSecType) const;
	ACDB_PORT Acad::ErrorStatus getHatchPattern(AcDbSectionSettings::SectionType nSecType,
												AcDbSectionSettings::Geometry nGeometry,
												AcDbHatch::HatchPatternType& nPatternType,
												const ACHAR*& pszPatternName) const;
	ACDB_PORT Acad::ErrorStatus getSourceObjects(AcDbSectionSettings::SectionType nSecType,
												 AcDbObjectIdArray& ids) const;
	ACDB_PORT double hatchAngle(AcDbSectionSettings::SectionType nSecType,
								AcDbSectionSettings::Geometry nGeometry) const;
	ACDB_PORT double hatchScale(AcDbSectionSettings::SectionType nSecType,
								AcDbSectionSettings::Geometry nGeometry) const;
	ACDB_PORT double hatchSpacing(AcDbSectionSettings::SectionType nSecType,
								  AcDbSectionSettings::Geometry nGeometry) const;
	ACDB_PORT bool hatchVisibility(AcDbSectionSettings::SectionType nSecType,
								   AcDbSectionSettings::Geometry nGeometry) const;
	ACDB_PORT bool hiddenLine(AcDbSectionSettings::SectionType nSecType,
							  AcDbSectionSettings::Geometry nGeometry) const;
	ACDB_PORT const ACHAR* layer(AcDbSectionSettings::SectionType nSecType,
								 AcDbSectionSettings::Geometry nGeometry) const;
	ACDB_PORT AcDb::LineWeight lineWeight(AcDbSectionSettings::SectionType nSecType,
										  AcDbSectionSettings::Geometry nGeometry) const;
	ACDB_PORT const ACHAR* linetype(AcDbSectionSettings::SectionType nSecType,
									AcDbSectionSettings::Geometry nGeometry) const;
	ACDB_PORT double linetypeScale(AcDbSectionSettings::SectionType nSecType,
								   AcDbSectionSettings::Geometry nGeometry) const;
	ACDB_PORT const ACHAR* plotStyleName(AcDbSectionSettings::SectionType nSecType,
										 AcDbSectionSettings::Geometry nGeometry) const;
	ACDB_PORT Acad::ErrorStatus reset();
	ACDB_PORT Acad::ErrorStatus reset(AcDbSectionSettings::SectionType nSecType);
	ACDB_PORT Acad::ErrorStatus setColor(AcDbSectionSettings::SectionType nSecType,
										 AcDbSectionSettings::Geometry nGeometry,
										 const AcCmColor& color);
	ACDB_PORT Acad::ErrorStatus setCurrentSectionType(AcDbSectionSettings::SectionType nSecType);
	ACDB_PORT Acad::ErrorStatus setDestinationBlock(AcDbSectionSettings::SectionType nSecType,
													const AcDbObjectId& id);
	ACDB_PORT Acad::ErrorStatus setDestinationFile(AcDbSectionSettings::SectionType nSecType,
												   const ACHAR* pszFileName);
	ACDB_PORT Acad::ErrorStatus setDivisionLines(AcDbSectionSettings::SectionType nSecType,
												 AcDbSectionSettings::Geometry nGeometry,
												 bool bShow);
	ACDB_PORT Acad::ErrorStatus setEdgeTransparency(AcDbSectionSettings::SectionType nSecType,
													AcDbSectionSettings::Geometry nGeometry,
													int nTransparency);
	ACDB_PORT Acad::ErrorStatus setFaceTransparency(AcDbSectionSettings::SectionType nSecType,
													AcDbSectionSettings::Geometry nGeometry,
													int nTransparency);
	ACDB_PORT Acad::ErrorStatus setGenerationOptions(AcDbSectionSettings::SectionType nSecType,
													 AcDbSectionSettings::Generation nOptions);
	ACDB_PORT Acad::ErrorStatus setHatchAngle(AcDbSectionSettings::SectionType nSecType,
											  AcDbSectionSettings::Geometry nGeometry,
											  double fAngle);
	ACDB_PORT Acad::ErrorStatus setHatchPattern(AcDbSectionSettings::SectionType nSecType,
												AcDbSectionSettings::Geometry nGeometry,
												AcDbHatch::HatchPatternType nPatternType,
												const ACHAR* pszPatternName);
	ACDB_PORT Acad::ErrorStatus setHatchScale(AcDbSectionSettings::SectionType nSecType,
											  AcDbSectionSettings::Geometry nGeometry,
											  double fScale);
	ACDB_PORT Acad::ErrorStatus setHatchSpacing(AcDbSectionSettings::SectionType nSecType,
												AcDbSectionSettings::Geometry nGeometry,
												double fSpacing);
	ACDB_PORT Acad::ErrorStatus setHatchVisibility(AcDbSectionSettings::SectionType nSecType,
												   AcDbSectionSettings::Geometry nGeometry,
												   bool bVisible);
	ACDB_PORT Acad::ErrorStatus setHiddenLine(AcDbSectionSettings::SectionType nSecType,
											  AcDbSectionSettings::Geometry nGeometry,
											  bool bHiddenLine);
	ACDB_PORT Acad::ErrorStatus setLayer(AcDbSectionSettings::SectionType nSecType,
										 AcDbSectionSettings::Geometry nGeometry,
										 const ACHAR* pszLayer);
	ACDB_PORT Acad::ErrorStatus setLineWeight(AcDbSectionSettings::SectionType nSecType,
											  AcDbSectionSettings::Geometry nGeometry,
											  AcDb::LineWeight nLineWeight);
	ACDB_PORT Acad::ErrorStatus setLinetype(AcDbSectionSettings::SectionType nSecType,
											AcDbSectionSettings::Geometry nGeometry,
											const ACHAR* pszLinetype);
	ACDB_PORT Acad::ErrorStatus setLinetypeScale(AcDbSectionSettings::SectionType nSecType,
												 AcDbSectionSettings::Geometry nGeometry,
												 double fScale);
	ACDB_PORT Acad::ErrorStatus setPlotStyleName(AcDbSectionSettings::SectionType nSecType,
												 AcDbSectionSettings::Geometry nGeometry,
												 const ACHAR* pszPlotStyleName);
	ACDB_PORT Acad::ErrorStatus setSourceObjects(AcDbSectionSettings::SectionType nSecType,
												 const AcDbObjectIdArray& ids);
	ACDB_PORT Acad::ErrorStatus setVisibility(AcDbSectionSettings::SectionType nSecType,
											  AcDbSectionSettings::Geometry nGeometry,
											  bool bVisible);
	ACDB_PORT bool visibility(AcDbSectionSettings::SectionType nSecType,
							  AcDbSectionSettings::Geometry nGeometry) const;
};

#include "IcArxPackPop.h"

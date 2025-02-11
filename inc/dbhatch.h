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
***     Description: Declaration of AcDbHatch class
***
*****************************************************************************/
#pragma once

#include "acdb.h"
#include "dbmain.h"
#include "gelnsg2d.h"
#include "gelnsg3d.h"
#include "gearc2d.h"
#include "gearc3d.h"
#include "gept2dar.h"
#include "gevptar.h"
#include "geintarr.h"

#define GRADIENT_COLOR_NAME_LENGTH 256
#define GRADIENT_PATTERN_NAME_LENGTH 32

#undef HATCH_PATTERN_NAME_LENGTH
#define HATCH_PATTERN_NAME_LENGTH 35

class AcDbRegion;

#include "icarx/IcArxPackPush.h"

class AcDbHatch : public AcDbEntity
{
public:
	enum GradientPatternType
	{
		kPreDefinedGradient = 0,
		kUserDefinedGradient = 1
	};

	enum HatchEdgeType
	{
		kLine = 1,
		kCirArc = 2,
		kEllArc = 3,
		kSpline = 4
	};

	enum HatchLoopType
	{
		kDefault = 0,
		kExternal = 1,
		kPolyline = 2,
		kDerived = 4,
		kTextbox = 8,
		kOutermost = 0x10,
		kNotClosed = 0x20,
		kSelfIntersecting = 0x40,
		kTextIsland = 0x80,
		kDuplicate = 0x100,
		kIsAnnotative = 0x200,
		kDoesNotSupportScale = 0x400,
		kForceAnnoAllVisible = 0x800,
		kOrientToPaper = 0x1000,
		kIsAnnotativeBlock = 0x2000
	};

	enum HatchObjectType
	{
		kHatchObject = 0,
		kGradientObject = 1
	};

	enum HatchPatternType
	{
		kUserDefined = 0,
		kPreDefined = 1,
		kCustomDefined = 2
	};

	enum HatchStyle
	{
		kNormal = 0,
		kOuter = 1,
		kIgnore = 2
	};

protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	AcDbHatch();
	~AcDbHatch();

	ACDB_DECLARE_MEMBERS(AcDbHatch);

	Acad::ErrorStatus appendLoop(int32_t loopType, const AcGeVoidPointerArray& edgePtrs,
								 const AcGeIntArray& edgeTypes);
	Acad::ErrorStatus appendLoop(int32_t loopType, const AcGePoint2dArray& vertices,
								 const AcGeDoubleArray& bulges);
	Acad::ErrorStatus appendLoop(int32_t loopType, const AcDbObjectIdArray& dbObjIds);
	bool associative() const;
	AcCmColor backgroundColor() const;
	double elevation() const;
	Acad::ErrorStatus evaluateGradientColorAt(float value, AcCmColor& color);
	Acad::ErrorStatus evaluateHatch(bool bUnderestimateNumLines = false);
	Acad::ErrorStatus evaluateHatchAllScales(bool bUnderestimateNumLines = false);
	Acad::ErrorStatus getArea(double& a) const;
	Acad::ErrorStatus getAssocObjIds(AcDbObjectIdArray& dbObjIds) const;
	Acad::ErrorStatus getAssocObjIdsAt(int loopIndex, AcDbObjectIdArray& dbObjIds) const;
	Acad::ErrorStatus getGradientColors(unsigned int& count, AcCmColor*& colors, float*& values);
	bool getGradientOneColorMode() const;
	Acad::ErrorStatus getHatchLineDataAt(int index, AcGePoint2d& startPt, AcGePoint2d& endPt) const;
	Acad::ErrorStatus getHatchLinesData(AcGePoint2dArray& startPts, AcGePoint2dArray& endPts) const;
	Acad::ErrorStatus getLoopAt(int loopIndex, int32_t& loopType, AcGeVoidPointerArray& edgePtrs,
								AcGeIntArray& edgeTypes) const;
	Acad::ErrorStatus getLoopAt(int loopIndex, int32_t& loopType, AcGePoint2dArray& vertices,
								AcGeDoubleArray& bulges) const;
	Acad::ErrorStatus getPatternDefinitionAt(int index, double& angle, double& baseX, double& baseY,
											 double& offsetX, double& offsetY,
											 AcGeDoubleArray& dashes) const;
	Acad::ErrorStatus getPlane(AcGePlane&, AcDb::Planarity&) const override;
	AcDbRegion* getRegionArea() const;
	float getShadeTintValue() const;
	double gradientAngle() const;
	const ACHAR* gradientName() const;
	float gradientShift() const;
	AcDbHatch::GradientPatternType gradientType() const;
	AcDbHatch::HatchObjectType hatchObjectType() const;
	AcDbHatch::HatchStyle hatchStyle() const;
	Acad::ErrorStatus insertLoopAt(int loopIndex, int32_t loopType,
								   const AcGeVoidPointerArray& edgePtrs,
								   const AcGeIntArray& edgeTypes);
	Acad::ErrorStatus insertLoopAt(int loopIndex, int32_t loopType,
								   const AcGePoint2dArray& vertices, const AcGeDoubleArray& bulges);
	Acad::ErrorStatus insertLoopAt(int loopIndex, int32_t loopType,
								   const AcDbObjectIdArray& dbObjIds);
	virtual bool isGradient() const;
	virtual bool isHatch() const;
	bool isPlanar() const override { return true; }
	bool isSolidFill() const;
	bool lineGenerationEnabled() const;
	int32_t loopTypeAt(int loopIndex) const;
	void modifiedGraphics(const AcDbEntity* pObj) override;
	AcGeVector3d normal() const;
	int numHatchLines() const;
	int numLoops() const;
	int numPatternDefinitions() const;
	AcGePoint2d originPoint() const;
	double patternAngle() const;
	bool patternDouble() const;
	ACDBCORE2D_PORT const ACHAR (&patternName() const)[HATCH_PATTERN_NAME_LENGTH];
	double patternScale() const;
	double patternSpace() const;
	AcDbHatch::HatchPatternType patternType() const;
	Acad::ErrorStatus removeAssocObjIds();
	void removeHatchLines();
	Acad::ErrorStatus removeLoopAt(int loopIndex);
	Acad::ErrorStatus setAssociative(bool isAssociative);
	Acad::ErrorStatus setBackgroundColor(const AcCmColor& color);
	Acad::ErrorStatus setElevation(double elevation);
	Acad::ErrorStatus setGradient(AcDbHatch::GradientPatternType gradType, const ACHAR* gradName);
	Acad::ErrorStatus setGradientAngle(double angle);
	Acad::ErrorStatus setGradientColors(unsigned int count, AcCmColor* colors, float* values);
	Acad::ErrorStatus setGradientOneColorMode(bool oneColorMode);
	Acad::ErrorStatus setGradientShift(float shiftValue);
	Acad::ErrorStatus setHatchObjectType(AcDbHatch::HatchObjectType type);
	Acad::ErrorStatus setHatchStyle(AcDbHatch::HatchStyle hstyle);
	bool setLineGenerationEnabled(bool bEnable);
	Acad::ErrorStatus setNormal(const AcGeVector3d& normal);
	Acad::ErrorStatus setOriginPoint(const AcGePoint2d& pt);
	Acad::ErrorStatus setPattern(AcDbHatch::HatchPatternType patType, const ACHAR* patName);
	Acad::ErrorStatus setPatternAngle(double angle);
	Acad::ErrorStatus setPatternDouble(bool isDouble);
	Acad::ErrorStatus setPatternScale(double scale);
	Acad::ErrorStatus setPatternSpace(double space);
	Acad::ErrorStatus setShadeTintValue(float value);
	Acad::ErrorStatus setShadeTintValueAndColor2(float value);
	Acad::ErrorStatus subSwapIdWith(AcDbObjectId otherId, bool swapXdata = false,
									bool swapExtDict = false) override;
	Acad::ErrorStatus swapReferences(const AcDbIdMapping& idMap) override;
};

#include "icarx/IcArxPackPop.h"

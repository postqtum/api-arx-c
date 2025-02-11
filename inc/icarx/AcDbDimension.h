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
***     Description: Declaration of AcDbDimension class
***
*****************************************************************************/
#pragma once

#include "../dbmtext.h"

#include "AcDbEntity.h"

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcDbDimension : public AcDbEntity
{
	friend class AcDbDimensionStyleOverrule;

public:
	enum CenterMarkType
	{
		kMark = 0,
		kLine = 1,
		kNone = 2
	};

	enum DimInspect
	{
		kShapeRemove = 0,
		kShapeRound = 1,
		kShapeAngular = 2,
		kShapeNone = 4,
		kShapeLabel = 0x10,
		kShapeRate = 0x20,
	};

protected:
	AcDbDimension();

	AcDbObjectId subDimensionStyle() const;
	Acad::ErrorStatus subGetDimstyleData(AcDbDimStyleTableRecord*& pRecord) const;
	Acad::ErrorStatus subSetDimensionStyle(AcDbObjectId dimStyleId);
	Acad::ErrorStatus subSetDimstyleData(AcDbDimStyleTableRecord* pNewData);
	Acad::ErrorStatus subSetDimstyleData(AcDbObjectId newDataId);

public:
	~AcDbDimension();

	ACDB_DECLARE_MEMBERS(AcDbDimension);

	ACDBCORE2D_PORT bool altSuppressLeadingZeros() const;
	ACDBCORE2D_PORT bool altSuppressTrailingZeros() const;
	ACDBCORE2D_PORT bool altSuppressZeroFeet() const;
	ACDBCORE2D_PORT bool altSuppressZeroInches() const;
	ACDBCORE2D_PORT bool altToleranceSuppressLeadingZeros() const;
	ACDBCORE2D_PORT bool altToleranceSuppressTrailingZeros() const;
	ACDBCORE2D_PORT bool altToleranceSuppressZeroFeet() const;
	ACDBCORE2D_PORT bool altToleranceSuppressZeroInches() const;
	ACDBCORE2D_PORT Acad::ErrorStatus alternatePrefix(AcString&) const;
	ACDBCORE2D_PORT Acad::ErrorStatus alternateSuffix(AcString&) const;
	AcGeMatrix3d blockTransform() const;
	ACDBCORE2D_PORT double centerMarkSize() const;
	ACDBCORE2D_PORT AcDbDimension::CenterMarkType centerMarkType() const;
	AcDbObjectId dimBlockId() const;
	AcGePoint3d dimBlockPosition() const;
	AcDbObjectId dimExt1Linetype() const;
	AcDbObjectId dimExt2Linetype() const;
	AcDbObjectId dimLineLinetype() const;
	AcDbObjectId dimensionStyle() const;
	ACDBCORE2D_PORT Acad::ErrorStatus dimensionText(AcString& sDimText) const;
	ACHAR* dimensionText() const;
	int dimfit() const;
	int dimunit() const;
	void dragStatus(const AcDb::DragStat status) override;
	double elevation() const;
	virtual void erased(AcDbObject* dbObj, bool bErasing);
	Acad::ErrorStatus fieldFromMText(AcDbMText* pDimMText);
	Acad::ErrorStatus fieldToMText(AcDbMText* pDimMText);
	ACDBCORE2D_PORT
	Acad::ErrorStatus formatMeasurement(AcString& sMTextContent, double measurement,
										const ACHAR* dimensionText = nullptr);
	Acad::ErrorStatus formatMeasurement(ACHAR* MTextContentBuffer, size_t contentBufferLen,
										double measurement, ACHAR* dimensionText);
	Acad::ErrorStatus generateLayout();
	bool getArrowFirstIsFlipped() const;
	bool getArrowSecondIsFlipped() const;
	Acad::ErrorStatus getDimstyleData(AcDbDimStyleTableRecord*& pRecord) const;
	Acad::ErrorStatus getOsnapPointsAtSubentPath(AcDb::OsnapMode osnapMode,
												 const AcDbFullSubentPath& subentId,
												 const AcGePoint3d& pickPoint,
												 const AcGePoint3d& lastPoint,
												 const AcGeMatrix3d& viewXform,
												 AcGePoint3dArray& snapPoints,
												 AcDbIntArray& geomIds) const;
	Acad::ErrorStatus getPlane(AcGePlane&, AcDb::Planarity&) const override;
	double horizontalRotation() const;
	bool inspection() const;
	int inspectionFrame() const;
	const ACHAR* inspectionLabel() const;
	const ACHAR* inspectionRate() const;
	bool isConstraintDynamic() const;
	bool isConstraintObject() const;
	bool isConstraintObject(bool& hasExpression, bool& isReferenceConstraint) const;
	bool isDynamicDimension() const;
	bool isHorizontalRefTextRotation() const;
	bool isPlanar() const override { return true; }
	bool isUsingDefaultTextPosition() const;
	Acad::ErrorStatus measurement(double& val);
	AcGeVector3d normal() const;
	void objectClosed(const AcDbObjectId dbObj) override;
	ACDBCORE2D_PORT Acad::ErrorStatus prefix(AcString& sPrefix) const;
	Acad::ErrorStatus recomputeDimBlock(bool forceUpdate = true);
	Acad::ErrorStatus removeTextField();
	ACDBCORE2D_PORT void resetTextDefinedSize();
	ACDBCORE2D_PORT Acad::ErrorStatus setAltSuppressLeadingZeros(bool);
	ACDBCORE2D_PORT Acad::ErrorStatus setAltSuppressTrailingZeros(bool);
	ACDBCORE2D_PORT Acad::ErrorStatus setAltSuppressZeroFeet(bool);
	ACDBCORE2D_PORT Acad::ErrorStatus setAltSuppressZeroInches(bool);
	ACDBCORE2D_PORT Acad::ErrorStatus setAltToleranceSuppressLeadingZeros(bool);
	ACDBCORE2D_PORT Acad::ErrorStatus setAltToleranceSuppressTrailingZeros(bool);
	ACDBCORE2D_PORT Acad::ErrorStatus setAltToleranceSuppressZeroFeet(bool);
	ACDBCORE2D_PORT Acad::ErrorStatus setAltToleranceSuppressZeroInches(bool);
	ACDBCORE2D_PORT Acad::ErrorStatus setAlternatePrefix(const AcString&);
	ACDBCORE2D_PORT Acad::ErrorStatus setAlternateSuffix(const AcString&);
	Acad::ErrorStatus setArrowFirstIsFlipped(bool bIsFlipped);
	Acad::ErrorStatus setArrowSecondIsFlipped(bool bIsFlipped);
	Acad::ErrorStatus setConstraintDynamic(bool bDynamic);
	Acad::ErrorStatus setDimBlockId(const AcDbObjectId&);
	Acad::ErrorStatus setDimBlockPosition(const AcGePoint3d&);
	Acad::ErrorStatus setDimExt1Linetype(const AcDbObjectId linetype);
	Acad::ErrorStatus setDimExt2Linetype(const AcDbObjectId linetype);
	Acad::ErrorStatus setDimLineLinetype(const AcDbObjectId linetype);
	Acad::ErrorStatus setDimensionStyle(AcDbObjectId);
	Acad::ErrorStatus setDimensionText(const ACHAR*);
	Acad::ErrorStatus setDimfit(int);
	Acad::ErrorStatus setDimstyleData(AcDbDimStyleTableRecord* pNewData);
	Acad::ErrorStatus setDimstyleData(AcDbObjectId newDataId);
	Acad::ErrorStatus setDimunit(int);
	Acad::ErrorStatus setDynamicDimension(bool newVal);
	Acad::ErrorStatus setElevation(double);
	Acad::ErrorStatus setHorizontalRefTextRotation(bool newVal);
	Acad::ErrorStatus setHorizontalRotation(double newVal);
	Acad::ErrorStatus setInspection(bool val);
	Acad::ErrorStatus setInspectionFrame(int frame);
	Acad::ErrorStatus setInspectionLabel(const ACHAR* label);
	Acad::ErrorStatus setInspectionRate(const ACHAR* label);
	Acad::ErrorStatus setNormal(const AcGeVector3d&);
	ACDBCORE2D_PORT Acad::ErrorStatus setPrefix(const AcString&);
	void setShouldParticipateInOPM(bool bShouldParticipate);
	ACDBCORE2D_PORT Acad::ErrorStatus setSuffix(const AcString&);
	ACDBCORE2D_PORT Acad::ErrorStatus setSuppressAngularLeadingZeros(bool);
	ACDBCORE2D_PORT Acad::ErrorStatus setSuppressAngularTrailingZeros(bool);
	ACDBCORE2D_PORT Acad::ErrorStatus setSuppressLeadingZeros(bool);
	ACDBCORE2D_PORT Acad::ErrorStatus setSuppressTrailingZeros(bool);
	ACDBCORE2D_PORT Acad::ErrorStatus setSuppressZeroFeet(bool);
	ACDBCORE2D_PORT Acad::ErrorStatus setSuppressZeroInches(bool);
	Acad::ErrorStatus setTextAttachment(AcDbMText::AttachmentPoint eAtt);
	ACDBCORE2D_PORT void setTextDefinedSize(double width, double height);
	Acad::ErrorStatus setTextLineSpacingFactor(double dFactor);
	Acad::ErrorStatus setTextLineSpacingStyle(AcDb::LineSpacingStyle eStyle);
	Acad::ErrorStatus setTextPosition(const AcGePoint3d&);
	Acad::ErrorStatus setTextRotation(double);
	ACDBCORE2D_PORT Acad::ErrorStatus setToleranceSuppressLeadingZeros(bool);
	ACDBCORE2D_PORT Acad::ErrorStatus setToleranceSuppressTrailingZeros(bool);
	ACDBCORE2D_PORT Acad::ErrorStatus setToleranceSuppressZeroFeet(bool);
	ACDBCORE2D_PORT Acad::ErrorStatus setToleranceSuppressZeroInches(bool);
	ACDBCORE2D_PORT Acad::ErrorStatus setUsingDefaultTextPosition(bool);
	bool shouldParticipateInOPM() const;
	ACDBCORE2D_PORT Acad::ErrorStatus suffix(AcString&) const;
	ACDBCORE2D_PORT bool suppressAngularLeadingZeros() const;
	ACDBCORE2D_PORT bool suppressAngularTrailingZeros() const;
	ACDBCORE2D_PORT bool suppressLeadingZeros() const;
	ACDBCORE2D_PORT bool suppressTrailingZeros() const;
	ACDBCORE2D_PORT bool suppressZeroFeet() const;
	ACDBCORE2D_PORT bool suppressZeroInches() const;
	AcDbMText::AttachmentPoint textAttachment() const;
	ACDBCORE2D_PORT void textDefinedSize(double& width, double& height) const;
	double textLineSpacingFactor() const;
	AcDb::LineSpacingStyle textLineSpacingStyle() const;
	AcGePoint3d textPosition() const;
	double textRotation() const;
	ACDBCORE2D_PORT bool toleranceSuppressLeadingZeros() const;
	ACDBCORE2D_PORT bool toleranceSuppressTrailingZeros() const;
	ACDBCORE2D_PORT bool toleranceSuppressZeroFeet() const;
	ACDBCORE2D_PORT bool toleranceSuppressZeroInches() const;
	Acad::ErrorStatus useDefaultTextPosition();
	Acad::ErrorStatus useSetTextPosition();

	DIM_METHOD();
};

#include "IcArxPackPop.h"

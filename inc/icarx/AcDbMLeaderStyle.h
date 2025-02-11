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
***     Description: Declaration of AcDbMLeaderStyle class
***
*****************************************************************************/
#pragma once

#include "AcDbObject.h"
#include "acut_str_util.h"
#include "../AcString.h"

class AcCmColor;
class AcDbMText;
class AcGeScale3d;

#include "IcArxPackPush.h"

class AcDbMLeaderStyle : public AcDbObject
{
public:
	enum BlockConnectionType
	{
		kConnectExtents = 0,
		kConnectBase = 1
	};

	enum ContentType
	{
		kNoneContent = 0,
		kBlockContent = 1,
		kMTextContent = 2,
		kToleranceContent = 3,
	};

	enum DrawLeaderOrderType
	{
		kDrawLeaderHeadFirst = 0,
		kDrawLeaderTailFirst = 1
	};

	enum DrawMLeaderOrderType
	{
		kDrawContentFirst = 0,
		kDrawLeaderFirst = 1
	};

	enum LeaderDirectionType
	{
		kUnknownLeader = 0,
		kLeftLeader = 1,
		kRightLeader = 2,
		kTopLeader = 3,
		kBottomLeader = 4
	};

	enum LeaderType
	{
		kInVisibleLeader = 0,
		kStraightLeader = 1,
		kSplineLeader = 2
	};

	enum SegmentAngleType
	{
		kAny = 0,
		k15 = 1,
		k30 = 2,
		k45 = 3,
		k60 = 4,
		k90 = 6,
		kHorz = 12
	};

	enum TextAlignmentType
	{
		kLeftAlignment = 0,
		kCenterAlignment = 1,
		kRightAlignment = 2
	};

	enum TextAngleType
	{
		kInsertAngle = 0,
		kHorizontalAngle = 1,
		kAlwaysRightReadingAngle = 2
	};

	enum TextAttachmentDirection
	{
		kAttachmentHorizontal = 0,
		kAttachmentVertical = 1
	};

	enum TextAttachmentType
	{
		kAttachmentTopOfTop = 0,
		kAttachmentMiddleOfTop = 1,
		kAttachmentMiddle = 2,
		kAttachmentMiddleOfBottom = 3,
		kAttachmentBottomOfBottom = 4,
		kAttachmentBottomLine = 5,
		kAttachmentBottomOfTopLine = 6,
		kAttachmentBottomOfTop = 7,
		kAttachmentAllLine = 8,
		kAttachmentCenter = 9,
		kAttachmentLinedCenter = 10
	};

protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbMLeaderStyle);

	AcDbMLeaderStyle();
	~AcDbMLeaderStyle();

	double alignSpace() const;
	bool annotative() const;
	double arrowSize() const;
	AcDbObjectId arrowSymbolId() const;
	virtual uint32_t bitFlags() const;
	AcCmColor blockColor() const;
	BlockConnectionType blockConnectionType() const;
	AcDbObjectId blockId() const;
	double blockRotation() const;
	AcGeScale3d blockScale() const;
	double breakSize() const;
	ContentType contentType() const;
	AcDbMText* defaultMText() const;
	virtual const ACHAR* description(void) const;
	double doglegLength() const;
	DrawLeaderOrderType drawLeaderOrderType() const;
	DrawMLeaderOrderType drawMLeaderOrderType() const;
	bool enableBlockRotation() const;
	bool enableBlockScale() const;
	bool enableDogleg() const;
	bool enableFrameText() const;
	bool enableLanding() const;
	bool extendLeaderToText() const;
	SegmentAngleType firstSegmentAngleConstraint() const;
	virtual Acad::ErrorStatus getName(AcString& sName) const;
	virtual Acad::ErrorStatus getName(ACHAR*& pszName) const final;
	bool isRenamable() const;
	double landingGap() const;
	AcCmColor leaderLineColor() const;
	LeaderType leaderLineType() const;
	AcDbObjectId leaderLineTypeId() const;
	AcDb::LineWeight leaderLineWeight() const;
	int maxLeaderSegmentsPoints() const;
	bool overwritePropChanged() const;
	Acad::ErrorStatus postMLeaderStyleToDb(AcDbDatabase* pDb, const ACHAR* styleName,
										   AcDbObjectId& mleaderStyleId);
	double scale() const;
	SegmentAngleType secondSegmentAngleConstraint() const;
	Acad::ErrorStatus setAlignSpace(double alignSpace);
	Acad::ErrorStatus setAnnotative(bool isAnnotative);
	Acad::ErrorStatus setArrowSize(double arrowSize);
	Acad::ErrorStatus setArrowSymbolId(const ACHAR* name);
	Acad::ErrorStatus setArrowSymbolId(AcDbObjectId arrowSymbolId);
	virtual Acad::ErrorStatus setBitFlags(uint32_t flags);
	Acad::ErrorStatus setBlockColor(const AcCmColor& blockColor);
	Acad::ErrorStatus setBlockConnectionType(BlockConnectionType blockConnectionType);
	Acad::ErrorStatus setBlockId(const ACHAR* name);
	Acad::ErrorStatus setBlockId(AcDbObjectId blockId);
	Acad::ErrorStatus setBlockRotation(double rotation);
	Acad::ErrorStatus setBlockScale(const AcGeScale3d& scale);
	Acad::ErrorStatus setBreakSize(double size);
	Acad::ErrorStatus setContentType(ContentType contentType);
	Acad::ErrorStatus setDefaultMText(const AcDbMText* defaultMText);
	virtual Acad::ErrorStatus setDescription(const ACHAR* pszDescription);
	Acad::ErrorStatus setDoglegLength(double doglegLength);
	Acad::ErrorStatus setDrawLeaderOrderType(DrawLeaderOrderType drawLeaderOrderType);
	Acad::ErrorStatus setDrawMLeaderOrderType(DrawMLeaderOrderType drawMLeaderOrderType);
	Acad::ErrorStatus setEnableBlockRotation(bool enableBlockRotation);
	Acad::ErrorStatus setEnableBlockScale(bool enableBlockScale);
	Acad::ErrorStatus setEnableDogleg(bool enableDogleg);
	Acad::ErrorStatus setEnableFrameText(bool enableFrameText);
	Acad::ErrorStatus setEnableLanding(bool enableLanding);
	Acad::ErrorStatus setExtendLeaderToText(bool value);
	Acad::ErrorStatus setFirstSegmentAngleConstraint(SegmentAngleType angle);
	Acad::ErrorStatus setLandingGap(double landingGap);
	Acad::ErrorStatus setLeaderLineColor(const AcCmColor& leaderLineColor);
	Acad::ErrorStatus setLeaderLineType(LeaderType leaderLineType);
	Acad::ErrorStatus setLeaderLineTypeId(AcDbObjectId leaderLineTypeId);
	Acad::ErrorStatus setLeaderLineWeight(AcDb::LineWeight leaderLineWeight);
	Acad::ErrorStatus setMaxLeaderSegmentsPoints(int maxLeaderSegmentsPoints);
	virtual Acad::ErrorStatus setName(const ACHAR* pszName);
	Acad::ErrorStatus setScale(double scale);
	Acad::ErrorStatus setSecondSegmentAngleConstraint(SegmentAngleType angle);
	Acad::ErrorStatus setTextAlignAlwaysLeft(bool bAlwaysLeft);
	Acad::ErrorStatus setTextAlignmentType(TextAlignmentType textAlignmentType);
	Acad::ErrorStatus setTextAngleType(TextAngleType textAngleType);
	Acad::ErrorStatus setTextAttachmentDirection(
			AcDbMLeaderStyle::TextAttachmentDirection textAttachmentDirection);
	Acad::ErrorStatus setTextAttachmentType(TextAttachmentType textAttachmentType,
											LeaderDirectionType leaderDirection);
	Acad::ErrorStatus setTextAttachmentType(TextAttachmentType textAttachmentType);
	Acad::ErrorStatus setTextColor(const AcCmColor& textColor);
	Acad::ErrorStatus setTextHeight(double textHeight);
	Acad::ErrorStatus setTextStyleId(AcDbObjectId textStyleId);
	bool textAlignAlwaysLeft() const;
	TextAlignmentType textAlignmentType() const;
	TextAngleType textAngleType() const;
	TextAttachmentDirection textAttachmentDirection() const;
	TextAttachmentType textAttachmentType(LeaderDirectionType leaderDirection) const;
	TextAttachmentType textAttachmentType() const;
	AcCmColor textColor() const;
	double textHeight() const;
	AcDbObjectId textStyleId() const;
};

#include "IcArxPackPop.h"

inline Acad::ErrorStatus AcDbMLeaderStyle::getName(ACHAR*& pName) const
{
	return ::acutGetAcStringConvertToAChar(this, &AcDbMLeaderStyle::getName, pName);
}

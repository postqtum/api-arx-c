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
***     Description: Declaration of AcDbMLeader class
***
*****************************************************************************/
#pragma once

#include "AcDbEntity.h"
#include "AcDbMLeaderStyle.h"

#ifndef MAX_LEADER_NUMBER
const int MAX_LEADER_NUMBER = 5000;
#endif
#ifndef MAX_LEADERLINE_NUMBER
const int MAX_LEADERLINE_NUMBER = 5000;
#endif

class AcDbMLeaderObjectContextData;
class AcDbAttribute;

#include "IcArxPackPush.h"

class AcDbMLeader : public AcDbEntity
{
public:
	enum MoveType
	{
		kMoveAllPoints = 0,
		kMoveAllExceptArrowHeaderPoints = 1,
		kMoveContentAndDoglegPoints = 2
	};

	enum PropertyOverrideType
	{
		kLeaderLineType = 0,
		kLeaderLineColor = 1,
		kLeaderLineTypeId = 2,
		kLeaderLineWeight = 3,
		kEnableLanding = 4,
		kLandingGap = 5,
		kEnableDogleg = 6,
		kDoglegLength = 7,
		kArrowSymbolId = 8,
		kArrowSize = 9,
		kContentType = 10,
		kTextStyleId = 11,
		kTextLeftAttachmentType = 12,
		kTextAngleType = 13,
		kTextAlignmentType = 14,
		kTextColor = 15,
		kTextHeight = 16,
		kEnableFrameText = 17,
		kDefaultMText = 18,
		kBlockId = 19,
		kBlockColor = 20,
		kBlockScale = 21,
		kBlockRotation = 22,
		kBlockConnectionType = 23,
		kScale = 24,
		kTextRightAttachmentType = 25,
		kTextSwitchAlignmentType = 26,
		kTextAttachmentDirection = 27,
		kTextTopAttachmentType = 28,
		kTextBottomAttachmentType = 29,
		kExtendLeaderToText = 30,
		kSize = kExtendLeaderToText + 1
	};

	enum gsMarkType
	{
		kNone = 0,
		kArrowMark = 1,
		kLeaderLineMark = kArrowMark + MAX_LEADERLINE_NUMBER,
		kDoglegMark = kLeaderLineMark + MAX_LEADERLINE_NUMBER,
		kMTextMark = kDoglegMark + MAX_LEADER_NUMBER,
		kMTextUnderLineMark = kMTextMark + 1,
		kToleranceMark = kMTextUnderLineMark + 1,
		kBlockMark = kToleranceMark + 1,
		kBlockAttribute = kBlockMark + 1
	};

protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	AcDbMLeader();
	~AcDbMLeader();

	ACDB_DECLARE_MEMBERS(AcDbMLeader);

	AcDbObjectId MLeaderStyle();
	Acad::ErrorStatus addFirstVertex(int leaderLineIndex, const AcGePoint3d& point);
	Acad::ErrorStatus addLastVertex(int leaderLineIndex, const AcGePoint3d& point);
	Acad::ErrorStatus addLeader(int& leaderIndex);
	Acad::ErrorStatus addLeaderLine(int leaderIndex, int& leaderLineIndex);
	Acad::ErrorStatus addLeaderLine(const AcGePoint3d& point, int& leaderLineIndex);
	double arrowSize() const;
	AcDbObjectId arrowSymbolId() const;
	AcDbObjectId arrowSymbolId(int leaderLineIndex) const;
	AcCmColor blockColor() const;
	AcDbMLeaderStyle::BlockConnectionType blockConnectionType() const;
	AcDbObjectId blockContentId() const;
	double blockRotation() const;
	AcGeScale3d blockScale() const;
	Acad::ErrorStatus connectionPoint(const AcGeVector3d& vect, AcGePoint3d& point) const;
	Acad::ErrorStatus connectionPoint(
			const AcGeVector3d& vect, AcGePoint3d& point,
			AcDbMLeaderStyle::TextAttachmentDirection textAttachmentDirection) const;
	AcDbMLeaderStyle::ContentType contentType() const;
	Acad::ErrorStatus doglegLength(int leaderIndex, double& doglegLength) const;
	double doglegLength() const;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* filer) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* filer) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* filer) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* filer) const override;
	bool enableAnnotationScale() const;
	bool enableDogleg() const;
	bool enableFrameText() const;
	bool enableLanding() const;
	bool extendLeaderToText() const;
	Acad::ErrorStatus getArrowSize(int leaderLineIndex, double& arrowSize) const;
	Acad::ErrorStatus getArrowSymbolId(int leaderLineIndex, AcDbObjectId& arrowSymbolId) const;
	Acad::ErrorStatus getBlockAttributeValue(const AcDbObjectId& attdefId,
											 AcDbAttribute*& pAtt) const;
	Acad::ErrorStatus getBlockAttributeValue(const AcDbObjectId& attdefId, ACHAR*& value) const;
	Acad::ErrorStatus getBlockPosition(AcGePoint3d& position) const;
	Acad::ErrorStatus getContentGeomExtents(AcDbExtents& extents) const;
	void* getContextDataManager() const;
	Acad::ErrorStatus getDoglegDirection(int leaderIndex, AcGeVector3d& vector) const;
	Acad::ErrorStatus getFirstVertex(int leaderLineIndex, AcGePoint3d& point) const;
	Acad::ErrorStatus getLastVertex(int leaderLineIndex, AcGePoint3d& point) const;
	Acad::ErrorStatus getLeaderIndex(int leaderLineIndex, int& leaderIndex) const;
	Acad::ErrorStatus getLeaderIndexes(AcArray<int>& leaderIndexes) const;
	Acad::ErrorStatus getLeaderLineColor(int leaderLineIndex, AcCmColor& leaderLineColor) const;
	Acad::ErrorStatus getLeaderLineIndexes(AcArray<int>& leaderLineIndexes) const;
	Acad::ErrorStatus getLeaderLineIndexes(int leaderIndex, AcArray<int>& leaderLineIndexes) const;
	Acad::ErrorStatus getLeaderLineType(int leaderLineIndex,
										AcDbMLeaderStyle::LeaderType& leaderLineType) const;
	Acad::ErrorStatus getLeaderLineTypeId(int leaderLineIndex,
										  AcDbObjectId& leaderLineTypeId) const;
	Acad::ErrorStatus getLeaderLineWeight(int leaderLineIndex,
										  AcDb::LineWeight& leaderLineWeight) const;
	Acad::ErrorStatus getOverridedMLeaderStyle(AcDbMLeaderStyle& mleaderStyle);
	Acad::ErrorStatus getTextLocation(AcGePoint3d& location) const;
	Acad::ErrorStatus getToleranceLocation(AcGePoint3d& location) const;
	Acad::ErrorStatus getVertex(int leaderLineIndex, int index, AcGePoint3d& point) const;
	bool hasContent() const;
	bool isOverride(PropertyOverrideType propertyType) const;
	double landingGap() const;
	AcCmColor leaderLineColor() const;
	AcDbMLeaderStyle::LeaderType leaderLineType() const;
	AcDbObjectId leaderLineTypeId() const;
	AcDb::LineWeight leaderLineWeight() const;
	void modified(const AcDbObject* dbObj) override;
	Acad::ErrorStatus moveMLeader(const AcGeVector3d& vector, MoveType moveType,
								  bool bAutoSwitchDogleg = true);
	AcDbMText* mtext() const;
	AcGeVector3d normal() const;
	int numLeaderLines() const;
	int numLeaders() const;
	Acad::ErrorStatus numVertices(int leaderLineIndex, int& num) const;
	void objectClosed(const AcDbObjectId dbObjId) override;
	AcGePlane plane() const;
	Acad::ErrorStatus postMLeaderToDb(AcDbDatabase* pDb);
	Acad::ErrorStatus recomputeBreakPoints();
	Acad::ErrorStatus removeFirstVertex(int leaderLineIndex);
	Acad::ErrorStatus removeLastVertex(int leaderLineIndex);
	Acad::ErrorStatus removeLeader(int leaderIndex);
	Acad::ErrorStatus removeLeaderLine(int leaderLineIndex);
	Acad::ErrorStatus removeLeaderLineRefAssoc(int leaderLineIndex) const;
	double scale() const;
	Acad::ErrorStatus setArrowSize(double arrowSize);
	Acad::ErrorStatus setArrowSize(int leaderLineIndex, double arrowSize);
	Acad::ErrorStatus setArrowSymbolId(AcDbObjectId arrowSymbolId);
	Acad::ErrorStatus setArrowSymbolId(int leaderLineIndex, AcDbObjectId arrowSymbolId);
	Acad::ErrorStatus setBlockAttributeValue(const AcDbObjectId& attdefId,
											 const AcDbAttribute* pAtt);
	Acad::ErrorStatus setBlockAttributeValue(const AcDbObjectId& attdefId, const ACHAR* value);
	Acad::ErrorStatus setBlockColor(const AcCmColor& blockColor);
	Acad::ErrorStatus setBlockConnectionType(
			AcDbMLeaderStyle::BlockConnectionType blockConnectionType);
	Acad::ErrorStatus setBlockContentId(AcDbObjectId blockId);
	Acad::ErrorStatus setBlockPosition(const AcGePoint3d& position);
	Acad::ErrorStatus setBlockRotation(double rotation);
	Acad::ErrorStatus setBlockScale(const AcGeScale3d& scale);
	Acad::ErrorStatus setContentType(AcDbMLeaderStyle::ContentType contentType);
	Acad::ErrorStatus setContextDataManager(void* pContextDataManager);
	Acad::ErrorStatus setDoglegDirection(int leaderIndex, const AcGeVector3d& vector);
	Acad::ErrorStatus setDoglegLength(int leaderIndex, double doglegLength);
	Acad::ErrorStatus setDoglegLength(double doglegLength);
	Acad::ErrorStatus setEnableAnnotationScale(bool enableAnnotationScale);
	Acad::ErrorStatus setEnableDogleg(bool enableDogleg);
	Acad::ErrorStatus setEnableFrameText(bool enableFrameText);
	Acad::ErrorStatus setEnableLanding(bool enableLanding);
	Acad::ErrorStatus setExtendLeaderToText(bool value);
	Acad::ErrorStatus setFirstVertex(int leaderLineIndex, const AcGePoint3d& point);
	Acad::ErrorStatus setLandingGap(double landingGap);
	Acad::ErrorStatus setLastVertex(int leaderLineIndex, const AcGePoint3d& point);
	Acad::ErrorStatus setLeaderLineColor(const AcCmColor& leaderLineColor);
	Acad::ErrorStatus setLeaderLineColor(int leaderLineIndex, const AcCmColor& leaderLineColor);
	Acad::ErrorStatus setLeaderLineType(AcDbMLeaderStyle::LeaderType leaderLineType);
	Acad::ErrorStatus setLeaderLineType(int leaderLineIndex,
										AcDbMLeaderStyle::LeaderType leaderLineType);
	Acad::ErrorStatus setLeaderLineTypeId(AcDbObjectId leaderLineTypeId);
	Acad::ErrorStatus setLeaderLineTypeId(int leaderLineIndex, AcDbObjectId leaderLineTypeId);
	Acad::ErrorStatus setLeaderLineWeight(AcDb::LineWeight leaderLineWeight);
	Acad::ErrorStatus setLeaderLineWeight(int leaderLineIndex, AcDb::LineWeight leaderLineWeight);
	Acad::ErrorStatus setMLeaderStyle(AcDbObjectId newStyleId);
	Acad::ErrorStatus setMText(const AcDbMText* pMText);
	Acad::ErrorStatus setOverride(PropertyOverrideType propertyType, bool isOverride = true);
	void setPlane(const AcGePlane& plane);
	Acad::ErrorStatus setScale(double scale);
	Acad::ErrorStatus setTextAlignmentType(AcDbMLeaderStyle::TextAlignmentType textAlignmentType);
	Acad::ErrorStatus setTextAngleType(AcDbMLeaderStyle::TextAngleType textAngleType);
	Acad::ErrorStatus setTextAttachmentDirection(
			AcDbMLeaderStyle::TextAttachmentDirection textAttachmentDirection);
	Acad::ErrorStatus setTextAttachmentType(AcDbMLeaderStyle::TextAttachmentType textAttachmentType,
											AcDbMLeaderStyle::LeaderDirectionType leaderDirection);
	Acad::ErrorStatus setTextAttachmentType(
			AcDbMLeaderStyle::TextAttachmentType textAttachmentType);
	Acad::ErrorStatus setTextColor(const AcCmColor& textColor);
	Acad::ErrorStatus setTextHeight(double textHeight);
	Acad::ErrorStatus setTextLocation(const AcGePoint3d& location);
	Acad::ErrorStatus setTextStyleId(AcDbObjectId textStyleId);
	Acad::ErrorStatus setToleranceLocation(const AcGePoint3d& location);
	Acad::ErrorStatus setVertex(int leaderLineIndex, int index, const AcGePoint3d& point);
	Acad::ErrorStatus subClose() override;
	Acad::ErrorStatus subErase(bool erasing) override;
	AcDbMLeaderStyle::TextAlignmentType textAlignmentType() const;
	AcDbMLeaderStyle::TextAngleType textAngleType() const;
	AcDbMLeaderStyle::TextAttachmentDirection textAttachmentDirection() const;
	AcDbMLeaderStyle::TextAttachmentType textAttachmentType(
			AcDbMLeaderStyle::LeaderDirectionType leaderDirection) const;
	AcDbMLeaderStyle::TextAttachmentType textAttachmentType() const;
	AcCmColor textColor() const;
	double textHeight() const;
	AcDbObjectId textStyleId() const;
	Acad::ErrorStatus updateContentScale(AcDbMLeaderObjectContextData* pContext);
	Acad::ErrorStatus updateLeaderLinePosition();
};

#include "IcArxPackPop.h"

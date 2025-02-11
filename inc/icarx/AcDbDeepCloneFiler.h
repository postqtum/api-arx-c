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
***     Description: Declaration of AcDbDeepCloneFiler class
***
*****************************************************************************/
#pragma once

#include "AcDbDwgFiler.h"

class AcDbImpDeepCloneFiler;
class AcDbObjectId;

#include "IcArxPackPush.h"

class AcDbDeepCloneFiler : public AcDbDwgFiler
{
	friend class AcDbSystemInternals;

private:
	AcDbImpDeepCloneFiler* mpImpFiler;

protected:
	AcDbDeepCloneFiler(AcDbSystemInternals*);

public:
	ACRX_DECLARE_MEMBERS(AcDbDeepCloneFiler);

	AcDbDeepCloneFiler();
	~AcDbDeepCloneFiler();

	Acad::ErrorStatus addReferences(AcDbIdRefQueue&) override;
	AcDbFilerController& controller() const override;
	Acad::ErrorStatus filerStatus() const override;
	AcDb::FilerType filerType() const override;
	virtual bool getNextOwnedObject(AcDbObjectId& id);
	virtual bool moreOwnedObjects() const;
	Acad::ErrorStatus readAcDbHandle(AcDbHandle*) override;
	Acad::ErrorStatus readAddress(void**) override;
	Acad::ErrorStatus readBChunk(ads_binary*) override;
	Acad::ErrorStatus readBool(bool*) override;
	Acad::ErrorStatus readBoolean(bool*) override;
	Acad::ErrorStatus readBytes(void*, IcArx::Integers::UIntPtr) override;
	Acad::ErrorStatus readDouble(double*) override;
	Acad::ErrorStatus readHardOwnershipId(AcDbHardOwnershipId*) override;
	Acad::ErrorStatus readHardPointerId(AcDbHardPointerId*) override;
	Acad::ErrorStatus readInt16(int16_t*) override;
	Acad::ErrorStatus readInt32(int32_t*) override;
	Acad::ErrorStatus readInt64(int64_t*) override;
	Acad::ErrorStatus readInt8(int8_t*) override;
	Acad::ErrorStatus readPoint2d(AcGePoint2d*) override;
	Acad::ErrorStatus readPoint3d(AcGePoint3d*) override;
	Acad::ErrorStatus readScale3d(AcGeScale3d*) override;
	Acad::ErrorStatus readSoftOwnershipId(AcDbSoftOwnershipId*) override;
	Acad::ErrorStatus readSoftPointerId(AcDbSoftPointerId*) override;
	Acad::ErrorStatus readString(ACHAR**) override;
	Acad::ErrorStatus readString(AcString&) override;
	Acad::ErrorStatus readUInt16(uint16_t*) override;
	Acad::ErrorStatus readUInt32(uint32_t*) override;
	Acad::ErrorStatus readUInt64(uint64_t*) override;
	Acad::ErrorStatus readUInt8(uint8_t*) override;
	Acad::ErrorStatus readVector2d(AcGeVector2d*) override;
	Acad::ErrorStatus readVector3d(AcGeVector3d*) override;
	void resetFilerStatus() override;
	Acad::ErrorStatus seek(int64_t nOffset, int nMethod) override;
	void setFilerStatus(Acad::ErrorStatus) override;
	int64_t tell() const override;
	bool usesReferences() const override;
	Acad::ErrorStatus writeAcDbHandle(const AcDbHandle&) override;
	Acad::ErrorStatus writeAddress(const void*) override;
	Acad::ErrorStatus writeBChunk(const ads_binary&) override;
	Acad::ErrorStatus writeBool(bool) override;
	Acad::ErrorStatus writeBoolean(bool) override;
	Acad::ErrorStatus writeBytes(const void*, IcArx::Integers::UIntPtr) override;
	Acad::ErrorStatus writeDouble(double) override;
	Acad::ErrorStatus writeHardOwnershipId(const AcDbHardOwnershipId&) override;
	Acad::ErrorStatus writeHardPointerId(const AcDbHardPointerId&) override;
	Acad::ErrorStatus writeInt16(int16_t) override;
	Acad::ErrorStatus writeInt32(int32_t) override;
	Acad::ErrorStatus writeInt64(int64_t) override;
	Acad::ErrorStatus writeInt8(int8_t) override;
	Acad::ErrorStatus writePoint2d(const AcGePoint2d&) override;
	Acad::ErrorStatus writePoint3d(const AcGePoint3d&) override;
	Acad::ErrorStatus writeScale3d(const AcGeScale3d&) override;
	Acad::ErrorStatus writeSoftOwnershipId(const AcDbSoftOwnershipId&) override;
	Acad::ErrorStatus writeSoftPointerId(const AcDbSoftPointerId&) override;
	Acad::ErrorStatus writeString(const ACHAR*) override;
	Acad::ErrorStatus writeString(const AcString&) override;
	Acad::ErrorStatus writeUInt16(uint16_t) override;
	Acad::ErrorStatus writeUInt32(uint32_t) override;
	Acad::ErrorStatus writeUInt64(uint64_t) override;
	Acad::ErrorStatus writeUInt8(uint8_t) override;
	Acad::ErrorStatus writeVector2d(const AcGeVector2d&) override;
	Acad::ErrorStatus writeVector3d(const AcGeVector3d&) override;
};

#include "IcArxPackPop.h"

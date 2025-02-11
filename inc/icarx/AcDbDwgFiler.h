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
***     Description: Declaration of AcDbDwgFiler class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "AcDbEnumType.h"
#include "AcDbEnumMode.h"

class AcDbHardOwnershipId;
class AcDbSoftOwnershipId;
class AcDbHardPointerId;
class AcDbSoftPointerId;
class AcString;
struct ads_binary;
class AcGePoint2d;
class AcGePoint3d;
class AcGeScale3d;
class AcGeVector2d;
class AcGeVector3d;
class AcDbHandle;
class AcDbIdRefQueue;
class AcDbAuditInfo;
class AcDbFilerController;

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcDbDwgFiler : public AcRxObject
{
private:
	AcDbDwgFiler(const AcDbDwgFiler&) = delete;
	AcDbDwgFiler& operator=(const AcDbDwgFiler&) = delete;

protected:
	ACDBCORE2D_PORT AcDbDwgFiler();

public:
	ACRX_DECLARE_MEMBERS(AcDbDwgFiler);

public:
	ACDBCORE2D_PORT ~AcDbDwgFiler();

	virtual Acad::ErrorStatus addReferences(AcDbIdRefQueue& /*qToAbsorb*/);
	virtual AcDbFilerController& controller() const;
	virtual Acad::ErrorStatus dwgVersion(AcDb::AcDbDwgVersion& ver,
										 AcDb::MaintenanceReleaseVersion& maintVer) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus extendedDwgMaintenanceReleaseVersion(
			AcDb::MaintenanceReleaseVersion& maintVer) const;
	virtual Acad::ErrorStatus filerStatus() const = 0;
	virtual AcDb::FilerType filerType() const = 0;
	virtual AcDbAuditInfo* getAuditInfo() const;
	virtual Acad::ErrorStatus readAcDbHandle(AcDbHandle* pVal) = 0;
	virtual Acad::ErrorStatus readAddress(void** pVal);
	virtual Acad::ErrorStatus readBChunk(ads_binary* pVal) = 0;
	virtual Acad::ErrorStatus readBool(bool* pVal) = 0;
	virtual Acad::ErrorStatus readBoolean(bool* pVal) = 0;
	virtual Acad::ErrorStatus readBytes(void* pDest, IcArx::Integers::UIntPtr nBytes) = 0;
	virtual Acad::ErrorStatus readDouble(double* pVal) = 0;
	virtual Acad::ErrorStatus readHardOwnershipId(AcDbHardOwnershipId* pVal) = 0;
	virtual Acad::ErrorStatus readHardPointerId(AcDbHardPointerId* pVal) = 0;
	virtual Acad::ErrorStatus readInt16(int16_t* pVal) = 0;
	virtual Acad::ErrorStatus readInt32(int32_t* pVal) = 0;
	virtual Acad::ErrorStatus readInt64(int64_t* pVal) = 0;
	virtual Acad::ErrorStatus readInt8(int8_t* pVal) = 0;
	Acad::ErrorStatus readItem(AcDbHardOwnershipId* pId);
	Acad::ErrorStatus readItem(AcDbSoftOwnershipId* pId);
	Acad::ErrorStatus readItem(AcDbHardPointerId* pId);
	Acad::ErrorStatus readItem(AcDbSoftPointerId* pId);
	Acad::ErrorStatus readItem(ACHAR** pVal);
	Acad::ErrorStatus readItem(ads_binary* pVal);
	Acad::ErrorStatus readItem(AcDbHandle* pVal);
	Acad::ErrorStatus readItem(int32_t* pVal);
	Acad::ErrorStatus readItem(int16_t* pVal);
	Acad::ErrorStatus readItem(int8_t* pVal);
	Acad::ErrorStatus readItem(uint32_t* pVal);
	Acad::ErrorStatus readItem(uint16_t* pVal);
	Acad::ErrorStatus readItem(uint8_t* pVal);
	Acad::ErrorStatus readItem(bool* pVal);
	Acad::ErrorStatus readItem(double* pVal);
	Acad::ErrorStatus readItem(AcGePoint2d* pVal);
	Acad::ErrorStatus readItem(AcGePoint3d* pVal);
	Acad::ErrorStatus readItem(AcGeVector2d* pVal);
	Acad::ErrorStatus readItem(AcGeVector3d* pVal);
	Acad::ErrorStatus readItem(AcGeScale3d* pVal);
	Acad::ErrorStatus readItem(void* pDest, IcArx::Integers::UIntPtr nBytes);
	Acad::ErrorStatus readItem(void** pp);
	virtual Acad::ErrorStatus readPoint2d(AcGePoint2d* pVal) = 0;
	virtual Acad::ErrorStatus readPoint3d(AcGePoint3d* pVal) = 0;
	virtual Acad::ErrorStatus readScale3d(AcGeScale3d* pVal) = 0;
	virtual Acad::ErrorStatus readSoftOwnershipId(AcDbSoftOwnershipId* pVal) = 0;
	virtual Acad::ErrorStatus readSoftPointerId(AcDbSoftPointerId* pVal) = 0;
	virtual Acad::ErrorStatus readString(ACHAR** pVal) = 0;
	virtual Acad::ErrorStatus readString(AcString& val) = 0;
	virtual Acad::ErrorStatus readUInt16(uint16_t* pVal) = 0;
	virtual Acad::ErrorStatus readUInt32(uint32_t* pVal) = 0;
	virtual Acad::ErrorStatus readUInt64(uint64_t* pVal) = 0;
	virtual Acad::ErrorStatus readUInt8(uint8_t* pVal) = 0;
	virtual Acad::ErrorStatus readVector2d(AcGeVector2d* pVal) = 0;
	virtual Acad::ErrorStatus readVector3d(AcGeVector3d* pVal) = 0;
	virtual void resetFilerStatus() = 0;
	virtual Acad::ErrorStatus seek(int64_t nOffset, int nMethod) = 0;
	virtual void setFilerStatus(Acad::ErrorStatus es) = 0;
	virtual int64_t tell() const = 0;
	virtual bool usesReferences() const;
	virtual Acad::ErrorStatus writeAcDbHandle(const AcDbHandle& val) = 0;
	virtual Acad::ErrorStatus writeAddress(const void* pVal);
	virtual Acad::ErrorStatus writeBChunk(const ads_binary&) = 0;
	virtual Acad::ErrorStatus writeBool(bool val) = 0;
	virtual Acad::ErrorStatus writeBoolean(bool val) = 0;
	virtual Acad::ErrorStatus writeBytes(const void* pSrc, IcArx::Integers::UIntPtr nBytes) = 0;
	virtual Acad::ErrorStatus writeDouble(double val) = 0;
	virtual Acad::ErrorStatus writeHardOwnershipId(const AcDbHardOwnershipId& val) = 0;
	virtual Acad::ErrorStatus writeHardPointerId(const AcDbHardPointerId& val) = 0;
	virtual Acad::ErrorStatus writeInt16(int16_t val) = 0;
	virtual Acad::ErrorStatus writeInt32(int32_t val) = 0;
	virtual Acad::ErrorStatus writeInt64(int64_t val) = 0;
	virtual Acad::ErrorStatus writeInt8(int8_t val) = 0;
	Acad::ErrorStatus writeItem(const AcDbHardOwnershipId& id);
	Acad::ErrorStatus writeItem(const AcDbSoftOwnershipId& id);
	Acad::ErrorStatus writeItem(const AcDbHardPointerId& id);
	Acad::ErrorStatus writeItem(const AcDbSoftPointerId& id);
	Acad::ErrorStatus writeItem(const ACHAR* val);
	Acad::ErrorStatus writeItem(const AcString& val);
	Acad::ErrorStatus writeItem(const ads_binary& val);
	Acad::ErrorStatus writeItem(const AcDbHandle& val);
	Acad::ErrorStatus writeItem(int32_t val);
	Acad::ErrorStatus writeItem(int16_t val);
	Acad::ErrorStatus writeItem(int8_t val);
	Acad::ErrorStatus writeItem(uint32_t val);
	Acad::ErrorStatus writeItem(uint16_t val);
	Acad::ErrorStatus writeItem(uint8_t val);
	Acad::ErrorStatus writeItem(bool val);
	Acad::ErrorStatus writeItem(double val);
	Acad::ErrorStatus writeItem(const AcGePoint2d& val);
	Acad::ErrorStatus writeItem(const AcGePoint3d& val);
	Acad::ErrorStatus writeItem(const AcGeVector2d& val);
	Acad::ErrorStatus writeItem(const AcGeVector3d& val);
	Acad::ErrorStatus writeItem(const AcGeScale3d& val);
	Acad::ErrorStatus writeItem(const void* pSrc, IcArx::Integers::UIntPtr nBytes);
	Acad::ErrorStatus writeItem(const void* p);
	virtual Acad::ErrorStatus writePoint2d(const AcGePoint2d& val) = 0;
	virtual Acad::ErrorStatus writePoint3d(const AcGePoint3d& val) = 0;
	virtual Acad::ErrorStatus writeScale3d(const AcGeScale3d& val) = 0;
	virtual Acad::ErrorStatus writeSoftOwnershipId(const AcDbSoftOwnershipId& val) = 0;
	virtual Acad::ErrorStatus writeSoftPointerId(const AcDbSoftPointerId& val) = 0;
	virtual Acad::ErrorStatus writeString(const ACHAR* pVal) = 0;
	virtual Acad::ErrorStatus writeString(const AcString& pVal) = 0;
	virtual Acad::ErrorStatus writeUInt16(uint16_t val) = 0;
	virtual Acad::ErrorStatus writeUInt32(uint32_t val) = 0;
	virtual Acad::ErrorStatus writeUInt64(uint64_t val) = 0;
	virtual Acad::ErrorStatus writeUInt8(uint8_t val) = 0;
	virtual Acad::ErrorStatus writeVector2d(const AcGeVector2d& val) = 0;
	virtual Acad::ErrorStatus writeVector3d(const AcGeVector3d& val) = 0;
};

#include "IcArxPackPop.h"

inline Acad::ErrorStatus AcDbDwgFiler::readItem(AcDbHardOwnershipId* pId)
{
	return readHardOwnershipId(pId);
}

inline Acad::ErrorStatus AcDbDwgFiler::readItem(AcDbSoftOwnershipId* pId)
{
	return readSoftOwnershipId(pId);
}

inline Acad::ErrorStatus AcDbDwgFiler::readItem(AcDbHardPointerId* pId)
{
	return readHardPointerId(pId);
}

inline Acad::ErrorStatus AcDbDwgFiler::readItem(AcDbSoftPointerId* pId)
{
	return readSoftPointerId(pId);
}

inline Acad::ErrorStatus AcDbDwgFiler::readItem(ACHAR** pVal)
{
	return readString(pVal);
}

inline Acad::ErrorStatus AcDbDwgFiler::readItem(ads_binary* pVal)
{
	return readBChunk(pVal);
}

inline Acad::ErrorStatus AcDbDwgFiler::readItem(AcDbHandle* pVal)
{
	return readAcDbHandle(pVal);
}

inline Acad::ErrorStatus AcDbDwgFiler::readItem(int32_t* pVal)
{
	return readInt32(pVal);
}

inline Acad::ErrorStatus AcDbDwgFiler::readItem(int16_t* pVal)
{
	return readInt16(pVal);
}

inline Acad::ErrorStatus AcDbDwgFiler::readItem(int8_t* pVal)
{
	return this->readInt8(pVal);
}

inline Acad::ErrorStatus AcDbDwgFiler::readItem(uint32_t* pVal)
{
	return readUInt32(pVal);
}

inline Acad::ErrorStatus AcDbDwgFiler::readItem(uint16_t* pVal)
{
	return readUInt16(pVal);
}

inline Acad::ErrorStatus AcDbDwgFiler::readItem(uint8_t* pVal)
{
	return readUInt8(pVal);
}

inline Acad::ErrorStatus AcDbDwgFiler::readItem(bool* pVal)
{
	return readBool(pVal);
}

inline Acad::ErrorStatus AcDbDwgFiler::readItem(double* pVal)
{
	return readDouble(pVal);
}

inline Acad::ErrorStatus AcDbDwgFiler::readItem(AcGePoint2d* pVal)
{
	return readPoint2d(pVal);
}

inline Acad::ErrorStatus AcDbDwgFiler::readItem(AcGePoint3d* pVal)
{
	return readPoint3d(pVal);
}

inline Acad::ErrorStatus AcDbDwgFiler::readItem(AcGeVector2d* pVal)
{
	return readVector2d(pVal);
}

inline Acad::ErrorStatus AcDbDwgFiler::readItem(AcGeVector3d* pVal)
{
	return readVector3d(pVal);
}

inline Acad::ErrorStatus AcDbDwgFiler::readItem(AcGeScale3d* pVal)
{
	return readScale3d(pVal);
}

inline Acad::ErrorStatus AcDbDwgFiler::readItem(void* buf, IcArx::Integers::UIntPtr cnt)
{
	return readBytes(buf, cnt);
}

inline Acad::ErrorStatus AcDbDwgFiler::readItem(void** pp)
{
	return readAddress(pp);
}

inline Acad::ErrorStatus AcDbDwgFiler::writeItem(const AcDbHardOwnershipId& pId)
{
	return writeHardOwnershipId(pId);
}

inline Acad::ErrorStatus AcDbDwgFiler::writeItem(const AcDbSoftOwnershipId& pId)
{
	return writeSoftOwnershipId(pId);
}

inline Acad::ErrorStatus AcDbDwgFiler::writeItem(const AcDbHardPointerId& pId)
{
	return writeHardPointerId(pId);
}

inline Acad::ErrorStatus AcDbDwgFiler::writeItem(const AcDbSoftPointerId& pId)
{
	return writeSoftPointerId(pId);
}

inline Acad::ErrorStatus AcDbDwgFiler::writeItem(const ACHAR* val)
{
	return writeString(val);
}

inline Acad::ErrorStatus AcDbDwgFiler::writeItem(const ads_binary& val)
{
	return writeBChunk(val);
}

inline Acad::ErrorStatus AcDbDwgFiler::writeItem(const AcDbHandle& val)
{
	return writeAcDbHandle(val);
}

inline Acad::ErrorStatus AcDbDwgFiler::writeItem(int32_t val)
{
	return writeInt32(val);
}

inline Acad::ErrorStatus AcDbDwgFiler::writeItem(int16_t val)
{
	return writeInt16(val);
}

inline Acad::ErrorStatus AcDbDwgFiler::writeItem(int8_t val)
{
	return this->writeInt8(val);
}

inline Acad::ErrorStatus AcDbDwgFiler::writeItem(uint32_t val)
{
	return writeUInt32(val);
}

inline Acad::ErrorStatus AcDbDwgFiler::writeItem(uint16_t val)
{
	return writeUInt16(val);
}

inline Acad::ErrorStatus AcDbDwgFiler::writeItem(uint8_t val)
{
	return writeUInt8(val);
}

inline Acad::ErrorStatus AcDbDwgFiler::writeItem(bool val)
{
	return writeBool(val);
}

inline Acad::ErrorStatus AcDbDwgFiler::writeItem(double val)
{
	return writeDouble(val);
}

inline Acad::ErrorStatus AcDbDwgFiler::writeItem(const AcGePoint2d& val)
{
	return writePoint2d(val);
}

inline Acad::ErrorStatus AcDbDwgFiler::writeItem(const AcGePoint3d& val)
{
	return writePoint3d(val);
}

inline Acad::ErrorStatus AcDbDwgFiler::writeItem(const AcGeVector2d& val)
{
	return writeVector2d(val);
}

inline Acad::ErrorStatus AcDbDwgFiler::writeItem(const AcGeVector3d& val)
{
	return writeVector3d(val);
}

inline Acad::ErrorStatus AcDbDwgFiler::writeItem(const AcGeScale3d& val)
{
	return writeScale3d(val);
}

inline Acad::ErrorStatus AcDbDwgFiler::writeItem(const void* buf, IcArx::Integers::UIntPtr cnt)
{
	return writeBytes(buf, cnt);
}

inline Acad::ErrorStatus AcDbDwgFiler::writeItem(const void* p)
{
	return writeAddress(p);
}

inline Acad::ErrorStatus AcDbDwgFiler::writeItem(const AcString& val)
{
	return writeString(val);
}

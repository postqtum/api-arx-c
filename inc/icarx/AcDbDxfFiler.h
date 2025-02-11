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
***     Description: Declaration of AcDbDxfFiler class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"

#include "AcDbEnumType.h"

struct resbuf;
class AcDbDatabase;
class AcDbObjectId;
class AcString;
struct ads_binary;
class AcDbHandle;
class AcGePoint2d;
class AcGePoint3d;
class AcGeVector2d;
class AcGeVector3d;
class AcGeScale3d;
class AcDbFilerController;

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcDbDxfFiler : public AcRxObject
{
public:
	enum
	{
		kDfltPrec = -1,
		kMaxPrec = 16
	};

private:
	AcDbDxfFiler(const AcDbDxfFiler&) = delete;
	AcDbDxfFiler& operator=(const AcDbDxfFiler&) = delete;

	virtual Acad::ErrorStatus setVAError(Acad::ErrorStatus, const ACHAR*, va_list);

public:
	AcDbDxfFiler();
	~AcDbDxfFiler();

	ACRX_DECLARE_MEMBERS(AcDbDxfFiler);

	virtual bool atEOF();
	virtual bool atEmbeddedObjectStart();
	virtual bool atEndOfObject();
	virtual bool atExtendedData();
	virtual bool atSubclassData(const ACHAR* subClassName);
	AcDbFilerController& controller() const;
	virtual AcDbDatabase* database() const = 0;
	virtual Acad::ErrorStatus dwgVersion(AcDb::AcDbDwgVersion& ver,
										 AcDb::MaintenanceReleaseVersion& maintVer) const;
	virtual double elevation() const;
	virtual const ACHAR* errorMessage() const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus extendedDwgMaintenanceReleaseVersion(
			AcDb::MaintenanceReleaseVersion& maintVer) const;
	virtual Acad::ErrorStatus filerStatus() const = 0;
	virtual AcDb::FilerType filerType() const = 0;
	virtual void haltAtClassBoundaries(bool halt);
	virtual bool includesDefaultValues() const = 0;
	virtual bool isModifyingExistingObject() const;
	virtual int precision() const;
	virtual Acad::ErrorStatus pushBackItem();
	Acad::ErrorStatus readItem(resbuf* pItem);
	virtual Acad::ErrorStatus readResBuf(resbuf* pRb);
	virtual void resetFilerStatus() = 0;
	virtual int rewindFiler() = 0;
	virtual Acad::ErrorStatus setError(Acad::ErrorStatus es, const ACHAR* errMsg, ...);
	virtual Acad::ErrorStatus setError(const ACHAR* errMsg, ...);
	virtual void setPrecision(int prec);
	virtual double thickness() const;
	virtual Acad::ErrorStatus writeAcDbHandle(AcDb::DxfCode code, const AcDbHandle& val) = 0;
	virtual Acad::ErrorStatus writeBChunk(AcDb::DxfCode code, const ads_binary& val) = 0;
	virtual Acad::ErrorStatus writeBool(AcDb::DxfCode code, bool val) = 0;
	virtual Acad::ErrorStatus writeBoolean(AcDb::DxfCode code, bool val) = 0;
	virtual Acad::ErrorStatus writeDouble(AcDb::DxfCode code, double val, int prec = kDfltPrec) = 0;
	virtual Acad::ErrorStatus writeEmbeddedObjectStart();
	virtual Acad::ErrorStatus writeInt16(AcDb::DxfCode code, int16_t val) = 0;
	virtual Acad::ErrorStatus writeInt32(AcDb::DxfCode code, int32_t val) = 0;
	virtual Acad::ErrorStatus writeInt64(AcDb::DxfCode code, int64_t val) = 0;
	virtual Acad::ErrorStatus writeInt8(AcDb::DxfCode code, int8_t) = 0;
	Acad::ErrorStatus writeItem(const resbuf& pItem);
	Acad::ErrorStatus writeItem(AcDb::DxfCode dc, const AcDbObjectId& id);
	Acad::ErrorStatus writeItem(AcDb::DxfCode dc, const ACHAR* val);
	Acad::ErrorStatus writeItem(AcDb::DxfCode dc, const AcString& val);
	Acad::ErrorStatus writeItem(AcDb::DxfCode dc, const ads_binary& val);
	Acad::ErrorStatus writeItem(AcDb::DxfCode dc, const AcDbHandle& val);
	Acad::ErrorStatus writeItem(AcDb::DxfCode dc, int32_t val);
	Acad::ErrorStatus writeItem(AcDb::DxfCode dc, int16_t val);
	Acad::ErrorStatus writeItem(AcDb::DxfCode dc, int8_t val);
	Acad::ErrorStatus writeItem(AcDb::DxfCode dc, uint32_t val);
	Acad::ErrorStatus writeItem(AcDb::DxfCode dc, uint16_t val);
	Acad::ErrorStatus writeItem(AcDb::DxfCode dc, uint8_t val);
	Acad::ErrorStatus writeItem(AcDb::DxfCode dc, bool val);
	Acad::ErrorStatus writeItem(AcDb::DxfCode dc, double val, int = kDfltPrec);
	Acad::ErrorStatus writeItem(AcDb::DxfCode dc, const AcGePoint2d& val, int prec = kDfltPrec);
	Acad::ErrorStatus writeItem(AcDb::DxfCode dc, const AcGePoint3d& val, int prec = kDfltPrec);
	Acad::ErrorStatus writeItem(AcDb::DxfCode dc, const AcGeVector2d& val, int prec = kDfltPrec);
	Acad::ErrorStatus writeItem(AcDb::DxfCode dc, const AcGeVector3d& val, int prec = kDfltPrec);
	Acad::ErrorStatus writeItem(AcDb::DxfCode dc, const AcGeScale3d& val, int prec = kDfltPrec);
	virtual Acad::ErrorStatus writeObjectId(AcDb::DxfCode code, const AcDbObjectId& id) = 0;
	virtual Acad::ErrorStatus writePoint2d(AcDb::DxfCode code, const AcGePoint2d& val,
										   int prec = kDfltPrec) = 0;
	virtual Acad::ErrorStatus writePoint3d(AcDb::DxfCode code, const AcGePoint3d& val,
										   int prec = kDfltPrec) = 0;
	virtual Acad::ErrorStatus writeResBuf(const resbuf& rb);
	virtual Acad::ErrorStatus writeScale3d(AcDb::DxfCode code, const AcGeScale3d& val,
										   int prec = kDfltPrec) = 0;
	virtual Acad::ErrorStatus writeString(AcDb::DxfCode code, const ACHAR* pVal) = 0;
	virtual Acad::ErrorStatus writeString(AcDb::DxfCode code, const AcString& pVal) = 0;
	virtual Acad::ErrorStatus writeUInt16(AcDb::DxfCode code, uint16_t val) = 0;
	virtual Acad::ErrorStatus writeUInt32(AcDb::DxfCode code, uint32_t val) = 0;
	virtual Acad::ErrorStatus writeUInt64(AcDb::DxfCode code, uint64_t val) = 0;
	virtual Acad::ErrorStatus writeUInt8(AcDb::DxfCode code, uint8_t val) = 0;
	virtual Acad::ErrorStatus writeVector2d(AcDb::DxfCode code, const AcGeVector2d& val,
											int prec = kDfltPrec) = 0;
	virtual Acad::ErrorStatus writeVector3d(AcDb::DxfCode code, const AcGeVector3d& val,
											int prec = kDfltPrec) = 0;
	virtual Acad::ErrorStatus writeXDataStart();
};

#include "IcArxPackPop.h"

inline Acad::ErrorStatus AcDbDxfFiler::readItem(resbuf* pVal)
{
	return readResBuf(pVal);
}

inline Acad::ErrorStatus AcDbDxfFiler::writeItem(const resbuf& val)
{
	return writeResBuf(val);
}

inline Acad::ErrorStatus AcDbDxfFiler::writeItem(AcDb::DxfCode dc, const AcDbObjectId& id)
{
	return writeObjectId(dc, id);
}

inline Acad::ErrorStatus AcDbDxfFiler::writeItem(AcDb::DxfCode dc, const ACHAR* val)
{
	return writeString(dc, val);
}

inline Acad::ErrorStatus AcDbDxfFiler::writeItem(AcDb::DxfCode dc, const ads_binary& val)
{
	return writeBChunk(dc, val);
}

inline Acad::ErrorStatus AcDbDxfFiler::writeItem(AcDb::DxfCode dc, const AcDbHandle& val)
{
	return writeAcDbHandle(dc, val);
}

inline Acad::ErrorStatus AcDbDxfFiler::writeItem(AcDb::DxfCode dc, int32_t val)
{
	return writeInt32(dc, val);
}

inline Acad::ErrorStatus AcDbDxfFiler::writeItem(AcDb::DxfCode dc, int16_t val)
{
	return writeInt16(dc, val);
}

inline Acad::ErrorStatus AcDbDxfFiler::writeItem(AcDb::DxfCode dc, int8_t val)
{
	return this->writeInt8(dc, val);
}

inline Acad::ErrorStatus AcDbDxfFiler::writeItem(AcDb::DxfCode dc, uint32_t val)
{
	return writeUInt32(dc, val);
}

inline Acad::ErrorStatus AcDbDxfFiler::writeItem(AcDb::DxfCode dc, uint16_t val)
{
	return writeUInt16(dc, val);
}

inline Acad::ErrorStatus AcDbDxfFiler::writeItem(AcDb::DxfCode dc, uint8_t val)
{
	return writeUInt8(dc, val);
}

inline Acad::ErrorStatus AcDbDxfFiler::writeItem(AcDb::DxfCode dc, bool val)
{
	return writeBool(dc, val);
}

inline Acad::ErrorStatus AcDbDxfFiler::writeItem(AcDb::DxfCode dc, double val, int prec)
{
	return writeDouble(dc, val, prec);
}

inline Acad::ErrorStatus AcDbDxfFiler::writeItem(AcDb::DxfCode dc, const AcGePoint2d& val, int prec)
{
	return writePoint2d(dc, val, prec);
}

inline Acad::ErrorStatus AcDbDxfFiler::writeItem(AcDb::DxfCode dc, const AcGePoint3d& val, int prec)
{
	return writePoint3d(dc, val, prec);
}

inline Acad::ErrorStatus AcDbDxfFiler::writeItem(AcDb::DxfCode dc, const AcGeVector2d& val,
												 int prec)
{
	return writeVector2d(dc, val, prec);
}

inline Acad::ErrorStatus AcDbDxfFiler::writeItem(AcDb::DxfCode dc, const AcGeVector3d& val,
												 int prec)
{
	return writeVector3d(dc, val, prec);
}

inline Acad::ErrorStatus AcDbDxfFiler::writeItem(AcDb::DxfCode dc, const AcGeScale3d& val, int prec)
{
	return writeScale3d(dc, val, prec);
}

inline Acad::ErrorStatus AcDbDxfFiler::writeItem(AcDb::DxfCode dc, const AcString& val)
{
	return writeString(dc, val);
}

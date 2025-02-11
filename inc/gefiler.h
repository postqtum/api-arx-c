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
***     Description:  Declaration of AcGeFiler struct
***
*****************************************************************************/
#pragma once

#include "AdAChar.h"
#include "gegbl.h"
#include "acdb.h"
#include "acadstrc.h"

class AcDbDwgFiler;
class AcGePoint2d;
class AcGePoint3d;
class AcGeVector2d;
class AcGeVector3d;
class AcString;

#include "icarx/IcArxPackPush.h"

class ADESK_NO_VTABLE AcGeFiler
{
protected:
	GE_DLLEXPIMPORT AcGeFiler();

public:
	GE_DLLEXPIMPORT virtual AcDbDwgFiler* dwgFiler();

	GE_DLLEXPIMPORT virtual Acad::ErrorStatus readBool(bool*) = 0;
	GE_DLLEXPIMPORT virtual Acad::ErrorStatus readBoolean(bool*) = 0;
	GE_DLLEXPIMPORT virtual Acad::ErrorStatus readBytes(void*, uint32_t) = 0;
	GE_DLLEXPIMPORT virtual Acad::ErrorStatus readDouble(double*) = 0;
	GE_DLLEXPIMPORT virtual Acad::ErrorStatus readLong(int32_t*) = 0;
	GE_DLLEXPIMPORT virtual Acad::ErrorStatus readPoint2d(AcGePoint2d*) = 0;
	GE_DLLEXPIMPORT virtual Acad::ErrorStatus readPoint3d(AcGePoint3d*) = 0;
	GE_DLLEXPIMPORT virtual Acad::ErrorStatus readShort(short*) = 0;
	GE_DLLEXPIMPORT virtual Acad::ErrorStatus readSignedByte(char*) = 0;
	GE_DLLEXPIMPORT virtual Acad::ErrorStatus readString(AcString&) = 0;
	GE_DLLEXPIMPORT virtual Acad::ErrorStatus readUChar(unsigned char*) = 0;
	GE_DLLEXPIMPORT virtual Acad::ErrorStatus readULong(uint32_t*) = 0;
	GE_DLLEXPIMPORT virtual Acad::ErrorStatus readUShort(unsigned short*) = 0;
	GE_DLLEXPIMPORT virtual Acad::ErrorStatus readVector2d(AcGeVector2d*) = 0;
	GE_DLLEXPIMPORT virtual Acad::ErrorStatus readVector3d(AcGeVector3d*) = 0;

	GE_DLLEXPIMPORT virtual Acad::ErrorStatus writeBool(bool) = 0;
	GE_DLLEXPIMPORT virtual Acad::ErrorStatus writeBoolean(bool) = 0;
	GE_DLLEXPIMPORT virtual Acad::ErrorStatus writeBytes(const void*, uint32_t) = 0;
	GE_DLLEXPIMPORT virtual Acad::ErrorStatus writeDouble(double) = 0;
	GE_DLLEXPIMPORT virtual Acad::ErrorStatus writeLong(int32_t) = 0;
	GE_DLLEXPIMPORT virtual Acad::ErrorStatus writePoint2d(const AcGePoint2d&) = 0;
	GE_DLLEXPIMPORT virtual Acad::ErrorStatus writePoint3d(const AcGePoint3d&) = 0;
	GE_DLLEXPIMPORT virtual Acad::ErrorStatus writeShort(short) = 0;
	GE_DLLEXPIMPORT virtual Acad::ErrorStatus writeSignedByte(char) = 0;
	GE_DLLEXPIMPORT virtual Acad::ErrorStatus writeString(const AcString&) = 0;
	GE_DLLEXPIMPORT virtual Acad::ErrorStatus writeUChar(unsigned char) = 0;
	GE_DLLEXPIMPORT virtual Acad::ErrorStatus writeULong(uint32_t) = 0;
	GE_DLLEXPIMPORT virtual Acad::ErrorStatus writeUShort(unsigned short) = 0;
	GE_DLLEXPIMPORT virtual Acad::ErrorStatus writeVector2d(const AcGeVector2d&) = 0;
	GE_DLLEXPIMPORT virtual Acad::ErrorStatus writeVector3d(const AcGeVector3d&) = 0;
};

#include "icarx/IcArxPackPop.h"

inline AcDbDwgFiler* AcGeFiler::dwgFiler()
{
	return nullptr;
}

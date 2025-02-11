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
***     Description: Declaration of AcGeLibVersion class
***
*****************************************************************************/
#pragma once

#include "adesk.h"
#include "gedll.h"

#define IMAGE_MAJOR_VER 2
#define IMAGE_MINOR_VER 0
#define IMAGE_CORRECTIVE_VER 0
#define IMAGE_INTERNAL_VER 0

#include "icarx/IcArxPackPush.h"

class AcGeLibVersion
{
private:
	uint8_t mVersion[10];

public:
	GE_DLLDATAEXIMP static const AcGeLibVersion kRelease0_95;
	GE_DLLDATAEXIMP static const AcGeLibVersion kReleaseSed;
	GE_DLLDATAEXIMP static const AcGeLibVersion kReleaseTah;

public:
	GE_DLLEXPIMPORT AcGeLibVersion();
	GE_DLLEXPIMPORT AcGeLibVersion(uint8_t major, uint8_t minor, uint8_t corrective,
								   uint8_t internal_version);
	GE_DLLEXPIMPORT AcGeLibVersion(const AcGeLibVersion&);
	~AcGeLibVersion() = default;
	AcGeLibVersion& operator=(const AcGeLibVersion&) = default;
	GE_DLLEXPIMPORT bool operator==(const AcGeLibVersion&) const;
	GE_DLLEXPIMPORT bool operator!=(const AcGeLibVersion&) const;
	GE_DLLEXPIMPORT bool operator<(const AcGeLibVersion&) const;
	GE_DLLEXPIMPORT bool operator<=(const AcGeLibVersion&) const;
	GE_DLLEXPIMPORT bool operator>(const AcGeLibVersion&) const;
	GE_DLLEXPIMPORT bool operator>=(const AcGeLibVersion&) const;

	GE_DLLEXPIMPORT uint8_t correctiveVersion() const;
	GE_DLLEXPIMPORT uint8_t majorVersion() const;
	GE_DLLEXPIMPORT uint8_t minorVersion() const;
	GE_DLLEXPIMPORT uint8_t schemaVersion() const;
	GE_DLLEXPIMPORT AcGeLibVersion& setCorrectiveVersion(uint8_t val);
	GE_DLLEXPIMPORT AcGeLibVersion& setMajorVersion(uint8_t val);
	GE_DLLEXPIMPORT AcGeLibVersion& setMinorVersion(uint8_t val);
	GE_DLLEXPIMPORT AcGeLibVersion& setSchemaVersion(uint8_t val);
};

#include "icarx/IcArxPackPop.h"

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
***     Description: Declaration of AcCmTransparency class
***
*****************************************************************************/
#pragma once

#include <cstdint>

#include "IcArxPackPush.h"

class AcCmTransparency
{
public:
	enum transparencyMethod
	{
		kByLayer = 0,
		kByBlock,
		kByAlpha,
		kErrorValue
	};

	enum
	{
		kTransparencyByLayer = (unsigned long)kByLayer,
		kTransparencyByBlock = (unsigned long)kByBlock,
		kTransparencySolid = ((unsigned long)(kByAlpha | (0xff << 24))),
		kTransparencyClear = (unsigned long)kByAlpha
	};

private:
	union AM
	{
		struct
		{
			uint8_t alpha;
			uint8_t reserved1;
			uint8_t reserved2;
			uint8_t method;
		} mdata;
		uint32_t whole;
	};

private:
	AM mAM;

public:
	AcCmTransparency() { mAM.whole = kTransparencyByLayer; }
	AcCmTransparency(uint8_t alpha);
	AcCmTransparency(double alphaPercent);
	AcCmTransparency(const AcCmTransparency& other) { mAM.whole = other.mAM.whole; }
	~AcCmTransparency() = default;
	AcCmTransparency& operator=(const AcCmTransparency& other);
	bool operator==(const AcCmTransparency& other) const;
	bool operator!=(const AcCmTransparency& other) const;

	uint8_t alpha() const;
	double alphaPercent() const;
	bool isByAlpha() const { return (mAM.mdata.method == kByAlpha); }
	bool isByBlock() const { return (mAM.mdata.method == kByBlock); }
	bool isByLayer() const { return (mAM.mdata.method == kByLayer); }
	bool isClear() const;
	bool isInvalid() const { return (mAM.mdata.method == kErrorValue); }
	bool isSolid() const;
	void serializeIn(uint32_t);
	uint32_t serializeOut() const { return mAM.whole; }
	void setAlpha(uint8_t alpha);
	void setAlphaPercent(double alphaPercent);
	void setMethod(transparencyMethod method);
};

#include "IcArxPackPop.h"

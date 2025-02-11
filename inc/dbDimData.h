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
***     Description: Declaration of AcDbDimData class
***
*****************************************************************************/
#pragma once

#include "acdb.h"
#include "acarray.h"
#include "dbdim.h"

class AcDbDimData;

typedef AcArray<AcDbDimData*> AcDbDimDataPtrArray;
typedef AcGeVector3d (*DimDataSetValueFuncPtr)(AcDbDimData* pThis, AcDbEntity* pEnt,
											   double newValue, const AcGeVector3d& offset);
typedef AcGeVector3d (*DimDataSetCustomStringFuncPtr)(AcDbDimData* pThis, AcDbEntity* pEnt,
													  const ACHAR* pCustomString,
													  const AcGeVector3d& offset);

#include "icarx/IcArxPackPush.h"

class AcDbDimData
{
public:
	enum DimDataFlags
	{
		kDimEditable = 0x1,
		kDimInvisible = 0x2,
		kDimFocal = 0x4,
		kDimHideIfValueIsZero = 0x8,
		kDimEmptyData = 0x10,
		kDimResultantLength = 0x20,
		kDimDeltaLength = 0x40,
		kDimResultantAngle = 0x80,
		kDimDeltaAngle = 0x100,
		kDimRadius = 0x200,
		kDimCustomValue = 0x400,
		kDimConstrained = 0x800,
		kDimCustomString = 0x1000
	};

private:
	AcDbDimension* mpDim;
	AcDbObjectId mOwnerId;
	unsigned int mBitFlags;
	DimDataSetValueFuncPtr mpSetDimValueFunc;
	void* mpAppData;
	DimDataSetCustomStringFuncPtr mpSetCustomStringFunc;

public:
	AcDbDimData();
	AcDbDimData(const AcDbDimData&);
	AcDbDimData(AcDbDimension* pDim, DimDataSetValueFuncPtr setDimFunc = nullptr,
				unsigned int bitFlags = 0, void* appData = nullptr,
				DimDataSetCustomStringFuncPtr setCustomStringFunc = nullptr);
	~AcDbDimData();
	AcDbDimData& operator=(const AcDbDimData&);

	void* appData() const;
	unsigned int bitFlags() const;
	DimDataSetCustomStringFuncPtr customStringFunc() const;
	DimDataSetValueFuncPtr dimValueFunc() const;
	AcDbDimension* dimension() const;
	bool isConstrained() const;
	bool isCustomDimValue() const;
	bool isCustomString() const;
	bool isDimDeltaAngle() const;
	bool isDimDeltaLength() const;
	bool isDimEditable() const;
	bool isDimFocal() const;
	bool isDimHideIfValueIsZero() const;
	bool isDimInvisible() const;
	bool isDimRadius() const;
	bool isDimResultantAngle() const;
	bool isDimResultantLength() const;
	AcDbObjectId ownerId() const;
	Acad::ErrorStatus setAppData(void* appData);
	Acad::ErrorStatus setBitFlags(unsigned int flags);
	Acad::ErrorStatus setConstrain(bool bValue);
	Acad::ErrorStatus setCustomDimValue(bool custom);
	Acad::ErrorStatus setCustomString(bool bValue);
	Acad::ErrorStatus setCustomStringFunc(DimDataSetCustomStringFuncPtr funcPtr);
	Acad::ErrorStatus setDimDeltaAngle(bool bValue);
	Acad::ErrorStatus setDimDeltaLength(bool bValue);
	Acad::ErrorStatus setDimEditable(bool editable);
	Acad::ErrorStatus setDimFocal(bool focal);
	Acad::ErrorStatus setDimHideIfValueIsZero(bool hide);
	Acad::ErrorStatus setDimInvisible(bool invisible);
	Acad::ErrorStatus setDimRadius(bool bValue);
	Acad::ErrorStatus setDimResultantAngle(bool bValue);
	Acad::ErrorStatus setDimResultantLength(bool bValue);
	Acad::ErrorStatus setDimValueFunc(DimDataSetValueFuncPtr funcPtr);
	Acad::ErrorStatus setDimension(AcDbDimension* pDim);
	Acad::ErrorStatus setOwnerId(const AcDbObjectId& objId);
};

#include "icarx/IcArxPackPop.h"

inline AcDbDimData::AcDbDimData()
		: mpDim(nullptr)
		, mBitFlags(0)
		, mpSetDimValueFunc(nullptr)
		, mpAppData(nullptr)
		, mpSetCustomStringFunc(nullptr)
{
}

inline AcDbDimData::AcDbDimData(AcDbDimension* pDim, DimDataSetValueFuncPtr setValueFunc,
								unsigned int bitFlags, void* appData,
								DimDataSetCustomStringFuncPtr setCustomStringFunc)
		: mpDim(pDim)
		, mBitFlags(bitFlags)
		, mpSetDimValueFunc(setValueFunc)
		, mpAppData(appData)
		, mpSetCustomStringFunc(setCustomStringFunc)
{
}

inline AcDbDimData::AcDbDimData(const AcDbDimData& src)
{
	*this = src;
}

inline AcDbDimData::~AcDbDimData()
{
	if (mpDim)
		delete mpDim;
}

inline AcDbDimData& AcDbDimData::operator=(const AcDbDimData& src)
{
	if (this == &src)
		return *this;

	mpDim = (AcDbDimension*)src.dimension()->clone();
	mOwnerId = src.ownerId();
	mpSetDimValueFunc = src.dimValueFunc();
	mpSetCustomStringFunc = src.customStringFunc();
	mBitFlags = src.bitFlags();
	mpAppData = src.appData();
	return *this;
}

inline void* AcDbDimData::appData() const
{
	return mpAppData;
}

inline unsigned int AcDbDimData::bitFlags() const
{
	return mBitFlags;
}

inline DimDataSetCustomStringFuncPtr AcDbDimData::customStringFunc() const
{
	return mpSetCustomStringFunc;
}

inline DimDataSetValueFuncPtr AcDbDimData::dimValueFunc() const
{
	return mpSetDimValueFunc;
}

inline AcDbDimension* AcDbDimData::dimension() const
{
	return mpDim;
}

inline bool AcDbDimData::isConstrained() const
{
	return !!(mBitFlags & kDimConstrained);
}

inline bool AcDbDimData::isCustomDimValue() const
{
	return !!(mBitFlags & kDimCustomValue);
}

inline bool AcDbDimData::isCustomString() const
{
	return !!(mBitFlags & kDimCustomString);
}

inline bool AcDbDimData::isDimDeltaAngle() const
{
	return !!(mBitFlags & kDimDeltaAngle);
}

inline bool AcDbDimData::isDimDeltaLength() const
{
	return !!(mBitFlags & kDimDeltaLength);
}

inline bool AcDbDimData::isDimEditable() const
{
	return !!(mBitFlags & kDimEditable);
}

inline bool AcDbDimData::isDimFocal() const
{
	return !!(mBitFlags & kDimFocal);
}

inline bool AcDbDimData::isDimHideIfValueIsZero() const
{
	return !!(mBitFlags & kDimHideIfValueIsZero);
}

inline bool AcDbDimData::isDimInvisible() const
{
	return !!(mBitFlags & kDimInvisible);
}

inline bool AcDbDimData::isDimRadius() const
{
	return !!(mBitFlags & kDimRadius);
}

inline bool AcDbDimData::isDimResultantAngle() const
{
	return !!(mBitFlags & kDimResultantAngle);
}

inline bool AcDbDimData::isDimResultantLength() const
{
	return !!(mBitFlags & kDimResultantLength);
}

inline AcDbObjectId AcDbDimData::ownerId() const
{
	return mOwnerId;
}

inline Acad::ErrorStatus AcDbDimData::setAppData(void* appData)
{
	mpAppData = appData;
	return Acad::eOk;
}

inline Acad::ErrorStatus AcDbDimData::setBitFlags(unsigned int flags)
{
	mBitFlags = flags;
	return Acad::eOk;
}

inline Acad::ErrorStatus AcDbDimData::setConstrain(bool bValue)
{
	if (bValue)
		mBitFlags |= kDimConstrained;
	else
		mBitFlags &= ~kDimConstrained;
	return Acad::eOk;
}

inline Acad::ErrorStatus AcDbDimData::setCustomDimValue(bool custom)
{
	if (custom)
		mBitFlags |= kDimCustomValue;
	else
		mBitFlags &= ~kDimCustomValue;
	return Acad::eOk;
}

inline Acad::ErrorStatus AcDbDimData::setCustomString(bool bValue)
{
	if (bValue)
		mBitFlags |= kDimCustomString;
	else
		mBitFlags &= ~kDimCustomString;
	return Acad::eOk;
}

inline Acad::ErrorStatus AcDbDimData::setCustomStringFunc(DimDataSetCustomStringFuncPtr funcPtr)
{
	mpSetCustomStringFunc = funcPtr;
	return Acad::eOk;
}

inline Acad::ErrorStatus AcDbDimData::setDimDeltaAngle(bool bValue)
{
	if (bValue)
		mBitFlags |= kDimDeltaAngle;
	else
		mBitFlags &= ~kDimDeltaAngle;
	return Acad::eOk;
}

inline Acad::ErrorStatus AcDbDimData::setDimDeltaLength(bool bValue)
{
	if (bValue)
		mBitFlags |= kDimDeltaLength;
	else
		mBitFlags &= ~kDimDeltaLength;
	return Acad::eOk;
}

inline Acad::ErrorStatus AcDbDimData::setDimEditable(bool editable)
{
	if (editable)
		mBitFlags |= kDimEditable;
	else
		mBitFlags &= ~kDimEditable;
	return Acad::eOk;
}

inline Acad::ErrorStatus AcDbDimData::setDimFocal(bool focal)
{
	if (focal)
		mBitFlags |= kDimFocal;
	else
		mBitFlags &= ~kDimFocal;
	return Acad::eOk;
}

inline Acad::ErrorStatus AcDbDimData::setDimHideIfValueIsZero(bool hide)
{
	if (hide)
		mBitFlags |= kDimHideIfValueIsZero;
	else
		mBitFlags &= ~kDimHideIfValueIsZero;
	return Acad::eOk;
}

inline Acad::ErrorStatus AcDbDimData::setDimInvisible(bool invisible)
{
	if (invisible)
		mBitFlags |= kDimInvisible;
	else
		mBitFlags &= ~kDimInvisible;
	return Acad::eOk;
}

inline Acad::ErrorStatus AcDbDimData::setDimRadius(bool bValue)
{
	if (bValue)
		mBitFlags |= kDimRadius;
	else
		mBitFlags &= ~kDimRadius;
	return Acad::eOk;
}

inline Acad::ErrorStatus AcDbDimData::setDimResultantAngle(bool bValue)
{
	if (bValue)
		mBitFlags |= kDimResultantAngle;
	else
		mBitFlags &= ~kDimResultantAngle;
	return Acad::eOk;
}

inline Acad::ErrorStatus AcDbDimData::setDimResultantLength(bool bValue)
{
	if (bValue)
		mBitFlags |= kDimResultantLength;
	else
		mBitFlags &= ~kDimResultantLength;
	return Acad::eOk;
}

inline Acad::ErrorStatus AcDbDimData::setDimValueFunc(DimDataSetValueFuncPtr funcPtr)
{
	mpSetDimValueFunc = funcPtr;
	return Acad::eOk;
}

inline Acad::ErrorStatus AcDbDimData::setDimension(AcDbDimension* pDim)
{
	mpDim = pDim;
	return Acad::eOk;
}

inline Acad::ErrorStatus AcDbDimData::setOwnerId(const AcDbObjectId& objId)
{
	mOwnerId = objId;
	return Acad::eOk;
}

using AcDbDimDataArray = AcArray<AcDbDimData>;

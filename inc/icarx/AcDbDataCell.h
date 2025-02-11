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
***     Description: Declaration of AcDbDataCell class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../acarray.h"
#include "../gepnt3d.h"

class AcDbImpDataCell;
class AcDbObjectId;
class AcDbHardOwnershipId;
class AcDbSoftOwnershipId;
class AcDbHardPointerId;
class AcDbSoftPointerId;
class AcString;

#include "IcArxPackPush.h"
#pragma warning(disable : 4275 4251)

class AcDbDataCell : public AcRxObject
{
	friend class AcDbSystemInternals;

public:
	enum CellType
	{
		kUnknown = 0,
		kInteger,
		kDouble,
		kCharPtr,
		kPoint,
		kObjectId,
		kHardOwnerId,
		kSoftOwnerId,
		kHardPtrId,
		kSoftPtrId,
		kBool,
		kVector
	};

private:
	AcDbImpDataCell* mpImpDataCell = nullptr;

public:
	AcDbDataCell();
	AcDbDataCell(const AcDbDataCell& rCell);
	AcDbDataCell(bool b);
	AcDbDataCell(int i);
	AcDbDataCell(double d);
	AcDbDataCell(const ACHAR* pChar);
	AcDbDataCell(const AcGePoint3d& point);
	AcDbDataCell(const AcGeVector3d& vec);
	AcDbDataCell(const AcDbObjectId& id);
	AcDbDataCell(const AcDbHardOwnershipId& hoId);
	AcDbDataCell(const AcDbSoftOwnershipId& soId);
	AcDbDataCell(const AcDbHardPointerId& hpId);
	AcDbDataCell(const AcDbSoftPointerId& spId);
	~AcDbDataCell();
	virtual AcDbDataCell& operator=(const AcDbObjectId& id);
	virtual AcDbDataCell& operator=(const AcDbHardOwnershipId& hoId);
	virtual AcDbDataCell& operator=(const AcDbSoftOwnershipId& soId);
	virtual AcDbDataCell& operator=(const AcDbHardPointerId& hpId);
	virtual AcDbDataCell& operator=(const AcDbSoftPointerId& spId);
	ACDBCORE2D_PORT virtual AcDbDataCell& operator=(const AcString& s);
	virtual AcDbDataCell& operator=(const ACHAR* pChar);
	virtual AcDbDataCell& operator=(double d);
	virtual AcDbDataCell& operator=(int i);
	virtual AcDbDataCell& operator=(bool b);
	virtual AcDbDataCell& operator=(const AcGePoint3d& pt);
	virtual AcDbDataCell& operator=(const AcDbDataCell& cell);
	virtual AcDbDataCell& operator=(const AcGeVector3d& vec);
	virtual bool operator==(const AcDbDataCell& cell) const;
	virtual bool operator!=(const AcDbDataCell& cell) const;
	virtual operator AcDbHardOwnershipId&() const;
	virtual operator AcDbHardPointerId&() const;
	virtual operator AcDbObjectId&() const;
	virtual operator AcDbSoftOwnershipId&() const;
	virtual operator AcDbSoftPointerId&() const;
	virtual operator AcGePoint3d&() const;
	virtual operator AcGeVector3d&() const;
	ACDBCORE2D_PORT virtual operator AcString&() const;
	virtual operator bool() const;
	virtual operator const ACHAR*() const;
	virtual operator double() const;
	virtual operator int() const;

	ACRX_DECLARE_MEMBERS(AcDbDataCell);

	virtual void init();
	virtual AcDbDataCell::CellType type() const;
};

#include "IcArxPackPop.h"

typedef AcArray<AcDbDataCell, AcArrayObjectCopyReallocator<AcDbDataCell> > AcDbDataCellArray;

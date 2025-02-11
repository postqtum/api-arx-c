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
***     Description: Declaration of AcDbCompoundObjectId class
***
*****************************************************************************/
#pragma once

#include "AcDbCore2dDefs.h"

#include "rxobject.h"

#include "dbidar.h"

class AcDbDwgFiler;
class AcDbDxfFiler;
class AcDbIdMapping;
class AcDbObject;
class AcGeMatrix3d;
class AcDbImpCompoundObjectId;

#include "icarx/IcArxPackPush.h"

class ACDBCORE2D_PORT AcDbCompoundObjectId : public AcRxObject
{
public:
	enum Status
	{
		kValid = 0,
		kWasLoadedNowUnloaded = 1,
		kCouldNotResolveNonTerminal = 2,
		kCouldNotResolveTerminal = 3,
		kCouldNotResolveTooEarly = 4,
		kIncompatibleIdType = 1000
	};

private:
	AcDbImpCompoundObjectId* mpImp;

public:
	ACRX_DECLARE_MEMBERS(AcDbCompoundObjectId);

public:
	AcDbCompoundObjectId();
	AcDbCompoundObjectId(const AcDbObjectId& id, AcDbDatabase* pHostDatabase = nullptr);
	AcDbCompoundObjectId(const AcDbCompoundObjectId&);
	AcDbCompoundObjectId(const AcDbObjectId& id, const AcDbObjectIdArray& path,
						 AcDbDatabase* pHostDatabase = nullptr);
	~AcDbCompoundObjectId();
	AcDbCompoundObjectId& operator=(const AcDbObjectId&);
	AcDbCompoundObjectId& operator=(const AcDbCompoundObjectId&);
	bool operator==(const AcDbCompoundObjectId&) const;
	bool operator!=(const AcDbCompoundObjectId& other) const { return !(*this == other); }

	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler, int ownerVersion);
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler, AcDbDatabase* pHostDatabase) const;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler, AcDbDatabase* pHostDatabase,
								  int ownerVersion);
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler, AcDbDatabase* pHostDatabase) const;
	Acad::ErrorStatus getFullPath(AcDbObjectIdArray& fullPath) const;
	Acad::ErrorStatus getPath(AcDbObjectIdArray& path) const;
	Acad::ErrorStatus getTransform(AcGeMatrix3d& trans) const;
	bool isEmpty() const;
	bool isExternal() const;
	bool isSimpleObjectId() const;
	bool isValid(int validityCheckingLevel = 1) const;
	AcDbObjectId leafId() const;
	static const AcDbCompoundObjectId& nullId();
	bool remap(const AcDbIdMapping& idMap);
	Acad::ErrorStatus set(const AcDbObjectId&, AcDbDatabase* pHostDatabase = nullptr);
	Acad::ErrorStatus set(const AcDbCompoundObjectId&, AcDbDatabase* pHostDatabase = nullptr);
	Acad::ErrorStatus set(const AcDbObjectId& id, const AcDbObjectIdArray& path,
						  AcDbDatabase* pHostDatabase = nullptr);
	void setEmpty();
	Acad::ErrorStatus setFullPath(const AcDbObjectIdArray& fullPath,
								  AcDbDatabase* pHostDatabase = nullptr);
	AcDbCompoundObjectId::Status status() const;
	AcDbObjectId topId() const;
};

class ACDBCORE2D_PORT AcDbParentTransformOfChildPE : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcDbParentTransformOfChildPE);

	virtual Acad::ErrorStatus getParentTransformOfChild(
			const AcDbObject* pThisParent, const AcDbObjectId& childId, AcGeMatrix3d&) = 0;
};

#include "icarx/IcArxPackPop.h"

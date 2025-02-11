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
***     Description: Declaration of AcRxClass class
***
*****************************************************************************/
#pragma once

#include "acbasedefs.h"
#include "rxobject.h"
#include "AdAChar.h"

class AcRxMemberCollection;
class AcRxAttributeCollection;
class AcRxSet;
class AcRxImpClass;
class AcRxMemberCollectionBuilder;
using AcRxMemberCollectionConstructorPtr = void (*)(AcRxMemberCollectionBuilder&, void*);

#include "icarx/IcArxPackPush.h"

class AcRxClass : public AcRxObject
{
	friend class AcRxImpClass;

private:
	AcRxImpClass* m_pImp;

private:
	AcRxClass();
	AcRxClass(const AcRxClass&) = delete;
	AcRxClass operator=(const AcRxClass&) = delete;

	void isKindOf(void*);

protected:
	AcRxClass(const ACHAR* name, const ACHAR* parent,
			  AcRxMemberCollectionConstructorPtr memberConstruct, void* userData);
	~AcRxClass();

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcRxClass, ACBASE_PORT);

	ACBASE_PORT AcRxObject* addX(AcRxClass*, AcRxObject*);
	ACBASE_PORT const ACHAR* appName() const;
	ACBASE_PORT ArxAppNameChangeFuncPtr appNameCallbackPtr() const;
	ACBASE_PORT const AcRxAttributeCollection& attributes() const;
	ACBASE_PORT AcRxAttributeCollection& attributes();
	ACBASE_PORT AcRx::Ordering comparedTo(const AcRxObject*) const override;
	ACBASE_PORT AcRxObject* create();
	ACBASE_PORT AcRxObject* delX(AcRxClass*);
	ACBASE_PORT const AcRxSet* descendants() const;
	ACBASE_PORT const ACHAR* dxfName() const;
	ACBASE_PORT void getClassVersion(int& dwgVer, int& maintVer) const;
	ACBASE_PORT AcRxObject* getX(const AcRxClass*);
	bool isDerivedFrom(const AcRxClass*) const;
	static ACBASE_PORT bool isDerivedFrom(const AcRxClass* pDerived, const AcRxClass* pBase);
	ACBASE_PORT AcRxMemberCollection* members() const;
	ACBASE_PORT AcRxClass* myParent() const;
	ACBASE_PORT const ACHAR* name() const;
	ACBASE_PORT int proxyFlags() const;
	ACBASE_PORT AcRxObject* queryX(const AcRxClass*);
	ACBASE_PORT AcRxObject* queryX(const AcRxClass*) const;
};

#include "icarx/IcArxPackPop.h"

using RxInitFuncPtr = void (*)();

ACBASE_PORT void acrxBuildClassHierarchy();
AcRxClass* acrxQueueClassForInitialization(AcRxClass** pgpDesc, RxInitFuncPtr rxInit);
ACBASE_PORT void deleteAcRxClass(AcRxClass* pClassObj);
ACBASE_PORT AcRxClass* newAcRxClass(const ACHAR* className, const ACHAR* parentClassName,
									int proxyFlags = 0, AcRxObject* (*pseudoConstructor)() = nullptr,
									const ACHAR* dxfName = nullptr, const ACHAR* appName = nullptr);
ACBASE_PORT AcRxClass* newAcRxClass(const ACHAR* className, const ACHAR* parentClassName,
									int dwgVer, int maintVer, int proxyFlags = 0,
									AcRxObject* (*pseudoConstructor)() = nullptr,
									const ACHAR* dxfName = nullptr, const ACHAR* appName = nullptr,
									ArxAppNameChangeFuncPtr func = nullptr);
ACBASE_PORT AcRxClass* newAcRxClass(const ACHAR* className, const ACHAR* parentClassName,
									int dwgVer, int maintVer, int proxyFlags,
									AcRxObject* (*pseudoConstructor)(), const ACHAR* dxfName,
									const ACHAR* appName, ArxAppNameChangeFuncPtr func,
									AcRxMemberCollectionConstructorPtr makeMembers,
									void* userData = nullptr);

inline bool AcRxClass::isDerivedFrom(const AcRxClass* pOtherClass) const
{
	return AcRxClass::isDerivedFrom(this, pOtherClass);
}

inline bool AcRxObject::isKindOf(const AcRxClass* pOtherClass) const
{
	return AcRxClass::isDerivedFrom(this->isA(), pOtherClass);
}

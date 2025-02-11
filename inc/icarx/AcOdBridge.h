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
***     Description: Declaration of AcOdBridge class
***
*****************************************************************************/
#pragma once

#include <functional>

#include <Kernel/Include/RxRef_itc.h>

#include "IcArxBridgeDefs.h"

class AcRxObject;
class OdRxObject;

class ICARXBRIDGE_PORT AcOdBridge : public AcOdBridgeInterface
{
public:
	AcOdBridge();

	AcOdBridge(const AcOdBridge& other) = delete;
	AcOdBridge& operator=(const AcOdBridge& other) = delete;

	virtual ~AcOdBridge();
	void delete_me() override;

	// Increments ptr's ref counter
	AcOdBridge* resetOdRxObj(OdAcBridge* ptr = nullptr);
	// Does not increment ptr's ref counter
	AcOdBridge* attachToOdRxObj(OdAcBridge* ptr = nullptr);
	// Does not decrement pOdRxObj's counter
	OdAcBridge* detachFromOdRxObj();
	void releaseOdRxObj();
	const OdAcBridge* getBridge() const;
	OdAcBridge* getBridge();
	const OdRxObject* getOdRxObj() const;
	virtual OdRxObject* getOdRxObj();

	template<typename OdObject>
	const OdObject* getOdObj() const;
	template<typename OdObject>
	OdObject* getOdObj();

	template<typename OdObject>
	static const OdObject* getOdObj(const AcOdBridge* obj);

	template<typename OdObject>
	static OdObject* getOdObj(AcOdBridge* obj);

	template<typename AcObject>
	static const AcObject* getAcObj(const OdRxObject* obj);

	template<typename AcObject>
	static AcObject* getAcObj(OdRxObject* obj);

	static AcOdBridgeInterface* const& getAcRxObject(const OdAcBridge* obj);
	static AcOdBridgeInterface* getOrCreateAcRxObject(OdRxObject* od_obj);
	static AcOdBridgeInterface* getOrCreateAcRxObject(const OdRxObject* od_obj);

protected:
	void delayConstruction(std::function<void()>&& func);
	// To be called when this object is requested for the given OdAcBridge
	virtual void acObjectRequested(const OdAcBridge* obj);

private:
	void delayedConstruction();
	void resetDelayedConstruction();

private:
	// ODA implementation.
	OdAcBridge* pOdRxObj;
	void* pDelayedConstruction;
};

template<typename OdObject>
inline const OdObject* AcOdBridge::getOdObj() const
{
	static_assert(std::is_base_of<OdRxObject, OdObject>::value, "is_base_of<OdRxObject, OdObject>");
	return dynamic_cast<const OdObject*>(getOdRxObj());
}

template<typename OdObject>
inline OdObject* AcOdBridge::getOdObj()
{
	static_assert(std::is_base_of<OdRxObject, OdObject>::value, "is_base_of<OdRxObject, OdObject>");
	return dynamic_cast<OdObject*>(getOdRxObj());
}

template<typename OdObject>
inline OdObject* AcOdBridge::getOdObj(AcOdBridge* obj)
{
	if (obj == nullptr)
	{
		return nullptr;
	}
	return obj->getOdObj<OdObject>();
}

template<typename OdObject>
inline const OdObject* AcOdBridge::getOdObj(const AcOdBridge* obj)
{
	if (obj == nullptr)
	{
		return nullptr;
	}
	return obj->getOdObj<OdObject>();
}

template<typename AcObject>
inline AcObject* AcOdBridge::getAcObj(OdRxObject* obj)
{
	static_assert(std::is_base_of<AcRxObject, AcObject>::value, "is_base_of<AcRxObject, AcObject>");
	return dynamic_cast<AcObject*>(getOrCreateAcRxObject(obj));
}

template<typename AcObject>
inline const AcObject* AcOdBridge::getAcObj(const OdRxObject* obj)
{
	static_assert(std::is_base_of<AcRxObject, AcObject>::value, "is_base_of<AcRxObject, AcObject>");
	return dynamic_cast<AcObject*>(getOrCreateAcRxObject(obj));
}

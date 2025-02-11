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
***     Description: Declaration of AcGiLightAttenuation class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../rxboiler.h"

#include "IcArxPackPush.h"

class AcGiImpLightAttenuation;

class AcGiLightAttenuation : public AcRxObject
{
	friend class AcGiImpLightAttenuation;

public:
	enum AttenuationType
	{
		kNone = 0,
		kInverseLinear,
		kInverseSquare
	};

private:
	AcGiImpLightAttenuation* m_Imp;

public:
	ACRX_DECLARE_MEMBERS(AcGiLightAttenuation);

	AcGiLightAttenuation();
	~AcGiLightAttenuation();
	AcGiLightAttenuation(const AcGiLightAttenuation& atten);
	AcGiLightAttenuation(AcGiLightAttenuation&& atten) noexcept;

	AcGiLightAttenuation& operator=(const AcGiLightAttenuation& other);
	AcGiLightAttenuation& operator=(AcGiLightAttenuation&& other) noexcept;

	bool operator==(const AcGiLightAttenuation& atten) const;

	virtual AttenuationType attenuationType() const;
	virtual double endLimit() const;
	virtual void setAttenuationType(AttenuationType typ);
	virtual void setLimits(double startlim, double endlim);
	virtual void setUseLimits(bool on);
	virtual double startLimit() const;
	virtual bool useLimits() const;
};

#include "IcArxPackPop.h"

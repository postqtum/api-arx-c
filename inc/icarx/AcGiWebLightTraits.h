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
***     Description: Declaration of AcGiWebLightTraits class
***
*****************************************************************************/
#pragma once

#include "AcGiPointLightTraits.h"

#include "IcArxPackPush.h"

class AcGiWebLightTraits : public AcGiPointLightTraits
{
public:
	enum WebFileType
	{
		kTypeC = 1,
		kTypeB = 2,
		kTypeA = 3
	};

	enum WebSymmetry
	{
		kNoSymmetry = 0,
		kSingleSymmetry = 1,
		kDoubleSymmetry = 2,
		kAxialSymmetry = 3,
	};

public:
	ACRX_DECLARE_MEMBERS(AcGiWebLightTraits);

	virtual void setWebFile(const ACHAR* webFile) = 0;
	virtual void setWebFileType(WebFileType type) = 0;
	virtual void setWebFlux(double flux) const = 0;
	virtual void setWebHorzAng90to270(bool bIs90to270) = 0;
	virtual void setWebRotation(AcGeVector3d rotation) = 0;
	virtual void setWebSymmetry(WebSymmetry symmetry) = 0;
	virtual void webFile(AcString& webFile) const = 0;
	virtual WebFileType webFileType() const = 0;
	virtual double webFlux() const = 0;
	virtual bool webHorzAng90to270() const = 0;
	virtual void webRotation(AcGeVector3d& rotation) const = 0;
	virtual WebSymmetry webSymmetry() const = 0;
};

#include "IcArxPackPop.h"

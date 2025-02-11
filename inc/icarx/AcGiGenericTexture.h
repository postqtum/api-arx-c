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
***     Description: Declaration of AcGiGenericTexture classes
***
*****************************************************************************/
#pragma once

#include "AcGiMaterialTexture.h"

#include "IcArxPackPush.h"

class AcGiGenericTexture : public AcGiProceduralTexture
{
protected:
	AcGiVariant m_definition;

public:
	ACRX_DECLARE_MEMBERS(AcGiGenericTexture);

	AcGiGenericTexture();
	AcGiGenericTexture(const AcGiGenericTexture& texture);
	~AcGiGenericTexture();
	AcGiGenericTexture& operator=(const AcGiGenericTexture& texture);
	bool operator==(const AcGiMaterialTexture& texture) const override;

	Acad::ErrorStatus copyFrom(const AcRxObject* other) override;
	AcGiVariant definition() const;
	void definition(AcGiVariant*& pDefinition);
	void setDefinition(const AcGiVariant& definition);
};

#include "IcArxPackPop.h"

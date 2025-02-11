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
***     Description: Declaration of AcGiImageFileTexture classes
***
*****************************************************************************/
#pragma once

#include "AcGiMaterialTexture.h"

class AcGiImpImageFileTexture;

#include "IcArxPackPush.h"

class AcGiImageFileTexture : public AcGiImageTexture
{
private:
	AcGiImpImageFileTexture* mpAcGiImpImageFileTexture;

public:
	ACRX_DECLARE_MEMBERS(AcGiImageFileTexture);

	AcGiImageFileTexture();
	AcGiImageFileTexture(const AcGiImageFileTexture& texture);
	~AcGiImageFileTexture();
	AcGiImageFileTexture& operator=(const AcGiImageFileTexture& texture);
	bool operator==(const AcGiMaterialTexture& texture) const override;

	Acad::ErrorStatus copyFrom(const AcRxObject* other) override;
	virtual void setSourceFileName(const ACHAR* fileName);
	virtual const ACHAR* sourceFileName() const;
};

#include "IcArxPackPop.h"

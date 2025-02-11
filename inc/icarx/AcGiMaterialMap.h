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
***     Description: Declaration of AcGiMaterialMap classes
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../rxboiler.h"
#include "AcGiMaterialDefs.h"

class AcGiImpMaterialMap;
class AcGiMapper;
class AcGiMaterialTexture;

#include "IcArxPackPush.h"

class AcGiMaterialMap : public AcRxObject
{
public:
	enum Source
	{
		kScene = 0,
		kFile,
		kProcedural
	};

	enum Filter
	{
		kFilterDefault = 0,
		kFilterNone
	};

protected:
	AcGiImpMaterialMap* mpAcGiImpMaterialMap;

public:
	ACGIMAT_IMPEXP static const AcGiMaterialMap kNull;

public:
	ACRX_DECLARE_MEMBERS(AcGiMaterialMap);

	AcGiMaterialMap();
	AcGiMaterialMap(const AcGiMaterialMap& matMap);
	~AcGiMaterialMap();
	AcGiMaterialMap& operator=(const AcGiMaterialMap& matMap);
	bool operator==(const AcGiMaterialMap& matMap) const;

	virtual double blendFactor() const;
	ACGIMAT_IMPEXP Filter filter() const;
	virtual const AcGiMapper& mapper() const;
	virtual void set(const AcGiMaterialMap& matMap);
	virtual void setBlendFactor(double blendFactor);
	ACGIMAT_IMPEXP Acad::ErrorStatus setFilter(Filter filter);
	virtual void setMapper(const AcGiMapper& mapper);
	virtual void setSource(Source source);
	virtual void setSourceFileName(const ACHAR* fileName);
	virtual void setTexture(const AcGiMaterialTexture* pTexture);
	virtual Source source() const;
	virtual const ACHAR* sourceFileName() const;
	virtual const AcGiMaterialTexture* texture() const;
};

#include "IcArxPackPop.h"

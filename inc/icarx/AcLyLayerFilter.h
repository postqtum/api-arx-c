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
***     Description: Declaration of AcLyLayerFilter class
***
*****************************************************************************/
#pragma once

#include "../acarray.h"
#include "../AdAChar.h"
#include "../acadstrc.h"
#include "../AcHeapOpers.h"
#include "../rxobject.h"

class AcLySystemInternals;
class AcLyBoolExpr;
class AcDbLayerTableRecord;
class AcDbDxfFiler;
class AcImpLyLayerFilter;

#ifndef HIMAGELIST
struct _IMAGELIST;
typedef struct _IMAGELIST* HIMAGELIST;
#endif

#include "IcArxPackPush.h"

class AcLyLayerFilter
		: public AcRxObject
		, public AcHeapOperators
{
	friend class AcLySystemInternals;

public:
	enum DialogResult
	{
		kOk = 0,
		kCancel = 1,
		kUseDefault = 2
	};

protected:
	AcImpLyLayerFilter* mp_impObj = nullptr;
	AcLyLayerFilter(AcLySystemInternals*);

public:
	ACRX_DECLARE_MEMBERS(AcLyLayerFilter);

	AcLyLayerFilter();
	~AcLyLayerFilter();

	virtual Acad::ErrorStatus addNested(AcLyLayerFilter* filter);
	virtual bool allowDelete() const;
	virtual bool allowNested() const;
	virtual bool allowRename() const;
	virtual bool compareTo(const AcLyLayerFilter* pOther) const;
	virtual bool dynamicallyGenerated() const;
	virtual Acad::ErrorStatus generateNested();
	virtual Acad::ErrorStatus getImages(HIMAGELIST& imageList, uint32_t& normalImage,
										uint32_t& selected) const;
	virtual const AcArray<AcLyLayerFilter*>& getNestedFilters() const;
	virtual bool filter(AcDbLayerTableRecord* layer) const;
	virtual const ACHAR* filterExpression() const;
	virtual const AcLyBoolExpr* filterExpressionTree() const;
	virtual bool isIdFilter() const;
	virtual bool isProxy() const;
	virtual const ACHAR* name() const;
	virtual AcLyLayerFilter* parent() const;
	virtual Acad::ErrorStatus readFrom(AcDbDxfFiler* filer);
	virtual Acad::ErrorStatus removeNested(AcLyLayerFilter* filter);
	virtual Acad::ErrorStatus setFilterExpression(const ACHAR* expr);
	virtual Acad::ErrorStatus setName(const ACHAR*);
	virtual DialogResult showEditor();
	virtual Acad::ErrorStatus writeTo(AcDbDxfFiler* pFiler) const;
};

#include "IcArxPackPop.h"

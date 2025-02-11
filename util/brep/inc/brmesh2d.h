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
***     Description: Declaration of AcBrMesh2d class
***
*****************************************************************************/
#pragma once

#include "inc/adesk.h"
#include "inc/rxobject.h"
#include "inc/rxboiler.h"
#include "brgbl.h"
#include "brmesh.h"
#include "brm2dctl.h"

class AcBrEntity;
class AcBrMesh2dControl;
class AcBrMesh;
class AcBrMesh2dData;

static AcBrMesh2dControl AcBrMesh2dControlDefault;

#include "inc/icarx/IcArxPackPush.h"

struct pair
{
	AcBrEntity* first;
	AcBrMesh2dControl second;

	pair() : first(nullptr), second(AcBrMesh2dControlDefault) {}
	pair(const AcBrEntity*& a, const AcBrMesh2dControl& b) : first((AcBrEntity*)a), second(b) {}
};

inline pair make_pair(const AcBrEntity*& entity, const AcBrMesh2dControl& control)
{
	return pair(entity, control);
}

typedef pair value_type;
typedef void iterator;

class AcBrMesh2dFilter
{
private:
	friend class AcBrImpMesh2d;
	value_type mKeyValuePair;

	AcBrMesh2dFilter(const AcBrMesh2dFilter& src) = delete;
	AcBrMesh2dFilter& operator=(const AcBrMesh2dFilter& src) = delete;

public:
	AcBrMesh2dFilter() = default;
	~AcBrMesh2dFilter() = default;
	iterator insert(const value_type& x);
};

inline iterator AcBrMesh2dFilter::insert(const value_type& x)
{
	mKeyValuePair.first = x.first;
	mKeyValuePair.second = x.second;
}

class AcBrMesh2d : public AcBrMesh
{
public:
	ACRX_DECLARE_MEMBERS(AcBrMesh2d);

	AcBrMesh2d();
	AcBrMesh2d(const AcBrMesh2d& src);
	~AcBrMesh2d();
	AcBrMesh2d& operator=(const AcBrMesh2d& src);
	AcBr::ErrorStatus generate(const AcBrMesh2dFilter& meshFilter);
	AcBr::ErrorStatus get(AcBrMesh2dData*& mesh2d) const;
	AcBr::ErrorStatus set(AcBrMesh2dData* mesh2d);
};

#include "inc/icarx/IcArxPackPop.h"

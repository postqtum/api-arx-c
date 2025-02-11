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
***     Description:
***
*****************************************************************************/
#pragma once

#include "inc/adesk.h"
#include "inc/rxobject.h"
#include "inc/rxboiler.h"
#include "brgbl.h"
#include "brtrav.h"

class AcGeCurve2d;
class AcGeCurve3d;
class AcGeNurbCurve2d;
class AcGeNurbCurve3d;
class AcBrLoop;
class AcBrEdge;
class AcBrFaceLoopTraverser;
class AcBrEdgeLoopTraverser;

#include "inc/icarx/IcArxPackPush.h"

class AcBrLoopEdgeTraverser : public AcBrTraverser
{
public:
	ACRX_DECLARE_MEMBERS(AcBrLoopEdgeTraverser);

	AcBrLoopEdgeTraverser();
	AcBrLoopEdgeTraverser(const AcBrLoopEdgeTraverser& src);
	~AcBrLoopEdgeTraverser();
	AcBrLoopEdgeTraverser& operator=(const AcBrLoopEdgeTraverser& src);
	AcBr::ErrorStatus getEdge(AcBrEdge& edge) const;
	AcBr::ErrorStatus getEdgeOrientToLoop(bool& orient) const;
	AcBr::ErrorStatus getLoop(AcBrLoop& loop) const;
	AcBr::ErrorStatus getOrientedCurve(AcGeCurve3d*& curve) const;
	AcBr::ErrorStatus getOrientedCurveAsNurb(AcGeNurbCurve3d& nurb,
											 const double& fitTolRequired = *(double*)nullptr,
											 double& fitTolAchieved = *(double*)nullptr) const;
	AcBr::ErrorStatus getParamCurve(AcGeCurve2d*& pcurve) const;
	AcBr::ErrorStatus getParamCurveAsNurb(AcGeNurbCurve2d& nurb,
										  const double& fitTolRequired = *(double*)nullptr,
										  double& fitTolAchieved = *(double*)nullptr) const;
	AcBr::ErrorStatus setEdge(AcBrEdge& edge);
	AcBr::ErrorStatus setEdge(const AcBrEdge& edge);
	AcBr::ErrorStatus setLoop(AcBrFaceLoopTraverser& loop);
	AcBr::ErrorStatus setLoop(const AcBrFaceLoopTraverser& faceLoop);
	AcBr::ErrorStatus setLoop(const AcBrLoop& loop);
	AcBr::ErrorStatus setLoopAndEdge(AcBrEdgeLoopTraverser& edgeLoop);
	AcBr::ErrorStatus setLoopAndEdge(const AcBrEdgeLoopTraverser& edgeLoop);
};

#include "inc/icarx/IcArxPackPop.h"

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

class AcBrFace;
class AcBrLoop;
class AcBrShellFaceTraverser;

#include "inc/icarx/IcArxPackPush.h"

class AcBrFaceLoopTraverser : public AcBrTraverser
{
public:
	ACRX_DECLARE_MEMBERS(AcBrFaceLoopTraverser);

	AcBrFaceLoopTraverser();
	AcBrFaceLoopTraverser(const AcBrFaceLoopTraverser& src);
	~AcBrFaceLoopTraverser();
	AcBrFaceLoopTraverser& operator=(const AcBrFaceLoopTraverser& src);
	AcBr::ErrorStatus getFace(AcBrFace& face) const;
	AcBr::ErrorStatus getLoop(AcBrLoop& loop) const;
	AcBr::ErrorStatus setFace(AcBrFace& face);
	AcBr::ErrorStatus setFace(const AcBrFace& face);
	AcBr::ErrorStatus setFace(const AcBrShellFaceTraverser& shellFaceTrav);
	AcBr::ErrorStatus setFaceAndLoop(const AcBrLoop& loop);
	AcBr::ErrorStatus setLoop(AcBrLoop& loop);
	AcBr::ErrorStatus setLoop(const AcBrLoop& loop);
};

#include "inc/icarx/IcArxPackPop.h"

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
***     Description: Declaration of AcGiDrawStream classes
***
*****************************************************************************/
#pragma once

#include "AcGiDrawable.h"
#include "../acarray.h"

class AcGiDrawStreamImp;
class IAcWriteStream;
class IAcReadStream;

using GraphicsUpdateProc = bool (*)(const AcArray<AcGiDrawable*>&);

#include "IcArxPackPush.h"

class AcGiDrawStream : public AcGiDrawable
{
	friend class AcGiDrawStreamImp;

protected:
	AcGiDrawStreamImp* m_pImp;

protected:
	ACDBCORE2D_PORT uint32_t subSetAttributes(AcGiDrawableTraits* pTraits) override;
	ACDBCORE2D_PORT void subViewportDraw(AcGiViewportDraw* pVd) override;
	ACDBCORE2D_PORT uint32_t subViewportDrawLogicalFlags(AcGiViewportDraw* pVd) override;
	ACDBCORE2D_PORT bool subWorldDraw(AcGiWorldDraw* pWd) override;

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcGiDrawStream, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT AcGiDrawStream();
	ACDBCORE2D_PORT AcGiDrawStream(const AcGiDrawable* pOwner);
	ACDBCORE2D_PORT ~AcGiDrawStream();

	ACDBCORE2D_PORT bool bounds(AcDbExtents& bounds) const override;
	ACDBCORE2D_PORT static bool build(const AcArray<AcGiDrawStream*>& streamArray,
									  GraphicsUpdateProc lpFunc);
	ACDBCORE2D_PORT AcGiDrawStream* drawStream() const override;
	ACDBCORE2D_PORT AcGiDrawable::DrawableType drawableType() const override;
	ACDBCORE2D_PORT AcGiDrawable* getOwner() const;
	ACDBCORE2D_PORT AcDbObjectId id() const override;
	ACDBCORE2D_PORT bool isValid() const;
	ACDBCORE2D_PORT bool isPersistent() const override;
	ACDBCORE2D_PORT bool serializeIn(IAcReadStream* pInput, AcDbDatabase* pDb = nullptr);
	ACDBCORE2D_PORT bool serializeOut(IAcWriteStream* pOutput) const;
	ACDBCORE2D_PORT void setDrawStream(AcGiDrawStream* pStream) override;
	ACDBCORE2D_PORT void setOwner(const AcGiDrawable* pOwner);
};

#include "IcArxPackPop.h"

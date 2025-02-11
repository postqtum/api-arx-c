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
***     Description: Declaration of AcEdInputContextReactor class
***
*****************************************************************************/
#pragma once

#include "AcOdBridge.h"
#include "../acadapidef.h"
#include "../acarray.h"
#include "../gepnt3d.h"
#include "AcDbObjectId.h"

struct resbuf;
class AcGeMatrix3d;
class AcGeVector3d;

#include "IcArxPackPush.h"

class AcEdInputContextReactor : public AcOdBridge
{
public:
	ACAD_PORT virtual ~AcEdInputContextReactor();

	virtual void beginDragSequence(const ACHAR* /*promptString*/) {}
	virtual void beginEntsel(const ACHAR* /*promptString*/, int /*initGetFlags*/,
							 const ACHAR* /*pKeywords*/)
	{
	}
	virtual void beginGetAngle(const AcGePoint3d* /*pointIn*/, const ACHAR* /*promptString*/,
							   int /*initGetFlags*/, const ACHAR* /*pKeywords*/)
	{
	}
	virtual void beginGetColor(const int* /*dfault*/,
							   const ACHAR* /*promptString*/, int /*initGetFlags*/,
							   const ACHAR* /*pKeywords*/)
	{
	}
	virtual void beginGetCorner(const AcGePoint3d* /*firstCorner*/, const ACHAR* /*promptString*/,
								int /*initGetFlags*/, const ACHAR* /*pKeywords*/)
	{
	}
	virtual void beginGetDistance(const AcGePoint3d* /*pointIn*/, const ACHAR* /*promptString*/,
								  int /*initGetFlags*/, const ACHAR* /*pKeywords*/)
	{
	}
	virtual void beginGetInteger(const int* /*dfault*/,
								 const ACHAR* /*promptString*/, int /*initGetFlags*/,
								 const ACHAR* /*pKeywords*/)
	{
	}
	virtual void beginGetKeyword(const ACHAR* /*promptString*/, int /*initGetFlags*/,
								 const ACHAR* /*pKeywords*/)
	{
	}
	virtual void beginGetOrientation(const AcGePoint3d* /*pointIn*/, const ACHAR* /*promptString*/,
									 int /*initGetFlags*/, const ACHAR* /*pKeywords*/)
	{
	}
	virtual void beginGetPoint(const AcGePoint3d* /*pointIn*/, const ACHAR* /*promptString*/,
							   int /*initGetFlags*/, const ACHAR* /*pKeywords*/)
	{
	}
	virtual void beginGetReal(const double* /*dfault*/,
							  const ACHAR* /*promptString*/, int /*initGetFlags*/,
							  const ACHAR* /*pKeywords*/)
	{
	}
	virtual void beginGetScaleFactor(const AcGePoint3d* /*pointIn*/, const ACHAR* /*promptString*/,
									 int /*initGetFlags*/, const ACHAR* /*pKeywords*/)
	{
	}
	virtual void beginGetString(const ACHAR* /*promptString*/, int /*initGetFlags*/) {}
	virtual void beginNentsel(const ACHAR* /*promptString*/, bool /*pickFlag*/,
							  int /*initGetFlags*/, const ACHAR* /*pKeywords*/)
	{
	}
	virtual void beginQuiescentState() {}
	virtual void beginSSGet(const ACHAR* /*pPrompt*/, int /*initGetFlags*/,
							const ACHAR* /*pKeywords*/, const ACHAR* /*pSSControls*/,
							const AcArray<AcGePoint3d>& /*points*/, const resbuf* /*entMask*/)
	{
	}
	virtual void endDragSequence(Acad::PromptStatus /*returnStatus*/, AcGePoint3d& /*pickPoint*/,
								 AcGeVector3d& /*vec*/)
	{
	}
	virtual void endEntsel(Acad::PromptStatus /*returnStatus*/, AcDbObjectId& /*entPicked*/,
						   AcGePoint3d& /*pickPoint*/, const ACHAR* /*pKeyword*/)
	{
	}
	virtual void endGetAngle(Acad::PromptStatus /*returnStatus*/, double& /*angle*/,
							 const ACHAR*& /*pKeyword*/)
	{
	}
	virtual void endGetColor(Acad::PromptStatus /*returnStatus*/, int& /*retValue*/,
							 const ACHAR*& /*pKeyword*/)
	{
	}
	virtual void endGetCorner(Acad::PromptStatus /*returnStatus*/, AcGePoint3d& /*secondCorner*/,
							  const ACHAR*& /*pKeyword*/)
	{
	}
	virtual void endGetDistance(Acad::PromptStatus /*returnStatus*/, double& /*distance*/,
								const ACHAR*& /*pKeyword*/)
	{
	}
	virtual void endGetInteger(Acad::PromptStatus /*returnStatus*/, int& /*retValue*/,
							   const ACHAR*& /*pKeyword*/)
	{
	}
	virtual void endGetKeyword(Acad::PromptStatus /*returnStatus*/, const ACHAR*& /*pKeyword*/) {}
	virtual void endGetOrientation(Acad::PromptStatus /*returnStatus*/, double& /*angle*/,
								   const ACHAR*& /*pKeyword*/)
	{
	}
	virtual void endGetPoint(Acad::PromptStatus /*returnStatus*/, const AcGePoint3d& /*pointOut*/,
							 const ACHAR*& /*pKeyword*/)
	{
	}
	virtual void endGetReal(Acad::PromptStatus /*returnStatus*/, double& /*returnValue*/,
							const ACHAR*& /*pKeyword*/)
	{
	}
	virtual void endGetScaleFactor(Acad::PromptStatus /*returnStatus*/, double& /*distance*/,
								   const ACHAR*& /*pKeyword*/)
	{
	}
	virtual void endGetString(Acad::PromptStatus /*returnStatus*/, ACHAR* /*pString*/) {}
	virtual void endNentsel(Acad::PromptStatus /*returnStatus*/, AcDbObjectId /*entPicked*/,
							const AcGePoint3d& /*pickPoint*/, const AcGeMatrix3d& /*xform*/,
							const resbuf* /*referenceStack*/, const ACHAR* /*pKeyword*/)
	{
	}
	virtual void endQuiescentState() {}
	virtual void endSSGet(Acad::PromptStatus /*returnStatus*/, const AcArray<AcDbObjectId>& /*ss*/)
	{
	}
	virtual void undoLastPoint(const AcGePoint3d* /*previousPoint*/) {}
};

#include "IcArxPackPop.h"

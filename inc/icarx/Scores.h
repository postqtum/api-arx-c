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
***     Description: Declaration of Scores class
***
*****************************************************************************/
#pragma once

#include "../gepnt3d.h"

#include "AcGiContext.h"
#include "TextParams.h"

using LineSegmentCallback = void (*)(const AcGePoint3d&, const AcGePoint3d&, const void*);

#define ON 1
#define OFF 0

#include "IcArxPackPush.h"

class Scores
{
private:
	int m_overline;
	int m_underline;
	int m_strikethrough;
	AcGePoint3d m_position;
	AcGePoint3d m_over_point[2];
	AcGePoint3d m_under_point[2];
	AcGePoint3d m_strikethrough_point[2];
	AcGePoint3d m_bbox[4];
	TextParams const* m_pTextParams;
	LineSegmentCallback m_pLineSegmentCB;
	void* m_pAction;
	AcGiContext* m_pContext;

public:
	Scores(AcGiContext* pContext, const TextParams* pTextParams, LineSegmentCallback pLineSegment,
		   void* pAction);
	~Scores() = default;

	void close_scores(const wchar_t* text, int length);
	void draw_vector(const AcGePoint3d& p1, const AcGePoint3d& p2);
	void over_score(const wchar_t* text, int length);
	void strikethrough_score(const wchar_t* text, int length);
	void under_score(const wchar_t* text, int length);
};

#include "IcArxPackPop.h"

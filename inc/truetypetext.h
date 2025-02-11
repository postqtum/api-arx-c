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

#include "icarx/TrueTypeUnicodeBuffer.h"
#include "icarx/Scores.h"
#include "icarx/TextParams.h"

#include "icarx/IcArxAssert.h"
#define TrueTypeText_Assert ICARX_ASSERT

#define UC_DEGREE_SYMBOL 0x00B0
#define UC_PLUSMINUS_SYMBOL 0x00B1
#define UC_PHI_SYMBOL 0x00D8
#define UC_DIAMETER_SYMBOL 0x2205

void process_uc_string(wchar_t* uc_string, int& uc_length, TextParams const* tp, int draw_scores,
					   LineSegmentCallback line_segment = nullptr, void* action = nullptr);

void process_underoverline(const wchar_t* uc_string, int uc_length, TextParams const* tp,
						   LineSegmentCallback line_segment, void* action = nullptr);

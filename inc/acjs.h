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

#ifdef _ACJSCORESTUB
#	define ACJSCORESTUB_PORT __declspec(dllexport)
#else
#	define ACJSCORESTUB_PORT __declspec(dllimport)
#endif

using AcJsFunctionPtr = char* (*)(const char*);

#define ACJS_FUNC_INVOKEINDOC 0x00000001
#define ACJS_FUNC_HANDLE_NULLDOC 0x00000002

#define ACJSCORESTUB_DEFUN "acjsDefun"

using ACJSCORESTUB_DEFUN_PROC = Acad::ErrorStatus (*)(const TCHAR* name, AcJsFunctionPtr funcAddr,
													  int32_t funcFlags);

extern "C" ACJSCORESTUB_PORT Acad::ErrorStatus acjsDefun(const TCHAR* name,
														 AcJsFunctionPtr funcAddr,
														 int32_t funcFlags = 0);
extern "C" ACJSCORESTUB_PORT Acad::ErrorStatus acjsInvokeAsync(const TCHAR* name,
															   const TCHAR* jsonArgs);
extern "C" ACJSCORESTUB_PORT Acad::ErrorStatus acjsInvokeAsyncA(const char* name,
																const char* jsonArgs);

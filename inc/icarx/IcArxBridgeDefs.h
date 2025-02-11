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
***     Description: Macro definitions for IcArxBridge library
***
*****************************************************************************/
#ifndef __ICARXBRIDGEDEFS_H__
#define __ICARXBRIDGEDEFS_H__

#pragma once

#ifdef ICARXBRIDGE_API
#	define ICARXBRIDGE_PORT __declspec(dllexport)
#else
#	define ICARXBRIDGE_PORT __declspec(dllimport)
#endif

#endif // __ICARXBRIDGEDEFS_H__

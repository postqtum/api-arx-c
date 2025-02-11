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

#include "AdAChar.h"
#include "adesk.h"

namespace Atil
{
class ImageFormatCodec;
class ProgressCallbackInterface;
};	// namespace Atil

class AdHostImageAppServices;

class ADESK_NO_VTABLE AdHostImageAppServices
{
public:
	virtual const ACHAR* imageFileExtensions(bool bRefresh = false) = 0;

	virtual const ACHAR* imageFilterString(bool bRefresh = false) = 0;

	virtual bool registerFormatCodec(Atil::ImageFormatCodec& codec) = 0;

	virtual bool formatCodecRegistered(Atil::ImageFormatCodec& codec) = 0;

	virtual bool reRegisterFormatCodec(Atil::ImageFormatCodec& codec) = 0;

	virtual bool unRegisterFormatCodec(Atil::ImageFormatCodec& codec) = 0;

	virtual Atil::ProgressCallbackInterface* registerProgressCallback(
			Atil::ProgressCallbackInterface* pCallback) = 0;
};

AdHostImageAppServices* getAdHostImageAppServices();

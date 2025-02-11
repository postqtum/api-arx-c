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
***     Description: Declaration of SecurityParams, SignatureInfo structs
***
*****************************************************************************/
#pragma once

class AcDbDate;

#ifndef OBJARX_EXCLUDE_CONFLICTS
enum
{
	SECURITYPARAMS_ENCRYPT_DATA = 0x00000001,
	SECURITYPARAMS_ENCRYPT_PROPS = 0x00000002,
	SECURITYPARAMS_SIGN_DATA = 0x00000010,
	SECURITYPARAMS_ADD_TIMESTAMP = 0x00000020
};

enum
{
	SECURITYPARAMS_ALGID_RC4 = 0x00006801
};
#endif	// OBJARX_EXCLUDE_CONFLICTS

#include "icarx/IcArxPackPush.h"

struct SecurityParams
{
	unsigned long cbSize;
	unsigned long ulFlags;
	wchar_t* wszPassword;
	unsigned long ulProvType;
	wchar_t* wszProvName;
	unsigned long ulAlgId;
	unsigned long ulKeyLength;
	wchar_t* wszCertSubject;
	wchar_t* wszCertIssuer;
	wchar_t* wszCertSerialNum;
	wchar_t* wszComment;
	wchar_t* wszTimeServer;
};

struct SignatureInfo
{
	unsigned long cbSize;
	unsigned long ulFlags;
	wchar_t* wszCertSubject;
	wchar_t* wszCertIssuer;
	wchar_t* wszSubjectEMail;
	wchar_t* wszCertSerialNum;
	wchar_t* wszX500;
	AcDbDate* pTimeCertNotBefore;
	AcDbDate* pTimeCertNotAfter;
	wchar_t* wszComment;
	wchar_t* wszTimeServer;
	AcDbDate* pTimestamp;
};

#include "icarx/IcArxPackPop.h"

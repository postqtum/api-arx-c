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

namespace AcadInet
{

const int StatusBase = 20000;

enum
{
	TF_VALIDATE_URL = 0x01,
	TF_DOWNLOAD_FILE = 0x02,
	TF_UPLOAD_FILE = 0x04,
	TF_IGNORE_CACHE = 0x08
};

enum Status
{
	statusOk = StatusBase,
	statusInCache,
	statusFileNotFound,
	statusBadPath,
	statusTooManyOpenFiles,
	statusFileAccessDenied,
	statusInvalidFileHandle,
	statusDirectoryFull,
	statusHardwareError,
	statusSharingViolation,
	statusDiskFull,
	statusFileGenericError,
	statusValidURL,
	statusNotAnURL,
	statusNoWinInet,
	statusOldWinInet,
	statusNoAcadInet,
	statusNotImplemented,
	statusProtocolNotSupported,
	statusCreateInternetSessionFailed,
	statusInternetSessionConnectFailed,
	statusInternetSessionOpenFailed,
	statusInvalidAccessType,
	statusFileOpenFailed,
	statusHttpOpenRequestFailed,
	statusUserCancelledTransfer,
	statusHttpBadRequest,
	statusHttpAccessDenied,
	statusHttpPaymentRequired,
	statusHttpRequestForbidden,
	statusHttpObjectNotFound,
	statusHttpBadMethod,
	statusHttpNoAcceptableResponse,
	statusHttpProxyAuthorizationRequired,
	statusHttpTimedOut,
	statusHttpConflict,
	statusHttpResourceGone,
	statusHttpLengthRequired,
	statusHttpPreconditionFailure,
	statusHttpRequestTooLarge,
	statusHttpUriTooLong,
	statusHttpUnsupportedMedia,
	statusHttpServerError,
	statusHttpNotSupported,
	statusHttpBadGateway,
	statusHttpServiceUnavailable,
	statusHttpGatewayTimeout,
	statusHttpVersionNotSupported,
	statusInternetError,
	statusGenericException,
	statusUnknownError
};

}  // namespace AcadInet

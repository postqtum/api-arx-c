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
***     Description: Declaration of AdUi message support classes
***
*****************************************************************************/
#pragma once

#include <afxwin.h>

#include "adui_port.h"

enum ADUI_COMMAND_STATE
{
	kAdUiCommand_Cancelled = -1,
	kAdUiCommand_Completed,
	kAdUiCommand_Begun,
};

enum ADUI_MODAL_STATE
{
	kAdUiModal_Begun = 1,
	kAdUiModal_Ended,
};

enum ADUI_NOTIFY
{
	kAdUiNotify_Nothing,
	kAdUiNotify_Generic,
	kAdUiNotify_AppMainWindow,
	kAdUiNotify_AppResourceInstance,
	kAdUiNotify_AutoLoad,
	kAdUiNotify_Reload,
	kAdUiNotify_GetTipSupport,
	kAdUiNotify_GetTipText,
	kAdUiNotify_GetTipRect,
	kAdUiNotify_HitTipRect,
	kAdUiNotify_DrawTip,
	kAdUiNotify_DrawTipText,
	kAdUiNotify_UpdateTip,
	kAdUiNotify_HideWindow,
	kAdUiNotify_ShowWindow,
	kAdUiNotify_RestoreFocus,
	kAdUiNotify_Change,
	kAdUiNotify_NotValid,
	kAdUiNotify_Valid,
	kAdUiNotify_Validate,
	kAdUiNotify_CommandState,
	kAdUiNotify_ModalState,
};

enum ADUI_REPLY
{
	kAdUiReply_Nothing,
	kAdUiReply_Ok,
	kAdUiReply_NotValid,
	kAdUiReply_Valid,
	kAdUiReply_TextTip,
	kAdUiReply_ToolTip,
	kAdUiReply_DrawTip,
};

const UINT ADUI_PORT AdUiMessage();

ADUI_NOTIFY ADUI_PORT AdUiNotification(WPARAM wp);

ADUI_REPLY ADUI_PORT AdUiNotify(CWnd& w, UINT id, ADUI_NOTIFY n, LPARAM lParam);
ADUI_REPLY ADUI_PORT AdUiNotify(CWnd* w, UINT id, ADUI_NOTIFY n, LPARAM lParam);

UINT ADUI_PORT AdUiNotifyId(WPARAM wp);

BOOL ADUI_PORT AdUiPostNotify(CWnd& w, UINT id, ADUI_NOTIFY n, LPARAM lParam);
BOOL ADUI_PORT AdUiPostNotify(CWnd* w, UINT id, ADUI_NOTIFY n, LPARAM lParam);


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

#include "ads.h"
#include "AdAChar.h"

#ifndef CALLB
#	define CALLB
#endif

#ifdef __ZTC__
#	pragma ZTC align 1
#endif

#ifdef __cplusplus
extern "C"
{
#endif

	typedef void* ads_hdlg;
	typedef void* ads_htile;

#include "icarx/IcArxPackPush.h"

	typedef struct
	{
		ads_hdlg dialog;
		ads_htile tile;
		ACHAR* value;
		void* client_data;
		int reason;
		long x, y;
	} ads_callback_packet;

#include "icarx/IcArxPackPop.h"

#define CBR_SELECT 1
#define CBR_LOST_FOCUS 2
#define CBR_DRAG 3
#define CBR_DOUBLE_CLICK 4

#ifndef _PROTEUS_H
	typedef void (*CLIENTFUNC)(ads_callback_packet* cpkt);
#endif /* _PROTEUS_H */

#define NULLCB ((CLIENTFUNC)0)
#define BAD_DIALOG NULL

#define DLGCANCEL 0
#define DLGOK 1
#define DLGALLDONE -1
#define DLGSTATUS 2

#ifndef _PROCONST_H
#	define LIST_CHANGE ((short)1)
#	define LIST_APPEND ((short)2)
#	define LIST_NEW ((short)3)
#	define MODE_ENABLE ((short)0)
#	define MODE_DISABLE ((short)1)
#	define MODE_SETFOCUS ((short)2)
#	define MODE_SETSEL ((short)3)
#	define MODE_FLIP ((short)4)
#endif	// _PROCONST_H

#ifndef _PROTEUS_H
#	define MAX_TILE_STR 40
#endif

#define TILE_STR_LIMIT 2035

	int ads_action_tile(ads_hdlg hdlg, const ACHAR* key, CLIENTFUNC tilefunc);
	int ads_add_list(const ACHAR* item);
	int ads_client_data_tile(ads_hdlg hdlg, const ACHAR* key, void* clientdata);
	int ads_dimensions_tile(ads_hdlg hdlg, const ACHAR* key, short* cx, short* cy);
	int ads_done_dialog(ads_hdlg hdlg, int status);
	int ads_done_positioned_dialog(ads_hdlg hdlg, int status, int* x_result, int* y_result);
	int ads_end_image(void);
	int ads_end_list(void);
	int ads_fill_image(short x1, short y1, short x2, short y2, short color);
	int ads_get_attr(ads_hdlg hdlg, const ACHAR* key, ACHAR* attr, ACHAR* value, int len);
	int ads_get_attr_string(ads_htile tile, ACHAR* attr, ACHAR* value, int len);
	int ads_get_tile(ads_hdlg hdlg, const ACHAR* key, ACHAR* value, int maxlen);
	int ads_load_dialog(const ACHAR* dclfile, int* dcl_id);
	int ads_mode_tile(ads_hdlg hdlg, const ACHAR* key, short mode);
	int ads_new_dialog(const ACHAR* dlgname, int dcl_id, CLIENTFUNC def_callback, ads_hdlg* hdlg);
	int ads_new_positioned_dialog(const ACHAR* dlgname, int dcl_id, CLIENTFUNC def_callback, int x,
								  int y, ads_hdlg* hdlg);
	int ads_set_tile(ads_hdlg hdlg, const ACHAR* key, const ACHAR* value);
	int ads_slide_image(short x1, short y1, short x2, short y2, const ACHAR* slnam);
	int ads_start_dialog(ads_hdlg hdlg, int* status);
	int ads_start_image(ads_hdlg hdlg, const ACHAR* key);
	int ads_start_list(ads_hdlg hdlg, const ACHAR* key, short operation, short index);
	int ads_term_dialog(void);
	int ads_vector_image(short x1, short y1, short x2, short y2, short color);
	int ads_unload_dialog(int dcl_id);

#ifdef __cplusplus
}
#endif

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
***     Description: AcEd internat related routines
***
*****************************************************************************/
#pragma once

#include "acadapidef.h"

ACAD_PORT bool acedCreateInternetShortcut(/*[in]*/ const ACHAR* szURL,
										  /*[in]*/ const ACHAR* szShortcutPath);
ACAD_PORT bool acedCreateShortcut(/*[in]*/ void* pvHwndParent,
								  /*[in]*/ const ACHAR* szLinkPath,
								  /*[in]*/ const ACHAR* szObjectPath,
								  /*[in]*/ const ACHAR* szDesc);
ACAD_PORT bool acedGetUserFavoritesDir(/*[out]*/ ACHAR* szFavoritesDir);
ACAD_PORT bool acedResolveInternetShortcut(/*[in]*/ const ACHAR* szLinkFile,
										   /*[out]*/ ACHAR* szUrl);
ACAD_PORT bool acedResolveShortcut(/*[in]*/ void* pvHwndParent,
								   /*[in]*/ const ACHAR* szLinkPath,
								   /*[out]*/ ACHAR* szObjectPath);

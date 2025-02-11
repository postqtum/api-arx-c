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
***     Description: Various file-system related enums
***
*****************************************************************************/
#pragma once

enum FS_TYPE
{
	NOFS,
	UKFS,
	NTFS,
	FAT,
	VFAT,
	HPFS,
	CDFS,
	HFS,
	UFS
};

enum path_category
{
	DRIVE_TYPE,
	UNC_TYPE,
	ROOT_TYPE,
	RELATIVE_TYPE
};

enum path_status
{
	PATH_NOTEXISTS = 0x00,
	PATH_EXISTS = 0x01,
	PATH_READ = 0x02,
	PATH_READWRITE = 0x04
};

enum path_type
{
	NO_PATH = 0,
	NEW_PATH,
	WC_PATH,
	FILE_PATH,
	DIR_PATH,
	DEV_PATH,
};

enum PathErr
{
	PATH_NOERR = 0,
	PATH_INVALID,
	PATH_BADOP,
	PATH_REFUSED,
	PATH_ERR
};


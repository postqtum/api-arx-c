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
***     Description: Pushes current warning status and alignment
***
*****************************************************************************/
#ifdef _MSC_VER

// We disable the following warning globally to allow our trick with IcArxPackPush.h/IcArxPackPop.h
#	pragma warning(disable : 4103)	 // alignment changed after including header, may be due to
									 // missing #pragma pack(pop)
#	if defined(__clang__)
#		pragma clang diagnostic ignored "-Wpragma-pack"
#		pragma clang diagnostic push
#	endif
#	pragma warning(push)
#	pragma pack(push, 8)

#endif

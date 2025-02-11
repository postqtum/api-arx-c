/***************************************************************************
***
***     Copyright (C) 2023 IntelliCAD Technology Consortium. All Rights Reserved.
***
***     Use of the information contained herein, in part or in whole,
***     in/as source code and/or in/as object code, in any way by anyone
***     other than authorized employees of The IntelliCAD Technology Consortium,
***     or by anyone to whom The IntelliCAD Technology Consortium  has not
***     granted use is illegal.
***
***     Description: Implementation of MyTabChildDialog class
***
*****************************************************************************/
#include "stdafx.h"
#include "MyTabChildDialog.h"

BEGIN_MESSAGE_MAP(MyTabChildDialog, CAdUiTabChildDialog)
END_MESSAGE_MAP()


void MyTabChildDialog::PostNcDestroy()
{
	__super::PostNcDestroy();

	delete this;
}

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
***     Description: Declaration of AcPcPointFloat, AcPcPointDouble, AcPcPointAttributes classes
***
*****************************************************************************/
#pragma once

#include "../acdbport.h"

#include "IcArxPackPush.h"

class ACDB_PORT AcPcPointFloat
{
public:
	float m_x;
	float m_y;
	float m_z;
	DWORD m_argb;
};

class ACDB_PORT AcPcPointDouble
{
public:
	double m_x;
	double m_y;
	double m_z;
	DWORD m_argb;
};

class ACDB_PORT AcPcPointAttributes
{
public:
	float m_intensity;
	float m_nx;
	float m_ny;
	float m_nz;
	BYTE m_classification;
};

#include "IcArxPackPop.h"

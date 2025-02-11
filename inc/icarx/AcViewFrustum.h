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
***     Description: Declaration of AcViewFrustum class
***
*****************************************************************************/
#pragma once

#include "../acdbport.h"

class AcPointCloudViewFrustum;

#include "IcArxPackPush.h"

class ACDB_PORT AcViewFrustum
{
private:
	AcPointCloudViewFrustum* m_pData;

public:
	AcViewFrustum();
	~AcViewFrustum();
	AcViewFrustum(const AcViewFrustum&) = delete;
	AcViewFrustum& operator=(const AcViewFrustum&) = delete;

	AcPointCloudViewFrustum* asPointCloudFrustum() const;
	bool farClip() const;
	void farLowerLeft(double& x, double& y, double& z) const;
	void farLowerRight(double& x, double& y, double& z) const;
	void farUpperLeft(double& x, double& y, double& z) const;
	void farUpperRight(double& x, double& y, double& z) const;
	bool nearClip() const;
	void nearLowerLeft(double& x, double& y, double& z) const;
	void nearLowerRight(double& x, double& y, double& z) const;
	void nearUpperLeft(double& x, double& y, double& z) const;
	void nearUpperRight(double& x, double& y, double& z) const;
	void setFarClip(bool clip);
	void setFarLowerLeft(double x, double y, double z);
	void setFarLowerRight(double x, double y, double z);
	void setFarUpperLeft(double x, double y, double z);
	void setFarUpperRight(double x, double y, double z);
	void setNearClip(bool clip);
	void setNearLowerLeft(double x, double y, double z);
	void setNearLowerRight(double x, double y, double z);
	void setNearUpperLeft(double x, double y, double z);
	void setNearUpperRight(double x, double y, double z);
};

#include "IcArxPackPop.h"

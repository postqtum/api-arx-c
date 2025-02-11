/***************************************************************************
***
***     Copyright (C) 2021-2023 IntelliCAD Technology Consortium. All Rights Reserved.
***
***     Use of the information contained herein, in part or in whole,
***     in/as source code and/or in/as object code, in any way by anyone
***     other than authorized employees of The IntelliCAD Technology Consortium,
***     or by anyone to whom The IntelliCAD Technology Consortium  has not
***     granted use is illegal.
***
***     Description: Declaration of AcReCallout class
***
*****************************************************************************/
#pragma once

#include "../AdAChar.h"
#include "../acadstrc.h"
#include "../adsdef.h"

using dwg3dp = double[3];

#include "IcArxPackPush.h"

class AcReCallout
{
public:
	int flag;

public:
	virtual void e2fBlockData(struct e2f_ent* ent, struct e2f_xform* xform){};
	virtual void e2fEntityData(struct e2f_ent* ent){};
	virtual void e2fHeaderData(struct e2f_hdr* hdr){};
	virtual void e2fLayerData(struct e2f_layer* lyr){};
	virtual void e2fMeshData(struct scn_pmsh* polymesh, long** polyindex){};
	virtual void e2fNormalData(dwg3dp* normals_array){};
	virtual void e2fVertexData(dwg3dp* vertex_array){};
};

#include "IcArxPackPop.h"

Acad::ErrorStatus acreEntityToFaces(ads_name ss, ACHAR** const name, int normal);
int acreRegisterCallout(AcReCallout* imp);

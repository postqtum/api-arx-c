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

#include "icarx/AcDbSequenceEnd.h"
#include "icarx/AcDbBlockBeginEnd.h"
#include "icarx/AcDbShape.h"
#include "icarx/AcDbTrace.h"
#include "icarx/AcDbViewport.h"
#include "icarx/AcDbPolygonMesh.h"
#include "icarx/AcDbSolid.h"
#include "icarx/AcDbPolyFaceMesh.h"
#include "icarx/AcDbFace.h"
#include "icarx/AcDbPoint.h"
#include "icarx/AcDbLine.h"
#include "icarx/AcDbCircle.h"
#include "icarx/AcDbArc.h"
#include "icarx/AcDb3dPolyline.h"
#include "icarx/AcDb2dPolyline.h"
#include "icarx/AcDbFaceRecord.h"
#include "icarx/AcDbPolyFaceMeshVertex.h"
#include "icarx/AcDbPolygonMeshVertex.h"
#include "icarx/AcDb3dPolylineVertex.h"
#include "icarx/AcDbVertex.h"
#include "icarx/AcDb2dVertex.h"
#include "icarx/AcDbMInsertBlock.h"
#include "icarx/AcDbBlockReference.h"
#include "icarx/AcDbAttribute.h"
#include "icarx/AcDbAttributeDefinition.h"
#include "icarx/AcDbText.h"

#include "dbmain.h"
#include "dbcurve.h"
#include "gescl3d.h"
#include "gepnt2d.h"
#include "dbmtext.h"
#include "dbBackground.h"
#include "dbdim.h"
#include "gept2dar.h"
#include "gedblar.h"
#include "dbsymtb.h"
#include "gemat3d.h"
#include "AcDbXref.h"
#include "acgi.h"
#include "acgiviewport.h"
#include "acgivisualstyle.h"

#include "icarx/IcArxAssert.h"

namespace Atil
{
class Image;
}

inline bool isPtInsideBoundingBox(const AcGePoint3dArray& bBox, const AcGePoint3d m)
{
	ICARX_ASSERT(bBox.length() == 4);
	const AcGeVector3d ADvector = bBox[3] - bBox[0];
	const AcGeVector3d ABvector = bBox[1] - bBox[0];
	const AcGeVector3d AMvector = m - bBox[0];
	const double dotAMADvec = AMvector.dotProduct(ADvector);
	const double dotAMABvec = AMvector.dotProduct(ABvector);
	const double dotABABvec = ABvector.dotProduct(ABvector);
	const double dotADADvec = ADvector.dotProduct(ADvector);

	return (((0 < dotAMABvec) && (dotAMABvec < dotABABvec)) &&
			((0 < dotAMADvec) && (dotAMADvec < dotADADvec)));
}

typedef struct tagBITMAPINFO BITMAPINFO;

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
***     Description: Declaration of AcDbModelDocViewStyle class
***
*****************************************************************************/
#pragma once

#include "acdbport.h"
#include "dbmain.h"
#include "dbmtext.h"
#include "AcString.h"

class AcDbImpModelDocViewStyle;

#include "icarx/IcArxPackPush.h"

class AcDbModelDocViewStyle : public AcDbObject
{
	friend class AcDbImpModelDocViewStyle;

public:
	enum AttachmentPoint
	{
		kAboveView = 0,
		kBelowView = 1,
	};

	enum TextAlignment
	{
		kTextAlignmentLeft = 0,
		kTextAlignmentCenter = 1,
		kTextAlignmentRight = 2,
	};

protected:
	ACDBCORE2D_PORT AcDbModelDocViewStyle();

	ACDBCORE2D_PORT Acad::ErrorStatus subDeepClone(AcDbObject* pOwner, AcDbObject*& pClonedObject,
												   AcDbIdMapping& idMap,
												   bool isPrimary = true) const override;
	ACDBCORE2D_PORT Acad::ErrorStatus subWblockClone(
			AcRxObject* pOwner, AcDbObject*& pClonedObject, AcDbIdMapping& idMap,
			bool isPrimary = true) const override;

public:
	ACDB_DECLARE_MEMBERS_EXPIMP(AcDbModelDocViewStyle, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT ~AcDbModelDocViewStyle() = 0;

	ACDBCORE2D_PORT static AcGePoint3d calculateViewLabelPosition(
			AcGeVector2d& offsetVector, AcDbMText::AttachmentPoint& textAlignment,
			AcDbModelDocViewStyle::AttachmentPoint attachment, double offset,
			const AcGePoint3d& minPt, const AcGePoint3d& maxPt);
	ACDBCORE2D_PORT AcString defaultViewName(int index) const;
	ACDBCORE2D_PORT virtual const ACHAR* description(void) const;
	ACDBCORE2D_PORT virtual void getDescription(AcString& strDescription) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getName(ACHAR*& pszName) const final;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getName(AcString& strName) const;
	ACDBCORE2D_PORT bool isModifiedForRecompute() const;
	ACDBCORE2D_PORT bool isViewNameValid(const ACHAR* pName) const;
	ACDBCORE2D_PORT Acad::ErrorStatus postViewStyleToDb(AcDbDatabase* pDb, const ACHAR* styleName,
														AcDbObjectId& viewStyleId);
	ACDBCORE2D_PORT void setDatabaseDefaults(AcDbDatabase* pDb);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setDescription(const ACHAR* pszDescription);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setName(const ACHAR* pszName);
	ACDBCORE2D_PORT static AcGeVector2d setViewLabelPosition(
			AcDbMText* pMText, AcDbModelDocViewStyle::AttachmentPoint attachment, double offset,
			const AcGePoint3d& minPt, const AcGePoint3d& maxPt);
	ACDBCORE2D_PORT static AcGeVector2d updateViewLabelPosition(
			AcDbMText* pMText, AcDbModelDocViewStyle::AttachmentPoint& attachment,
			const AcGePoint3d& minPt, const AcGePoint3d& maxPt);
};

#include "icarx/IcArxPackPop.h"

inline Acad::ErrorStatus AcDbModelDocViewStyle::getName(ACHAR*& pName) const
{
	return ::acutGetAcStringConvertToAChar(this, &AcDbModelDocViewStyle::getName, pName);
}

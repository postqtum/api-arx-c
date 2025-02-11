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
***     Description: Declaration of AcDbAssocDimDependencyBodyBase class
***
*****************************************************************************/
#pragma once

#include "AcDbAssocGlobal.h"
#include "AcString.h"
#include "acarray.h"
#include "AcConstrainedGeometry.h"
#include "AcDbAssocDependencyBody.h"

class AcExplicitConstraint;

#include "icarx/IcArxPackPush.h"

class AcDbAssocDimDependencyBodyBase : public AcDbAssocDependencyBody
{
public:
	class NotificationIgnorer
	{
	private:
		const bool mPrevIsIgnoringNotifications;
		static bool smIsIgnoringNotifications;

	public:
		ACDBCORE2D_PORT NotificationIgnorer();
		ACDBCORE2D_PORT ~NotificationIgnorer();
		ACDBCORE2D_PORT static bool isIgnoringNotifications();
	};

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbAssocDimDependencyBodyBase, ACDBCORE2D_PORT);

public:
	ACDBCORE2D_PORT explicit AcDbAssocDimDependencyBodyBase(
			AcDbAssocCreateImpObject createImpObject = kAcDbAssocCreateImpObject);
	ACDBCORE2D_PORT ~AcDbAssocDimDependencyBodyBase();

	ACDBCORE2D_PORT AcString composeEntityText(int requiredNameFormat = -1) const;
	ACDBCORE2D_PORT AcExplicitConstraint* constraint() const;
	ACDBCORE2D_PORT Acad::ErrorStatus deactivateConstraint() const;
	ACDBCORE2D_PORT void dragStatus(const AcDb::DragStat status);
	ACDBCORE2D_PORT Acad::ErrorStatus entityAttachmentPointMoved(
			const AcArray<AcDbSubentGeometry>& newAttachedGeometries, double measurement = 0.);
	ACDBCORE2D_PORT void erasedOverride(const AcDbObject* pDbObj, bool isErasing);
	ACDBCORE2D_PORT void evaluateOverride();
	ACDBCORE2D_PORT static AcString formatToCurrentPrecision(const AcString& expression,
															 bool isAngular);
	ACDBCORE2D_PORT Acad::ErrorStatus getConstrainedGeoms(
			AcArray<AcConstrainedGeometry*>& geoms) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getConstrainedGeoms(AcArray<AcDbFullSubentPath>& geoms) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getConstrainedGeoms(AcArray<AcDbSubentGeometry>& geoms,
														  AcGeVector3d& distanceDirection) const;
	ACDBCORE2D_PORT int getCurrentlyUsedEntityNameFormat() const;
	ACDBCORE2D_PORT virtual double getEntityMeasurementOverride() const = 0;
	ACDBCORE2D_PORT Acad::ErrorStatus getEntityNameAndExpression(AcString& name,
																 AcString& expression) const;
	ACDBCORE2D_PORT virtual AcString getEntityTextOverride() const = 0;
	ACDBCORE2D_PORT static bool getEraseDimensionIfDependencyIsErased();
	ACDBCORE2D_PORT static Acad::ErrorStatus getFromEntity(const AcDbObjectId& entityId,
														   AcDbObjectId& dimDepBodyId);
	ACDBCORE2D_PORT Acad::ErrorStatus getMeasuredValue(double& measurement) const;
	ACDBCORE2D_PORT static Acad::ErrorStatus getNameAndExpressionFromEntityText(
			const AcString& entityText, bool useMeasurementIfNoText, double measurement,
			bool isAngular, AcString& name, AcString& expression);
	ACDBCORE2D_PORT Acad::ErrorStatus getVariableNameAndExpression(AcString& name,
																   AcString& expression,
																   AcString& value) const;
	ACDBCORE2D_PORT bool isConstraintActive() const;
	ACDBCORE2D_PORT virtual bool isEntityAttachmentChangedOverride() const = 0;
	ACDBCORE2D_PORT Acad::ErrorStatus isRelevantChangeOverride(bool& isRelevChange) const;
	ACDBCORE2D_PORT void modifiedOverride(const AcDbObject* pDbObj);
	ACDBCORE2D_PORT Acad::ErrorStatus reactivateConstraint() const;
	ACDBCORE2D_PORT Acad::ErrorStatus setEntityNameAndExpression(const AcString& name,
																 const AcString& expression,
																 const AcString& value);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setEntityTextOverride(const AcString& newText) = 0;
	ACDBCORE2D_PORT static bool setEraseDimensionIfDependencyIsErased(bool yesNo);
	ACDBCORE2D_PORT Acad::ErrorStatus setIsReferenceOnly(bool yesNo);
	ACDBCORE2D_PORT Acad::ErrorStatus setNameAndExpression(const AcString& name,
														   const AcString& expression);
	ACDBCORE2D_PORT Acad::ErrorStatus setVariableNameAndExpression(const AcString& name,
																   const AcString& expression);
	ACDBCORE2D_PORT Acad::ErrorStatus setVariableValueToMeasuredValue() const;
	ACDBCORE2D_PORT Acad::ErrorStatus subErase(bool erasing);
	ACDBCORE2D_PORT Acad::ErrorStatus updateDependentOnObjectOverride();
	ACDBCORE2D_PORT Acad::ErrorStatus updateEntityText();
	ACDBCORE2D_PORT Acad::ErrorStatus validateEntityText(const AcString& entityTextToValidate,
														 AcString& errorMessage) const;
	ACDBCORE2D_PORT AcDbObjectId variable() const;
};

#include "icarx/IcArxPackPop.h"

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
***     Description: Declaration of AcDMMEntityReactorInfo class
***
*****************************************************************************/
#pragma once

#include "../dbidar.h"
#include "AcDMMWideString.h"

class AcDbObjectId;
class AcDbEntity;
class AcDMMNode;
class AcPlPlotLogger;
class AcDMMEPlotProperties;

#include "IcArxPackPush.h"

class AcDMMEntityReactorInfo
{
protected:
	AcDMMEntityReactorInfo() = default;

public:
	virtual ~AcDMMEntityReactorInfo() = default;

	virtual bool AddNodeToMap(
					  AcDbObjectId Id, AcDbObjectIdArray objIds, int nodeId) = 0;
	virtual bool AddProperties(const AcDMMEPlotProperties* props) = 0;
	virtual bool AddPropertiesIds(AcDMMStringVec* IdVec, AcDMMNode& node) = 0;
	virtual bool GetCurrentEntityNode(AcDMMNode& node, AcDbObjectIdArray objIds) const = 0;
	virtual bool GetEntityNode(AcDbObjectId id, AcDbObjectIdArray objIds, int& nodeId) const = 0;
	virtual int GetNextAvailableNodeId() const = 0;
	virtual const AcDMMNode* GetNode(int nodeId) const = 0;
	virtual AcPlPlotLogger* GetPlotLogger() = 0;
	virtual bool SetCurrentNode(int nodeId, AcDbObjectIdArray objIds) = 0;
	virtual bool SetNodeName(int nodeNumber, const wchar_t* name) = 0;
	virtual const wchar_t* UniqueEntityId() = 0;
	virtual bool add3DDwfAttribute(const wchar_t* category, const wchar_t* name, const wchar_t* ns,
								   const wchar_t* nsUrl, const wchar_t* attName,
								   const wchar_t* attVal) = 0;
	virtual bool add3DDwfProperty(const wchar_t* category, const wchar_t* name,
								  const wchar_t* value) = 0;
	virtual void cancelTheJob() = 0;
	virtual AcDbObjectId effectiveBlockLayerId() const = 0;
	virtual AcDbEntity* entity() const = 0;
	virtual void flush() = 0;
	virtual const AcDbObjectIdArray& getEntityBlockRefPath() = 0;
	virtual const AcArray<long>& getGraphicIDs() = 0;
	virtual bool isCancelled() const = 0;
};

#include "IcArxPackPop.h"

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
***     Description: Declaration of AcDMMNode class
***
*****************************************************************************/
#pragma once

#include "../AcString.h"

#include "IcArxPackPush.h"

class AcDMMNode
{
private:
	int m_nodeNumber = 0;
	AcString m_nodeName;

public:
	AcDMMNode() = default;
	AcDMMNode(int number, const wchar_t* name) : m_nodeNumber(number), m_nodeName(name) {}
	AcDMMNode(const AcDMMNode& src) = default;
	~AcDMMNode() = default;
	AcDMMNode& operator=(const AcDMMNode& src) = default;

	void SetNodeName(const wchar_t* name) { m_nodeName = name; }
	void SetNodeNumber(int number) { m_nodeNumber = number; };
	const wchar_t* nodeName() const { return m_nodeName.isEmpty() ? nullptr : m_nodeName.constPtr(); };
	int nodeNumber() const { return m_nodeNumber; };
};

#include "IcArxPackPop.h"

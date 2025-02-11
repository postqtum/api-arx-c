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
***     Description: Declaration of AcDMMSheetReactorInfo class
***
*****************************************************************************/
#pragma once

#include <tchar.h>

#include "../acdmmeplotproperty.h"
#include "../acdmmutils.h"

class AcPlPlotLogger;
class AcDbDatabase;
class AcDbObjectId;
class Ac3dDwfNavTreeNode;

#include "IcArxPackPush.h"

class AcDMMSheetReactorInfo
{
public:
	enum PlotArea
	{
		kDisplay = 0,
		kExtents = 1,
		kLimits = 2,
		kView,
		kWindow,
		kLayout
	};

	enum PlotMediaUnits
	{
		kInches,
		kMillimeters,
		kPixels
	};

	enum PlotRotation
	{
		k0degrees,
		k90degrees,
		k180degrees,
		k270degrees
	};

protected:
	AcDMMSheetReactorInfo() = default;

public:
	virtual ~AcDMMSheetReactorInfo() = default;

	virtual void AddPageProperties(AcDMMEPlotPropertyVec props) = 0;
	virtual void AddPageResources(AcDMMResourceVec resources) = 0;
	virtual AcPlPlotLogger* GetPlotLogger() = 0;
	virtual const ACHAR* UniqueLayoutId() = 0;
	virtual bool areLinesHidden() const = 0;
	virtual bool arePlottingLineWeights() const = 0;
	virtual bool areScalingLineWeights() const = 0;
	virtual const TCHAR* canonicalMediaName() const = 0;
	virtual const TCHAR* configuration() const = 0;
	virtual AcDbDatabase* database() const = 0;
	virtual double displayMaxX() const = 0;
	virtual double displayMaxY() const = 0;
	virtual double displayMinX() const = 0;
	virtual double displayMinY() const = 0;
	virtual double drawingScale() const = 0;
	virtual double effectivePlotOffsetX() const = 0;
	virtual int effectivePlotOffsetXdevice() const = 0;
	virtual double effectivePlotOffsetY() const = 0;
	virtual int effectivePlotOffsetYdevice() const = 0;
	virtual Ac3dDwfNavTreeNode* get3dDwfNavigationTreeNode() = 0;
	virtual bool isModelLayout() const = 0;
	virtual bool isPlotJobCancelled() const = 0;
	virtual bool isScaleSpecified() const = 0;
	virtual double layoutBoundsMaxX() const = 0;
	virtual double layoutBoundsMaxY() const = 0;
	virtual double layoutBoundsMinX() const = 0;
	virtual double layoutBoundsMinY() const = 0;
	virtual double layoutMarginMaxX() const = 0;
	virtual double layoutMarginMaxY() const = 0;
	virtual double layoutMarginMinX() const = 0;
	virtual double layoutMarginMinY() const = 0;
	virtual double maxBoundsX() const = 0;
	virtual double maxBoundsY() const = 0;
	virtual double originX() const = 0;
	virtual double originY() const = 0;
	virtual double paperScale() const = 0;
	virtual AcDMMSheetReactorInfo::PlotArea plotArea() const = 0;
	virtual double plotBoundsMaxX() const = 0;
	virtual double plotBoundsMaxY() const = 0;
	virtual double plotBoundsMinX() const = 0;
	virtual double plotBoundsMinY() const = 0;
	virtual AcDbObjectId plotLayoutId() const = 0;
	virtual AcDMMSheetReactorInfo::PlotMediaUnits plotMediaUnits() const = 0;
	virtual AcDMMSheetReactorInfo::PlotRotation plotRotation() const = 0;
	virtual const TCHAR* plotToFileName() const = 0;
	virtual const TCHAR* plotToFilePath() const = 0;
	virtual double plotWindowMaxX() const = 0;
	virtual double plotWindowMaxY() const = 0;
	virtual double plotWindowMinX() const = 0;
	virtual double plotWindowMinY() const = 0;
	virtual double printableBoundsX() const = 0;
	virtual double printableBoundsY() const = 0;
	virtual bool publishingTo3DDwf() const = 0;
	virtual bool set3dDwfNavigationTreeNode(const Ac3dDwfNavTreeNode* root) = 0;
	virtual double stepsPerInch() const = 0;
	virtual const TCHAR* viewPlotted() const = 0;
};

#include "IcArxPackPop.h"

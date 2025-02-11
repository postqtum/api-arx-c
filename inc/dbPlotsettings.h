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
***     Description: Declaration of AcDbPlotSettings class
***
*****************************************************************************/
#pragma once

#include "dbmain.h"
#include "dbdict.h"
#include "AcDbCore2dDefs.h"

class IAcReadStream;

#include "icarx/IcArxPackPush.h"

class AcDbPlotSettings : public AcDbObject
{
public:
	enum PlotPaperUnits
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

	enum PlotType
	{
		kDisplay,
		kExtents,
		kLimits,
		kView,
		kWindow,
		kLayout
	};

	enum ShadePlotResLevel
	{
		kDraft,
		kPreview,
		kNormal,
		kPresentation,
		kMaximum,
		kCustom
	};

	enum ShadePlotType
	{
		kAsDisplayed = 0,
		kWireframe = 1,
		kHidden = 2,
		kRendered = 3,
		kVisualStyle = 4,
		kRenderPreset = 5
	};

	enum StdScaleType
	{
		kScaleToFit,
		k1_128in_1ft,
		k1_64in_1ft,
		k1_32in_1ft,
		k1_16in_1ft,
		k3_32in_1ft,
		k1_8in_1ft,
		k3_16in_1ft,
		k1_4in_1ft,
		k3_8in_1ft,
		k1_2in_1ft,
		k3_4in_1ft,
		k1in_1ft,
		k3in_1ft,
		k6in_1ft,
		k1ft_1ft,
		k1_1,
		k1_2,
		k1_4,
		k1_5,
		k1_8,
		k1_10,
		k1_16,
		k1_20,
		k1_30,
		k1_40,
		k1_50,
		k1_100,
		k2_1,
		k4_1,
		k8_1,
		k10_1,
		k100_1,
		k1000_1,
		k1and1_2in_1ft
	};

protected:
	virtual Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbPlotSettings);

	AcDbPlotSettings();
	AcDbPlotSettings(bool ModelType);
	~AcDbPlotSettings();

	using AcDbObject::copyFrom;

	Acad::ErrorStatus addToPlotSettingsDict(AcDbDatabase* towhichDb);
	Acad::ErrorStatus copyFrom(AcDbPlotSettings* fromPlotSettings);
	bool drawViewportsFirst() const;
	Acad::ErrorStatus getCanonicalMediaName(const ACHAR*& mediaName) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getCanonicalMediaName(AcString& mediaName) const;
	Acad::ErrorStatus getCurrentStyleSheet(const ACHAR*& styleSheetName) const;
	Acad::ErrorStatus getCustomPrintScale(double& numerator, double& denominator) const;
	Acad::ErrorStatus getPlotCfgName(const ACHAR*& plotCfgName) const;
	Acad::ErrorStatus getPlotOrigin(double& x, double& y) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getPlotOrigin(AcGePoint2d& origin) const;
	Acad::ErrorStatus getPlotPaperMargins(double& printableXmin, double& printableYmin,
										  double& printableXmax, double& printableYmax) const;
	Acad::ErrorStatus getPlotPaperSize(double& paperWidth, double& paperHeight) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getPlotPaperSize(AcGePoint2d& paperSize) const;
	Acad::ErrorStatus getPlotSettingsName(const ACHAR*& plotSettingsName) const;
	Acad::ErrorStatus getPlotSettingsName(ACHAR*& plotSettingsName) const;
	Acad::ErrorStatus getPlotViewName(const ACHAR*& viewName) const;
	Acad::ErrorStatus getPlotWindowArea(double& xmin, double& ymin, double& xmax,
										double& ymax) const;
	Acad::ErrorStatus getStdScale(double& scale) const;
	ACDBCORE2D_PORT IAcReadStream* getStyleSheetReadStream();
	bool modelType() const;
	bool plotAsRaster() const;
	bool plotCentered() const;
	bool plotHidden() const;
	AcDbPlotSettings::PlotPaperUnits plotPaperUnits() const;
	bool plotPlotStyles() const;
	AcDbPlotSettings::PlotRotation plotRotation() const;
	bool plotTransparency() const;
	AcDbPlotSettings::PlotType plotType() const;
	bool plotViewportBorders() const;
	bool plotWireframe() const;
	bool printLineweights() const;
	bool scaleLineweights() const;
	void setDrawViewportsFirst(bool drawViewportsFirst);
	void setPlotHidden(bool plotHidden);
	void setPlotPlotStyles(bool plotPlotStyles);
	Acad::ErrorStatus setPlotSettingsName(const ACHAR* plotSettingsName);
	void setPlotTransparency(bool plotTransparency);
	void setPlotViewportBorders(bool plotViewportBorders);
	void setPrintLineweights(bool printLineweights);
	void setScaleLineweights(bool scaleLineweights);
	Acad::ErrorStatus setShadePlot(AcDbPlotSettings::ShadePlotType shadePlot);
	Acad::ErrorStatus setShadePlot(AcDbPlotSettings::ShadePlotType type, AcDbObjectId shadePlotId);
	Acad::ErrorStatus setShadePlotCustomDPI(int16_t val);
	Acad::ErrorStatus setShadePlotResLevel(AcDbPlotSettings::ShadePlotResLevel resLevel);
	void setShowPlotStyles(bool showPlotStyles);
	AcDbPlotSettings::ShadePlotType shadePlot() const;
	int16_t shadePlotCustomDPI() const;
	AcDbObjectId shadePlotId() const;
	AcDbPlotSettings::ShadePlotResLevel shadePlotResLevel() const;
	bool showPlotStyles() const;
	AcDbPlotSettings::StdScaleType stdScaleType() const;
	bool useStandardScale() const;
};

#include "icarx/IcArxPackPop.h"

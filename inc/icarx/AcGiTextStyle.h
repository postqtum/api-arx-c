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
***     Description: Declaration of AcGiTextStyle class
***
*****************************************************************************/
#pragma once

#include "../acgiparameter.h"
#include "../AcString.h"
#include "../PAL/api/charset.h"
#include "../PAL/api/FontPitchAndFamily.h"
#include "acut_str_util.h"

class AcGiImpTextStyle;
class AcDbDatabase;
class AcGePoint2d;
class AcGiWorldDraw;

#include "IcArxPackPush.h"

class AcGiTextStyle : public AcGiParameter
{
public:
	ACRX_DECLARE_MEMBERS_READWRITE(AcGiTextStyle, AcGiImpTextStyle);

	AcGiTextStyle(AcDbDatabase* pDb = nullptr);
	AcGiTextStyle(const ACHAR* fontName, const ACHAR* bigFontName, const double textSize,
				  const double xScale, const double obliqueAngle, const double trPercent,
				  const bool isBackward, const bool isUpsideDown, const bool isVertical,
				  const bool isOverlined, const bool isUnderlined,
				  const bool isStrikethrough = false,
				  const ACHAR* styleName = nullptr);
	~AcGiTextStyle();

	virtual const ACHAR* bigFontFileName() const;
	virtual AcGePoint2d extents(const ACHAR* pStr, const bool penups, const int len, const bool raw,
								AcGiWorldDraw* ctxt = nullptr) const;
	virtual Acad::ErrorStatus extentsBox(const ACHAR* pStr, const bool penups, const int len,
										 const bool raw, AcGePoint2d& extMin, AcGePoint2d& extMax,
										 AcGiWorldDraw* ctxt = nullptr) const;
	virtual const ACHAR* fileName() const;
	virtual Acad::ErrorStatus font(
			ACHAR*& pTypeface, bool& bold, bool& italic, Charset& charset,
			Autodesk::AutoCAD::PAL::FontUtils::FontPitch& pitch,
			Autodesk::AutoCAD::PAL::FontUtils::FontFamily& family) const final;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus font(
			AcString& sTypeface, bool& bold, bool& italic, Charset& charset,
			Autodesk::AutoCAD::PAL::FontUtils::FontPitch& pitch,
			Autodesk::AutoCAD::PAL::FontUtils::FontFamily& family) const;
	virtual bool isBackward() const;
	virtual bool isOverlined() const;
	virtual bool isStrikethrough() const;
	virtual bool isUnderlined() const;
	virtual bool isUpsideDown() const;
	virtual bool isVertical() const;
	virtual int loadStyleRec(AcDbDatabase* pDb = nullptr) const;
	virtual double obliquingAngle() const;
	virtual bool preLoaded() const;
	virtual void setBackward(const bool isBackward);
	virtual void setBigFontFileName(const ACHAR* bigFontFileName);
	virtual void setFileName(const ACHAR* fontName);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setFont(
			const ACHAR* pTypeface, bool bold, bool italic, Charset charset,
			Autodesk::AutoCAD::PAL::FontUtils::FontPitch pitch,
			Autodesk::AutoCAD::PAL::FontUtils::FontFamily family);
	virtual void setObliquingAngle(const double obliquingAngle);
	virtual void setOverlined(const bool isOverlined);
	virtual void setPreLoaded(bool);
	virtual void setStrikethrough(const bool isStrikethrough);
	virtual Acad::ErrorStatus setStyleName(const ACHAR*);
	virtual void setTextSize(const double size);
	virtual void setTrackKerning(double trackPercent) const;
	virtual void setTrackingPercent(const double trPercent);
	virtual void setUnderlined(const bool isUnderlined);
	virtual void setUpsideDown(const bool isUpsideDown);
	virtual void setVertical(const bool isVertical);
	virtual void setXScale(const double xScale);
	virtual const ACHAR* styleName() const;
	virtual double textSize() const;
	virtual double trackingPercent() const;
	virtual double xScale() const;
};

#include "IcArxPackPop.h"

inline Acad::ErrorStatus AcGiTextStyle::font(
		ACHAR*& pTypeface, bool& bold, bool& italic, Charset& charset,
		Autodesk::AutoCAD::PAL::FontUtils::FontPitch& pitch,
		Autodesk::AutoCAD::PAL::FontUtils::FontFamily& family) const
{
	AcString sTypeface;
	const Acad::ErrorStatus es = this->font(sTypeface, bold, italic, charset, pitch, family);
	::acutNewString(sTypeface.constPtr(), pTypeface);
	return es;
}

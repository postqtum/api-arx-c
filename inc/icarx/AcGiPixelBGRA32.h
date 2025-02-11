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
***     Description: Declaration of AcGiPixelBGRA32 class
***
*****************************************************************************/
#pragma once

#include "../adesk.h"

#include "IcArxPackPush.h"

class AcGiPixelBGRA32
{
private:
	union
	{
		uint32_t m_whole;
		struct PIXEL
		{
			uint8_t b, g, r, a;
		} m_bgra;
	};

public:
	AcGiPixelBGRA32()
	{
		m_bgra.b = 0;
		m_bgra.g = 0;
		m_bgra.r = 0;
		m_bgra.a = 255;
	}
	AcGiPixelBGRA32(uint32_t bgra) : m_whole(bgra) {}
	AcGiPixelBGRA32(uint8_t blue, uint8_t green, uint8_t red, uint8_t alpha)
	{
		m_bgra.b = blue;
		m_bgra.g = green;
		m_bgra.r = red;
		m_bgra.a = alpha;
	}

	uint8_t alpha() const;
	uint8_t blue() const;
	uint32_t getBGRA() const;
	uint32_t getRGBA() const;
	uint8_t green() const;
	uint8_t red() const;
	void setBGRA(uint8_t blue, uint8_t green, uint8_t red, uint8_t alpha);
	void setBGRA(uint32_t bgra);
	void setRGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
	void setRGBA(uint32_t rgba);
	void setAlpha(uint8_t alpha);
	void setBlue(uint8_t blue);
	void setGreen(uint8_t green);
	void setRed(uint8_t red);
};

#include "IcArxPackPop.h"

inline uint8_t AcGiPixelBGRA32::alpha() const
{
	return m_bgra.a;
}

inline uint8_t AcGiPixelBGRA32::blue() const
{
	return m_bgra.b;
}

inline uint32_t AcGiPixelBGRA32::getBGRA() const
{
	return m_whole;
}

inline uint32_t AcGiPixelBGRA32::getRGBA() const
{
	return (uint32_t)(m_bgra.a) << 24 | (uint32_t)(m_bgra.b) << 16 |
		   (uint32_t)(m_bgra.g) << 8 | (uint32_t)(m_bgra.r);
}

inline uint8_t AcGiPixelBGRA32::green() const
{
	return m_bgra.g;
}

inline uint8_t AcGiPixelBGRA32::red() const
{
	return m_bgra.r;
}

inline void AcGiPixelBGRA32::setBGRA(uint8_t blue, uint8_t green, uint8_t red,
									 uint8_t alpha)
{
	m_bgra.b = blue;
	m_bgra.g = green;
	m_bgra.r = red;
	m_bgra.a = alpha;
}

inline void AcGiPixelBGRA32::setBGRA(uint32_t bgra)
{
	m_whole = bgra;
}

inline void AcGiPixelBGRA32::setRGBA(uint8_t red, uint8_t green, uint8_t blue,
									 uint8_t alpha)
{
	m_bgra.r = red;
	m_bgra.g = green;
	m_bgra.b = blue;
	m_bgra.a = alpha;
}

inline void AcGiPixelBGRA32::setRGBA(uint32_t rgba)
{
	m_bgra.r = (uint8_t)(rgba & 0x000000FF);
	m_bgra.g = (uint8_t)((rgba & 0x0000FF00) >> 8);
	m_bgra.b = (uint8_t)((rgba & 0x00FF0000) >> 16);
	m_bgra.a = (uint8_t)((rgba & 0xFF000000) >> 24);
}

inline void AcGiPixelBGRA32::setAlpha(uint8_t alpha)
{
	m_bgra.a = alpha;
}

inline void AcGiPixelBGRA32::setBlue(uint8_t blue)
{
	m_bgra.b = blue;
}

inline void AcGiPixelBGRA32::setGreen(uint8_t green)
{
	m_bgra.g = green;
}

inline void AcGiPixelBGRA32::setRed(uint8_t red)
{
	m_bgra.r = red;
}

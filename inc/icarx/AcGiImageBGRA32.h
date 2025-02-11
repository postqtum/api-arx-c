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
***     Description: Declaration of AcGiImageBGRA32 class
***
*****************************************************************************/
#pragma once

#include "../adesk.h"

class AcGiPixelBGRA32;

#include "IcArxPackPush.h"

class AcGiImageBGRA32
{
private:
	AcGiPixelBGRA32* m_pImageData = nullptr;
	uint32_t m_nImageWidth = 0;
	uint32_t m_nImageHeight = 0;

public:
	AcGiImageBGRA32() = default;
	AcGiImageBGRA32(uint32_t imageWidth, uint32_t imageHeight, AcGiPixelBGRA32* imageData)
			: m_pImageData(imageData), m_nImageWidth(imageWidth), m_nImageHeight(imageHeight)
	{
	}

	uint32_t height() const;
	AcGiPixelBGRA32* image() const;
	void setImage(uint32_t imageWidth, uint32_t imageHeight, AcGiPixelBGRA32* imageData);
	uint32_t width() const;
};

#include "IcArxPackPop.h"

inline uint32_t AcGiImageBGRA32::height() const
{
	return m_nImageHeight;
}

inline AcGiPixelBGRA32* AcGiImageBGRA32::image() const
{
	return m_pImageData;
}

inline void AcGiImageBGRA32::setImage(uint32_t imageWidth, uint32_t imageHeight,
									  AcGiPixelBGRA32* imageData)
{
	m_nImageWidth = imageWidth;
	m_nImageHeight = imageHeight;
	m_pImageData = imageData;
}

inline uint32_t AcGiImageBGRA32::width() const
{
	return m_nImageWidth;
}

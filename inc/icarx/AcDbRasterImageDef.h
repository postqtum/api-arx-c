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
***     Description: Declaration of AcDbRasterImageDef class
***
*****************************************************************************/
#pragma once

#include "../acgi.h"
#include "../dbmain.h"

#include "IsmDllAccess.h"

class RasterImageDefImp;
class IAcReadStream;

typedef struct tagBITMAPINFO BITMAPINFO;

namespace Atil
{
class Image;
class FileReadDescriptor;
};	// namespace Atil

enum ClassVersion
{
	kVersion1 = 0,
	kVersion2 = 1,
	kVersion3 = 2
};

#include "IcArxPackPush.h"
#pragma warning(disable : 4275)

class ISMDLLACCESS AcDbRasterImageDef : public AcDbObject
{
public:
	enum Units
	{
		kNone = 0,
		kMillimeter = 1,
		kCentimeter = 2,
		kMeter = 3,
		kKilometer = 4,
		kInch = 5,
		kFoot = 6,
		kYard = 7,
		kMile = 8,
		kMicroinches = 9,
		kMils = 10,
		kAngstroms = 11,
		kNanometers = 12,
		kMicrons = 13,
		kDecimeters = 14,
		kDekameters = 15,
		kHectometers = 16,
		kGigameters = 17,
		kAstronomical = 18,
		kLightYears = 19,
		kParsecs = 20
	};

	enum
	{
		kMaxSuggestNameSize = 2049
	};

private:
	RasterImageDefImp* mpImp = nullptr;
	static ClassVersion mVersion;

public:
	ACRX_DECLARE_MEMBERS(AcDbRasterImageDef);

	AcDbRasterImageDef();
	~AcDbRasterImageDef();

	virtual const ACHAR* activeFileName() const;
	static ClassVersion classVersion() { return mVersion; }
	virtual Acad::ErrorStatus closeImage();
	virtual int colorDepth() const;
	static Acad::ErrorStatus createImageDictionary(AcDbDatabase* pDb, AcDbObjectId& dictId);
	virtual void* createThumbnailBitmap(BITMAPINFO*& pBitmapInfo, uint8_t brightness = 50,
										uint8_t contrast = 50, uint8_t fade = 0);
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* filer) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* filer) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* filer) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* filer) const override;
	virtual Acad::ErrorStatus embed();
	virtual int entityCount(bool* pbLocked = 0) const;
	virtual Atil::FileReadDescriptor* fileDescCopy() const;
	virtual const ACHAR* fileType() const;
	Acad::ErrorStatus forceImageFileClosed(bool modifyDatabase);
	virtual IAcReadStream* getReadStream();
	virtual Atil::Image* imageCopy(bool bForceImageLoad = true) const;
	static AcDbObjectId imageDictionary(AcDbDatabase* pDb);
	virtual bool imageModified() const;
	virtual bool isEmbedded() const;
	virtual bool isLoaded() const;
	virtual Acad::ErrorStatus load();
	virtual Acad::ErrorStatus loadThumbnail(uint16_t& maxWidth, uint16_t& maxHeight,
											uint8_t* pPalette = 0, int nPaletteEntries = 0);
	virtual AcGiSentScanLines* makeScanLines(const AcGiRequestScanLines* pReq,
											 const AcGeMatrix2d& pixToScreen,
											 AcGePoint2dArray* pActiveClipBndy = 0,
											 bool draftQuality = false, bool isTransparent = false,
											 const double brightness = 50.0,
											 const double contrast = 50.0,
											 const double fade = 0.0) const;
	virtual Acad::ErrorStatus openImage(Atil::Image*& pImage);
	virtual AcGiImageOrg organization() const;
	RasterImageDefImp* ptrImp() const { return mpImp; }
	virtual AcGeVector2d resolutionMMPerPixel() const;
	virtual Units resolutionUnits() const;
	virtual const ACHAR* searchForActivePath();
	virtual Acad::ErrorStatus setActiveFileName(const ACHAR* pPathName);
	virtual Acad::ErrorStatus setImage(const Atil::Image* pImage,
									   const Atil::FileReadDescriptor* pFileDesc,
									   bool modifyDatabase = true);
	virtual Acad::ErrorStatus setImageModified(bool modified);
	RasterImageDefImp* setPtrImp(RasterImageDefImp* pImp);
	virtual Acad::ErrorStatus setResolutionMMPerPixel(const AcGeVector2d& resMMPerPixel);
	virtual void setResolutionUnits(AcDbRasterImageDef::Units units);
	virtual Acad::ErrorStatus setSourceFileName(const ACHAR* pPathName);
	virtual Acad::ErrorStatus setUndoStoreSize(unsigned int maxImages = 10);
	virtual bool shouldLoad() const;
	virtual AcGeVector2d size() const;
	virtual const ACHAR* sourceFileName() const;
	Acad::ErrorStatus subClose() override;
	Acad::ErrorStatus subErase(bool erasing) override;
	static Acad::ErrorStatus suggestName(AcDbDictionary* pImageDictionary,
										 const ACHAR* pNewImagePathName, ACHAR* newImageName,
										 size_t nSize);
	virtual unsigned int undoStoreSize() const;
	virtual Acad::ErrorStatus unload(bool modifyDatabase = true);
	virtual Acad::ErrorStatus unloadThumbnail();
	virtual void updateEntities() const;
};

#include "IcArxPackPop.h"

inline RasterImageDefImp* AcDbRasterImageDef::setPtrImp(RasterImageDefImp* pImp)
{
	RasterImageDefImp* oldImp = mpImp;
	mpImp = pImp;
	return oldImp;
}

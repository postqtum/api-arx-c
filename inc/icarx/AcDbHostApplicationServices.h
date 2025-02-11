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
***     Description: Declaration of AcDbHostApplicationServices class
***
*****************************************************************************/
#pragma once

#include "../acarray.h"
#include "../AcString.h"
#include "../rxobject.h"
#include "../inetstrc.h"
#include "../PAL/api/codepgid.h"
#include "../PAL/api/product_flavors.h"
#include "AcRxDynamicLinker.h"

using SELECTFILEPROC = Acad::ErrorStatus (*)(/*[out]*/ short* userCancel,
											 /*[out]*/ ACHAR*& chosenPath,
											 void* h,  // HWND
											 const int nFlags, const ACHAR* prompt,
											 const ACHAR* dir, const ACHAR* name, const ACHAR* type,
											 int* pnChoice, bool* pbReadOnly,
											 const ACHAR* pszWSTags, AcStringArray* pReserved);
using REMAPPROC = Acad::ErrorStatus (*)(/*[out]*/ ACHAR*& newName, const ACHAR* filename,
										int context, void* pReserved);
using MAPFILENOTIFYPROC = void (*)(const ACHAR* filename, const ACHAR* newName, int context,
								   void* pReserved);

class AcDbDatabase;
class AcDbHostApplicationProgressMeter;
class AcDbAbstractClipBoundaryDefinition;
class ClipBoundaryArray;
class AcDbUndoController;
class AcDbTransactionManager;
class AcDbGlobals;
class AcDbAppSystemVariables;
class AcLocale;
class COleClientItem;
class CArchive;
struct flagmat;
class AcDbAuditInfo;
class AcDbPlotSettingsValidator;
class AcDbLayoutManager;
class AcPwdCache;
class AcDbObjectId;

ACDBCORE2D_PORT AcDbGlobals* getDefaultGlobals();

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcDbHostApplicationServices : public AcRxObject
{
	friend class AcadInternalServices;

public:
	enum FindFileHint
	{
		kDefault = 0,
		kFontFile,
		kCompiledShapeFile,
		kTrueTypeFontFile,
		kEmbeddedImageFile,
		kXRefDrawing,
		kPatternFile,
		kARXApplication,
		kFontMapFile,
		kUnderlayFile,
		kDataLinkFile,
		kPhotometricWebFile,
		kMaterialMapFile,
		kCloudOrProjectFile,
	};

	enum ModelerFlavor
	{
		kModelerFull = 0,
		kModelerRegionsOnly = 1,
		kModelerObjectsOnly = 2
	};

	enum PasswordOptions
	{
		kPasswordOptionDefault = 0,
		kPasswordOptionUpperCase = 1,
		kPasswordOptionIsExternalReference = 2
	};

	enum RemapFileContext
	{
		kDrawingOpen,
		kXrefResolution,
		kRasterResolution,
		kAfterXrefResolution
	};

	enum RequiredVersionFlags
	{
		kNoOpen = 0,
		kReadOnly = 1,
		kWriteAllowed = 2
	};

protected:
	void* mp_sessionVars = nullptr;

private:
	AcDbDatabase* mpWorkingDatabase = nullptr;
	AcDbUndoController* mpDefaultUndoController = nullptr;
	AcDbTransactionManager* mpWorkingTransactionManager = nullptr;
	AcDbGlobals* mpWorkingGlobals = nullptr;
	AcDbAppSystemVariables* mpWorkingAppSysvars = nullptr;
	code_page_id m_eSystemCodePage = code_page_id::CODE_PAGE_UNDEFINED;
	bool mbDisplayMessages = true;
	AcPwdCache* mpPasswordCache = nullptr;
	CString m_releaseMarketVersion = L""; // progesoft

private:
	virtual Acad::ErrorStatus findFile(ACHAR* pcFullPathOut, int nBufferLength,
									   const ACHAR* pcFilename, AcDbDatabase* pDb = nullptr,
									   FindFileHint hint = kDefault) = 0;

protected:
	void acadInternalSetvar(const ACHAR* name, void* var);
	Acad::ErrorStatus mapInetStatusToAcadStatus(const AcadInet::Status status) const;

public:
	ACRX_DECLARE_MEMBERS(AcDbHostApplicationServices);

	ACDBCORE2D_PORT AcDbHostApplicationServices(int createGlobals = 1);
	ACDBCORE2D_PORT ~AcDbHostApplicationServices();

	ACDBCORE2D_PORT virtual bool _entToWorldTransform(double normal[3], flagmat* tran);
	ACDBCORE2D_PORT void* acadInternalGetvar(const ACHAR* name);
	ACDBCORE2D_PORT virtual AcadInternalServices* acadInternalServices();
	AcadInternalServices* acadInternalServices2() { return this->acadInternalServices(); }
	ACDBCORE2D_PORT virtual void alert(const ACHAR* string) const;
	ACDBCORE2D_PORT virtual void auditPrintReport(AcDbAuditInfo* pAuditInfo, const ACHAR* line,
												  int both) const;
	ACDBCORE2D_PORT virtual bool cacheSymbolIndices() const;
	ACDBCORE2D_PORT virtual const ACHAR* companyName();
	ACDBCORE2D_PORT virtual AcDbGlobals* createWorkingGlobals();
	ACDBCORE2D_PORT virtual AcDbUndoController* defaultUndoController();
	ACDBCORE2D_PORT virtual void displayChar(ACHAR c) const;
	ACDBCORE2D_PORT virtual void displayString(const ACHAR* string, int count) const;
	ACDBCORE2D_PORT virtual bool doFullCRCCheck();
	ACDBCORE2D_PORT virtual void drawOleOwnerDrawItem(COleClientItem* pItem,
													  IcArx::Integers::LongPtr hdc, int32_t left,
													  int32_t top, int32_t right, int32_t bottom);
	ACDBCORE2D_PORT virtual void enableMessageDisplay(bool);
	ACDBCORE2D_PORT virtual void fatalError(const ACHAR* format, ...);
	ACDBCORE2D_PORT Acad::ErrorStatus findFile(AcString& fileOut, const ACHAR* pcFilename,
											   AcDbDatabase* pDb = nullptr,
											   FindFileHint hint = kDefault);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getAllUsersRootFolder(const ACHAR*& folder);
	ACDBCORE2D_PORT virtual const ACHAR* getAlternateFontName() const;
	ACDBCORE2D_PORT virtual const ACHAR* getColorBookLocation() const;
	ACDBCORE2D_PORT virtual void getDefaultPlotCfgInfo(AcString& devName, AcString& styleName);
	ACDBCORE2D_PORT virtual const ACHAR* getEnv(const ACHAR* var);
	ACDBCORE2D_PORT virtual const ACHAR* getFontMapFileName() const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getGraphicsCacheFolder(const ACHAR*& folder);
	ACDBCORE2D_PORT virtual short getKeyState(int nVirtKey) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getLocalRootFolder(const ACHAR*& folder);
	ACDBCORE2D_PORT virtual const ACHAR* getMachineRegistryProductRootKey();
	ACDBCORE2D_PORT virtual ModelerFlavor getModelerFlavor() const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getNewOleClientItem(COleClientItem*& pItem);
	ACDBCORE2D_PORT virtual bool getPassword(const ACHAR* dwgName, PasswordOptions options,
											 wchar_t* password, const size_t bufSize);
	bool getPassword(const ACHAR* dwgName, PasswordOptions options, AcString& password);
	ACDBCORE2D_PORT AcPwdCache* getPasswordCache() const { return mpPasswordCache; }
	ACDBCORE2D_PORT virtual AcLocale getProductLocale();
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getRegisteredFileMapClients(
			AcArray<const ACHAR*>& clients);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getRegisteredSelectFileClients(
			AcArray<const ACHAR*>& clients);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getRemoteFile(const ACHAR* pszURL,
															ACHAR* pszLocalFile,
															size_t nLocalFileLen,
															bool bIgnoreCache) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getRemoteFile(const ACHAR* pszURL, AcString& strLocalFile,
													bool bIgnoreCache = false) const;
	template<size_t N>
	Acad::ErrorStatus getRemoteFile(const ACHAR* pszURL, ACHAR (&pszLocalFile)[N]) const
	{
		return this->getRemoteFile(pszURL, pszLocalFile, N, /*bIgnoreCache*/ false);
	}
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getRoamableRootFolder(const ACHAR*& folder);
	ACDBCORE2D_PORT virtual bool getSubstituteFont(ACHAR** pFileName, const ACHAR* prompt, int type,
												   int fontAlt);
	virtual bool getSubstituteFont(ACHAR** pFileName, ACHAR* prompt, int type, int fontAlt) final
	{
		const ACHAR* pConstPrompt = prompt;
		return this->getSubstituteFont(pFileName, pConstPrompt, type, fontAlt);
	}
	ACDBCORE2D_PORT code_page_id getSystemCodePage() const { return this->m_eSystemCodePage; }
	ACDBCORE2D_PORT virtual unsigned int getTempPath(uint32_t lBufferSize, ACHAR* pcBuffer);
	ACDBCORE2D_PORT AcString getTempPath();
	ACDBCORE2D_PORT virtual const ACHAR* getUserRegistryProductRootKey();
	ACDBCORE2D_PORT virtual bool isRemoteFile(const ACHAR* pszLocalFile, ACHAR* pszURL,
											  size_t nUrlLen) const;
	ACDBCORE2D_PORT bool isRemoteFile(const ACHAR* pszLocalFile, AcString& strUrl);
	template<size_t N>
	bool isRemoteFile(const ACHAR* pszLocalFile, ACHAR (&pszURL)[N]) const
	{
		return isRemoteFile(pszLocalFile, pszURL, N);
	}
	ACDBCORE2D_PORT virtual bool isURL(const ACHAR* pszURL) const;
	ACDBCORE2D_PORT virtual bool launchBrowserDialog(ACHAR* pszSelectedURL, size_t selectedUrlLen,
													 const ACHAR* pszDialogTitle,
													 const ACHAR* pszOpenButtonCaption,
													 const ACHAR* pszStartURL,
													 const ACHAR* pszRegistryRootKey = 0,
													 bool bOpenButtonAlwaysEnabled = false) const;
	template<size_t N>
	bool launchBrowserDialog(ACHAR (&pszSelectedURL)[N], const ACHAR* pszDialogTitle,
							 const ACHAR* pszOpenButtonCaption, const ACHAR* pszStartURL,
							 const ACHAR* pszRegistryRootKey = 0,
							 bool bOpenButtonAlwaysEnabled = false) const
	{
		return launchBrowserDialog(pszSelectedURL, N, pszDialogTitle, pszOpenButtonCaption,
								   pszStartURL, pszRegistryRootKey, bOpenButtonAlwaysEnabled);
	}
	ACDBCORE2D_PORT virtual AcDbLayoutManager* layoutManager() const;
	ACDBCORE2D_PORT virtual bool loadApp(const ACHAR* appName, AcadApp::LoadReasons why,
										 bool printit, bool asCmd);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus mapFile(/*out*/ ACHAR*& newName,
													  const ACHAR* filename, int context,
													  void* pReserved);
	ACDBCORE2D_PORT virtual void missingCryptoProviderMsg();
	ACDBCORE2D_PORT virtual ClipBoundaryArray* newClipBoundaryArray();
	ACDBCORE2D_PORT virtual AcDbAbstractClipBoundaryDefinition* newClipBoundaryPolygonal();
	ACDBCORE2D_PORT virtual AcDbAbstractClipBoundaryDefinition* newClipBoundaryRectangular();
	ACDBCORE2D_PORT virtual AcDbHostApplicationProgressMeter* newProgressMeter();
	ACDBCORE2D_PORT virtual bool notifyCorruptDrawingFoundOnOpen(AcDbObjectId id,
																 Acad::ErrorStatus es);
	ACDBCORE2D_PORT virtual AcDbPlotSettingsValidator* plotSettingsValidator() const;
	ACDBCORE2D_PORT virtual const ACHAR* primaryClientForMapFileCallback();
	ACDBCORE2D_PORT virtual const ACHAR* primaryClientForSelectFileCallback();
	ACDBCORE2D_PORT virtual const ProdIdCode prodcode();
	ACDBCORE2D_PORT virtual const ACHAR* product();
	ACDBCORE2D_PORT virtual const ACHAR* program();
	ACDBCORE2D_PORT virtual Acad::ErrorStatus putRemoteFile(const ACHAR* pszURL,
															const ACHAR* pszLocalFile) const;
	ACDBCORE2D_PORT virtual bool readyToDisplayMessages();
	ACDBCORE2D_PORT virtual Acad::ErrorStatus registerMapFileCallback(const ACHAR* appName,
																	  REMAPPROC proc,
																	  bool unRegister = false,
																	  bool asPrimary = false);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus registerMapFileNotification(const ACHAR* appName,
																		  MAPFILENOTIFYPROC,
																		  bool unRegister = false);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus registerSelectFileCallback(const ACHAR* appName,
																		 SELECTFILEPROC proc,
																		 bool unRegister = false,
																		 bool asPrimary = false);
	ACDBCORE2D_PORT virtual const ACHAR* releaseMajorMinorString();
	ACDBCORE2D_PORT virtual int releaseMajorVersion();
	ACDBCORE2D_PORT virtual const ACHAR* releaseMarketVersion();
	ACDBCORE2D_PORT virtual int releaseMinorVersion();
	ACDBCORE2D_PORT virtual void reportUnhandledArxException(const ACHAR* pExceptionDescription,
															 const ACHAR* pAppName);
	ACDBCORE2D_PORT virtual bool requiredVersionNotAvailable(RequiredVersionFlags flags,
															 AcDbDatabase* pDb) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus selectFile(short* userCancel, ACHAR*& chosenPath,
														 void* h,  // HWND
														 const int nFlags, const ACHAR* prompt,
														 const ACHAR* dir, const ACHAR* name,
														 const ACHAR* type, int* pnChoice,
														 bool* pbReadOnly, const ACHAR* pszWSTags,
														 AcStringArray* pReserved);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus serializeOleItem(COleClientItem* pItem, CArchive*);
	ACDBCORE2D_PORT void setDefaultUndoController(AcDbUndoController* pUndoCtrl);
	ACDBCORE2D_PORT virtual bool setMapFlag(bool setIt);
	ACDBCORE2D_PORT void setWorkingAppSysvars(AcDbAppSystemVariables* pSysvars)
	{
		mpWorkingAppSysvars = pSysvars;
	}
	ACDBCORE2D_PORT void setWorkingDatabase(AcDbDatabase* pDatabase);
	ACDBCORE2D_PORT void setWorkingGlobals(AcDbGlobals* pGlobals);
	ACDBCORE2D_PORT void setWorkingProgressMeter(AcDbHostApplicationProgressMeter* pNewMeter);
	void setWorkingTransactionManager(AcDbTransactionManager* pTM);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus signingComplete(Acad::ErrorStatus es,
															  const ACHAR* msg, bool* result);
	ACDBCORE2D_PORT virtual bool supportsMultiRedo() const;
	ACDBCORE2D_PORT virtual void terminateScript();
	ACDBCORE2D_PORT virtual void usedPasswordFromCacheMsg(const ACHAR* dwgName);
	ACDBCORE2D_PORT virtual bool userBreak(bool updCtrlsWhenEnteringIdle = true) const;
	ACDBCORE2D_PORT virtual const ACHAR* versionString();
	ACDBCORE2D_PORT AcDbAppSystemVariables* workingAppSysvars() const
	{
		return mpWorkingAppSysvars;
	}
	AcDbDatabase* workingDatabase() const;
	ACDBCORE2D_PORT AcDbGlobals* workingGlobals() const
	{
		return mpWorkingGlobals ? mpWorkingGlobals : getDefaultGlobals();
	}
	virtual AcDbTransactionManager* workingTransactionManager();
};

#include "IcArxPackPop.h"

ACDBCORE2D_PORT AcDbHostApplicationServices* acdbHostApplicationServices();
ACDBCORE2D_PORT Acad::ErrorStatus acdbSendInitialDwgFileOpenComplete(AcDbDatabase* pDb);
Acad::ErrorStatus acdbSetBreak3dQueueForRegen(bool);
ACDBCORE2D_PORT Acad::ErrorStatus acdbSetHostApplicationServices(
		AcDbHostApplicationServices* pServices);
void acdbTriggerAcadOctTreeReclassification();

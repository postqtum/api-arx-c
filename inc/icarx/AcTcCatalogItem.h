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
***     Description: Declaration of AcTcCatalogItem class
***
*****************************************************************************/
#pragma once

#include "AcTcBase.h"

class AcTcScheme;
class AcTcSystemInternals;
class AcTcCatalogItemReactor;

#include "IcArxPackPush.h"

class ACTC_PORT AcTcCatalogItem
{
	friend class AcTcImpCatalogItem;

public:
	static AcTcCatalogItem* FromFile(LPCTSTR pszFile, BOOL bLoad = FALSE,
									 DWORD dwLoadOption = AcTc::kLoadLinks);
	static AcTc::CatalogItemType GetType(LPCTSTR pszFile);

public:
	virtual ~AcTcCatalogItem();

	BOOL Load(LPCTSTR pszUrl, DWORD dwLoadOption = AcTc::kLoadLinks);
	BOOL LoadLink(void);
	BOOL Save(LPCTSTR pszUrl, DWORD dwSaveOption = AcTc::kSaveLinksAsLinks);
	INT_PTR AddChild(AcTcCatalogItem* pNewItem);
	INT_PTR InsertChild(INT_PTR iIndex, AcTcCatalogItem* pNewItem);
	BOOL DeleteChild(AcTcCatalogItem* pItem);
	BOOL DetachChild(AcTcCatalogItem* pItem);
	INT_PTR GetChildCount(void) const;
	INT_PTR GetChildCount(AcTc::CatalogItemType nType) const;
	AcTcCatalogItem* GetChild(INT_PTR iIndex) const;
	AcTcCatalogItem* GetNextChild(int iIndex, AcTc::CatalogItemType nType) const;
	BOOL DeleteAllChildren(void);
	BOOL HasChildren(void) const;

	BOOL GetID(GUID* pId) const;
	BOOL SetID(const GUID* pId);
	AcTc::AccessRight GetAccessRight(void) const;
	BOOL SetAccessRight(AcTc::AccessRight nAccessRight);
	BOOL IsReadOnly(void) const;
	int GetName(LPTSTR pszString, int cchSize) const;
	BOOL SetName(LPCTSTR pszString);
	int GetDescription(LPTSTR pszString, int cchSize) const;
	BOOL SetDescription(LPCTSTR pszString);
	int GetToolTipText(LPTSTR pszString, int cchSize) const;
	BOOL SetToolTipText(LPCTSTR pszString);
	INT_PTR GetImageFilePath(INT_PTR iIndex, LPTSTR pszString, size_t cchSize) const;
	BOOL GetHelpInfo(LPTSTR pszFile, LPTSTR pszCommand, LPTSTR pszData) const;
	BOOL SetHelpInfo(LPCTSTR pszFile, LPCTSTR pszCommand, LPCTSTR pszData);
	int GetKeywords(LPTSTR pszString, int cchSize) const;
	BOOL SetKeywords(LPCTSTR pszString);
	int GetLinkUrl(LPTSTR pszString, int cchSize) const;
	BOOL SetLinkUrl(LPCTSTR pszString);
	int GetSourceUrl(LPTSTR pszString, int cchSize) const;
	BOOL SetSourceUrl(LPCTSTR pszString);
	int GetParentDocumentName(LPTSTR pszString, int cchSize) const;
	BOOL SetParentDocumentName(LPCTSTR pszString);
	int GetParentDocumentDescription(LPTSTR pszString, int cchSize) const;
	BOOL SetParentDocumentDescription(LPCTSTR pszString);
	int GetParentDocumentUrl(LPTSTR pszString, int cchSize) const;
	BOOL SetParentDocumentUrl(LPCTSTR pszString);
	int GetPublisherName(LPTSTR pszString, int cchSize) const;
	BOOL SetPublisherName(LPCTSTR pszString);
	int GetPublisherDescription(LPTSTR pszString, int cchSize) const;
	BOOL SetPublisherDescription(LPCTSTR pszString);
	int GetPublisherCountry(LPTSTR pszString, int cchSize) const;
	BOOL SetPublisherCountry(LPCTSTR pszString);
	int GetPublisherEmail(LPTSTR pszString, int cchSize) const;
	BOOL SetPublisherEmail(LPCTSTR pszString);
	int GetPublisherUrl(LPTSTR pszString, int cchSize) const;
	BOOL SetPublisherUrl(LPCTSTR pszString);
	int GetUrl(LPTSTR pszString, int cchSize) const;
	int GetLocalFile(LPTSTR pszString, int cchSize) const;
	AcTcCatalogItem* GetRoot(void) const;
	AcTcScheme* GetScheme(void) const;
	AcTcCatalogItem* GetParent(void) const;
	BOOL SetParent(AcTcCatalogItem* pParent);
	BOOL IsRoot(void) const;
	BOOL IsLink(void) const;
	BOOL IsLinkLoaded(void) const;
	AcTcImageList* GetImageList(void) const;
	AcTcImage* GetImage(const SIZE* pSize, BOOL bUseDarkTheme = FALSE);
	int GetXml(LPTSTR pszString, int cchSize, DWORD dwSaveOption = AcTc::kSaveLinksAsLinks);
	virtual AcTcCatalogItem* FindInChildren(const GUID& id, BOOL bRecursive = TRUE);
	AcTcCatalogItem* FindInChildren(LPCTSTR pszName);
	AcTcCatalogItem* FindInChildren(LPCTSTR pszName, BOOL bRecursive);
	BOOL GetTime(time_t* pCreated, time_t* pLastModified, time_t* pLastRefreshed) const;
	BOOL SetTime(const time_t* pCreated, const time_t* pLastModified, const time_t* pLastRefreshed);
	BOOL CanRefresh(void) const;
	BOOL SetRefresh(BOOL bRefresh);
	BOOL GetRefresh(void) const;
	virtual BOOL Refresh(DWORD dwRefreshFlag = AcTc::kRefreshAll);
	virtual BOOL Download(LPCTSTR pszUrl, DWORD dwDownloadFlag = AcTc::kDownloadAll,
						  LPCTSTR pszDownloadPath = nullptr);
	BOOL SetAutoRefresh(BOOL bAutoRefresh);
	BOOL GetAutoRefresh(void) const;
	int GetReferencePath(LPTSTR pszString, int cchSize, int nFlag) const;
	BOOL SetReferencePath(LPCTSTR pszString, int nFlag);
	BOOL GetCustomData(IUnknown** ppCustomData);
	BOOL SetNewID(BOOL bRecursive = FALSE);
	BOOL DeleteImageFile(BOOL bRecursive = FALSE);
	int GetLinkFilePath(LPTSTR pszString, int cchSize) const;
	BOOL DeleteLinkFile(BOOL bRecursive = FALSE);
	BOOL GetSourceID(GUID* pId) const;
	BOOL SetSourceID(const GUID* pId);
	AcTcImage* GetOverlayImage(BOOL bUseDarkTheme = FALSE) const;
	BOOL SetOverlayImage(const AcTcImage* pImage, BOOL bUseDarkTheme = FALSE);
	BOOL GetOverlayImageInfo(ACTC_IMAGE_INFO* pImageInfo, BOOL bUseDarkTheme = FALSE) const;
	BOOL SetOverlayImageInfo(const ACTC_IMAGE_INFO* pImageInfo);
	INT_PTR GetOverlayImageFilePath(LPTSTR pszString, size_t cchSize,
									BOOL bUseDarkTheme = FALSE) const;
	BOOL DeleteOverlayImageFile(BOOL bRecursive = FALSE);
	INT_PTR GetTargetProductCount(void) const;
	BOOL GetTargetProduct(INT_PTR iIndex, ACTC_TARGET_PRODUCT_INFO* pProductInfo) const;
	INT_PTR AddTargetProduct(const ACTC_TARGET_PRODUCT_INFO* pProductInfo);
	BOOL DeleteTargetProduct(int iIndex);
	BOOL IsValidForProduct(LPCTSTR pszProductName, int nMajorVersion, int nMinorVersion,
						   DWORD dwLocaleId = 0);
	BOOL AddReactor(AcTcCatalogItemReactor* pReactor);
	BOOL RemoveReactor(AcTcCatalogItemReactor* pReactor);
	BOOL Sort(int nSortOption, BOOL bRecursive);
	BOOL SetItemOrder(AcTcCatalogItem** pItems, INT_PTR nNumItems);
	AcTc::ItemOption GetOption(void) const;
	BOOL SetOption(AcTc::ItemOption nOption);
	BOOL GetFileRevision(long& lMajorVersion, long& lMinorVersion) const;
	BOOL GetRevision(long& lMajorVersion, long& lMinorVersion, long& lUserVersion) const;
	BOOL IsUserModified(void) const;

public:
	virtual AcTcCatalogItem& operator=(const AcTcCatalogItem& srcItem);
	virtual BOOL Reset(void);

	virtual AcTc::CatalogItemType GetType(void) const;
	virtual int GetTypeString(LPTSTR pszString, int cchSize, BOOL bLocalized = FALSE,
							  BOOL bPluralForm = FALSE) const;
	virtual int GetTagName(LPTSTR pszString, int cchSize) const;

	virtual BOOL Load(IUnknown* pUnknown, DWORD dwLoadOption = AcTc::kLoadLinks);
	virtual BOOL Load(IStream* pStream, DWORD dwLoadOption = AcTc::kLoadLinks);
	virtual BOOL Save(IUnknown* pUnknown, DWORD dwSaveOption = AcTc::kSaveLinksAsLinks);
	virtual BOOL Save(IStream* pStream, DWORD dwSaveOption = AcTc::kSaveLinksAsLinks);
	virtual BOOL Clone(BOOL bDeep, AcTcCatalogItem*& pClone, BOOL bCopyId = FALSE) const;
	virtual BOOL CopyFrom(const AcTcCatalogItem* pSrcItem, BOOL bCopyId = FALSE);
	virtual BOOL IsValidChild(const AcTc::CatalogItemType nType) const;

protected:
	virtual AcTcCatalogItem* CreateObject(void) const;

protected:
	AcTcCatalogItem(AcTcSystemInternals*);

protected:
	void* mpImpObj;

private:
	friend class AcTcSystemInternals;
};

#include "IcArxPackPop.h"

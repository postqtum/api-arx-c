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
***     Description: Declaration of AcApDocManager class
***
*****************************************************************************/
#pragma once

#include "AcApDocument.h"

class IAcApDocManagerHost;
class AcApDocumentIterator;
class AcApDocManagerReactor;

#include "IcArxPackPush.h"

class ACCORE_PORT ADESK_NO_VTABLE AcApDocManager : public AcRxObject
{
public:
	struct DocOpenParams
	{
		enum InitialViewType : unsigned char
		{
			kUnknown = 0,
			kDefaultView = 1,
			kLayoutName = 2,
			kViewName = 3,
			kLayoutHandle = 4,
			kViewHandle = 5,
			kViewWorldCoords = 6
		};

		enum
		{
			kDisallowReadOnly = 0x01,
			kRequireReadOnly = 0x02,
			kFileNameArgIsUnicode = 0x04,
			kViewNameArgIsUnicode = 0x08,
			kUseUIOnErrors = 0x10,
			kOwnerControlled = 0x20,
			kUseUI = 0x40
		};

		union
		{
			const ACHAR* mpszFileName;
			const wchar_t* mpwszFileName;
		};
		union
		{
			const ACHAR* mpszViewName;
			const wchar_t* mpwszViewName;
			const double* mpCoords;
		};
		InitialViewType mnInitialViewType;
		int mnFlags;
		const wchar_t* mpwszPassword;
		void* mpOwnerData;
		void* mpUnused;
		int mnUnused;
		const wchar_t* mpwszTitle;
	};

public:
	ACRX_DECLARE_MEMBERS(AcApDocManager);

public:
	virtual Acad::ErrorStatus activateDocument(AcApDocument* pAcTargetDocument,
											   bool bPassScript = false) = 0;
	virtual void addReactor(AcApDocManagerReactor*) = 0;
	Acad::ErrorStatus appContextCloseDocument(AcApDocument* pDoc);
	virtual Acad::ErrorStatus appContextNewDocument(const ACHAR* pszTemplateName) = 0;
	virtual Acad::ErrorStatus appContextOpenDocument(
			const AcApDocManager::DocOpenParams* pParams) = 0;
	virtual Acad::ErrorStatus appContextOpenDocument(const ACHAR* pszDrawingName) = 0;
	Acad::ErrorStatus appContextPromptNewDocument();
	Acad::ErrorStatus appContextPromptOpenDocument();
	virtual Acad::ErrorStatus appContextRecoverDocument(const ACHAR* pszDrawingName) = 0;
	Acad::ErrorStatus beginExecuteInApplicationContext(void (*procAddr)(void*), void* pData);
	Acad::ErrorStatus beginExecuteInCommandContext(void (*procAddr)(void*), void* pData);
	virtual Acad::ErrorStatus closeDocument(AcApDocument* pAcTargetDocument) = 0;
	virtual AcApDocument* curDocument() const = 0;
	virtual AcApDocument::SaveFormat defaultFormatForSave() const = 0;
	virtual Acad::ErrorStatus disableDocumentActivation() = 0;
	virtual AcApDocument* document(const AcDbDatabase*) const = 0;
	virtual int documentCount() const = 0;
	virtual Acad::ErrorStatus enableDocumentActivation() = 0;
	virtual void executeInApplicationContext(void (*procAddr)(void*), void* pData) const = 0;
	virtual int inputPending(AcApDocument* pAcTargetDocument) = 0;
	virtual bool isApplicationContext() const = 0;
	virtual bool isDocumentActivationEnabled() = 0;
	virtual Acad::ErrorStatus lockDocument(AcApDocument* pDoc, AcAp::DocLockMode = AcAp::kWrite,
										   const ACHAR* pGlobalCmdName = nullptr,
										   const ACHAR* pLocalCmdName = nullptr,
										   bool prompt = true) = 0;
	virtual AcApDocument* mdiActiveDocument() const = 0;
	virtual AcApDocumentIterator* newAcApDocumentIterator() = 0;
	virtual Acad::ErrorStatus newDocument() = 0;
	virtual Acad::ErrorStatus openDocument() = 0;
	virtual void popResourceHandle() = 0;
	virtual void pushAcadResourceHandle() = 0;
	virtual void removeReactor(AcApDocManagerReactor*) = 0;
	virtual Acad::ErrorStatus sendModelessInterrupt(AcApDocument* pAcTargetDocument) = 0;
	virtual Acad::ErrorStatus sendStringToExecute(AcApDocument* pAcTargetDocument,
												  const ACHAR* pszExecute, bool bActivate = true,
												  bool bWrapUpInactiveDoc = false,
												  bool bEchoString = true) = 0;
	virtual Acad::ErrorStatus setCurDocument(AcApDocument* pDoc, AcAp::DocLockMode = AcAp::kNone,
											 bool activate = false) = 0;
	virtual Acad::ErrorStatus setDefaultFormatForSave(AcApDocument::SaveFormat format) = 0;
	void setHost(IAcApDocManagerHost* pHost);
	virtual Acad::ErrorStatus unlockDocument(AcApDocument* pDoc) = 0;
};

#include "IcArxPackPop.h"

ACCORE_PORT AcApDocManager* acDocManagerPtr();
#define AC_DOCUMENT_MANAGER_OBJ ACRX_T("AcApDocManager")

#define acDocManager acDocManagerPtr()

inline AcApDocument* curDoc()
{
	return ::acDocManagerPtr()->curDocument();
}

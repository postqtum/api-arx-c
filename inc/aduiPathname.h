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
***     Description:
***
*****************************************************************************/
#pragma once

#include "adesk.h"
#include "acbasedefs.h"
#include "aduipathenums.h"
#include "AcString.h"

class CAdUiVolumeDescriptor;

AcString GetDriveForRoottypePath(const CAdUiVolumeDescriptor* const);

namespace Autodesk
{
namespace AutoCAD
{
namespace PAL
{
namespace FileIO
{
class File;
}
}  // namespace PAL
}  // namespace AutoCAD
}  // namespace Autodesk

extern __declspec(selectany) const ACHAR kBackslash = ACRX_T('\\');
extern __declspec(selectany) const ACHAR kColon = ACRX_T(':');
extern __declspec(selectany) const ACHAR kDoubleQuote = ACRX_T('"');
extern __declspec(selectany) const ACHAR kEOS = ACRX_T('\0');
extern __declspec(selectany) const ACHAR kPeriod = ACRX_T('.');
extern __declspec(selectany) const ACHAR kSlash = ACRX_T('/');
extern __declspec(selectany) const ACHAR kSpace = ACRX_T(' ');
extern __declspec(selectany) const ACHAR kAsterisk = ACRX_T('*');
extern __declspec(selectany) const ACHAR kQuestionmark = ACRX_T('?');
extern __declspec(selectany) const ACHAR kZero = ACRX_T('0');

#include "icarx/IcArxPackPush.h"

class ACBASE_PORT CAdUiPathname
{
	friend CAdUiVolumeDescriptor* NewVolDescriptorHelper(const CAdUiPathname* pPathName,
														 const AcString& vol_name);
	friend bool IsPathValid(CAdUiPathname* pPathName, const CAdUiPathname* rel_path,
							const AcString* work);
	friend void HandleSpecialPath(CAdUiPathname* pPathName, const CAdUiPathname* rel_path,
								  AcString* work, int index, bool wildcard_ok);
	friend void SetupVolForRoottypePath(CAdUiPathname* pPathName, const CAdUiPathname* pRelPath,
										const wchar_t* pPathStr);
	friend AcString GetDriveForRoottypePath(const CAdUiVolumeDescriptor*);

public:
	template<size_t nBufLen>
	inline bool GetFullPath(wchar_t (&buf)[nBufLen]) const
	{
		return this->GetFullPath(buf, nBufLen);
	}

protected:
	path_type m_this_type = NO_PATH;
	const CAdUiVolumeDescriptor* m_pvolume = nullptr;
	AcString* m_pathbuffer = nullptr;
	AcString* m_relpath = nullptr;
	path_category m_path_cat = DRIVE_TYPE;
	bool m_had_prefix = false;

protected:
	virtual void AssignCopy(const CAdUiPathname&);
	const CAdUiVolumeDescriptor* FindVolumeDescriptor(const AcString& vol_name) const;
	static FS_TYPE GetFileSystem(AcString& vol_name);
	static ACHAR GetLastCharacter(const AcString& s)
	{
		const int kLen = s.length();
		return (kLen == 0) ? L'\x00' : s[kLen - 1];
	}
	static ACHAR GetSeparator();
	static bool IsDeviceName(const wchar_t*);
	const CAdUiVolumeDescriptor* NewVolDescriptor(const AcString& vol_name) const;
	static bool Unquote(AcString&);

public:
	CAdUiPathname();
	CAdUiPathname(const CAdUiPathname& other) { AssignCopy(other); }
	virtual ~CAdUiPathname() noexcept;
	const CAdUiPathname& operator=(const CAdUiPathname& pathSrc)
	{
		AssignCopy(pathSrc);
		return *this;
	}
	const CAdUiPathname& operator=(const CAdUiPathname* pathSrc)
	{
		AssignCopy(*pathSrc);
		return *this;
	}

	PathErr AddExtensionAlways(const wchar_t*);
	PathErr AddExtensionIfNoMatch(const wchar_t*);
	PathErr Append(const wchar_t*);
	PathErr AppendComponent(const wchar_t*);
	PathErr AppendSlash();
	void BaseToLower();
	void BaseToUpper();
	void Empty();
	bool Exists();
	void GetBasename(AcString&) const;
	void GetDisplayName(AcString& strResult, int maxchars) const;
	void GetExtension(AcString&) const;
	void GetFilename(AcString&) const;
	bool GetFullPath(wchar_t* pBuf, size_t strBuffLen) const;
	bool GetFullPath(AcString&) const;
	void GetFullUNCPath(AcString&) const;
	void GetParent(CAdUiPathname&) const;
	const wchar_t* GetPathString() const;
	path_type GetPathType() const { return m_this_type; }
	bool GetUniqueName(CAdUiPathname&, bool alwaysMangle = false) const;
	const CAdUiVolumeDescriptor* GetVolumeDescriptor() const { return m_pvolume; }
	bool HadPrefix() const { return m_had_prefix; }
	bool IsEmpty() const { return (m_this_type == NO_PATH); }
	bool IsPath() const
	{
		return ((m_this_type == FILE_PATH) || (m_this_type == DIR_PATH) ||
				(m_this_type == NEW_PATH) || (m_this_type == WC_PATH));
	}
	bool OpenReadOnly(Autodesk::AutoCAD::PAL::FileIO::File&);
	bool OpenWriteOnly(Autodesk::AutoCAD::PAL::FileIO::File&);
	virtual PathErr Parse(const wchar_t*, bool wildcard_ok = false);
	bool ParseAndOSFind(const wchar_t*);
	PathErr ParseRelative(const wchar_t* name, const CAdUiPathname* relpath,
						  bool wildcard_ok = false);
	bool PathMatch(const CAdUiPathname*) const;
	bool PathMatch(const wchar_t*) const;
	bool Remove();
	void RemoveExtensionAlways();
	void RemoveExtensionIfMatch(const wchar_t*);
	void RemoveSpaces();
	bool Rename(const ACHAR* newname);
	PathErr ReplaceExtensionAlways(const wchar_t*);
	PathErr ReplaceExtensionIfNoMatch(const wchar_t*);
	path_status Status();
	PathErr Trim();
	PathErr TrimComponent();
	PathErr TrimSlash();
	bool VerifyExtension(const wchar_t* extlist) const;
	bool WasAbsolute() const;
	bool WasRoot() const { return (m_path_cat == ROOT_TYPE); }
};

#include "icarx/IcArxPackPop.h"

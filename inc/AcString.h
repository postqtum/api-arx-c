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
***     Description: Declaration of AcString class
***
*****************************************************************************/
#pragma once

#include "icarx/IcArxPackPush.h"

#include <cstdarg>

#include "acbasedefs.h"
#include "adesk.h"
#include "AcHeapOpers.h"
#include "AdAChar.h"
#include "acarray.h"

class AcDbHandle;
class AcRxResourceInstance;

class OdAcString;
class OdString;

class ACBASE_PORT AcString
		: public AcHeapOperators
{
public:
	enum Encoding
	{
		Utf8
	};
	enum eFormat
	{
		kSigned = 2,
		kUnSigned = 3,
		kHex = 4
	};
	enum
	{
		kParseZero = 0,
		kParseMinus1 = 1,
		kParseAssert = 2,
		kParseExcept = 4,
		kParseNoEmpty = 8,
		kParseDefault = (kParseAssert | kParseZero)
	};

public:
#if defined(_AFX) || defined(__OSX_WINAPI_UNIX_STRING_H__) || defined(__ATLSTR_H__)
	AcString(const CStringW& csw);
	AcString& operator+=(const CStringW& csw);
	AcString& operator=(const CStringW& csw);
	bool operator!=(const CStringW&) const;
	bool operator<(const CStringW&) const;
	bool operator<=(const CStringW&) const;
	bool operator==(const CStringW&) const;
	bool operator>(const CStringW&) const;
	bool operator>=(const CStringW&) const;
	int compare(const CStringW& csw) const;
	int compareNoCase(const CStringW& csw) const;
	int match(const CStringW& csw) const;
	int matchNoCase(const CStringW& csw) const;
#endif
	AcDbHandle asAcDbHandle(int nFlags = kParseDefault) const;
	ACHAR* getBuffer(int nMinBufferLength = 0);
	AcString& append(const AcString& acs);
	AcString& append(const char* psz, AcString::Encoding encoding);
	AcString& append(const wchar_t* pwsz);
	AcString& append(wchar_t wch);
	AcString& appendFormat(const ACHAR* pszFmt, ...);
	AcString& assign(const AcDbHandle& h);
	AcString& assign(const AcString& acs);
	AcString& assign(const char* psz, AcString::Encoding encoding);
	AcString& assign(const wchar_t* pwsz);
	AcString& assign(wchar_t wch);
	AcString& format(const ACHAR* pszFmt, ...);
	AcString& formatV(const ACHAR* pszFmt, va_list args);
	AcString& insert(int nIndex, const wchar_t* pwsz);
	AcString& insert(int nIndex, wchar_t ch);
	AcString& makeLower();
	AcString& makeReverse();
	AcString& makeUpper();
	AcString& operator+=(const AcString& acs);
	AcString& operator+=(const wchar_t* pwsz);
	AcString& operator+=(wchar_t wch);
	AcString& operator=(AcString&& acs);
	AcString& operator=(const AcDbHandle& h);
	AcString& operator=(const AcString& acs);
	AcString& operator=(const wchar_t* pwsz);
	AcString& operator=(wchar_t wch);
	AcString& setAt(int nIndex, ACHAR ch);
	AcString& setEmpty();
	AcString& trim();
	AcString& trim(const wchar_t* pwszChars);
	AcString& trim(wchar_t wch);
	AcString& trimLeft();
	AcString& trimLeft(const wchar_t* pwszChars);
	AcString& trimLeft(wchar_t wch);
	AcString& trimRight();
	AcString& trimRight(const wchar_t* pwszChars);
	AcString& trimRight(wchar_t wch);
	AcString concat(const AcString& acs) const;
	AcString concat(const char* psz, AcString::Encoding encoding) const;
	AcString concat(const wchar_t* pwsz) const;
	AcString concat(wchar_t wch) const;
	AcString left(int nNumChars) const;
	AcString mid(int nStart) const;
	AcString mid(int nStart, int nNumChars) const;
	AcString operator+(const AcString& acs) const;
	AcString operator+(const wchar_t* pwsz) const;
	AcString operator+(wchar_t wch) const;
	AcString precat(ACHAR ch) const;
	AcString precat(const char* psz, AcString::Encoding encoding) const;
	AcString precat(const wchar_t* psz) const;
	AcString right(int nNumChars) const;
	AcString spanExcluding(const wchar_t* pwszChars) const;
	AcString spanIncluding(const wchar_t* pwszChars) const;
	AcString substr(int nStart, int nNumChars) const;
	AcString substr(int numChars) const;
	AcString substrRev(int numChars) const;
	AcString tokenize(const wchar_t* pszTokens, int& iStart) const;
	AcString();
	AcString(ACHAR ch, unsigned int nRepeatTimes);
	AcString(AcString&& acs);
	AcString(AcString::eFormat nCtorFlags, unsigned int nArg);
	AcString(const AcDbHandle& h);
	AcString(const AcRxResourceInstance& hDll, unsigned int nId);
	AcString(const AcString& acs);
	AcString(const char* psz, AcString::Encoding encoding);
	AcString(const char* psz, AcString::Encoding encoding, unsigned int nByteCount);
	AcString(const wchar_t* pwsz);
	AcString(const wchar_t* pwsz, unsigned int count);
	AcString(wchar_t wch);
	uint64_t asUDeci64(int nFlags = kParseDefault) const;
	uint64_t asUHex64(int nFlags = kParseDefault) const;
	bool is7Bit() const;
	bool isAscii() const;
	bool isEmpty() const;
	bool loadString(const AcRxResourceInstance& hDll, unsigned int nId);
	bool operator!=(const AcString& acs) const;
	bool operator!=(const wchar_t* pwsz) const;
	bool operator!=(wchar_t wch) const;
	bool operator<(const AcString& acs) const;
	bool operator<(const wchar_t* pwsz) const;
	bool operator<(wchar_t wch) const;
	bool operator<=(const AcString& acs) const;
	bool operator<=(const wchar_t* pwsz) const;
	bool operator<=(wchar_t wch) const;
	bool operator==(const AcString& acs) const;
	bool operator==(const wchar_t* pwsz) const;
	bool operator==(wchar_t wch) const;
	bool operator>(const AcString& acs) const;
	bool operator>(const wchar_t* pwsz) const;
	bool operator>(wchar_t wch) const;
	bool operator>=(const AcString& acs) const;
	bool operator>=(const wchar_t* pwsz) const;
	bool operator>=(wchar_t wch) const;
	bool releaseBuffer(int nNewLength = -1);
	bool reserve(unsigned int nCapacity);
	const ACHAR* kACharPtr() const;
	const char* utf8Ptr() const;
	const wchar_t* constPtr() const;
	const wchar_t* kTCharPtr() const;
	const wchar_t* kwszPtr() const;
	int asDeci(int nFlags = kParseDefault) const;
	int asHex(int nFlags = kParseDefault) const;
	int collate(const AcString& acs) const;
	int collate(const wchar_t* pwsz) const;
	int collateNoCase(const AcString& acs) const;
	int collateNoCase(const wchar_t* psz) const;
	int compare(const AcString& acs) const;
	int compare(const char* psz, AcString::Encoding encoding) const;
	int compare(const wchar_t* pwsz) const;
	int compare(wchar_t wch) const;
	int compareNoCase(const AcString& acs) const;
	int compareNoCase(const char* psz, AcString::Encoding encoding) const;
	int compareNoCase(const wchar_t* pwsz) const;
	int compareNoCase(wchar_t wch) const;
	int deleteAtIndex(int iIndex, int nCount = 1);
	int find(ACHAR ch) const;
	int find(ACHAR ch, int nStartPos) const;
	int find(const ACHAR* psz, int nStartPos = 0) const;
	int find(const AcString& acs) const;
	int findLast(ACHAR ch, int nEndPos = -1) const;
	int findLast(const ACHAR* psz, int nEndPos = -1) const;
	int findLastNoneOf(const ACHAR* psz, int nEndPos = -1) const;
	int findLastOneOf(const ACHAR* psz, int nEndPos = -1) const;
	int findNoneOf(const ACHAR* psz, int nStartPos = 0) const;
	int findOneOf(const ACHAR* psz, int nStartPos = 0) const;
	int findOneOfRev(const ACHAR* psz) const;
	int findRev(ACHAR ch) const;
	int findRev(const ACHAR* psz) const;
	int findRev(const AcString& acs) const;
	int match(const AcString& acs) const;
	int match(const char* psz, AcString::Encoding encoding) const;
	int match(const wchar_t* pwsz) const;
	int matchNoCase(const AcString& acs) const;
	int matchNoCase(const char* psz, AcString::Encoding encoding) const;
	int matchNoCase(const wchar_t* pwsz) const;
	int remove() { return this->remove(0); }
	int remove(wchar_t wch);
	int replace(const wchar_t* pwszOld, const wchar_t* pwszNew);
	int replace(wchar_t wchOld, wchar_t wchNew);
	int64_t asDeci64(int nFlags = kParseDefault) const;
	int64_t asHex64(int nFlags = kParseDefault) const;
	operator const wchar_t*() const;
	static bool equalsNoCase(const AcString& left, const AcString& right);
	unsigned int asUDeci(int nFlags = kParseDefault) const;
	unsigned int asUHex(int nFlags = kParseDefault) const;
	unsigned int capacity() const;
	unsigned int length() const;
	unsigned int tcharLength() const { return this->length(); }
	wchar_t getAt(int nIndex) const;
	~AcString();

private:
	OdAcString* m_pImp = nullptr;

	friend OdString* getImp(const AcString* acString);
};

typedef AcArray<AcString, AcArrayObjectCopyReallocator<AcString> > AcStringArray;

bool operator==(wchar_t wch, const AcString& acs);

bool operator==(const wchar_t* pwsz, const AcString& acs);

bool operator!=(wchar_t wch, const AcString& acs);

bool operator!=(const wchar_t* pwsz, const AcString& acs);

bool operator>(wchar_t wch, const AcString& acs);

bool operator>(const wchar_t* pwsz, const AcString& acs);

bool operator>=(wchar_t wch, const AcString& acs);

bool operator>=(const wchar_t* pwsz, const AcString& acs);

bool operator<(wchar_t wch, const AcString& acs);

bool operator<(const wchar_t* pwsz, const AcString& acs);

bool operator<=(wchar_t wch, const AcString& acs);

bool operator<=(const wchar_t* pwsz, const AcString& acs);

AcString operator+(wchar_t wch, const AcString& acs);

AcString operator+(const wchar_t* pwsz, const AcString& acs);


inline AcString::operator const wchar_t*() const
{
	return this->kwszPtr();
}

inline const wchar_t* AcString::constPtr() const
{
	return this->kwszPtr();
}

inline const wchar_t* AcString::kTCharPtr() const
{
	return this->kwszPtr();
}

inline const ACHAR* AcString::kACharPtr() const
{
	return this->kwszPtr();
}

inline int AcString::find(ACHAR ch) const
{
	const ACHAR str[2] = {ch, '\0'};
	return this->findOneOf(str);
}

inline int AcString::find(wchar_t wch, int nStartPos) const
{
	const wchar_t wsz[2] = {wch, 0};
	return this->findOneOf(wsz, nStartPos);
}

inline int AcString::find(const AcString& s) const
{
	return this->find(s.kwszPtr());
}

inline int AcString::findRev(ACHAR ch) const
{
	return this->findLast(ch);
}

inline int AcString::findRev(const wchar_t* pwsz) const
{
	return this->findLast(pwsz, -1);
}

inline int AcString::findRev(const AcString& s) const
{
	return this->findLast(s.kwszPtr());
}

inline int AcString::findOneOfRev(const wchar_t* pwsz) const
{
	return this->findLastOneOf(pwsz, -1);
}

inline int AcString::findLast(ACHAR ch, int nStartPos) const
{
	const ACHAR str[2] = {ch, '\0'};
	return this->findLastOneOf(str, nStartPos);
}

inline AcString AcString::mid(int nStart, int nNumChars) const
{
	return this->substr(nStart, nNumChars);
}

inline AcString AcString::mid(int nStart) const
{
	return this->mid(nStart, -1);
}

inline AcString AcString::substr(int nNumChars) const
{
	return this->substr(0, nNumChars);
}

inline AcString AcString::left(int nNumChars) const
{
	return this->substr(nNumChars);
}

inline AcString AcString::right(int nNumChars) const
{
	return this->substrRev(nNumChars);
}

inline AcString& AcString::trimLeft(wchar_t wch)
{
	const wchar_t wszChars[] = {wch, L'\0'};
	return this->trimLeft(wszChars);
}

inline AcString& AcString::trimLeft()
{
	return this->trimLeft(nullptr);
}

inline AcString& AcString::trimRight(wchar_t wch)
{
	const wchar_t wszChars[] = {wch, L'\0'};
	return this->trimRight(wszChars);
}

inline AcString& AcString::trimRight()
{
	return this->trimRight(nullptr);
}

inline AcString& AcString::trim(wchar_t wch)
{
	const wchar_t wszChars[] = {wch, L'\0'};
	return this->trim(wszChars);
}

inline AcString& AcString::trim()
{
	return this->trim(nullptr);
}

inline AcString& AcString::trim(const wchar_t* pwszChars)
{
	return this->trimRight(pwszChars).trimLeft(pwszChars);
}


inline AcString& AcString::assign(wchar_t wch)
{
	const wchar_t wstr[2] = {wch, L'\0'};
	return this->assign(wstr);
}


inline AcString& AcString::operator=(wchar_t wch)
{
	return this->assign(wch);
}

inline AcString& AcString::operator=(const wchar_t* pwsz)
{
	return this->assign(pwsz);
}

inline AcString& AcString::operator=(const AcString& acs)
{
	return this->assign(acs);
}

inline AcString& AcString::operator=(const AcDbHandle& h)
{
	return this->assign(h);
}

inline AcString& AcString::operator+=(wchar_t wch)
{
	return this->append(wch);
}

inline AcString& AcString::operator+=(const wchar_t* pwsz)
{
	return this->append(pwsz);
}

inline AcString& AcString::operator+=(const AcString& acs)
{
	return this->append(acs);
}

inline AcString& AcString::append(wchar_t wch)
{
	const wchar_t wstr[2] = {wch, L'\0'};
	return this->append(wstr);
}

inline AcString AcString::operator+(wchar_t wch) const
{
	return this->concat(wch);
}

inline AcString AcString::operator+(const wchar_t* pwsz) const
{
	return this->concat(pwsz);
}

inline AcString AcString::operator+(const AcString& acs) const
{
	return this->concat(acs);
}

inline AcString AcString::concat(wchar_t wch) const
{
	const wchar_t wstr[2] = {wch, L'\0'};
	return this->concat(wstr);
}

inline AcString AcString::precat(wchar_t ch) const
{
	const wchar_t str[2] = {ch, '\0'};
	return this->precat(str);
}

inline int AcString::compare(wchar_t wch) const
{
	const wchar_t wstr[2] = {wch, L'\0'};
	return this->compare(wstr);
}

inline int AcString::compare(const AcString& acs) const
{
	return this->compare(acs.kwszPtr());
}

inline int AcString::compareNoCase(wchar_t wch) const
{
	const wchar_t wstr[2] = {wch, L'\0'};
	return this->compareNoCase(wstr);
}

inline int AcString::compareNoCase(const AcString& acs) const
{
	return this->compareNoCase(acs.kwszPtr());
}

inline int AcString::collate(const AcString& acs) const
{
	return this->collate(acs.kwszPtr());
}

inline int AcString::collateNoCase(const AcString& acs) const
{
	return this->collateNoCase(acs.kwszPtr());
}

inline bool AcString::operator==(wchar_t wch) const
{
	return this->compare(wch) == 0;
}

inline bool AcString::operator==(const wchar_t* pwsz) const
{
	return this->compare(pwsz) == 0;
}

inline bool AcString::operator==(const AcString& acs) const
{
	return this->compare(acs) == 0;
}

inline bool AcString::operator!=(wchar_t wch) const
{
	return this->compare(wch) != 0;
}

inline bool AcString::operator!=(const wchar_t* pwsz) const
{
	return this->compare(pwsz) != 0;
}

inline bool AcString::operator!=(const AcString& acs) const
{
	return this->compare(acs) != 0;
}

inline bool AcString::operator>(wchar_t wch) const
{
	return this->compare(wch) > 0;
}

inline bool AcString::operator>(const wchar_t* pwsz) const
{
	return this->compare(pwsz) > 0;
}

inline bool AcString::operator>(const AcString& acs) const
{
	return this->compare(acs) > 0;
}

inline bool AcString::operator>=(wchar_t wch) const
{
	return this->compare(wch) >= 0;
}

inline bool AcString::operator>=(const wchar_t* pwsz) const
{
	return this->compare(pwsz) >= 0;
}

inline bool AcString::operator>=(const AcString& acs) const
{
	return this->compare(acs) >= 0;
}

inline bool AcString::operator<(wchar_t wch) const
{
	return this->compare(wch) < 0;
}

inline bool AcString::operator<(const wchar_t* pwsz) const
{
	return this->compare(pwsz) < 0;
}

inline bool AcString::operator<(const AcString& acs) const
{
	return this->compare(acs) < 0;
}

inline bool AcString::operator<=(wchar_t wch) const
{
	return this->compare(wch) <= 0;
}

inline bool AcString::operator<=(const wchar_t* pwsz) const
{
	return this->compare(pwsz) <= 0;
}

inline bool AcString::operator<=(const AcString& acs) const
{
	return this->compare(acs) <= 0;
}


inline bool operator==(wchar_t wch, const AcString& acs)
{
	return acs.compare(wch) == 0;
}

inline bool operator==(const wchar_t* pwsz, const AcString& acs)
{
	return acs.compare(pwsz) == 0;
}

inline bool operator!=(wchar_t wch, const AcString& acs)
{
	return acs.compare(wch) != 0;
}

inline bool operator!=(const wchar_t* pwsz, const AcString& acs)
{
	return acs.compare(pwsz) != 0;
}

inline bool operator>(wchar_t wch, const AcString& acs)
{
	return acs.compare(wch) < 0;
}

inline bool operator>(const wchar_t* pwsz, const AcString& acs)
{
	return acs.compare(pwsz) < 0;
}

inline bool operator>=(wchar_t wch, const AcString& acs)
{
	return acs.compare(wch) <= 0;
}

inline bool operator>=(const wchar_t* pwsz, const AcString& acs)
{
	return acs.compare(pwsz) <= 0;
}

inline bool operator<(wchar_t wch, const AcString& acs)
{
	return acs.compare(wch) > 0;
}

inline bool operator<(const wchar_t* pwsz, const AcString& acs)
{
	return acs.compare(pwsz) > 0;
}

inline bool operator<=(wchar_t wch, const AcString& acs)
{
	return acs.compare(wch) >= 0;
}

inline bool operator<=(const wchar_t* pwsz, const AcString& acs)
{
	return acs.compare(pwsz) >= 0;
}

inline AcString operator+(ACHAR ch, const AcString& acs)
{
	return acs.precat(ch);
}

inline AcString operator+(const wchar_t* pwsz, const AcString& acs)
{
	return acs.precat(pwsz);
}

inline bool AcString::equalsNoCase(const AcString& left, const AcString& right)
{
	return left.compareNoCase(right) == 0;
}

class AcUniqueString
{
public:
	ACBASE_PORT static const AcUniqueString* Intern(const wchar_t*);
};


#if defined(_AFX) || defined(__OSX_WINAPI_UNIX_STRING_H__) || defined(__ATLSTR_H__)


inline AcString::AcString(const CStringW& csw) : AcString()
{
	const wchar_t* pwsz = (const wchar_t*)csw;
	*this = pwsz;
}

inline AcString& AcString::operator=(const CStringW& csw)
{
	const wchar_t* pwsz = (const wchar_t*)csw;
	return this->assign(pwsz);
}

inline AcString& AcString::operator+=(const CStringW& csw)
{
	const wchar_t* pwsz = (const wchar_t*)csw;
	return this->append(pwsz);
}

inline int AcString::compare(const CStringW& csw) const
{
	const wchar_t* pwsz = (const wchar_t*)csw;
	return this->compare(pwsz);
}

inline int AcString::compareNoCase(const CStringW& csw) const
{
	const wchar_t* pwsz = (const wchar_t*)csw;
	return this->compareNoCase(pwsz);
}

inline int AcString::match(const CStringW& csw) const
{
	const wchar_t* pwsz = (const wchar_t*)csw;
	return this->match(pwsz);
}

inline int AcString::matchNoCase(const CStringW& csw) const
{
	const wchar_t* pwsz = (const wchar_t*)csw;
	return this->matchNoCase(pwsz);
}

inline bool AcString::operator==(const CStringW& csw) const
{
	return this->compare(csw) == 0;
}

inline bool AcString::operator!=(const CStringW& csw) const
{
	return this->compare(csw) != 0;
}

inline bool AcString::operator>(const CStringW& csw) const
{
	return this->compare(csw) > 0;
}

inline bool AcString::operator>=(const CStringW& csw) const
{
	return this->compare(csw) >= 0;
}

inline bool AcString::operator<(const CStringW& csw) const
{
	return this->compare(csw) < 0;
}

inline bool AcString::operator<=(const CStringW& csw) const
{
	return this->compare(csw) <= 0;
}

#	if defined(_AFX)
inline bool operator==(const CStringW& csw, const AcString& acs)
{
	return acs.compare(csw) == 0;
}

inline bool operator!=(const CStringW& csw, const AcString& acs)
{
	return acs.compare(csw) != 0;
}

inline bool operator>(const CStringW& csw, const AcString& acs)
{
	return acs.compare(csw) < 0;
}

inline bool operator>=(const CStringW& csw, const AcString& acs)
{
	return acs.compare(csw) <= 0;
}

inline bool operator<(const CStringW& csw, const AcString& acs)
{
	return acs.compare(csw) > 0;
}

inline bool operator<=(const CStringW& csw, const AcString& acs)
{
	return acs.compare(csw) >= 0;
}

#		ifndef DISABLE_CSTRING_PLUS_ACSTRING

inline AcString operator+(const CStringW& csw, const AcString& acs)
{
	const wchar_t* pwsz = (const wchar_t*)csw;
	return acs.precat(pwsz);
}
#		endif

#	endif

#endif

#include "icarx/IcArxPackPop.h"

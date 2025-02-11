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

#include "AcPl.h"
#include "AcPlObject.h"
#include "AcPlDSDEntry.h"
#include "AcPlPrecisionEntry.h"
#include "acarray.h"
#include "AcString.h"

using AcPlDSDEntries = AcArray<AcPlDSDEntry, AcArrayObjectCopyReallocator<AcPlDSDEntry>>;
using AcPlPrecisionEntries =
		AcArray<AcPlPrecisionEntry, AcArrayObjectCopyReallocator<AcPlPrecisionEntry>>;

#include "icarx/IcArxPackPush.h"

struct AcPl3dDwfOptions
{
	bool bGroupByXrefHierarchy;
	bool bPublishWithMaterials;
};

class AcPlDSDData : public AcPlObject
{
private:
	ACPL_DECLARE_MEMBERS(AcPlDSDData)

public:
	ACPL_PORT AcPlDSDData();
	ACPL_PORT AcPlDSDData(const AcPlDSDData& src);
	ACPL_PORT ~AcPlDSDData();
	ACPL_PORT AcPlDSDData& operator=(const AcPlDSDData& src);

	ACPL_PORT AcPlDSDEntry& DSDEntryAt(int idx);
	ACPL_PORT const ACHAR* categoryName() const;
	ACPL_PORT const ACHAR* currentPrecision() const;
	ACPL_PORT const ACHAR* destinationName() const;
	ACPL_PORT const AcPl3dDwfOptions& get3dDwfOptions() const;
	ACPL_PORT void getDSDEntries(AcPlDSDEntries& val) const;
	ACPL_PORT void getPrecisionEntries(AcPlPrecisionEntries& val) const;
	ACPL_PORT void getUnrecognizedData(AcArray<ACHAR*>& sectionArray,
									   AcArray<ACHAR*>& dataArray) const;
	ACPL_PORT void getUnrecognizedData(AcStringArray& sectionArray, AcStringArray& dataArray) const;
	ACPL_PORT bool includeLayerInfo() const;
	ACPL_PORT bool initializeLayouts() const;
	ACPL_PORT bool isHomogeneous() const;
	ACPL_PORT bool isSheetSet() const;
	ACPL_PORT bool lineMerge() const;
	ACPL_PORT const ACHAR* logFilePath() const;
	ACPL_PORT unsigned int majorVersion() const;
	ACPL_PORT unsigned int minorVersion() const;
	ACPL_PORT unsigned int noOfCopies() const;
	ACPL_PORT int numberOfDSDEntries() const;
	ACPL_PORT const ACHAR* password() const;
	ACPL_PORT bool plotStampOn() const;
	ACPL_PORT const ACHAR* projectPath() const;
	ACPL_PORT bool promptForDwfName() const;
	ACPL_PORT bool promptForPassword() const;
	ACPL_PORT bool pwdProtectPublishedDWF() const;
	ACPL_PORT bool readDSD(const ACHAR* pName);
	ACPL_PORT const ACHAR* selectionSetName() const;
	ACPL_PORT void set3dDwfOptions(const AcPl3dDwfOptions& val);
	ACPL_PORT void setCategoryName(const ACHAR* pCategoryName);
	ACPL_PORT void setCurrentPrecision(const ACHAR* pCurrentPrecision);
	ACPL_PORT void setDestinationName(const ACHAR* pVal);
	ACPL_PORT void setDSDEntries(const AcPlDSDEntries& val);
	ACPL_PORT void setIncludeLayerInfo(bool bOn);
	ACPL_PORT void setInitializeLayouts(bool initLayouts);
	ACPL_PORT void setIsHomogeneous(bool bHomogeneous);
	ACPL_PORT void setIsSheetSet(bool bSheetSet);
	ACPL_PORT void setLineMerge(bool bOn);
	ACPL_PORT void setLogFilePath(const ACHAR* pLogFilePath);
	ACPL_PORT void setMajorVersion(unsigned int majorVersion);
	ACPL_PORT void setMinorVersion(unsigned int minorVersion);
	ACPL_PORT void setNoOfCopies(unsigned int copies);
	ACPL_PORT void setPassword(const ACHAR* pVal);
	ACPL_PORT void setPlotStampOn(bool bOn);
	ACPL_PORT void setPrecisionEntries(const AcPlPrecisionEntries& val);
	ACPL_PORT void setProjectPath(const ACHAR* pVal);
	ACPL_PORT void setPromptForDwfName(bool bPromptForDwfName);
	ACPL_PORT void setPromptForPassword(bool bPromptForPassword);
	ACPL_PORT void setPwdProtectPublishedDWF(bool bPwdProtectPublishedDWF);
	ACPL_PORT void setSelectionSetName(const ACHAR* pSelSetName);
	ACPL_PORT void setSheetSetName(const ACHAR* pSheetSetName);
	ACPL_PORT void setSheetType(AcPlDSDEntry::SheetType val);
	ACPL_PORT void setUnrecognizedData(const ACHAR* pSectionName, const ACHAR* pSectionData);
	ACPL_PORT void setUnrecognizedData(const AcArray<ACHAR*>& sectionArray,
									   const AcArray<ACHAR*>& dataArray);
	ACPL_PORT void setUnrecognizedData(const AcStringArray& sectionArray,
									   const AcStringArray& dataArray);
	ACPL_PORT void setViewFile(bool bViewFile);
	ACPL_PORT const ACHAR* sheetSetName() const;
	ACPL_PORT AcPlDSDEntry::SheetType sheetType() const;
	ACPL_PORT bool viewFile() const;
	ACPL_PORT bool writeDSD(const ACHAR* pName);
};

#include "icarx/IcArxPackPop.h"

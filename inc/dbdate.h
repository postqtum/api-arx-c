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
***     Description: Declaration of AcDbDate class
***
*****************************************************************************/
#pragma once

#include <ctime>
#include "acdb.h"
#include "acadstrc.h"
#include "AcDbCore2dDefs.h"
#include "acdbport.h"

class AcDbDwgFiler;
class AcString;
class AcDbImpDate;

typedef struct _SYSTEMTIME SYSTEMTIME;

#include "icarx/IcArxPackPush.h"

class AcDbDate
{
	friend class AcDbImpDate;

public:
	enum InitialValue
	{
		kInitZero = 1,
		kInitLocalTime = 2,
		kInitUniversalTime = 3
	};

private:
	AcDbImpDate* mpImpDate;

public:
	AcDbDate();
	AcDbDate(InitialValue i);
	AcDbDate(const AcDbDate&);
	virtual ~AcDbDate();
	const AcDbDate& operator=(const AcDbDate&);
	const AcDbDate operator+(const AcDbDate& date) const;
	const AcDbDate& operator+=(const AcDbDate& date);
	const AcDbDate operator-(const AcDbDate& date) const;
	const AcDbDate& operator-=(const AcDbDate& date);
	bool operator==(const AcDbDate&) const;
	bool operator<(const AcDbDate&) const;
	bool operator<=(const AcDbDate&) const;
	bool operator>(const AcDbDate&) const;
	bool operator>=(const AcDbDate&) const;

	const AcDbDate& add(const AcDbDate& date);
	short day() const;
	Acad::ErrorStatus dwgIn(AcDbDwgFiler* inFiler);
	Acad::ErrorStatus dwgOut(AcDbDwgFiler* outFiler) const;
	int getApproximateTime() const;
	void getDate(short& month, short& day, short& year) const;
	ACDBCORE2D_PORT AcString getLocalDisplayString() const;
	void getLocalTime();
	ACDB_PORT void getTime(SYSTEMTIME& st) const;
	void getTime(std::tm& st) const;
	void getTime(time_t& st) const;
	void getTime(short& hour, short& min, short& sec, short& msec) const;
	void getUniversalTime();
	short hour() const;
	int32_t julianDay() const;
	double julianFraction() const;
	void localToUniversal();
	short millisecond() const;
	short minute() const;
	short month() const;
	int32_t msecsPastMidnight() const;
	short second() const;
	void setApproximateTime(int time);
	ACDBCORE2D_PORT void setDate(int month, int day, int year);
	ACDBCORE2D_PORT void setDay(int);
	ACDBCORE2D_PORT void setHour(int);
	void setJulianDate(int32_t julianDay, int32_t msec);
	void setJulianDay(int32_t julianDay);
	void setJulianFraction(double);
	ACDBCORE2D_PORT void setMillisecond(int);
	ACDBCORE2D_PORT void setMinute(int);
	ACDBCORE2D_PORT void setMonth(int);
	void setMsecsPastMidnight(int32_t msec);
	ACDBCORE2D_PORT void setSecond(int);
	ACDBCORE2D_PORT void setTime(const std::tm& st);
	ACDB_PORT void setTime(const SYSTEMTIME& st);
	ACDBCORE2D_PORT void setTime(int hour, int min, int sec, int msec);
	void setToZero();
	ACDBCORE2D_PORT void setYear(int);
	const AcDbDate& subtract(const AcDbDate& date);
	void universalToLocal();
	short year() const;
};

#include "icarx/IcArxPackPop.h"

inline const AcDbDate AcDbDate::operator+(const AcDbDate& d) const
{
	return AcDbDate(*this) += d;
}

inline const AcDbDate AcDbDate::operator-(const AcDbDate& d) const
{
	return AcDbDate(*this) -= d;
}

inline bool AcDbDate::operator<(const AcDbDate& d) const
{
	return !operator>=(d);
}

inline bool AcDbDate::operator<=(const AcDbDate& d) const
{
	return !operator>(d);
}

inline const AcDbDate& AcDbDate::add(const AcDbDate& date)
{
	return operator+=(date);
}

inline const AcDbDate& AcDbDate::subtract(const AcDbDate& date)
{
	return operator-=(date);
}

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

class AcGePoint2d;
class AcGePoint3d;
class AcGeVector2d;
class AcGeVector3d;

#ifdef __clang__
#	pragma clang diagnostic push
#	pragma clang diagnostic ignored "-Wcast-align"
#endif

inline double* asDblArray(const AcGePoint2d& pnt)
{
	return const_cast<double*>(reinterpret_cast<const double*>(&pnt));
}

inline double* asDblArray(const AcGePoint3d& pnt)
{
	return const_cast<double*>(reinterpret_cast<const double*>(&pnt));
}

inline double* asDblArray(const AcGeVector2d& vec)
{
	return const_cast<double*>(reinterpret_cast<const double*>(&vec));
}

inline double* asDblArray(const AcGeVector3d& vec)
{
	return const_cast<double*>(reinterpret_cast<const double*>(&vec));
}

inline AcGePoint2d& asPnt2d(const double* pnt)
{
	return *const_cast<AcGePoint2d*>(reinterpret_cast<const AcGePoint2d*>(pnt));
}

inline AcGePoint3d& asPnt3d(const double* pnt)
{
	return *const_cast<AcGePoint3d*>(reinterpret_cast<const AcGePoint3d*>(pnt));
}

inline AcGeVector2d& asVec2d(const double* vec)
{
	return *const_cast<AcGeVector2d*>(reinterpret_cast<const AcGeVector2d*>(vec));
}

inline AcGeVector3d& asVec3d(const double* vec)
{
	return *const_cast<AcGeVector3d*>(reinterpret_cast<const AcGeVector3d*>(vec));
}

#ifdef __clang__
#	pragma clang diagnostic pop
#endif

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
***     Description: Some AcArray specializations
***
*****************************************************************************/

#if defined(ADSK_ACGEVECTOR2D_DEFINED) && defined(AC_ACARRAY_H)
#	undef ADSK_ACGEVECTOR2D_DEFINED
template<>
struct AcArrayItemCopierSelector<AcGeVector2d, false>
{
	typedef AcArrayMemCopyReallocator<AcGeVector2d> allocator;
};
#endif

#if defined(ADSK_ACGEVECTOR3D_DEFINED) && defined(AC_ACARRAY_H)
#	undef ADSK_ACGEVECTOR3D_DEFINED
template<>
struct AcArrayItemCopierSelector<AcGeVector3d, false>
{
	typedef AcArrayMemCopyReallocator<AcGeVector3d> allocator;
};
#endif

#if defined(ADSK_ACGEPOINT3D_DEFINED) && defined(AC_ACARRAY_H)
#	undef ADSK_ACGEPOINT3D_DEFINED
template<>
struct AcArrayItemCopierSelector<AcGePoint3d, false>
{
	typedef AcArrayMemCopyReallocator<AcGePoint3d> allocator;
};
#endif

#if defined(ADSK_ACGEPOINT2D_DEFINED) && defined(AC_ACARRAY_H)
#	undef ADSK_ACGEPOINT2D_DEFINED
template<>
struct AcArrayItemCopierSelector<AcGePoint2d, false>
{
	typedef AcArrayMemCopyReallocator<AcGePoint2d> allocator;
};
#endif

#if defined(ADSK_ACDBOBJECTID_DEFINED) && defined(AC_ACARRAY_H)
#	undef ADSK_ACDBOBJECTID_DEFINED
template<>
struct AcArrayItemCopierSelector<AcDbObjectId, false>
{
	typedef AcArrayMemCopyReallocator<AcDbObjectId> allocator;
};
#endif

#if defined(ADSK_ACCMENTITYCOLOR_DEFINED) && defined(AC_ACARRAY_H)
#	undef ADSK_ACCMENTITYCOLOR_DEFINED
template<>
struct AcArrayItemCopierSelector<AcCmEntityColor, false>
{
	typedef AcArrayMemCopyReallocator<AcCmEntityColor> allocator;
};
#endif


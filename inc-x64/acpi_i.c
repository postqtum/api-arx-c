

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.01.0626 */
/* at Tue Jan 19 04:14:07 2038
 */
/* Compiler settings for ..\..\lib\IcArx\AcPi.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0626 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        EXTERN_C __declspec(selectany) const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif // !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_ACPILib,0x7082D741,0xB42B,0x4B52,0x8F,0x06,0x13,0xA8,0x28,0x24,0x80,0xE1);


MIDL_DEFINE_GUID(IID, IID_IAcPiPropertyInspector,0xC99EBB61,0x90C8,0x4768,0xAD,0xD1,0x8F,0x5A,0xF9,0x89,0xCE,0x2C);


MIDL_DEFINE_GUID(IID, IID_IAcPiPropertyInspector2,0x687AE26A,0xA274,0x4829,0xAD,0xEB,0xD1,0x4F,0x8D,0x45,0xC5,0x85);


MIDL_DEFINE_GUID(IID, IID_IAcPiPropertyInspectorInputEventSink,0xF1C290A2,0x801A,0x4A41,0xB9,0xE4,0xE5,0xE9,0xEE,0x46,0x12,0x9A);


MIDL_DEFINE_GUID(IID, IID_IAcPiPropertyIdentifier,0x081530C1,0x530B,0x417B,0x80,0xEF,0xCA,0xB5,0xC7,0x0A,0x3B,0x77);


MIDL_DEFINE_GUID(IID, IID_IAcPiCommandButton,0x438CBD47,0x3AFB,0x4D63,0xB6,0xAB,0x4C,0x7D,0xA9,0xEA,0x7A,0x5C);


MIDL_DEFINE_GUID(IID, IID_IAcPiPropertyDisplay,0x19BE5D38,0xF41C,0x4AC1,0xAF,0xD4,0xFB,0x9B,0xFE,0x5A,0xB6,0xC7);


MIDL_DEFINE_GUID(CLSID, CLSID_AcPiPropertyInspector,0xA3AA0E16,0x0609,0x422B,0x94,0x9D,0x1F,0xA1,0xEC,0x9F,0xE2,0x33);


MIDL_DEFINE_GUID(CLSID, CLSID_AcPiPropertyIdentifier,0x7D5E7BEE,0x19F6,0x4CA2,0x85,0xC5,0x17,0x5D,0x5E,0x14,0x3C,0xDD);


MIDL_DEFINE_GUID(IID, IID_IAcPiPropertyUnspecified,0x401F8094,0xBF7E,0x4CA5,0xA6,0x92,0xBD,0x14,0x07,0x7E,0x21,0x7B);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif




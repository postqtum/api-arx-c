

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.01.0626 */
/* at Tue Jan 19 04:14:07 2038
 */
/* Compiler settings for ..\..\lib\IcArx\axdb.idl:
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

MIDL_DEFINE_GUID(IID, LIBID_AXDBLib,0xCD262873,0x105D,0x4C9F,0x81,0xFA,0xDF,0xF1,0x87,0x28,0x58,0x15);


MIDL_DEFINE_GUID(IID, IID_IAcadObject,0xE1FBFAC0,0x8561,0x4CEA,0xBB,0xF7,0x64,0x4C,0x59,0x1A,0xD8,0x6F);


MIDL_DEFINE_GUID(IID, IID_IAcadDatabase,0xC8CC9840,0xBF9A,0x4B92,0x8E,0x38,0xFA,0xAB,0x17,0x88,0x53,0x53);


MIDL_DEFINE_GUID(IID, IID_IAcadBlock,0x07B442F2,0xE73F,0x4B54,0xAB,0x3F,0xA7,0xBF,0xC8,0xB6,0x5E,0xAE);


MIDL_DEFINE_GUID(IID, IID_IAcadModelSpace,0xF646D04C,0xF99D,0x4D80,0xB1,0xE6,0xC0,0x46,0x3C,0xCB,0x0A,0xCE);


MIDL_DEFINE_GUID(IID, IID_IAcadEntity,0x59CD01D8,0x01AF,0x4389,0x81,0xDE,0x3E,0x25,0xA2,0x9C,0x60,0xCC);


MIDL_DEFINE_GUID(IID, IID_IAcadAcCmColor,0x1FED8EE6,0x83E5,0x4FDB,0x83,0x88,0xD5,0x52,0x38,0xDA,0xD2,0x61);


MIDL_DEFINE_GUID(IID, IID_IAcadHyperlinks,0x51702644,0x14F6,0x433C,0x92,0x88,0xC1,0x98,0xD7,0xCA,0xE2,0xB1);


MIDL_DEFINE_GUID(IID, IID_IAcadHyperlink,0xFF45681E,0x16FF,0x4F71,0xBD,0xDC,0xB8,0xBE,0x61,0xC4,0x53,0x42);


MIDL_DEFINE_GUID(IID, IID_IAcad3DFace,0x7314819E,0xA824,0x4B02,0xB1,0x7D,0x0F,0x57,0xF1,0x1E,0x08,0xC1);


MIDL_DEFINE_GUID(IID, IID_IAcadPolygonMesh,0xCC3084DC,0x9ACC,0x48C5,0xB6,0x3E,0x25,0x02,0x06,0x0E,0xAD,0x0C);


MIDL_DEFINE_GUID(IID, IID_IAcad3DPolyline,0xBDD86ABC,0x051B,0x45E0,0x99,0xF7,0xAB,0xC4,0xB3,0xB2,0x2E,0xCD);


MIDL_DEFINE_GUID(IID, IID_IAcadArc,0x7850B24F,0xB500,0x40CC,0x91,0x71,0x32,0xC0,0xCF,0xBC,0x07,0xC2);


MIDL_DEFINE_GUID(IID, IID_IAcadAttribute,0x6D3D73CE,0x3FBA,0x4B2D,0xBB,0x2C,0xEC,0xFF,0x06,0x71,0x7A,0x0D);


MIDL_DEFINE_GUID(IID, IID_IAcad3DSolid,0x5F89CD72,0x0503,0x4D4E,0x8B,0x7D,0xD2,0xEC,0x8A,0xE2,0xE8,0x03);


MIDL_DEFINE_GUID(IID, IID_IAcadRegion,0x9E7AFB8D,0x1FCE,0x46E5,0x9C,0xEB,0xB4,0x2A,0x4A,0x4F,0xAA,0xF8);


MIDL_DEFINE_GUID(IID, IID_IAcadCircle,0x21A07C7C,0x8D8A,0x44AC,0xBE,0x13,0x87,0xEA,0x0F,0xDF,0x53,0x57);


MIDL_DEFINE_GUID(IID, IID_IAcadDimension,0xC6CC8B3C,0x950E,0x4402,0xB4,0x1C,0x5B,0x12,0x9D,0x6E,0x09,0x17);


MIDL_DEFINE_GUID(IID, IID_IAcadDimAligned,0x7614E89A,0x6B64,0x46F2,0xBC,0x0E,0x2D,0xAA,0xBC,0xA3,0x68,0x6E);


MIDL_DEFINE_GUID(IID, IID_IAcadDimAngular,0x222B8FF2,0x5E92,0x4348,0x9D,0xE7,0x84,0x05,0x64,0x83,0x3A,0x69);


MIDL_DEFINE_GUID(IID, IID_IAcadDimDiametric,0xD9A70468,0xE145,0x426A,0x9C,0x19,0x33,0x4A,0x02,0x2E,0x28,0xE3);


MIDL_DEFINE_GUID(IID, IID_IAcadDimRotated,0x6E48B532,0x1218,0x4CEF,0xBF,0x06,0x53,0xB6,0xF4,0x56,0xF6,0x97);


MIDL_DEFINE_GUID(IID, IID_IAcadDimOrdinate,0xF0EE0846,0xFDE4,0x4ADA,0xAE,0x26,0x55,0x24,0x16,0xDB,0xEB,0xF6);


MIDL_DEFINE_GUID(IID, IID_IAcadDimRadial,0xF08A026D,0xD41E,0x4537,0xBE,0x98,0x5B,0xD7,0x45,0x5E,0xDF,0x97);


MIDL_DEFINE_GUID(IID, IID_IAcadEllipse,0x1EBB424A,0x2E5C,0x439D,0x9C,0x21,0xAD,0xF7,0xBF,0x2B,0x64,0xAA);


MIDL_DEFINE_GUID(IID, IID_IAcadLeader,0x1135487F,0x207A,0x468F,0x96,0x97,0x44,0xA6,0xAE,0xDA,0x63,0xB4);


MIDL_DEFINE_GUID(IID, IID_IAcadMText,0x67106696,0x2891,0x4BBB,0xA3,0x1B,0x5B,0x41,0x8D,0xEC,0x14,0xC0);


MIDL_DEFINE_GUID(IID, IID_IAcadPoint,0xA6462574,0x7A49,0x45A0,0x98,0xA6,0x8E,0xAA,0x28,0xD2,0x39,0x83);


MIDL_DEFINE_GUID(IID, IID_IAcadLWPolyline,0x796959A5,0x1792,0x42B9,0xB3,0xB4,0xAD,0xF3,0xF0,0xB6,0x1F,0x01);


MIDL_DEFINE_GUID(IID, IID_IAcadPolyline,0x2460B81E,0x458B,0x46A6,0x81,0x8E,0x7A,0x8E,0x60,0xA2,0x99,0x67);


MIDL_DEFINE_GUID(IID, IID_IAcadRay,0xFF7D7606,0x498A,0x4A30,0xAF,0x47,0x1A,0x9F,0x7C,0x76,0x2E,0x72);


MIDL_DEFINE_GUID(IID, IID_IAcadShape,0xD5F3FD01,0x0922,0x4315,0x9F,0xDD,0x14,0x9C,0xFB,0x0B,0x24,0xFB);


MIDL_DEFINE_GUID(IID, IID_IAcadSolid,0xFF042446,0xB14C,0x46D7,0x8F,0x45,0xAB,0xAE,0xD4,0x42,0x61,0x31);


MIDL_DEFINE_GUID(IID, IID_IAcadSpline,0x8D11500F,0xB93E,0x4EA7,0xBD,0xEE,0x45,0x10,0xD4,0x85,0x60,0xE0);


MIDL_DEFINE_GUID(IID, IID_IAcadText,0x8872B558,0x29F9,0x41B6,0x94,0x8C,0xAA,0xBC,0xB7,0x44,0xD6,0x82);


MIDL_DEFINE_GUID(IID, IID_IAcadTolerance,0xB5BCF95E,0xA3E0,0x43C2,0xA2,0x37,0xF5,0x4A,0x8D,0x84,0x60,0x86);


MIDL_DEFINE_GUID(IID, IID_IAcadTrace,0xF84EA407,0xC3FA,0x48C8,0x99,0xC3,0x0B,0xD4,0xB9,0x7E,0x77,0x52);


MIDL_DEFINE_GUID(IID, IID_IAcadXline,0x0E43F770,0x03ED,0x4111,0x95,0x4D,0x70,0x1E,0xE9,0x2B,0xD2,0xD8);


MIDL_DEFINE_GUID(IID, IID_IAcadBlockReference,0xC7BEFAAE,0x9315,0x43DD,0x94,0xCC,0xD2,0xF3,0x83,0x40,0x22,0x80);


MIDL_DEFINE_GUID(IID, IID_IAcadHatch,0x6C7034B2,0x1EE6,0x4100,0x93,0x8A,0x45,0x53,0x34,0xA9,0x76,0x74);


MIDL_DEFINE_GUID(IID, IID_IAcadRasterImage,0xB63304F3,0x7E00,0x47B7,0xA8,0xF9,0x01,0x16,0xAB,0x3B,0x97,0x79);


MIDL_DEFINE_GUID(IID, IID_IAcadLine,0xCCAF1FAE,0xB030,0x4FED,0x8F,0xAE,0xA7,0xE8,0xED,0x0A,0xE9,0x37);


MIDL_DEFINE_GUID(IID, IID_IAcadPlotConfiguration,0xC7171462,0x64C7,0x4336,0x85,0xB3,0xE5,0x3E,0xC3,0x97,0xC6,0x46);


MIDL_DEFINE_GUID(IID, IID_IAcadLayout,0xF2B0B76B,0x5AF8,0x476E,0xA4,0x05,0x1A,0xD4,0x29,0xCA,0xD7,0x1D);


MIDL_DEFINE_GUID(IID, IID_IAcadMInsertBlock,0x73B36591,0xCAA1,0x4A10,0x9C,0x7E,0x87,0xAB,0x0A,0xC8,0xA1,0xB1);


MIDL_DEFINE_GUID(IID, IID_IAcadPolyfaceMesh,0x9D6665D4,0x28D9,0x4B61,0xBD,0xC1,0x30,0xDB,0x6F,0xDF,0x60,0xCE);


MIDL_DEFINE_GUID(IID, IID_IAcadMLine,0xB7D3F562,0xFA0A,0x4757,0xBB,0xA5,0xAD,0x2D,0x3C,0x40,0x0F,0xE6);


MIDL_DEFINE_GUID(IID, IID_IAcadDim3PointAngular,0x437D797E,0x091E,0x476A,0x95,0x1F,0x10,0x10,0x66,0xF3,0xC9,0xD1);


MIDL_DEFINE_GUID(IID, IID_IAcadExternalReference,0x2CCCA4A2,0x72E3,0x4ACE,0x9F,0x67,0xA5,0x1A,0x1B,0x12,0x83,0x30);


MIDL_DEFINE_GUID(IID, IID_IAcadTable,0xFF91C0E7,0xDF11,0x48F8,0x89,0xCE,0xCB,0xA5,0x4A,0x91,0x95,0x28);


MIDL_DEFINE_GUID(IID, IID_IAcadDimArcLength,0xE1783C43,0xD1A0,0x49FD,0xB0,0x79,0x95,0xFF,0x7B,0xEB,0x42,0xD4);


MIDL_DEFINE_GUID(IID, IID_IAcadDimRadialLarge,0x59ED92C9,0x8F2D,0x42CD,0xBA,0xB6,0xDD,0xAC,0xA8,0xFC,0x0A,0x34);


MIDL_DEFINE_GUID(IID, IID_IAcadSection,0x47221F40,0xF48B,0x4E81,0x8C,0xD6,0x5C,0x70,0xFF,0x58,0xD7,0xEB);


MIDL_DEFINE_GUID(IID, IID_IAcadSectionSettings,0x88895D75,0x357D,0x4731,0xB0,0xE1,0x15,0xAD,0xEA,0xC9,0xA2,0x9A);


MIDL_DEFINE_GUID(IID, IID_IAcadSectionTypeSettings,0x7BFD46A3,0x4C13,0x4172,0xA4,0x71,0x32,0x6A,0xD5,0x60,0xAD,0x03);


MIDL_DEFINE_GUID(IID, IID_IAcadMLeader,0xA248688F,0xEA97,0x4208,0xAC,0xE7,0xF0,0x7E,0x11,0xD0,0xC5,0xD5);


MIDL_DEFINE_GUID(IID, IID_IAcadPaperSpace,0x0BB3DC1E,0xD9C9,0x4487,0x94,0x70,0x39,0xE5,0x80,0xBA,0xA0,0x36);


MIDL_DEFINE_GUID(IID, IID_IAcadPViewport,0xFB472388,0x2D52,0x4C35,0x83,0xF4,0xF3,0x94,0x7E,0x80,0x17,0x40);


MIDL_DEFINE_GUID(IID, IID_IAcadView,0x21A08CA4,0xD500,0x4CD2,0x89,0x6F,0x9C,0xE1,0xF9,0x33,0x5E,0x61);


MIDL_DEFINE_GUID(IID, IID_IAcadBlocks,0x083050CC,0xCC9C,0x4145,0xB4,0x28,0xAA,0x07,0x32,0x02,0xED,0x70);


MIDL_DEFINE_GUID(IID, IID_IAcadGroups,0xDB01B68E,0x3B6D,0x44E9,0x97,0xF7,0x19,0xF5,0x3F,0x4C,0x64,0xA4);


MIDL_DEFINE_GUID(IID, IID_IAcadGroup,0x751C52DF,0x7D8F,0x4CB9,0x93,0xD4,0x87,0x80,0xAB,0xF2,0x4A,0xAC);


MIDL_DEFINE_GUID(IID, IID_IAcadDimStyles,0x8570B105,0x9807,0x4822,0xAF,0x97,0x85,0xFD,0x50,0x25,0x56,0xE5);


MIDL_DEFINE_GUID(IID, IID_IAcadDimStyle,0x392C597F,0xA7A3,0x49A0,0xA7,0xF6,0x29,0xD6,0xF7,0x9A,0xA6,0x6D);


MIDL_DEFINE_GUID(IID, IID_IAcadLayers,0x1596CF53,0xE620,0x49B0,0xB9,0xCD,0x9B,0x64,0x6F,0x5A,0xE8,0x16);


MIDL_DEFINE_GUID(IID, IID_IAcadLayer,0xE88DADA5,0x4CFD,0x4ADC,0x9E,0x23,0x03,0x34,0x96,0x99,0x85,0x08);


MIDL_DEFINE_GUID(IID, IID_IAcadLineTypes,0x4F944F76,0x7D8B,0x4132,0x94,0x6A,0x3D,0x3E,0x24,0x4B,0x87,0xF0);


MIDL_DEFINE_GUID(IID, IID_IAcadLineType,0x99F9B977,0x990B,0x496F,0xAB,0xA5,0x74,0xBE,0x49,0x5D,0xE1,0x56);


MIDL_DEFINE_GUID(IID, IID_IAcadDictionaries,0xB3D013EC,0xFF83,0x44EF,0x8C,0x3F,0xD1,0x0F,0xFF,0x8A,0x8F,0x48);


MIDL_DEFINE_GUID(IID, IID_IAcadDictionary,0x1C373D9E,0x4938,0x4439,0x94,0x97,0x34,0xE3,0xF4,0xC2,0x06,0xCF);


MIDL_DEFINE_GUID(IID, IID_IAcadXRecord,0xCFAA2527,0x49E5,0x470E,0xA4,0xF3,0xD2,0x1C,0x31,0xB1,0xB0,0x29);


MIDL_DEFINE_GUID(IID, IID_IAcadRegisteredApplications,0x95136332,0x5329,0x4DBA,0xB0,0x0B,0xA7,0xFF,0xA8,0x99,0xB4,0xC2);


MIDL_DEFINE_GUID(IID, IID_IAcadRegisteredApplication,0x6977B86C,0xC685,0x4D3B,0xB0,0x97,0x2C,0x83,0x9A,0xCA,0xF8,0x17);


MIDL_DEFINE_GUID(IID, IID_IAcadTextStyles,0xD7185BEE,0x0673,0x4390,0x8E,0x49,0x54,0xCB,0xD9,0x9A,0xF9,0xF4);


MIDL_DEFINE_GUID(IID, IID_IAcadTextStyle,0x962B049E,0xD7B2,0x4E9C,0xAE,0x42,0xD0,0xC3,0x37,0xB9,0xEA,0x85);


MIDL_DEFINE_GUID(IID, IID_IAcadUCSs,0xACF23DCF,0x9586,0x42EC,0xBA,0x27,0x6F,0x35,0xFC,0xFC,0x56,0x27);


MIDL_DEFINE_GUID(IID, IID_IAcadUCS,0xEF447A30,0x90A9,0x4682,0x97,0x27,0x4D,0xF7,0x33,0xDE,0xA3,0x4B);


MIDL_DEFINE_GUID(IID, IID_IAcadViews,0xC24EB33E,0xA921,0x4B32,0x98,0xB2,0x6B,0xF6,0x36,0xD4,0x47,0xD3);


MIDL_DEFINE_GUID(IID, IID_IAcadViewports,0x74B0D1E2,0xA5B6,0x4ABC,0xB4,0xE9,0x4C,0x95,0xE4,0xF6,0xF1,0xBA);


MIDL_DEFINE_GUID(IID, IID_IAcadViewport,0x66CF992D,0x9F5A,0x4471,0x93,0xD1,0x3F,0x46,0xBE,0x6A,0xF8,0xEE);


MIDL_DEFINE_GUID(IID, IID_IAcadLayouts,0x81F9CAFF,0xDA8F,0x471A,0xB1,0x80,0x09,0xF8,0xF4,0xF3,0x40,0x9A);


MIDL_DEFINE_GUID(IID, IID_IAcadPlotConfigurations,0xAB24E034,0xD88F,0x4434,0xA4,0x78,0x7C,0x25,0x59,0xFC,0x3F,0xBD);


MIDL_DEFINE_GUID(IID, IID_IAcadDatabasePreferences,0x040AD8B5,0xA3D8,0x4B21,0xA7,0xE3,0x84,0x3D,0xD1,0x30,0xCE,0x44);


MIDL_DEFINE_GUID(IID, IID_IAcadSummaryInfo,0xFFB903E7,0xC9F9,0x4BA5,0xB3,0xB9,0x7A,0x2E,0x2F,0x7D,0x64,0xB7);


MIDL_DEFINE_GUID(IID, IID_IAcadSectionManager,0xBD458E9E,0xCB9A,0x4A95,0x91,0xF1,0xFA,0x5A,0x8B,0xF2,0x2E,0x78);


MIDL_DEFINE_GUID(IID, IID_IAcadMaterials,0xCE9157CB,0x3F94,0x430E,0xB9,0x9C,0x76,0x93,0x53,0x0D,0x48,0x00);


MIDL_DEFINE_GUID(IID, IID_IAcadMaterial,0xF1546217,0xFAA4,0x4886,0xBD,0xB7,0x1A,0xF0,0xA5,0xCE,0x25,0x23);


MIDL_DEFINE_GUID(IID, IID_IAcadSectionTypeSettings2,0xBCBC187F,0x55A5,0x4E7A,0x86,0x88,0x9B,0xDF,0x6E,0x79,0x16,0x67);


MIDL_DEFINE_GUID(IID, IID_IAcadDynamicBlockReferenceProperty,0xBAF75EA6,0x3EBF,0x4BB1,0xA2,0xD9,0x1D,0xC9,0x75,0x2A,0x60,0xA5);


MIDL_DEFINE_GUID(IID, IID_IAcadObjectEvents,0xE81DDF0C,0x3266,0x4AB3,0xAF,0x44,0x60,0x74,0xB2,0x32,0xD3,0x72);


MIDL_DEFINE_GUID(IID, IID_IAcadSortentsTable,0x2AF2C4FE,0x87BE,0x4202,0xB5,0x1D,0x9B,0x35,0x74,0xA6,0xD4,0xC8);


MIDL_DEFINE_GUID(IID, IID_IAcadIdPair,0x81E6EAEF,0xBEED,0x4078,0x9A,0xEE,0x56,0x99,0x1B,0x86,0x0E,0x63);


MIDL_DEFINE_GUID(IID, IID_IAcadTableStyle,0x55B3AF25,0x0342,0x4F52,0xA0,0x7A,0xF7,0xCF,0xE9,0x4A,0x34,0xB8);


MIDL_DEFINE_GUID(IID, IID_IAcadMLeaderStyle,0xFD3F6BE2,0x18E3,0x4239,0x94,0x6B,0x15,0x3F,0x58,0x0E,0xBB,0x04);


MIDL_DEFINE_GUID(IID, IID_IAcadShadowDisplay,0xF008567A,0x45E6,0x46A1,0x85,0x6B,0xF3,0xCC,0xBC,0x31,0xA8,0x6E);


MIDL_DEFINE_GUID(IID, IID_IAcadAttributeReference,0x960C6317,0xCE27,0x4C06,0x9F,0xB9,0x1E,0xE2,0x77,0x90,0x4F,0x19);


MIDL_DEFINE_GUID(IID, IID_IAcadSubEntity,0xCD3C7A3F,0x04C8,0x4DDE,0x86,0x98,0x69,0x3A,0xEA,0xD0,0xB7,0xC8);


MIDL_DEFINE_GUID(IID, IID_IAcadMLeaderLeader,0xA0ED126D,0x4F5B,0x437B,0xBF,0xCA,0xD8,0x5A,0x6C,0x3B,0x6A,0x08);


MIDL_DEFINE_GUID(IID, IID_IAcadComparedReference,0x68BB798E,0xDC89,0x469E,0x9B,0xB8,0xE0,0x71,0xE6,0x17,0x9E,0x33);


MIDL_DEFINE_GUID(IID, IID_IAcadOle,0x1161547D,0x2DFD,0x418F,0x9B,0xB0,0x85,0x14,0xED,0xB0,0xB9,0xAA);


MIDL_DEFINE_GUID(IID, IID_IAcadHelix,0xD35E41A8,0x5594,0x4005,0xA4,0x91,0x53,0x8D,0x7E,0xDC,0x9B,0x4B);


MIDL_DEFINE_GUID(IID, IID_IAcadSurface,0x398A0E3D,0x7BBC,0x42C8,0x94,0xD6,0xC8,0xCF,0x8F,0xE9,0xEE,0xD3);


MIDL_DEFINE_GUID(IID, IID_IAcadPlaneSurface,0x884438B1,0x43A6,0x496D,0xA0,0x0C,0xA7,0xDE,0xA9,0x09,0xAD,0x0C);


MIDL_DEFINE_GUID(IID, IID_IAcadExtrudedSurface,0x8D72B17E,0x7DE8,0x44F6,0xA4,0x8F,0x71,0x3B,0x18,0x2C,0xC3,0x0D);


MIDL_DEFINE_GUID(IID, IID_IAcadRevolvedSurface,0xAABA2A36,0xA0F3,0x4BB1,0x92,0x3D,0xA8,0x61,0xA6,0xFB,0x13,0xF7);


MIDL_DEFINE_GUID(IID, IID_IAcadSweptSurface,0x5BAD0CF6,0x6559,0x4788,0x85,0x75,0x14,0xF4,0x76,0x34,0x4A,0x0A);


MIDL_DEFINE_GUID(IID, IID_IAcadLoftedSurface,0x94929706,0x84AD,0x4C74,0xA4,0x14,0x06,0xFC,0x72,0x3B,0xE2,0x95);


MIDL_DEFINE_GUID(IID, IID_IAcadSection2,0xD167184A,0x3622,0x466F,0x88,0x9A,0x0F,0x73,0x4D,0xBD,0x7E,0x33);


MIDL_DEFINE_GUID(IID, IID_IAcadUnderlay,0x64C7028E,0xD605,0x4827,0x99,0x3D,0xE1,0x8E,0x8E,0x72,0x12,0x37);


MIDL_DEFINE_GUID(IID, IID_IAcadDwfUnderlay,0x82D7A439,0x75E7,0x4474,0x8F,0x4C,0x46,0x69,0xC7,0xD5,0x61,0x50);


MIDL_DEFINE_GUID(IID, IID_IAcadSubEntSolidFace,0xB8E400B7,0x84E6,0x47FF,0x81,0xC8,0x57,0xDD,0x7A,0xC4,0xFE,0xFB);


MIDL_DEFINE_GUID(IID, IID_IAcadSubEntSolidEdge,0xD1F7666D,0x8E5A,0x4B81,0xAC,0x84,0xB7,0x73,0x38,0x63,0xD8,0xFF);


MIDL_DEFINE_GUID(IID, IID_IAcadSubEntSolidVertex,0xB26BD609,0x9666,0x4ABE,0x82,0xF8,0x43,0x80,0x8A,0x82,0xCF,0xFB);


MIDL_DEFINE_GUID(IID, IID_IAcadSubEntSolidNode,0x1ECBED52,0xAC3B,0x424F,0xA5,0x7C,0x9A,0x1C,0x0C,0x86,0x30,0x86);


MIDL_DEFINE_GUID(IID, IID_IAcadWipeout,0xFF702054,0xE09A,0x4FB8,0xA7,0x4B,0x8A,0x71,0x95,0xFE,0x73,0x8E);


MIDL_DEFINE_GUID(IID, IID_IAcadSubDMesh,0x26421902,0x0235,0x4D52,0x9C,0x15,0x8E,0xAB,0x1D,0x6F,0x45,0x4C);


MIDL_DEFINE_GUID(IID, IID_IAcadSubDMeshFace,0xF7C9455F,0x283D,0x46A5,0x9A,0xF1,0x06,0xF8,0x51,0xB3,0x06,0xF6);


MIDL_DEFINE_GUID(IID, IID_IAcadSubDMeshEdge,0x77BAEBC7,0xBC63,0x430D,0x85,0xF7,0xCD,0x66,0x70,0x7D,0xBB,0x0B);


MIDL_DEFINE_GUID(IID, IID_IAcadSubDMeshVertex,0xCFC5A429,0x6AB8,0x4F55,0x81,0x2B,0x87,0x9E,0x21,0x79,0xD6,0x36);


MIDL_DEFINE_GUID(IID, IID_IAcadNurbSurface,0xE8B4CB77,0xBCE7,0x44B6,0x81,0xF5,0xD9,0xE4,0xA4,0x6D,0xF0,0x28);


MIDL_DEFINE_GUID(IID, IID_IAcadGeoPositionMarker,0x6AA0F292,0x84F3,0x42CB,0xA1,0x46,0xF0,0xD2,0x13,0x4D,0xEB,0x33);


MIDL_DEFINE_GUID(IID, IID_IAcadGeomapImage,0xB5DFB730,0x175B,0x4FF1,0xA9,0x3E,0x9F,0xBC,0x0F,0xBA,0xFC,0x93);


MIDL_DEFINE_GUID(IID, IID_IAcadPointCloud,0x2D9BB85A,0x8A6B,0x4C85,0xB0,0xBD,0xD4,0xC0,0x78,0xBC,0x6D,0x0A);


MIDL_DEFINE_GUID(IID, IID_IAcadPointCloudEx,0x01AD7F44,0xA473,0x4A2B,0x89,0xFF,0xF3,0xE9,0xFF,0xDE,0xF2,0x53);


MIDL_DEFINE_GUID(IID, IID_IAcadPointCloudEx2,0x82FE2759,0x560D,0x4A84,0x97,0x4D,0x49,0x56,0xA2,0x76,0xB6,0xC1);


MIDL_DEFINE_GUID(IID, IID_IAcadSecurityParams,0x9975FDCA,0xB7EE,0x44EF,0x88,0xD9,0xD9,0x3B,0xDB,0xD8,0x91,0x58);


MIDL_DEFINE_GUID(IID, IID_IAcadLayerStateManager,0x51A9812A,0x88F3,0x48FD,0x91,0x86,0x45,0x06,0x29,0x29,0x69,0xEA);


MIDL_DEFINE_GUID(IID, IID_IAxDbDocumentEvents,0xA6970944,0x68DD,0x42D9,0x98,0xC6,0x7C,0x7C,0x57,0x01,0x91,0x8F);


MIDL_DEFINE_GUID(IID, IID_IAxDbDocument,0x3A8004FC,0x9456,0x4D9E,0x8A,0x07,0xE1,0xB5,0x96,0x55,0x67,0x67);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadHyperlink,0xA51C6962,0xE574,0x41E3,0x8E,0xA1,0x6D,0xDD,0xBC,0x5A,0x96,0x1F);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDynamicBlockReferenceProperty,0x15867C64,0xB299,0x4AFA,0x83,0x16,0x8A,0xCE,0xA2,0x40,0xC3,0x9A);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadAcCmColor,0xE95C802A,0xD337,0x4DAC,0x83,0x08,0x43,0x1B,0xF7,0x33,0xB0,0xAD);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadObject,0xB692F36A,0x2AA8,0x4517,0x8B,0x36,0x78,0xD2,0xF1,0x63,0x56,0x66);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadXRecord,0x065BD37A,0x6643,0x4087,0xB0,0xA9,0x47,0x88,0x78,0xB6,0x12,0x69);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSortentsTable,0x4742381A,0xDE3B,0x47C0,0x96,0xD6,0x6C,0x49,0x5E,0x7C,0xE0,0x2B);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimStyle,0x493519C3,0x5C62,0x4E00,0xA9,0x27,0x13,0x1B,0xDA,0x0D,0x0D,0x1F);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLayer,0x9654FDDF,0xE6DB,0x44BF,0x9E,0xBD,0xF5,0xF2,0x28,0x65,0xB1,0xD0);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLineType,0x010B289B,0xDA6B,0x46BF,0xB4,0xC9,0xA5,0xC2,0xAE,0xD1,0x12,0x91);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadMaterial,0x96C2A3B9,0xE6F4,0x4EAD,0x88,0x23,0xF5,0xD8,0xDC,0xF7,0x7C,0x84);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadRegisteredApplication,0x29507959,0x3771,0x419C,0x9E,0x15,0xE1,0xAA,0x59,0xA5,0x4A,0x67);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadTextStyle,0x4E230566,0x634E,0x4E64,0x9C,0xC2,0x4C,0x59,0xA3,0x07,0xA0,0x4A);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadUCS,0x26101609,0xCE38,0x46D3,0xBE,0x49,0x2A,0x09,0x20,0x41,0x5C,0x84);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadView,0x68BFC83B,0x3081,0x4B8F,0x91,0x51,0xBF,0xFE,0x9C,0x1C,0x85,0x9E);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadViewport,0x25F44B30,0xC54E,0x4E58,0x97,0x5A,0x22,0xB8,0x54,0xEA,0x94,0xB5);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadGroup,0x42319570,0xE7C2,0x4FAC,0x8C,0x5C,0xA9,0x80,0x99,0xB6,0x4E,0x71);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPlotConfiguration,0x504CBBC1,0x09C0,0x4EA5,0xBE,0xD4,0xD4,0xCA,0x2E,0x4E,0x66,0x7C);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLayout,0xC07E7085,0x4BBD,0x4EB5,0xB2,0xC9,0x8E,0x19,0xBC,0xE6,0x8A,0x6F);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadIdPair,0x754E976B,0x0B92,0x46AD,0xB1,0xF8,0xF9,0xE6,0x70,0xC1,0x72,0x14);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadTableStyle,0xDEF00114,0xFF10,0x470E,0x8F,0x5A,0x51,0x69,0x01,0x27,0xAD,0x22);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSectionSettings,0x0A60ABBB,0x99BE,0x471A,0x9A,0xD1,0x5D,0x1A,0x97,0x37,0x0F,0xB9);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSectionTypeSettings,0xB94E3B27,0x1CE5,0x46E2,0x90,0xD4,0x26,0x44,0x3A,0xEC,0x82,0x01);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadMLeaderStyle,0xD96597EB,0x5775,0x48BC,0xAC,0x8A,0x28,0x89,0x90,0x91,0x8A,0x68);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadHyperlinks,0x9DEA828D,0x097C,0x4F5C,0xBF,0x7C,0xF7,0xA5,0x11,0x18,0x57,0x8C);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDictionary,0x1E76236E,0xB5A7,0x4EEF,0xA0,0x92,0xA7,0xFD,0xAF,0x34,0x2C,0x96);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLayers,0x5D5387E5,0xEE2B,0x442E,0x95,0xEC,0x9B,0xE7,0xA3,0xA4,0xF7,0x2A);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimStyles,0x53C82EC1,0x626A,0x4A90,0x9B,0xCE,0xD5,0xE3,0xC0,0xD0,0xB0,0xF5);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDictionaries,0x592A7C8B,0xA5DC,0x4817,0xB8,0x18,0xFA,0x33,0xEA,0xC2,0x49,0xA5);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLineTypes,0xA43D153A,0x2036,0x4568,0xAA,0x54,0xE0,0x91,0x38,0xA5,0x62,0x93);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadMaterials,0xC3606413,0x0EC2,0x4FA6,0x8F,0xCB,0x7E,0x07,0x89,0xA4,0x7C,0x67);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadTextStyles,0x754CA1B4,0xAE09,0x42D1,0x9F,0xAE,0x18,0xD3,0x6D,0x02,0xD0,0xFD);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadUCSs,0x01E01A48,0x5FF5,0x4289,0x9E,0x53,0x3B,0xF8,0x80,0x89,0xF4,0xFE);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadRegisteredApplications,0x5724C4A1,0xD14D,0x4BF4,0x84,0xF3,0x61,0x9B,0x23,0xAB,0x31,0x80);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadViews,0x4F7C0904,0x2D12,0x48BB,0x98,0xF3,0x91,0x54,0xE5,0x7D,0x1F,0x76);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadViewports,0xE5BC9B7A,0xCBE4,0x4F1E,0xBF,0x6B,0x7D,0x4C,0xC7,0x4B,0xB3,0xD0);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadGroups,0x3EC14BF8,0x2E66,0x431E,0x9C,0x82,0x9E,0x6C,0x1A,0x58,0xC3,0x01);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadBlocks,0x9D99781C,0x0164,0x4F3B,0x8C,0x90,0x40,0xD8,0xF5,0x07,0x2E,0x31);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLayouts,0x0BBBC99D,0x35F1,0x4110,0xAE,0xF5,0x43,0xBE,0x8E,0xD2,0x1B,0x4E);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPlotConfigurations,0xD2FE5769,0xD087,0x415B,0x95,0x62,0x38,0x8A,0xE3,0xF8,0xE1,0xC4);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadEntity,0x7EBA367D,0x9203,0x4231,0xAE,0x28,0xB5,0x5E,0xD6,0xFB,0x0D,0x07);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadRasterImage,0x895C197F,0xF1CD,0x4F17,0xBC,0x61,0x4D,0x47,0x7D,0x11,0x11,0x75);


MIDL_DEFINE_GUID(CLSID, CLSID_Acad3DFace,0x300360B1,0xAD02,0x44A5,0x92,0x44,0x77,0xA8,0xD4,0xD4,0xF0,0x10);


MIDL_DEFINE_GUID(CLSID, CLSID_Acad3DPolyline,0x26F2AB32,0x0602,0x4430,0x84,0xA4,0xDA,0xE2,0x5A,0x7E,0x1B,0xF1);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadRegion,0x5421FD0F,0xD90E,0x43F7,0x98,0x27,0x0B,0xA6,0xFD,0xDE,0xF2,0x4A);


MIDL_DEFINE_GUID(CLSID, CLSID_Acad3DSolid,0xB88042CB,0xA3FB,0x499A,0xB5,0x4C,0xDF,0xCC,0xA1,0xCD,0x7D,0x20);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadArc,0xF0948C0D,0x038B,0x4C5A,0xAA,0x12,0xE8,0x6B,0x71,0xE5,0x54,0x0A);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadAttribute,0xB3B6FCCA,0xDFAF,0x4CDF,0x86,0x8B,0x5C,0x6C,0xAD,0xE8,0x3B,0xB8);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadAttributeReference,0x5BC35321,0x0A9A,0x4459,0xB5,0xBC,0x95,0x8B,0x91,0x0B,0xFB,0x1F);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadBlockReference,0x91DFF2B2,0xA08F,0x4B18,0x95,0x59,0x77,0xA2,0x21,0x9D,0x04,0x18);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadCircle,0x19E5F74E,0xDE82,0x4EA2,0xBD,0x1A,0x4E,0xA7,0x22,0x0A,0xDC,0x9B);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadEllipse,0xE374E463,0xB131,0x41ED,0xAF,0x18,0xAA,0xF3,0xE8,0xDF,0x94,0x0E);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadHatch,0x7AEB582E,0x74B3,0x44D8,0x8E,0x65,0x23,0x8D,0xF5,0x5C,0x85,0x7C);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLeader,0x740C1F56,0x2211,0x4267,0x86,0xCF,0x10,0xA9,0xFE,0x8A,0xDA,0xF7);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadMLeaderLeader,0xE2EAC177,0x1E39,0x4F70,0xAB,0x7A,0x9F,0x9E,0xAE,0x5F,0x23,0xC0);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadMLeader,0xFC4788C8,0xE741,0x4D95,0xBB,0x3D,0x23,0x16,0x93,0x6E,0x1F,0x84);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLWPolyline,0xFA0CDD61,0x23BC,0x40C6,0xA6,0x74,0x2E,0x98,0xF3,0xBC,0xF7,0x21);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLine,0x2734EECC,0x24D2,0x4A78,0xA7,0x26,0xD4,0x9E,0xAC,0x4B,0xD2,0xE9);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadMText,0x0EE67552,0x693C,0x4E55,0xB0,0xB0,0xA8,0x91,0xD2,0x18,0xF6,0x68);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPoint,0x4D2E4505,0x8BEA,0x4389,0x80,0x4F,0x94,0x2D,0xE0,0x5D,0xF3,0x81);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPolyline,0x17BA9269,0x595F,0x4848,0x9A,0x8C,0x1E,0x71,0xA4,0x93,0x05,0x1B);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPolygonMesh,0xEECA7188,0x7717,0x42DF,0xAD,0x5D,0x68,0xAD,0x96,0x97,0x79,0xD2);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadRay,0x2F8E58ED,0xFDEC,0x4439,0x93,0x05,0xAD,0xD4,0x23,0x12,0x24,0x02);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadShape,0x4F1BBA75,0x0063,0x4AA3,0x8D,0xA5,0x4D,0xB6,0x62,0x38,0x05,0x4E);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSolid,0xB5B83FBB,0xF413,0x49E9,0x87,0x90,0x44,0x7F,0x61,0x44,0x58,0x31);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSpline,0xEFFE46AE,0x9279,0x4AD1,0x8C,0x56,0x49,0xE3,0x8A,0x9E,0x0F,0xDB);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadText,0x0987002C,0x8D7E,0x4009,0xBA,0xBE,0xED,0xC4,0x31,0xC9,0xE4,0xB5);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadTolerance,0xC546D5B9,0x0FBB,0x4CE3,0xA7,0x1A,0x72,0x82,0x51,0xD1,0x35,0xFF);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadTrace,0xD06C736D,0xFA2D,0x4E8C,0xB5,0xD4,0x64,0x97,0x30,0x3F,0x50,0x25);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadXline,0x073E9BEC,0x4E14,0x4570,0x83,0xDF,0x5A,0xBC,0x35,0xF3,0xEB,0x25);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPViewport,0x053890B9,0x6849,0x4785,0xA9,0x2F,0xC4,0xF9,0x20,0xBC,0xE8,0xEB);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadMInsertBlock,0xC798092E,0xF975,0x49F2,0x9B,0xB3,0x73,0x73,0xA2,0xE2,0x56,0x33);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPolyfaceMesh,0x66C465AA,0x0C7B,0x46F6,0x97,0xF2,0x01,0x82,0x43,0xDD,0x22,0x45);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadMLine,0xC573E9DF,0xB7D6,0x4DB3,0x9D,0xD5,0x19,0x7F,0xC1,0xC9,0x5D,0x2F);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadExternalReference,0x0CFA20DB,0xB5E8,0x41A8,0x86,0x01,0xC9,0x1D,0x99,0x2C,0x29,0xD5);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadComparedReference,0xBA625FD2,0xED13,0x491F,0x91,0xA9,0x4F,0x67,0x22,0x87,0x3C,0xF5);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadTable,0x272BC87B,0x199F,0x439A,0x81,0x80,0x20,0xBB,0x9B,0xE5,0x2F,0xFF);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadOle,0xFA49020A,0x9E3F,0x433F,0x98,0x83,0xC2,0x02,0x3C,0x4E,0x77,0x94);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadHelix,0x12EAE887,0x63FA,0x4D13,0xB2,0xE5,0xBF,0x49,0x92,0xFF,0x3E,0xBC);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSurface,0x2560DD39,0xA11A,0x476F,0xBC,0x80,0x00,0x3E,0xC4,0x1E,0x98,0xCB);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPlaneSurface,0xDDC1E66E,0x5767,0x4D72,0xBF,0x64,0x67,0x72,0xBE,0x3E,0x65,0xBF);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadExtrudedSurface,0x978345AD,0x1683,0x4D3E,0xAA,0x6A,0xC2,0x87,0x13,0xA8,0x79,0xC7);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadRevolvedSurface,0xF12B5B7E,0x978D,0x4D77,0xA2,0xB2,0xC2,0xC8,0x33,0x1E,0x01,0x6F);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSweptSurface,0x13568A0F,0x7608,0x47A8,0xAA,0xA8,0xDF,0xD6,0x49,0xF2,0x5E,0xF5);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLoftedSurface,0x882A6BD7,0xD7CC,0x46F9,0xB1,0x43,0x92,0x87,0x3A,0x5A,0xDF,0x73);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSection,0x01B39C1C,0x8B0D,0x4ABF,0x95,0xA8,0xAA,0x22,0x32,0x09,0x92,0x7A);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSectionManager,0x47E3FFE2,0xFB4D,0x4AD4,0x88,0x49,0x3A,0x47,0xE6,0xF8,0x90,0x81);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDwfUnderlay,0x5E20A4F2,0x88AB,0x45A0,0x98,0xA9,0x51,0xAF,0xD9,0xD2,0x72,0x58);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDgnUnderlay,0xD2308D2C,0x02D4,0x4042,0x9B,0xC4,0xCB,0xC0,0x8C,0x34,0x68,0x27);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPdfUnderlay,0x63B5540D,0xA608,0x44EB,0x89,0x98,0x00,0xD7,0xA1,0x2B,0x17,0xB6);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSubEntity,0x5DC740C3,0x2FBD,0x433F,0x88,0xB7,0x8E,0x5A,0x63,0xBB,0xDF,0x7C);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSubEntSolidFace,0xCAE09FE3,0x107E,0x422C,0xA5,0x51,0x57,0xA9,0xCC,0x0C,0xC5,0xE5);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSubEntSolidEdge,0x7955BF86,0x95AA,0x4F10,0x97,0x0E,0xDE,0x06,0x69,0x91,0xE4,0xF1);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSubEntSolidVertex,0x44495642,0xBEDB,0x4942,0x95,0xC3,0x32,0x98,0x78,0xC6,0x54,0x1E);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSubEntSolidNode,0x9EFE3080,0x821C,0x4502,0x92,0xA3,0xD5,0x1A,0xC1,0x8B,0x7C,0xF2);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadWipeout,0x173F7328,0x7D8B,0x490D,0x9E,0xD9,0x2E,0xD4,0x00,0x4A,0xC4,0xD2);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSubDMesh,0x3B5068D3,0x6A6E,0x4EEF,0x82,0xA4,0xFC,0x4C,0x76,0x86,0x7D,0x81);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSubDMeshFace,0xB6D8E532,0x3469,0x48DB,0xBE,0x3F,0x9C,0xBB,0xD3,0xE8,0x0C,0xEC);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSubDMeshEdge,0xB49AB0CA,0xC1D8,0x4746,0xA4,0x0B,0x11,0xE2,0x22,0x11,0xBA,0x08);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSubDMeshVertex,0xE506F59A,0x27C1,0x4E72,0xAA,0xB3,0xF1,0xEA,0x23,0x76,0x26,0x88);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadNurbSurface,0x3B8DFF63,0x109C,0x47CA,0x84,0xA0,0x0B,0x1E,0x37,0xBB,0x2F,0x79);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadGeoPositionMarker,0x830C2DF0,0xD0BB,0x4336,0x8C,0xCB,0x68,0xA5,0xA4,0x00,0xF9,0xDE);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadGeomapImage,0xFEEF4C72,0x1350,0x4427,0xB0,0x36,0xAA,0xFF,0x1E,0xEF,0x80,0x2C);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimension,0x1266FC21,0xB3F3,0x4436,0xA9,0xE7,0x5E,0xB4,0xF5,0xFB,0x85,0xA4);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimAligned,0x2EF9A3C0,0x8F64,0x479C,0x90,0x17,0x30,0xBD,0xCC,0x24,0x82,0xB2);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimAngular,0x777EB235,0x642D,0x4CE4,0xA2,0x5A,0xF3,0x8B,0x49,0xD3,0x67,0x1A);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimDiametric,0xE9762ECE,0x8D10,0x49D9,0x95,0x1A,0xA4,0x35,0x74,0xFD,0x21,0x1A);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimOrdinate,0xCD9B4F83,0x3308,0x455D,0x9C,0xCF,0x5F,0xC1,0xF3,0x9C,0x1E,0x8D);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimRadial,0xD27A8C19,0x613F,0x4E1B,0xA2,0x49,0xBC,0x64,0x89,0xAD,0x23,0x31);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimRotated,0xFD8D40F9,0x3538,0x44A7,0x91,0xC2,0x12,0x79,0xED,0x5C,0x76,0x01);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDim3PointAngular,0x5BE745DA,0x500B,0x4592,0x95,0x4D,0x7C,0x74,0xE8,0x4C,0x9F,0xA3);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimArcLength,0x004C2D76,0x82D1,0x4139,0x80,0x6C,0xF1,0x19,0x67,0x6A,0x5F,0x46);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimRadialLarge,0x47B03685,0xC448,0x4079,0x9A,0x0D,0xE8,0xC1,0x1F,0xC5,0xCE,0x33);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadBlock,0x4D58BDA1,0x16F4,0x4680,0xBC,0x28,0x49,0x16,0x8F,0x89,0x41,0x20);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadModelSpace,0xF7A3B8B7,0x9775,0x478D,0xA6,0xFB,0xF5,0xE0,0x7E,0x61,0x4F,0x96);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPaperSpace,0xA6D908B2,0x2365,0x42E5,0x8A,0x5A,0xB2,0x97,0x6C,0xB8,0xC0,0x28);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPointCloud,0x1448B9B5,0x0257,0x4D56,0xA6,0xBE,0x8F,0x46,0xCE,0xDE,0x75,0x64);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPointCloudEx,0xD7B0BCC9,0xE0EF,0x482C,0x8C,0x9A,0xC2,0x97,0x45,0xB8,0x32,0xB1);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSummaryInfo,0x05B0BF87,0xFCB4,0x43DD,0x8A,0x75,0x72,0xE7,0x3D,0x3F,0x48,0xCE);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDatabasePreferences,0x592616FA,0xA3C8,0x41F0,0xB3,0xD0,0x92,0xEC,0x14,0x6E,0x5B,0xB1);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDatabase,0x456D6679,0x7558,0x4694,0x85,0xCD,0x69,0xBB,0xF8,0x38,0xDB,0xA9);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSecurityParams,0x84FAFBF9,0x7B3E,0x4FD5,0x9E,0x82,0x07,0x00,0x80,0xF0,0x0C,0xDC);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLayerStateManager,0x84F91629,0x65EB,0x476C,0xB7,0xF4,0xAC,0xF4,0x43,0x85,0x69,0xE9);


MIDL_DEFINE_GUID(CLSID, CLSID_AxDbDocument,0xB35829A7,0x07D2,0x49E7,0xB8,0x48,0xD9,0x22,0xC3,0xB7,0x2B,0x05);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif




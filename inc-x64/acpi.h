

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __acpi_h__
#define __acpi_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DECLSPEC_XFGVIRT
#if _CONTROL_FLOW_GUARD_XFG
#define DECLSPEC_XFGVIRT(base, func) __declspec(xfg_virtual(base, func))
#else
#define DECLSPEC_XFGVIRT(base, func)
#endif
#endif

/* Forward Declarations */ 

#ifndef __IAcPiPropertyInspector_FWD_DEFINED__
#define __IAcPiPropertyInspector_FWD_DEFINED__
typedef interface IAcPiPropertyInspector IAcPiPropertyInspector;

#endif 	/* __IAcPiPropertyInspector_FWD_DEFINED__ */


#ifndef __IAcPiPropertyInspector2_FWD_DEFINED__
#define __IAcPiPropertyInspector2_FWD_DEFINED__
typedef interface IAcPiPropertyInspector2 IAcPiPropertyInspector2;

#endif 	/* __IAcPiPropertyInspector2_FWD_DEFINED__ */


#ifndef __IAcPiPropertyInspectorInputEventSink_FWD_DEFINED__
#define __IAcPiPropertyInspectorInputEventSink_FWD_DEFINED__
typedef interface IAcPiPropertyInspectorInputEventSink IAcPiPropertyInspectorInputEventSink;

#endif 	/* __IAcPiPropertyInspectorInputEventSink_FWD_DEFINED__ */


#ifndef __IAcPiPropertyIdentifier_FWD_DEFINED__
#define __IAcPiPropertyIdentifier_FWD_DEFINED__
typedef interface IAcPiPropertyIdentifier IAcPiPropertyIdentifier;

#endif 	/* __IAcPiPropertyIdentifier_FWD_DEFINED__ */


#ifndef __IAcPiCommandButton_FWD_DEFINED__
#define __IAcPiCommandButton_FWD_DEFINED__
typedef interface IAcPiCommandButton IAcPiCommandButton;

#endif 	/* __IAcPiCommandButton_FWD_DEFINED__ */


#ifndef __IAcPiPropertyDisplay_FWD_DEFINED__
#define __IAcPiPropertyDisplay_FWD_DEFINED__
typedef interface IAcPiPropertyDisplay IAcPiPropertyDisplay;

#endif 	/* __IAcPiPropertyDisplay_FWD_DEFINED__ */


#ifndef __AcPiPropertyInspector_FWD_DEFINED__
#define __AcPiPropertyInspector_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPiPropertyInspector AcPiPropertyInspector;
#else
typedef struct AcPiPropertyInspector AcPiPropertyInspector;
#endif /* __cplusplus */

#endif 	/* __AcPiPropertyInspector_FWD_DEFINED__ */


#ifndef __AcPiPropertyIdentifier_FWD_DEFINED__
#define __AcPiPropertyIdentifier_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPiPropertyIdentifier AcPiPropertyIdentifier;
#else
typedef struct AcPiPropertyIdentifier AcPiPropertyIdentifier;
#endif /* __cplusplus */

#endif 	/* __AcPiPropertyIdentifier_FWD_DEFINED__ */


#ifndef __IAcPiPropertyUnspecified_FWD_DEFINED__
#define __IAcPiPropertyUnspecified_FWD_DEFINED__
typedef interface IAcPiPropertyUnspecified IAcPiPropertyUnspecified;

#endif 	/* __IAcPiPropertyUnspecified_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __ACPILib_LIBRARY_DEFINED__
#define __ACPILib_LIBRARY_DEFINED__

/* library ACPILib */
/* [helpstring][version][uuid] */ 







typedef /* [uuid] */  DECLSPEC_UUID("AAC0030E-A4F0-4393-B56B-CD7C950AF8E4") 
enum AcPiColorIndex
    {
        ACPI_COLOR_TOP	= 0,
        ACPI_COLOR_CATEGORY	= 1,
        ACPI_COLOR_ITEM	= 2,
        ACPI_COLOR_BORDER	= 3,
        ACPI_COLOR_BORDER_ITEM	= 4,
        ACPI_COLOR_TEXT_TOP	= 5,
        ACPI_COLOR_TEXT_CATEGORY	= 6,
        ACPI_COLOR_TEXT_ITEM	= 7,
        ACPI_COLOR_FORE_HIGHLIGHT	= 8,
        ACPI_COLOR_BACK_HIGHLIGHT	= 9,
        ACPI_COLOR_3DSHADOW	= 10,
        ACPI_COLOR_BACK_CONTROL	= 11,
        ACPI_COLOR_SCROLLBACKGROUND	= 12,
        ACPI_COLOR_SCROLLTHUMB	= 13,
        ACPI_COLOR_SCROLLARROW	= 14,
        ACPI_COLOR_DOUBLECHEVRON1	= 15,
        ACPI_COLOR_DOUBLECHEVRON2	= 16,
        ACPI_COLOR_SINGLECHEVRON	= 17,
        ACPI_COLOR_TOP_GRADIENT1	= 18,
        ACPI_COLOR_TOP_GRADIENT2	= 19,
        ACPI_COLOR_TOP_CLOSED_OUTER_BORDER	= 20,
        ACPI_COLOR_TOP_OPEN_OUTER_BORDER	= 21,
        ACPI_COLOR_TOP_INNER_BORDER	= 22,
        ACPI_COLOR_SCROLL_BACKGROUNDBORDER	= 23,
        ACPI_COLOR_SCROLL_BACKGROUNDGRADIENT1	= 24,
        ACPI_COLOR_SCROLL_BACKGROUNDGRADIENT2	= 25,
        ACPI_COLOR_SCROLL_SLIDER_INACTIVE	= 26,
        ACPI_COLOR_SCROLL_SLIDER_ACTIVE_OUTERBORDER	= 27,
        ACPI_COLOR_SCROLL_SLIDER_ACTIVE_OUTERGRADIENT1	= 28,
        ACPI_COLOR_SCROLL_SLIDER_ACTIVE_OUTERGRADIENT2	= 29,
        ACPI_COLOR_SCROLL_SLIDER_ACTIVE_OUTERGRADIENT3	= 30,
        ACPI_COLOR_SCROLL_SLIDER_ACTIVE_OUTERGRADIENT4	= 31,
        ACPI_COLOR_SCROLL_SLIDER_ACTIVE_INNERGRADIENT1	= 32,
        ACPI_COLOR_SCROLL_SLIDER_ACTIVE_INNERGRADIENT2	= 33,
        ACPI_COLOR_TEXT_LABEL	= 34,
        ACPI_COLOR_CELL_HIGHLIGHT	= 35,
        ACPI_COLOR_DISABLED_TEXT_ITEM	= 36
    } 	AcPiColorIndex;


EXTERN_C const IID LIBID_ACPILib;

#ifndef __IAcPiPropertyInspector_INTERFACE_DEFINED__
#define __IAcPiPropertyInspector_INTERFACE_DEFINED__

/* interface IAcPiPropertyInspector */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcPiPropertyInspector;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C99EBB61-90C8-4768-ADD1-8F5AF989CE2C")
    IAcPiPropertyInspector : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Reset( 
            /* [in] */ VARIANT *pObjUnkArray,
            /* [in] */ VARIANT *pDynUnkArray,
            /* [in] */ unsigned long dwFlags) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Style( 
            /* [retval][out] */ unsigned long *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Style( 
            /* [in] */ unsigned long pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_KeepFocus( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetColor( 
            /* [in] */ AcPiColorIndex index,
            /* [in] */ /* external definition not present */ OLE_COLOR color) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetColor( 
            /* [in] */ AcPiColorIndex __MIDL__IAcPiPropertyInspector0000,
            /* [retval][out] */ /* external definition not present */ OLE_COLOR *pColor) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Font( 
            /* [retval][out] */ IUnknown **pIFont) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Font( 
            /* [in] */ IUnknown *pIFont) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_BoldFont( 
            /* [retval][out] */ IUnknown **pIFont) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_BoldFont( 
            /* [in] */ IUnknown *pIFont) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetPersistence( 
            /* [in] */ IUnknown *pINode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPersistence( 
            /* [in] */ IUnknown *pINode) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DelayRefresh( 
            /* [retval][out] */ VARIANT_BOOL *pbDelayRefresh) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DelayRefresh( 
            /* [in] */ VARIANT_BOOL pbDelayRefresh) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcPiPropertyInspectorVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcPiPropertyInspector * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcPiPropertyInspector * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcPiPropertyInspector * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcPiPropertyInspector * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcPiPropertyInspector * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcPiPropertyInspector * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcPiPropertyInspector * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyInspector, Reset)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IAcPiPropertyInspector * This,
            /* [in] */ VARIANT *pObjUnkArray,
            /* [in] */ VARIANT *pDynUnkArray,
            /* [in] */ unsigned long dwFlags);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyInspector, get_Style)
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Style )( 
            IAcPiPropertyInspector * This,
            /* [retval][out] */ unsigned long *pVal);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyInspector, put_Style)
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Style )( 
            IAcPiPropertyInspector * This,
            /* [in] */ unsigned long pVal);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyInspector, get_KeepFocus)
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_KeepFocus )( 
            IAcPiPropertyInspector * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyInspector, SetColor)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetColor )( 
            IAcPiPropertyInspector * This,
            /* [in] */ AcPiColorIndex index,
            /* [in] */ /* external definition not present */ OLE_COLOR color);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyInspector, GetColor)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetColor )( 
            IAcPiPropertyInspector * This,
            /* [in] */ AcPiColorIndex __MIDL__IAcPiPropertyInspector0000,
            /* [retval][out] */ /* external definition not present */ OLE_COLOR *pColor);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyInspector, get_Font)
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Font )( 
            IAcPiPropertyInspector * This,
            /* [retval][out] */ IUnknown **pIFont);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyInspector, put_Font)
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Font )( 
            IAcPiPropertyInspector * This,
            /* [in] */ IUnknown *pIFont);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyInspector, get_BoldFont)
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_BoldFont )( 
            IAcPiPropertyInspector * This,
            /* [retval][out] */ IUnknown **pIFont);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyInspector, put_BoldFont)
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_BoldFont )( 
            IAcPiPropertyInspector * This,
            /* [in] */ IUnknown *pIFont);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyInspector, SetPersistence)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetPersistence )( 
            IAcPiPropertyInspector * This,
            /* [in] */ IUnknown *pINode);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyInspector, GetPersistence)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPersistence )( 
            IAcPiPropertyInspector * This,
            /* [in] */ IUnknown *pINode);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyInspector, get_DelayRefresh)
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DelayRefresh )( 
            IAcPiPropertyInspector * This,
            /* [retval][out] */ VARIANT_BOOL *pbDelayRefresh);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyInspector, put_DelayRefresh)
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DelayRefresh )( 
            IAcPiPropertyInspector * This,
            /* [in] */ VARIANT_BOOL pbDelayRefresh);
        
        END_INTERFACE
    } IAcPiPropertyInspectorVtbl;

    interface IAcPiPropertyInspector
    {
        CONST_VTBL struct IAcPiPropertyInspectorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcPiPropertyInspector_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcPiPropertyInspector_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcPiPropertyInspector_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcPiPropertyInspector_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcPiPropertyInspector_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcPiPropertyInspector_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcPiPropertyInspector_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAcPiPropertyInspector_Reset(This,pObjUnkArray,pDynUnkArray,dwFlags)	\
    ( (This)->lpVtbl -> Reset(This,pObjUnkArray,pDynUnkArray,dwFlags) ) 

#define IAcPiPropertyInspector_get_Style(This,pVal)	\
    ( (This)->lpVtbl -> get_Style(This,pVal) ) 

#define IAcPiPropertyInspector_put_Style(This,pVal)	\
    ( (This)->lpVtbl -> put_Style(This,pVal) ) 

#define IAcPiPropertyInspector_get_KeepFocus(This,pVal)	\
    ( (This)->lpVtbl -> get_KeepFocus(This,pVal) ) 

#define IAcPiPropertyInspector_SetColor(This,index,color)	\
    ( (This)->lpVtbl -> SetColor(This,index,color) ) 

#define IAcPiPropertyInspector_GetColor(This,__MIDL__IAcPiPropertyInspector0000,pColor)	\
    ( (This)->lpVtbl -> GetColor(This,__MIDL__IAcPiPropertyInspector0000,pColor) ) 

#define IAcPiPropertyInspector_get_Font(This,pIFont)	\
    ( (This)->lpVtbl -> get_Font(This,pIFont) ) 

#define IAcPiPropertyInspector_put_Font(This,pIFont)	\
    ( (This)->lpVtbl -> put_Font(This,pIFont) ) 

#define IAcPiPropertyInspector_get_BoldFont(This,pIFont)	\
    ( (This)->lpVtbl -> get_BoldFont(This,pIFont) ) 

#define IAcPiPropertyInspector_put_BoldFont(This,pIFont)	\
    ( (This)->lpVtbl -> put_BoldFont(This,pIFont) ) 

#define IAcPiPropertyInspector_SetPersistence(This,pINode)	\
    ( (This)->lpVtbl -> SetPersistence(This,pINode) ) 

#define IAcPiPropertyInspector_GetPersistence(This,pINode)	\
    ( (This)->lpVtbl -> GetPersistence(This,pINode) ) 

#define IAcPiPropertyInspector_get_DelayRefresh(This,pbDelayRefresh)	\
    ( (This)->lpVtbl -> get_DelayRefresh(This,pbDelayRefresh) ) 

#define IAcPiPropertyInspector_put_DelayRefresh(This,pbDelayRefresh)	\
    ( (This)->lpVtbl -> put_DelayRefresh(This,pbDelayRefresh) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcPiPropertyInspector_INTERFACE_DEFINED__ */


#ifndef __IAcPiPropertyInspector2_INTERFACE_DEFINED__
#define __IAcPiPropertyInspector2_INTERFACE_DEFINED__

/* interface IAcPiPropertyInspector2 */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcPiPropertyInspector2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("687AE26A-A274-4829-ADEB-D14F8D45C585")
    IAcPiPropertyInspector2 : public IAcPiPropertyInspector
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetHeight( 
            /* [in] */ VARIANT_BOOL bFull,
            /* [retval][out] */ int *height) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_EnableScrollbar( 
            /* [retval][out] */ VARIANT_BOOL *pbEnableScrollbar) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_EnableScrollbar( 
            /* [in] */ VARIANT_BOOL pbEnableScrollbar) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcPiPropertyInspector2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcPiPropertyInspector2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcPiPropertyInspector2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcPiPropertyInspector2 * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcPiPropertyInspector2 * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcPiPropertyInspector2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcPiPropertyInspector2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcPiPropertyInspector2 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyInspector, Reset)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IAcPiPropertyInspector2 * This,
            /* [in] */ VARIANT *pObjUnkArray,
            /* [in] */ VARIANT *pDynUnkArray,
            /* [in] */ unsigned long dwFlags);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyInspector, get_Style)
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Style )( 
            IAcPiPropertyInspector2 * This,
            /* [retval][out] */ unsigned long *pVal);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyInspector, put_Style)
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Style )( 
            IAcPiPropertyInspector2 * This,
            /* [in] */ unsigned long pVal);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyInspector, get_KeepFocus)
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_KeepFocus )( 
            IAcPiPropertyInspector2 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyInspector, SetColor)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetColor )( 
            IAcPiPropertyInspector2 * This,
            /* [in] */ AcPiColorIndex index,
            /* [in] */ /* external definition not present */ OLE_COLOR color);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyInspector, GetColor)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetColor )( 
            IAcPiPropertyInspector2 * This,
            /* [in] */ AcPiColorIndex __MIDL__IAcPiPropertyInspector0000,
            /* [retval][out] */ /* external definition not present */ OLE_COLOR *pColor);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyInspector, get_Font)
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Font )( 
            IAcPiPropertyInspector2 * This,
            /* [retval][out] */ IUnknown **pIFont);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyInspector, put_Font)
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Font )( 
            IAcPiPropertyInspector2 * This,
            /* [in] */ IUnknown *pIFont);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyInspector, get_BoldFont)
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_BoldFont )( 
            IAcPiPropertyInspector2 * This,
            /* [retval][out] */ IUnknown **pIFont);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyInspector, put_BoldFont)
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_BoldFont )( 
            IAcPiPropertyInspector2 * This,
            /* [in] */ IUnknown *pIFont);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyInspector, SetPersistence)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetPersistence )( 
            IAcPiPropertyInspector2 * This,
            /* [in] */ IUnknown *pINode);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyInspector, GetPersistence)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPersistence )( 
            IAcPiPropertyInspector2 * This,
            /* [in] */ IUnknown *pINode);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyInspector, get_DelayRefresh)
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DelayRefresh )( 
            IAcPiPropertyInspector2 * This,
            /* [retval][out] */ VARIANT_BOOL *pbDelayRefresh);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyInspector, put_DelayRefresh)
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DelayRefresh )( 
            IAcPiPropertyInspector2 * This,
            /* [in] */ VARIANT_BOOL pbDelayRefresh);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyInspector2, GetHeight)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetHeight )( 
            IAcPiPropertyInspector2 * This,
            /* [in] */ VARIANT_BOOL bFull,
            /* [retval][out] */ int *height);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyInspector2, get_EnableScrollbar)
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EnableScrollbar )( 
            IAcPiPropertyInspector2 * This,
            /* [retval][out] */ VARIANT_BOOL *pbEnableScrollbar);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyInspector2, put_EnableScrollbar)
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_EnableScrollbar )( 
            IAcPiPropertyInspector2 * This,
            /* [in] */ VARIANT_BOOL pbEnableScrollbar);
        
        END_INTERFACE
    } IAcPiPropertyInspector2Vtbl;

    interface IAcPiPropertyInspector2
    {
        CONST_VTBL struct IAcPiPropertyInspector2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcPiPropertyInspector2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcPiPropertyInspector2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcPiPropertyInspector2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcPiPropertyInspector2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcPiPropertyInspector2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcPiPropertyInspector2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcPiPropertyInspector2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAcPiPropertyInspector2_Reset(This,pObjUnkArray,pDynUnkArray,dwFlags)	\
    ( (This)->lpVtbl -> Reset(This,pObjUnkArray,pDynUnkArray,dwFlags) ) 

#define IAcPiPropertyInspector2_get_Style(This,pVal)	\
    ( (This)->lpVtbl -> get_Style(This,pVal) ) 

#define IAcPiPropertyInspector2_put_Style(This,pVal)	\
    ( (This)->lpVtbl -> put_Style(This,pVal) ) 

#define IAcPiPropertyInspector2_get_KeepFocus(This,pVal)	\
    ( (This)->lpVtbl -> get_KeepFocus(This,pVal) ) 

#define IAcPiPropertyInspector2_SetColor(This,index,color)	\
    ( (This)->lpVtbl -> SetColor(This,index,color) ) 

#define IAcPiPropertyInspector2_GetColor(This,__MIDL__IAcPiPropertyInspector0000,pColor)	\
    ( (This)->lpVtbl -> GetColor(This,__MIDL__IAcPiPropertyInspector0000,pColor) ) 

#define IAcPiPropertyInspector2_get_Font(This,pIFont)	\
    ( (This)->lpVtbl -> get_Font(This,pIFont) ) 

#define IAcPiPropertyInspector2_put_Font(This,pIFont)	\
    ( (This)->lpVtbl -> put_Font(This,pIFont) ) 

#define IAcPiPropertyInspector2_get_BoldFont(This,pIFont)	\
    ( (This)->lpVtbl -> get_BoldFont(This,pIFont) ) 

#define IAcPiPropertyInspector2_put_BoldFont(This,pIFont)	\
    ( (This)->lpVtbl -> put_BoldFont(This,pIFont) ) 

#define IAcPiPropertyInspector2_SetPersistence(This,pINode)	\
    ( (This)->lpVtbl -> SetPersistence(This,pINode) ) 

#define IAcPiPropertyInspector2_GetPersistence(This,pINode)	\
    ( (This)->lpVtbl -> GetPersistence(This,pINode) ) 

#define IAcPiPropertyInspector2_get_DelayRefresh(This,pbDelayRefresh)	\
    ( (This)->lpVtbl -> get_DelayRefresh(This,pbDelayRefresh) ) 

#define IAcPiPropertyInspector2_put_DelayRefresh(This,pbDelayRefresh)	\
    ( (This)->lpVtbl -> put_DelayRefresh(This,pbDelayRefresh) ) 


#define IAcPiPropertyInspector2_GetHeight(This,bFull,height)	\
    ( (This)->lpVtbl -> GetHeight(This,bFull,height) ) 

#define IAcPiPropertyInspector2_get_EnableScrollbar(This,pbEnableScrollbar)	\
    ( (This)->lpVtbl -> get_EnableScrollbar(This,pbEnableScrollbar) ) 

#define IAcPiPropertyInspector2_put_EnableScrollbar(This,pbEnableScrollbar)	\
    ( (This)->lpVtbl -> put_EnableScrollbar(This,pbEnableScrollbar) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcPiPropertyInspector2_INTERFACE_DEFINED__ */


#ifndef __IAcPiPropertyInspectorInputEventSink_INTERFACE_DEFINED__
#define __IAcPiPropertyInspectorInputEventSink_INTERFACE_DEFINED__

/* interface IAcPiPropertyInspectorInputEventSink */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcPiPropertyInspectorInputEventSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F1C290A2-801A-4A41-B9E4-E5E9EE46129A")
    IAcPiPropertyInspectorInputEventSink : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT __stdcall OnKeyDown( 
            /* [in] */ long pnChar,
            /* [in] */ long keyData) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall OnPopulateContextMenu( 
            /* [in] */ VARIANT *flagArray,
            /* [in] */ VARIANT *idArray,
            /* [in] */ VARIANT *szItemArray) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall OnContextMenuCommand( 
            /* [in] */ int cmdId) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcPiPropertyInspectorInputEventSinkVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcPiPropertyInspectorInputEventSink * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcPiPropertyInspectorInputEventSink * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcPiPropertyInspectorInputEventSink * This);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyInspectorInputEventSink, OnKeyDown)
        /* [helpstring] */ HRESULT ( __stdcall *OnKeyDown )( 
            IAcPiPropertyInspectorInputEventSink * This,
            /* [in] */ long pnChar,
            /* [in] */ long keyData);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyInspectorInputEventSink, OnPopulateContextMenu)
        /* [helpstring] */ HRESULT ( __stdcall *OnPopulateContextMenu )( 
            IAcPiPropertyInspectorInputEventSink * This,
            /* [in] */ VARIANT *flagArray,
            /* [in] */ VARIANT *idArray,
            /* [in] */ VARIANT *szItemArray);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyInspectorInputEventSink, OnContextMenuCommand)
        /* [helpstring] */ HRESULT ( __stdcall *OnContextMenuCommand )( 
            IAcPiPropertyInspectorInputEventSink * This,
            /* [in] */ int cmdId);
        
        END_INTERFACE
    } IAcPiPropertyInspectorInputEventSinkVtbl;

    interface IAcPiPropertyInspectorInputEventSink
    {
        CONST_VTBL struct IAcPiPropertyInspectorInputEventSinkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcPiPropertyInspectorInputEventSink_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcPiPropertyInspectorInputEventSink_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcPiPropertyInspectorInputEventSink_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcPiPropertyInspectorInputEventSink_OnKeyDown(This,pnChar,keyData)	\
    ( (This)->lpVtbl -> OnKeyDown(This,pnChar,keyData) ) 

#define IAcPiPropertyInspectorInputEventSink_OnPopulateContextMenu(This,flagArray,idArray,szItemArray)	\
    ( (This)->lpVtbl -> OnPopulateContextMenu(This,flagArray,idArray,szItemArray) ) 

#define IAcPiPropertyInspectorInputEventSink_OnContextMenuCommand(This,cmdId)	\
    ( (This)->lpVtbl -> OnContextMenuCommand(This,cmdId) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcPiPropertyInspectorInputEventSink_INTERFACE_DEFINED__ */


#ifndef __IAcPiPropertyIdentifier_INTERFACE_DEFINED__
#define __IAcPiPropertyIdentifier_INTERFACE_DEFINED__

/* interface IAcPiPropertyIdentifier */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcPiPropertyIdentifier;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("081530C1-530B-417B-80EF-CAB5C70A3B77")
    IAcPiPropertyIdentifier : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ unsigned short *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Type( 
            /* [in] */ unsigned short pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ControlCLSID( 
            /* [retval][out] */ GUID *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ControlCLSID( 
            /* [in] */ GUID pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Value( 
            /* [in] */ VARIANT pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Categories( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Categories( 
            /* [in] */ BSTR pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ValueAsString( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ValueAsString( 
            /* [in] */ BSTR pVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcPiPropertyIdentifierVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcPiPropertyIdentifier * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcPiPropertyIdentifier * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcPiPropertyIdentifier * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcPiPropertyIdentifier * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcPiPropertyIdentifier * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcPiPropertyIdentifier * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcPiPropertyIdentifier * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyIdentifier, get_Name)
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IAcPiPropertyIdentifier * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyIdentifier, put_Name)
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IAcPiPropertyIdentifier * This,
            /* [in] */ BSTR pVal);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyIdentifier, get_Type)
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            IAcPiPropertyIdentifier * This,
            /* [retval][out] */ unsigned short *pVal);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyIdentifier, put_Type)
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Type )( 
            IAcPiPropertyIdentifier * This,
            /* [in] */ unsigned short pVal);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyIdentifier, get_ControlCLSID)
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ControlCLSID )( 
            IAcPiPropertyIdentifier * This,
            /* [retval][out] */ GUID *pVal);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyIdentifier, put_ControlCLSID)
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ControlCLSID )( 
            IAcPiPropertyIdentifier * This,
            /* [in] */ GUID pVal);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyIdentifier, get_Value)
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            IAcPiPropertyIdentifier * This,
            /* [retval][out] */ VARIANT *pVal);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyIdentifier, put_Value)
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Value )( 
            IAcPiPropertyIdentifier * This,
            /* [in] */ VARIANT pVal);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyIdentifier, get_Categories)
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Categories )( 
            IAcPiPropertyIdentifier * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyIdentifier, put_Categories)
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Categories )( 
            IAcPiPropertyIdentifier * This,
            /* [in] */ BSTR pVal);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyIdentifier, get_ValueAsString)
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ValueAsString )( 
            IAcPiPropertyIdentifier * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyIdentifier, put_ValueAsString)
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ValueAsString )( 
            IAcPiPropertyIdentifier * This,
            /* [in] */ BSTR pVal);
        
        END_INTERFACE
    } IAcPiPropertyIdentifierVtbl;

    interface IAcPiPropertyIdentifier
    {
        CONST_VTBL struct IAcPiPropertyIdentifierVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcPiPropertyIdentifier_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcPiPropertyIdentifier_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcPiPropertyIdentifier_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcPiPropertyIdentifier_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcPiPropertyIdentifier_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcPiPropertyIdentifier_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcPiPropertyIdentifier_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAcPiPropertyIdentifier_get_Name(This,pVal)	\
    ( (This)->lpVtbl -> get_Name(This,pVal) ) 

#define IAcPiPropertyIdentifier_put_Name(This,pVal)	\
    ( (This)->lpVtbl -> put_Name(This,pVal) ) 

#define IAcPiPropertyIdentifier_get_Type(This,pVal)	\
    ( (This)->lpVtbl -> get_Type(This,pVal) ) 

#define IAcPiPropertyIdentifier_put_Type(This,pVal)	\
    ( (This)->lpVtbl -> put_Type(This,pVal) ) 

#define IAcPiPropertyIdentifier_get_ControlCLSID(This,pVal)	\
    ( (This)->lpVtbl -> get_ControlCLSID(This,pVal) ) 

#define IAcPiPropertyIdentifier_put_ControlCLSID(This,pVal)	\
    ( (This)->lpVtbl -> put_ControlCLSID(This,pVal) ) 

#define IAcPiPropertyIdentifier_get_Value(This,pVal)	\
    ( (This)->lpVtbl -> get_Value(This,pVal) ) 

#define IAcPiPropertyIdentifier_put_Value(This,pVal)	\
    ( (This)->lpVtbl -> put_Value(This,pVal) ) 

#define IAcPiPropertyIdentifier_get_Categories(This,pVal)	\
    ( (This)->lpVtbl -> get_Categories(This,pVal) ) 

#define IAcPiPropertyIdentifier_put_Categories(This,pVal)	\
    ( (This)->lpVtbl -> put_Categories(This,pVal) ) 

#define IAcPiPropertyIdentifier_get_ValueAsString(This,pVal)	\
    ( (This)->lpVtbl -> get_ValueAsString(This,pVal) ) 

#define IAcPiPropertyIdentifier_put_ValueAsString(This,pVal)	\
    ( (This)->lpVtbl -> put_ValueAsString(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcPiPropertyIdentifier_INTERFACE_DEFINED__ */


#ifndef __IAcPiCommandButton_INTERFACE_DEFINED__
#define __IAcPiCommandButton_INTERFACE_DEFINED__

/* interface IAcPiCommandButton */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcPiCommandButton;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("438CBD47-3AFB-4D63-B6AB-4C7DA9EA7A5C")
    IAcPiCommandButton : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [in] */ LCID lcid,
            /* [out][retval] */ BSTR *name) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_EnabledPicture( 
            /* [out][retval] */ IUnknown **pPicture) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_DisabledPicture( 
            /* [out][retval] */ IUnknown **pPicture) = 0;
        
        virtual /* [propget][bindable] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [out][retval] */ VARIANT_BOOL *bEnabled) = 0;
        
        virtual /* [propput][bindable] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL bEnabled) = 0;
        
        virtual /* [propget][bindable] */ HRESULT STDMETHODCALLTYPE get_Checked( 
            /* [out][retval] */ VARIANT_BOOL *bChecked) = 0;
        
        virtual /* [propput][bindable] */ HRESULT STDMETHODCALLTYPE put_Checked( 
            /* [in] */ VARIANT_BOOL bChecked) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ButtonStyle( 
            /* [out][retval] */ long *style) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Execute( 
            /* [in] */ VARIANT Objects) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcPiCommandButtonVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcPiCommandButton * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcPiCommandButton * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcPiCommandButton * This);
        
        DECLSPEC_XFGVIRT(IAcPiCommandButton, GetName)
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IAcPiCommandButton * This,
            /* [in] */ LCID lcid,
            /* [out][retval] */ BSTR *name);
        
        DECLSPEC_XFGVIRT(IAcPiCommandButton, get_EnabledPicture)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnabledPicture )( 
            IAcPiCommandButton * This,
            /* [out][retval] */ IUnknown **pPicture);
        
        DECLSPEC_XFGVIRT(IAcPiCommandButton, get_DisabledPicture)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_DisabledPicture )( 
            IAcPiCommandButton * This,
            /* [out][retval] */ IUnknown **pPicture);
        
        DECLSPEC_XFGVIRT(IAcPiCommandButton, get_Enabled)
        /* [propget][bindable] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            IAcPiCommandButton * This,
            /* [out][retval] */ VARIANT_BOOL *bEnabled);
        
        DECLSPEC_XFGVIRT(IAcPiCommandButton, put_Enabled)
        /* [propput][bindable] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            IAcPiCommandButton * This,
            /* [in] */ VARIANT_BOOL bEnabled);
        
        DECLSPEC_XFGVIRT(IAcPiCommandButton, get_Checked)
        /* [propget][bindable] */ HRESULT ( STDMETHODCALLTYPE *get_Checked )( 
            IAcPiCommandButton * This,
            /* [out][retval] */ VARIANT_BOOL *bChecked);
        
        DECLSPEC_XFGVIRT(IAcPiCommandButton, put_Checked)
        /* [propput][bindable] */ HRESULT ( STDMETHODCALLTYPE *put_Checked )( 
            IAcPiCommandButton * This,
            /* [in] */ VARIANT_BOOL bChecked);
        
        DECLSPEC_XFGVIRT(IAcPiCommandButton, get_ButtonStyle)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ButtonStyle )( 
            IAcPiCommandButton * This,
            /* [out][retval] */ long *style);
        
        DECLSPEC_XFGVIRT(IAcPiCommandButton, Execute)
        HRESULT ( STDMETHODCALLTYPE *Execute )( 
            IAcPiCommandButton * This,
            /* [in] */ VARIANT Objects);
        
        END_INTERFACE
    } IAcPiCommandButtonVtbl;

    interface IAcPiCommandButton
    {
        CONST_VTBL struct IAcPiCommandButtonVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcPiCommandButton_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcPiCommandButton_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcPiCommandButton_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcPiCommandButton_GetName(This,lcid,name)	\
    ( (This)->lpVtbl -> GetName(This,lcid,name) ) 

#define IAcPiCommandButton_get_EnabledPicture(This,pPicture)	\
    ( (This)->lpVtbl -> get_EnabledPicture(This,pPicture) ) 

#define IAcPiCommandButton_get_DisabledPicture(This,pPicture)	\
    ( (This)->lpVtbl -> get_DisabledPicture(This,pPicture) ) 

#define IAcPiCommandButton_get_Enabled(This,bEnabled)	\
    ( (This)->lpVtbl -> get_Enabled(This,bEnabled) ) 

#define IAcPiCommandButton_put_Enabled(This,bEnabled)	\
    ( (This)->lpVtbl -> put_Enabled(This,bEnabled) ) 

#define IAcPiCommandButton_get_Checked(This,bChecked)	\
    ( (This)->lpVtbl -> get_Checked(This,bChecked) ) 

#define IAcPiCommandButton_put_Checked(This,bChecked)	\
    ( (This)->lpVtbl -> put_Checked(This,bChecked) ) 

#define IAcPiCommandButton_get_ButtonStyle(This,style)	\
    ( (This)->lpVtbl -> get_ButtonStyle(This,style) ) 

#define IAcPiCommandButton_Execute(This,Objects)	\
    ( (This)->lpVtbl -> Execute(This,Objects) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcPiCommandButton_INTERFACE_DEFINED__ */


#ifndef __IAcPiPropertyDisplay_INTERFACE_DEFINED__
#define __IAcPiPropertyDisplay_INTERFACE_DEFINED__

/* interface IAcPiPropertyDisplay */
/* [object][uuid] */ 

#define IPerPropertyDisplay IAcPiPropertyDisplay
#define IID_IPerPropertyDisplay IID_IAcPiPropertyDisplay

EXTERN_C const IID IID_IAcPiPropertyDisplay;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19BE5D38-F41C-4AC1-AFD4-FB9BFE5AB6C7")
    IAcPiPropertyDisplay : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCustomPropertyCtrl( 
            /* [in] */ VARIANT Id,
            /* [in] */ LCID lcid,
            /* [out] */ BSTR *pProgId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPropertyIcon( 
            /* [in] */ VARIANT Id,
            /* [out] */ IUnknown **pIcon) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPropTextColor( 
            /* [in] */ VARIANT Id,
            /* [out] */ /* external definition not present */ OLE_COLOR *pTextColor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsFullView( 
            /* [in] */ VARIANT Id,
            /* [out] */ VARIANT_BOOL *pbVisible,
            /* [out] */ DWORD *pIntegralHeight) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPropertyWeight( 
            /* [in] */ VARIANT Id,
            /* [out] */ long *pPropertyWeight) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcPiPropertyDisplayVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcPiPropertyDisplay * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcPiPropertyDisplay * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcPiPropertyDisplay * This);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyDisplay, GetCustomPropertyCtrl)
        HRESULT ( STDMETHODCALLTYPE *GetCustomPropertyCtrl )( 
            IAcPiPropertyDisplay * This,
            /* [in] */ VARIANT Id,
            /* [in] */ LCID lcid,
            /* [out] */ BSTR *pProgId);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyDisplay, GetPropertyIcon)
        HRESULT ( STDMETHODCALLTYPE *GetPropertyIcon )( 
            IAcPiPropertyDisplay * This,
            /* [in] */ VARIANT Id,
            /* [out] */ IUnknown **pIcon);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyDisplay, GetPropTextColor)
        HRESULT ( STDMETHODCALLTYPE *GetPropTextColor )( 
            IAcPiPropertyDisplay * This,
            /* [in] */ VARIANT Id,
            /* [out] */ /* external definition not present */ OLE_COLOR *pTextColor);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyDisplay, IsFullView)
        HRESULT ( STDMETHODCALLTYPE *IsFullView )( 
            IAcPiPropertyDisplay * This,
            /* [in] */ VARIANT Id,
            /* [out] */ VARIANT_BOOL *pbVisible,
            /* [out] */ DWORD *pIntegralHeight);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyDisplay, GetPropertyWeight)
        HRESULT ( STDMETHODCALLTYPE *GetPropertyWeight )( 
            IAcPiPropertyDisplay * This,
            /* [in] */ VARIANT Id,
            /* [out] */ long *pPropertyWeight);
        
        END_INTERFACE
    } IAcPiPropertyDisplayVtbl;

    interface IAcPiPropertyDisplay
    {
        CONST_VTBL struct IAcPiPropertyDisplayVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcPiPropertyDisplay_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcPiPropertyDisplay_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcPiPropertyDisplay_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcPiPropertyDisplay_GetCustomPropertyCtrl(This,Id,lcid,pProgId)	\
    ( (This)->lpVtbl -> GetCustomPropertyCtrl(This,Id,lcid,pProgId) ) 

#define IAcPiPropertyDisplay_GetPropertyIcon(This,Id,pIcon)	\
    ( (This)->lpVtbl -> GetPropertyIcon(This,Id,pIcon) ) 

#define IAcPiPropertyDisplay_GetPropTextColor(This,Id,pTextColor)	\
    ( (This)->lpVtbl -> GetPropTextColor(This,Id,pTextColor) ) 

#define IAcPiPropertyDisplay_IsFullView(This,Id,pbVisible,pIntegralHeight)	\
    ( (This)->lpVtbl -> IsFullView(This,Id,pbVisible,pIntegralHeight) ) 

#define IAcPiPropertyDisplay_GetPropertyWeight(This,Id,pPropertyWeight)	\
    ( (This)->lpVtbl -> GetPropertyWeight(This,Id,pPropertyWeight) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcPiPropertyDisplay_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_AcPiPropertyInspector;

#ifdef __cplusplus

class DECLSPEC_UUID("A3AA0E16-0609-422B-949D-1FA1EC9FE233")
AcPiPropertyInspector;
#endif

EXTERN_C const CLSID CLSID_AcPiPropertyIdentifier;

#ifdef __cplusplus

class DECLSPEC_UUID("7D5E7BEE-19F6-4CA2-85C5-175D5E143CDD")
AcPiPropertyIdentifier;
#endif

#ifndef __IAcPiPropertyUnspecified_INTERFACE_DEFINED__
#define __IAcPiPropertyUnspecified_INTERFACE_DEFINED__

/* interface IAcPiPropertyUnspecified */
/* [object][uuid] */ 

#define IPropertyUnspecified IAcPiPropertyUnspecified
#define IID_IPropertyUnspecified IID_IAcPiPropertyUnspecified

EXTERN_C const IID IID_IAcPiPropertyUnspecified;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("401F8094-BF7E-4CA5-A692-BD14077E217B")
    IAcPiPropertyUnspecified : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE IsValueUnspecified( 
            /* [in] */ VARIANT varId,
            /* [out][retval] */ VARIANT_BOOL *pVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetUnspecified( 
            /* [in] */ VARIANT varId,
            /* [in] */ VARIANT_BOOL bIsUnspecified) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsUnspecifiedAllowed( 
            /* [in] */ VARIANT varId,
            /* [out][retval] */ VARIANT_BOOL *pVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUnspecifiedString( 
            /* [in] */ VARIANT varId,
            /* [out][retval] */ BSTR *pVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcPiPropertyUnspecifiedVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcPiPropertyUnspecified * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcPiPropertyUnspecified * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcPiPropertyUnspecified * This);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyUnspecified, IsValueUnspecified)
        HRESULT ( STDMETHODCALLTYPE *IsValueUnspecified )( 
            IAcPiPropertyUnspecified * This,
            /* [in] */ VARIANT varId,
            /* [out][retval] */ VARIANT_BOOL *pVal);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyUnspecified, SetUnspecified)
        HRESULT ( STDMETHODCALLTYPE *SetUnspecified )( 
            IAcPiPropertyUnspecified * This,
            /* [in] */ VARIANT varId,
            /* [in] */ VARIANT_BOOL bIsUnspecified);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyUnspecified, IsUnspecifiedAllowed)
        HRESULT ( STDMETHODCALLTYPE *IsUnspecifiedAllowed )( 
            IAcPiPropertyUnspecified * This,
            /* [in] */ VARIANT varId,
            /* [out][retval] */ VARIANT_BOOL *pVal);
        
        DECLSPEC_XFGVIRT(IAcPiPropertyUnspecified, GetUnspecifiedString)
        HRESULT ( STDMETHODCALLTYPE *GetUnspecifiedString )( 
            IAcPiPropertyUnspecified * This,
            /* [in] */ VARIANT varId,
            /* [out][retval] */ BSTR *pVal);
        
        END_INTERFACE
    } IAcPiPropertyUnspecifiedVtbl;

    interface IAcPiPropertyUnspecified
    {
        CONST_VTBL struct IAcPiPropertyUnspecifiedVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcPiPropertyUnspecified_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcPiPropertyUnspecified_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcPiPropertyUnspecified_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcPiPropertyUnspecified_IsValueUnspecified(This,varId,pVal)	\
    ( (This)->lpVtbl -> IsValueUnspecified(This,varId,pVal) ) 

#define IAcPiPropertyUnspecified_SetUnspecified(This,varId,bIsUnspecified)	\
    ( (This)->lpVtbl -> SetUnspecified(This,varId,bIsUnspecified) ) 

#define IAcPiPropertyUnspecified_IsUnspecifiedAllowed(This,varId,pVal)	\
    ( (This)->lpVtbl -> IsUnspecifiedAllowed(This,varId,pVal) ) 

#define IAcPiPropertyUnspecified_GetUnspecifiedString(This,varId,pVal)	\
    ( (This)->lpVtbl -> GetUnspecifiedString(This,varId,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcPiPropertyUnspecified_INTERFACE_DEFINED__ */

#endif /* __ACPILib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



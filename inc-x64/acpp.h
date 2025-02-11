

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0626 */
/* at Tue Jan 19 04:14:07 2038
 */
/* Compiler settings for ..\..\lib\IcArx\AcPp.idl:
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


#ifndef __acpp_h__
#define __acpp_h__

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

#ifndef __IAcPpAcadInput_FWD_DEFINED__
#define __IAcPpAcadInput_FWD_DEFINED__
typedef interface IAcPpAcadInput IAcPpAcadInput;

#endif 	/* __IAcPpAcadInput_FWD_DEFINED__ */


#ifndef __IAcPpPaletteSet_FWD_DEFINED__
#define __IAcPpPaletteSet_FWD_DEFINED__
typedef interface IAcPpPaletteSet IAcPpPaletteSet;

#endif 	/* __IAcPpPaletteSet_FWD_DEFINED__ */


#ifndef __IAcPpPalette_FWD_DEFINED__
#define __IAcPpPalette_FWD_DEFINED__
typedef interface IAcPpPalette IAcPpPalette;

#endif 	/* __IAcPpPalette_FWD_DEFINED__ */


#ifndef __IAcPpPaletteSetEvents_FWD_DEFINED__
#define __IAcPpPaletteSetEvents_FWD_DEFINED__
typedef interface IAcPpPaletteSetEvents IAcPpPaletteSetEvents;

#endif 	/* __IAcPpPaletteSetEvents_FWD_DEFINED__ */


#ifndef __IAcPpPaletteEvents_FWD_DEFINED__
#define __IAcPpPaletteEvents_FWD_DEFINED__
typedef interface IAcPpPaletteEvents IAcPpPaletteEvents;

#endif 	/* __IAcPpPaletteEvents_FWD_DEFINED__ */


#ifndef __IAcPpPalette2_FWD_DEFINED__
#define __IAcPpPalette2_FWD_DEFINED__
typedef interface IAcPpPalette2 IAcPpPalette2;

#endif 	/* __IAcPpPalette2_FWD_DEFINED__ */


#ifndef __IAcPpNavTree_FWD_DEFINED__
#define __IAcPpNavTree_FWD_DEFINED__
typedef interface IAcPpNavTree IAcPpNavTree;

#endif 	/* __IAcPpNavTree_FWD_DEFINED__ */


#ifndef __IAcPpNavTreeNodeCollection_FWD_DEFINED__
#define __IAcPpNavTreeNodeCollection_FWD_DEFINED__
typedef interface IAcPpNavTreeNodeCollection IAcPpNavTreeNodeCollection;

#endif 	/* __IAcPpNavTreeNodeCollection_FWD_DEFINED__ */


#ifndef __IAcPpNavTreeNode_FWD_DEFINED__
#define __IAcPpNavTreeNode_FWD_DEFINED__
typedef interface IAcPpNavTreeNode IAcPpNavTreeNode;

#endif 	/* __IAcPpNavTreeNode_FWD_DEFINED__ */


#ifndef __IAcPpNavTreeNodeCollectionIter_FWD_DEFINED__
#define __IAcPpNavTreeNodeCollectionIter_FWD_DEFINED__
typedef interface IAcPpNavTreeNodeCollectionIter IAcPpNavTreeNodeCollectionIter;

#endif 	/* __IAcPpNavTreeNodeCollectionIter_FWD_DEFINED__ */


#ifndef __IAcPpNavTreeCmdBtnCollection_FWD_DEFINED__
#define __IAcPpNavTreeCmdBtnCollection_FWD_DEFINED__
typedef interface IAcPpNavTreeCmdBtnCollection IAcPpNavTreeCmdBtnCollection;

#endif 	/* __IAcPpNavTreeCmdBtnCollection_FWD_DEFINED__ */


#ifndef __IAcPpNavTreeCmdBtn_FWD_DEFINED__
#define __IAcPpNavTreeCmdBtn_FWD_DEFINED__
typedef interface IAcPpNavTreeCmdBtn IAcPpNavTreeCmdBtn;

#endif 	/* __IAcPpNavTreeCmdBtn_FWD_DEFINED__ */


#ifndef __IAcPpNavTreeCmdBtnCollectionIter_FWD_DEFINED__
#define __IAcPpNavTreeCmdBtnCollectionIter_FWD_DEFINED__
typedef interface IAcPpNavTreeCmdBtnCollectionIter IAcPpNavTreeCmdBtnCollectionIter;

#endif 	/* __IAcPpNavTreeCmdBtnCollectionIter_FWD_DEFINED__ */


#ifndef __IAcPpNavTreeEvents_FWD_DEFINED__
#define __IAcPpNavTreeEvents_FWD_DEFINED__
typedef interface IAcPpNavTreeEvents IAcPpNavTreeEvents;

#endif 	/* __IAcPpNavTreeEvents_FWD_DEFINED__ */


#ifndef __AcPpAcadInput_FWD_DEFINED__
#define __AcPpAcadInput_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPpAcadInput AcPpAcadInput;
#else
typedef struct AcPpAcadInput AcPpAcadInput;
#endif /* __cplusplus */

#endif 	/* __AcPpAcadInput_FWD_DEFINED__ */


#ifndef __AcPpPaletteSet_FWD_DEFINED__
#define __AcPpPaletteSet_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPpPaletteSet AcPpPaletteSet;
#else
typedef struct AcPpPaletteSet AcPpPaletteSet;
#endif /* __cplusplus */

#endif 	/* __AcPpPaletteSet_FWD_DEFINED__ */


#ifndef __AcPpPalette_FWD_DEFINED__
#define __AcPpPalette_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPpPalette AcPpPalette;
#else
typedef struct AcPpPalette AcPpPalette;
#endif /* __cplusplus */

#endif 	/* __AcPpPalette_FWD_DEFINED__ */


#ifndef __AcPpPalette2_FWD_DEFINED__
#define __AcPpPalette2_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPpPalette2 AcPpPalette2;
#else
typedef struct AcPpPalette2 AcPpPalette2;
#endif /* __cplusplus */

#endif 	/* __AcPpPalette2_FWD_DEFINED__ */


#ifndef __AcPpNavTree_FWD_DEFINED__
#define __AcPpNavTree_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPpNavTree AcPpNavTree;
#else
typedef struct AcPpNavTree AcPpNavTree;
#endif /* __cplusplus */

#endif 	/* __AcPpNavTree_FWD_DEFINED__ */


#ifndef __AcPpNavTreeNode_FWD_DEFINED__
#define __AcPpNavTreeNode_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcPpNavTreeNode AcPpNavTreeNode;
#else
typedef struct AcPpNavTreeNode AcPpNavTreeNode;
#endif /* __cplusplus */

#endif 	/* __AcPpNavTreeNode_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __AcPpLib_LIBRARY_DEFINED__
#define __AcPpLib_LIBRARY_DEFINED__

/* library AcPpLib */
/* [helpstring][version][uuid] */ 

#include "acpi.h"
















EXTERN_C const IID LIBID_AcPpLib;

#ifndef __IAcPpAcadInput_INTERFACE_DEFINED__
#define __IAcPpAcadInput_INTERFACE_DEFINED__

/* interface IAcPpAcadInput */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcPpAcadInput;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("70B0E2F8-2913-4410-B2FD-A76E5E1549B1")
    IAcPpAcadInput : public IUnknown
    {
    public:
        virtual /* [helpstring][requestedit][bindable][propget] */ HRESULT __stdcall get_Value( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][propput] */ HRESULT __stdcall put_Value( 
            /* [in] */ VARIANT pVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][propget] */ HRESULT __stdcall get_Status( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][propput] */ HRESULT __stdcall put_Status( 
            /* [in] */ long pVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][propget] */ HRESULT __stdcall get_Document( 
            /* [retval][out] */ IUnknown **pVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][propput] */ HRESULT __stdcall put_Document( 
            /* [in] */ IUnknown *pVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][propget] */ HRESULT __stdcall get_CrOnly( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][propput] */ HRESULT __stdcall put_CrOnly( 
            /* [in] */ VARIANT_BOOL pVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][propget] */ HRESULT __stdcall get_Prompt( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][propput] */ HRESULT __stdcall put_Prompt( 
            /* [in] */ BSTR pVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][propget] */ HRESULT __stdcall get_Prompt2( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][propput] */ HRESULT __stdcall put_Prompt2( 
            /* [in] */ BSTR pVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][propget] */ HRESULT __stdcall get_InitGetBit( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][propput] */ HRESULT __stdcall put_InitGetBit( 
            /* [in] */ long pVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][propget] */ HRESULT __stdcall get_InitGetKword( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][propput] */ HRESULT __stdcall put_InitGetKword( 
            /* [in] */ BSTR pVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][propget] */ HRESULT __stdcall get_BasePoint( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][propput] */ HRESULT __stdcall put_BasePoint( 
            /* [in] */ VARIANT pVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][propget] */ HRESULT __stdcall get_PromptType( 
            /* [retval][out] */ short *pVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][propput] */ HRESULT __stdcall put_PromptType( 
            /* [in] */ short pVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][propget] */ HRESULT __stdcall get_EnableNotification( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][requestedit][bindable][propput] */ HRESULT __stdcall put_EnableNotification( 
            /* [in] */ VARIANT_BOOL pVal) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall DoPrompt( void) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall CancelPrompt( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcPpAcadInputVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcPpAcadInput * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcPpAcadInput * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcPpAcadInput * This);
        
        DECLSPEC_XFGVIRT(IAcPpAcadInput, get_Value)
        /* [helpstring][requestedit][bindable][propget] */ HRESULT ( __stdcall *get_Value )( 
            IAcPpAcadInput * This,
            /* [retval][out] */ VARIANT *pVal);
        
        DECLSPEC_XFGVIRT(IAcPpAcadInput, put_Value)
        /* [helpstring][requestedit][bindable][propput] */ HRESULT ( __stdcall *put_Value )( 
            IAcPpAcadInput * This,
            /* [in] */ VARIANT pVal);
        
        DECLSPEC_XFGVIRT(IAcPpAcadInput, get_Status)
        /* [helpstring][requestedit][bindable][propget] */ HRESULT ( __stdcall *get_Status )( 
            IAcPpAcadInput * This,
            /* [retval][out] */ long *pVal);
        
        DECLSPEC_XFGVIRT(IAcPpAcadInput, put_Status)
        /* [helpstring][requestedit][bindable][propput] */ HRESULT ( __stdcall *put_Status )( 
            IAcPpAcadInput * This,
            /* [in] */ long pVal);
        
        DECLSPEC_XFGVIRT(IAcPpAcadInput, get_Document)
        /* [helpstring][requestedit][bindable][propget] */ HRESULT ( __stdcall *get_Document )( 
            IAcPpAcadInput * This,
            /* [retval][out] */ IUnknown **pVal);
        
        DECLSPEC_XFGVIRT(IAcPpAcadInput, put_Document)
        /* [helpstring][requestedit][bindable][propput] */ HRESULT ( __stdcall *put_Document )( 
            IAcPpAcadInput * This,
            /* [in] */ IUnknown *pVal);
        
        DECLSPEC_XFGVIRT(IAcPpAcadInput, get_CrOnly)
        /* [helpstring][requestedit][bindable][propget] */ HRESULT ( __stdcall *get_CrOnly )( 
            IAcPpAcadInput * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        DECLSPEC_XFGVIRT(IAcPpAcadInput, put_CrOnly)
        /* [helpstring][requestedit][bindable][propput] */ HRESULT ( __stdcall *put_CrOnly )( 
            IAcPpAcadInput * This,
            /* [in] */ VARIANT_BOOL pVal);
        
        DECLSPEC_XFGVIRT(IAcPpAcadInput, get_Prompt)
        /* [helpstring][requestedit][bindable][propget] */ HRESULT ( __stdcall *get_Prompt )( 
            IAcPpAcadInput * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IAcPpAcadInput, put_Prompt)
        /* [helpstring][requestedit][bindable][propput] */ HRESULT ( __stdcall *put_Prompt )( 
            IAcPpAcadInput * This,
            /* [in] */ BSTR pVal);
        
        DECLSPEC_XFGVIRT(IAcPpAcadInput, get_Prompt2)
        /* [helpstring][requestedit][bindable][propget] */ HRESULT ( __stdcall *get_Prompt2 )( 
            IAcPpAcadInput * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IAcPpAcadInput, put_Prompt2)
        /* [helpstring][requestedit][bindable][propput] */ HRESULT ( __stdcall *put_Prompt2 )( 
            IAcPpAcadInput * This,
            /* [in] */ BSTR pVal);
        
        DECLSPEC_XFGVIRT(IAcPpAcadInput, get_InitGetBit)
        /* [helpstring][requestedit][bindable][propget] */ HRESULT ( __stdcall *get_InitGetBit )( 
            IAcPpAcadInput * This,
            /* [retval][out] */ long *pVal);
        
        DECLSPEC_XFGVIRT(IAcPpAcadInput, put_InitGetBit)
        /* [helpstring][requestedit][bindable][propput] */ HRESULT ( __stdcall *put_InitGetBit )( 
            IAcPpAcadInput * This,
            /* [in] */ long pVal);
        
        DECLSPEC_XFGVIRT(IAcPpAcadInput, get_InitGetKword)
        /* [helpstring][requestedit][bindable][propget] */ HRESULT ( __stdcall *get_InitGetKword )( 
            IAcPpAcadInput * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IAcPpAcadInput, put_InitGetKword)
        /* [helpstring][requestedit][bindable][propput] */ HRESULT ( __stdcall *put_InitGetKword )( 
            IAcPpAcadInput * This,
            /* [in] */ BSTR pVal);
        
        DECLSPEC_XFGVIRT(IAcPpAcadInput, get_BasePoint)
        /* [helpstring][requestedit][bindable][propget] */ HRESULT ( __stdcall *get_BasePoint )( 
            IAcPpAcadInput * This,
            /* [retval][out] */ VARIANT *pVal);
        
        DECLSPEC_XFGVIRT(IAcPpAcadInput, put_BasePoint)
        /* [helpstring][requestedit][bindable][propput] */ HRESULT ( __stdcall *put_BasePoint )( 
            IAcPpAcadInput * This,
            /* [in] */ VARIANT pVal);
        
        DECLSPEC_XFGVIRT(IAcPpAcadInput, get_PromptType)
        /* [helpstring][requestedit][bindable][propget] */ HRESULT ( __stdcall *get_PromptType )( 
            IAcPpAcadInput * This,
            /* [retval][out] */ short *pVal);
        
        DECLSPEC_XFGVIRT(IAcPpAcadInput, put_PromptType)
        /* [helpstring][requestedit][bindable][propput] */ HRESULT ( __stdcall *put_PromptType )( 
            IAcPpAcadInput * This,
            /* [in] */ short pVal);
        
        DECLSPEC_XFGVIRT(IAcPpAcadInput, get_EnableNotification)
        /* [helpstring][requestedit][bindable][propget] */ HRESULT ( __stdcall *get_EnableNotification )( 
            IAcPpAcadInput * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        DECLSPEC_XFGVIRT(IAcPpAcadInput, put_EnableNotification)
        /* [helpstring][requestedit][bindable][propput] */ HRESULT ( __stdcall *put_EnableNotification )( 
            IAcPpAcadInput * This,
            /* [in] */ VARIANT_BOOL pVal);
        
        DECLSPEC_XFGVIRT(IAcPpAcadInput, DoPrompt)
        /* [helpstring] */ HRESULT ( __stdcall *DoPrompt )( 
            IAcPpAcadInput * This);
        
        DECLSPEC_XFGVIRT(IAcPpAcadInput, CancelPrompt)
        /* [helpstring] */ HRESULT ( __stdcall *CancelPrompt )( 
            IAcPpAcadInput * This);
        
        END_INTERFACE
    } IAcPpAcadInputVtbl;

    interface IAcPpAcadInput
    {
        CONST_VTBL struct IAcPpAcadInputVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcPpAcadInput_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcPpAcadInput_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcPpAcadInput_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcPpAcadInput_get_Value(This,pVal)	\
    ( (This)->lpVtbl -> get_Value(This,pVal) ) 

#define IAcPpAcadInput_put_Value(This,pVal)	\
    ( (This)->lpVtbl -> put_Value(This,pVal) ) 

#define IAcPpAcadInput_get_Status(This,pVal)	\
    ( (This)->lpVtbl -> get_Status(This,pVal) ) 

#define IAcPpAcadInput_put_Status(This,pVal)	\
    ( (This)->lpVtbl -> put_Status(This,pVal) ) 

#define IAcPpAcadInput_get_Document(This,pVal)	\
    ( (This)->lpVtbl -> get_Document(This,pVal) ) 

#define IAcPpAcadInput_put_Document(This,pVal)	\
    ( (This)->lpVtbl -> put_Document(This,pVal) ) 

#define IAcPpAcadInput_get_CrOnly(This,pVal)	\
    ( (This)->lpVtbl -> get_CrOnly(This,pVal) ) 

#define IAcPpAcadInput_put_CrOnly(This,pVal)	\
    ( (This)->lpVtbl -> put_CrOnly(This,pVal) ) 

#define IAcPpAcadInput_get_Prompt(This,pVal)	\
    ( (This)->lpVtbl -> get_Prompt(This,pVal) ) 

#define IAcPpAcadInput_put_Prompt(This,pVal)	\
    ( (This)->lpVtbl -> put_Prompt(This,pVal) ) 

#define IAcPpAcadInput_get_Prompt2(This,pVal)	\
    ( (This)->lpVtbl -> get_Prompt2(This,pVal) ) 

#define IAcPpAcadInput_put_Prompt2(This,pVal)	\
    ( (This)->lpVtbl -> put_Prompt2(This,pVal) ) 

#define IAcPpAcadInput_get_InitGetBit(This,pVal)	\
    ( (This)->lpVtbl -> get_InitGetBit(This,pVal) ) 

#define IAcPpAcadInput_put_InitGetBit(This,pVal)	\
    ( (This)->lpVtbl -> put_InitGetBit(This,pVal) ) 

#define IAcPpAcadInput_get_InitGetKword(This,pVal)	\
    ( (This)->lpVtbl -> get_InitGetKword(This,pVal) ) 

#define IAcPpAcadInput_put_InitGetKword(This,pVal)	\
    ( (This)->lpVtbl -> put_InitGetKword(This,pVal) ) 

#define IAcPpAcadInput_get_BasePoint(This,pVal)	\
    ( (This)->lpVtbl -> get_BasePoint(This,pVal) ) 

#define IAcPpAcadInput_put_BasePoint(This,pVal)	\
    ( (This)->lpVtbl -> put_BasePoint(This,pVal) ) 

#define IAcPpAcadInput_get_PromptType(This,pVal)	\
    ( (This)->lpVtbl -> get_PromptType(This,pVal) ) 

#define IAcPpAcadInput_put_PromptType(This,pVal)	\
    ( (This)->lpVtbl -> put_PromptType(This,pVal) ) 

#define IAcPpAcadInput_get_EnableNotification(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableNotification(This,pVal) ) 

#define IAcPpAcadInput_put_EnableNotification(This,pVal)	\
    ( (This)->lpVtbl -> put_EnableNotification(This,pVal) ) 

#define IAcPpAcadInput_DoPrompt(This)	\
    ( (This)->lpVtbl -> DoPrompt(This) ) 

#define IAcPpAcadInput_CancelPrompt(This)	\
    ( (This)->lpVtbl -> CancelPrompt(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcPpAcadInput_INTERFACE_DEFINED__ */


#ifndef __IAcPpPaletteSet_INTERFACE_DEFINED__
#define __IAcPpPaletteSet_INTERFACE_DEFINED__

/* interface IAcPpPaletteSet */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcPpPaletteSet;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C9292B35-1C30-4B58-B8BE-C95B9AD5FE2A")
    IAcPpPaletteSet : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT __stdcall AddPalette( 
            /* [in] */ IAcPpPalette *pPalette) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall DeletePalette( 
            /* [in] */ IAcPpPalette *pPalette) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall InsertPalette( 
            /* [in] */ int index,
            /* [in] */ IAcPpPalette *pPalette) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall GetPalette( 
            /* [in] */ int index,
            /* [retval][out] */ IAcPpPalette **pPalette) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall GetPaletteByName( 
            /* [in] */ BSTR paletteName,
            /* [retval][out] */ IAcPpPalette **pPalette) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall ActivatePalette( 
            /* [in] */ IAcPpPalette *pPalette) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT __stdcall get_PaletteCount( 
            /* [retval][out] */ int *nPalettes) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT __stdcall get_Visibility( 
            /* [retval][out] */ VARIANT_BOOL *bIsVisible) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT __stdcall put_Visibility( 
            /* [in] */ VARIANT_BOOL bIsVisible) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT __stdcall get_CurrentIndex( 
            /* [retval][out] */ int *nCurrentIndex) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall GetDockingState( 
            /* [out] */ int *nDockPos,
            /* [out] */ long *left,
            /* [out] */ long *top,
            /* [out] */ long *width,
            /* [out] */ long *height) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall SetDockingState( 
            /* [in] */ int nDockPos,
            /* [in] */ long left,
            /* [in] */ long top,
            /* [in] */ long width,
            /* [in] */ long height) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall GetFloatingRect( 
            /* [out] */ long *left,
            /* [out] */ long *top,
            /* [out] */ long *width,
            /* [out] */ long *height) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall GetDockingRect( 
            /* [out] */ int *nDockPos,
            /* [out] */ long *left,
            /* [out] */ long *top,
            /* [out] */ long *width,
            /* [out] */ long *height) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcPpPaletteSetVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcPpPaletteSet * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcPpPaletteSet * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcPpPaletteSet * This);
        
        DECLSPEC_XFGVIRT(IAcPpPaletteSet, AddPalette)
        /* [helpstring] */ HRESULT ( __stdcall *AddPalette )( 
            IAcPpPaletteSet * This,
            /* [in] */ IAcPpPalette *pPalette);
        
        DECLSPEC_XFGVIRT(IAcPpPaletteSet, DeletePalette)
        /* [helpstring] */ HRESULT ( __stdcall *DeletePalette )( 
            IAcPpPaletteSet * This,
            /* [in] */ IAcPpPalette *pPalette);
        
        DECLSPEC_XFGVIRT(IAcPpPaletteSet, InsertPalette)
        /* [helpstring] */ HRESULT ( __stdcall *InsertPalette )( 
            IAcPpPaletteSet * This,
            /* [in] */ int index,
            /* [in] */ IAcPpPalette *pPalette);
        
        DECLSPEC_XFGVIRT(IAcPpPaletteSet, GetPalette)
        /* [helpstring] */ HRESULT ( __stdcall *GetPalette )( 
            IAcPpPaletteSet * This,
            /* [in] */ int index,
            /* [retval][out] */ IAcPpPalette **pPalette);
        
        DECLSPEC_XFGVIRT(IAcPpPaletteSet, GetPaletteByName)
        /* [helpstring] */ HRESULT ( __stdcall *GetPaletteByName )( 
            IAcPpPaletteSet * This,
            /* [in] */ BSTR paletteName,
            /* [retval][out] */ IAcPpPalette **pPalette);
        
        DECLSPEC_XFGVIRT(IAcPpPaletteSet, ActivatePalette)
        /* [helpstring] */ HRESULT ( __stdcall *ActivatePalette )( 
            IAcPpPaletteSet * This,
            /* [in] */ IAcPpPalette *pPalette);
        
        DECLSPEC_XFGVIRT(IAcPpPaletteSet, get_PaletteCount)
        /* [helpstring][propget] */ HRESULT ( __stdcall *get_PaletteCount )( 
            IAcPpPaletteSet * This,
            /* [retval][out] */ int *nPalettes);
        
        DECLSPEC_XFGVIRT(IAcPpPaletteSet, get_Visibility)
        /* [helpstring][propget] */ HRESULT ( __stdcall *get_Visibility )( 
            IAcPpPaletteSet * This,
            /* [retval][out] */ VARIANT_BOOL *bIsVisible);
        
        DECLSPEC_XFGVIRT(IAcPpPaletteSet, put_Visibility)
        /* [helpstring][propput] */ HRESULT ( __stdcall *put_Visibility )( 
            IAcPpPaletteSet * This,
            /* [in] */ VARIANT_BOOL bIsVisible);
        
        DECLSPEC_XFGVIRT(IAcPpPaletteSet, get_CurrentIndex)
        /* [helpstring][propget] */ HRESULT ( __stdcall *get_CurrentIndex )( 
            IAcPpPaletteSet * This,
            /* [retval][out] */ int *nCurrentIndex);
        
        DECLSPEC_XFGVIRT(IAcPpPaletteSet, GetDockingState)
        /* [helpstring] */ HRESULT ( __stdcall *GetDockingState )( 
            IAcPpPaletteSet * This,
            /* [out] */ int *nDockPos,
            /* [out] */ long *left,
            /* [out] */ long *top,
            /* [out] */ long *width,
            /* [out] */ long *height);
        
        DECLSPEC_XFGVIRT(IAcPpPaletteSet, SetDockingState)
        /* [helpstring] */ HRESULT ( __stdcall *SetDockingState )( 
            IAcPpPaletteSet * This,
            /* [in] */ int nDockPos,
            /* [in] */ long left,
            /* [in] */ long top,
            /* [in] */ long width,
            /* [in] */ long height);
        
        DECLSPEC_XFGVIRT(IAcPpPaletteSet, GetFloatingRect)
        /* [helpstring] */ HRESULT ( __stdcall *GetFloatingRect )( 
            IAcPpPaletteSet * This,
            /* [out] */ long *left,
            /* [out] */ long *top,
            /* [out] */ long *width,
            /* [out] */ long *height);
        
        DECLSPEC_XFGVIRT(IAcPpPaletteSet, GetDockingRect)
        /* [helpstring] */ HRESULT ( __stdcall *GetDockingRect )( 
            IAcPpPaletteSet * This,
            /* [out] */ int *nDockPos,
            /* [out] */ long *left,
            /* [out] */ long *top,
            /* [out] */ long *width,
            /* [out] */ long *height);
        
        END_INTERFACE
    } IAcPpPaletteSetVtbl;

    interface IAcPpPaletteSet
    {
        CONST_VTBL struct IAcPpPaletteSetVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcPpPaletteSet_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcPpPaletteSet_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcPpPaletteSet_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcPpPaletteSet_AddPalette(This,pPalette)	\
    ( (This)->lpVtbl -> AddPalette(This,pPalette) ) 

#define IAcPpPaletteSet_DeletePalette(This,pPalette)	\
    ( (This)->lpVtbl -> DeletePalette(This,pPalette) ) 

#define IAcPpPaletteSet_InsertPalette(This,index,pPalette)	\
    ( (This)->lpVtbl -> InsertPalette(This,index,pPalette) ) 

#define IAcPpPaletteSet_GetPalette(This,index,pPalette)	\
    ( (This)->lpVtbl -> GetPalette(This,index,pPalette) ) 

#define IAcPpPaletteSet_GetPaletteByName(This,paletteName,pPalette)	\
    ( (This)->lpVtbl -> GetPaletteByName(This,paletteName,pPalette) ) 

#define IAcPpPaletteSet_ActivatePalette(This,pPalette)	\
    ( (This)->lpVtbl -> ActivatePalette(This,pPalette) ) 

#define IAcPpPaletteSet_get_PaletteCount(This,nPalettes)	\
    ( (This)->lpVtbl -> get_PaletteCount(This,nPalettes) ) 

#define IAcPpPaletteSet_get_Visibility(This,bIsVisible)	\
    ( (This)->lpVtbl -> get_Visibility(This,bIsVisible) ) 

#define IAcPpPaletteSet_put_Visibility(This,bIsVisible)	\
    ( (This)->lpVtbl -> put_Visibility(This,bIsVisible) ) 

#define IAcPpPaletteSet_get_CurrentIndex(This,nCurrentIndex)	\
    ( (This)->lpVtbl -> get_CurrentIndex(This,nCurrentIndex) ) 

#define IAcPpPaletteSet_GetDockingState(This,nDockPos,left,top,width,height)	\
    ( (This)->lpVtbl -> GetDockingState(This,nDockPos,left,top,width,height) ) 

#define IAcPpPaletteSet_SetDockingState(This,nDockPos,left,top,width,height)	\
    ( (This)->lpVtbl -> SetDockingState(This,nDockPos,left,top,width,height) ) 

#define IAcPpPaletteSet_GetFloatingRect(This,left,top,width,height)	\
    ( (This)->lpVtbl -> GetFloatingRect(This,left,top,width,height) ) 

#define IAcPpPaletteSet_GetDockingRect(This,nDockPos,left,top,width,height)	\
    ( (This)->lpVtbl -> GetDockingRect(This,nDockPos,left,top,width,height) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcPpPaletteSet_INTERFACE_DEFINED__ */


#ifndef __IAcPpPalette_INTERFACE_DEFINED__
#define __IAcPpPalette_INTERFACE_DEFINED__

/* interface IAcPpPalette */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcPpPalette;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("30D793B7-C94E-45EA-8077-F9A5DC84E1E0")
    IAcPpPalette : public IUnknown
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT __stdcall get_Name( 
            /* [retval][out] */ BSTR *Name) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT __stdcall put_Name( 
            /* [in] */ BSTR Name) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT __stdcall get_InspectorControl( 
            /* [retval][out] */ IAcPiPropertyInspector **pInspector) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcPpPaletteVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcPpPalette * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcPpPalette * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcPpPalette * This);
        
        DECLSPEC_XFGVIRT(IAcPpPalette, get_Name)
        /* [helpstring][propget] */ HRESULT ( __stdcall *get_Name )( 
            IAcPpPalette * This,
            /* [retval][out] */ BSTR *Name);
        
        DECLSPEC_XFGVIRT(IAcPpPalette, put_Name)
        /* [helpstring][propput] */ HRESULT ( __stdcall *put_Name )( 
            IAcPpPalette * This,
            /* [in] */ BSTR Name);
        
        DECLSPEC_XFGVIRT(IAcPpPalette, get_InspectorControl)
        /* [helpstring][propget] */ HRESULT ( __stdcall *get_InspectorControl )( 
            IAcPpPalette * This,
            /* [retval][out] */ IAcPiPropertyInspector **pInspector);
        
        END_INTERFACE
    } IAcPpPaletteVtbl;

    interface IAcPpPalette
    {
        CONST_VTBL struct IAcPpPaletteVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcPpPalette_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcPpPalette_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcPpPalette_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcPpPalette_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define IAcPpPalette_put_Name(This,Name)	\
    ( (This)->lpVtbl -> put_Name(This,Name) ) 

#define IAcPpPalette_get_InspectorControl(This,pInspector)	\
    ( (This)->lpVtbl -> get_InspectorControl(This,pInspector) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcPpPalette_INTERFACE_DEFINED__ */


#ifndef __IAcPpPaletteSetEvents_INTERFACE_DEFINED__
#define __IAcPpPaletteSetEvents_INTERFACE_DEFINED__

/* interface IAcPpPaletteSetEvents */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcPpPaletteSetEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7E08DAAE-374D-4794-A487-934AA7C4CBC8")
    IAcPpPaletteSetEvents : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT __stdcall OnPaletteAdded( 
            /* [in] */ IAcPpPalette *pNewPalette) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall OnPaletteDeleted( 
            /* [in] */ IAcPpPalette *pPalette) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall OnPaletteActivated( 
            /* [in] */ IAcPpPalette *pPalette) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall OnPaletteDeActivated( 
            /* [in] */ IAcPpPalette *pPalette) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall OnSelectionChanged( 
            /* [in] */ VARIANT *newObjectArray,
            /* [in] */ VARIANT *newPropMgrArray) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall OnVisibilityChanged( 
            /* [in] */ VARIANT_BOOL bIsVisible) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcPpPaletteSetEventsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcPpPaletteSetEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcPpPaletteSetEvents * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcPpPaletteSetEvents * This);
        
        DECLSPEC_XFGVIRT(IAcPpPaletteSetEvents, OnPaletteAdded)
        /* [helpstring] */ HRESULT ( __stdcall *OnPaletteAdded )( 
            IAcPpPaletteSetEvents * This,
            /* [in] */ IAcPpPalette *pNewPalette);
        
        DECLSPEC_XFGVIRT(IAcPpPaletteSetEvents, OnPaletteDeleted)
        /* [helpstring] */ HRESULT ( __stdcall *OnPaletteDeleted )( 
            IAcPpPaletteSetEvents * This,
            /* [in] */ IAcPpPalette *pPalette);
        
        DECLSPEC_XFGVIRT(IAcPpPaletteSetEvents, OnPaletteActivated)
        /* [helpstring] */ HRESULT ( __stdcall *OnPaletteActivated )( 
            IAcPpPaletteSetEvents * This,
            /* [in] */ IAcPpPalette *pPalette);
        
        DECLSPEC_XFGVIRT(IAcPpPaletteSetEvents, OnPaletteDeActivated)
        /* [helpstring] */ HRESULT ( __stdcall *OnPaletteDeActivated )( 
            IAcPpPaletteSetEvents * This,
            /* [in] */ IAcPpPalette *pPalette);
        
        DECLSPEC_XFGVIRT(IAcPpPaletteSetEvents, OnSelectionChanged)
        /* [helpstring] */ HRESULT ( __stdcall *OnSelectionChanged )( 
            IAcPpPaletteSetEvents * This,
            /* [in] */ VARIANT *newObjectArray,
            /* [in] */ VARIANT *newPropMgrArray);
        
        DECLSPEC_XFGVIRT(IAcPpPaletteSetEvents, OnVisibilityChanged)
        /* [helpstring] */ HRESULT ( __stdcall *OnVisibilityChanged )( 
            IAcPpPaletteSetEvents * This,
            /* [in] */ VARIANT_BOOL bIsVisible);
        
        END_INTERFACE
    } IAcPpPaletteSetEventsVtbl;

    interface IAcPpPaletteSetEvents
    {
        CONST_VTBL struct IAcPpPaletteSetEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcPpPaletteSetEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcPpPaletteSetEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcPpPaletteSetEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcPpPaletteSetEvents_OnPaletteAdded(This,pNewPalette)	\
    ( (This)->lpVtbl -> OnPaletteAdded(This,pNewPalette) ) 

#define IAcPpPaletteSetEvents_OnPaletteDeleted(This,pPalette)	\
    ( (This)->lpVtbl -> OnPaletteDeleted(This,pPalette) ) 

#define IAcPpPaletteSetEvents_OnPaletteActivated(This,pPalette)	\
    ( (This)->lpVtbl -> OnPaletteActivated(This,pPalette) ) 

#define IAcPpPaletteSetEvents_OnPaletteDeActivated(This,pPalette)	\
    ( (This)->lpVtbl -> OnPaletteDeActivated(This,pPalette) ) 

#define IAcPpPaletteSetEvents_OnSelectionChanged(This,newObjectArray,newPropMgrArray)	\
    ( (This)->lpVtbl -> OnSelectionChanged(This,newObjectArray,newPropMgrArray) ) 

#define IAcPpPaletteSetEvents_OnVisibilityChanged(This,bIsVisible)	\
    ( (This)->lpVtbl -> OnVisibilityChanged(This,bIsVisible) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcPpPaletteSetEvents_INTERFACE_DEFINED__ */


#ifndef __IAcPpPaletteEvents_INTERFACE_DEFINED__
#define __IAcPpPaletteEvents_INTERFACE_DEFINED__

/* interface IAcPpPaletteEvents */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcPpPaletteEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5D11FF65-EF2A-48CD-B27F-36765C6AB640")
    IAcPpPaletteEvents : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT __stdcall OnNameChanged( 
            /* [in] */ BSTR newName) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall OnSelectionChanged( 
            /* [in] */ VARIANT *newObjectArray,
            /* [in] */ VARIANT *newPropMgrArray,
            /* [out][in] */ VARIANT_BOOL *bHandled) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcPpPaletteEventsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcPpPaletteEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcPpPaletteEvents * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcPpPaletteEvents * This);
        
        DECLSPEC_XFGVIRT(IAcPpPaletteEvents, OnNameChanged)
        /* [helpstring] */ HRESULT ( __stdcall *OnNameChanged )( 
            IAcPpPaletteEvents * This,
            /* [in] */ BSTR newName);
        
        DECLSPEC_XFGVIRT(IAcPpPaletteEvents, OnSelectionChanged)
        /* [helpstring] */ HRESULT ( __stdcall *OnSelectionChanged )( 
            IAcPpPaletteEvents * This,
            /* [in] */ VARIANT *newObjectArray,
            /* [in] */ VARIANT *newPropMgrArray,
            /* [out][in] */ VARIANT_BOOL *bHandled);
        
        END_INTERFACE
    } IAcPpPaletteEventsVtbl;

    interface IAcPpPaletteEvents
    {
        CONST_VTBL struct IAcPpPaletteEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcPpPaletteEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcPpPaletteEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcPpPaletteEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcPpPaletteEvents_OnNameChanged(This,newName)	\
    ( (This)->lpVtbl -> OnNameChanged(This,newName) ) 

#define IAcPpPaletteEvents_OnSelectionChanged(This,newObjectArray,newPropMgrArray,bHandled)	\
    ( (This)->lpVtbl -> OnSelectionChanged(This,newObjectArray,newPropMgrArray,bHandled) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcPpPaletteEvents_INTERFACE_DEFINED__ */


#ifndef __IAcPpPalette2_INTERFACE_DEFINED__
#define __IAcPpPalette2_INTERFACE_DEFINED__

/* interface IAcPpPalette2 */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcPpPalette2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D2CDF7CE-1B43-413B-955F-DF1A9A358AC9")
    IAcPpPalette2 : public IUnknown
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT __stdcall get_NavTree( 
            /* [retval][out] */ IAcPpNavTree **pNavTree) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT __stdcall put_NavTree( 
            /* [in] */ IAcPpNavTree *pNavTree) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcPpPalette2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcPpPalette2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcPpPalette2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcPpPalette2 * This);
        
        DECLSPEC_XFGVIRT(IAcPpPalette2, get_NavTree)
        /* [helpstring][propget] */ HRESULT ( __stdcall *get_NavTree )( 
            IAcPpPalette2 * This,
            /* [retval][out] */ IAcPpNavTree **pNavTree);
        
        DECLSPEC_XFGVIRT(IAcPpPalette2, put_NavTree)
        /* [helpstring][propput] */ HRESULT ( __stdcall *put_NavTree )( 
            IAcPpPalette2 * This,
            /* [in] */ IAcPpNavTree *pNavTree);
        
        END_INTERFACE
    } IAcPpPalette2Vtbl;

    interface IAcPpPalette2
    {
        CONST_VTBL struct IAcPpPalette2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcPpPalette2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcPpPalette2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcPpPalette2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcPpPalette2_get_NavTree(This,pNavTree)	\
    ( (This)->lpVtbl -> get_NavTree(This,pNavTree) ) 

#define IAcPpPalette2_put_NavTree(This,pNavTree)	\
    ( (This)->lpVtbl -> put_NavTree(This,pNavTree) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcPpPalette2_INTERFACE_DEFINED__ */


#ifndef __IAcPpNavTree_INTERFACE_DEFINED__
#define __IAcPpNavTree_INTERFACE_DEFINED__

/* interface IAcPpNavTree */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcPpNavTree;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B06BC163-454F-49AD-8EE0-541D2FF85766")
    IAcPpNavTree : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT __stdcall Reset( 
            /* [in] */ IAcPpNavTreeNodeCollection *pNodeCollection,
            /* [in] */ IAcPpNavTreeCmdBtnCollection *pCmdBtnCollection) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcPpNavTreeVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcPpNavTree * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcPpNavTree * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcPpNavTree * This);
        
        DECLSPEC_XFGVIRT(IAcPpNavTree, Reset)
        /* [helpstring] */ HRESULT ( __stdcall *Reset )( 
            IAcPpNavTree * This,
            /* [in] */ IAcPpNavTreeNodeCollection *pNodeCollection,
            /* [in] */ IAcPpNavTreeCmdBtnCollection *pCmdBtnCollection);
        
        END_INTERFACE
    } IAcPpNavTreeVtbl;

    interface IAcPpNavTree
    {
        CONST_VTBL struct IAcPpNavTreeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcPpNavTree_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcPpNavTree_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcPpNavTree_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcPpNavTree_Reset(This,pNodeCollection,pCmdBtnCollection)	\
    ( (This)->lpVtbl -> Reset(This,pNodeCollection,pCmdBtnCollection) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcPpNavTree_INTERFACE_DEFINED__ */


#ifndef __IAcPpNavTreeNodeCollection_INTERFACE_DEFINED__
#define __IAcPpNavTreeNodeCollection_INTERFACE_DEFINED__

/* interface IAcPpNavTreeNodeCollection */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcPpNavTreeNodeCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("60C40E81-69EF-4B68-BFD4-FC4DFD3BE10A")
    IAcPpNavTreeNodeCollection : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT __stdcall AddNode( 
            /* [in] */ IAcPpNavTreeNode *pNode) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall DeleteNode( 
            /* [in] */ IAcPpNavTreeNode *pNode) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall DeleteAllNodes( void) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall GetNodeCollectionIter( 
            /* [retval][out] */ IAcPpNavTreeNodeCollectionIter **PIter) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcPpNavTreeNodeCollectionVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcPpNavTreeNodeCollection * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcPpNavTreeNodeCollection * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcPpNavTreeNodeCollection * This);
        
        DECLSPEC_XFGVIRT(IAcPpNavTreeNodeCollection, AddNode)
        /* [helpstring] */ HRESULT ( __stdcall *AddNode )( 
            IAcPpNavTreeNodeCollection * This,
            /* [in] */ IAcPpNavTreeNode *pNode);
        
        DECLSPEC_XFGVIRT(IAcPpNavTreeNodeCollection, DeleteNode)
        /* [helpstring] */ HRESULT ( __stdcall *DeleteNode )( 
            IAcPpNavTreeNodeCollection * This,
            /* [in] */ IAcPpNavTreeNode *pNode);
        
        DECLSPEC_XFGVIRT(IAcPpNavTreeNodeCollection, DeleteAllNodes)
        /* [helpstring] */ HRESULT ( __stdcall *DeleteAllNodes )( 
            IAcPpNavTreeNodeCollection * This);
        
        DECLSPEC_XFGVIRT(IAcPpNavTreeNodeCollection, GetNodeCollectionIter)
        /* [helpstring] */ HRESULT ( __stdcall *GetNodeCollectionIter )( 
            IAcPpNavTreeNodeCollection * This,
            /* [retval][out] */ IAcPpNavTreeNodeCollectionIter **PIter);
        
        END_INTERFACE
    } IAcPpNavTreeNodeCollectionVtbl;

    interface IAcPpNavTreeNodeCollection
    {
        CONST_VTBL struct IAcPpNavTreeNodeCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcPpNavTreeNodeCollection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcPpNavTreeNodeCollection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcPpNavTreeNodeCollection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcPpNavTreeNodeCollection_AddNode(This,pNode)	\
    ( (This)->lpVtbl -> AddNode(This,pNode) ) 

#define IAcPpNavTreeNodeCollection_DeleteNode(This,pNode)	\
    ( (This)->lpVtbl -> DeleteNode(This,pNode) ) 

#define IAcPpNavTreeNodeCollection_DeleteAllNodes(This)	\
    ( (This)->lpVtbl -> DeleteAllNodes(This) ) 

#define IAcPpNavTreeNodeCollection_GetNodeCollectionIter(This,PIter)	\
    ( (This)->lpVtbl -> GetNodeCollectionIter(This,PIter) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcPpNavTreeNodeCollection_INTERFACE_DEFINED__ */


#ifndef __IAcPpNavTreeNode_INTERFACE_DEFINED__
#define __IAcPpNavTreeNode_INTERFACE_DEFINED__

/* interface IAcPpNavTreeNode */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcPpNavTreeNode;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("95EC1B09-245A-4B5E-8305-87E015931AC2")
    IAcPpNavTreeNode : public IUnknown
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT __stdcall get_ID( 
            /* [retval][out] */ long *pID) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT __stdcall get_ParentID( 
            /* [retval][out] */ long *pID) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT __stdcall get_Label( 
            /* [retval][out] */ BSTR *pLabel) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT __stdcall get_LeftIconRes( 
            /* [retval][out] */ BSTR *pPath) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT __stdcall get_LeftIconResType( 
            /* [retval][out] */ unsigned long *pVal) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall GetObject( 
            VARIANT *pObject) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcPpNavTreeNodeVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcPpNavTreeNode * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcPpNavTreeNode * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcPpNavTreeNode * This);
        
        DECLSPEC_XFGVIRT(IAcPpNavTreeNode, get_ID)
        /* [helpstring][propget] */ HRESULT ( __stdcall *get_ID )( 
            IAcPpNavTreeNode * This,
            /* [retval][out] */ long *pID);
        
        DECLSPEC_XFGVIRT(IAcPpNavTreeNode, get_ParentID)
        /* [helpstring][propget] */ HRESULT ( __stdcall *get_ParentID )( 
            IAcPpNavTreeNode * This,
            /* [retval][out] */ long *pID);
        
        DECLSPEC_XFGVIRT(IAcPpNavTreeNode, get_Label)
        /* [helpstring][propget] */ HRESULT ( __stdcall *get_Label )( 
            IAcPpNavTreeNode * This,
            /* [retval][out] */ BSTR *pLabel);
        
        DECLSPEC_XFGVIRT(IAcPpNavTreeNode, get_LeftIconRes)
        /* [helpstring][propget] */ HRESULT ( __stdcall *get_LeftIconRes )( 
            IAcPpNavTreeNode * This,
            /* [retval][out] */ BSTR *pPath);
        
        DECLSPEC_XFGVIRT(IAcPpNavTreeNode, get_LeftIconResType)
        /* [helpstring][propget] */ HRESULT ( __stdcall *get_LeftIconResType )( 
            IAcPpNavTreeNode * This,
            /* [retval][out] */ unsigned long *pVal);
        
        DECLSPEC_XFGVIRT(IAcPpNavTreeNode, GetObject)
        /* [helpstring] */ HRESULT ( __stdcall *GetObject )( 
            IAcPpNavTreeNode * This,
            VARIANT *pObject);
        
        END_INTERFACE
    } IAcPpNavTreeNodeVtbl;

    interface IAcPpNavTreeNode
    {
        CONST_VTBL struct IAcPpNavTreeNodeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcPpNavTreeNode_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcPpNavTreeNode_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcPpNavTreeNode_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcPpNavTreeNode_get_ID(This,pID)	\
    ( (This)->lpVtbl -> get_ID(This,pID) ) 

#define IAcPpNavTreeNode_get_ParentID(This,pID)	\
    ( (This)->lpVtbl -> get_ParentID(This,pID) ) 

#define IAcPpNavTreeNode_get_Label(This,pLabel)	\
    ( (This)->lpVtbl -> get_Label(This,pLabel) ) 

#define IAcPpNavTreeNode_get_LeftIconRes(This,pPath)	\
    ( (This)->lpVtbl -> get_LeftIconRes(This,pPath) ) 

#define IAcPpNavTreeNode_get_LeftIconResType(This,pVal)	\
    ( (This)->lpVtbl -> get_LeftIconResType(This,pVal) ) 

#define IAcPpNavTreeNode_GetObject(This,pObject)	\
    ( (This)->lpVtbl -> GetObject(This,pObject) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcPpNavTreeNode_INTERFACE_DEFINED__ */


#ifndef __IAcPpNavTreeNodeCollectionIter_INTERFACE_DEFINED__
#define __IAcPpNavTreeNodeCollectionIter_INTERFACE_DEFINED__

/* interface IAcPpNavTreeNodeCollectionIter */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcPpNavTreeNodeCollectionIter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4AD85C7A-96C1-49B3-AC62-88DCFC3EB2AC")
    IAcPpNavTreeNodeCollectionIter : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT __stdcall Start( void) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall Next( void) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall Current( 
            /* [out] */ IAcPpNavTreeNode **pNode) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall Done( 
            /* [out] */ VARIANT_BOOL *pBool) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcPpNavTreeNodeCollectionIterVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcPpNavTreeNodeCollectionIter * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcPpNavTreeNodeCollectionIter * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcPpNavTreeNodeCollectionIter * This);
        
        DECLSPEC_XFGVIRT(IAcPpNavTreeNodeCollectionIter, Start)
        /* [helpstring] */ HRESULT ( __stdcall *Start )( 
            IAcPpNavTreeNodeCollectionIter * This);
        
        DECLSPEC_XFGVIRT(IAcPpNavTreeNodeCollectionIter, Next)
        /* [helpstring] */ HRESULT ( __stdcall *Next )( 
            IAcPpNavTreeNodeCollectionIter * This);
        
        DECLSPEC_XFGVIRT(IAcPpNavTreeNodeCollectionIter, Current)
        /* [helpstring] */ HRESULT ( __stdcall *Current )( 
            IAcPpNavTreeNodeCollectionIter * This,
            /* [out] */ IAcPpNavTreeNode **pNode);
        
        DECLSPEC_XFGVIRT(IAcPpNavTreeNodeCollectionIter, Done)
        /* [helpstring] */ HRESULT ( __stdcall *Done )( 
            IAcPpNavTreeNodeCollectionIter * This,
            /* [out] */ VARIANT_BOOL *pBool);
        
        END_INTERFACE
    } IAcPpNavTreeNodeCollectionIterVtbl;

    interface IAcPpNavTreeNodeCollectionIter
    {
        CONST_VTBL struct IAcPpNavTreeNodeCollectionIterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcPpNavTreeNodeCollectionIter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcPpNavTreeNodeCollectionIter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcPpNavTreeNodeCollectionIter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcPpNavTreeNodeCollectionIter_Start(This)	\
    ( (This)->lpVtbl -> Start(This) ) 

#define IAcPpNavTreeNodeCollectionIter_Next(This)	\
    ( (This)->lpVtbl -> Next(This) ) 

#define IAcPpNavTreeNodeCollectionIter_Current(This,pNode)	\
    ( (This)->lpVtbl -> Current(This,pNode) ) 

#define IAcPpNavTreeNodeCollectionIter_Done(This,pBool)	\
    ( (This)->lpVtbl -> Done(This,pBool) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcPpNavTreeNodeCollectionIter_INTERFACE_DEFINED__ */


#ifndef __IAcPpNavTreeCmdBtnCollection_INTERFACE_DEFINED__
#define __IAcPpNavTreeCmdBtnCollection_INTERFACE_DEFINED__

/* interface IAcPpNavTreeCmdBtnCollection */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcPpNavTreeCmdBtnCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4D6DF14F-A2CA-4B71-8C71-318A911A7EA5")
    IAcPpNavTreeCmdBtnCollection : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT __stdcall AddButton( 
            /* [in] */ IAcPpNavTreeCmdBtn *pBtn) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall DeleteButton( 
            /* [in] */ IAcPpNavTreeCmdBtn *pBtn) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall DeleteAllButtons( void) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall GetCmdBtnCollectionIter( 
            /* [retval][out] */ IAcPpNavTreeCmdBtnCollectionIter **PIter) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcPpNavTreeCmdBtnCollectionVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcPpNavTreeCmdBtnCollection * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcPpNavTreeCmdBtnCollection * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcPpNavTreeCmdBtnCollection * This);
        
        DECLSPEC_XFGVIRT(IAcPpNavTreeCmdBtnCollection, AddButton)
        /* [helpstring] */ HRESULT ( __stdcall *AddButton )( 
            IAcPpNavTreeCmdBtnCollection * This,
            /* [in] */ IAcPpNavTreeCmdBtn *pBtn);
        
        DECLSPEC_XFGVIRT(IAcPpNavTreeCmdBtnCollection, DeleteButton)
        /* [helpstring] */ HRESULT ( __stdcall *DeleteButton )( 
            IAcPpNavTreeCmdBtnCollection * This,
            /* [in] */ IAcPpNavTreeCmdBtn *pBtn);
        
        DECLSPEC_XFGVIRT(IAcPpNavTreeCmdBtnCollection, DeleteAllButtons)
        /* [helpstring] */ HRESULT ( __stdcall *DeleteAllButtons )( 
            IAcPpNavTreeCmdBtnCollection * This);
        
        DECLSPEC_XFGVIRT(IAcPpNavTreeCmdBtnCollection, GetCmdBtnCollectionIter)
        /* [helpstring] */ HRESULT ( __stdcall *GetCmdBtnCollectionIter )( 
            IAcPpNavTreeCmdBtnCollection * This,
            /* [retval][out] */ IAcPpNavTreeCmdBtnCollectionIter **PIter);
        
        END_INTERFACE
    } IAcPpNavTreeCmdBtnCollectionVtbl;

    interface IAcPpNavTreeCmdBtnCollection
    {
        CONST_VTBL struct IAcPpNavTreeCmdBtnCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcPpNavTreeCmdBtnCollection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcPpNavTreeCmdBtnCollection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcPpNavTreeCmdBtnCollection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcPpNavTreeCmdBtnCollection_AddButton(This,pBtn)	\
    ( (This)->lpVtbl -> AddButton(This,pBtn) ) 

#define IAcPpNavTreeCmdBtnCollection_DeleteButton(This,pBtn)	\
    ( (This)->lpVtbl -> DeleteButton(This,pBtn) ) 

#define IAcPpNavTreeCmdBtnCollection_DeleteAllButtons(This)	\
    ( (This)->lpVtbl -> DeleteAllButtons(This) ) 

#define IAcPpNavTreeCmdBtnCollection_GetCmdBtnCollectionIter(This,PIter)	\
    ( (This)->lpVtbl -> GetCmdBtnCollectionIter(This,PIter) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcPpNavTreeCmdBtnCollection_INTERFACE_DEFINED__ */


#ifndef __IAcPpNavTreeCmdBtn_INTERFACE_DEFINED__
#define __IAcPpNavTreeCmdBtn_INTERFACE_DEFINED__

/* interface IAcPpNavTreeCmdBtn */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcPpNavTreeCmdBtn;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9FA4BA9E-58DC-43E1-83F3-AD2A97CA70AB")
    IAcPpNavTreeCmdBtn : public IUnknown
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT __stdcall get_Name( 
            /* [retval][out] */ BSTR *pName) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall GetBtnImage( 
            /* [out] */ BSTR *pPath,
            /* [out] */ unsigned long *pImgType) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall Execute( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcPpNavTreeCmdBtnVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcPpNavTreeCmdBtn * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcPpNavTreeCmdBtn * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcPpNavTreeCmdBtn * This);
        
        DECLSPEC_XFGVIRT(IAcPpNavTreeCmdBtn, get_Name)
        /* [helpstring][propget] */ HRESULT ( __stdcall *get_Name )( 
            IAcPpNavTreeCmdBtn * This,
            /* [retval][out] */ BSTR *pName);
        
        DECLSPEC_XFGVIRT(IAcPpNavTreeCmdBtn, GetBtnImage)
        /* [helpstring] */ HRESULT ( __stdcall *GetBtnImage )( 
            IAcPpNavTreeCmdBtn * This,
            /* [out] */ BSTR *pPath,
            /* [out] */ unsigned long *pImgType);
        
        DECLSPEC_XFGVIRT(IAcPpNavTreeCmdBtn, Execute)
        /* [helpstring] */ HRESULT ( __stdcall *Execute )( 
            IAcPpNavTreeCmdBtn * This);
        
        END_INTERFACE
    } IAcPpNavTreeCmdBtnVtbl;

    interface IAcPpNavTreeCmdBtn
    {
        CONST_VTBL struct IAcPpNavTreeCmdBtnVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcPpNavTreeCmdBtn_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcPpNavTreeCmdBtn_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcPpNavTreeCmdBtn_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcPpNavTreeCmdBtn_get_Name(This,pName)	\
    ( (This)->lpVtbl -> get_Name(This,pName) ) 

#define IAcPpNavTreeCmdBtn_GetBtnImage(This,pPath,pImgType)	\
    ( (This)->lpVtbl -> GetBtnImage(This,pPath,pImgType) ) 

#define IAcPpNavTreeCmdBtn_Execute(This)	\
    ( (This)->lpVtbl -> Execute(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcPpNavTreeCmdBtn_INTERFACE_DEFINED__ */


#ifndef __IAcPpNavTreeCmdBtnCollectionIter_INTERFACE_DEFINED__
#define __IAcPpNavTreeCmdBtnCollectionIter_INTERFACE_DEFINED__

/* interface IAcPpNavTreeCmdBtnCollectionIter */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcPpNavTreeCmdBtnCollectionIter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("29DF6149-8A8B-4D6E-807C-84A1DA8B171B")
    IAcPpNavTreeCmdBtnCollectionIter : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT __stdcall Start( void) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall Next( void) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall Current( 
            /* [out] */ IAcPpNavTreeCmdBtn **pNode) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall Done( 
            /* [out] */ VARIANT_BOOL *pBool) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcPpNavTreeCmdBtnCollectionIterVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcPpNavTreeCmdBtnCollectionIter * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcPpNavTreeCmdBtnCollectionIter * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcPpNavTreeCmdBtnCollectionIter * This);
        
        DECLSPEC_XFGVIRT(IAcPpNavTreeCmdBtnCollectionIter, Start)
        /* [helpstring] */ HRESULT ( __stdcall *Start )( 
            IAcPpNavTreeCmdBtnCollectionIter * This);
        
        DECLSPEC_XFGVIRT(IAcPpNavTreeCmdBtnCollectionIter, Next)
        /* [helpstring] */ HRESULT ( __stdcall *Next )( 
            IAcPpNavTreeCmdBtnCollectionIter * This);
        
        DECLSPEC_XFGVIRT(IAcPpNavTreeCmdBtnCollectionIter, Current)
        /* [helpstring] */ HRESULT ( __stdcall *Current )( 
            IAcPpNavTreeCmdBtnCollectionIter * This,
            /* [out] */ IAcPpNavTreeCmdBtn **pNode);
        
        DECLSPEC_XFGVIRT(IAcPpNavTreeCmdBtnCollectionIter, Done)
        /* [helpstring] */ HRESULT ( __stdcall *Done )( 
            IAcPpNavTreeCmdBtnCollectionIter * This,
            /* [out] */ VARIANT_BOOL *pBool);
        
        END_INTERFACE
    } IAcPpNavTreeCmdBtnCollectionIterVtbl;

    interface IAcPpNavTreeCmdBtnCollectionIter
    {
        CONST_VTBL struct IAcPpNavTreeCmdBtnCollectionIterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcPpNavTreeCmdBtnCollectionIter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcPpNavTreeCmdBtnCollectionIter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcPpNavTreeCmdBtnCollectionIter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcPpNavTreeCmdBtnCollectionIter_Start(This)	\
    ( (This)->lpVtbl -> Start(This) ) 

#define IAcPpNavTreeCmdBtnCollectionIter_Next(This)	\
    ( (This)->lpVtbl -> Next(This) ) 

#define IAcPpNavTreeCmdBtnCollectionIter_Current(This,pNode)	\
    ( (This)->lpVtbl -> Current(This,pNode) ) 

#define IAcPpNavTreeCmdBtnCollectionIter_Done(This,pBool)	\
    ( (This)->lpVtbl -> Done(This,pBool) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcPpNavTreeCmdBtnCollectionIter_INTERFACE_DEFINED__ */


#ifndef __IAcPpNavTreeEvents_INTERFACE_DEFINED__
#define __IAcPpNavTreeEvents_INTERFACE_DEFINED__

/* interface IAcPpNavTreeEvents */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_IAcPpNavTreeEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E484401D-0C76-405D-8E4F-1C7C8B887150")
    IAcPpNavTreeEvents : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT __stdcall OnSelectionChanged( 
            /* [in] */ VARIANT *pIntArray,
            /* [out] */ VARIANT *pObjUnkArray,
            /* [out][in] */ VARIANT_BOOL *bHandled) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall OnDblClickTreeItem( 
            /* [in] */ unsigned long index,
            /* [in] */ unsigned int nResourceId) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcPpNavTreeEventsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcPpNavTreeEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcPpNavTreeEvents * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcPpNavTreeEvents * This);
        
        DECLSPEC_XFGVIRT(IAcPpNavTreeEvents, OnSelectionChanged)
        /* [helpstring] */ HRESULT ( __stdcall *OnSelectionChanged )( 
            IAcPpNavTreeEvents * This,
            /* [in] */ VARIANT *pIntArray,
            /* [out] */ VARIANT *pObjUnkArray,
            /* [out][in] */ VARIANT_BOOL *bHandled);
        
        DECLSPEC_XFGVIRT(IAcPpNavTreeEvents, OnDblClickTreeItem)
        /* [helpstring] */ HRESULT ( __stdcall *OnDblClickTreeItem )( 
            IAcPpNavTreeEvents * This,
            /* [in] */ unsigned long index,
            /* [in] */ unsigned int nResourceId);
        
        END_INTERFACE
    } IAcPpNavTreeEventsVtbl;

    interface IAcPpNavTreeEvents
    {
        CONST_VTBL struct IAcPpNavTreeEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcPpNavTreeEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcPpNavTreeEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcPpNavTreeEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcPpNavTreeEvents_OnSelectionChanged(This,pIntArray,pObjUnkArray,bHandled)	\
    ( (This)->lpVtbl -> OnSelectionChanged(This,pIntArray,pObjUnkArray,bHandled) ) 

#define IAcPpNavTreeEvents_OnDblClickTreeItem(This,index,nResourceId)	\
    ( (This)->lpVtbl -> OnDblClickTreeItem(This,index,nResourceId) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcPpNavTreeEvents_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_AcPpAcadInput;

#ifdef __cplusplus

class DECLSPEC_UUID("E3CC8042-C28D-4B35-B916-448ED743BF36")
AcPpAcadInput;
#endif

EXTERN_C const CLSID CLSID_AcPpPaletteSet;

#ifdef __cplusplus

class DECLSPEC_UUID("21272901-1B34-4109-BB98-9DD3D69CD5AF")
AcPpPaletteSet;
#endif

EXTERN_C const CLSID CLSID_AcPpPalette;

#ifdef __cplusplus

class DECLSPEC_UUID("FDA75C1F-4D75-486F-A9E7-27590D5005A2")
AcPpPalette;
#endif

EXTERN_C const CLSID CLSID_AcPpPalette2;

#ifdef __cplusplus

class DECLSPEC_UUID("13443EE4-F670-4C18-BA5E-4B6ADCCC011A")
AcPpPalette2;
#endif

EXTERN_C const CLSID CLSID_AcPpNavTree;

#ifdef __cplusplus

class DECLSPEC_UUID("AFB93FAA-4F17-4981-87E9-02F71B1E350D")
AcPpNavTree;
#endif

EXTERN_C const CLSID CLSID_AcPpNavTreeNode;

#ifdef __cplusplus

class DECLSPEC_UUID("EB2C7963-4CA1-41C2-90EB-93AD55518905")
AcPpNavTreeNode;
#endif
#endif /* __AcPpLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif





/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Mon Nov 11 18:53:23 2013
 */
/* Compiler settings for PrinterService.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __PrinterService_h__
#define __PrinterService_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IPrinterService_FWD_DEFINED__
#define __IPrinterService_FWD_DEFINED__
typedef interface IPrinterService IPrinterService;

#endif 	/* __IPrinterService_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IPrinterService_INTERFACE_DEFINED__
#define __IPrinterService_INTERFACE_DEFINED__

/* interface IPrinterService */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPrinterService;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9EC071A0-03B3-4c4b-859A-52326D7923DA")
    IPrinterService : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SendDocument( 
            /* [in] */ LONG body,
            /* [out] */ LONG *jobId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CancelJob( 
            /* [in] */ LONG jobId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPrinterElements( 
            /* [in] */ INT opcode,
            /* [out] */ WCHAR **bodyOut) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPrinterServiceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPrinterService * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPrinterService * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPrinterService * This);
        
        HRESULT ( STDMETHODCALLTYPE *SendDocument )( 
            IPrinterService * This,
            /* [in] */ LONG body,
            /* [out] */ LONG *jobId);
        
        HRESULT ( STDMETHODCALLTYPE *CancelJob )( 
            IPrinterService * This,
            /* [in] */ LONG jobId);
        
        HRESULT ( STDMETHODCALLTYPE *GetPrinterElements )( 
            IPrinterService * This,
            /* [in] */ INT opcode,
            /* [out] */ WCHAR **bodyOut);
        
        END_INTERFACE
    } IPrinterServiceVtbl;

    interface IPrinterService
    {
        CONST_VTBL struct IPrinterServiceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPrinterService_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPrinterService_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPrinterService_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPrinterService_SendDocument(This,body,jobId)	\
    ( (This)->lpVtbl -> SendDocument(This,body,jobId) ) 

#define IPrinterService_CancelJob(This,jobId)	\
    ( (This)->lpVtbl -> CancelJob(This,jobId) ) 

#define IPrinterService_GetPrinterElements(This,opcode,bodyOut)	\
    ( (This)->lpVtbl -> GetPrinterElements(This,opcode,bodyOut) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPrinterService_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



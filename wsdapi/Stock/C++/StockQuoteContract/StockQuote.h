

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0595 */
/* at Sun Dec 15 01:00:50 2013
 */
/* Compiler settings for StockQuote.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0595 
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

#ifndef __StockQuote_h__
#define __StockQuote_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IStockQuote_FWD_DEFINED__
#define __IStockQuote_FWD_DEFINED__
typedef interface IStockQuote IStockQuote;

#endif 	/* __IStockQuote_FWD_DEFINED__ */


#ifndef __IStockQuoteProxy_FWD_DEFINED__
#define __IStockQuoteProxy_FWD_DEFINED__
typedef interface IStockQuoteProxy IStockQuoteProxy;

#endif 	/* __IStockQuoteProxy_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "wsdattachment.h"
#include "wsdclient.h"
#include "wsdhost.h"
#include "StockQuoteTypes.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_StockQuote_0000_0000 */
/* [local] */ 





extern RPC_IF_HANDLE __MIDL_itf_StockQuote_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_StockQuote_0000_0000_v0_0_s_ifspec;

#ifndef __IStockQuote_INTERFACE_DEFINED__
#define __IStockQuote_INTERFACE_DEFINED__

/* interface IStockQuote */
/* [local][restricted][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IStockQuote;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("fb368bf5-f7f0-4071-9549-d1c567c74336")
    IStockQuote : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetLastTradePrice( 
            /* [in] */ TRADE_PRICE_REQUEST *body,
            /* [out] */ TRADE_PRICE **bodyOut) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IStockQuoteVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IStockQuote * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IStockQuote * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IStockQuote * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetLastTradePrice )( 
            IStockQuote * This,
            /* [in] */ TRADE_PRICE_REQUEST *body,
            /* [out] */ TRADE_PRICE **bodyOut);
        
        END_INTERFACE
    } IStockQuoteVtbl;

    interface IStockQuote
    {
        CONST_VTBL struct IStockQuoteVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IStockQuote_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IStockQuote_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IStockQuote_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IStockQuote_GetLastTradePrice(This,body,bodyOut)	\
    ( (This)->lpVtbl -> GetLastTradePrice(This,body,bodyOut) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IStockQuote_INTERFACE_DEFINED__ */


#ifndef __IStockQuoteProxy_INTERFACE_DEFINED__
#define __IStockQuoteProxy_INTERFACE_DEFINED__

/* interface IStockQuoteProxy */
/* [local][restricted][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IStockQuoteProxy;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c22359e-f0ae-43bf-8195-11cf207318b3")
    IStockQuoteProxy : public IStockQuote
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Init( 
            IWSDServiceProxy *genericProxy) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BeginGetLastTradePrice( 
            /* [in] */ TRADE_PRICE_REQUEST *body,
            /* [in] */ IUnknown *AsyncState,
            /* [in] */ IWSDAsyncCallback *AsyncCallback,
            /* [out] */ IWSDAsyncResult **AsyncResultOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EndGetLastTradePrice( 
            /* [in] */ IWSDAsyncResult *AsyncResult,
            /* [out] */ TRADE_PRICE **bodyOut) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IStockQuoteProxyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IStockQuoteProxy * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IStockQuoteProxy * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IStockQuoteProxy * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetLastTradePrice )( 
            IStockQuoteProxy * This,
            /* [in] */ TRADE_PRICE_REQUEST *body,
            /* [out] */ TRADE_PRICE **bodyOut);
        
        HRESULT ( STDMETHODCALLTYPE *Init )( 
            IStockQuoteProxy * This,
            IWSDServiceProxy *genericProxy);
        
        HRESULT ( STDMETHODCALLTYPE *BeginGetLastTradePrice )( 
            IStockQuoteProxy * This,
            /* [in] */ TRADE_PRICE_REQUEST *body,
            /* [in] */ IUnknown *AsyncState,
            /* [in] */ IWSDAsyncCallback *AsyncCallback,
            /* [out] */ IWSDAsyncResult **AsyncResultOut);
        
        HRESULT ( STDMETHODCALLTYPE *EndGetLastTradePrice )( 
            IStockQuoteProxy * This,
            /* [in] */ IWSDAsyncResult *AsyncResult,
            /* [out] */ TRADE_PRICE **bodyOut);
        
        END_INTERFACE
    } IStockQuoteProxyVtbl;

    interface IStockQuoteProxy
    {
        CONST_VTBL struct IStockQuoteProxyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IStockQuoteProxy_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IStockQuoteProxy_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IStockQuoteProxy_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IStockQuoteProxy_GetLastTradePrice(This,body,bodyOut)	\
    ( (This)->lpVtbl -> GetLastTradePrice(This,body,bodyOut) ) 


#define IStockQuoteProxy_Init(This,genericProxy)	\
    ( (This)->lpVtbl -> Init(This,genericProxy) ) 

#define IStockQuoteProxy_BeginGetLastTradePrice(This,body,AsyncState,AsyncCallback,AsyncResultOut)	\
    ( (This)->lpVtbl -> BeginGetLastTradePrice(This,body,AsyncState,AsyncCallback,AsyncResultOut) ) 

#define IStockQuoteProxy_EndGetLastTradePrice(This,AsyncResult,bodyOut)	\
    ( (This)->lpVtbl -> EndGetLastTradePrice(This,AsyncResult,bodyOut) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IStockQuoteProxy_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



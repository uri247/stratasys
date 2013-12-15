

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Mon Nov 11 18:53:24 2013
 */
/* Compiler settings for PrinterServiceType.idl:
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

#ifndef __PrinterServiceType_h__
#define __PrinterServiceType_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IPrinterServiceType_FWD_DEFINED__
#define __IPrinterServiceType_FWD_DEFINED__
typedef interface IPrinterServiceType IPrinterServiceType;

#endif 	/* __IPrinterServiceType_FWD_DEFINED__ */


#ifndef __IPrinterServiceTypeProxy_FWD_DEFINED__
#define __IPrinterServiceTypeProxy_FWD_DEFINED__
typedef interface IPrinterServiceTypeProxy IPrinterServiceTypeProxy;

#endif 	/* __IPrinterServiceTypeProxy_FWD_DEFINED__ */


#ifndef __IPrinterServiceTypeEventNotify_FWD_DEFINED__
#define __IPrinterServiceTypeEventNotify_FWD_DEFINED__
typedef interface IPrinterServiceTypeEventNotify IPrinterServiceTypeEventNotify;

#endif 	/* __IPrinterServiceTypeEventNotify_FWD_DEFINED__ */


#ifndef __IPrinterServiceV12Type_FWD_DEFINED__
#define __IPrinterServiceV12Type_FWD_DEFINED__
typedef interface IPrinterServiceV12Type IPrinterServiceV12Type;

#endif 	/* __IPrinterServiceV12Type_FWD_DEFINED__ */


#ifndef __IPrinterServiceV12TypeProxy_FWD_DEFINED__
#define __IPrinterServiceV12TypeProxy_FWD_DEFINED__
typedef interface IPrinterServiceV12TypeProxy IPrinterServiceV12TypeProxy;

#endif 	/* __IPrinterServiceV12TypeProxy_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "wsdattachment.h"
#include "wsdclient.h"
#include "wsdhost.h"
#include "PrinterServiceTypeTypes.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_PrinterServiceType_0000_0000 */
/* [local] */ 








extern RPC_IF_HANDLE __MIDL_itf_PrinterServiceType_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_PrinterServiceType_0000_0000_v0_0_s_ifspec;

#ifndef __IPrinterServiceType_INTERFACE_DEFINED__
#define __IPrinterServiceType_INTERFACE_DEFINED__

/* interface IPrinterServiceType */
/* [local][restricted][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPrinterServiceType;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9d6aa8be-71f6-46d0-944b-121c678bab48")
    IPrinterServiceType : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreatePrintJob( 
            /* [in] */ CREATE_PRINT_JOB_REQUEST_TYPE *body,
            /* [out] */ CREATE_PRINT_JOB_RESPONSE_TYPE **bodyOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SendDocument( 
            /* [in] */ SEND_DOCUMENT_REQUEST_TYPE *body,
            /* [out] */ SEND_DOCUMENT_RESPONSE_TYPE **bodyOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddDocument( 
            /* [in] */ ADD_DOCUMENT_REQUEST_TYPE *body,
            /* [out] */ ADD_DOCUMENT_RESPONSE_TYPE **bodyOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CancelJob( 
            /* [in] */ CANCEL_JOB_REQUEST_TYPE *body,
            /* [out] */ CANCEL_JOB_RESPONSE_TYPE **bodyOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPrinterElements( 
            /* [in] */ GET_PRINTER_ELEMENTS_REQUEST_TYPE *body,
            /* [out] */ GET_PRINTER_ELEMENTS_RESPONSE_TYPE **bodyOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetJobElements( 
            /* [in] */ GET_JOB_ELEMENTS_REQUEST_TYPE *body,
            /* [out] */ GET_JOB_ELEMENTS_RESPONSE_TYPE **bodyOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetActiveJobs( 
            /* [in] */ GET_ACTIVE_JOBS_REQUEST_TYPE *body,
            /* [out] */ GET_ACTIVE_JOBS_RESPONSE_TYPE **bodyOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetJobHistory( 
            /* [in] */ GET_JOB_HISTORY_REQUEST_TYPE *body,
            /* [out] */ GET_JOB_HISTORY_RESPONSE_TYPE **bodyOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetEventRate( 
            /* [in] */ SET_EVENT_RATE_REQUEST_TYPE *body,
            /* [out] */ SET_EVENT_RATE_RESPONSE_TYPE **bodyOut) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPrinterServiceTypeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPrinterServiceType * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPrinterServiceType * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPrinterServiceType * This);
        
        HRESULT ( STDMETHODCALLTYPE *CreatePrintJob )( 
            IPrinterServiceType * This,
            /* [in] */ CREATE_PRINT_JOB_REQUEST_TYPE *body,
            /* [out] */ CREATE_PRINT_JOB_RESPONSE_TYPE **bodyOut);
        
        HRESULT ( STDMETHODCALLTYPE *SendDocument )( 
            IPrinterServiceType * This,
            /* [in] */ SEND_DOCUMENT_REQUEST_TYPE *body,
            /* [out] */ SEND_DOCUMENT_RESPONSE_TYPE **bodyOut);
        
        HRESULT ( STDMETHODCALLTYPE *AddDocument )( 
            IPrinterServiceType * This,
            /* [in] */ ADD_DOCUMENT_REQUEST_TYPE *body,
            /* [out] */ ADD_DOCUMENT_RESPONSE_TYPE **bodyOut);
        
        HRESULT ( STDMETHODCALLTYPE *CancelJob )( 
            IPrinterServiceType * This,
            /* [in] */ CANCEL_JOB_REQUEST_TYPE *body,
            /* [out] */ CANCEL_JOB_RESPONSE_TYPE **bodyOut);
        
        HRESULT ( STDMETHODCALLTYPE *GetPrinterElements )( 
            IPrinterServiceType * This,
            /* [in] */ GET_PRINTER_ELEMENTS_REQUEST_TYPE *body,
            /* [out] */ GET_PRINTER_ELEMENTS_RESPONSE_TYPE **bodyOut);
        
        HRESULT ( STDMETHODCALLTYPE *GetJobElements )( 
            IPrinterServiceType * This,
            /* [in] */ GET_JOB_ELEMENTS_REQUEST_TYPE *body,
            /* [out] */ GET_JOB_ELEMENTS_RESPONSE_TYPE **bodyOut);
        
        HRESULT ( STDMETHODCALLTYPE *GetActiveJobs )( 
            IPrinterServiceType * This,
            /* [in] */ GET_ACTIVE_JOBS_REQUEST_TYPE *body,
            /* [out] */ GET_ACTIVE_JOBS_RESPONSE_TYPE **bodyOut);
        
        HRESULT ( STDMETHODCALLTYPE *GetJobHistory )( 
            IPrinterServiceType * This,
            /* [in] */ GET_JOB_HISTORY_REQUEST_TYPE *body,
            /* [out] */ GET_JOB_HISTORY_RESPONSE_TYPE **bodyOut);
        
        HRESULT ( STDMETHODCALLTYPE *SetEventRate )( 
            IPrinterServiceType * This,
            /* [in] */ SET_EVENT_RATE_REQUEST_TYPE *body,
            /* [out] */ SET_EVENT_RATE_RESPONSE_TYPE **bodyOut);
        
        END_INTERFACE
    } IPrinterServiceTypeVtbl;

    interface IPrinterServiceType
    {
        CONST_VTBL struct IPrinterServiceTypeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPrinterServiceType_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPrinterServiceType_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPrinterServiceType_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPrinterServiceType_CreatePrintJob(This,body,bodyOut)	\
    ( (This)->lpVtbl -> CreatePrintJob(This,body,bodyOut) ) 

#define IPrinterServiceType_SendDocument(This,body,bodyOut)	\
    ( (This)->lpVtbl -> SendDocument(This,body,bodyOut) ) 

#define IPrinterServiceType_AddDocument(This,body,bodyOut)	\
    ( (This)->lpVtbl -> AddDocument(This,body,bodyOut) ) 

#define IPrinterServiceType_CancelJob(This,body,bodyOut)	\
    ( (This)->lpVtbl -> CancelJob(This,body,bodyOut) ) 

#define IPrinterServiceType_GetPrinterElements(This,body,bodyOut)	\
    ( (This)->lpVtbl -> GetPrinterElements(This,body,bodyOut) ) 

#define IPrinterServiceType_GetJobElements(This,body,bodyOut)	\
    ( (This)->lpVtbl -> GetJobElements(This,body,bodyOut) ) 

#define IPrinterServiceType_GetActiveJobs(This,body,bodyOut)	\
    ( (This)->lpVtbl -> GetActiveJobs(This,body,bodyOut) ) 

#define IPrinterServiceType_GetJobHistory(This,body,bodyOut)	\
    ( (This)->lpVtbl -> GetJobHistory(This,body,bodyOut) ) 

#define IPrinterServiceType_SetEventRate(This,body,bodyOut)	\
    ( (This)->lpVtbl -> SetEventRate(This,body,bodyOut) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPrinterServiceType_INTERFACE_DEFINED__ */


#ifndef __IPrinterServiceTypeProxy_INTERFACE_DEFINED__
#define __IPrinterServiceTypeProxy_INTERFACE_DEFINED__

/* interface IPrinterServiceTypeProxy */
/* [local][restricted][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPrinterServiceTypeProxy;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2a470947-2531-4e55-8242-4198f4186ba4")
    IPrinterServiceTypeProxy : public IPrinterServiceType
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Init( 
            IWSDServiceProxy *genericProxy) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BeginCreatePrintJob( 
            /* [in] */ CREATE_PRINT_JOB_REQUEST_TYPE *body,
            /* [in] */ IUnknown *AsyncState,
            /* [in] */ IWSDAsyncCallback *AsyncCallback,
            /* [out] */ IWSDAsyncResult **AsyncResultOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EndCreatePrintJob( 
            /* [in] */ IWSDAsyncResult *AsyncResult,
            /* [out] */ CREATE_PRINT_JOB_RESPONSE_TYPE **bodyOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BeginSendDocument( 
            /* [in] */ SEND_DOCUMENT_REQUEST_TYPE *body,
            /* [in] */ IUnknown *AsyncState,
            /* [in] */ IWSDAsyncCallback *AsyncCallback,
            /* [out] */ IWSDAsyncResult **AsyncResultOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EndSendDocument( 
            /* [in] */ IWSDAsyncResult *AsyncResult,
            /* [out] */ SEND_DOCUMENT_RESPONSE_TYPE **bodyOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BeginAddDocument( 
            /* [in] */ ADD_DOCUMENT_REQUEST_TYPE *body,
            /* [in] */ IUnknown *AsyncState,
            /* [in] */ IWSDAsyncCallback *AsyncCallback,
            /* [out] */ IWSDAsyncResult **AsyncResultOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EndAddDocument( 
            /* [in] */ IWSDAsyncResult *AsyncResult,
            /* [out] */ ADD_DOCUMENT_RESPONSE_TYPE **bodyOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BeginCancelJob( 
            /* [in] */ CANCEL_JOB_REQUEST_TYPE *body,
            /* [in] */ IUnknown *AsyncState,
            /* [in] */ IWSDAsyncCallback *AsyncCallback,
            /* [out] */ IWSDAsyncResult **AsyncResultOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EndCancelJob( 
            /* [in] */ IWSDAsyncResult *AsyncResult,
            /* [out] */ CANCEL_JOB_RESPONSE_TYPE **bodyOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BeginGetPrinterElements( 
            /* [in] */ GET_PRINTER_ELEMENTS_REQUEST_TYPE *body,
            /* [in] */ IUnknown *AsyncState,
            /* [in] */ IWSDAsyncCallback *AsyncCallback,
            /* [out] */ IWSDAsyncResult **AsyncResultOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EndGetPrinterElements( 
            /* [in] */ IWSDAsyncResult *AsyncResult,
            /* [out] */ GET_PRINTER_ELEMENTS_RESPONSE_TYPE **bodyOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BeginGetJobElements( 
            /* [in] */ GET_JOB_ELEMENTS_REQUEST_TYPE *body,
            /* [in] */ IUnknown *AsyncState,
            /* [in] */ IWSDAsyncCallback *AsyncCallback,
            /* [out] */ IWSDAsyncResult **AsyncResultOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EndGetJobElements( 
            /* [in] */ IWSDAsyncResult *AsyncResult,
            /* [out] */ GET_JOB_ELEMENTS_RESPONSE_TYPE **bodyOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BeginGetActiveJobs( 
            /* [in] */ GET_ACTIVE_JOBS_REQUEST_TYPE *body,
            /* [in] */ IUnknown *AsyncState,
            /* [in] */ IWSDAsyncCallback *AsyncCallback,
            /* [out] */ IWSDAsyncResult **AsyncResultOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EndGetActiveJobs( 
            /* [in] */ IWSDAsyncResult *AsyncResult,
            /* [out] */ GET_ACTIVE_JOBS_RESPONSE_TYPE **bodyOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BeginGetJobHistory( 
            /* [in] */ GET_JOB_HISTORY_REQUEST_TYPE *body,
            /* [in] */ IUnknown *AsyncState,
            /* [in] */ IWSDAsyncCallback *AsyncCallback,
            /* [out] */ IWSDAsyncResult **AsyncResultOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EndGetJobHistory( 
            /* [in] */ IWSDAsyncResult *AsyncResult,
            /* [out] */ GET_JOB_HISTORY_RESPONSE_TYPE **bodyOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BeginSetEventRate( 
            /* [in] */ SET_EVENT_RATE_REQUEST_TYPE *body,
            /* [in] */ IUnknown *AsyncState,
            /* [in] */ IWSDAsyncCallback *AsyncCallback,
            /* [out] */ IWSDAsyncResult **AsyncResultOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EndSetEventRate( 
            /* [in] */ IWSDAsyncResult *AsyncResult,
            /* [out] */ SET_EVENT_RATE_RESPONSE_TYPE **bodyOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SubscribeToPrinterElementsChangeEvent( 
            /* [in] */ IPrinterServiceTypeEventNotify *eventSink) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnsubscribeToPrinterElementsChangeEvent( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SubscribeToPrinterStatusSummaryEvent( 
            /* [in] */ IPrinterServiceTypeEventNotify *eventSink) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnsubscribeToPrinterStatusSummaryEvent( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SubscribeToPrinterStatusConditionEvent( 
            /* [in] */ IPrinterServiceTypeEventNotify *eventSink) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnsubscribeToPrinterStatusConditionEvent( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SubscribeToPrinterStatusConditionClearedEvent( 
            /* [in] */ IPrinterServiceTypeEventNotify *eventSink) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnsubscribeToPrinterStatusConditionClearedEvent( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SubscribeToJobStatusEvent( 
            /* [in] */ IPrinterServiceTypeEventNotify *eventSink) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnsubscribeToJobStatusEvent( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SubscribeToJobEndStateEvent( 
            /* [in] */ IPrinterServiceTypeEventNotify *eventSink) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnsubscribeToJobEndStateEvent( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPrinterServiceTypeProxyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPrinterServiceTypeProxy * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPrinterServiceTypeProxy * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPrinterServiceTypeProxy * This);
        
        HRESULT ( STDMETHODCALLTYPE *CreatePrintJob )( 
            IPrinterServiceTypeProxy * This,
            /* [in] */ CREATE_PRINT_JOB_REQUEST_TYPE *body,
            /* [out] */ CREATE_PRINT_JOB_RESPONSE_TYPE **bodyOut);
        
        HRESULT ( STDMETHODCALLTYPE *SendDocument )( 
            IPrinterServiceTypeProxy * This,
            /* [in] */ SEND_DOCUMENT_REQUEST_TYPE *body,
            /* [out] */ SEND_DOCUMENT_RESPONSE_TYPE **bodyOut);
        
        HRESULT ( STDMETHODCALLTYPE *AddDocument )( 
            IPrinterServiceTypeProxy * This,
            /* [in] */ ADD_DOCUMENT_REQUEST_TYPE *body,
            /* [out] */ ADD_DOCUMENT_RESPONSE_TYPE **bodyOut);
        
        HRESULT ( STDMETHODCALLTYPE *CancelJob )( 
            IPrinterServiceTypeProxy * This,
            /* [in] */ CANCEL_JOB_REQUEST_TYPE *body,
            /* [out] */ CANCEL_JOB_RESPONSE_TYPE **bodyOut);
        
        HRESULT ( STDMETHODCALLTYPE *GetPrinterElements )( 
            IPrinterServiceTypeProxy * This,
            /* [in] */ GET_PRINTER_ELEMENTS_REQUEST_TYPE *body,
            /* [out] */ GET_PRINTER_ELEMENTS_RESPONSE_TYPE **bodyOut);
        
        HRESULT ( STDMETHODCALLTYPE *GetJobElements )( 
            IPrinterServiceTypeProxy * This,
            /* [in] */ GET_JOB_ELEMENTS_REQUEST_TYPE *body,
            /* [out] */ GET_JOB_ELEMENTS_RESPONSE_TYPE **bodyOut);
        
        HRESULT ( STDMETHODCALLTYPE *GetActiveJobs )( 
            IPrinterServiceTypeProxy * This,
            /* [in] */ GET_ACTIVE_JOBS_REQUEST_TYPE *body,
            /* [out] */ GET_ACTIVE_JOBS_RESPONSE_TYPE **bodyOut);
        
        HRESULT ( STDMETHODCALLTYPE *GetJobHistory )( 
            IPrinterServiceTypeProxy * This,
            /* [in] */ GET_JOB_HISTORY_REQUEST_TYPE *body,
            /* [out] */ GET_JOB_HISTORY_RESPONSE_TYPE **bodyOut);
        
        HRESULT ( STDMETHODCALLTYPE *SetEventRate )( 
            IPrinterServiceTypeProxy * This,
            /* [in] */ SET_EVENT_RATE_REQUEST_TYPE *body,
            /* [out] */ SET_EVENT_RATE_RESPONSE_TYPE **bodyOut);
        
        HRESULT ( STDMETHODCALLTYPE *Init )( 
            IPrinterServiceTypeProxy * This,
            IWSDServiceProxy *genericProxy);
        
        HRESULT ( STDMETHODCALLTYPE *BeginCreatePrintJob )( 
            IPrinterServiceTypeProxy * This,
            /* [in] */ CREATE_PRINT_JOB_REQUEST_TYPE *body,
            /* [in] */ IUnknown *AsyncState,
            /* [in] */ IWSDAsyncCallback *AsyncCallback,
            /* [out] */ IWSDAsyncResult **AsyncResultOut);
        
        HRESULT ( STDMETHODCALLTYPE *EndCreatePrintJob )( 
            IPrinterServiceTypeProxy * This,
            /* [in] */ IWSDAsyncResult *AsyncResult,
            /* [out] */ CREATE_PRINT_JOB_RESPONSE_TYPE **bodyOut);
        
        HRESULT ( STDMETHODCALLTYPE *BeginSendDocument )( 
            IPrinterServiceTypeProxy * This,
            /* [in] */ SEND_DOCUMENT_REQUEST_TYPE *body,
            /* [in] */ IUnknown *AsyncState,
            /* [in] */ IWSDAsyncCallback *AsyncCallback,
            /* [out] */ IWSDAsyncResult **AsyncResultOut);
        
        HRESULT ( STDMETHODCALLTYPE *EndSendDocument )( 
            IPrinterServiceTypeProxy * This,
            /* [in] */ IWSDAsyncResult *AsyncResult,
            /* [out] */ SEND_DOCUMENT_RESPONSE_TYPE **bodyOut);
        
        HRESULT ( STDMETHODCALLTYPE *BeginAddDocument )( 
            IPrinterServiceTypeProxy * This,
            /* [in] */ ADD_DOCUMENT_REQUEST_TYPE *body,
            /* [in] */ IUnknown *AsyncState,
            /* [in] */ IWSDAsyncCallback *AsyncCallback,
            /* [out] */ IWSDAsyncResult **AsyncResultOut);
        
        HRESULT ( STDMETHODCALLTYPE *EndAddDocument )( 
            IPrinterServiceTypeProxy * This,
            /* [in] */ IWSDAsyncResult *AsyncResult,
            /* [out] */ ADD_DOCUMENT_RESPONSE_TYPE **bodyOut);
        
        HRESULT ( STDMETHODCALLTYPE *BeginCancelJob )( 
            IPrinterServiceTypeProxy * This,
            /* [in] */ CANCEL_JOB_REQUEST_TYPE *body,
            /* [in] */ IUnknown *AsyncState,
            /* [in] */ IWSDAsyncCallback *AsyncCallback,
            /* [out] */ IWSDAsyncResult **AsyncResultOut);
        
        HRESULT ( STDMETHODCALLTYPE *EndCancelJob )( 
            IPrinterServiceTypeProxy * This,
            /* [in] */ IWSDAsyncResult *AsyncResult,
            /* [out] */ CANCEL_JOB_RESPONSE_TYPE **bodyOut);
        
        HRESULT ( STDMETHODCALLTYPE *BeginGetPrinterElements )( 
            IPrinterServiceTypeProxy * This,
            /* [in] */ GET_PRINTER_ELEMENTS_REQUEST_TYPE *body,
            /* [in] */ IUnknown *AsyncState,
            /* [in] */ IWSDAsyncCallback *AsyncCallback,
            /* [out] */ IWSDAsyncResult **AsyncResultOut);
        
        HRESULT ( STDMETHODCALLTYPE *EndGetPrinterElements )( 
            IPrinterServiceTypeProxy * This,
            /* [in] */ IWSDAsyncResult *AsyncResult,
            /* [out] */ GET_PRINTER_ELEMENTS_RESPONSE_TYPE **bodyOut);
        
        HRESULT ( STDMETHODCALLTYPE *BeginGetJobElements )( 
            IPrinterServiceTypeProxy * This,
            /* [in] */ GET_JOB_ELEMENTS_REQUEST_TYPE *body,
            /* [in] */ IUnknown *AsyncState,
            /* [in] */ IWSDAsyncCallback *AsyncCallback,
            /* [out] */ IWSDAsyncResult **AsyncResultOut);
        
        HRESULT ( STDMETHODCALLTYPE *EndGetJobElements )( 
            IPrinterServiceTypeProxy * This,
            /* [in] */ IWSDAsyncResult *AsyncResult,
            /* [out] */ GET_JOB_ELEMENTS_RESPONSE_TYPE **bodyOut);
        
        HRESULT ( STDMETHODCALLTYPE *BeginGetActiveJobs )( 
            IPrinterServiceTypeProxy * This,
            /* [in] */ GET_ACTIVE_JOBS_REQUEST_TYPE *body,
            /* [in] */ IUnknown *AsyncState,
            /* [in] */ IWSDAsyncCallback *AsyncCallback,
            /* [out] */ IWSDAsyncResult **AsyncResultOut);
        
        HRESULT ( STDMETHODCALLTYPE *EndGetActiveJobs )( 
            IPrinterServiceTypeProxy * This,
            /* [in] */ IWSDAsyncResult *AsyncResult,
            /* [out] */ GET_ACTIVE_JOBS_RESPONSE_TYPE **bodyOut);
        
        HRESULT ( STDMETHODCALLTYPE *BeginGetJobHistory )( 
            IPrinterServiceTypeProxy * This,
            /* [in] */ GET_JOB_HISTORY_REQUEST_TYPE *body,
            /* [in] */ IUnknown *AsyncState,
            /* [in] */ IWSDAsyncCallback *AsyncCallback,
            /* [out] */ IWSDAsyncResult **AsyncResultOut);
        
        HRESULT ( STDMETHODCALLTYPE *EndGetJobHistory )( 
            IPrinterServiceTypeProxy * This,
            /* [in] */ IWSDAsyncResult *AsyncResult,
            /* [out] */ GET_JOB_HISTORY_RESPONSE_TYPE **bodyOut);
        
        HRESULT ( STDMETHODCALLTYPE *BeginSetEventRate )( 
            IPrinterServiceTypeProxy * This,
            /* [in] */ SET_EVENT_RATE_REQUEST_TYPE *body,
            /* [in] */ IUnknown *AsyncState,
            /* [in] */ IWSDAsyncCallback *AsyncCallback,
            /* [out] */ IWSDAsyncResult **AsyncResultOut);
        
        HRESULT ( STDMETHODCALLTYPE *EndSetEventRate )( 
            IPrinterServiceTypeProxy * This,
            /* [in] */ IWSDAsyncResult *AsyncResult,
            /* [out] */ SET_EVENT_RATE_RESPONSE_TYPE **bodyOut);
        
        HRESULT ( STDMETHODCALLTYPE *SubscribeToPrinterElementsChangeEvent )( 
            IPrinterServiceTypeProxy * This,
            /* [in] */ IPrinterServiceTypeEventNotify *eventSink);
        
        HRESULT ( STDMETHODCALLTYPE *UnsubscribeToPrinterElementsChangeEvent )( 
            IPrinterServiceTypeProxy * This);
        
        HRESULT ( STDMETHODCALLTYPE *SubscribeToPrinterStatusSummaryEvent )( 
            IPrinterServiceTypeProxy * This,
            /* [in] */ IPrinterServiceTypeEventNotify *eventSink);
        
        HRESULT ( STDMETHODCALLTYPE *UnsubscribeToPrinterStatusSummaryEvent )( 
            IPrinterServiceTypeProxy * This);
        
        HRESULT ( STDMETHODCALLTYPE *SubscribeToPrinterStatusConditionEvent )( 
            IPrinterServiceTypeProxy * This,
            /* [in] */ IPrinterServiceTypeEventNotify *eventSink);
        
        HRESULT ( STDMETHODCALLTYPE *UnsubscribeToPrinterStatusConditionEvent )( 
            IPrinterServiceTypeProxy * This);
        
        HRESULT ( STDMETHODCALLTYPE *SubscribeToPrinterStatusConditionClearedEvent )( 
            IPrinterServiceTypeProxy * This,
            /* [in] */ IPrinterServiceTypeEventNotify *eventSink);
        
        HRESULT ( STDMETHODCALLTYPE *UnsubscribeToPrinterStatusConditionClearedEvent )( 
            IPrinterServiceTypeProxy * This);
        
        HRESULT ( STDMETHODCALLTYPE *SubscribeToJobStatusEvent )( 
            IPrinterServiceTypeProxy * This,
            /* [in] */ IPrinterServiceTypeEventNotify *eventSink);
        
        HRESULT ( STDMETHODCALLTYPE *UnsubscribeToJobStatusEvent )( 
            IPrinterServiceTypeProxy * This);
        
        HRESULT ( STDMETHODCALLTYPE *SubscribeToJobEndStateEvent )( 
            IPrinterServiceTypeProxy * This,
            /* [in] */ IPrinterServiceTypeEventNotify *eventSink);
        
        HRESULT ( STDMETHODCALLTYPE *UnsubscribeToJobEndStateEvent )( 
            IPrinterServiceTypeProxy * This);
        
        END_INTERFACE
    } IPrinterServiceTypeProxyVtbl;

    interface IPrinterServiceTypeProxy
    {
        CONST_VTBL struct IPrinterServiceTypeProxyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPrinterServiceTypeProxy_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPrinterServiceTypeProxy_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPrinterServiceTypeProxy_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPrinterServiceTypeProxy_CreatePrintJob(This,body,bodyOut)	\
    ( (This)->lpVtbl -> CreatePrintJob(This,body,bodyOut) ) 

#define IPrinterServiceTypeProxy_SendDocument(This,body,bodyOut)	\
    ( (This)->lpVtbl -> SendDocument(This,body,bodyOut) ) 

#define IPrinterServiceTypeProxy_AddDocument(This,body,bodyOut)	\
    ( (This)->lpVtbl -> AddDocument(This,body,bodyOut) ) 

#define IPrinterServiceTypeProxy_CancelJob(This,body,bodyOut)	\
    ( (This)->lpVtbl -> CancelJob(This,body,bodyOut) ) 

#define IPrinterServiceTypeProxy_GetPrinterElements(This,body,bodyOut)	\
    ( (This)->lpVtbl -> GetPrinterElements(This,body,bodyOut) ) 

#define IPrinterServiceTypeProxy_GetJobElements(This,body,bodyOut)	\
    ( (This)->lpVtbl -> GetJobElements(This,body,bodyOut) ) 

#define IPrinterServiceTypeProxy_GetActiveJobs(This,body,bodyOut)	\
    ( (This)->lpVtbl -> GetActiveJobs(This,body,bodyOut) ) 

#define IPrinterServiceTypeProxy_GetJobHistory(This,body,bodyOut)	\
    ( (This)->lpVtbl -> GetJobHistory(This,body,bodyOut) ) 

#define IPrinterServiceTypeProxy_SetEventRate(This,body,bodyOut)	\
    ( (This)->lpVtbl -> SetEventRate(This,body,bodyOut) ) 


#define IPrinterServiceTypeProxy_Init(This,genericProxy)	\
    ( (This)->lpVtbl -> Init(This,genericProxy) ) 

#define IPrinterServiceTypeProxy_BeginCreatePrintJob(This,body,AsyncState,AsyncCallback,AsyncResultOut)	\
    ( (This)->lpVtbl -> BeginCreatePrintJob(This,body,AsyncState,AsyncCallback,AsyncResultOut) ) 

#define IPrinterServiceTypeProxy_EndCreatePrintJob(This,AsyncResult,bodyOut)	\
    ( (This)->lpVtbl -> EndCreatePrintJob(This,AsyncResult,bodyOut) ) 

#define IPrinterServiceTypeProxy_BeginSendDocument(This,body,AsyncState,AsyncCallback,AsyncResultOut)	\
    ( (This)->lpVtbl -> BeginSendDocument(This,body,AsyncState,AsyncCallback,AsyncResultOut) ) 

#define IPrinterServiceTypeProxy_EndSendDocument(This,AsyncResult,bodyOut)	\
    ( (This)->lpVtbl -> EndSendDocument(This,AsyncResult,bodyOut) ) 

#define IPrinterServiceTypeProxy_BeginAddDocument(This,body,AsyncState,AsyncCallback,AsyncResultOut)	\
    ( (This)->lpVtbl -> BeginAddDocument(This,body,AsyncState,AsyncCallback,AsyncResultOut) ) 

#define IPrinterServiceTypeProxy_EndAddDocument(This,AsyncResult,bodyOut)	\
    ( (This)->lpVtbl -> EndAddDocument(This,AsyncResult,bodyOut) ) 

#define IPrinterServiceTypeProxy_BeginCancelJob(This,body,AsyncState,AsyncCallback,AsyncResultOut)	\
    ( (This)->lpVtbl -> BeginCancelJob(This,body,AsyncState,AsyncCallback,AsyncResultOut) ) 

#define IPrinterServiceTypeProxy_EndCancelJob(This,AsyncResult,bodyOut)	\
    ( (This)->lpVtbl -> EndCancelJob(This,AsyncResult,bodyOut) ) 

#define IPrinterServiceTypeProxy_BeginGetPrinterElements(This,body,AsyncState,AsyncCallback,AsyncResultOut)	\
    ( (This)->lpVtbl -> BeginGetPrinterElements(This,body,AsyncState,AsyncCallback,AsyncResultOut) ) 

#define IPrinterServiceTypeProxy_EndGetPrinterElements(This,AsyncResult,bodyOut)	\
    ( (This)->lpVtbl -> EndGetPrinterElements(This,AsyncResult,bodyOut) ) 

#define IPrinterServiceTypeProxy_BeginGetJobElements(This,body,AsyncState,AsyncCallback,AsyncResultOut)	\
    ( (This)->lpVtbl -> BeginGetJobElements(This,body,AsyncState,AsyncCallback,AsyncResultOut) ) 

#define IPrinterServiceTypeProxy_EndGetJobElements(This,AsyncResult,bodyOut)	\
    ( (This)->lpVtbl -> EndGetJobElements(This,AsyncResult,bodyOut) ) 

#define IPrinterServiceTypeProxy_BeginGetActiveJobs(This,body,AsyncState,AsyncCallback,AsyncResultOut)	\
    ( (This)->lpVtbl -> BeginGetActiveJobs(This,body,AsyncState,AsyncCallback,AsyncResultOut) ) 

#define IPrinterServiceTypeProxy_EndGetActiveJobs(This,AsyncResult,bodyOut)	\
    ( (This)->lpVtbl -> EndGetActiveJobs(This,AsyncResult,bodyOut) ) 

#define IPrinterServiceTypeProxy_BeginGetJobHistory(This,body,AsyncState,AsyncCallback,AsyncResultOut)	\
    ( (This)->lpVtbl -> BeginGetJobHistory(This,body,AsyncState,AsyncCallback,AsyncResultOut) ) 

#define IPrinterServiceTypeProxy_EndGetJobHistory(This,AsyncResult,bodyOut)	\
    ( (This)->lpVtbl -> EndGetJobHistory(This,AsyncResult,bodyOut) ) 

#define IPrinterServiceTypeProxy_BeginSetEventRate(This,body,AsyncState,AsyncCallback,AsyncResultOut)	\
    ( (This)->lpVtbl -> BeginSetEventRate(This,body,AsyncState,AsyncCallback,AsyncResultOut) ) 

#define IPrinterServiceTypeProxy_EndSetEventRate(This,AsyncResult,bodyOut)	\
    ( (This)->lpVtbl -> EndSetEventRate(This,AsyncResult,bodyOut) ) 

#define IPrinterServiceTypeProxy_SubscribeToPrinterElementsChangeEvent(This,eventSink)	\
    ( (This)->lpVtbl -> SubscribeToPrinterElementsChangeEvent(This,eventSink) ) 

#define IPrinterServiceTypeProxy_UnsubscribeToPrinterElementsChangeEvent(This)	\
    ( (This)->lpVtbl -> UnsubscribeToPrinterElementsChangeEvent(This) ) 

#define IPrinterServiceTypeProxy_SubscribeToPrinterStatusSummaryEvent(This,eventSink)	\
    ( (This)->lpVtbl -> SubscribeToPrinterStatusSummaryEvent(This,eventSink) ) 

#define IPrinterServiceTypeProxy_UnsubscribeToPrinterStatusSummaryEvent(This)	\
    ( (This)->lpVtbl -> UnsubscribeToPrinterStatusSummaryEvent(This) ) 

#define IPrinterServiceTypeProxy_SubscribeToPrinterStatusConditionEvent(This,eventSink)	\
    ( (This)->lpVtbl -> SubscribeToPrinterStatusConditionEvent(This,eventSink) ) 

#define IPrinterServiceTypeProxy_UnsubscribeToPrinterStatusConditionEvent(This)	\
    ( (This)->lpVtbl -> UnsubscribeToPrinterStatusConditionEvent(This) ) 

#define IPrinterServiceTypeProxy_SubscribeToPrinterStatusConditionClearedEvent(This,eventSink)	\
    ( (This)->lpVtbl -> SubscribeToPrinterStatusConditionClearedEvent(This,eventSink) ) 

#define IPrinterServiceTypeProxy_UnsubscribeToPrinterStatusConditionClearedEvent(This)	\
    ( (This)->lpVtbl -> UnsubscribeToPrinterStatusConditionClearedEvent(This) ) 

#define IPrinterServiceTypeProxy_SubscribeToJobStatusEvent(This,eventSink)	\
    ( (This)->lpVtbl -> SubscribeToJobStatusEvent(This,eventSink) ) 

#define IPrinterServiceTypeProxy_UnsubscribeToJobStatusEvent(This)	\
    ( (This)->lpVtbl -> UnsubscribeToJobStatusEvent(This) ) 

#define IPrinterServiceTypeProxy_SubscribeToJobEndStateEvent(This,eventSink)	\
    ( (This)->lpVtbl -> SubscribeToJobEndStateEvent(This,eventSink) ) 

#define IPrinterServiceTypeProxy_UnsubscribeToJobEndStateEvent(This)	\
    ( (This)->lpVtbl -> UnsubscribeToJobEndStateEvent(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPrinterServiceTypeProxy_INTERFACE_DEFINED__ */


#ifndef __IPrinterServiceTypeEventNotify_INTERFACE_DEFINED__
#define __IPrinterServiceTypeEventNotify_INTERFACE_DEFINED__

/* interface IPrinterServiceTypeEventNotify */
/* [local][restricted][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPrinterServiceTypeEventNotify;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("69538431-8e7f-43fa-b76b-ef39a2876602")
    IPrinterServiceTypeEventNotify : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE PrinterElementsChangeEvent( 
            /* [in] */ PRINTER_ELEMENTS_CHANGE_EVENT_TYPE *body) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PrinterStatusSummaryEvent( 
            /* [in] */ PRINTER_STATUS_SUMMARY_EVENT_TYPE *body) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PrinterStatusConditionEvent( 
            /* [in] */ PRINTER_STATUS_CONDITION_EVENT_TYPE *body) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PrinterStatusConditionClearedEvent( 
            /* [in] */ PRINTER_STATUS_CONDITION_CLEARED_EVENT_TYPE *body) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE JobStatusEvent( 
            /* [in] */ JOB_STATUS_EVENT_TYPE *body) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE JobEndStateEvent( 
            /* [in] */ JOB_END_STATE_EVENT_TYPE *body) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPrinterServiceTypeEventNotifyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPrinterServiceTypeEventNotify * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPrinterServiceTypeEventNotify * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPrinterServiceTypeEventNotify * This);
        
        HRESULT ( STDMETHODCALLTYPE *PrinterElementsChangeEvent )( 
            IPrinterServiceTypeEventNotify * This,
            /* [in] */ PRINTER_ELEMENTS_CHANGE_EVENT_TYPE *body);
        
        HRESULT ( STDMETHODCALLTYPE *PrinterStatusSummaryEvent )( 
            IPrinterServiceTypeEventNotify * This,
            /* [in] */ PRINTER_STATUS_SUMMARY_EVENT_TYPE *body);
        
        HRESULT ( STDMETHODCALLTYPE *PrinterStatusConditionEvent )( 
            IPrinterServiceTypeEventNotify * This,
            /* [in] */ PRINTER_STATUS_CONDITION_EVENT_TYPE *body);
        
        HRESULT ( STDMETHODCALLTYPE *PrinterStatusConditionClearedEvent )( 
            IPrinterServiceTypeEventNotify * This,
            /* [in] */ PRINTER_STATUS_CONDITION_CLEARED_EVENT_TYPE *body);
        
        HRESULT ( STDMETHODCALLTYPE *JobStatusEvent )( 
            IPrinterServiceTypeEventNotify * This,
            /* [in] */ JOB_STATUS_EVENT_TYPE *body);
        
        HRESULT ( STDMETHODCALLTYPE *JobEndStateEvent )( 
            IPrinterServiceTypeEventNotify * This,
            /* [in] */ JOB_END_STATE_EVENT_TYPE *body);
        
        END_INTERFACE
    } IPrinterServiceTypeEventNotifyVtbl;

    interface IPrinterServiceTypeEventNotify
    {
        CONST_VTBL struct IPrinterServiceTypeEventNotifyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPrinterServiceTypeEventNotify_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPrinterServiceTypeEventNotify_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPrinterServiceTypeEventNotify_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPrinterServiceTypeEventNotify_PrinterElementsChangeEvent(This,body)	\
    ( (This)->lpVtbl -> PrinterElementsChangeEvent(This,body) ) 

#define IPrinterServiceTypeEventNotify_PrinterStatusSummaryEvent(This,body)	\
    ( (This)->lpVtbl -> PrinterStatusSummaryEvent(This,body) ) 

#define IPrinterServiceTypeEventNotify_PrinterStatusConditionEvent(This,body)	\
    ( (This)->lpVtbl -> PrinterStatusConditionEvent(This,body) ) 

#define IPrinterServiceTypeEventNotify_PrinterStatusConditionClearedEvent(This,body)	\
    ( (This)->lpVtbl -> PrinterStatusConditionClearedEvent(This,body) ) 

#define IPrinterServiceTypeEventNotify_JobStatusEvent(This,body)	\
    ( (This)->lpVtbl -> JobStatusEvent(This,body) ) 

#define IPrinterServiceTypeEventNotify_JobEndStateEvent(This,body)	\
    ( (This)->lpVtbl -> JobEndStateEvent(This,body) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPrinterServiceTypeEventNotify_INTERFACE_DEFINED__ */


#ifndef __IPrinterServiceV12Type_INTERFACE_DEFINED__
#define __IPrinterServiceV12Type_INTERFACE_DEFINED__

/* interface IPrinterServiceV12Type */
/* [local][restricted][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPrinterServiceV12Type;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5fa7991a-9f96-4bda-9daa-6d0f4a238442")
    IPrinterServiceV12Type : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetPrinterElements( 
            /* [in] */ SET_PRINTER_ELEMENTS_REQUEST_TYPE *body,
            /* [out] */ SET_PRINTER_ELEMENTS_RESPONSE_TYPE **bodyOut) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPrinterServiceV12TypeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPrinterServiceV12Type * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPrinterServiceV12Type * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPrinterServiceV12Type * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetPrinterElements )( 
            IPrinterServiceV12Type * This,
            /* [in] */ SET_PRINTER_ELEMENTS_REQUEST_TYPE *body,
            /* [out] */ SET_PRINTER_ELEMENTS_RESPONSE_TYPE **bodyOut);
        
        END_INTERFACE
    } IPrinterServiceV12TypeVtbl;

    interface IPrinterServiceV12Type
    {
        CONST_VTBL struct IPrinterServiceV12TypeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPrinterServiceV12Type_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPrinterServiceV12Type_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPrinterServiceV12Type_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPrinterServiceV12Type_SetPrinterElements(This,body,bodyOut)	\
    ( (This)->lpVtbl -> SetPrinterElements(This,body,bodyOut) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPrinterServiceV12Type_INTERFACE_DEFINED__ */


#ifndef __IPrinterServiceV12TypeProxy_INTERFACE_DEFINED__
#define __IPrinterServiceV12TypeProxy_INTERFACE_DEFINED__

/* interface IPrinterServiceV12TypeProxy */
/* [local][restricted][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPrinterServiceV12TypeProxy;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ec86c41d-cbe6-49ef-9c71-caefb876a04d")
    IPrinterServiceV12TypeProxy : public IPrinterServiceV12Type
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Init( 
            IWSDServiceProxy *genericProxy) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BeginSetPrinterElements( 
            /* [in] */ SET_PRINTER_ELEMENTS_REQUEST_TYPE *body,
            /* [in] */ IUnknown *AsyncState,
            /* [in] */ IWSDAsyncCallback *AsyncCallback,
            /* [out] */ IWSDAsyncResult **AsyncResultOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EndSetPrinterElements( 
            /* [in] */ IWSDAsyncResult *AsyncResult,
            /* [out] */ SET_PRINTER_ELEMENTS_RESPONSE_TYPE **bodyOut) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPrinterServiceV12TypeProxyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPrinterServiceV12TypeProxy * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPrinterServiceV12TypeProxy * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPrinterServiceV12TypeProxy * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetPrinterElements )( 
            IPrinterServiceV12TypeProxy * This,
            /* [in] */ SET_PRINTER_ELEMENTS_REQUEST_TYPE *body,
            /* [out] */ SET_PRINTER_ELEMENTS_RESPONSE_TYPE **bodyOut);
        
        HRESULT ( STDMETHODCALLTYPE *Init )( 
            IPrinterServiceV12TypeProxy * This,
            IWSDServiceProxy *genericProxy);
        
        HRESULT ( STDMETHODCALLTYPE *BeginSetPrinterElements )( 
            IPrinterServiceV12TypeProxy * This,
            /* [in] */ SET_PRINTER_ELEMENTS_REQUEST_TYPE *body,
            /* [in] */ IUnknown *AsyncState,
            /* [in] */ IWSDAsyncCallback *AsyncCallback,
            /* [out] */ IWSDAsyncResult **AsyncResultOut);
        
        HRESULT ( STDMETHODCALLTYPE *EndSetPrinterElements )( 
            IPrinterServiceV12TypeProxy * This,
            /* [in] */ IWSDAsyncResult *AsyncResult,
            /* [out] */ SET_PRINTER_ELEMENTS_RESPONSE_TYPE **bodyOut);
        
        END_INTERFACE
    } IPrinterServiceV12TypeProxyVtbl;

    interface IPrinterServiceV12TypeProxy
    {
        CONST_VTBL struct IPrinterServiceV12TypeProxyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPrinterServiceV12TypeProxy_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPrinterServiceV12TypeProxy_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPrinterServiceV12TypeProxy_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPrinterServiceV12TypeProxy_SetPrinterElements(This,body,bodyOut)	\
    ( (This)->lpVtbl -> SetPrinterElements(This,body,bodyOut) ) 


#define IPrinterServiceV12TypeProxy_Init(This,genericProxy)	\
    ( (This)->lpVtbl -> Init(This,genericProxy) ) 

#define IPrinterServiceV12TypeProxy_BeginSetPrinterElements(This,body,AsyncState,AsyncCallback,AsyncResultOut)	\
    ( (This)->lpVtbl -> BeginSetPrinterElements(This,body,AsyncState,AsyncCallback,AsyncResultOut) ) 

#define IPrinterServiceV12TypeProxy_EndSetPrinterElements(This,AsyncResult,bodyOut)	\
    ( (This)->lpVtbl -> EndSetPrinterElements(This,AsyncResult,bodyOut) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPrinterServiceV12TypeProxy_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



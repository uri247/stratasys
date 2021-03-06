// <Include>
///////////////////////////////////////////////////////////////////////////////
//
// THIS FILE IS AUTOMATICALLY GENERATED.  DO NOT MODIFY IT BY HAND.
//
///////////////////////////////////////////////////////////////////////////////
// </Include>

// <Include>
#pragma once
// </Include>

// <CDATA>

class CPrinterServiceTypeProxy;
class CPrinterServiceTypeEventSource;
class CPrinterServiceV12TypeProxy;

// </CDATA>

// <ProxyBuilderDeclarations>
HRESULT CreateCPrinterServiceTypeProxy(
                LPCWSTR pszDeviceAddress,
                LPCWSTR pszLocalAddress,
                CPrinterServiceTypeProxy** ppProxyOut,
                IWSDXMLContext** ppContextOut);

HRESULT CreateCPrinterServiceTypeProxyById(
                LPCWSTR pszDeviceAddress,
                LPCWSTR pszServiceId,
                LPCWSTR pszLocalAddress,
                CPrinterServiceTypeProxy** ppProxyOut,
                IWSDXMLContext** ppContextOut);
// </ProxyBuilderDeclarations>

// <CDATA>

class CPrinterServiceTypeProxy: public IPrinterServiceTypeProxy
{
protected:
    ~CPrinterServiceTypeProxy();
    LONG m_cRef;
    IWSDServiceProxy* m_genericProxy;

public:
    HRESULT STDMETHODCALLTYPE Init(IWSDServiceProxy* genericProxy);
    CPrinterServiceTypeProxy();

// </CDATA>

// <IUnknownDeclarations>
    // 
    // IUnknown
    // 
    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppvObject);
    ULONG STDMETHODCALLTYPE AddRef();
    ULONG STDMETHODCALLTYPE Release();
// </IUnknownDeclarations>

// <FunctionDeclarations>
    HRESULT STDMETHODCALLTYPE
    CreatePrintJob
    (   /* [in] */ CREATE_PRINT_JOB_REQUEST_TYPE* body
    ,   /* [out] */ CREATE_PRINT_JOB_RESPONSE_TYPE** bodyOut
    );

    HRESULT STDMETHODCALLTYPE
    SendDocument
    (   /* [in] */ SEND_DOCUMENT_REQUEST_TYPE* body
    ,   /* [out] */ SEND_DOCUMENT_RESPONSE_TYPE** bodyOut
    );

    HRESULT STDMETHODCALLTYPE
    AddDocument
    (   /* [in] */ ADD_DOCUMENT_REQUEST_TYPE* body
    ,   /* [out] */ ADD_DOCUMENT_RESPONSE_TYPE** bodyOut
    );

    HRESULT STDMETHODCALLTYPE
    CancelJob
    (   /* [in] */ CANCEL_JOB_REQUEST_TYPE* body
    ,   /* [out] */ CANCEL_JOB_RESPONSE_TYPE** bodyOut
    );

    HRESULT STDMETHODCALLTYPE
    GetPrinterElements
    (   /* [in] */ GET_PRINTER_ELEMENTS_REQUEST_TYPE* body
    ,   /* [out] */ GET_PRINTER_ELEMENTS_RESPONSE_TYPE** bodyOut
    );

    HRESULT STDMETHODCALLTYPE
    GetJobElements
    (   /* [in] */ GET_JOB_ELEMENTS_REQUEST_TYPE* body
    ,   /* [out] */ GET_JOB_ELEMENTS_RESPONSE_TYPE** bodyOut
    );

    HRESULT STDMETHODCALLTYPE
    GetActiveJobs
    (   /* [in] */ GET_ACTIVE_JOBS_REQUEST_TYPE* body
    ,   /* [out] */ GET_ACTIVE_JOBS_RESPONSE_TYPE** bodyOut
    );

    HRESULT STDMETHODCALLTYPE
    GetJobHistory
    (   /* [in] */ GET_JOB_HISTORY_REQUEST_TYPE* body
    ,   /* [out] */ GET_JOB_HISTORY_RESPONSE_TYPE** bodyOut
    );

    HRESULT STDMETHODCALLTYPE
    SetEventRate
    (   /* [in] */ SET_EVENT_RATE_REQUEST_TYPE* body
    ,   /* [out] */ SET_EVENT_RATE_RESPONSE_TYPE** bodyOut
    );

// </FunctionDeclarations>

// <FunctionDeclarations>
    HRESULT STDMETHODCALLTYPE
    BeginCreatePrintJob
    (   /* [in] */ CREATE_PRINT_JOB_REQUEST_TYPE* body
    ,   /* [in] */ IUnknown* AsyncState
    ,   /* [in] */ IWSDAsyncCallback* AsyncCallback
    ,   /* [out] */ IWSDAsyncResult** AsyncResultOut
    );

    HRESULT STDMETHODCALLTYPE
    EndCreatePrintJob
    (   /* [in] */ IWSDAsyncResult* AsyncResult
    ,   /* [out] */ CREATE_PRINT_JOB_RESPONSE_TYPE** bodyOut
    );

    HRESULT STDMETHODCALLTYPE
    BeginSendDocument
    (   /* [in] */ SEND_DOCUMENT_REQUEST_TYPE* body
    ,   /* [in] */ IUnknown* AsyncState
    ,   /* [in] */ IWSDAsyncCallback* AsyncCallback
    ,   /* [out] */ IWSDAsyncResult** AsyncResultOut
    );

    HRESULT STDMETHODCALLTYPE
    EndSendDocument
    (   /* [in] */ IWSDAsyncResult* AsyncResult
    ,   /* [out] */ SEND_DOCUMENT_RESPONSE_TYPE** bodyOut
    );

    HRESULT STDMETHODCALLTYPE
    BeginAddDocument
    (   /* [in] */ ADD_DOCUMENT_REQUEST_TYPE* body
    ,   /* [in] */ IUnknown* AsyncState
    ,   /* [in] */ IWSDAsyncCallback* AsyncCallback
    ,   /* [out] */ IWSDAsyncResult** AsyncResultOut
    );

    HRESULT STDMETHODCALLTYPE
    EndAddDocument
    (   /* [in] */ IWSDAsyncResult* AsyncResult
    ,   /* [out] */ ADD_DOCUMENT_RESPONSE_TYPE** bodyOut
    );

    HRESULT STDMETHODCALLTYPE
    BeginCancelJob
    (   /* [in] */ CANCEL_JOB_REQUEST_TYPE* body
    ,   /* [in] */ IUnknown* AsyncState
    ,   /* [in] */ IWSDAsyncCallback* AsyncCallback
    ,   /* [out] */ IWSDAsyncResult** AsyncResultOut
    );

    HRESULT STDMETHODCALLTYPE
    EndCancelJob
    (   /* [in] */ IWSDAsyncResult* AsyncResult
    ,   /* [out] */ CANCEL_JOB_RESPONSE_TYPE** bodyOut
    );

    HRESULT STDMETHODCALLTYPE
    BeginGetPrinterElements
    (   /* [in] */ GET_PRINTER_ELEMENTS_REQUEST_TYPE* body
    ,   /* [in] */ IUnknown* AsyncState
    ,   /* [in] */ IWSDAsyncCallback* AsyncCallback
    ,   /* [out] */ IWSDAsyncResult** AsyncResultOut
    );

    HRESULT STDMETHODCALLTYPE
    EndGetPrinterElements
    (   /* [in] */ IWSDAsyncResult* AsyncResult
    ,   /* [out] */ GET_PRINTER_ELEMENTS_RESPONSE_TYPE** bodyOut
    );

    HRESULT STDMETHODCALLTYPE
    BeginGetJobElements
    (   /* [in] */ GET_JOB_ELEMENTS_REQUEST_TYPE* body
    ,   /* [in] */ IUnknown* AsyncState
    ,   /* [in] */ IWSDAsyncCallback* AsyncCallback
    ,   /* [out] */ IWSDAsyncResult** AsyncResultOut
    );

    HRESULT STDMETHODCALLTYPE
    EndGetJobElements
    (   /* [in] */ IWSDAsyncResult* AsyncResult
    ,   /* [out] */ GET_JOB_ELEMENTS_RESPONSE_TYPE** bodyOut
    );

    HRESULT STDMETHODCALLTYPE
    BeginGetActiveJobs
    (   /* [in] */ GET_ACTIVE_JOBS_REQUEST_TYPE* body
    ,   /* [in] */ IUnknown* AsyncState
    ,   /* [in] */ IWSDAsyncCallback* AsyncCallback
    ,   /* [out] */ IWSDAsyncResult** AsyncResultOut
    );

    HRESULT STDMETHODCALLTYPE
    EndGetActiveJobs
    (   /* [in] */ IWSDAsyncResult* AsyncResult
    ,   /* [out] */ GET_ACTIVE_JOBS_RESPONSE_TYPE** bodyOut
    );

    HRESULT STDMETHODCALLTYPE
    BeginGetJobHistory
    (   /* [in] */ GET_JOB_HISTORY_REQUEST_TYPE* body
    ,   /* [in] */ IUnknown* AsyncState
    ,   /* [in] */ IWSDAsyncCallback* AsyncCallback
    ,   /* [out] */ IWSDAsyncResult** AsyncResultOut
    );

    HRESULT STDMETHODCALLTYPE
    EndGetJobHistory
    (   /* [in] */ IWSDAsyncResult* AsyncResult
    ,   /* [out] */ GET_JOB_HISTORY_RESPONSE_TYPE** bodyOut
    );

    HRESULT STDMETHODCALLTYPE
    BeginSetEventRate
    (   /* [in] */ SET_EVENT_RATE_REQUEST_TYPE* body
    ,   /* [in] */ IUnknown* AsyncState
    ,   /* [in] */ IWSDAsyncCallback* AsyncCallback
    ,   /* [out] */ IWSDAsyncResult** AsyncResultOut
    );

    HRESULT STDMETHODCALLTYPE
    EndSetEventRate
    (   /* [in] */ IWSDAsyncResult* AsyncResult
    ,   /* [out] */ SET_EVENT_RATE_RESPONSE_TYPE** bodyOut
    );

// </FunctionDeclarations>

// <SubscriptionFunctionDeclarations>
    HRESULT STDMETHODCALLTYPE
    SubscribeToPrinterElementsChangeEvent
    (    IPrinterServiceTypeEventNotify* eventSink
    );

    HRESULT STDMETHODCALLTYPE
    UnsubscribeToPrinterElementsChangeEvent
    (    void
    );

    HRESULT STDMETHODCALLTYPE
    SubscribeToPrinterStatusSummaryEvent
    (    IPrinterServiceTypeEventNotify* eventSink
    );

    HRESULT STDMETHODCALLTYPE
    UnsubscribeToPrinterStatusSummaryEvent
    (    void
    );

    HRESULT STDMETHODCALLTYPE
    SubscribeToPrinterStatusConditionEvent
    (    IPrinterServiceTypeEventNotify* eventSink
    );

    HRESULT STDMETHODCALLTYPE
    UnsubscribeToPrinterStatusConditionEvent
    (    void
    );

    HRESULT STDMETHODCALLTYPE
    SubscribeToPrinterStatusConditionClearedEvent
    (    IPrinterServiceTypeEventNotify* eventSink
    );

    HRESULT STDMETHODCALLTYPE
    UnsubscribeToPrinterStatusConditionClearedEvent
    (    void
    );

    HRESULT STDMETHODCALLTYPE
    SubscribeToJobStatusEvent
    (    IPrinterServiceTypeEventNotify* eventSink
    );

    HRESULT STDMETHODCALLTYPE
    UnsubscribeToJobStatusEvent
    (    void
    );

    HRESULT STDMETHODCALLTYPE
    SubscribeToJobEndStateEvent
    (    IPrinterServiceTypeEventNotify* eventSink
    );

    HRESULT STDMETHODCALLTYPE
    UnsubscribeToJobEndStateEvent
    (    void
    );

// </SubscriptionFunctionDeclarations>

// <CDATA>

};

// </CDATA>

// <EventSourceBuilderDeclarations>
HRESULT CreateCPrinterServiceTypeEventSource(IWSDDeviceHost* pHost, LPCWSTR pszServiceId, CPrinterServiceTypeEventSource** ppEventSourceOut);
// </EventSourceBuilderDeclarations>

// <CDATA>

class CPrinterServiceTypeEventSource: public IPrinterServiceTypeEventNotify
{
protected:
    ~CPrinterServiceTypeEventSource();
    LONG m_cRef;
    IWSDDeviceHost* m_host;
    const WCHAR* m_serviceId;

public:
    HRESULT STDMETHODCALLTYPE Init(IWSDDeviceHost* pIWSDDeviceHost, const WCHAR* serviceId);
    CPrinterServiceTypeEventSource();

// </CDATA>

// <IUnknownDeclarations>
    // 
    // IUnknown
    // 
    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppvObject);
    ULONG STDMETHODCALLTYPE AddRef();
    ULONG STDMETHODCALLTYPE Release();
// </IUnknownDeclarations>

// <FunctionDeclarations>
    HRESULT STDMETHODCALLTYPE
    PrinterElementsChangeEvent
    (   /* [in] */ PRINTER_ELEMENTS_CHANGE_EVENT_TYPE* body
    );

    HRESULT STDMETHODCALLTYPE
    PrinterStatusSummaryEvent
    (   /* [in] */ PRINTER_STATUS_SUMMARY_EVENT_TYPE* body
    );

    HRESULT STDMETHODCALLTYPE
    PrinterStatusConditionEvent
    (   /* [in] */ PRINTER_STATUS_CONDITION_EVENT_TYPE* body
    );

    HRESULT STDMETHODCALLTYPE
    PrinterStatusConditionClearedEvent
    (   /* [in] */ PRINTER_STATUS_CONDITION_CLEARED_EVENT_TYPE* body
    );

    HRESULT STDMETHODCALLTYPE
    JobStatusEvent
    (   /* [in] */ JOB_STATUS_EVENT_TYPE* body
    );

    HRESULT STDMETHODCALLTYPE
    JobEndStateEvent
    (   /* [in] */ JOB_END_STATE_EVENT_TYPE* body
    );

// </FunctionDeclarations>

// <CDATA>

};

// </CDATA>

// <ProxyBuilderDeclarations>
HRESULT CreateCPrinterServiceV12TypeProxy(
                LPCWSTR pszDeviceAddress,
                LPCWSTR pszLocalAddress,
                CPrinterServiceV12TypeProxy** ppProxyOut,
                IWSDXMLContext** ppContextOut);

HRESULT CreateCPrinterServiceV12TypeProxyById(
                LPCWSTR pszDeviceAddress,
                LPCWSTR pszServiceId,
                LPCWSTR pszLocalAddress,
                CPrinterServiceV12TypeProxy** ppProxyOut,
                IWSDXMLContext** ppContextOut);
// </ProxyBuilderDeclarations>

// <CDATA>

class CPrinterServiceV12TypeProxy: public IPrinterServiceV12TypeProxy
{
protected:
    ~CPrinterServiceV12TypeProxy();
    LONG m_cRef;
    IWSDServiceProxy* m_genericProxy;

public:
    HRESULT STDMETHODCALLTYPE Init(IWSDServiceProxy* genericProxy);
    CPrinterServiceV12TypeProxy();

// </CDATA>

// <IUnknownDeclarations>
    // 
    // IUnknown
    // 
    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppvObject);
    ULONG STDMETHODCALLTYPE AddRef();
    ULONG STDMETHODCALLTYPE Release();
// </IUnknownDeclarations>

// <FunctionDeclarations>
    HRESULT STDMETHODCALLTYPE
    SetPrinterElements
    (   /* [in] */ SET_PRINTER_ELEMENTS_REQUEST_TYPE* body
    ,   /* [out] */ SET_PRINTER_ELEMENTS_RESPONSE_TYPE** bodyOut
    );

// </FunctionDeclarations>

// <FunctionDeclarations>
    HRESULT STDMETHODCALLTYPE
    BeginSetPrinterElements
    (   /* [in] */ SET_PRINTER_ELEMENTS_REQUEST_TYPE* body
    ,   /* [in] */ IUnknown* AsyncState
    ,   /* [in] */ IWSDAsyncCallback* AsyncCallback
    ,   /* [out] */ IWSDAsyncResult** AsyncResultOut
    );

    HRESULT STDMETHODCALLTYPE
    EndSetPrinterElements
    (   /* [in] */ IWSDAsyncResult* AsyncResult
    ,   /* [out] */ SET_PRINTER_ELEMENTS_RESPONSE_TYPE** bodyOut
    );

// </FunctionDeclarations>

// <CDATA>

};

// </CDATA>


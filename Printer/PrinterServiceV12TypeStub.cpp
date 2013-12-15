///////////////////////////////////////////////////////////////////////////////
//
// THIS FILE IS AUTOMATICALLY GENERATED.  DO NOT MODIFY IT BY HAND.
//
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <wsdapi.h>
#include "PrinterServiceV12Type_h.h"
#include "PrinterServiceV12TypeTypes.h"
//
// Port type http://schemas.microsoft.com/windows/2012/10/wdp/printV12/PrinterServiceV12Type
// Message type declarations
//
extern WSDXML_TYPE REQUESTTYPE_SetPrinterElements;
extern WSDXML_TYPE RESPONSETYPE_SetPrinterElements;

HRESULT CreatePrinterServiceV12TypeHost(
                LPCWSTR pszDeviceAddress,
                const WSD_THIS_DEVICE_METADATA* pThisDeviceMetadata,
                IPrinterServiceV12Type* pIPrinterServiceV12Type,
                IWSDDeviceHost** ppHostOut,
                IWSDXMLContext** ppContextOut)
{
    HRESULT hr = S_OK;
    IWSDXMLContext* pContext = NULL;
    IWSDDeviceHost* pHost = NULL;

    // 
    // Validate parameters
    // 
    if( NULL == pszDeviceAddress )
    {
        return E_INVALIDARG;
    }

    if( NULL == pThisDeviceMetadata )
    {
        return E_INVALIDARG;
    }

    // pIPrinterServiceV12Type is optional
    if( NULL == ppHostOut )
    {
        return E_POINTER;
    }

    // ppContextOut is optional

    *ppHostOut = NULL;
    if( NULL != ppContextOut )
    {
        *ppContextOut = NULL;
    }

    // 
    // Create XML context for namespace and type registration
    // 
    hr = WSDXMLCreateContext(&pContext);

    // 
    // Register types used by the service
    // 
    if( S_OK == hr )
    {
        hr = PrinterServiceV12TypeRegisterTypes(pContext);
    }

    // 
    // Register namespaces used by the service
    // 
    if( S_OK == hr )
    {
        hr = PrinterServiceV12TypeRegisterNamespaces(pContext);
    }

    // 
    // Create device host
    // 
    if( S_OK == hr )
    {
        hr = WSDCreateDeviceHost(pszDeviceAddress, pContext, &pHost);
    }

    // 
    // Register port types
    // 
    if( S_OK == hr )
    {
        hr = pHost->RegisterPortType(&PortType_PrinterServiceV12Type);
    }

    // 
    // Set metadata
    // 
    if( S_OK == hr )
    {
        hr = pHost->SetMetadata(&thisModelMetadata, pThisDeviceMetadata, &hostMetadata, NULL);
    }

    // 
    // Register services and set discoverability
    // 
    if( S_OK == hr && pIPrinterServiceV12Type != NULL )
    {
        hr = pHost->RegisterService(L"http://schemas.microsoft.com/windows/2012/10/wdp/printV12/PrinterServiceV12Type0", pIPrinterServiceV12Type);
    }

    // 
    // Cleanup
    // 
    if( S_OK == hr && ppContextOut )
    {
        *ppContextOut = pContext;
    }
    else
    {
        if( NULL != pContext )
        {
            pContext->Release();
        }
    }

    if( S_OK == hr )
    {
        *ppHostOut = pHost;
    }
    else
    {
        if( NULL != pHost )
        {
            pHost->Release();
        }
    }

    return hr;
}

HRESULT __stdcall
Stub_SetPrinterElements
(   IUnknown* server
,   IWSDServiceMessaging* service
,   WSD_EVENT* event
)
{
    HRESULT hr = S_OK;
    IPrinterServiceV12Type* pServer = NULL;

    REQUESTBODY_PrinterServiceV12Type_SetPrinterElements* p = reinterpret_cast<REQUESTBODY_PrinterServiceV12Type_SetPrinterElements*>(event->Soap->Body);
    RESPONSEBODY_PrinterServiceV12Type_SetPrinterElements result;
    ::ZeroMemory(&result,sizeof(result));

    hr = server->QueryInterface( __uuidof(IPrinterServiceV12Type), (void**)&pServer );
    if( S_OK == hr )
    {
        hr =
        pServer->SetPrinterElements
        (   p->body
        ,   &result.body
        );

        pServer->Release();
        pServer = NULL;
    }
    if (SUCCEEDED(hr))
    {
        hr = service->SendResponse(&result,event->Operation,event->MessageParameters);
    }
    if (FAILED(hr))
    {
        hr = service->FaultRequest(&event->Soap->Header,event->MessageParameters, NULL);
    }

    // Clean up memory from outparams
    if (NULL != result.body)
    {
        WSDFreeLinkedMemory( (void*) (result.body) );
    }

    return hr;
}


 //////////////////////////////////////////////////////////////////////////////
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//////////////////////////////////////////////////////////////////////////////
#pragma once

#include <wsdapi.h>

// PrinterServiceTYpe.h is automatically generated from PrinterServiceType.idl
#include "PrinterServiceType.h"
// Include PrinterServiceProxy for CPrinterServiceEventSource class
#include "PrinterServiceTypeProxy.h"




WSD_LOCALIZED_STRING thisDeviceName = {NULL, L"Printer Service Device"};
WSD_LOCALIZED_STRING_LIST thisDeviceNameList = {NULL, &thisDeviceName};

// thisDeviceNameList is the FriendlyName
// "0.095" is the FirmwareVersion
// "0123456789-9876543210" is the SerialNumber

const WSD_THIS_DEVICE_METADATA thisDeviceMetadata = {
    &thisDeviceNameList,
    L"0.095",
    L"0123456789-9876543210",
}; 

//////////////////////////////////////////////////////////////////////////////
// CFileServiceService Class
//       Implements the service functionality
//////////////////////////////////////////////////////////////////////////////
class CPrinterServiceService : public IPrinterServiceType
{
private:
    ULONG m_cRef;
	void StubCreateResponseGetPrinterElements(PRINTER_ELEMENT_DATA_TYPE*);

public:
	CPrinterServiceService();


	       HRESULT STDMETHODCALLTYPE CreatePrintJob( 
            /* [in] */ CREATE_PRINT_JOB_REQUEST_TYPE *body,
            /* [out] */ CREATE_PRINT_JOB_RESPONSE_TYPE **bodyOut);
        
        HRESULT STDMETHODCALLTYPE SendDocument( 
            /* [in] */ SEND_DOCUMENT_REQUEST_TYPE *body,
            /* [out] */ SEND_DOCUMENT_RESPONSE_TYPE **bodyOut);
        
        HRESULT STDMETHODCALLTYPE AddDocument( 
            /* [in] */ ADD_DOCUMENT_REQUEST_TYPE *body,
            /* [out] */ ADD_DOCUMENT_RESPONSE_TYPE **bodyOut);
        
        HRESULT STDMETHODCALLTYPE CancelJob( 
            /* [in] */ CANCEL_JOB_REQUEST_TYPE *body,
            /* [out] */ CANCEL_JOB_RESPONSE_TYPE **bodyOut);
        
        HRESULT STDMETHODCALLTYPE GetPrinterElements( 
            /* [in] */ GET_PRINTER_ELEMENTS_REQUEST_TYPE *body,
            /* [out] */ GET_PRINTER_ELEMENTS_RESPONSE_TYPE **bodyOut);
        
        HRESULT STDMETHODCALLTYPE GetJobElements( 
            /* [in] */ GET_JOB_ELEMENTS_REQUEST_TYPE *body,
            /* [out] */ GET_JOB_ELEMENTS_RESPONSE_TYPE **bodyOut);
        
        HRESULT STDMETHODCALLTYPE GetActiveJobs( 
            /* [in] */ GET_ACTIVE_JOBS_REQUEST_TYPE *body,
            /* [out] */ GET_ACTIVE_JOBS_RESPONSE_TYPE **bodyOut);
        
        HRESULT STDMETHODCALLTYPE GetJobHistory( 
            /* [in] */ GET_JOB_HISTORY_REQUEST_TYPE *body,
            /* [out] */ GET_JOB_HISTORY_RESPONSE_TYPE **bodyOut);
        
        HRESULT STDMETHODCALLTYPE SetEventRate( 
            /* [in] */ SET_EVENT_RATE_REQUEST_TYPE *body,
            /* [out] */ SET_EVENT_RATE_RESPONSE_TYPE **bodyOut);

 

public:
    //////////////////////////////////////////////////////////////////////////
    // Methods to make this class act like a COM object
    //////////////////////////////////////////////////////////////////////////
    HRESULT STDMETHODCALLTYPE QueryInterface(
        REFIID riid, 
        void** ppvObject)
    {
        if (NULL == ppvObject)
        {
            return E_POINTER;
        }

        HRESULT hr = S_OK;
        *ppvObject = NULL;

        if (( __uuidof(IPrinterServiceType) == riid) ||
            ( __uuidof(IUnknown) == riid) )
        {
			*ppvObject = (IPrinterServiceType*)this;
        }
        else
        {
            hr = E_NOINTERFACE;
        }

        if (SUCCEEDED(hr))
        {
            ((LPUNKNOWN) *ppvObject)->AddRef( );
        }

        return hr;
    } 

    ULONG STDMETHODCALLTYPE AddRef()
    {
        ULONG ulNewRefCount = (ULONG)InterlockedIncrement((LONG *)&m_cRef);
        return ulNewRefCount;
    }

    ULONG STDMETHODCALLTYPE Release()
    {
        ULONG ulNewRefCount = (ULONG)InterlockedDecrement((LONG *)&m_cRef);

        if( 0 == ulNewRefCount )
        {
            delete this;
        }
        return ulNewRefCount;
    } 
};



//////////////////////////////////////////////////////////////////////////////
// CFileServiceService Class
//       Implements the service functionality
//////////////////////////////////////////////////////////////////////////////
class CPrinterServiceServiceV12 : public IPrinterServiceV12Type
{
private:
	ULONG m_cRef;


public:
	CPrinterServiceServiceV12();


	HRESULT STDMETHODCALLTYPE SetPrinterElements(
		/* [in] */ SET_PRINTER_ELEMENTS_REQUEST_TYPE *body,
		/* [out] */ SET_PRINTER_ELEMENTS_RESPONSE_TYPE **bodyOut);





public:
	//////////////////////////////////////////////////////////////////////////
	// Methods to make this class act like a COM object
	//////////////////////////////////////////////////////////////////////////
	HRESULT STDMETHODCALLTYPE QueryInterface(
		REFIID riid,
		void** ppvObject)
	{
		if (NULL == ppvObject)
		{
			return E_POINTER;
		}

		HRESULT hr = S_OK;
		*ppvObject = NULL;

		if ((__uuidof(IPrinterServiceV12Type) == riid) ||
			(__uuidof(IUnknown) == riid))
		{
			*ppvObject = (IPrinterServiceV12Type*)this;
		}
		else
		{
			hr = E_NOINTERFACE;
		}

		if (SUCCEEDED(hr))
		{
			((LPUNKNOWN)*ppvObject)->AddRef();
		}

		return hr;
	}

	ULONG STDMETHODCALLTYPE AddRef()
	{
		ULONG ulNewRefCount = (ULONG)InterlockedIncrement((LONG *)&m_cRef);
		return ulNewRefCount;
	}

	ULONG STDMETHODCALLTYPE Release()
	{
		ULONG ulNewRefCount = (ULONG)InterlockedDecrement((LONG *)&m_cRef);

		if (0 == ulNewRefCount)
		{
			delete this;
		}
		return ulNewRefCount;
	}
};


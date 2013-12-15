////////////////////////////////////////////////////////////////////////////////
// [Written by Elad Atar, 2013]
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND.
//
// This Project interacts with the Windows' Function Discovery mechanism, so that the printer
// be recognized automatically during searching & adding a new printer
// Copyright (c) Stratasys. All rights reserved.
////////////////////////////////////////////////////////////////////////////////

// Public Headers
#include <windows.h>
#include <stdio.h>

// Sample Headers
#include "PrinterServiceProvider.h"
#include "PrinterFdProxy.h"
#include "common.h"

//------------------------------------------------------------------------------
// PrinterServiceProvider::PrinterServiceProvider (Constructor)
//------------------------------------------------------------------------------
CPrinterServiceProvider::CPrinterServiceProvider() :
m_cRef(1)
{
	DllIncLockCount();
}


//------------------------------------------------------------------------------
// PrinterServiceProvider::~PrinterServiceProvider (Destructor)
//------------------------------------------------------------------------------
CPrinterServiceProvider::~CPrinterServiceProvider()
{
	DllDecLockCount();
}


//
// IFunctionDiscoveryServiceProvider
//

//------------------------------------------------------------------------------
// PrinterServiceProvider::Initialize
//      This function is called by Function Discovery (FD) when QueryService is
//      called on an FD Function Instance specifying
//      CLSID_SsysPrinterServiceProxy. This function creates a WSD or UPnP proxy
//      object depending on what type of device the FD Function Instance
//      represents.
//------------------------------------------------------------------------------
HRESULT CPrinterServiceProvider::Initialize(
	IFunctionInstance* pFunInst,
	REFIID riid,
	void** ppv
	)
{
	DEVICE_PROTOCOL_TYPE    deviceType = DEVICE_PROTOCOL_TYPE_WSD;
	HRESULT                 hr = S_OK;
	IPropertyStore*         pPropStore = NULL;

	if (NULL == ppv ||
		NULL == pFunInst)
	{
		return E_INVALIDARG;
	}

	//
	// Open the property store of the function instance
	//
	if (S_OK == hr)
	{
		wprintf(L"OpenPropertyStore on the FI...");
		hr = pFunInst->OpenPropertyStore(STGM_READ, &pPropStore);
		wprintf(L"0x%x\n", hr);
	}

	//
	// See if this is a device type supported. This is done by checking
	// the 'Type' property inside the FI's property store.
	//
	if (S_OK == hr)
	{
		wprintf(L"GetDeviceType...");
		hr = GetDeviceType(pPropStore, &deviceType);
		wprintf(L"0x%x\n", hr);
		if (S_FALSE == hr)
		{
			wprintf(L"Device type unsupported!");
		}
	}

	if (S_OK == hr)
	{
		wprintf(L"Device type: %s\n",
			DEVICE_PROTOCOL_TYPE_WSD == deviceType ? L"WSD" : L"Unknown (UPNP?)");
	}

	//
	// Create the appropriate proxy
	//
	if (S_OK == hr &&
		DEVICE_PROTOCOL_TYPE_WSD == deviceType)
	{
		hr = CreateCPrinterServiceWsdProxy(
			pPropStore,
			reinterpret_cast<IPrinterService**>(ppv)
			);
	}

	//
	// Cleanup
	//
	if (NULL != pPropStore)
	{
		pPropStore->Release();
		pPropStore = NULL;
	}

	return hr;
}// PrinterServiceProvider::Initialize


//
// IUnknown
//

//------------------------------------------------------------------------------
// PrinterServiceProvider::QueryInterface
//------------------------------------------------------------------------------
HRESULT CPrinterServiceProvider::QueryInterface(
	REFIID riid,
	void** ppvObject
	)
{
	HRESULT hr = S_OK;

	if (NULL == ppvObject)
	{
		return E_INVALIDARG;
	}

	*ppvObject = NULL;

	if (__uuidof(IFunctionDiscoveryServiceProvider) == riid)
	{
		*ppvObject = static_cast<IFunctionDiscoveryServiceProvider*>(this);
		AddRef();
	}
	else if (__uuidof(IUnknown) == riid)
	{
		*ppvObject = static_cast<IUnknown*>(this);
		AddRef();
	}
	else
	{
		hr = E_NOINTERFACE;
	}

	return hr;
}// PrinterServiceProvider::QueryInterface


//------------------------------------------------------------------------------
// PrinterServiceProvider::AddRef
//------------------------------------------------------------------------------
ULONG CPrinterServiceProvider::AddRef()
{
	return InterlockedIncrement(&m_cRef);
}// PrinterServiceProvider::AddRef


//------------------------------------------------------------------------------
// PrinterServiceProvider::Release
//------------------------------------------------------------------------------
ULONG CPrinterServiceProvider::Release()
{
	LONG cRef = InterlockedDecrement(&m_cRef);

	if (0 == cRef)
	{
		delete this;
	}
	return cRef;
}// PrinterServiceProvider::Release

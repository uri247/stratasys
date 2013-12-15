#pragma once

	// Public Headers
#include <FunctionDiscoveryProvider.h>

	//------------------------------------------------------------------------------
	// PrinterServiceProvider
	//      This class is used by Function Discovery (FD) to create the correct
	//      proxy object when a client asks for CLSID_SsysPrinterSvcProxy from an
	//      FD Function Instance supporting IPrinterService.
	//------------------------------------------------------------------------------
class CPrinterServiceProvider :
	public IFunctionDiscoveryServiceProvider
{
private:

	~CPrinterServiceProvider();

public:

	CPrinterServiceProvider();

	//
	// IFunctionDiscoveryServiceProvider Implementation
	//
	STDMETHODIMP Initialize(
		__in IFunctionInstance *pIFunctionInstance,
		__in REFIID riid,
		__deref_out_opt void **ppvObject
		);

	//
	// IUnknown Implementation
	//
	STDMETHODIMP QueryInterface(
		__in REFIID riid,
		__deref_out_opt void** ppvObject
		);
	STDMETHODIMP_(ULONG) AddRef();
	STDMETHODIMP_(ULONG) Release();

private:

	LONG m_cRef;

};// CPrinterServiceProvider


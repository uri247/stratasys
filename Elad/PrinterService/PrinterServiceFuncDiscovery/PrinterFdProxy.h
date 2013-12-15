#pragma once

// Public Headers
#include <wsdapi.h>
#include <FunctionDiscovery.h>

// Sample Headers
#include "PrinterService.h"
#include "PrinterServiceType.h"

//
// Function Declarations
//
STDMETHODIMP CreateCPrinterServiceWsdProxy(
	__in IPropertyStore* pPropertyStore,
	__deref_out IPrinterService** ppSimpleThermostat
	);

//------------------------------------------------------------------------------
// CPrinterServiceWsdProxy
//      This proxy object implements the real IPrinterService interface and
//      knows how to talk to the IPrinterServiceType interface.
//      IPrinterServiceType is the WSD protocol specific version of the 
//      IPrinterService interface.
//------------------------------------------------------------------------------
class CPrinterServiceWsdProxy :
	public IPrinterService
{
private:

	~CPrinterServiceWsdProxy();

public:

	CPrinterServiceWsdProxy(__in IPrinterServiceType* pPrinterServiceType);

	//
	// IPrinterService Implementation
	//
	STDMETHODIMP SendDocument(
						LONG	body,
			__deref_out LONG*	jobId
		);
	
	STDMETHODIMP CancelJob(
			LONG	jobId
		);
	
	STDMETHODIMP GetPrinterElements(
						INT		opcode,
			__deref_out WCHAR** bodyOut
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

	LONG                  m_cRef;
	IPrinterServiceType*  m_pPrinterServiceType;

};// CPrinterServiceWsdProxy


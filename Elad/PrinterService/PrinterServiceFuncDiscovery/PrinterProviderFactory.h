#pragma once

	// Public Headers
#include <windows.h>
#include <unknwn.h>

	//------------------------------------------------------------------------------
	// CPrinterProviderFactory
	//      Factory class for CPrinterServiceProvider
	//------------------------------------------------------------------------------
class CPrinterProviderFactory :
	public IClassFactory
{
private:

	~CPrinterProviderFactory();

public:

	CPrinterProviderFactory();

	//
	// IClassFactory Implementation
	//
	STDMETHODIMP CreateInstance(
		__in_opt IUnknown* pUnkOuter,
		__in REFIID riid,
		__deref_out_opt void** ppvObject
		);

	STDMETHODIMP LockServer(
		BOOL bLock
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

};// CPrinterProviderFactory


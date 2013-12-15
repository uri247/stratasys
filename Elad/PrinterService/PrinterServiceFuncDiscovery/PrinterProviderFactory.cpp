// Public Headers
#include <windows.h>

// Sample Headers
#include "PrinterProviderFactory.h"
#include "PrinterServiceProvider.h"
#include "common.h"

//------------------------------------------------------------------------------
// CPrinterProviderFactory::CPrinterProviderFactory (Constructor)
//------------------------------------------------------------------------------
CPrinterProviderFactory::CPrinterProviderFactory() :
m_cRef(1)
{
	DllIncLockCount();
}


//------------------------------------------------------------------------------
// CPrinterProviderFactory::~CPrinterProviderFactory (Destructor)
//------------------------------------------------------------------------------
CPrinterProviderFactory::~CPrinterProviderFactory()
{
	DllDecLockCount();
}


//
// IClassFactory
//

//------------------------------------------------------------------------------
// CPrinterProviderFactory::CreateInstance
//------------------------------------------------------------------------------
HRESULT CPrinterProviderFactory::CreateInstance(
	IUnknown* pUnkOuter,
	REFIID riid,
	void** ppvObject
	)
{
	HRESULT hr = E_FAIL;
	CPrinterServiceProvider* pCPrinterServiceProvider = NULL;

	if (NULL == ppvObject)
	{
		return E_INVALIDARG;
	}

	if (NULL != pUnkOuter)
	{
		return CLASS_E_NOAGGREGATION;
	}

	pCPrinterServiceProvider = new CPrinterServiceProvider();
	if (NULL == pCPrinterServiceProvider)
	{
		return E_OUTOFMEMORY;
	}

	hr = pCPrinterServiceProvider->QueryInterface(riid, ppvObject);
	pCPrinterServiceProvider->Release();

	return hr;
}// CPrinterProviderFactory::CreateInstance


//------------------------------------------------------------------------------
// CPrinterProviderFactory::LockServer
//------------------------------------------------------------------------------
HRESULT CPrinterProviderFactory::LockServer(
	BOOL bLock
	)
{
	if (TRUE == bLock)
	{
		DllIncLockCount();
	}
	else
	{
		DllDecLockCount();
	}

	return S_OK;
}// CPrinterProviderFactory::LockServer


//
// IUnknown
//

//------------------------------------------------------------------------------
// CPrinterProviderFactory::QueryInterface
//------------------------------------------------------------------------------
HRESULT CPrinterProviderFactory::QueryInterface(
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

	if (__uuidof(IClassFactory) == riid)
	{
		*ppvObject = static_cast<IClassFactory*>(this);
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
}// CPrinterProviderFactory::QueryInterface


//------------------------------------------------------------------------------
// CPrinterProviderFactory::AddRef
//------------------------------------------------------------------------------
ULONG CPrinterProviderFactory::AddRef()
{
	return InterlockedIncrement(&m_cRef);
}// CPrinterProviderFactory::AddRef


//------------------------------------------------------------------------------
// CPrinterProviderFactory::Release
//------------------------------------------------------------------------------
ULONG CPrinterProviderFactory::Release()
{
	LONG cRef = InterlockedDecrement(&m_cRef);

	if (0 == cRef)
	{
		delete this;
	}
	return cRef;
}// CPrinterProviderFactory::Release
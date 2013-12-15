/////////////////////////////////////////////////////////////////////
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.

#include <stdio.h>
#include <conio.h>
#include "Client.h"
#include <strsafe.h>

//additional public headers for the use of Windows' FunctionDiscovery (aka FD)
#include <windows.h>
#include <functiondiscovery.h>
#include "PrintServiceFuncDiscovery_h.h"
#include "PrinterService.h"

class TestDocument : public IWSDAttachment
{
public:
	HRESULT STDMETHODCALLTYPE QueryInterface(/* [in] */ REFIID riid, /* [iid_is][out] */ _COM_Outptr_ void __RPC_FAR *__RPC_FAR *ppvObject)
	{
		return S_OK;
	}

	ULONG STDMETHODCALLTYPE AddRef(void)
	{
		return 1;
	}

	ULONG STDMETHODCALLTYPE Release(void)
	{
		return 0;
	}
};

CPrinterServiceTypeProxy* pPrinterServiceProxy;
CPrinterServiceV12TypeProxy* pPrinterServiceV12Proxy;

//
// Function Declarations -- for using Windows' FunctionDiscovery object
//
VOID DeviceControl(	__in IFunctionInstance* pFunInst);
LONG GetDesiredTempFromUser();
HRESULT GetDeviceFiFromUser(__deref_out IFunctionInstance** ppFunInst);
HRESULT PrintDeviceFiInfo(__in IFunctionInstance* pFunInst);

HRESULT TestSrvComm_GetPrinterElements(CPrinterServiceTypeProxy* pPrinterServiceProxy);
HRESULT TestSrvComm_SendDocument(CPrinterServiceTypeProxy* pPrinterServiceProxy);
HRESULT QueryPrinter(void);

//////////////////////////////////////////////////////////////////////////////
// print_result - Display HRESULTs
//////////////////////////////////////////////////////////////////////////////
void print_result(HRESULT hr)
{
    if( S_OK == hr )
    {
        _cwprintf(L"[S_OK]\r\n");
    }
    else 
    {
        _cwprintf(L"[ERROR: %x]\r\n", hr);
    }
}

//////////////////////////////////////////////////////////////////////////////
// Usage
//////////////////////////////////////////////////////////////////////////////
void Usage()
{
    _cwprintf(L"PrinterServiceClient.exe <device-address>\r\n");
    _cwprintf(L"Ex: PrinterServiceClient.exe urn:uuid:41F8BE9C-CF75-48f7-9294-1B2DC8698214\r\n");
}

//////////////////////////////////////////////////////////////////////////////
// Main Entry Point
//      argv[0] = executable name
//      argv[1] = device address (GUID, matching the server's)
//////////////////////////////////////////////////////////////////////////////
int _cdecl wmain(int argc, __in_ecount(argc) LPWSTR* argv)
{
    LPCWSTR pszDeviceAddress = NULL;
    WCHAR szLocalAddress[MAX_PATH];
	WCHAR szLocalAddressV12[MAX_PATH];
    HRESULT hr = S_OK;
    UUID uuid;
	UUID uuidV12;
    pPrinterServiceProxy = NULL;
	pPrinterServiceV12Proxy = NULL;
    
    //////////////////////////////////////////////////////////////////////////
    // Process command-line parameters
    //////////////////////////////////////////////////////////////////////////

    if( argc <= 1 )
    {
        Usage();
        return -1;
    }

    pszDeviceAddress = argv[1];

    //////////////////////////////////////////////////////////////////////////
    // Build the proxy
    //////////////////////////////////////////////////////////////////////////

    // Generate local ID for our proxy
    if( S_OK == hr )
    {
        hr = UuidCreate( &uuid );
		hr = UuidCreate(&uuidV12);
    }

    if( S_OK == hr )
    {
        hr = StringCbPrintfW(
            szLocalAddress, sizeof(szLocalAddress),
            L"urn:uuid:%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x",
            uuid.Data1, uuid.Data2, uuid.Data3,
            uuid.Data4[0], uuid.Data4[1], uuid.Data4[2], uuid.Data4[3], 
            uuid.Data4[4], uuid.Data4[5], uuid.Data4[6], uuid.Data4[7]); 

		hr = StringCbPrintfW(
			szLocalAddressV12, sizeof(szLocalAddressV12),
			L"urn:uuid:%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x",
			uuidV12.Data1, uuidV12.Data2, uuidV12.Data3,
			uuidV12.Data4[0], uuidV12.Data4[1], uuidV12.Data4[2], uuidV12.Data4[3],
			uuidV12.Data4[4], uuidV12.Data4[5], uuidV12.Data4[6], uuidV12.Data4[7]);
    }

    // Build the proxies
    if( S_OK == hr )
    {
        _cwprintf(L"Creating a proxy for device %s...", pszDeviceAddress);
        hr = CreateCPrinterServiceTypeProxy( pszDeviceAddress, szLocalAddress,
			&pPrinterServiceProxy, NULL);

		print_result(hr);
		_cwprintf(L"Creating a V12 proxy for device %s...", pszDeviceAddress);
		hr = CreateCPrinterServiceV12TypeProxy(pszDeviceAddress, szLocalAddressV12,
			&pPrinterServiceV12Proxy, NULL);

		

        print_result( hr );
    }

    //////////////////////////////////////////////////////////////////////////
    // Call service methods on the proxy
    //////////////////////////////////////////////////////////////////////////

	if (S_OK == hr)
	{
		hr = QueryPrinter();
	}
	if (S_OK == hr)
	{
	//	hr = TestSrvComm_GetPrinterElements(pPrinterServiceProxy);
	}
	if (S_OK == hr)
	{
	//	hr = TestSrvComm_SendDocument(pPrinterServiceProxy);
	}

	_cwprintf(L"Cleaning up resources... ");
    // cleanup
   

	if (NULL != pPrinterServiceProxy)
    {
		pPrinterServiceProxy->Release();
		pPrinterServiceProxy = NULL;
    }


	if (NULL != pPrinterServiceV12Proxy)
	{
		pPrinterServiceV12Proxy->Release();
		pPrinterServiceV12Proxy = NULL;
	}

    _cwprintf(L"finished.\r\n");

    if( SUCCEEDED(hr) )
    {
        return 0;
    }

    return -1;
} // main

HRESULT TestSrvComm_GetPrinterElements(CPrinterServiceTypeProxy* pPrinterServiceProxy)
{
	HRESULT hr;
	GET_PRINTER_ELEMENTS_REQUEST_TYPE request;
	GET_PRINTER_ELEMENTS_RESPONSE_TYPE* response = NULL;

	/* Hi Kris/Jesse
	The Request types, as well as the Response types, contain members that are not
	that straight-forward. They are unclear and under-documented.

	In the following example, we can pass a valid request to the server-side.
	Should the construction of the Response struct be finished
	[see CPrinterServiceService::GetPrinterElements] - it is much complex than
	expected.
	If the driver asks about an element like "JobName", it seems odd to retrieve data
	about all the printer's elements and capabilities.
	Which makes the negotiation unclear.

	Can we please get a description of each of the declared SOAP messages,
	what is intended to be sent and what is intended to be received ?
	*/
	request.RequestedElements = new REQUESTED_PRINTER_ELEMENTS_TYPE();
	request.RequestedElements->Name = new WSDXML_NAME_LIST();
	request.RequestedElements->Name->Element = &Names_Print[239]; //i.e. WSDXML_NAME is like { &Namespace_Print, L"JobName" }
	request.RequestedElements->Name->Next = NULL;

	hr = pPrinterServiceProxy->GetPrinterElements(&request, &response);
	_cwprintf(L"Error in GetPrinterElements [ERROR: %x]\r\n", hr);

	return hr;
}

HRESULT TestSrvComm_SendDocument(CPrinterServiceTypeProxy* pPrinterServiceProxy)
{
	HRESULT hr;
	SEND_DOCUMENT_REQUEST_TYPE request;
	SEND_DOCUMENT_RESPONSE_TYPE* response = NULL;

	request.JobId = 1;
	request.LastDocument = FALSE;
	request.DocumentDescription = new DOCUMENT_DESCRIPTION_TYPE();
	request.DocumentDescription->DocumentId = 666;
	request.DocumentDescription->MustHonorCompression = FALSE;
	request.DocumentDescription->Compression = new COMPRESSION_EXT_TYPE();
	request.DocumentDescription->Compression->CompressionWKVTypeValue = CompressionWKVType_None;
	request.DocumentDescription->Compression->KeywordNsExtensionPatternTypeValue = new WCHAR[3];
	request.DocumentDescription->MustHonorFormat = TRUE;
	request.DocumentDescription->Format = new DOCUMENT_FORMAT_EXT_TYPE();
	request.DocumentDescription->Format->DocumentFormatWKVTypeValue = DocumentFormatWKVType_image_gif;
	request.DocumentDescription->Format->MimeExtensionPatternTypeValue = new WCHAR[3];
	request.DocumentDescription->DocumentName = L"Demo Gif";
	request.DocumentDescription->DocumentUrl = new WCHAR[3];
	request.DocumentDescription->Any = NULL;
	
	request.DocumentData = new TestDocument();

	hr = pPrinterServiceProxy->SendDocument(&request, &response);
	_cwprintf(L"Error in GetPrinterElements [ERROR: %x]\r\n", hr);

	return hr;
}

/*
*******************************************************************************
*************************    QUERY  DEVICE(S)          ************************
*******************************************************************************
*/

//------------------------------------------------------------------------------
// DeviceControl
//      Presents the user with information about the device represented by the
//      FI. Also allows minimum interaction with the device.
//------------------------------------------------------------------------------
VOID DeviceControl(
	IFunctionInstance* pFunInst
	)
{
	HRESULT             hr = S_OK;
	ULONG               i = 0;
	LONG                lCurrentTemp = 0;
	LONG                lDesiredTemp = 0;
	PROPVARIANT         pvID = { 0 };
	PROPVARIANT         pvName = { 0 };
	IPropertyStore*     pPropStore = NULL;
	IPrinterService*	pPrinterService = NULL;

	//
	// Ask for the simple thermostat object from the function instance
	//
	wprintf(L"Query service on the FI for ISimpleThermostat...\n");
	hr = pFunInst->QueryService(
		__uuidof(SsysPrinterSvcProxy),
		__uuidof(IPrinterService),
		reinterpret_cast<void**>(&pPrinterService)
		);
	wprintf(L"Query service for IPrinterService returned...0x%x\n", hr);

	//
	// Grab the name and ID of the device
	//
	if (S_OK == hr)
	{
		wprintf(L"OpenPropertyStore on the FI...");
		hr = pFunInst->OpenPropertyStore(STGM_READ, &pPropStore);
		wprintf(L"0x%x\n", hr);
	}

	if (S_OK == hr)
	{
		wprintf(L"GetValue of PKEY_PNPX_FriendlyName...");
		hr = pPropStore->GetValue(PKEY_PNPX_FriendlyName, &pvName);
		wprintf(L"0x%x\n", hr);
	}

	if (S_OK == hr)
	{
		wprintf(L"GetValue of PKEY_PNPX_GlobalIdentity...");
		hr = pPropStore->GetValue(PKEY_PNPX_GlobalIdentity, &pvID);
		wprintf(L"0x%x\n", hr);
	}

	//
	// Respond to commands from the user until they choose to exit
	//
	while (S_OK == hr &&
		i != 3)
	{
		/*
		wprintf(L"GetCurrentTemp from thermostat (remote call)...");
		hr = pPrinterService->GetCurrentTemp(&lCurrentTemp);
		wprintf(L"0x%x\n", hr);

		wprintf(L"GetDesiredTemp from thermostat (remote call)...");
		hr = pPrinterService->GetDesiredTemp(&lDesiredTemp);
		wprintf(L"0x%x\n\n", hr);
		*/
		wprintf(L" __________________________\n");
		wprintf(L"| SSYS' 3-D Printer Device |\n");
		wprintf(L"|__________________________|_________________________\n");
		wprintf(L"|                                                    |\n");
		wprintf(L"|  Name: %-43.43s |\n", pvName.pwszVal);
		wprintf(L"|  ID: %-45.45s |\n", pvID.pwszVal);
//		wprintf(L"|  Current Temp: %-35d |\n", lCurrentTemp);
//		wprintf(L"|  Desired Temp: %-35d |\n", lDesiredTemp);
		wprintf(L"|                                                    |\n");
		wprintf(L"| MENU                                               |\n");
		wprintf(L"|  1) Refresh Device Info                            |\n");
//		wprintf(L"|  2) Set Desired Temp                               |\n");
		wprintf(L"|  2) Test GetPrinterElements                        |\n");
		wprintf(L"|  3) Test SendDocument                              |\n");
		wprintf(L"|  4) Exit                                           |\n");
		wprintf(L"|____________________________________________________|\n");
		wprintf(L"> ");
		i = _getche() - '0';
		wprintf(L"\n\n");

		switch (i)
		{
		case 1:
			wprintf(L"Refreshing device info...\n");
			//
			// Nothing needs to be done here since the device info is refreshed
			// with every loop.
			//
			break;
		case 2:
		/*	lDesiredTemp = GetDesiredTempFromUser();
			wprintf(L"SetDesiredTemp on thermostat (remote call)...");
			hr = pPrinterService->SetDesiredTemp(lDesiredTemp);
			wprintf(L"0x%x\n", hr);
			break;
		*/
			hr = TestSrvComm_GetPrinterElements(pPrinterServiceProxy);
			break;
		case 3:
			hr = TestSrvComm_SendDocument(pPrinterServiceProxy);
			break;
		case 4:
			break;
		default:
			wprintf(L"Invalid selection...\n");
			break;
		}
	}

	//
	// Cleanup
	//
	PropVariantClear(&pvID);
	PropVariantClear(&pvName);

	if (NULL != pPropStore)
	{
		pPropStore->Release();
		pPropStore = NULL;
	}

	if (NULL != pPrinterService)
	{
		pPrinterService->Release();
		pPrinterService = NULL;
	}

	return;
}// DeviceControl


//------------------------------------------------------------------------------
// GetDeviceFiFromUser
//      Presents the user with a list of IPrinterService devices and returns
//      the FI representing the device the user chooses.
//------------------------------------------------------------------------------
HRESULT GetDeviceFiFromUser(
	IFunctionInstance** ppFunInst
	)
{
	const ULONG							GUID_CCH_LEN = 40;
	ULONG                               ulCount = 0;
	HRESULT                             hr = S_OK;
	ULONG                               i = 0;
	IFunctionDiscovery*                 pFunDisc = NULL;
	IFunctionInstance*                  pFunInst = NULL;
	IFunctionInstanceCollection*        pFunInsts = NULL;
	IFunctionInstanceCollectionQuery*   pFunInstsQuery = NULL;
	WCHAR                               szInterface[GUID_CCH_LEN] = { 0 };

	wprintf(L"CoCreate the Function Discovery object...");
	hr = CoCreateInstance(
		__uuidof(FunctionDiscovery),
		NULL,
		CLSCTX_INPROC_SERVER,
		__uuidof(IFunctionDiscovery),
		reinterpret_cast<void**>(&pFunDisc)
		);
	wprintf(L"0x%x\n", hr);

	if (S_OK == hr)
	{
		wprintf(L"Create a PnP instance collection query...");
		hr = pFunDisc->CreateInstanceCollectionQuery(
			FCTN_CATEGORY_PNP,
			NULL,
			FALSE,
			NULL,
			NULL,
			&pFunInstsQuery
			);
		wprintf(L"0x%x\n", hr);
	}

	if (S_OK == hr)
	{
		wprintf(L"Adding IPrinterService as an interface constraint on the query...");
		StringFromGUID2(__uuidof(IPrinterService), szInterface, GUID_CCH_LEN);
		//Elad: doesn't work. Devices aren't recognized as being dervied from IPrinterService
		//Commenting the next command will show ALL devices
		/*     hr = pFunInstsQuery->AddQueryConstraint(
		PROVIDERPNP_QUERYCONSTRAINT_INTERFACECLASS,
		szInterface
		);
		*/   wprintf(L"0x%x\n", hr);
	}

	if (S_OK == hr)
	{
		wprintf(L"Execute the query...");
		hr = pFunInstsQuery->Execute(&pFunInsts);
		wprintf(L"0x%x\n", hr);
	}

	if (S_OK == hr)
	{
		wprintf(L"Get the number of results...");
		hr = pFunInsts->GetCount(&ulCount);
		wprintf(L"0x%x\n\n", hr);

		wprintf(L"RESULTS (Only listing first 5)\n\n");
		wprintf(L"  #  Friendly Name              Device Identity\n");
		wprintf(L"  -  -------------------------  ---------------------------------------------\n");

		if (S_OK == hr &&
			ulCount < 1)
		{
			wprintf(L"  No IPrinterService devices found\n");
			hr = E_FAIL;
		}

		if (S_OK == hr)
		{
			for (i = 0; i < ulCount; i++)
			{
				hr = pFunInsts->Item(i, &pFunInst);
				wprintf(L"  %d) ", i + 1);
				if (S_OK == hr)
				{
					hr = PrintDeviceFiInfo(pFunInst);
				}
				if (S_OK != hr)
				{
					wprintf(L"Error retrieving device info");
				}
				wprintf(L"\n");
				hr = S_OK;
			}
		}
		wprintf(L"  ---------------------------------------------------------------------------\n");
	}

	if (S_OK == hr &&
		ulCount > 0)
	{
		//ULONG j = 0;
		WCHAR deviceNo[3] = { 0 };
		wprintf(L"  Select a device> ");
		//i = _getche() - '0'; //reads a single digit
		hr = StringCchGetsW(deviceNo, 5);
		if (S_OK == hr)
		{
			i = _wtol(deviceNo);
			//j = _getche() - '0';
			//i = (10 * i) + j;
			wprintf(L"\n\n");
			if (0 >= i ||
				ulCount < i)
			{
				wprintf(L"Invalid selection...\n");
				hr = E_FAIL;
			}
		}
	}

	if (S_OK == hr)
	{
		wprintf(L"Grabbing device %d...", i);
		hr = pFunInsts->Item(i - 1, &pFunInst);
		wprintf(L"0x%x\n", hr);
		*ppFunInst = pFunInst;
		pFunInst->AddRef();
	}

	//
	// Cleanup
	//
	if (NULL != pFunInst)
	{
		pFunInst->Release();
		pFunInst = NULL;
	}

	if (NULL != pFunInsts)
	{
		pFunInsts->Release();
		pFunInsts = NULL;
	}

	if (NULL != pFunInstsQuery)
	{
		pFunInstsQuery->Release();
		pFunInstsQuery = NULL;
	}

	if (NULL != pFunDisc)
	{
		pFunDisc->Release();
		pFunDisc = NULL;
	}

	return hr;
}// GetDeviceFiFromUser


//------------------------------------------------------------------------------
// PrintDeviceFiInfo
//      Prints basic information about a device to the console.
//------------------------------------------------------------------------------
HRESULT PrintDeviceFiInfo(
	IFunctionInstance* pFunInst
	)
{
	HRESULT         hr = S_OK;
	PROPVARIANT     pvName = { 0 };
	PROPVARIANT     pvID = { 0 };
	IPropertyStore* pPropStore = NULL;

	if (NULL == pFunInst)
	{
		return E_INVALIDARG;
	}

	hr = pFunInst->OpenPropertyStore(STGM_READ, &pPropStore);

	if (S_OK == hr)
	{
		hr = pPropStore->GetValue(PKEY_PNPX_FriendlyName, &pvName);
	}

	if (S_OK == hr)
	{
		hr = pPropStore->GetValue(PKEY_PNPX_GlobalIdentity, &pvID);
	}

	if (S_OK == hr &&
		VT_LPWSTR == pvName.vt &&
		VT_LPWSTR == pvID.vt)
	{
		wprintf(L"%-25.25s  %-45.45s", pvName.pwszVal, pvID.pwszVal);
	}

	//
	// Cleanup
	//
	PropVariantClear(&pvName);
	PropVariantClear(&pvID);

	if (NULL != pPropStore)
	{
		pPropStore->Release();
		pPropStore = NULL;
	}

	return hr;
}// PrintDeviceFiInfo

HRESULT QueryPrinter(void)
{
	HRESULT             hr = E_FAIL;
	IFunctionInstance*  pFunInst = NULL;

	wprintf(L"\n");
	wprintf(L"*** 3D-Printer Client ***\n\n");
	wprintf(L"Searching for installed IPrinterService devices...\n\n");

	wprintf(L"CoInitializeEx...");
	hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);
	wprintf(L"0x%x\n", hr);

	//
	// Search for IPrinterService devices and ask the user which one to use.
	//
	if (S_OK == hr)
	{
		hr = GetDeviceFiFromUser(&pFunInst);
	}

	//
	// Allow the user to interact with the selected device
	//
	if (S_OK == hr)
	{
		DeviceControl(pFunInst);
	}

	wprintf(L"Exiting...\n");

	//
	// Cleanup
	//
	if (NULL != pFunInst)
	{
		pFunInst->Release();
		pFunInst = NULL;
	}

	return hr;
}


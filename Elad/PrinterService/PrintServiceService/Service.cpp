//////////////////////////////////////////////////////////////////////////////
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <conio.h>
#include "Service.h"
#include <strsafe.h>

//////////////////////////////////////////////////////////////////////////////
// print_result - Displays the HRESULT
//////////////////////////////////////////////////////////////////////////////
void print_result( HRESULT hr )
{
    if( hr == S_OK )
    {
        _cwprintf(L"[S_OK]\r\n");
    }
    else 
    {
        _cwprintf(L"[ERROR: %x]\r\n", hr);
    }
}

//////////////////////////////////////////////////////////////////////////////
// StripCbPath - Strips path info from a filename
//////////////////////////////////////////////////////////////////////////////
HRESULT StripCbPath(
    __out_bcount(cbDst) LPWSTR pszDst, 
    size_t cbDst, 
    LPCWSTR pszSrc)
{
    LPCWSTR pszBackSlash = NULL;
    LPCWSTR pszSlash = NULL;
    LPCWSTR psz = NULL;

    if( NULL == pszSrc )
    {
        return E_INVALIDARG;
    }

    pszBackSlash = wcsrchr(pszSrc, '\\');
    if( NULL != pszBackSlash )
    {
        pszBackSlash++;
    }

    pszSlash = wcsrchr(pszSrc, '/');
    if( NULL != pszSlash )
    {
        pszSlash++;
    }

    psz = (pszBackSlash > pszSlash ? pszBackSlash : pszSlash);
    if( NULL == psz )
    {
        psz = pszSrc;
    }

    return ::StringCbCopyW(pszDst, cbDst, psz);
}

//////////////////////////////////////////////////////////////////////////////
// CloneString - Allocates memory (via WSD Linked Memory) and copies a string
//////////////////////////////////////////////////////////////////////////////
HRESULT CloneString(
    LPCWSTR pszSrc,
    LPCWSTR *ppszDst)
{
    HRESULT hr = S_OK;
    LPWSTR pszDst = NULL;
    size_t len = 0;
    size_t cchDst = 0;

    if( NULL == pszSrc )
    {
        return E_INVALIDARG;
    }

    if( NULL == ppszDst )
    {
        return E_POINTER;
    }

    *ppszDst = NULL;

    hr = ::StringCchLengthW( pszSrc, MAX_PATH, &len );

    if( S_OK == hr )
    {
        cchDst = len + 1;
        pszDst = (LPWSTR)WSDAllocateLinkedMemory( NULL,
                cchDst * sizeof(WCHAR) );

        if( NULL == pszDst )
        {
            hr = E_OUTOFMEMORY;
        }
    }

    if( S_OK == hr )
    {
        hr = ::StringCchCopyW( pszDst, cchDst, pszSrc );
    }

    // cleanup
    if( S_OK != hr )
    {
        if( NULL != pszDst )
        {
            WSDFreeLinkedMemory( pszDst );
            pszDst = NULL;
        }
    }

    *ppszDst = pszDst;

    return hr;
}

//////////////////////////////////////////////////////////////////////////////
// CreateStringList - Allocates a string list object for a string
//      The resulting list object will eventually be used in a linked list,
//      but this routine does not chain the objects together.
//
//      The outparam ppList will contain the following members:
//          Element (cloned from pszItem, and linked to ppList)
//          Next    (NULL, but will be modified by caller to point to next
//                   PWCHAR_LIST in the linked list)
//
//////////////////////////////////////////////////////////////////////////////
HRESULT CreateStringList(
    LPCWSTR pszItem,
    PWCHAR_LIST **ppList)
{
    PWCHAR_LIST* pList = NULL;
    HRESULT hr = S_OK;
   
    if( NULL == pszItem )
    {
        return E_INVALIDARG;
    }

    if( NULL == ppList )
    {
        return E_POINTER;
    }

    *ppList = NULL;

    // Allocate and zero the linked-list container structure first
    if( S_OK == hr )
    {
        pList = (PWCHAR_LIST*)WSDAllocateLinkedMemory( NULL, sizeof(PWCHAR_LIST) );

        if( NULL == pList )
        {
            hr = E_OUTOFMEMORY;
        }
    }

    // NULL the Next field and clone a string into the Element field
    if( S_OK == hr )
    {
        pList->Next = NULL;
        hr = CloneString( pszItem, &pList->Element );
    }

    // Attach the Element item to pList
    if( S_OK == hr )
    {
        WSDAttachLinkedMemory( (void*)pList, (void*)pList->Element );
    }

    // If all was successful, set outparam and clear local variable
    if( S_OK == hr )
    {
        *ppList = pList;
        pList = NULL;
    }

    // cleanup
    if( NULL != pList )
    {
        WSDFreeLinkedMemory( pList );
        pList = NULL;
    }

    return hr;
}

//////////////////////////////////////////////////////////////////////////////
// CFileServiceService Class
//////////////////////////////////////////////////////////////////////////////
CPrinterServiceService::CPrinterServiceService()
:   m_cRef(1)
{
}



HRESULT STDMETHODCALLTYPE CPrinterServiceService::CreatePrintJob(/* [in] */ CREATE_PRINT_JOB_REQUEST_TYPE *body,
														/* [out] */ CREATE_PRINT_JOB_RESPONSE_TYPE **bodyOut)
{
	HRESULT hr = S_OK;

	_cwprintf(L"CPrinterServiceService::CreatePrintJob\r\n");

	return hr;

}

HRESULT STDMETHODCALLTYPE CPrinterServiceService::SendDocument(	/* [in] */ SEND_DOCUMENT_REQUEST_TYPE *body,
																/* [out] */ SEND_DOCUMENT_RESPONSE_TYPE **bodyOut)
{
	HRESULT hr = S_OK;

	_cwprintf(L"CPrinterServiceService::SendDocument\r\n");

	return hr;

}

HRESULT STDMETHODCALLTYPE CPrinterServiceService::AddDocument(/* [in] */ ADD_DOCUMENT_REQUEST_TYPE *body,
															  /* [out] */ ADD_DOCUMENT_RESPONSE_TYPE **bodyOut)
{
	HRESULT hr = S_OK;

	_cwprintf(L"CPrinterServiceService::AddDocument\r\n");

	return hr;

}

HRESULT STDMETHODCALLTYPE CPrinterServiceService::CancelJob(/* [in] */ CANCEL_JOB_REQUEST_TYPE *body,
															/* [out] */ CANCEL_JOB_RESPONSE_TYPE **bodyOut)
{
	HRESULT hr = S_OK;

	_cwprintf(L"CPrinterServiceService::CancelJob\r\n");

	return hr;

}

void CPrinterServiceService::StubCreateResponseGetPrinterElements(PRINTER_ELEMENT_DATA_TYPE* elmResponse)
{
	/*struct PRINTER_ELEMENT_DATA_TYPE
	{
		WSDXML_NAME* Name;
		BOOLEAN Valid;
		PRINTER_DESCRIPTION_TYPE* PrinterDescription;
		PRINTER_CONFIGURATION_TYPE* PrinterConfiguration;
		PRINTER_STATUS_TYPE* PrinterStatus;
		PRINT_TICKET_TYPE* DefaultPrintTicket;
		PRINTER_CAPABILITIES_TYPE* PrinterCapabilities;
		WSDXML_ELEMENT* Any;
	}; 
	-----------------------------------*/
	elmResponse->Name = &Names_Print[239];
	elmResponse->Valid = TRUE;

	/*	[PRINTER_DESCRIPTION_TYPE]
	BOOLEAN ColorSupported;
	const WCHAR* DeviceId;
	BOOLEAN* MultipleDocumentJobsSupported;
	LONG PagesPerMinute;
	LONG* PagesPerMinuteColor;
	PWCHAR_LIST* PrinterName;
	PWCHAR_LIST* PrinterInfo;
	PWCHAR_LIST* PrinterLocation;
	WSDXML_ELEMENT* Any;
	*/
	elmResponse->PrinterDescription = new PRINTER_DESCRIPTION_TYPE();
	elmResponse->PrinterDescription->ColorSupported = TRUE;
	elmResponse->PrinterDescription->DeviceId = new WCHAR[3];
	elmResponse->PrinterDescription->MultipleDocumentJobsSupported = new BOOLEAN(FALSE);
	elmResponse->PrinterDescription->PagesPerMinute = 2L;
	elmResponse->PrinterDescription->PagesPerMinuteColor = new LONG(1L);
	elmResponse->PrinterDescription->PrinterName = new PWCHAR_LIST();
	elmResponse->PrinterDescription->PrinterName->Element = new WCHAR[3];
	elmResponse->PrinterDescription->PrinterName->Next = NULL;
	elmResponse->PrinterDescription->PrinterInfo = new PWCHAR_LIST();
	elmResponse->PrinterDescription->PrinterInfo->Element = new WCHAR[3];
	elmResponse->PrinterDescription->PrinterInfo->Next = NULL;
	elmResponse->PrinterDescription->PrinterLocation = new PWCHAR_LIST();
	elmResponse->PrinterDescription->PrinterLocation->Element = new WCHAR[3];
	elmResponse->PrinterDescription->PrinterLocation->Next = NULL;
	elmResponse->PrinterDescription->Any = NULL;

	/*	[PRINTER_CONFIGURATION_TYPE]
	LONG* PrinterEventRate;
	STORAGE_BASE_TYPE* Storage; // optional
	CONSUMABLES_TYPE* Consumables; // optional
	INPUT_BINS_TYPE* InputBins; // optional
	FINISHINGS_TYPE* Finishings; // optional
	OUTPUT_BINS_TYPE* OutputBins; // optional
	WSDXML_ELEMENT* Any;
	*/
	elmResponse->PrinterConfiguration = new PRINTER_CONFIGURATION_TYPE();
	elmResponse->PrinterConfiguration->PrinterEventRate = new LONG(1L);
	elmResponse->PrinterConfiguration->Any = NULL;

	/*	[PRINTER_STATUS_TYPE]
	WSD_DATETIME* PrinterCurrentTime;
	PRINTER_STATE_BASE_TYPE* PrinterState;
	PRINTER_STATE_REASON_BASE_TYPE* PrinterPrimaryStateReason;
	PRINTER_STATE_REASONS_TYPE* PrinterStateReasons; // optional
	LONG QueuedJobCount;
	ACTIVE_CONDITION_TABLE_TYPE* ActiveCondition; // optional
	CONDITION_HISTORY_TABLE_TYPE* ConditionHistory; // optional
	WSDXML_ELEMENT* Any;
	*/
	elmResponse->PrinterStatus = new PRINTER_STATUS_TYPE();
	elmResponse->PrinterStatus->PrinterCurrentTime = new WSD_DATETIME();
	elmResponse->PrinterStatus->PrinterState = new PRINTER_STATE_BASE_TYPE();
	elmResponse->PrinterStatus->PrinterState->KeywordNsExtensionPatternTypeValue = new WCHAR[3];
	elmResponse->PrinterStatus->PrinterState->PrinterStateWKVTypeValue = new WCHAR[3];
	elmResponse->PrinterStatus->PrinterPrimaryStateReason = new PRINTER_STATE_REASON_BASE_TYPE();
	elmResponse->PrinterStatus->PrinterPrimaryStateReason->KeywordNsExtensionPatternTypeValue = new WCHAR[3];
	elmResponse->PrinterStatus->PrinterPrimaryStateReason->PrinterStateReasonsWKVTypeValue = new WCHAR[3];
	elmResponse->PrinterStatus->QueuedJobCount = 0L;
	elmResponse->PrinterStatus->Any = NULL;

	/*	[PRINT_TICKET_TYPE]
	JOB_DESCRIPTION_TYPE* JobDescription; // optional
	JOB_PROCESSING_TYPE* JobProcessing; // optional
	DOCUMENT_PROCESSING_TYPE* DocumentProcessing; // optional
	WSDXML_ELEMENT* Any;
	*/
	elmResponse->DefaultPrintTicket = new PRINT_TICKET_TYPE();
	elmResponse->DefaultPrintTicket->DocumentProcessing = new DOCUMENT_PROCESSING_TYPE(); /*TODO: CREATE STUB*/

	elmResponse->DefaultPrintTicket->JobDescription = new JOB_DESCRIPTION_TYPE();
	elmResponse->DefaultPrintTicket->JobDescription->JobName = new WCHAR[3];
	elmResponse->DefaultPrintTicket->JobDescription->JobOriginatingUserName = new WCHAR[3];
	elmResponse->DefaultPrintTicket->JobDescription->Any = NULL;
	elmResponse->DefaultPrintTicket->JobProcessing = new JOB_PROCESSING_TYPE();
	elmResponse->DefaultPrintTicket->JobProcessing->Copies = new LONG(1L);
	elmResponse->DefaultPrintTicket->JobProcessing->JobFinishings = new JOB_FINISHINGS_TYPE();
	elmResponse->DefaultPrintTicket->JobProcessing->JobFinishings->HolePunch = new HOLE_PUNCH_DETAILS_TYPE();
	elmResponse->DefaultPrintTicket->JobProcessing->JobFinishings->HolePunch->Edge = new HOLE_PUNCH_EDGE_EXT_TYPE();
	elmResponse->DefaultPrintTicket->JobProcessing->JobFinishings->HolePunch->Edge->HolePunchEdgeWKVTypeValue = new WCHAR[3];
	elmResponse->DefaultPrintTicket->JobProcessing->JobFinishings->HolePunch->Edge->KeywordNsExtensionPatternTypeValue = new WCHAR[3];
	elmResponse->DefaultPrintTicket->JobProcessing->JobFinishings->HolePunch->Pattern = new HOLE_PUNCH_PATTERN_EXT_TYPE();
	elmResponse->DefaultPrintTicket->JobProcessing->JobFinishings->HolePunch->Pattern->HolePunchPatternWKVTypeValue = new WCHAR[3];
	elmResponse->DefaultPrintTicket->JobProcessing->JobFinishings->HolePunch->Pattern->KeywordNsExtensionPatternTypeValue = new WCHAR[3];
	elmResponse->DefaultPrintTicket->JobProcessing->JobFinishings->HolePunch->MustHonor = new BOOLEAN(FALSE);
	elmResponse->DefaultPrintTicket->JobProcessing->JobFinishings->HolePunch->Any = NULL;
	elmResponse->DefaultPrintTicket->JobProcessing->JobFinishings->JogOffset = new BOOLEAN(FALSE);
	elmResponse->DefaultPrintTicket->JobProcessing->JobFinishings->MustHonorCollate = new BOOLEAN(FALSE);
	elmResponse->DefaultPrintTicket->JobProcessing->JobFinishings->MustHonorJogOffset = new BOOLEAN(FALSE);
	elmResponse->DefaultPrintTicket->JobProcessing->JobFinishings->Staple = new STAPLE_DETAILS_TYPE();
	elmResponse->DefaultPrintTicket->JobProcessing->JobFinishings->Staple->MustHonorAngle = new BOOLEAN(FALSE);
	elmResponse->DefaultPrintTicket->JobProcessing->JobFinishings->Staple->Location = new STAPLE_LOCATION_EXT_TYPE();
	elmResponse->DefaultPrintTicket->JobProcessing->JobFinishings->Staple->Location->KeywordNsExtensionPatternTypeValue = new WCHAR[3];
	elmResponse->DefaultPrintTicket->JobProcessing->JobFinishings->Staple->Location->StapleLocationWKVTypeValue = new WCHAR[3];
	elmResponse->DefaultPrintTicket->JobProcessing->JobFinishings->Staple->MustHonorLocation = FALSE;
	elmResponse->DefaultPrintTicket->JobProcessing->JobFinishings->Staple->Angle = new STAPLE_ANGLE_EXT_TYPE();
	elmResponse->DefaultPrintTicket->JobProcessing->JobFinishings->Staple->Angle->KeywordNsExtensionPatternTypeValue = new WCHAR[3];
	elmResponse->DefaultPrintTicket->JobProcessing->JobFinishings->Staple->Angle->StapleAngleWKVTypeValue = new WCHAR[3];
	elmResponse->DefaultPrintTicket->JobProcessing->JobFinishings->Staple->Any = NULL;
	elmResponse->DefaultPrintTicket->JobProcessing->JobFinishings->Collate = new BOOLEAN(FALSE);
	elmResponse->DefaultPrintTicket->JobProcessing->JobFinishings->Any = NULL;
	elmResponse->DefaultPrintTicket->JobProcessing->MustHonorCopies = new BOOLEAN(TRUE);
	elmResponse->DefaultPrintTicket->JobProcessing->MustHonorPriority = new BOOLEAN(TRUE);
	elmResponse->DefaultPrintTicket->JobProcessing->Priority = new LONG(1L);
	elmResponse->DefaultPrintTicket->JobProcessing->Any = NULL;
	elmResponse->DefaultPrintTicket->Any = NULL;

	/*	[PRINTER_CAPABILITIES_TYPE]
	JOB_VALUES_TYPE* JobValues; // optional
	DOCUMENT_VALUES_TYPE* DocumentValues; // optional
	WSDXML_ELEMENT* Any;
	*/
	elmResponse->PrinterCapabilities = new PRINTER_CAPABILITIES_TYPE(); /*TODO: CREATE STUB*/
	elmResponse->PrinterCapabilities->DocumentValues = new DOCUMENT_VALUES_TYPE();
	elmResponse->PrinterCapabilities->DocumentValues->DocumentDescription = new DOCUMENT_DESCRIPTION_0(); /*TODO: CREATE STUB*/
	elmResponse->PrinterCapabilities->DocumentValues->Any = NULL;
	elmResponse->PrinterCapabilities->JobValues = new JOB_VALUES_TYPE(); /*TODO: CREATE STUB*/
	elmResponse->PrinterCapabilities->Any = NULL;
	elmResponse->Any = NULL;
}

HRESULT STDMETHODCALLTYPE CPrinterServiceService::GetPrinterElements(/* [in] */ GET_PRINTER_ELEMENTS_REQUEST_TYPE *body,
																	 /* [out] */ GET_PRINTER_ELEMENTS_RESPONSE_TYPE **bodyOut)
{
	HRESULT hr = S_OK;

	_cwprintf(L"Was in GetPrinterElements\r\n");

	//E_INVALIDARG E_FAIL(80004005L)
	// bodyOut is of type GET_PRINTER_ELEMENTS_RESPONSE_TYPE* which in turn... is PRINTER_ELEMENT_DATA_TYPE*
	try {
		PRINTER_ELEMENT_DATA_TYPE* elmResponse = new PRINTER_ELEMENT_DATA_TYPE();
		/*
			StubCreateResponseGetPrinterElements will create a fictional PRINTER_ELEMENT_DATA_TYPE typed
			struct. Lines describing elements that still needed to be constructed have breakpoints 
			set next to them and the comment "TODO: CREATE STUB".
			Without constructing them, WSDFreeLinkedMemory() calls (within Service.cpp) will FAIL
			as the type is not as predefined in the XML schema files (i.e. XSD)
		*/
		StubCreateResponseGetPrinterElements(elmResponse);

		(*bodyOut) = new GET_PRINTER_ELEMENTS_RESPONSE_TYPE();
		(*bodyOut)->PrinterElements = new PRINTER_ELEMENTS_TYPE();
		(*bodyOut)->PrinterElements->ElementData = new PRINTER_ELEMENT_DATA_TYPE_LIST();
		(*bodyOut)->PrinterElements->ElementData->Element = elmResponse;
		(*bodyOut)->PrinterElements->ElementData->Next = NULL;
	}
	catch (...) {
		hr = ((HRESULT)-1L);
	}
	
	return hr;

}

HRESULT STDMETHODCALLTYPE CPrinterServiceService::GetJobElements(/* [in] */ GET_JOB_ELEMENTS_REQUEST_TYPE *body,
																 /* [out] */ GET_JOB_ELEMENTS_RESPONSE_TYPE **bodyOut)
{
	HRESULT hr = S_OK;

	_cwprintf(L"CPrinterServiceService::GetJobElements\r\n");

	return hr;

}

HRESULT STDMETHODCALLTYPE CPrinterServiceService::GetActiveJobs(/* [in] */ GET_ACTIVE_JOBS_REQUEST_TYPE *body,
																/* [out] */ GET_ACTIVE_JOBS_RESPONSE_TYPE **bodyOut)
{
	HRESULT hr = S_OK;

	_cwprintf(L"CPrinterServiceService::GetActiveJobs\r\n");

	return hr;
}


HRESULT STDMETHODCALLTYPE CPrinterServiceService::GetJobHistory(/* [in] */ GET_JOB_HISTORY_REQUEST_TYPE *body,
	/* [out] */ GET_JOB_HISTORY_RESPONSE_TYPE **bodyOut)
{
	HRESULT hr = S_OK;

	_cwprintf(L"CPrinterServiceService::GetJobHistory\r\n");

	return hr;
}

HRESULT STDMETHODCALLTYPE CPrinterServiceService::SetEventRate(/* [in] */ SET_EVENT_RATE_REQUEST_TYPE *body,
	/* [out] */ SET_EVENT_RATE_RESPONSE_TYPE **bodyOut)
{
	HRESULT hr = S_OK;

	_cwprintf(L"CPrinterServiceService::SetEventRate\r\n");

	return hr;
}



//////////////////////////////////////////////////////////////////////////////
// CFileServiceService Class
//////////////////////////////////////////////////////////////////////////////
CPrinterServiceServiceV12::CPrinterServiceServiceV12()
: m_cRef(1)
{
}



HRESULT STDMETHODCALLTYPE CPrinterServiceServiceV12::SetPrinterElements(/* [in] */ SET_PRINTER_ELEMENTS_REQUEST_TYPE *body,
																		/* [out] */ SET_PRINTER_ELEMENTS_RESPONSE_TYPE **bodyOut)
{
	HRESULT hr = S_OK;

	_cwprintf(L"CPrinterServiceServiceV12::SetPrinterElements\r\n");

	return hr;

}



//////////////////////////////////////////////////////////////////////////////
// Usage
//////////////////////////////////////////////////////////////////////////////
void Usage(LPCWSTR pszAdditionalInformation)
{
    _cwprintf(L"FileService.exe <files-directory> [<device-address>]\r\n");

    if( NULL != pszAdditionalInformation )
    {
        _cwprintf( L"%s\r\n", pszAdditionalInformation );
    }
}

//////////////////////////////////////////////////////////////////////////////
// Main Entry Point
//      argv[0] = executable name
//      argv[1] = files-directory - the directory from which to get the files
//      argv[2] = device address (optional) 
//////////////////////////////////////////////////////////////////////////////
int _cdecl wmain(int argc,  __in_ecount(argc) LPWSTR* argv)
{
    HRESULT hr = S_OK;
    LPCWSTR pszAdditionalInformation = NULL;
    UUID uuid;
	WCHAR szDeviceAddress[MAX_PATH];


	CPrinterServiceService* pPrinterService = NULL;
    IPrinterServiceType* pIPrinterService = NULL;

	CPrinterServiceServiceV12* pPrinterServiceV12 = NULL;
	IPrinterServiceV12Type* pIPrinterServiceV12 = NULL;

    IWSDDeviceHost* pHost = NULL;
    DWORD dwErr = 0;


    
    if( S_OK == hr )
    {
        // If the device address is specified, copy it
        if( argc > 1 )
        {
            hr = ::StringCbCopyW( szDeviceAddress,
                    sizeof(szDeviceAddress), argv[1] );
        }
        else
        {
            // Otherwise, generate an ID for the host
            hr = UuidCreate( &uuid );

            if( S_OK == hr )
            {
                hr = StringCbPrintfW(
                    szDeviceAddress, sizeof(szDeviceAddress),
                    L"urn:uuid:%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x",
                    uuid.Data1, uuid.Data2, uuid.Data3,
                    uuid.Data4[0], uuid.Data4[1], uuid.Data4[2], uuid.Data4[3],
                    uuid.Data4[4], uuid.Data4[5], uuid.Data4[6], uuid.Data4[7]);
            }
        }
    }

    if( S_OK != hr )
    {
        Usage( pszAdditionalInformation );
        return -1;
    }
	wprintf(L"Device host id: %s\n", szDeviceAddress);

    //////////////////////////////////////////////////////////////////////////
    // Build ourPrinterService service
    //////////////////////////////////////////////////////////////////////////
    if( S_OK == hr )
    {
        _cwprintf(L"Creating the print service... ");
        pPrinterService = new CPrinterServiceService();
		pPrinterServiceV12 = new CPrinterServiceServiceV12();

        
		if (NULL == pPrinterService || NULL == pPrinterServiceV12)
        {
            hr = E_OUTOFMEMORY;
        }
        print_result( hr );
    }

  
    // Retrieve an IPrinterService pointer to pass into CreateFileServiceHost
    if( S_OK == hr )
    {
        _cwprintf(L"Querying print service for service interface... ");
		hr = pPrinterService->QueryInterface(__uuidof(IPrinterServiceType),
                (void**)&pIPrinterService );
		print_result( hr );

		hr = pPrinterServiceV12->QueryInterface(__uuidof(IPrinterServiceV12Type),
			(void**)&pIPrinterServiceV12);
		print_result(hr);
    }

    //////////////////////////////////////////////////////////////////////////
    // Build the host
    //////////////////////////////////////////////////////////////////////////

    // Create host
    if( S_OK == hr )
    {
        _cwprintf(L"Creating print service host with ID %s... ",
                szDeviceAddress );
        hr = CreatePrinterServiceTypeHost( szDeviceAddress, &thisDeviceMetadata,
			pIPrinterService, pIPrinterServiceV12,  &pHost, NULL);
        print_result( hr );
    }

    // Start host
    if( S_OK == hr )
    {
        _cwprintf(L"Starting Host... ");
        hr = pHost->Start( 0, NULL, NULL );
        print_result( hr );
    }

   

    // Let service run
    if( S_OK == hr )
    {
        _cwprintf(L">>> Service running.  Press any key to stop service. <<<\r\n");
        // Ignore character returned from prompt
        (void)::_getch();
    }

   

    // Stop host
    if( S_OK == hr )
    {
        _cwprintf(L"Stopping host... ");
        hr = pHost->Stop();
        print_result(hr);
    }

    _cwprintf(L"Cleaning up resources... ");

    // cleanup
    if( NULL != pIPrinterService )
    {
		pIPrinterService->Release();
		pIPrinterService = NULL;
    }

    if( NULL != pPrinterService )
    {
		pPrinterService->Release();
		pPrinterService = NULL;
    }


	if (NULL != pIPrinterServiceV12)
	{
		pIPrinterServiceV12->Release();
		pIPrinterServiceV12 = NULL;
	}

	if (NULL != pPrinterServiceV12)
	{
		pPrinterServiceV12->Release();
		pPrinterServiceV12 = NULL;
	}

    if( NULL != pHost )
    {
        // Terminating the host is nonoptional, so it's done in the cleanup
        // block
        hr = pHost->Terminate();
        pHost->Release();
        pHost = NULL;
    }

    _cwprintf(L"finished.\r\n");

    if( SUCCEEDED(hr) )
    {
        return 0;
    }

    return -1;
}
